#include "KEY.h"

volatile bit trigger_KEY_control;		//按键检测总变量
volatile bit trigger_KEY1;					//KEY1变量
volatile bit trigger_KEY2;					//KEY2变量
volatile bit trigger_KEY2_1;

void KEY1_CHECK()										//KEY1检查
{
	static unsigned char KEY1_Cnt = 0;
	static unsigned char KEY1_Status = 0;
	
	switch(KEY1_Status)
	{
		case 0:							//default-mode Check//初始模式检查
		if(KEY1 == 0)				//check KEY1 //检测低电平
		{
			KEY1_Cnt = 0;
			KEY1_Status = 1;
		}
		else								//按住时间是否大于20ms
		{
			KEY1_Cnt ++;
			if(KEY1_Cnt >= 20)
			{
				KEY1_Cnt = 0;
				trigger_KEY1 = 0;
			}
		}
		break;							//function end//语句结束
		
		case 1:							//去抖
		if(KEY1 == 0)
		{
			KEY1_Cnt++;
			if(KEY1_Cnt >= 20)
			{
				KEY1_Cnt = 0;
				trigger_KEY1 = 1;				//KEY1变量改变
				trigger_KEY_control = 1;//按键检测总变量改变
				KEY1_Status = 2;
			}
		}
		else
		{
			KEY1_Cnt = 0;
			KEY1_Status = 0;
		}
		break;							//function end//语句结束
		
		case 2:							//复位KEY1
		if(KEY1)
		{
			KEY1_Cnt = 0;
			KEY1_Status =0;
		}
		break;
	}
}

void KEY2_CHECK()										//KEY2检查
{
	static unsigned char KEY2_Cnt = 0;
	static unsigned char KEY2_Status = 0;
	
	switch(KEY2_Status)
	{
		case 0:							//default-mode Check//初始模式检查
		if(KEY2 == 0)				//check KEY1 //检测低电平
		{
			KEY2_Cnt = 0;
			KEY2_Status = 1;
		}
		else								//按住时间是否大于20ms
		{
			KEY2_Cnt ++;
			if(KEY2_Cnt >= 20)
			{
				KEY2_Cnt = 0;
				trigger_KEY2 = 0;
			}
		}
		break;							//function end//语句结束
		
		case 1:							//去抖
		if(KEY2 == 0)
		{
			KEY2_Cnt++;
			if(KEY2_Cnt >= 20)
			{
				KEY2_Cnt = 0;
				trigger_KEY2 = 1;				//KEY2变量改变
				trigger_KEY2_1 = 1;
				trigger_KEY_control = 1;//按键检测总变量改变
				
				KEY2_Status = 2;
			}
		}
		else
		{
			KEY2_Cnt = 0;
			KEY2_Status = 0;
		}
		break;							//function end//语句结束
		
		case 2:							//复位KEY1
		if(KEY2)
		{
			KEY2_Cnt = 0;
			KEY2_Status =0;
		}
		break;
	}
}