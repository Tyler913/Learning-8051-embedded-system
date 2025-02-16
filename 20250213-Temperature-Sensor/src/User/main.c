// #include "ds18b20.h"
// #include "digital_tube.h"
// #include "public.h"

// void main() {
//     int temperature = 0;     // temperature * 10 (for one decimal place)
//     u8 buffer_smg[5];        // buffer: [sign, thousands, hundreds, tens, ones]
//     u8 i = 0;
//     float temp_val = 0.0;

//     // Initialize DS18B20 (optionally check for sensor error)
//     if(ds18b20_init() != 0) {
//         // Handle sensor absence/error if needed
//     }
    
//     while (1) {
//         i++;
//         if (i % 50 == 0) {
//             // Read temperature (in Celsius) and multiply by 10
//             temp_val = ds18b20_read_temperature();
//             temperature = (int)(temp_val * 10);

//             // If negative, set sign (assuming 0x40 represents '-' on your display)
//             if(temperature < 0) {
//                 temperature = -temperature;
//                 buffer_smg[0] = 0x40; 
//             } else {
//                 buffer_smg[0] = 0x00; // blank
//             }

//             // Break temperature (e.g. 25.0��C �� 250) into digits
//             buffer_smg[1] = gsmg_code[temperature / 1000];                     // Thousands digit
//             buffer_smg[2] = gsmg_code[(temperature % 1000) / 100];               // Hundreds digit
//             buffer_smg[3] = gsmg_code[((temperature % 100) / 10)] | 0x80;        // Tens digit with decimal point
//             buffer_smg[4] = gsmg_code[temperature % 10];                         // Ones digit

//             // Display 5 digits starting at position 4
//             smg_display(buffer_smg, 4);
//         }
//     }
// }


/**************************************************************************************
���������пƼ����޹�˾��PRECHIN ���У�
����֧�֣�www.prechin.net
PRECHIN
 ����

ʵ�����ƣ�DS18B20�¶ȴ�����ʵ��
����˵����	
ʵ���������س���󣬲���DS18B20�¶ȴ��������������ʾ�����¶�ֵ
ע�����ע���¶ȴ������ķ����ڽӿڴ������Ѿ���˿ӡ����һ��͹��
		  ����ֻ��Ҫ���¶ȴ�������Ӧ���뼴��																				  
***************************************************************************************/
#include "public.h"
#include "digital_tube.h"
#include "ds18b20.h"


/*******************************************************************************
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void main()
{	
	u8 i=0;
   	int temp_value;
	u8 temp_buf[5];

	ds18b20_init();//��ʼ��DS18B20

	while(1)
	{				
		i++;
		if(i%50==0)//���һ��ʱ���ȡ�¶�ֵ�����ʱ��Ҫ�����¶ȴ�����ת���¶�ʱ��
			temp_value=ds18b20_read_temperture()*10;//�����¶�ֵС����һλ
		if(temp_value<0)//���¶�
		{
			temp_value=-temp_value;
			temp_buf[0]=0x40;//��ʾ����	
		}
		else
			temp_buf[0]=0x00;//����ʾ
		temp_buf[1]=gsmg_code[temp_value/1000];//��λ
		temp_buf[2]=gsmg_code[temp_value%1000/100];//ʮλ
		temp_buf[3]=gsmg_code[temp_value%1000%100/10]|0x80;//��λ+С����
		temp_buf[4]=gsmg_code[temp_value%1000%100%10];//С�����һλ
		smg_display(temp_buf,4);
	}		
}
