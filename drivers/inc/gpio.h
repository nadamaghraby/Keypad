/*
 * gpio.h
 *
 *  Created on: May 12, 2022
 *      Author: Dell
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin,char type);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin);

void KeyPad_INIT(void);
void KeyPad_MANAGE(void);
char KeyPad_GET_VALUE(void);
void KeypadCallouts_KeyPressNotificaton(void);


#endif /* INC_GPIO_H_ */
