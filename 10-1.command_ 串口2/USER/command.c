#include "command.H"




void poem()
{
	switch(Rec_Val)
	{
		case '1':
		SendMsg("				 ");Rec_Val = 0;
		break;
		
		case '2':
		SendMsg(" Wow!\r\n \n");Rec_Val = 0;
		break;
		
		case '3':
		SendMsg(" ��ǰ���¹����ǵ���˪��ͷ�����µ�ͷ˼���磡\r\n \n");Rec_Val = 0;
		break;
		
		case '4':
		SendMsg(" ����й���\r\n \n");Rec_Val = 0;
		break;
		
		case '5':
		SendMsg(" Warning! A huge battleship STEVE is approaching fast!\r\n \n");Rec_Val = 0;
		break;
		
		case '6':
		SendMsg(" Stay safe!\r\n \n");Rec_Val = 0;
		break;
		
		case '7':
		SendMsg(" Now Java16!\r\n \n");Rec_Val = 0;
		break;
		
		case '8':
		SendMsg(" Made by real people!\r\n \n");Rec_Val = 0;
		break;
		
		default:
		
		break;
	}
}

