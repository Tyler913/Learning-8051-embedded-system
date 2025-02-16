// #include "ds18b20.h"
// #include "INTRINS.H"

// /*
//   Note: You must calibrate the delay() routine so that the DS18B20 timing
//   (reset pulse, write/read slots, and conversion delay) matches the datasheet.
//   For example, if delay(1) ≈ 1?s, then a 750ms conversion delay needs delay(750000).
// */

// void ds18b20_reset() {
//     DS18B20_PORT = 0;
//     delay(500);   // Pull low for ~480?s (adjust as needed)
//     DS18B20_PORT = 1;
//     delay(20);    // Wait for recovery (~20?s)
// }

// u8 ds18b20_check() {
//     u8 timeout = 0;

//     // Wait for DS18B20 to pull the line low (presence pulse)
//     while (DS18B20_PORT && timeout < 100) {
//         timeout++;
//         delay(1);
//     }
//     if (timeout >= 100)
//         return 1;   // Sensor did not respond

//     timeout = 0;
//     // Wait for DS18B20 to release the line
//     while (!DS18B20_PORT && timeout < 100) {
//         timeout++;
//         delay(1);
//     }
//     if (timeout >= 100)
//         return 1;   // Error
//     else
//         return 0;
// }

// u8 ds18b20_init() {
//     ds18b20_reset();
//     return ds18b20_check();
// }

// void ds18b20_write_data(u8 data_input) {
//     u8 i;
//     for (i = 0; i < 8; i++) {
//         if (data_input & 0x01) {
//             // Write '1': pull low briefly then release
//             DS18B20_PORT = 0;
//             _nop_();
//             _nop_();
//             DS18B20_PORT = 1;
//             delay(6);  // Wait for the rest of the time slot
//         } else {
//             // Write '0': hold low longer
//             DS18B20_PORT = 0;
//             delay(6);  // Ensure low for required period
//             DS18B20_PORT = 1;
//             _nop_();
//             _nop_();
//         }
//         data_input >>= 1;
//     }
// }

// u8 ds18b20_read_data_one_bit() {
//     u8 data_read = 0;
//     DS18B20_PORT = 0;
//     _nop_();
//     _nop_();
//     DS18B20_PORT = 1;   // Release the bus so DS18B20 can drive it
//     delay(15);          // Wait ~15?s before sampling
//     data_read = DS18B20_PORT; // Sample the bus level
//     delay(5);           // Wait until end of time slot
//     return data_read;
// }

// u8 ds18b20_read_data_one_byte() {
//     u8 i, data_read = 0;
//     for (i = 0; i < 8; i++) {
//         data_read |= (ds18b20_read_data_one_bit() << i);
//     }
//     return data_read;
// }

// void ds18b20_start() {
//     ds18b20_reset();
//     if(ds18b20_check() != 0)
//         return; // Sensor not responding; add error handling as needed
//     ds18b20_write_data(0xCC); // Skip ROM command
//     ds18b20_write_data(0x44); // Convert T command

//     // Wait for conversion to complete.
//     // At 12-bit resolution, conversion may take up to 750ms.
//     // If delay(1) ≈ 1?s, then use delay(750000);
//     delay(750000);  
// }

// float ds18b20_read_temperature() {
//     u8 data_th = 0, data_tl = 0;
//     u16 value = 0;
//     float final_temperature = 0.0;

//     ds18b20_start();
//     ds18b20_reset();
//     if(ds18b20_check() != 0)
//         return 0.0;  // Sensor error
//     ds18b20_write_data(0xCC); // Skip ROM
//     ds18b20_write_data(0xBE); // Read Scratchpad command

//     data_tl = ds18b20_read_data_one_byte();
//     data_th = ds18b20_read_data_one_byte();

//     value = (data_th << 8) | data_tl;

//     // DS18B20 data is in two's complement.
//     if ((value & 0xF800) == 0xF800) {
//         value = (~value) + 1;
//         final_temperature = value * (-0.0625);
//     } else {
//         final_temperature = value * 0.0625;
//     }

//     return final_temperature;
// }


#include "ds18b20.h"
#include "intrins.h"

/*******************************************************************************
* 函 数 名         : ds18b20_reset
* 函数功能		   : 复位DS18B20  
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void ds18b20_reset(void)
{
	DS18B20_PORT=0;	//拉低DQ
	delay_10us(75);	//拉低750us
	DS18B20_PORT=1;	//DQ=1
	delay_10us(2);	//20US
}

/*******************************************************************************
* 函 数 名         : ds18b20_check
* 函数功能		   : 检测DS18B20是否存在
* 输    入         : 无
* 输    出         : 1:未检测到DS18B20的存在，0:存在
*******************************************************************************/
u8 ds18b20_check(void)
{
	u8 time_temp=0;

	while(DS18B20_PORT&&time_temp<20)	//等待DQ为低电平
	{
		time_temp++;
		delay_10us(1);	
	}
	if(time_temp>=20)return 1;	//如果超时则强制返回1
	else time_temp=0;
	while((!DS18B20_PORT)&&time_temp<20)	//等待DQ为高电平
	{
		time_temp++;
		delay_10us(1);
	}
	if(time_temp>=20)return 1;	//如果超时则强制返回1
	return 0;
}

/*******************************************************************************
* 函 数 名         : ds18b20_read_bit
* 函数功能		   : 从DS18B20读取一个位
* 输    入         : 无
* 输    出         : 1/0
*******************************************************************************/
u8 ds18b20_read_bit(void)
{
	u8 dat=0;
	
	DS18B20_PORT=0;
	_nop_();_nop_();
	DS18B20_PORT=1;	
	_nop_();_nop_(); //该段时间不能过长，必须在15us内读取数据
	if(DS18B20_PORT)dat=1;	//如果总线上为1则数据dat为1，否则为0
	else dat=0;
	delay_10us(5);
	return dat;
} 

/*******************************************************************************
* 函 数 名         : ds18b20_read_byte
* 函数功能		   : 从DS18B20读取一个字节
* 输    入         : 无
* 输    出         : 一个字节数据
*******************************************************************************/
u8 ds18b20_read_byte(void)
{
	u8 i=0;
	u8 dat=0;
	u8 temp=0;

	for(i=0;i<8;i++)//循环8次，每次读取一位，且先读低位再读高位
	{
		temp=ds18b20_read_bit();
		dat=(temp<<7)|(dat>>1);
	}
	return dat;	
}

/*******************************************************************************
* 函 数 名         : ds18b20_write_byte
* 函数功能		   : 写一个字节到DS18B20
* 输    入         : dat：要写入的字节
* 输    出         : 无
*******************************************************************************/
void ds18b20_write_byte(u8 dat)
{
	u8 i=0;
	u8 temp=0;

	for(i=0;i<8;i++)//循环8次，每次写一位，且先写低位再写高位
	{
		temp=dat&0x01;//选择低位准备写入
		dat>>=1;//将次高位移到低位
		if(temp)
		{
			DS18B20_PORT=0;
			_nop_();_nop_();
			DS18B20_PORT=1;	
			delay_10us(6);
		}
		else
		{
			DS18B20_PORT=0;
			delay_10us(6);
			DS18B20_PORT=1;
			_nop_();_nop_();	
		}	
	}	
}

/*******************************************************************************
* 函 数 名         : ds18b20_start
* 函数功能		   : 开始温度转换
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void ds18b20_start(void)
{
	ds18b20_reset();//复位
	ds18b20_check();//检查DS18B20
	ds18b20_write_byte(0xcc);//SKIP ROM
    ds18b20_write_byte(0x44);//转换命令	
}

/*******************************************************************************
* 函 数 名         : ds18b20_init
* 函数功能		   : 初始化DS18B20的IO口 DQ 同时检测DS的存在
* 输    入         : 无
* 输    出         : 1:不存在，0:存在
*******************************************************************************/ 
u8 ds18b20_init(void)
{
	ds18b20_reset();
	return ds18b20_check();	
}

/*******************************************************************************
* 函 数 名         : ds18b20_read_temperture
* 函数功能		   : 从ds18b20得到温度值
* 输    入         : 无
* 输    出         : 温度数据
*******************************************************************************/
float ds18b20_read_temperture(void)
{
	float temp;
	u8 dath=0;
	u8 datl=0;
	u16 value=0;

	ds18b20_start();//开始转换
	ds18b20_reset();//复位
	ds18b20_check();
	ds18b20_write_byte(0xcc);//SKIP ROM
    ds18b20_write_byte(0xbe);//读存储器

	datl=ds18b20_read_byte();//低字节
	dath=ds18b20_read_byte();//高字节
	value=(dath<<8)+datl;//合并为16位数据

	if((value&0xf800)==0xf800)//判断符号位，负温度
	{
		value=(~value)+1; //数据取反再加1
		temp=value*(-0.0625);//乘以精度	
	}
	else //正温度
	{
		temp=value*0.0625;	
	}
	return temp;
}
