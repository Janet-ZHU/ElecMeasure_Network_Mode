/*
 * ADE7758.h
 *
 *  Created on: 2017��7��19��
 *      Author: zhujingjie
 */

/*
 * Copyright (c) 2017, Janet ZHU.
 * All rights reserved.
 */

#ifndef ADE7758_H_
#define ADE7758_H_

#include "board.h"
#include "pin_mux.h"
#include "fsl_common.h"
#include "fsl_port.h"
#include  "LCD.h"

//��pin_mux.c�п����˿�ʹ�ܣ���ʼ���˿�
#define CS_0   GPIO_WritePinOutput(GPIOB, 18U, 0)//CS
#define CS_1   GPIO_WritePinOutput(GPIOB, 18U, 1)
#define DIN_0   GPIO_WritePinOutput(GPIOB, 2U, 0)//DIN
#define DIN_1  GPIO_WritePinOutput(GPIOB, 2U, 1)
#define CLK_0  GPIO_WritePinOutput(GPIOB, 3U, 0)//CLK
#define CLK_1  GPIO_WritePinOutput(GPIOB, 3U, 1)

#define DOUT    GPIO_ReadPinInput(GPIOB,1U)  //DOUT

#define 	    Addr_AWATTHR	0x01  //A���й�����
#define 	    Addr_BWATTHR	0x02  //B��
#define 	    Addr_CWATTHR	0x03  //C��
#define	        Addr_AVARHR		0x04  //A���޹�����
#define	        Addr_BVARHR		0x05  //B��
#define  	    Addr_CVARHR		0x06  //C��
#define  	    Addr_AVAHR	    0x07  //A�����ڵ���
#define  	    Addr_BVAHR		0x08  //B��
#define  	    Addr_CVAHR		0x09  //C��
#define  	    Addr_AIRMS		0x0a  //A�������Чֵ
#define  	    Addr_BIRMS		0x0b  //B��
#define  	    Addr_CIRMS		0x0c  //C��
#define  	    Addr_AVRMS		0x0d  //A���ѹ��Чֵ
#define  	    Addr_BVRMS		0x0e  //B��
#define  	    Addr_CVRMS		0x0f  //C��
#define         Addr_FREQ		0x10
#define         Addr_TEMP		0x11  //Ƭ���¶�
#define         Addr_WFORM		0x12  //���μĴ���   ����WAVMODE���
#define         Addr_OPMODE		0x13  //����ģʽ���ƼĴ���   ���趨Ϊ0x00����
#define         Addr_MMODE		0x14  //����ģʽ���ƼĴ���   ֻѡ��A B C����
#define         Addr_WAVMODE    0x15  //����ģʽѡ��Ĵ���
#define         Addr_COMPMODE	0x16  //���㷽ʽ             //������������ۼƵ��ǵ��໹������
#define         Addr_LCYCMODE	0x17
#define         Addr_MASK		0x18
#define         Addr_STATUS		0x19
#define         Addr_RSTATUS	0x1a
#define         Addr_ZXTOUT		0x1b
#define         Addr_LINCYC		0x1c
#define         Addr_SAGCYC		0x1d
#define         Addr_SAGLVL		0x1e
#define         Addr_VPINTLVL	0x1f
#define         Addr_IPINTLVL	0x20
#define         Addr_VPEAK		0x21
#define         Addr_IPEAK		0x22
#define         Addr_GAIN		0x23
#define         Addr_AVRMSGAIN	0x24 //A���ѹ����    �ߵ�ѹ������֮��    =1.732*���ѹ
#define         Addr_BVRMSGAIN	0x25 //B���ѹ����    ���ѹ����  ��  ֮��
#define         Addr_CVRMSGAIN	0x26 //C���ѹ����
#define         Addr_AIGAIN		0x27 //A�ߵ�������    �����νӷ����ߵ���=�����
#define         Addr_BIGAIN		0x28 //B�ߵ�������    �������νӷ����ߵ���=1.730*�����
#define         Addr_CIGAIN		0x29 //C�ߵ�������
#define         Addr_AWG		0x2a //A���й���������Ĵ���
#define         Addr_BWG		0x2b //B��
#define         Addr_CWG		0x2c //C��
#define         Addr_AVARG		0x2d //A���޹���������Ĵ���
#define         Addr_BVARG		0x2e //B��
#define         Addr_CVARG		0x2f //C��
#define         Addr_AVAG		0x30  //A�����ڹ�������Ĵ���
#define         Addr_BVAG		0x31  //B��
#define         Addr_CVAG		0x32  //C��
#define         Addr_AVRMSOS	0x33  //A���ѹƫ�����Ĳ����Ĵ���
#define         Addr_BVRMSOS	0x34  //B��
#define         Addr_CVRMSOS	0x35  //C��
#define         Addr_AIRMSOS	0x36  //A�����ƫ�����Ĳ����Ĵ���
#define         Addr_BIRMSOS	0x37  //B��
#define         Addr_CIRMSOS	0x38  //C��
#define         Addr_AWATTOS	0x39  //A���й�����ƫ�����Ĳ����Ĵ���
#define         Addr_BWATTOS	0x3a  //B��
#define         Addr_CWATTOS	0x3b  //C��
#define         Addr_AVAROS		0x3c  //A���޹�����ƫ�����Ĳ����Ĵ���
#define         Addr_BVAROS		0x3d  //B��
#define         Addr_CVAROS		0x3e  //C��
#define         Addr_APHCAL		0x3f  //A����λ�Ĵ���
#define         Addr_BPHCAL		0x40  //B����λ�Ĵ���
#define         Addr_CPHCAL		0x41  //C����λ�Ĵ���
#define         Addr_WDIV		0x42  //�й����ܼĴ�������λ
#define         Addr_VARDIV		0x43  //�޹����ܼĴ�������λ
#define         Addr_VADIV		0x44  //���ڵ��ܼĴ�������λ
#define         Addr_APCFNUM	0x45
#define         Addr_APCFDEN	0x46
#define         Addr_VARCFNUM	0x47
#define         Addr_VARCFDEN	0x48

#define         Addr_CHKSUM		0x7e
#define         Addr_VERSION	0x7f



unsigned int p_v[3]={100,100,199};
unsigned long int A_V=220,B_V=0x33U,C_V=219;

unsigned int i = 0;

unsigned char show1 =0x1CU;
unsigned char show2 =0x78U;
unsigned char current_unbalance = 100;
unsigned char voltage_unbalance = 100;

//ģ�����಻ƽ���
unsigned char current_unbalanceSimulate[256] = {
		0x00,0x03,0x06,0x09,0x0c,0x0f,0x12,0x15,0x19,0x1c,0x1f,0x22,0x25,0x28,0x2b,0x2e,
		0x31,0x34,0x38,0x3b,0x3e,0x41,0x44,0x47,0x4a,0x4d,0x50,0x53,0x56,0x59,0x5c,0x5f,
		0x61,0x64,0x67,0x6a,0x6d,0x70,0x73,0x75,0x78,0x7b,0x7e,0x80,0x83,0x86,0x88,0x8b,
		0x8e,0x90,0x93,0x95,0x98,0x9a,0x9d,0x9f,0xa2,0xa4,0xa7,0xa9,0xab,0xae,0xb0,0xb2,
		0xb4,0xb7,0xb9,0xbb,0xbd,0xbf,0xc1,0xc3,0xc5,0xc7,0xc9,0xcb,0xcd,0xcf,0xd1,0xd3,
		0xd4,0xd6,0xd8,0xd9,0xdb,0xdd,0xde,0xe0,0xe1,0xe3,0xe4,0xe5,0xe7,0xe8,0xe9,0xeb,
		0xec,0xed,0xee,0xef,0xf0,0xf2,0xf3,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xf9,0xfa,
		0xfb,0xfb,0xfc,0xfc,0xfd,0xfd,0xfe,0xfe,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xfe,0xfe,0xfd,0xfd,0xfc,0xfc,0xfb,
		0xfb,0xfa,0xf9,0xf9,0xf8,0xf7,0xf6,0xf5,0xf5,0xf4,0xf3,0xf2,0xf1,0xf0,0xee,0xed,
		0xec,0xeb,0xea,0xe8,0xe7,0xe6,0xe4,0xe3,0xe1,0xe0,0xde,0xdd,0xdb,0xda,0xd8,0xd6,
		0xd5,0xd3,0xd1,0xcf,0xcd,0xcb,0xc9,0xc8,0xc6,0xc4,0xc2,0xbf,0xbd,0xbb,0xb9,0xb7,
		0xb5,0xb3,0xb0,0xae,0xac,0xa9,0xa7,0xa5,0xa2,0xa0,0x9d,0x9b,0x98,0x96,0x93,0x91,
		0x8e,0x8b,0x89,0x86,0x83,0x81,0x7e,0x7b,0x78,0x76,0x73,0x70,0x6d,0x6a,0x68,0x65,
		0x62,0x5f,0x5c,0x59,0x56,0x53,0x50,0x4d,0x4a,0x47,0x44,0x41,0x3e,0x3b,0x38,0x35,
		0x32,0x2f,0x2c,0x29,0x25,0x22,0x1f,0x1c,0x19,0x16,0x13,0x10,0x0c,0x09,0x06,0x03
};

void delay(unsigned int t1) //��ʱ
{   unsigned int i,j;
    for(i=0;i<t1;i++);
    {
    	for(j=0;j<200;j++);
    }
}
void write_byte(unsigned char indata)
{
  unsigned char x,c;
    x=indata;
    CLK_0;//P2OUT &=~CLK;   //P2.1
    for(c=0;c<8;c++)
      {
       if(x & 0x80) {DIN_1;}
             else {DIN_0;}
    CLK_1;            //�½���д����
    CLK_0;
    x<<=1;
        }
}
unsigned char read_byte()
{
 unsigned char data=0;
 //CS_0; ��read8����
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=128;}  //�����ض�����
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=64;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=32;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=16;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=8;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=4;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=2;}
 CLK_0;CLK_1;delay(5); if(0x01&DOUT) {data+=1;}
 //CS_1;
 return (data);
}

void write8_ADE7758(unsigned char addr,unsigned char data)
{
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	//addr=addr|0x80;
	addr+=0x80;      //��Ĵ�����дʱ��Ҫ����ֵַ����0x80
	write_byte(addr);//��д���ַ
	delay(5);
	write_byte(data);//��д������
	CLK_0;
    CS_1;
}

void write16_ADE7758(unsigned char addr,unsigned int data)
{
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	addr=addr|0x80;     //��Ĵ�����дʱ��Ҫ����ֵַ����0x80
	write_byte(addr);//��д���ַ
	delay(5);
	write_byte(data/256);//��д�����ݸ߰�λ
	delay(5);
	write_byte(data%256);//��д�����ݵͰ�λ
	CLK_0;
	CS_1;
}
void write24_ADE7758(unsigned char addr,unsigned long int data)
{
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	addr=addr|0x80;     //��Ĵ�����дʱ��Ҫ����ֵַ����0x80
	write_byte(addr);//��д���ַ
	delay(5);
	write_byte(data/65536);//��д�����ݸ߰�λ
	delay(5);
	write_byte((data%65536)/256);//��д�������а�λ
	delay(5);
	write_byte((data%65536)%256);//��д�����ݵͰ�λ
	CLK_0;
	CS_1;
}
//***************************************************************
unsigned char read8_ADE7758(unsigned char addr)
{
	unsigned char data;
	CLK_0;
	CS_0;
	addr=addr&0x7F;//��ȡ��ַ��λΪ0
	write_byte(addr);//��д���ַ
	delay(5);
	data=read_byte();//��������
	CLK_0;
	CS_1;
	return(data);
}

unsigned int read16_ADE7758(unsigned char addr)
{
	unsigned char data1,data2;
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	write_byte(addr);//��д���ַ
	delay(5);
	data1=read_byte();//�����߰�λ
	delay(5);
	data2=read_byte();//�����Ͱ�λ
	CLK_0;
	CS_1;
	return(data1*256+data2);
}
unsigned long int read24_ADE7758(unsigned char addr)
{
	unsigned char data1,data2,data3;
	CLK_0;
	CS_0;
	addr=addr&0x7F;
	write_byte(addr);//��д���ַ
	delay(5);
	data1=read_byte();//�����߰�λ
	delay(5);
	data2=read_byte();//�����а�λ
	delay(5);
	data3=read_byte();//�����Ͱ�λ
	CLK_0;
	CS_1;
	return((unsigned long int)(data1*65536+data2*256+data3));
}

void ADE7758_Init()
{
    /* Initialize LPUART0 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortB);

    port_pin_config_t config;
    config.pullSelect = kPORT_PullUp;
    config.mux = kPORT_MuxAsGpio;
    PORT_SetPinConfig(PORTC, 4U, &config); //PTC4����Ϊ����

   //��������
    PORT_SetPinConfig(PORTB, 18U, &config); //PTC19   //���ڶŰ��ߵĽӿڲ�ƥ�䣬��ɽӴ�������ʹ�õ�������
    PORT_SetPinConfig(PORTB, 2U, &config); //PTC16   //�ɴ˵õ�һ����ѵ���Ժ����ѡ�ú��ʵĽӲ�ڽ������
    PORT_SetPinConfig(PORTB, 3U,  &config); //PTC3    //������ϸ�Ĳ�Ʒ
    PORT_SetPinConfig(PORTB, 1U,  &config); //PTC2  //�����Ӧ����9V��ص������㡣����

    //��ΪI/O
     PORT_SetPinMux(PORTB, 18U, kPORT_MuxAsGpio); //CS
     PORT_SetPinMux(PORTB, 2U, kPORT_MuxAsGpio); //DOUT SO --  MI
     PORT_SetPinMux(PORTB, 3U, kPORT_MuxAsGpio);  //CLK
     PORT_SetPinMux(PORTB, 1U, kPORT_MuxAsGpio);  //DIN  SI --  MO



	 /* Define the init structure for the ADE7758 controller's OUT and IN pin (for MCU) */
	    gpio_pin_config_t ADE7758_config_OUT =  { kGPIO_DigitalOutput, 1, };
	    gpio_pin_config_t ADE7758_config_IN =   { kGPIO_DigitalInput,  0, };

	 /* Init output ADE7758 GPIO. */
	    GPIO_PinInit(GPIOB, 18U, &ADE7758_config_OUT);
	    GPIO_PinInit(GPIOB, 2U,  &ADE7758_config_OUT);
	    GPIO_PinInit(GPIOB, 3U,  &ADE7758_config_OUT);
	    GPIO_PinInit(GPIOB, 1U,  &ADE7758_config_IN);

	  //write8_ADE7758(Addr_OPMODE,0x40);//������λ
	  //Software Chip Reset. A data transfer to the ADE7758 should not take place for at least 166 ��s after a software reset.
       write8_ADE7758(Addr_OPMODE,0x00);//ʹ���������
       write24_ADE7758(Addr_MASK,0x000007);//��λ����λ  ����־д���жϼĴ��� ,���������Ĵ�����������һ��ʱ�����ж�
}
//************************************************ **************************
void  V_RMS()          //��������  ���ѹ
{

   A_V=read24_ADE7758(Addr_AVRMS);
   B_V=read8_ADE7758(Addr_COMPMODE);
   C_V=read8_ADE7758(Addr_LCYCMODE);
   p_v[0]=(unsigned int)(0.5*A_V*1000/279701);//0.5V   50HZ ��Ӧ����1678210
   //p_v[1]=B_V; p_v[2]=C_V;
  // p_v[1]=(unsigned int)(0.5*B_V*1000/1678210);
  // p_v[2]=(unsigned int)(0.5*C_V*1000/1678210);
   show_figure4(p_v[0]);
   //voltage_unbalance = max(p_v[1], p_v[2],p_v[3]) - min(p_v[1], p_v[2],p_v[3])/max(p_v[1], p_v[2],p_v[3]) ;
   //��ʾ���಻ƽ���
   	for( i = 0; i <= 255; i = i + 4 )
   	    	{
   	    		current_unbalanceSimulate[i] = current_unbalanceSimulate[i] - i/3;
   	    		show_curve(current_unbalanceSimulate[i]);
   	    	}
   show_curve(voltage_unbalance);
}

#endif /* ADE7758_H_*/

