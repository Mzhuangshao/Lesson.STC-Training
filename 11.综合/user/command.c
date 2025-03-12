#include "command.H"

void poem()
{
	switch (Rec_Val)
	{
	case '1':
		SendMsg("				 ");
		Rec_Val = 0;
		break;

	case '2':
		SendMsg(" Wow!\r\n \n");
		Rec_Val = 0;
		break;

	case '3':
		SendMsg(" 床前明月光疑是地上霜举头望明月低头思故乡！\r\n \n");
		Rec_Val = 0;
		break;

	case '4':
		SendMsg(" 你好中国！\r\n \n");
		Rec_Val = 0;
		break;

	case '5':
		SendMsg(" Warning! A huge battleship STEVE is approaching fast!\r\n \n");
		Rec_Val = 0;
		break;

	case '6':
		SendMsg(" Stay safe!\r\n \n");
		Rec_Val = 0;
		break;

	case '7':
		SendMsg(" Now Java16!\r\n \n");
		Rec_Val = 0;
		break;

	case '8':
		SendMsg(" Made by real people!\r\n \n");
		Rec_Val = 0;
		break;

	default:

		break;
	}
}
