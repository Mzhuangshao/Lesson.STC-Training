#include "SysLed.H"		

void	SysLed_Display(void)
{
	//如无static修饰，则称为自动Auto变量，每次进入这个函数都将使用初始值
	//这里需要每隔10ms进行累加工作，所以必须使用前缀static来修饰，表示变量保留最后修改的值
	static	unsigned char	Time500ms_Cnt = 0; //用于计算500ms的时间变量，计50个数就可以
	
	Time500ms_Cnt ++;
	if(Time500ms_Cnt >= 50)
	{
		Time500ms_Cnt = 0;
		
		P45 = !P45;		//系统灯状态取反
	
	}
	
}