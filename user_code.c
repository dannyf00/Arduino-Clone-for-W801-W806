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
// v0.7e:12/23/2022 - implemented uart0 transmission over a circular buffer
//
//
//
//               |=======================|
//               |                       |
//     40M Xtal->|                  PB19 |>---------> UART0TX
//               |                  PB20 |<---------< UART0RX
//               |                       |
//               |                       |
//               |                  PB11 |>---------> LED0
//               |                  PB16 |>---------> LED1
//               |                  PB17 |>---------> LED2
//               |                  PB18 |>---------> LED3
//               |                  PB26 |>---------> LED4
//               |                  PB25 |>---------> LED5
//               |                  PB5  |>---------> LED6
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
//
#include "w801duino.h"					//we use w801
//#include "fractal.h"

//hardware configuration
#define LED				PB5				//led on pb11/16/17/18/26/25/5
#define LED_PORT		GPIOB
#define LED_PIN			0xfffffffful
#define LED_DLY			(F_CPU / 2)		//some delay
//end hareware configuration

//global defines

//global variables
CB_TypeDef u0CB;		//uart0 buffer
CB_TypeDef u1CB;		//uart1 buffer
CB_TypeDef u5CB;		//uart5 buffer
char uBuf[400];

int32_t main_class_marks(void);

//flip led/pb11
void led_flp(void) {
	pinFlip(PB11);
}

//flip pb18
void pb18_flp(void) {
	pinFlip(PB18);
}

void setup(void) {
	//initialize the led
	GIO_OUT(GPIOB, 0xfffffffful);				//all pins as output
	pinMode(LED, OUTPUT); digitalWrite(LED, LOW);
		
	//initialize the uart
	//uart0Init(UART_BR115K2);					//initialize uart0
	u0CBInit(&u0CB, UART_BR115K2);				//initialize uart0
	u1CBInit(&u1CB, UART_BR9K6);				//initialize uart1
	u5CBInit(&u5CB, UART_BR4K8);				//initialize uart5
	
	//initialize timer
	tmrSetPS(10);
	tmr4Init(); tmr4SetPR(10000ul); tmr4AttachISR(led_flp);
	tmr5Init(); tmr5SetPR(10100ul); tmr5AttachISR(led_flp);
	
	//initialize the pmu
	//pmuInit(); pmuSetT0(100); pmuSetT1(5000);

	//set time
	//rtcSecSet(12); rtcMinSet(3); rtcHourSet(4); rtcDaySet(5); rtcMonSet(6); rtcYearSet(7);

	//wdg - interrupt every 3 seconds
	//wdgInit(); wdgSet(F_CPU * 3); wdgAttachISR(pb18_flp);

	//adc
	adcInit();									//reset the adc
	//adcOffset(8);								//calibrate the adc

	//pwm
	//pwm3Init(); PWM3SetPS(50000ul); PWM3SetDC(10);					//output on PB25
	//pwm4Init(); PWM4SetPS(40000ul); PWM4SetDC(20);					//output on PB16
	//analogWrite(PB26, 10);						//write to pb26
	
	//touch
	//TSInit(); 
	//TSEnable(PA0); TSSetTHS(PA0, 40);
	//TSEnable(PA1); TSSetTHS(PA1, 60);
	
	//i2c
	//i2cInit();
	
	//spi
	//spiInit();
	
	//initialize prng
	//prngInit();
	
	//initialize pwm
	//pmuInit();
	
	//ei();										//enable interrupts - enabled by default
	
}

void loop(void) {
	static volatile uint32_t tick0=0;			//timing ticks
	static uint32_t tmp0;						//temp variables
	//uint32_t tmp;
	
	//one extra blinky
	//if (ticks() - tick1 > LED_DLY/2) {tick1 += LED_DLY/2; pinFlip(LED3);}
	
	//uart0 tranmit from CB
	u0CBTX(&u0CB);								//transmit on uart0
	u1CBTX(&u1CB);								//transmit on uart1
	u5CBTX(&u5CB);								//transmit on uart5
	
	//1st blinky
	//if (ticks() - tick0 > LED_DLY) {			//time is up
	if (ticks() > tick0) {						//time is up
		tick0 += LED_DLY;						//to the next match point
		pinFlip(LED);							//flip led
		
		//benchmark
		tmp0=ticks();
		//do something
		//dhrystone();							//dhrystone benchmark, 3.458M ticks
		//mandelbrot();							//33.680M ticks@double, 6.8M ticks@float
		//delayTks(1000);						//1056 ticks
		//for (tmp=0; tmp<1000/5; tmp++) {GIO_FLP(GPIOB, 1<<0); GIO_FLP(GPIOB, 1<<0); GIO_FLP(GPIOB, 1<<0); GIO_FLP(GPIOB, 1<<0); GIO_FLP(GPIOB, 1<<0); };	//8485 ticks
		//for (tmp=0; tmp<1000/5; tmp++) {pinFlip(PB0); pinFlip(PB0); pinFlip(PB0); pinFlip(PB0); pinFlip(PB0); };	//47.2K ticks
		//for (tmp=0; tmp<1000/5; tmp++) {HAL_GPIO_TogglePin(GPIOB, 1<<0); HAL_GPIO_TogglePin(GPIOB, 1<<0); HAL_GPIO_TogglePin(GPIOB, 1<<0); HAL_GPIO_TogglePin(GPIOB, 1<<0); HAL_GPIO_TogglePin(GPIOB, 1<<0); };	//51.1K ticks
		//tmp = adcReadN(ADC_CH0, 8);
		//tmp = adcReadTempCx100();
		//tmp = HAL_ADC_GET_INPUT_VOLTAGE(&hadc);
		//ticks();
		//adcReadmv1x(ADC_CH0);
		//sI2CWrite(0);
		//for (tick1=0; tick1<10; tick1++) spiWrite(0x00);	//32K ticks / 1K sends; 3.2k ticks / 100 sends; 358 ticks / 10 sends
		//spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);spiWrite(0x00);	//268 ticks / 10 sends
		//u5CBTX(&u5CB);							//transmitting on uart5 / CB: 43-28 ticks
		//uart5 transmission
		//main_class_marks();					//4194 cycles
		my_main_class_marks();					//2749 cycles
		tmp0=ticks()-tmp0;						//28 ticks overhead
		
		//display something on uart
#if 1
		//printf("F_CPU = %8dKhz. ", F_CPU/1000);	//to test for printf
		u0Print("F_CPU=                      ", F_CPU);
		//u0Print("F_PHB=                      ", F_PHB);
		u0Print("ticks=                      ", ticks());
		u0Print("tick0=                      ", tick0);
		u0Print("tmp0 =                      ", tmp0);
		u0Print("u0bps=                      ", u0bps());
		//u0Print("aOFST=                      ", adcRead(ADC_OFST));
		//u0Print("aTEMP=                      ", adcReadN(ADC_TEMP, 8));
		//u0Print("aCH0 =                      ", adcReadN(ADC_CH0,8));
		//u0Print("aCH1 =                      ", adcReadN(ADC_CH1,8));
		//u0Print("Vcmin=                      ", adcGetVcm());
		//u0Print("mvCh0=                      ", adcReadmv1x(ADC_CH0)); 
		//u0Print("mvCh1=                      ", adcReadmv256x(ADC_CH1));
		//u0Print("mvCh2=                      ", adcReadmv(ADC_CH2));
		//u0Print("mvCh3=                      ", adcReadmv(ADC_CH3));
		//u0Print("mvLDO=                      ", adcReadVcc()); 
		//u0Print("mvLDO=                      ", adcReadmv2x(ADC_VLDO)); 
		//u0Print("aVcc =                      ", adcReadVcc());
		//u0Print("aTemp=                      ", adcReadTempFx100());
		//u0Print("I2CH =                      ", I2C->PRESCALE_H);
		//u0Print("I2CL =                      ", I2C->PRESCALE_L);
		//u0Print("SPIBD=                      ", SPI->CLK_CFG);
		//u0Print("ADCBD=                      ", (RCC->CLK_SEL >> 8) & 0xff);
		//u0Print("PGA1 =                      ", (ADC->PGA_CR >> 4) & 0x07);
		//u0Print("PGA2 =                      ", (ADC->PGA_CR >> 7) & 0x03);
		//u0Print("BAUDM=                      ", UART0->BAUDR & 0xffff);
		//u0Print("BAUDF=                      ", UART0->BAUDR >> 16);
		//u0Print("TSIF =                      ", TSIFGet()); TSIFClr();
		//u0Print("TSCR =                      ", TOUCH->CR);
		//u0Print("TSCH0=                      ", TOUCH->CH0CR);
		//u0Print("TSCH1=                      ", TOUCH->CH1CR);
		//u0Print("P3PS =                      ", PWM3GetPS());
		//u0Print("P3PR =                      ", PWM3GetPR());
		//u0Print("P3DC =                      ", PWM3GetDC());
		//u0Print("P4PS =                      ", PWM4GetPS());
		//u0Print("P4PR =                      ", PWM4GetPR());
		//u0Print("P4DC =                      ", PWM4GetDC());
		//u0Print("AFSEL=                      ", (GPIOB->AF_SEL) & (1<<25));
		//u0Print("AF_S1=                      ", (GPIOB->AF_S1 ) & (1<<25));
		//u0Print("AF_S0=                      ", (GPIOB->AF_S0 ) & (1<<25));
		//u0Print("aOfst=                      ", hadc.offset);
		//u0Print("aCH0 =                      ", adcReadN(ADC_CH0, 8));
		//u0Print("delta=                      ", tmp - tick0);
		//u0Print("L_DLY=                      ", LED_DLY);
		//u0Print("pmuCR=                      ", PMU->CR);
		//u0Print("pmuT1=                      ", pmuGetT1());
		//u0Print("pRTC0=                      ", pmuRTC0());
		//u0Print("pRTC1=                      ", pmuRTC1());
		//u0Print("RTCS =                      ", rtcSecGet());
		//u0Print("RTCH =                      ", rtcHourGet());
		//u0Print("RTCD =                      ", rtcDayGet());
		//u0Print("RTCM =                      ", rtcMonGet());
		//u0Print("RTCY =                      ", rtcYearGet());
		//u0Print("RNG  =                      ", rngGet());
		//u0Print("ARAND=                      ", arand32());
		//u0Print("RNGCR=                      ", GPSEC->KEY0);
		//u0Print("STick=                      ", CORET->VAL);
		//u0Print("PWM4PS                      ", PWM4GetPS());
		//u0Print("u0BRD=                      ", UART0->BAUDR & 0xffff);
		u0Print("u0bps=                      ", uart0bps());
		u0Println();
#else
		//sprintf(u0str, "testing cb123...0! testing cb123...1! testing cb123...2! testing cb123...3! testing cb123...4! testing cb123...5!\n\r");
		//uart0 transmission
		sprintf(uBuf, "uart0: F_CPU= %16u     , tick0= %16u     , ticks= %16u     , tmp0 = %16u     , u0bps=%16u.\r\n", F_CPU, tick0, ticks(), tmp0, u0bps());
		str2cb(&u0CB, uBuf);
		//uart1 transmission
		sprintf(uBuf, "uart1: F_CPU= %16u     , tick0= %16u     , ticks= %16u     , tmp0 = %16u     , u0bps=%16u.\r\n", F_CPU, tick0, ticks(), tmp0, u0bps());
		str2cb(&u1CB, uBuf);
		//uart5 transmission
		sprintf(uBuf, "uart5: F_CPU= %16u     , tick0= %16u     , ticks= %16u     , tmp0 = %16u     , u0bps=%16u.\r\n", F_CPU, tick0, ticks(), tmp0, u0bps());
		str2cb(&u5CB, uBuf);
#endif
	}
}
