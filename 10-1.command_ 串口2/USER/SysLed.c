#include "SysLed.H"		

void	SysLed_Display(void)
{
	//����static���Σ����Ϊ�Զ�Auto������ÿ�ν��������������ʹ�ó�ʼֵ
	//������Ҫÿ��10ms�����ۼӹ��������Ա���ʹ��ǰ׺static�����Σ���ʾ������������޸ĵ�ֵ
	static	unsigned char	Time500ms_Cnt = 0; //���ڼ���500ms��ʱ���������50�����Ϳ���
	
	Time500ms_Cnt ++;
	if(Time500ms_Cnt >= 50)
	{
		Time500ms_Cnt = 0;
		
		P45 = !P45;		//ϵͳ��״̬ȡ��
	
	}
	
}