#include "rad.H"		//����ͷ�ļ�����ʱ���й� �Լ������ģ�������

//������������
volatile bit rad_Valid_Flag = 0;
volatile bit K1_Flag = 0;
volatile bit K2_Flag = 0;


void K1_Check(void)
{
	static unsigned char Cnt = 0;
	static unsigned char K1_Status = 0;
	switch(K1_Status)
	{
		case 0:  //��ʼ״̬��ע����ð��
			if(K1 == 0)
			{
				 Cnt = 0;
				K1_Status = 1;
			}
			else
			{
				 Cnt ++;
				if( Cnt >= 5)
				{
					 Cnt = 0;
					K1_Flag = 0;
				}
			}
			break;   //�˳���䣬�˳���ǰ״̬�������������ִ��
			
			case 1:  //ȥ��״̬
			if(K1 == 0)
			{
				Cnt ++;
				if( Cnt >= 5)
				{
					Cnt = 0;
					K1_Flag = 1;
					rad_Valid_Flag = 1;
					K1_Status  = 2;
				}
			}
			else
			{
					 Cnt = 0;
					K1_Status  = 0;
				}
			
			break;
			
					case 2:  //�ɿ����״̬
			if(K1)
			{
				Cnt = 0;
				K1_Status = 0;
			}
			break;
		}
}
					
void K2_Check(void)
{
	static unsigned char Cnt = 0;
	static unsigned char K2_Status = 0;
	switch(K2_Status)
	{
		case 0:  //��ʼ״̬��ע����ð��
			if(K2 == 0)
			{
				 Cnt = 0;
				K2_Status = 1;
			}
			else
			{
				 Cnt ++;
				if( Cnt >= 5)
				{
					 Cnt = 0;
					K2_Flag = 0;
				}
			}
			break;   //�˳���䣬�˳���ǰ״̬�������������ִ��
			
			case 1:  //ȥ��״̬
			if(K2 == 0)
			{
				Cnt ++;
				if( Cnt >= 5)
				{
					Cnt = 0;
					K2_Flag = 1;
					rad_Valid_Flag = 1;
					K2_Status  = 2;
				}
			}
			else
			{
					 Cnt = 0;
					K2_Status  = 0;
				}
			
			break;
			
					case 2:  //�ɿ����״̬
			if(K2)
			{
				Cnt = 0;
				K2_Status = 0;
			}
			break;
		}
}
			