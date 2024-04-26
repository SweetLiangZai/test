/***
	***************************************************************************************************
	*	@file  	main.c
	*	@version V1.4
	*  @date    2023-5-16
	*	@author  ���ͿƼ�	
	*	@brief   ����3.5����
   ****************************************************************************************************
   *  @description
	*
	*	ʵ��ƽ̨������STM32F407VET6���İ� ���ͺţ�FK407M3-VET6��+ 3.5��Һ�������ͺţ�MCU035M1��
	*	�Ա���ַ��https://shop212360197.taobao.com
	*	QQ����Ⱥ��536665479
	*
>>>>	V1.4�汾���˵����2023-5-16����	
	*		
	*		1.�����׼�����̸��Ż����룬��ʼ����Ļ����������
	*		2.�Ż���λʱ�䣬���͵ȴ�ʱ��
	*		3.���ӵ�ɫͼƬ��ʾ����
	*
>>>>	V1.3�汾���˵����	
	*
	*		���Ӻ���С�ֿ⣬���Ӻ�����ʾ�ĺ���
	*	
>>>>	V1.2�汾���˵����	
	*
	*		����ʼ��ʱLCD�ĸ�λʱ��ӳ���������Ļ�����β�һ����������Ļ��λʱ��̫�̵Ļ��޷�������ʾ
	*
>>>>	V1.1�汾���˵����
	*	
	*		�޸� LCD_DrawPoint ����������ɫ����ȷ��BUG
	*
>>>>> ����˵����
	*
	*	������Ļ��ʾ
	* 		
	***************************************************************************************************
***/


#include "stm32f4xx.h"
#include "led.h"   
#include "delay.h"
#include "key.h"  
#include "usart.h"
#include "lcd_3.5tft.h"

void LCD_ClearTest(void);			// ��������
void LCD_TextTest(void);			// �ı���ʾ����
void LCD_FillTest(void);			// ����������
void LCD_ColorTest(void);			// ��ɫ����
void LCD_GrahicTest(void);			// ��ͼ����
void LCD_Image_Test(void);			// ͼƬ��ʾ����(��ɫͼƬ)
void LCD_HorizontalText(void);	// ��������


/***************************************************************************************************
*	�� �� ��: main
*	��ڲ���: ��
*	�� �� ֵ: ��
*	��������: ����������
*	˵    ��: ��
****************************************************************************************************/

int main(void)
{
	Delay_Init();		//��ʱ������ʼ��
	LED_Init();			//LED��ʼ��
	KEY_Init();			//����IO�ڳ�ʼ��
	Usart_Config ();	// USART��ʼ������

	printf("����-STM32F407VET6���İ����\r\n");
	
	LCD_Init();		// LCD��ʼ��

	while (1)
	{
		LED1_Toggle;

		LCD_DisplayMode(Mode_V);	// ������ʾ	
		LCD_ClearTest();		// ��������
		LCD_TextTest();		// �ı���ʾ����
		LCD_FillTest();		// ����������
		LCD_ColorTest();		// ��ɫ����
		LCD_GrahicTest();		// ��ͼ����
		LCD_Image_Test();		// ͼƬ��ʾ����(��ɫͼƬ)
		
		LCD_DisplayMode(Mode_H);	// ������ʾ
		LCD_HorizontalText();		// ��������
	}
	
}



/*---------------------------- ���Ժ��� ---------------------------------*/

// ��������������
//
void LCD_ClearTest(void)
{
	u16 time = 1000;	//��ʱʱ��

	LCD_SetAsciiFont(&ASCII_Font24);		//��������
	LCD_SetColor(LCD_BLACK);	//���û�����ɫ

	LCD_SetBackColor(LCD_RED);    LCD_Clear();  Delay_ms(time);
	LCD_SetBackColor(LCD_GREEN);  LCD_Clear();  Delay_ms(time);
	LCD_SetBackColor(LCD_BLUE);   LCD_Clear();  Delay_ms(time);
	LCD_SetBackColor(LCD_GREY);   LCD_Clear();  Delay_ms(time);	
	LCD_SetBackColor(LCD_WHITE);   LCD_Clear();  Delay_ms(time);
	LCD_SetBackColor(LCD_BLACK);   LCD_Clear();  Delay_ms(time);
}
// �������ı�����
//
void LCD_TextTest(void)
{

	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ

	LCD_SetColor(LCD_WHITE);
	LCD_SetAsciiFont(&ASCII_Font32); LCD_DisplayString(0, 0,"!#$%&'()*+,-.01"); 						
	LCD_SetAsciiFont(&ASCII_Font24); LCD_DisplayString(0,32,"!#$%&'()*+,-.01234"); 			
	LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0,56,"!#$%&'()*+,-.012345"); 				
	LCD_SetAsciiFont(&ASCII_Font16); LCD_DisplayString(0,76,"!#$%&'()*+,-.01234567"); 			
	LCD_SetAsciiFont(&ASCII_Font12); LCD_DisplayString(0,92,"!#$%&'()*+,-.0123456789:"); 		

	LCD_SetColor(LCD_CYAN);                                                      
	LCD_SetAsciiFont(&ASCII_Font12); LCD_DisplayString(0,104,"!#$%&'()*+,-.0123456789:"); 		
	LCD_SetAsciiFont(&ASCII_Font16); LCD_DisplayString(0,116,"!#$%&'()*+,-.01234567"); 			
	LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0,132,"!#$%&'()*+,-.012345"); 				
	LCD_SetAsciiFont(&ASCII_Font24); LCD_DisplayString(0,152,"!#$%&'()*+,-.01234"); 					
	LCD_SetAsciiFont(&ASCII_Font32); LCD_DisplayString(0,176,"!#$%&'()*+,-.01"); 					

	LCD_SetAsciiFont(&ASCII_Font32);
	LCD_SetColor(LCD_YELLOW);
	LCD_DisplayNumber( 0,220,429496729,9);   
	LCD_ShowNumMode(Fill_Zero);	
	LCD_DisplayNumber( 0,252,123456,9);	     
	LCD_ShowNumMode(Fill_Space);	
	LCD_DisplayNumber( 0,284,1234,9);		  

	LCD_SetTextFont(&CH_Font12);			// ����1212��������,ASCII�����ӦΪ1206
	LCD_SetColor(0Xff8AC6D1);						// ���û���
	LCD_DisplayText(0, 330,"���ͿƼ�");	

	LCD_SetTextFont(&CH_Font16);			// ����1616��������,ASCII�����ӦΪ1608
	LCD_SetColor(0XffC5E1A5);						// ���û���
	LCD_DisplayText(0, 350,"���ͿƼ�");		
	
	LCD_SetTextFont(&CH_Font20);			// ����2020��������,ASCII�����ӦΪ2010
	LCD_SetColor(0Xff2D248A);						// ���û���	
	LCD_DisplayText(0, 370,"���ͿƼ�");		
	
	LCD_SetTextFont(&CH_Font24);			// ����2424��������,ASCII�����ӦΪ2412
	LCD_SetColor(0XffFF585D);						// ���û���	
	LCD_DisplayText(0, 400,"���ͿƼ�");		

	LCD_SetTextFont(&CH_Font32);			// ����3232��������,ASCII�����ӦΪ3216
	LCD_SetColor(0XffF6003C);						// ���û���
	LCD_DisplayText(0, 430,"���ͿƼ�");	
	
	Delay_ms(2000);	
}

// ����������������
//
void LCD_FillTest(void)
{
	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ

	LCD_SetAsciiFont(&ASCII_Font16);
	LCD_SetColor(LCD_BLUE);	  	  LCD_FillRect(110,  3,130,16);	LCD_DisplayString(0,  3,"LCD_BLUE");		
	LCD_SetColor(LCD_GREEN);  	  LCD_FillRect(110, 25,130,16);  LCD_DisplayString(0, 25,"LCD_GREEN");		
	LCD_SetColor(LCD_RED);    	  LCD_FillRect(110, 47,130,16);  LCD_DisplayString(0, 47,"LCD_RED");			
	LCD_SetColor(LCD_CYAN);   	  LCD_FillRect(110, 69,130,16);  LCD_DisplayString(0, 69,"LCD_CYAN");		
	LCD_SetColor(LCD_MAGENTA);	  LCD_FillRect(110, 91,130,16);  LCD_DisplayString(0, 91,"LCD_MAGENTA");	
	LCD_SetColor(LCD_YELLOW); 	  LCD_FillRect(110,113,130,16);  LCD_DisplayString(0,113,"LCD_YELLOW");		
	LCD_SetColor(LCD_GREY);   	  LCD_FillRect(110,135,130,16);	LCD_DisplayString(0,135,"LCD_GREY");		
                                      
	LCD_SetColor(LIGHT_BLUE);	  LCD_FillRect(110,157,130,16);  LCD_DisplayString(0,157,"LIGHT_BLUE");		
	LCD_SetColor(LIGHT_GREEN);   LCD_FillRect(110,179,130,16);  LCD_DisplayString(0,179,"LIGHT_GREEN");	
	LCD_SetColor(LIGHT_RED);     LCD_FillRect(110,201,130,16);  LCD_DisplayString(0,201,"LIGHT_RED");	   
	LCD_SetColor(LIGHT_CYAN);    LCD_FillRect(110,223,130,16);  LCD_DisplayString(0,223,"LIGHT_CYAN");	   
	LCD_SetColor(LIGHT_MAGENTA); LCD_FillRect(110,245,130,16);  LCD_DisplayString(0,245,"LIGHT_MAGENTA");	
	LCD_SetColor(LIGHT_YELLOW);  LCD_FillRect(110,267,130,16);  LCD_DisplayString(0,267,"LIGHT_YELLOW");	
	LCD_SetColor(LIGHT_GREY);    LCD_FillRect(110,289,130,16);	LCD_DisplayString(0,289,"LIGHT_GREY");  	
                                                     
	Delay_ms(2000);
}

// ��������ɫ����
//
void LCD_ColorTest(void)
{
	u16 i;

	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ
	LCD_SetAsciiFont(&ASCII_Font32);
	LCD_SetColor(LCD_BLACK);

	LCD_SetBackColor(LIGHT_MAGENTA); LCD_DisplayString(0,  0,"   Color Test   "); 
	LCD_SetBackColor(LCD_YELLOW);  	LCD_DisplayString(0, 40,"   Color Test   ");
	LCD_SetBackColor(LCD_CYAN);  	 	LCD_DisplayString(0, 80,"   Color Test   ");

	//ʹ�û��ߺ�����������ɫɫ��
	for(i=0;i<240;i++)
	{
		LCD_SetColor( LCD_RED-(i<<16) );
		LCD_DrawLine(i,150,i,190);			
	}
	for(i=0;i<240;i++)
	{
		LCD_SetColor( LCD_GREEN-(i<<8) );
		LCD_DrawLine(i,200,i,240);	
	}
	for(i=0;i<240;i++)
	{
		LCD_SetColor( LCD_BLUE-i );
		LCD_DrawLine(i,250,i,290);	
	}	
	Delay_ms(2000);	
}
// ��������ͼ����
//
void LCD_GrahicTest(void)
{
	u16 time = 80;

	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ	

	LCD_SetColor(LCD_RED);
	LCD_DrawLine(0,10,240,10);	Delay_ms(time);	//��ֱ��
	LCD_DrawLine(0,20,240,20);	Delay_ms(time);
	LCD_DrawLine(0,30,240,30); Delay_ms(time);
	LCD_DrawLine(0,40,240,40);	Delay_ms(time);	
	
	LCD_SetColor(LCD_YELLOW);	
	LCD_DrawRect( 5, 85,240,150); Delay_ms(time);	//���ƾ���
	LCD_DrawRect(30,100,190,120); Delay_ms(time);
	LCD_DrawRect(55,115,140,90);  Delay_ms(time);
	LCD_DrawRect(80,135,90,60);   Delay_ms(time);	

	LCD_SetColor(LIGHT_CYAN);
	LCD_DrawCircle(120,170,100);	Delay_ms(time);	//����Բ��
	LCD_DrawCircle(120,170,80);   Delay_ms(time);
	LCD_DrawCircle(120,170,60);   Delay_ms(time);
	LCD_DrawCircle(120,170,40);   Delay_ms(time);

	LCD_SetColor(DARK_CYAN);
	LCD_DrawLine(0,285,240,285);	Delay_ms(time);	//��ֱ��
	LCD_DrawLine(0,295,240,295);	Delay_ms(time);
	LCD_DrawLine(0,305,240,305);  Delay_ms(time);
	LCD_DrawLine(0,315,240,315);	Delay_ms(time);	
	Delay_ms(1000);

	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ	
	
	LCD_SetColor(LCD_RED);    LCD_FillCircle( 60,80,60);		//���Բ��
	LCD_SetColor(LCD_GREEN);  LCD_FillCircle(120,80,60); 	
	LCD_SetColor(LCD_BLUE);   LCD_FillCircle(160,80,60);  	

	LCD_SetColor(LIGHT_BLUE);
	LCD_DrawEllipse(120,250,110,50);  Delay_ms(time);	//������Բ
	LCD_DrawEllipse(120,250, 95,40);  Delay_ms(time);
	LCD_DrawEllipse(120,250, 80,30);  Delay_ms(time);
	LCD_DrawEllipse(120,250, 65,20);  Delay_ms(time);

	Delay_ms(2000);	
}

/*************************************************************************************************
*	�� �� ��:	LCD_Test_Image
*
*	��������:	ͼƬ��ʾ����
*************************************************************************************************/
void LCD_Image_Test(void)
{
	LCD_SetBackColor(LCD_BLACK); 			//	���ñ���ɫ
	LCD_Clear(); 								// ����
	
	LCD_SetColor( 0xF6E58D);
	LCD_DrawImage( 19, 55, 83, 83, Image_Android_83x83) ;	   // ��ʾͼƬ

	LCD_SetColor( 0xDFF9FB);
	LCD_DrawImage( 141, 55, 83, 83, Image_Message_83x83) ;	// ��ʾͼƬ
	
	LCD_SetColor( 0x9DD3A8);
	LCD_DrawImage( 19, 175, 83, 83, Image_Toys_83x83) ;		// ��ʾͼƬ
	
	LCD_SetColor( 0xFF8753);
	LCD_DrawImage( 141, 175, 83, 83, Image_Video_83x83) ;		// ��ʾͼƬ

	Delay_ms(2000);	
}

void LCD_HorizontalText(void)
{
	u16 time = 100;
	
	LCD_ClearTest();	// �������Ժ���

	
	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ
	LCD_SetColor(LCD_WHITE);
	LCD_SetAsciiFont(&ASCII_Font32); LCD_DisplayString(0, 0,"!#$%&'()*+,-.0123456"); 		Delay_ms(time);	// �ַ���ʾ����
	LCD_SetAsciiFont(&ASCII_Font24); LCD_DisplayString(0,32,"!#$%&'()*+,-.0123456789:"); 	Delay_ms(time);	// �ַ���ʾ����
	LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0,56,"!#$%&'()*+,-.0123456789:"); 	Delay_ms(time);	// �ַ���ʾ����
	LCD_SetAsciiFont(&ASCII_Font16); LCD_DisplayString(0,76,"!#$%&'()*+,-.0123456789:"); 	Delay_ms(time);	// �ַ���ʾ����
	LCD_SetAsciiFont(&ASCII_Font12); LCD_DisplayString(0,92,"!#$%&'()*+,-.0123456789:"); 	Delay_ms(time);	// �ַ���ʾ����
	LCD_SetColor(LIGHT_YELLOW);                                                      
	LCD_SetAsciiFont(&ASCII_Font12); LCD_DisplayString(0,104,"!#$%&'()*+,-.0123456789:"); Delay_ms(time);	// �ַ���ʾ����
	LCD_SetAsciiFont(&ASCII_Font16); LCD_DisplayString(0,116,"!#$%&'()*+,-.0123456789:"); Delay_ms(time);	// �ַ���ʾ����
	LCD_SetAsciiFont(&ASCII_Font20); LCD_DisplayString(0,132,"!#$%&'()*+,-.0123456789:"); Delay_ms(time);	// �ַ���ʾ����	
	LCD_SetAsciiFont(&ASCII_Font24); LCD_DisplayString(0,152,"!#$%&'()*+,-.0123456789:"); Delay_ms(time);	// �ַ���ʾ����	
	LCD_SetAsciiFont(&ASCII_Font32); LCD_DisplayString(0,176,"!#$%&'()*+,-.0123456"); 		Delay_ms(time);	// �ַ���ʾ����
	Delay_ms(2000);		
	
	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ
	LCD_SetAsciiFont(&ASCII_Font16);
	LCD_SetColor(LCD_BLUE);	  	  LCD_FillRect(110,  3,210,16);	LCD_DisplayString(0,  3,"LCD_BLUE");		// ����������
	LCD_SetColor(LCD_GREEN);  	  LCD_FillRect(110, 25,210,16);  LCD_DisplayString(0, 25,"LCD_GREEN");		// ����������
	LCD_SetColor(LCD_RED);    	  LCD_FillRect(110, 47,210,16);  LCD_DisplayString(0, 47,"LCD_RED");			// ����������
	LCD_SetColor(LCD_CYAN);   	  LCD_FillRect(110, 69,210,16);  LCD_DisplayString(0, 69,"LCD_CYAN");		// ����������
	LCD_SetColor(LCD_MAGENTA);	  LCD_FillRect(110, 91,210,16);  LCD_DisplayString(0, 91,"LCD_MAGENTA");	// ����������
	LCD_SetColor(LCD_YELLOW); 	  LCD_FillRect(110,113,210,16);  LCD_DisplayString(0,113,"LCD_YELLOW");		// ����������
	LCD_SetColor(LCD_GREY);   	  LCD_FillRect(110,135,210,16);	LCD_DisplayString(0,135,"LCD_GREY");		// ����������
                                                     
	LCD_SetColor(LIGHT_BLUE);	  LCD_FillRect(110,157,210,16);  LCD_DisplayString(0,157,"LIGHT_BLUE");		// ����������
	LCD_SetColor(LIGHT_GREEN);   LCD_FillRect(110,179,210,16);  LCD_DisplayString(0,179,"LIGHT_GREEN");	// ����������
	LCD_SetColor(LIGHT_RED);     LCD_FillRect(110,201,210,16);  LCD_DisplayString(0,201,"LIGHT_RED");	   // ����������
	LCD_SetColor(LIGHT_CYAN);    LCD_FillRect(110,223,210,16);  LCD_DisplayString(0,223,"LIGHT_CYAN");	   // ����������                                         
	Delay_ms(2000);	
	
	LCD_SetBackColor(LCD_BLACK); //���ñ���ɫ
	LCD_Clear(); //������ˢ����ɫ		
	LCD_SetColor(LCD_RED);    LCD_FillCircle( 80,120,80);		//���Բ��
	LCD_SetColor(LCD_GREEN);  LCD_FillCircle(160,120,80); 	//���Բ��
	LCD_SetColor(LCD_BLUE);   LCD_FillCircle(240,120,80);  	//���Բ��
	Delay_ms(2000);		
}




