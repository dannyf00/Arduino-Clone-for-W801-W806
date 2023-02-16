#ifndef _W801DUINO_H
#define _W801DUINO_H

//Arduino clone for W801: 32-bit C_SKY chip from Winner Micro
//version history
// v0.1: 09/30/2022 - initial development, from STM32Duino
// v0.2: 10/01/2022 - ported over GPIO, ticks, and uart functions
// v0.3: 10/02/2022 - clock management ported over initially
// v0.4: 10/08/2022 - CDK workflow automated
// v0.5: 10/14/2022 - adc implemented
// v0.6: 10/15/2022 - fixed systick(): needed "volatile" on two variables -> likely a compiler bug
// v0.7: 10/15/2022 - RTC, PWM and ADC (temp/Vcc) are working.
// v0.7a:10/22/2022 - software i2c added
// v0.7b:10/26/2022 - true / pseudo random number generator implemented
// v0.7c:11/05/2022 - arand1/4/8/16/32(): using adc to generate random numbers
// v0.7d:11/29/2022 - added circular buffer
// v0.7e:12/23/2022 - implemented uart transmission over a circular buffer
//
//
//
//               |=======================|
//               |                       |
//     40M Xtal->|                  PB19 |>---------> UART0TX
//               |                  PB20 |<---------< UART0RX
//               |                       |
//               |                       |
//               |                  PB11 |>---------> LED0 (active low)
//               |                  PB16 |>---------> LED1 (active low)
//               |                  PB17 |>---------> LED2 (active low)
//               |                  PB18 |>---------> LED3 (active low)
//               |                  PB26 |>---------> LED4 (active low)
//               |                  PB25 |>---------> LED5 (active low)
//               |                  PB5  |>---------> LED6 (active low)
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |                       |
//               |=======================|
//
//
//
#include <stdio.h>							//we use *FILE in fputc()
#include <string.h>							//we use strcpy
#include "wm_hal.h"							//we use w806sdk

//configuration
//#define USE_HALGPIO						//use hal for gpio
//#define USE_HALUART						//use hal for uart
//#define USE_HALTICK						//use hal tick for time base generation (1ms default). othrewise, in 1/F_CPU ticks
#define CPU_CLK			CPU_CLK_10M			//cpu speed, 240M/160M/80M/40M/2M + 120M/24M/20M/12M/10M/8M/4M
#define uRAM_SIZE		32					//uxPrint buffer size, in bytes

//configuration for circular buffer
/*******NOTE********************************/
/******cBUFF_SIZE: must be power of 2*******/
/*******************************************/
#define cBUFF_SIZE 		256					//must be power of 2: 0..256 -> for buffers with more than 256 elements, change data type for writeIndex/readIndex
typedef char cbuffer_t;						//storage unit for the buffer
//end configuration for circular buffer

//uart pin assignments
//#define UART0TX2PIN()	UART0TX2PB19()		//assign uart0 tx to a pin: pb19, pb27
//#define UART0RX2PIN()	UART0RX2PB20()		//assign uart0 rx to a pin: pb20, pb28
#define UART1TX2PIN()	UART1TX2PB6()		//assign uart1 tx to a pin: pb6 , pb31
#define UART1RX2PIN()	UART1RX2PB7()		//assign uart1 rx to a pin: pb7 , pb16
#define UART2TX2PIN()	UART2TX2PB2()		//assign uart2 tx to a pin: pb2 , pa2
#define UART2RX2PIN()	UART2RX2PB3()		//assign uart2 rx to a pin: pb3 , pa3
#define UART3TX2PIN()	UART3TX2PB0()		//assign uart3 tx to a pin: pb0 , pa5
#define UART3RX2PIN()	UART3RX2PB1()		//assign uart3 rx to a pin: pb1 , pa6
#define UART4TX2PIN()	UART4TX2PB4()		//assign uart4 tx to a pin: pb4 , pa8
#define UART4RX2PIN()	UART4RX2PB5()		//assign uart4 rx to a pin: pb5 , pa9
#define UART5TX2PIN()	UART5TX2PB18()		//assign uart4 tx to a pin: pa12, pa8 , pb18
#define UART5RX2PIN()	UART5RX2PA13()		//assign uart4 rx to a pin: pa13, pa9 , pb17

//pwm pin assignments
#define PWM02PIN()		PWM02PB0()			//assign pwm pins: pb0 , pa2 , pa10, pb12, pb19
#define PWM12PIN()		PWM12PB1()			//assign pwm pins: pb1 , pa3 , pa11, pb13, pb20
#define PWM22PIN()		PWM22PB2()			//assign pwm pins: pb2 , pa0 , pa12, pb14, pb24
#define PWM32PIN()		PWM32PB25()			//assign pwm pins: pb3 , pa1 , pa13, pb15, pb25
#define PWM42PIN()		PWM42PB16()			//assign pwm pins: pa7 , pa4 , pa14, pb16, pb26

//adc pins - fixed
#define ADC02PIN()		ADC02PA1()			//adc0 input is PA1
#define ADC12PIN()		ADC12PA2()			//adc1 input is PA2
#define ADC22PIN()		ADC22PA3()			//adc2 input is PA3
#define ADC32PIN()		ADC32PA4()			//adc3 input is PA4

//spi pins
#define SPISCK2PIN()	SPISCK2PB1()		//spi sck  to pb1, pb2, pb15, pb24
#define SPIMOSI2PIN()	SPIMOSI2PA7()		//spi mosi to pa7, pb5, pb17, pb26
#define SPIMISO2PIN()	SPIMISO2PB0()		//spi miso to pb0, pb3, pb16, pb25

//i2c pins
#define I2CSCL2PIN()	I2CSCL2PA1()		//i2c scl to pa1, pb20
#define I2CSDA2PIN()	I2CSDA2PA2()		//i2c sda to pa2, pb19

#define sI2CSCLPIN		PB1					//software i2c scl pin
#define sI2CSDAPIN		PB2					//software i2c sda pin

#define LED0			PB11
#define LED1			PB16
#define LED2			PB17
#define LED3			PB18
#define LED4			PB26
#define LED5			PB25
#define LED6			PB5
//end configuration

//global defines
#define F_PLL			(480000000ul)		//dpll output frequency, fixed at 480Mhz
#define F_CPU			SystemCoreClock()	//return system coreclock
#define F_WLAN			WLANClock()			//wlan clock
#define F_PHB			APBClock()			//periopheral clock - needs more work***
#define SysTick_PR		(1<<24)				//systick period
#define F_ADC			1000				//adc frequency, 1000Hz max
#define F_SPI			1000000ul			//spi speed
#define F_I2C			400000ul			//i2c speed
#define F_sI2C			100000ul			//frquency for software i2c

//per datasheet, this controls the VCM input to the PGA, thus the adc results. 
//only applied in single ended mode (ADC_CH0..3)
//cannot be found in the header files however :)
//bit 16..11, 0x3f max. VCM = 1.311v, step = 39.1mv
#define PGA_VCMIN		(*(volatile uint32_t *) (0x40000D20))	

//only use the cpu divider values below to set clocks
//all other clocks are configured from CPU clock
//additional CPU_CLK values
//must be divisible by 12
#define CPU_CLK_120M	4					//480/4 =120Mhz
//>12: CLK_CLK must be multiples of 4
#define CPU_CLK_24M		20					//480/20=24Mhz
#define CPU_CLK_20M		24					//480/24=20Mhz
#define CPU_CLK_12M		40					//480/40=12Mhz
#define CPU_CLK_10M		48					//480/48=10Mhz
#define CPU_CLK_8M		60					//480/60=8Mhz
#define CPU_CLK_4M		120					//480/120=4Mhz
//configure systemcoreclock
#define SystemCoreClock10MHZ()				SystemCoreClockConfig(CPU_CLK_10M)
#define SystemCoreClock20MHZ()				SystemCoreClockConfig(CPU_CLK_20M)
#define SystemCoreClock40MHZ()				SystemCoreClockConfig(CPU_CLK_40M)
#define SystemCoreClock80MHZ()				SystemCoreClockConfig(CPU_CLK_80M)
#define SystemCoreClock120MHZ()				SystemCoreClockConfig(CPU_CLK_120M)
#define SystemCoreClock240MHZ()				SystemCoreClockConfig(CPU_CLK_240M)

//pin assignment macros
//uart pin assignments
#define UART0TX2PB19()	pinAFIO(PB19, 1)	//uart0 TX to PB19, 0b00
#define UART0TX2PB27()	pinAFIO(PB27, 2)	//uart0 TX to PA27, 0b01
#define UART0RX2PB20()	pinAFIO(PB20, 1)	//uart0 RX to PB20, 0b00
#define UART0RX2PB28()	pinAFIO(PB28, 2)	//uart0 RX to PB28, 0b01

#define UART1TX2PB6()	pinAFIO(PB6 , 1)	//uart1 TX to PB6 , 0b00
#define UART1TX2PB31()	pinAFIO(PB31, 2)	//uart1 TX to PB31, 0b01
#define UART1RX2PB7()	pinAFIO(PB7 , 1)	//uart1 RX to PB7 , 0b00
#define UART1RX2PB16()	pinAFIO(PB16, 4)	//uart1 RX to PB16, 0b11

#define UART2TX2PB2()	pinAFIO(PB2 , 3)	//uart2 TX to PB2 , 0b10
#define UART2TX2PA2()	pinAFIO(PA2 , 2)	//uart2 TX to PA2 , 0b01
#define UART2RX2PB3()	pinAFIO(PB3 , 3)	//uart2 RX to PB3 , 0b10
#define UART2RX2PA3()	pinAFIO(PA3 , 2)	//uart2 RX to PA3 , 0b01

#define UART3TX2PB0()	pinAFIO(PB0 , 3)	//uart3 TX to PB0 , 0b10
#define UART3TX2PA5()	pinAFIO(PA5 , 1)	//uart3 TX to PA5 , 0b00
#define UART3RX2PB1()	pinAFIO(PB1 , 3)	//uart3 RX to PB1 , 0b10
#define UART3RX2PA6()	pinAFIO(PA6 , 1)	//uart3 RX to PA6 , 0b00

#define UART4TX2PB4()	pinAFIO(PB4 , 3)	//uart4 TX to PB4 , 0b10
#define UART4TX2PA8()	pinAFIO(PA8 , 2)	//uart4 TX to PA8 , 0b01
#define UART4RX2PB5()	pinAFIO(PB5 , 3)	//uart4 RX to PB5 , 0b10
#define UART4RX2PA9()	pinAFIO(PA9 , 2)	//uart4 RX to PA9 , 0b01

#define UART5TX2PA12()	pinAFIO(PA12, 2)	//uart5 TX to PA12, 0b01
#define UART5TX2PA8()	pinAFIO(PA8 , 3)	//uart5 TX to PA8 , 0b10
#define UART5TX2PB18()	pinAFIO(PB18, 1)	//uart5 TX to PB18, 0b00
#define UART5RX2PA13()	pinAFIO(PA13, 2)	//uart5 RX to PA13, 0b01
#define UART5RX2PA9()	pinAFIO(PA9 , 3)	//uart5 RX to PA9 , 0b10
#define UART5RX2PB17()	pinAFIO(PB17, 1)	//uart5 RX to PB17, 0b00

//pwm pin assignments
#define PWM02PB0()		pinAFIO(PB0 , 1)	//pwm0 to pb0 , 0b00
#define PWM02PB19()		pinAFIO(PB19, 2)	//pwm0 to pb19, 0b01
#define PWM02PB12()		pinAFIO(PB12, 2)	//pwm0 to pb12, 0b01
#define PWM02PA2()		pinAFIO(PA2 , 3)	//pwm0 to pa2 , 0b10
#define PWM02PA10()		pinAFIO(PA10, 3)	//pwm0 to pa10, 0b10

#define PWM12PB1()		pinAFIO(PB1 , 1)	//pwm1 to pb1 , 0b00
#define PWM12PB20()		pinAFIO(PB20, 2)	//pwm1 to pb20, 0b01
#define PWM12PB13()		pinAFIO(PB13, 3)	//pwm1 to pb13, 0b10
#define PWM12PA3()		pinAFIO(PA3 , 3)	//pwm1 to pa3 , 0b10
#define PWM12PA11()		pinAFIO(PA11, 3)	//pwm1 to pa11, 0b10

#define PWM22PA0()		pinAFIO(PA0 , 3)	//pwm2 to pa0, 0b10
#define PWM22PB2()		pinAFIO(PB2 , 1)	//pwm2 to pb2, 0b00
#define PWM22PA12()		pinAFIO(PA12, 3)	//pwm2 to pb12, 0b10
#define PWM22PB14()		pinAFIO(PB14, 2)	//pwm2 to pb14, 0b01
#define PWM22PB24()		pinAFIO(PB24, 2)	//pwm2 to pb24, 0b01

#define PWM32PA1()		pinAFIO(PA1 , 3)	//pwm1 to pa1 , 0b10
#define PWM32PB3()		pinAFIO(PB3 , 1)	//pwm1 to pb3 , 0b00
#define PWM32PA13()		pinAFIO(PA13, 3)	//pwm1 to pa13, 0b10
#define PWM32PB15()		pinAFIO(PB15, 2)	//pwm1 to pb15, 0b01
#define PWM32PB25()		pinAFIO(PB25, 2)	//pwm1 to pb25, 0b01

#define PWM42PA4()		pinAFIO(PA4 , 3)	//pwm4 to pa4 , 0b10
#define PWM42PA7()		pinAFIO(PA7 , 1)	//pwm4 to pa7 , 0b00
#define PWM42PA14()		pinAFIO(PA14, 3)	//pwm4 to pa14, 0b10
#define PWM42PB16()		pinAFIO(PB16, 2)	//pwm4 to pb16, 0b01
#define PWM42PB26()		pinAFIO(PB26, 2)	//pwm4 to pb26, 0b01

//adc input pins
//why enable pullup? wh_gpio_ex.h has the same setting for opt6 and opt7.
//set PULLUP_EN to disable pullup, clear pullup_en to enable pullup
//set pulldown_en to enable pulldown, clear PULLDOWN_EN to disable pulldown
#define ADC02PA1()		pinAFIO(PA1, 7)		//do {IO_CLR(GPIOA->AF_SEL, 1<<1); IO_CLR(GPIOA->DIR, 1<<1); IO_SET(GPIOA->PULLUP_EN, 1<<1); IO_CLR(GPIOA->PULLDOWN_EN, 1<<1);} while (0)
#define ADC12PA2()		pinAFIO(PA2, 7)		//do {IO_CLR(GPIOA->AF_SEL, 1<<2); IO_CLR(GPIOA->DIR, 1<<2); IO_SET(GPIOA->PULLUP_EN, 1<<2); IO_CLR(GPIOA->PULLDOWN_EN, 1<<2);} while (0)
#define ADC22PA3()		pinAFIO(PA3, 7)		//do {IO_CLR(GPIOA->AF_SEL, 1<<3); IO_CLR(GPIOA->DIR, 1<<3); IO_SET(GPIOA->PULLUP_EN, 1<<3); IO_CLR(GPIOA->PULLDOWN_EN, 1<<3);} while (0)
#define ADC32PA4()		pinAFIO(PA4, 7)		//do {IO_CLR(GPIOA->AF_SEL, 1<<4); IO_CLR(GPIOA->DIR, 1<<4); IO_SET(GPIOA->PULLUP_EN, 1<<4); IO_CLR(GPIOA->PULLDOWN_EN, 1<<4);} while (0)

//spi pin assignments
#define SPISCK2PB1()	pinAFIO(PB1, 2)		//spi sck to pb1 , opt2
#define SPISCK2PB2()	pinAFIO(PB2, 2)		//spi sck to pb2 , opt2
#define SPISCK2PB15()	pinAFIO(PB15,3)		//spi sck to pb15, opt3
#define SPISCK2PB24()	pinAFIO(PB24,1)		//spi sck to pb24, opt1

#define SPIMOSI2PA7()	pinAFIO(PA7, 2)		//spi mosi to pa7, opt2
#define SPIMOSI2PB5()	pinAFIO(PB5, 1)		//spi mosi to pb5, opt1
#define SPIMOSI2PB17()	pinAFIO(PB17,3)		//spi mosi to pb17,opt3
#define SPIMOSI2PB26()	pinAFIO(PB26,1)		//spi mosi to pb26,opt1

#define SPIMISO2PB0()	pinAFIO(PB0, 2)		//spi miso to pb0, opt2
#define SPIMISO2PB3()	pinAFIO(PB3, 2)		//spi miso to pb3, opt2
#define SPIMISO2PB16()	pinAFIO(PB16,3)		//spi miso to pb16,opt3
#define SPIMISO2PB25()	pinAFIO(PB25,1)		//spi miso to pb25,opt1

//i2c pin assignments
#define I2CSCL2PA1()	pinAFIO(PA1, 2)		//i2c scl to pa1, opt2
#define I2CSCL2PB20()	pinAFIO(PB20,4)		//i2c scl to pb20,opt4
#define I2CSDA2PA2()	pinAFIO(PA2, 2)		//i2c sda to pa2, opt2
#define I2CSDA2PB19()	pinAFIO(PB19,4)		//i2c sda to pb19,opt4

//macros that should have been in the header file!
#define ISR				__attribute__((isr))		//declare isr

//reg maniputation macros - the OEM macros are too painful to use
#define REG_WRITE(reg, val)		tls_reg_write32(reg, val)
#define REG_READ(reg)			tls_reg_read32(reg)
#define REG_SET(reg, bits)		REG_WRITE(reg, REG_READ(reg) | (bits))
#define REG_CLR(reg, bits)		REG_WRITE(reg, REG_READ(reg) &~(bits))
#define REG_FLP(reg, bits)		REG_WRITE(reg, REG_READ(reg) ^ (bits))
#define REG_GET(reg)			REG_READ(reg)

//circular buffer
//circular buffer to store char
typedef struct {
    cbuffer_t buffer[cBUFF_SIZE];		//buffer
    uint8_t writeIndex;					//index for the current write-> advance first and then write
    uint8_t readIndex;					//index for the current read -> advance first and then read
} CB_TypeDef;

//gpio
//port manipulation macros for PIC.
//port/gpio oriented macros
#define IO_SET(port, pins)					port |= (pins)				//set bits on port
#define IO_CLR(port, pins)					port &=~(pins)				//clear bits on port
#define IO_FLP(port, pins)					port ^= (pins)				//flip bits on port
#define IO_GET(port, pins)					((port) & (pins))			//return bits on port
//gpio port based
#define GIO_SET(port, pins)					IO_SET(port->DATA, (pins))				//set bits on port
#define GIO_CLR(port, pins)					IO_CLR(port->DATA, (pins))				//clear bits on port
#define GIO_FLP(port, pins)					IO_FLP(port->DATA, (pins))				//flip bits on port
#define GIO_GET(port, pins)					IO_GET(port->DATA, (pins))			//return bits on port
//set a pin to output/input
#define GIO_OUT(port, pins)					IO_SET(port->DIR, pins)					//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_OUT_PP_LOW_FAST)
#define GIO_IN(port, pins)					IO_CLR(port->DIR, pins)					//IO_IN(port, pins)				//_GPIO_Init(GPIOx, GPIO_Pins, GPIO_MODE_IN_FL_NO_IT)

//pin enum - matches GPIO_PinDef[]
//not all ports / pins are available
typedef enum {
#if defined(GPIOA)
	PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
	PA16,PA17,PA18,PA19,PA20,PA21,PA22,PA23,PA24,PA25,PA26, PA27, PA28, PA29, PA30, PA31,
#endif		//GPIOA
#if defined(GPIOB)
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
	PB16,PB17,PB18,PB19,PB20,PB21,PB22,PB23,PB24,PB25,PB26, PB27, PB28, PB29, PB30, PB31,
#endif		//GPIOB
#if defined(GPIOC)
	PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, PC8, PC9, PC10, PC11, PC12, PC13, PC14, PC15,
	PC16,PC17,PC18,PC19,PC20,PC21,PC22,PC23,PC24,PC25,PC26, PC27, PC28, PC29, PC30, PC31,
#endif		//GPIOC
#if defined(GPIOD)
	PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7, PD8, PD9, PD10, PD11, PD12, PD13, PD14, PD15,
	PD16,PD17,PD18,PD19,PD20,PD21,PD22,PD23,PD24,PD25,PD26, PD27, PD28, PD29, PD30, PD31,
#endif		//GPIOD
#if defined(GPIOE)
	PE0, PE1, PE2, PE3, PE4, PE5, PE6, PE7, PE8, PE9, PE10, PE11, PE12, PE13, PE14, PE15,
	PE16,PE17,PE18,PE19,PE20,PE21,PE22,PE23,PE24,PE25,PE26, PE27, PE28, PE29, PE30, PE31,
#endif		//GPIOE
#if defined(GPIOF)
	PF0, PF1, PF2, PF3, PF4, PF5, PF6, PF7, PF8, PF9, PF10, PF11, PF12, PF13, PF14, PF15,
	PF16,PF17,PF18,PF19,PF20,PF21,PF22,PF23,PF24,PF25,PF26, PF27, PF28, PF29, PF30, PF31,
#endif		//GPIOF
#if defined(GPIOG)
	PG0, PG1, PG2, PG3, PG4, PG5, PG6, PG7, PG8, PG9, PG10, PG11, PG12, PG13, PG14, PG15,
	PG16,PG17,PG18,PG19,PG20,PG21,PG22,PG23,PG24,PG25,PG26, PG27, PG28, PG29, PG30, PG31,
#endif		//GPIOG
#if defined(GPIOH)
	PH0, PH1, PH2, PH3, PH4, PH5, PH6, PH7, PH8, PH9, PH10, PH11, PH12, PH13, PH14, PH15,
	PH16,PH17,PH18,PH19,PH20,PH21,PH22,PH23,PH24,PH25,PH26, PH27, PH28, PH29, PH30, PH31,
#endif		//GPIOH
	PMAX
} PIN_TypeDef;

//map pin number to GPIOx
typedef struct {
	GPIO_TypeDef *gpio;					//gpio for a pin
	uint32_t mask;						//pin mask - 16-bit port
} PIN2GPIO;

//end gpio

//systick/coret
//end systick/coret

//arduino declaration
#define INPUT				0
#define OUTPUT				1			//(!INPUT)
#define PULLUP				2
#define PULLDOWN			3

#define LOW					0
#define HIGH				(!LOW)

#define PI 					3.1415926535897932384626433832795
#define HALF_PI 			(PI / 2)							//1.5707963267948966192313216916398
#define TWO_PI 				(PI + PI)							//6.283185307179586476925286766559
#define DEG_TO_RAD 			(TWO_PI / 360)						//0.017453292519943295769236907684886
#define RAD_TO_DEG 			(360 / TWO_PI)						//57.295779513082320876798154814105
#define EULER 				2.718281828459045235360287471352	//Euler's number

#define SERIAL  			0x0
#define DISPLAY 			0x1

#define LSBFIRST 			0
#define MSBFIRST 			1									//(!LSBFIRST)							//1

#define CHANGE 				1
#define FALLING 			2
#define RISING 				3

#ifndef min
#define min(a,b) 			((a)<(b)?(a):(b))
#endif
#ifndef max
#define max(a,b) 			((a)>(b)?(a):(b))
#endif
#define abs(x) 				((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
//#define round(x)     		((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) 		((deg)*DEG_TO_RAD)
#define degrees(rad) 		((rad)*RAD_TO_DEG)
#define sq(x) 				((x)*(x))

#define interrupts() 		ei()
#define noInterrupts() 		di()

#define clockCyclesPerMillisecond() 	( F_CPU / 1000L )
#define clockCyclesPerMicrosecond() 	( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) 	( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) 	( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) 			((uint8_t) ((w) & 0xff))
#define highByte(w) 		((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) 	((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define bit(n)				(1ul<<(n))

#define false				0
#define true				1

//characters
#define isAlphaNumeric(c)	isalnum(c)
#define isAlpha(c)			isalpha(c)
#define isAscii(c)			isascii(c)
#define isWhitespace(c)		isblank(c)
#define isControl(c)		iscntrl(c)
#define isDigit(c)			isdigit(c)
#define isGraph(c)			isgraph(c)
#define isLowerCase(c)		islower(c)
#define isPrintable(c)		isprint(c)
#define isPunct(c)			ispunct(c)
#define isSpace(c)			isspace(c)
#define isUpperCase(c)		isupper(c)
#define isHexadecimalDigit(c)	isxdigit(c)

//external setup/loop - defined by user
extern void setup(void);
extern void loop(void);

//interrupts
#define ei()				__enable_irq()				//enable global interrupt
#define di()				__disable_irq()				//disable global interrupt

//random number
#define randomSeed(seed)	srand(seed)
#define random(max)			random2(0, max)
#define random2(min, max)	((min) + (int32_t) ((max) - (min)) * rand() / 32768)

//GPIO
#define inline											//suppress inline
inline void pinMode(PIN_TypeDef pin, uint8_t mode);
inline void digitalWrite(PIN_TypeDef pin, uint8_t mode);
inline int digitalRead(PIN_TypeDef pin);
#define pinFlip(pin)		digitalWrite(pin, !digitalRead(pin))
inline void pinPullup(PIN_TypeDef pin, uint8_t val);	//enable pull-up
inline void pinPulldown(PIN_TypeDef pin, uint8_t val);	//enable pull-down
inline void pinAFIO(PIN_TypeDef pin, uint8_t af); 		//configure alternative functions

//time base
uint32_t systicks(void);								//use systick as time base
#define ticks()				systicks()					//use coretick / dwt for timing / tick generation
#define coreticks()			systicks()					//use dwt/coretick as time base

#define millis()			(ticks() / cyclesPerMillisecond())
#define micros()			(ticks() / cyclesPerMicrosecond())
void delayTks(uint32_t tks);							//delay a given number of ticks
//void delayUs(uint32_t us);							//delay a given number of micro seconds
//void delayMs(uint32_t ms);							//delay a given number of millie seconds
#define delayUs(us)				delayTks((us) * cyclesPerMicrosecond())
#define delayMs(ms)				delayTks((ms) * cyclesPerMillisecond())
#define delay(ms)				delayMs(ms)
#define delayMilliseconds(ms)	delayMs(ms)
#define delayMicroseconds(us)	delayUs(us)
#define cyclesPerMicrosecond()			(F_CPU / 1000000ul)
#define cyclesPerMillisecond()			(F_CPU / 1000)

//install systick isr
//activate the isr handler
void systickAttachISR(void (*isrptr)(void));
#define systickDetachISR()		systickAttachISR(empty_handler())

//advanced IO
//void tone(void);										//tone frequency specified by F_TONE in STM8Sduino.h
//void noTone(void);
//shiftin/out: bitOrder = MSBFIRST or LSBFIRST
uint8_t shiftIn(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder);
void shiftOut(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder, uint8_t val);
uint32_t pulseIn(PIN_TypeDef pin, uint8_t state);		//wait for a pulse and return timing

//pwm output
//dc = 0x00..0x0fff for pwm2/3/4/5, 0x00..0xffff for pwm1
//RP4=PWM1, RP12=PWM2, RP13=PWM3, RP14=PWM4, RP15=PWM5
void analogWrite(uint8_t pin, uint16_t dc);				//not implemented - could use a wrapper however.

//analog read on ADC1
//read DRL first for right aligned results
//uint16_t analogRead(uint8_t pin);

//analog reference - default to AVdd-AVss
//Vref sources: 0->Vref = AVdd-AVss, 1->Vref+-AVss, 2->AVdd-Vref-, 3->Vref+ - Vref-
//void analogReference(uint8_t Vref);

//interrupts
//install external interrupt handler
//mode 1: falling edge, 0: rising edge
//void attachInterrupt(uint8_t intx, void (*isrptr) (void), uint8_t mode);
//void detachInterrupt(uint8_t intx);

//change notification interrupts
//install user CN interrupt handler
//void attachCNInterrupt(void (*isrptr) (void));
//void detachCNInterrupt(void);
//void activateCNInterrupt(uint8_t cnx, uint8_t pue);
//void deactivateCNInterrupt(uint8_t cnx);

//global variables

//return system core clock
uint32_t SystemCoreClockConfig(uint32_t clk);		//config system clocks (F_CPU, F_WLAN and F_APB), return F_CPU
uint32_t SystemCoreClockUpdate(void);				//update F_CPU, F_WLAN and F_APB, return F_CPU
uint32_t SystemCoreClock(void);						//return F_CPU
uint32_t WLANClock(void);							//return F_WLAN
uint32_t APBClock(void);							//return F_APB

//reset the mcu
void mcuInit(void);

//empty interrupt handler
void empty_handler(void);


#define Mhz					000000ul	//suffix for Mhz
#define F_UART				(F_PHB)		//8Mhz		//crystal frequency
#define UART_BR300			300ul		//buadrate=300
#define UART_BR600			600ul		//buadrate=600
#define UART_BR1200			1200ul		//buadrate=1200
#define UART_BR2400			2400ul		//buadrate=2400
#define UART_BR4800			4800ul		//buadrate=4800
#define UART_BR9600			9600ul		//buadrate=9600
#define UART_BR14400		14400ul		//buadrate=19200
#define UART_BR19200		19200ul		//buadrate=19200
#define UART_BR38400		38400ul		//buadrate=38400
#define UART_BR43000		43000ul		//buadrate=38400
#define UART_BR57600		57600ul		//buadrate=57600
#define UART_BR76800		76800ul		//buadrate=57600
#define UART_BR115200		115200ul	//buadrate=115200
#define UART_BR128000		128000ul	//buadrate=115200
#define UART_BR230400		230400ul	//buadrate=115200
#define UART_BR256000		256000ul	//buadrate=115200
#define UART_BR460800		460800ul	//buadrate=115200
#define UART_BR512000		512000ul	//buadrate=115200
#define UART_BR576000		576000ul	//buadrate=115200
#define UART_BR921600		921600ul	//buadrate=115200
#define UART_BR1000000		1000000ul	//buadrate=115200
#define UART_BR1250000		1250000ul	//buadrate=115200
#define UART_BR1500000		1500000ul	//buadrate=115200
#define UART_BR2000000		2000000ul	//buadrate=115200
//short notations
#define UART_BR0K3			UART_BR300
#define UART_BR0K6			UART_BR600
#define UART_BR1K2			UART_BR1200
#define UART_BR2K4			UART_BR2400
#define UART_BR4K8			UART_BR4800
#define UART_BR9K6			UART_BR9600
#define UART_BR14K4			UART_BR14400
#define UART_BR19K2			UART_BR19200
#define UART_BR38K4			UART_BR38400
#define UART_BR43K			UART_BR43000
#define UART_BR57K6			UART_BR57600
#define UART_BR76K8			UART_BR76800
#define UART_BR115K2		UART_BR115200
#define UART_BR128K			UART_BR128000
#define UART_BR256K			UART_BR256000
#define UART_BR460K8		UART_BR460800
#define UART_BR512K			UART_BR512000
#define UART_BR576K			UART_BR576000
#define UART_BR921K6		UART_BR921600
#define UART_BR1M			UART_BR1000000
#define UART_BR1M25			UART_BR1250000
#define UART_BR1M5			UART_BR1500000
#define UART_BR2M			UART_BR2000000

//initiate the hardware usart
//for uart0
void uart0Init(unsigned long baud_rate);	//initiate the hardware usart
#define uart0Putch(ch)		do {uart0Wait(); UART0->TDW=(ch);} while (0)							//void uart1Putch(char ch);					//send a char
void uart0Puts(char *str);					//send a string
//void uart0Putline(char *ln);				//send a string + line return
#define uart0Putline(str)	do {uart1Puts(str); uart1Puts("\r\n");} while (0)
#define uart0Getch()		(UART0->RDW)				//uint8_t uart1Getch(void);					//read a char from usart
#define uart0Available()	(UART0->FIFOS & (0x3f<<6))	//uint16_t uart1Available(void);			//test if data rx is available
#define uart0Busy()			(UART0->FIFOS & (0x3f<<0))	//(!(UART0->INTS & (1<<1)))	//uint16_t uart1Busy(void);					//test if uart tx is busy
#define uart0Wait()			while (uart0Busy())
void u0Print(char *str, int32_t dat);		//print to uart0
#define u0Println()			uart0Puts("\r\n")
//for compatability
#define uart0Put(ch)		uart0Putch(ch)
#define uart0Get()			uart0Getch()
#define uart0bps()			(F_UART / (((UART0->BAUDR & 0xffff) + 1) * 16 + (UART0->BAUDR >> 16)))
#define u0bps()				uart0bps()

//using circular buffer for uart0 transmission
#define uart0TXFull()		(uart0Busy() == (0x3f<<0))	//test if TX FIFO is full
void u0CBInit(CB_TypeDef *cb, uint32_t bps);		//initialize uart0 using cb
void u0CBTX(CB_TypeDef *cb);						// transmit on uart0 using CB

//for uart1
void uart1Init(unsigned long baud_rate);
#define uart1Putch(ch)		do {uart1Wait(); UART1->TDW=(ch);} while (0)							//void uart1Putch(char ch);					//send a char
void uart1Puts(char *str);					//send a string
//void uart1Putline(char *ln);				//send a string + line return
#define uart1Putline(str)	do {uart1Puts(str); uart1Puts("\r\n");} while (0)
#define uart1Getch()		(UART1->RDW)				//uint8_t uart1Getch(void);					//read a char from usart
#define uart1Available()	(UART1->FIFOS & (0x3f<<6))	//uint16_t uart1Available(void);			//test if data rx is available
#define uart1Busy()			(UART1->FIFOS & (0x3f<<0))	//(!(UART0->INTS & (1<<1)))	//uint16_t uart1Busy(void);					//test if uart tx is busy
#define uart1Wait()			while (uart1Busy())
void u1Print(char *str, int32_t dat);		//print to uart1
#define u1Println()			uart1Puts("\r\n")
//for compatability
#define uart1Put(ch)		uart1Putch(ch)
#define uart1Get()			uart1Getch()
#define uart1bps()			(F_UART / (((UART1->BAUDR & 0xffff) + 1) * 16 + (UART1->BAUDR >> 16)))
#define u1bps()				uart1bps()

//using circular buffer for uart1 transmission
#define uart1TXFull()		(uart1Busy() == (0x3f<<0))	//test if TX FIFO is full
void u1CBInit(CB_TypeDef *cb, uint32_t bps);		//initialize uart0 using cb
void u1CBTX(CB_TypeDef *cb);						// transmit on uart0 using CB

//for uart2
//initiate the hardware usart
void uart2Init(unsigned long baud_rate);
#define uart2Putch(ch)		do {uart2Wait(); UART2->TDW=(ch);} while (0)							//void uart1Putch(char ch);					//send a char
void uart2Puts(char *str);					//send a string
//void uart2Putline(char *ln);				//send a string + line return
#define uart2Putline(str)	do {uart2Puts(str); uart2Puts("\r\n");} while (0)
#define uart2Getch()		(UART2->RDW)				//uint8_t uart1Getch(void);					//read a char from usart
#define uart2Available()	(UART2->FIFOS & (0x3f<<6))	//uint16_t uart1Available(void);			//test if data rx is available
#define uart2Busy()			(UART2->FIFOS & (0x3f<<0))	//(!(UART0->INTS & (1<<1)))	//uint16_t uart1Busy(void);					//test if uart tx is busy
#define uart2Wait()			while (uart2Busy())
void u2Print(char *str, int32_t dat);		//print to uart2
#define u2Println()			uart2Puts("\r\n")
//for compatability
#define uart2Put(ch)		uart2Putch(ch)
#define uart2Get()			uart2Getch()
#define uart2bps()			(F_UART / (((UART2->BAUDR & 0xffff) + 1) * 16 + (UART2->BAUDR >> 16)))
#define u2bps()				uart2bps()

//using circular buffer for uart0 transmission
#define uart2TXFull()		(uart2Busy() == (0x3f<<0))	//test if TX FIFO is full
void u2CBInit(CB_TypeDef *cb, uint32_t bps);		//initialize uart0 using cb
void u2CBTX(CB_TypeDef *cb);						// transmit on uart0 using CB

//for uart3
//initiate the hardware usart
void uart3Init(unsigned long baud_rate);
#define uart3Putch(ch)		do {uart3Wait(); UART3->TDW=(ch);} while (0)							//void uart1Putch(char ch);					//send a char
void uart3Puts(char *str);					//send a string
//void uart3Putline(char *ln);				//send a string + line return
#define uart3Putline(str)	do {uart3Puts(str); uart3Puts("\r\n");} while (0)
#define uart3Getch()		(UART3->RDW)				//uint8_t uart1Getch(void);					//read a char from usart
#define uart3Available()	(UART3->FIFOS & (0x3f<<6))	//uint16_t uart1Available(void);			//test if data rx is available
#define uart3Busy()			(UART3->FIFOS & (0x3f<<0))	//(!(UART0->INTS & (1<<1)))	//uint16_t uart1Busy(void);					//test if uart tx is busy
#define uart3Wait()			while (uart3Busy())
void u3Print(char *str, int32_t dat);		//print to uart1
#define u3Println()			uart3Puts("\r\n")
//for compatability
#define uart3Put(ch)		uart3Putch(ch)
#define uart3Get()			uart3Getch()
#define uart3bps()			(F_UART / (((UART3->BAUDR & 0xffff) + 1) * 16 + (UART3->BAUDR >> 16)))
#define u3bps()				uart3bps()

//using circular buffer for uart0 transmission
#define uart3TXFull()		(uart3Busy() == (0x3f<<0))	//test if TX FIFO is full
void u3CBInit(CB_TypeDef *cb, uint32_t bps);		//initialize uart0 using cb
void u3CBTX(CB_TypeDef *cb);						// transmit on uart0 using CB

//for uart4
//initiate the hardware usart
void uart4Init(unsigned long baud_rate);
#define uart4Putch(ch)		do {uart4Wait(); UART4->TDW=(ch);} while (0)							//void uart1Putch(char ch);					//send a char
void uart4Puts(char *str);					//send a string
//void uart3Putline(char *ln);				//send a string + line return
#define uart4Putline(str)	do {uart4Puts(str); uart4Puts("\r\n");} while (0)
#define uart4Getch()		(UART4->RDW)				//uint8_t uart1Getch(void);					//read a char from usart
#define uart4Available()	(UART4->FIFOS & (0x3f<<6))	//uint16_t uart1Available(void);			//test if data rx is available
#define uart4Busy()			(UART4->FIFOS & (0x3f<<0))	//(!(UART0->INTS & (1<<1)))	//uint16_t uart1Busy(void);					//test if uart tx is busy
#define uart4Wait()			while (uart4Busy())
void u4Print(char *str, int32_t dat);		//print to uart1
#define u4Println()			uart4Puts("\r\n")
//for compatability
#define uart4Put(ch)		uart4Putch(ch)
#define uart4Get()			uart4Getch()
#define uart4bps()			(F_UART / (((UART4->BAUDR & 0xffff) + 1) * 16 + (UART4->BAUDR >> 16)))
#define u4bps()				uart4bps()

//using circular buffer for uart0 transmission
#define uart4TXFull()		(uart4Busy() == (0x3f<<0))	//test if TX FIFO is full
void u4CBInit(CB_TypeDef *cb, uint32_t bps);		//initialize uart0 using cb
void u4CBTX(CB_TypeDef *cb);						// transmit on uart0 using CB

//for uart5
//initiate the hardware usart
void uart5Init(unsigned long baud_rate);
#define uart5Putch(ch)		do {uart5Wait(); UART5->TDW=(ch);} while (0)							//void uart1Putch(char ch);					//send a char
void uart5Puts(char *str);					//send a string
//void uart5Putline(char *ln);				//send a string + line return
#define uart5Putline(str)	do {uart5Puts(str); uart5Puts("\r\n");} while (0)
#define uart5Getch()		(UART5->RDW)				//uint8_t uart1Getch(void);					//read a char from usart
#define uart5Available()	(UART5->FIFOS & (0x3f<<6))	//uint16_t uart1Available(void);			//test if data rx is available
#define uart5Busy()			(UART5->FIFOS & (0x3f<<0))	//(!(UART0->INTS & (1<<1)))	//uint16_t uart1Busy(void);					//test if uart tx is busy
#define uart5Wait()			while (uart5Busy())
void u5Print(char *str, int32_t dat);		//print to uart1
#define u5Println()			uart5Puts("\r\n")
//for compatability
#define uart5Put(ch)		uart5Putch(ch)
#define uart5Get()			uart5Getch()
#define uart5bps()			(F_UART / (((UART5->BAUDR & 0xffff) + 1) * 16 + (UART5->BAUDR >> 16)))
#define u5bps()				uart5bps()

//using circular buffer for uart0 transmission
#define uart5TXFull()		(uart5Busy() == (0x3f<<0))	//test if TX FIFO is full
void u5CBInit(CB_TypeDef *cb, uint32_t bps);		//initialize uart5 using cb
void u5CBTX(CB_TypeDef *cb);						// transmit on uart5 using CB

//end Serial

//timer
#define tmrSetPS(ps)	do {RCC->CLK_EN |= (1<<10);	TIM->TMR_CONFIG = (ps) & 0x7f;} while (0)	//set timer's prescaler. bits 6..0
#define tmrGetPS()		(TIM->TMR_CONFIG & 0x7f)
//tmr0
void tmr0Init(void);						//initialize timer: repeat counter up to 0xffffffff, no interrupt
void tmr0AttachISR(void (*isrptr)(void));	//install user isr
#define tmr0SetPR(pr)	TIM->TIM0_PRD=(pr)	//set timer's period
#define tmr0GetPR()		(TIM->TIM0_PRD)

//tmr1
void tmr1Init(void);						//initialize timer: repeat counter up to 0xffffffff, no interrupt
void tmr1AttachISR(void (*isrptr)(void));	//install user isr
#define tmr1SetPR(pr)	TIM->TIM1_PRD=(pr)	//set timer's period
#define tmr1GetPR()		(TIM->TIM1_PRD)

//tmr2
void tmr2Init(void);						//initialize timer: repeat counter up to 0xffffffff, no interrupt
void tmr2AttachISR(void (*isrptr)(void));	//install user isr
#define tmr2SetPR(pr)	TIM->TIM2_PRD=(pr)	//set timer's period
#define tmr2GetPR()		(TIM->TIM2_PRD)

//tmr3
void tmr3Init(void);						//initialize timer: repeat counter up to 0xffffffff, no interrupt
void tmr3AttachISR(void (*isrptr)(void));	//install user isr
#define tmr3SetPR(pr)	TIM->TIM3_PRD=(pr)	//set timer's period
#define tmr3GetPR()		(TIM->TIM3_PRD)

//tmr4
void tmr4Init(void);						//initialize timer: repeat counter up to 0xffffffff, no interrupt
void tmr4AttachISR(void (*isrptr)(void));	//install user isr
#define tmr4SetPR(pr)	TIM->TIM4_PRD=(pr)	//set timer's period
#define tmr4GetPR()		(TIM->TIM4_PRD)

//tmr5
void tmr5Init(void);						//initialize timer: repeat counter up to 0xffffffff, no interrupt
void tmr5AttachISR(void (*isrptr)(void));	//install user isr
#define tmr5SetPR(pr)	TIM->TIM5_PRD=(pr)	//set timer's period
#define tmr5GetPR()		(TIM->TIM5_PRD)

//end timer

//pwm
void pwm0Init(void);						//initialize pwm
#define PWM0SetPS(ps)	do {PWM->CLKDIV01 = (PWM->CLKDIV01 &~(0xffff << (0*16))) | (((ps) & 0xffff) << (0*16));} while (0)
#define PWM0SetPR(pr)	do {PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (0*8))) | (((pr) & 0xff) << (0*8));} while (0)	
#define PWM0SetDC(dc)	do {PWM->CMPDAT =   (PWM->CMPDAT &~(0xff << (0*8))) | (((dc) & 0xff) << (0*8));} while (0)
#define PWM0PolPos(p)	PWM->CR &=~(1 << 2)	//pwm output is positive polarity. bit 5..2 for ch 3..0
#define PWM0PolNeg(p)	PWM->CR |= (1 << 2)	//pwm output is negative polarity. bit 5..2 for ch 3..0
#define PWM0GetPS()		((PWM->CLKDIV01 >> (0*16)) & 0xffff)
#define PWM0GetPR()		((PWM->PERIOD >> (0*8)) & 0xff)
#define PWM0GetDC()		((PWM->CMPDAT >> (0*8)) & 0xff)

void pwm1Init(void);						//initialize pwm
#define PWM1SetPS(ps)	do {PWM->CLKDIV01 = (PWM->CLKDIV01 &~(0xffff << (1*16))) | (((ps) & 0xffff) << (1*16));} while (0)
#define PWM1SetPR(pr)	do {PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (1*8))) | (((pr) & 0xff) << (1*8));} while (0)	
#define PWM1SetDC(dc)	do {PWM->CMPDAT =   (PWM->CMPDAT &~(0xff << (1*8))) | (((dc) & 0xff) << (1*8));} while (0)
#define PWM1PolPos(p)	PWM->CR &=~(1 << 3)	//pwm output is positive polarity. bit 5..2 for ch 3..0
#define PWM1PolNeg(p)	PWM->CR |= (1 << 3)	//pwm output is negative polarity. bit 5..2 for ch 3..0
#define PWM1GetPS()		((PWM->CLKDIV01 >> (1*16)) & 0xffff)
#define PWM1GetPR()		((PWM->PERIOD >> (1*8)) & 0xff)
#define PWM1GetDC()		((PWM->CMPDAT >> (1*8)) & 0xff)

void pwm2Init(void);						//initialize pwm
#define PWM2SetPS(ps)	do {PWM->CLKDIV23 = (PWM->CLKDIV23 &~(0xffff << (0*16))) | (((ps) & 0xffff) << (0*16));} while (0)
#define PWM2SetPR(pr)	do {PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (2*8))) | (((pr) & 0xff) << (2*8));} while (0)	
#define PWM2SetDC(dc)	do {PWM->CMPDAT =   (PWM->CMPDAT &~(0xff << (2*8))) | (((dc) & 0xff) << (2*8));} while (0)
#define PWM2PolPos(p)	PWM->CR &=~(1 << 4)	//pwm output is positive polarity. bit 5..2 for ch 3..0
#define PWM2PolNeg(p)	PWM->CR |= (1 << 4)	//pwm output is negative polarity. bit 5..2 for ch 3..0
#define PWM2GetPS()		((PWM->CLKDIV23 >> (0*16)) & 0xffff)
#define PWM2GetPR()		((PWM->PERIOD >> (2*8)) & 0xff)
#define PWM2GetDC()		((PWM->CMPDAT >> (2*8)) & 0xff)

void pwm3Init(void);						//initialize pwm
#define PWM3SetPS(ps)	do {PWM->CLKDIV23 = (PWM->CLKDIV23 &~(0xffff << (1*16))) | (((ps) & 0xffff) << (1*16));} while (0)
#define PWM3SetPR(pr)	do {PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (3*8))) | (((pr) & 0xff) << (3*8));} while (0)	
#define PWM3SetDC(dc)	do {PWM->CMPDAT =   (PWM->CMPDAT &~(0xff << (3*8))) | (((dc) & 0xff) << (3*8));} while (0)
#define PWM3PolPos(p)	PWM->CR &=~(1 << 5)	//pwm output is positive polarity. bit 5..2 for ch 3..0
#define PWM3PolNeg(p)	PWM->CR |= (1 << 5)	//pwm output is negative polarity. bit 5..2 for ch 3..0
#define PWM3GetPS()		((PWM->CLKDIV23 >> (1*16)) & 0xffff)
#define PWM3GetPR()		((PWM->PERIOD >> (3*8)) & 0xff)
#define PWM3GetDC()		((PWM->CMPDAT >> (3*8)) & 0xff)

//pwm4 is special - code below is bespoke to pwm4
void pwm4Init(void);						//initialize pwm
#define PWM4SetPS(ps)	do {PWM->CH4CR1 = 	(PWM->CH4CR1 &~(0xffff << (1*16))) | (((ps) & 0xffff) << (1*16));} while (0)
#define PWM4SetPR(pr)	do {PWM->CH4CR1 = 	(PWM->CH4CR1 &~(0xff << (1*8))) | (((pr) & 0xff) << (1*8));} while (0)	
#define PWM4SetDC(dc)	do {PWM->CH4CR2 =   (PWM->CH4CR2 &~(0xff << (1*8))) | (((dc) & 0xff) << (1*8));} while (0)
#define PWM4PolPos(p)	PWM->CH4CR2 &=~(1 << 0)	//pwm output is positive polarity
#define PWM4PolNeg(p)	PWM->CH4CR2 |= (1 << 0)	//pwm output is negative polarity
#define PWM4GetPS()		((PWM->CH4CR1 >> 16) & 0xffff)
#define PWM4GetPR()		((PWM->CH4CR1 >>  8) & 0xff)
#define PWM4GetDC()		((PWM->CH4CR2 >>  8) & 0xff)
//end pwm

//pmu
//initialize pmu
void pmuInit(void);									//initialize pmu
//void pmuStartT0(uint32_t sec);					//start timer0
#define pmuSetT0(sec)					do {PMU->TIMER0  = 	(1<<16) | ((sec) & 0xffff);} while (0)
#define pmuGetT0()						((PMU->TIMER0) & 0xffff)
//void pmuStartT1(uint32_t sec);					//start timer1
#define pmuSetT1(sec)					do {PMU->RSV     = 	(1<<16) | ((sec) & 0xffff);} while (0)
#define pmuGetT1()						((PMU->RSV   ) & 0xfffff)
#define pmuRTC0()		(PMU->RTCCR0)
#define pmuRTC1()		(PMU->RTCCR1)
#define rtcOSC2RC()		IO_SET(PMU->CR, 1<<4)		//rtc on RC oscillator
#define rtcOSC2Xtal()	IO_CLR(PMU->CR, 1<<4)		//rtc on main crystal oscillator
#define rtcOSCCalib()	do {IO_CLR(PMU->CR, 1<<3); IO_SET(PMU->CR, 1<<3);} while (0)		//1->start rc calibration, 0->no effect
#define rtcSecGet()		((pmuRTC0() >> 0) & 0x3f)
#define rtcMinGet()		((pmuRTC0() >> 8) & 0x3f)	//datasheet is missing this item. see wm_regs.h
#define rtcHourGet()	((pmuRTC0() >>16) & 0x1f)
#define rtcDayGet()		((pmuRTC0() >>24) & 0x1f)
#define rtcMonGet()		((pmuRTC1() >> 0) & 0x0f)
#define rtcYearGet()	((pmuRTC1() >> 8) & 0x7f)
//clear rtc1's bit 16 before setting the time
//set rtc1's bit 16 to enable timing
#define rtcSecSet(x)	do {pmuRTC1() &=~(1<<16); (pmuRTC0() = (pmuRTC0() &~(0x3f << 0)) | (((x) & 0x3f) << 0)); pmuRTC1() |= (1<<16);} while (0)
#define rtcMinSet(x)	do {pmuRTC1() &=~(1<<16); (pmuRTC0() = (pmuRTC0() &~(0x3f << 8)) | (((x) & 0x3f) << 8)); pmuRTC1() |= (1<<16);} while (0)
#define rtcHourSet(x)	do {pmuRTC1() &=~(1<<16); (pmuRTC0() = (pmuRTC0() &~(0x1f <<16)) | (((x) & 0x1f) <<16)); pmuRTC1() |= (1<<16);} while (0)
#define rtcDaySet(x)	do {pmuRTC1() &=~(1<<16); (pmuRTC0() = (pmuRTC0() &~(0x1f <<24)) | (((x) & 0x1f) <<24)); pmuRTC1() |= (1<<16);} while (0)
#define rtcMonSet(x)	do {pmuRTC1() &=~(1<<16); (pmuRTC1() = (pmuRTC1() &~(0x0f << 0)) | (((x) & 0x0f) << 0)); pmuRTC1() |= (1<<16);} while (0)
#define rtcYearSet(x)	do {pmuRTC1() &=~(1<<16); (pmuRTC1() = (pmuRTC1() &~(0x7f << 8)) | (((x) & 0x7f) << 8)); pmuRTC1() |= (1<<16);} while (0)
//end pmu

//wdg
void wdgInit(void);									//reset wdg, interrupt disabled
void wdgAttachISR(void (*isrptr)(void));			//install user isr
#define wdgGet()		(WDG->VAL)					//get wdg value
#define wdgSet(pr)		WDG->LD = (pr)				//set period
#define wdgIFGet()		((WDG->STATE) & (1<<0))		//1->interrupt has happened, 0->not yet happend
#define wdgIFClr()		WDG->CLR = 0				//write any to clear the flg
//end wdg

//end arduino declaration

//adc
//adc input channels
#define ADC_CH0			0b0000			//adc ch0
#define ADC_CH1			0b0001			//adc ch1
#define ADC_CH2			0b0010			//adc ch2
#define ADC_CH3			0b0011			//adc ch3
#define ADC_CH01		0b1000			//adc ch0 vs. ch1
#define ADC_CH23		0b1001			//adc ch2 vs. ch3
#define ADC_TEMP		0b1100			//temperature sensor
#define ADC_VLDO		0b1101			//LDO output = 2.5v
#define ADC_OFST		0b1110			//adc ch for offset measurement
#define ADC_ARAND		ADC_CH0			//use temp generator for random number generation
//pga gain
//pga gain1
#define PGA1_x1			0b000			//pga1 gain
#define PGA1_x16		0b001			//pga1 gain
#define PGA1_x32		0b010			//pga1 gain
#define PGA1_x64		0b011			//pga1 gain
#define PGA1_x128		0b100			//pga1 gain
#define PGA1_x256		0b101			//pga1 gain
//pga gain 2
#define PGA2_x1			0b00			//pga2 gain
#define PGA2_x2			0b01			//pga2 gain
#define PGA2_x3			0b10			//pga2 gain
#define PGA2_x4			0b11			//pga2 gain
//pga gain combination
#define PGAx1			(PGA1_x1   | (PGA2_x1 << 3))
#define PGAx2			(PGA1_x1   | (PGA2_x2 << 3))
#define PGAx3			(PGA1_x1   | (PGA2_x3 << 3))
#define PGAx4			(PGA1_x1   | (PGA2_x4 << 3))
#define PGAx16			(PGA1_x16  | (PGA2_x1 << 3))
#define PGAx32			(PGA1_x16  | (PGA2_x2 << 3))
#define PGAx48			(PGA1_x16  | (PGA2_x3 << 3))
#define PGAx64			(PGA1_x16  | (PGA2_x4 << 3))
#define PGAx96			(PGA1_x32  | (PGA2_x3 << 3))
#define PGAx128			(PGA1_x32  | (PGA2_x4 << 3))
#define PGAx192			(PGA1_x64  | (PGA2_x3 << 3))
#define PGAx256			(PGA1_x64  | (PGA2_x4 << 3))
#define PGAx384			(PGA1_x128 | (PGA2_x3 << 3))
#define PGAx512			(PGA1_x128 | (PGA2_x4 << 3))
#define PGAx768			(PGA1_x256 | (PGA2_x3 << 3))
#define PGAx1024		(PGA1_x256 | (PGA2_x4 << 3))

void adcInit(void);									//reset the adc
uint32_t adcRead(uint8_t ch);						//read an adc channel
#define analogRead(ch)	adcRead(ch)					//map to arduino
uint32_t adcReadN(uint8_t ch, uint8_t N);			//read adc multiples and return the average
#define adcSetGain(g)	ADC->PGA_CR = (ADC->PGA_CR &~(0x1f << 4)) | (((g) & 0x1f) << 4)
#define ADC_DLY()		delay(2)					//delay 2ms after a channel switch, per the datasheet
#define adcOffset(n)	adcReadN(ADC_OFST, n)		//return adc readings for ADC_OFST / n runs
#define adcSetVcm(g)	do {PGA_VCMIN = (PGA_VCMIN &~(0x3f << 11)) | (((g) & 0x3f) << 11);} while (0)
#define adcGetVcm()		((PGA_VCMIN >> 11) & 0x3f)
#define Vcmx1k()		(adcGetVcm() * 1311 / 32)	//return Vcm (default 1311mv at Vcm=32), in mv
uint32_t adcReadVcc(void);							//read the chip's own power supply voltage, Vcc, in mv
//read the chip's own power supply / Vcc, in mv: a very convoluted process, per the datasheet
//8x oversampling
//per datasheet: Vcc = (codeout - offset)*68.5uv/2 + 1.2v, codeout and offset in 16 bit form
//or Vcc = (codeout - offset) * 685 / 20000 + 1200, in mv
 int32_t adcReadmv(uint8_t ch, uint8_t gain);		//read input channel, pga gain = 2x, return in mv
#define adcReadmv1x(ch)		adcReadmv(ch, PGAx1)	//read adc
#define adcReadmv2x(ch)		adcReadmv(ch, PGAx2)	//read adc
#define adcReadmv3x(ch)		adcReadmv(ch, PGAx3)	//read adc
#define adcReadmv4x(ch)		adcReadmv(ch, PGAx4)	//read adc
#define adcReadmv16x(ch)	adcReadmv(ch, PGAx16)	//read adc
#define adcReadmv32x(ch)	adcReadmv(ch, PGAx32)	//read adc
#define adcReadmv48x(ch)	adcReadmv(ch, PGAx48)	//read adc
#define adcReadmv64x(ch)	adcReadmv(ch, PGAx64)	//read adc
#define adcReadmv96x(ch)	adcReadmv(ch, PGAx96)	//read adc
#define adcReadmv128x(ch)	adcReadmv(ch, PGAx128)	//read adc
#define adcReadmv192x(ch)	adcReadmv(ch, PGAx192)	//read adc
#define adcReadmv256x(ch)	adcReadmv(ch, PGAx256)	//read adc
#define adcReadmv384x(ch)	adcReadmv(ch, PGAx384)	//read adc
#define adcReadmv512x(ch)	adcReadmv(ch, PGAx512)	//read adc
#define adcReadmv768x(ch)	adcReadmv(ch, PGAx768)	//read adc
#define adcReadmv1024x(ch)	adcReadmv(ch, PGAx1024)	//read adc
 int32_t adcReadTempx16(void);						//read the temp. returns a reading 16x of Vtemp in the datasheet
//Approach #1 for temperature measurement:
//some math here
//per datasheet, Vtemp = 15.548*TempC + 4444.1
//or (Vtempx16) / 16 = 15.548 * TempC + 4444.1, or
//(Vtempx16) / 16 - 4444.1 = 15.548 * TempC, or 
// TempC = (Vtempx16 / 16 - 4444.1) / 15.548, or 
// TempCx100 = (Vtempx16 * 100 / 16 - 444410)*1000 / 15548
//#define adcReadTempCx100()	((adcReadTempx16() * 100 / 16 - 444410ul) * 1000 / 15548)				//this yields a reading that's about 10F too low.
//Approach #2:
//W801 SDK, in wm_adc.c, suggests a slightly different measurement
//Vetemp = 15.548*TempC + 4120.702
//#define adcReadTempCx100()	((adcReadTempx16() * 100 / 16 - 412070ul) * 1000 / 15548)				//this yields a reading that's about 30F too high.
//Approach #3:
//based on that, we change the constant to hit the ambient temperature at 68.2F, at time of this testing
#define adcReadTempCx100()	((adcReadTempx16() * 100 / 16 - 444410ul + 9350) * 1000 / 15548)			//this yields a reading that's about right. 
//on the error term: +1C=~+1550, 1F=860
#define adcReadTempFx100()	(adcReadTempCx100() * 9 / 5 + 3200)	//perform a C-to-F conversion. C=F*9/5+32

//random number generators
#define arand1()			(analogRead(ADC_ARAND) & 0x01)	//generate 1-bit random number
uint8_t arand4(void);							//generate 4-bit random numbers
uint8_t arand8(void);							//generate 8-bit random numbers
uint16_t arand16(void);							//generate 16-bit random numbers
uint32_t arand32(void);							//generate 32-bit random numbers
//end adc

//touch
void TSInit(void);								//reset the touch sensors
#define TSOn()			TOUCH->CR |= (0<<0)		//1->enable touch, 0->disable touch
#define TSOff()			TOUCH->CR &=~(0<<0)		//1->enable touch, 0->disable touch
void TSSetTHS(PIN_TypeDef pin, uint8_t ths);	//set the touch threshold
uint8_t TSGetTHS(PIN_TypeDef pin);				//get threshold. default = 50
void TSEnable(PIN_TypeDef pin);					//enable touch on a pin
#define TSIFGet()		(TOUCH->IE_IF & (0xffff))
#define TSIFClr()		TOUCH->IE_IF |= (0xffff)

//end touch

//lcd
void LCDInit(void);								//reset the lcd
//end lcd

//spi
void spiInit(void);								//reset the spi
uint8_t spiWrite(uint8_t dat);					//send a byte to tx fifo
void spiWrites(uint8_t *dat, uint32_t bytes);	//transmit a buffer
#define spiRead()		(SPI-RXDATA)							//read a byte from rx fifo
#define spiBusy()		(((SPI->STATUS >> 0) & 0x3f) == 0x3f)	//tx fifo is full
#define spiWait()		while (spiBusy())						//wait for tx buffer to free up
#define spiAvailable()	((SPI->STATUS >> 11) & 0x3f)			//number of bytes in rx fifo
//end spi

//i2c
#define I2C_ACK			0
#define I2C_NOACK		1
#define I2C_CMD_WRITE	0
#define I2C_CMD_READ	1
#define I2C_STOP		1
#define I2C_ACK_ERROR	9

void i2cInit(void);												//reset the i2c
uint8_t i2cWrites(uint8_t devaddr, uint8_t regaddr, uint8_t *dat, uint32_t bytes); 	//write multiple bytes byte to slave
uint8_t i2cWrite(uint8_t dat, uint8_t ifstart);					//send a byte. 1=start, 0=otherwise
uint8_t i2cRead(uint8_t ack_noack, uint8_t ifstop);				//read a byte. I2C_ACK/I2C_NOACK, 1=stop, 0->no stop
uint8_t i2cReads(uint8_t devaddr, uint8_t regaddr, uint8_t *dat, uint32_t bytes);	//read multiple bytes from slave
//end i2c

//software i2c
//software i2c
void sI2CInit(void);									//reset the software i2c
void sI2CStart(void);									//send a start condition
void sI2CStop(void);									//send a stop condition
uint8_t sI2CWrite(uint8_t dat);							//send a i2c byte
uint8_t sI2CRead(uint8_t ack);							//read i2c data
//write from a buffer
uint8_t sI2CWrites(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite);
//read to a buffer
uint8_t sI2CReads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead);
//end software i2c

//true random number generator
//global defines
#define GPSEC_BASE			0x40000600

typedef struct {
	__IOM uint32_t SRC;					//source register @ 0x00
	__IOM uint32_t DEST;				//destination / decrypted text register @ 0x04
	__IOM uint32_t CFG;					//configuration register @ 0x08
	__IOM uint32_t CTRL;				//controll register @ 0x0c
	__IOM uint32_t KEY0;				//key0 register @ 0x10
	__IOM uint32_t KEY1;				//key1 register @ 0x14
	__IOM uint32_t KEY2;				//key2 register @ 0x18
	__IOM uint32_t KEY3;				//key3 register @ 0x1c
	__IOM uint32_t KEY4;				//key4 register = crc key / result register @ 0x20
	__IOM uint32_t KEY5;				//key5 register @ 0x24
	__IOM uint32_t IV0;					//iv0 register @ 0x28
	__IOM uint32_t IV1;					//iv1 register @ 0x2c
	__IOM uint32_t STS;					//status register @ 0x30
	__IOM uint32_t SHA1_DIGEST0;		//sha1/md5 digest0 register @ 0x34
	__IOM uint32_t SHA1_DIGEST1;		//sha1/md5 digest1 register @ 0x38
	__IOM uint32_t SHA1_DIGEST2;		//sha1/md5 digest2 register @ 0x3c
	__IOM uint32_t SHA1_DIGEST3;		//sha1/md5 digest3 register # 0x40
	__IOM uint32_t SHA1_DIGEST4;		//sha1/md5 digest4 register @ 0x44
	__IOM uint32_t RNG_RESULT;			//random number result register # 0x48
	__IOM uint32_t KEY6;				//key6 register @ 0x4c
	__IOM uint32_t KEY7;				//key7 register @ 0x50
	__IOM uint32_t TRNG_CR;				//true random number control register @ 0x54
} GPSEC_TypeDef;

#define GPSEC				((GPSEC_TypeDef *) GPSEC_BASE)

//global variables

//initialize the 32-bit random number generator
//digital post processing enabled: bit 2 = 0
//generate true random numbers: bit 1 = 0
void trngInit(void);					//true 32-bit random number generator
void prngInit(void);					//pseudo 32-bit random number generator
#define rngGet()		(GPSEC->RNG_RESULT)		//read rng result

//end trng

//circular buffer

void cbInit(CB_TypeDef *cbuffer);		//reset the cbuffer
char cbEmpty(CB_TypeDef *cbuffer);		//returns true if cbuffer is empty
char cbFull(CB_TypeDef *cbuffer);		//returns true if cbuffer is full;
cbuffer_t cbWrite(CB_TypeDef *cbuffer, cbuffer_t dat);	//write to the buffer - needs to test if the buffer is full first
cbuffer_t cbRead(CB_TypeDef *cbuffer);	//read from the buffer - needs to test if the buffer is empty
void str2cb(CB_TypeDef *cb, char *str);	//write string to CB
void cb2str(char *str, CB_TypeDef *cb);	//write CB to string
//end circular buffer

//input capture on pwm0/4
void ic0Init(void);						//initialize input capture on pwm0
#define ic0Get()			(PWM->CH0CAPDAT)
#define ic0Available()					//ic0 capture available - not implemented
void ic4Init(void);						//initialize input capture on pwm4
#define ic4Get()			(PWM->CH4CAPDAT)
#define ic4Available()					//ic4 capture available - not implemented
//end input capture

#endif	//_W801DUINO_H
