#include "SysLed.H"		//包含头文件，系统灯 【本头文件自己定义】

//系统灯，频率1Hz，即0.5s亮，0.5s灭
//频率不高，调用频度越好
//1ms 调用处理一次，需要计500个数，才500ms
//10ms 调用处理，只需计50个数，就500ms  ——选用

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