#include "Uart.H"		//����ͷ�ļ� �Լ������ģ�������


volatile  unsigned int Rec_Val = 0;  //����ȫ�ֱ��������ڴ�Ŵ���1���յ�������
static bit busy = 0;  //���徲̬ȫ�ֱ�����ע�����ȫ�ֲ���ôȫ�֣�ֻ�����ı�����ʹ��

void SendData(unsigned char dat);
void SendMsg(char *s);


void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x01;		//����1ѡ��ʱ��2Ϊ�����ʷ�����
	AUXR |= 0x04;		//��ʱ��2ʱ��ΪFosc,��1T
	T2L = 0xE0;		//�趨��ʱ��ֵ
	T2H = 0xFE;		//�趨��ʱ��ֵ
	AUXR |= 0x10;		//������ʱ��2
	
  ES = 1;	      //���Ŵ���1�ж�
	EA = 1;       //�������ж�
	
	SendMsg("STC15F2K60S2\r\n I am Ready !\r\n �Ұ��й���\r\n");//
	
}

/*----------------------------
UART �жϷ������
-----------------------------*/
void Uart(void) interrupt 4
{
    if (RI)                     //���յ�һ������
    {
        RI = 0;                 //���RIλ
        P0 = SBUF;              //P0��ʾ��������
        Rec_Val =  SBUF;        //�����յ����ݴ���������Թ������ط�ʹ��
				SBUF = Rec_Val;        //дSBUF����ʵ���Ƿ��ͣ�
//			  if((Rec_Val >= '1')&&(Rec_Val <= '8'))
//				{
//					SBUF = 'Y';
//				}
//				else
//				{
//					SBUF = 'N';
//				}
    }		
    if (TI)                     //һ�����ݷ������
    {
        TI = 0;                 //���TIλ
        busy = 0;               //��æ��־
    }
}

/*----------------------------
���ʹ�������
----------------------------*/
void SendData(unsigned char dat)
{
    while (busy);               //�ȴ�ǰ������ݷ������
    busy = 1;
    SBUF = dat;                 //д���ݵ�UART���ݼĴ���
}

/*----------------------------
�����ַ���
----------------------------*/
void SendMsg(char *s)
{
    while (*s)                  //����ַ���������־
    {
        SendData(*s++);         //���͵�ǰ�ַ�
    }
}
