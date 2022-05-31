#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"

int main(void)
{

	KeyPad_INIT();
	// super loop
	while(1)
	{
		KeyPad_MANAGE();

	}
}
