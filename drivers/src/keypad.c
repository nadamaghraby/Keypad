#include "stm32f4xx.h"
#include"gpio.h"
const int no_rows = 4;
const int no_cols = 3;
char rows[4]={1,2,3,4}; //fill the array input
char cols[3]={5,6,7}; //fill the array output
char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array
char currentvalue;
void KeyPad_INIT(void)
{
	GPIO_Init(GPIOA,8,1,0,1);
	GPIO_Init(GPIOA,9,1,0,1);
	GPIO_Init(GPIOA,10,1,0,1);
	GPIO_Init(GPIOA,11,1,0,1);
	//pin 5,6,7 port A
	for(int i=0;i<no_cols;i++){
		GPIO_Init(GPIOA,cols[i],1,0,1);
	}
	//pin 1,2,3,4 in port A output
	for (int i=0;i<no_rows;i++){
		GPIO_Init(GPIOA,rows[i],0,0,1);
	}
	// set input and ouput pins
		// get pins from raw and set it as input
		// get pins from cols and set it as output
	// hint use gpio driver functions
}
void KeyPad_MANAGE(void)
{
	//nested for loop to check which button is pressed
	//if pressed wait until released then change the value;
	//call KeypadCallouts_KeyPressNotificaton
	for(int i=0;i<no_cols;i++)
	{
		for(int k = 0; k<no_cols;k++)
		{
			GPIO_Write(GPIOA,cols[k],1);
		}

		GPIO_Write(GPIOA,cols[i],0);

		for(int j=0;j<no_rows;j++){
			char x= GPIO_Read(GPIOA,rows[j]);
			if(x==0)
			{

				while(GPIO_Read(GPIOA,rows[j])==0);
				currentvalue=lookupTable[j][i];
				KeypadCallouts_KeyPressNotificaton();
			}
		}

	}
}
char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
// set seven segment
	char m=KeyPad_GET_VALUE();
	switch(m)
	{
	case 0: //9
			GPIO_Write(GPIOA,8,0);
			GPIO_Write(GPIOA,9,0);
			GPIO_Write(GPIOA,10,0);
			GPIO_Write(GPIOA,11,0);
			for(int i =0 ; i<50000;i++){}
	break;
	case 1:
		GPIO_Write(GPIOA,8,1);
		GPIO_Write(GPIOA,9,0);
		GPIO_Write(GPIOA,10,0);
		GPIO_Write(GPIOA,11,0);
		for(int i =0 ; i<50000;i++){}
	break;
	case 2: //1

			GPIO_Write(GPIOA,8,0);
			GPIO_Write(GPIOA,9,1);
			GPIO_Write(GPIOA,10,0);
			GPIO_Write(GPIOA,11,0);
			for(int i =0 ; i<50000;i++){}
	break;
	case 3://2

			GPIO_Write(GPIOA,8,1);
			GPIO_Write(GPIOA,9,1);
			GPIO_Write(GPIOA,10,0);
			GPIO_Write(GPIOA,11,0);
			for(int i =0 ; i<50000;i++){}
	break;
	case 4:

			GPIO_Write(GPIOA,8,0);
			GPIO_Write(GPIOA,9,0);
			GPIO_Write(GPIOA,10,1);
			GPIO_Write(GPIOA,11,0);
			for(int i =0 ; i<50000;i++){}
	break;
	case 5: //4

			GPIO_Write(GPIOA,8,1);
			GPIO_Write(GPIOA,9,0);
			GPIO_Write(GPIOA,10,1);
			GPIO_Write(GPIOA,11,0);
			for(int i =0 ; i<50000;i++){}
		break;
	case 6://5

			GPIO_Write(GPIOA,8,0);
			GPIO_Write(GPIOA,9,1);
			GPIO_Write(GPIOA,10,1);
			GPIO_Write(GPIOA,11,0);
			for(int i =0 ; i<50000;i++){}
	break;
	case 7://6

			GPIO_Write(GPIOA,8,1);
			GPIO_Write(GPIOA,9,1);
			GPIO_Write(GPIOA,10,1);
			GPIO_Write(GPIOA,11,0);
			for(int i =0 ; i<50000;i++){}
		break;
	case 8://7

			GPIO_Write(GPIOA,8,0);
			GPIO_Write(GPIOA,9,0);
			GPIO_Write(GPIOA,10,0);
			GPIO_Write(GPIOA,11,1);
			for(int i =0 ; i<50000;i++){}
		break;
	case 9: //8

			GPIO_Write(GPIOA,8,1);
			GPIO_Write(GPIOA,9,0);
			GPIO_Write(GPIOA,10,0);
			GPIO_Write(GPIOA,11,1);
			for(int i =0 ; i<50000;i++){}
	break;

	}
}
