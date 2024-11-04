#include "KEY.h"

volatile bit trigger_KEY_control;		//��������ܱ���
volatile bit trigger_KEY1;					//KEY1����
volatile bit trigger_KEY2;					//KEY2����
volatile bit trigger_KEY2_1;

void KEY1_CHECK()										//KEY1���
{
	static unsigned char KEY1_Cnt = 0;
	static unsigned char KEY1_Status = 0;
	
	switch(KEY1_Status)
	{
		case 0:							//default-mode Check//��ʼģʽ���
		if(KEY1 == 0)				//check KEY1 //���͵�ƽ
		{
			KEY1_Cnt = 0;
			KEY1_Status = 1;
		}
		else								//��סʱ���Ƿ����20ms
		{
			KEY1_Cnt ++;
			if(KEY1_Cnt >= 20)
			{
				KEY1_Cnt = 0;
				trigger_KEY1 = 0;
			}
		}
		break;							//function end//������
		
		case 1:							//ȥ��
		if(KEY1 == 0)
		{
			KEY1_Cnt++;
			if(KEY1_Cnt >= 20)
			{
				KEY1_Cnt = 0;
				trigger_KEY1 = 1;				//KEY1�����ı�
				trigger_KEY_control = 1;//��������ܱ����ı�
				KEY1_Status = 2;
			}
		}
		else
		{
			KEY1_Cnt = 0;
			KEY1_Status = 0;
		}
		break;							//function end//������
		
		case 2:							//��λKEY1
		if(KEY1)
		{
			KEY1_Cnt = 0;
			KEY1_Status =0;
		}
		break;
	}
}

void KEY2_CHECK()										//KEY2���
{
	static unsigned char KEY2_Cnt = 0;
	static unsigned char KEY2_Status = 0;
	
	switch(KEY2_Status)
	{
		case 0:							//default-mode Check//��ʼģʽ���
		if(KEY2 == 0)				//check KEY1 //���͵�ƽ
		{
			KEY2_Cnt = 0;
			KEY2_Status = 1;
		}
		else								//��סʱ���Ƿ����20ms
		{
			KEY2_Cnt ++;
			if(KEY2_Cnt >= 20)
			{
				KEY2_Cnt = 0;
				trigger_KEY2 = 0;
			}
		}
		break;							//function end//������
		
		case 1:							//ȥ��
		if(KEY2 == 0)
		{
			KEY2_Cnt++;
			if(KEY2_Cnt >= 20)
			{
				KEY2_Cnt = 0;
				trigger_KEY2 = 1;				//KEY2�����ı�
				trigger_KEY2_1 = 1;
				trigger_KEY_control = 1;//��������ܱ����ı�
				
				KEY2_Status = 2;
			}
		}
		else
		{
			KEY2_Cnt = 0;
			KEY2_Status = 0;
		}
		break;							//function end//������
		
		case 2:							//��λKEY1
		if(KEY2)
		{
			KEY2_Cnt = 0;
			KEY2_Status =0;
		}
		break;
	}
}