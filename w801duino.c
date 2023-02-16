#include "w801duino.h"						//we use w801duino

//gpio
//declare pins
//ALL PINS ARE MAPPED, WHETHER THEY EXIST OR NOT
//SO MAKE SURE THAT THE PINS YOU PICKED ACTUALLY EXIST FOR YOUR PACKAGE
//Pin  0.. 7 -> GPIOA
//Pin  8..15 -> GPIOB
const PIN2GPIO GPIO_PinDef[]= {
#if defined(GPIOA)
	{GPIOA, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOA, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOA, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOA, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOA, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOA, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOA, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOA, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOA, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOA, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOA, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOA, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOA, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOA, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOA, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOA, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOA, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOA, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOA, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOA, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOA, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOA, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOA, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOA, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOA, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOA, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOA, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOA, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOA, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOA, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOA, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOA, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOA

#if defined(GPIOB)
	{GPIOB, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOB, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOB, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOB, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOB, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOB, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOB, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOB, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOB, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOB, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOB, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOB, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOB, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOB, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOB, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOB, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOB, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOB, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOB, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOB, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOB, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOB, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOB, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOB, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOB, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOB, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOB, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOB, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOB, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOB, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOB, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOB, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOB

#if defined(GPIOC)
	{GPIOC, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOC, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOC, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOC, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOC, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOC, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOC, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOC, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOC, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOC, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOC, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOC, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOC, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOC, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOC, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOC, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOC, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOC, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOC, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOC, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOC, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOC, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOC, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOC, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOC, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOC, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOC, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOC, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOC, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOC, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOC, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOC, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOC

#if defined(GPIOD)							//pins 48..63
	{GPIOD, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOD, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOD, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOD, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOD, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOD, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOD, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOD, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOD, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOD, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOD, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOD, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOD, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOD, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOD, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOD, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOD, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOD, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOD, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOD, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOD, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOD, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOD, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOD, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOD, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOD, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOD, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOD, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOD, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOD, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOD, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOD, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOD

#if defined(GPIOE)							//pins 64..79
	{GPIOE, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOE, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOE, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOE, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOE, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOE, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOE, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOE, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOE, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOE, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOE, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOE, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOE, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOE, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOE, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOE, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOE, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOE, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOE, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOE, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOE, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOE, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOE, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOE, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOE, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOE, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOE, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOE, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOE, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOE, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOE, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOE, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOE

#if defined(GPIOF)							//pins 80..96
	{GPIOF, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOF, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOF, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOF, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOF, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOF, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOF, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOF, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOF, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOF, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOF, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOF, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOF, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOF, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOF, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOF, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOF, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOF, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOF, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOF, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOF, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOF, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOF, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOF, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOF, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOF, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOF, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOF, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOF, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOF, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOF, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOF, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOF

#if defined(GPIOG)							//pins 80..96
	{GPIOG, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOG, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOG, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOG, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOG, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOG, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOG, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOG, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOG, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOG, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOG, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOG, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOG, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOG, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOG, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOG, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOG, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOG, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOG, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOG, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOG, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOG, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOG, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOG, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOG, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOG, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOG, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOG, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOG, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOG, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOG, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOG, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOG

#if defined(GPIOH)
	{GPIOH, 1ul<<0},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOH, 1ul<<1},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOH, 1ul<<2},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOH, 1ul<<3},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOH, 1ul<<4},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOH, 1ul<<5},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOH, 1ul<<6},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOH, 1ul<<7},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOH, 1ul<<8},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOH, 1ul<<9},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOH, 1ul<<10},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOH, 1ul<<11},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOH, 1ul<<12},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOH, 1ul<<13},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOH, 1ul<<14},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOH, 1ul<<15},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
	{GPIOH, 1ul<<16},						//STM32duino Pin  0 = RP0/PB0/CHIP PIN4
	{GPIOH, 1ul<<17},						//STM32duino Pin  1 = RP1/PB1/CHIP PIN5
	{GPIOH, 1ul<<18},						//STM32duino Pin  2 = RP2/PB2/CHIP PIN6
	{GPIOH, 1ul<<19},						//STM32duino Pin  3 = RP3/PB3/CHIP PIN7
	{GPIOH, 1ul<<20},						//STM32duino Pin  4 = RP4/PB4/CHIP PIN11
	{GPIOH, 1ul<<21},						//STM32duino Pin  5 = RP5/PB5/CHIP PIN14
	{GPIOH, 1ul<<22},						//STM32duino Pin  6 = RP6/PB6/CHIP PIN15
	{GPIOH, 1ul<<23},						//STM32duino Pin  7 = RP7/PB7/CHIP PIN16
	{GPIOH, 1ul<<24},						//STM32duino Pin  8 = RP8/PB8/CHIP PIN17
	{GPIOH, 1ul<<25},						//STM32duino Pin  9 = RP9/PB9/CHIP PIN18
	{GPIOH, 1ul<<26},						//STM32duino Pin 10 = RP10/PB10/CHIP PIN21
	{GPIOH, 1ul<<27},						//STM32duino Pin 11 = RP11/PB11/CHIP PIN22
	{GPIOH, 1ul<<28},						//STM32duino Pin 12 = RP12/PB12/CHIP PIN23
	{GPIOH, 1ul<<29},						//STM32duino Pin 13 = RP13/PB13/CHIP PIN24
	{GPIOH, 1ul<<30},						//STM32duino Pin 14 = RP14/PB14/CHIP PIN25
	{GPIOH, 1ul<<31},						//STM32duino Pin 15 = RP15/PB15/CHIP PIN26
#endif	//GPIOH
};
//end gpio

//system core clocks
struct {
	__IOM uint32_t cpu;						//F_CPU=F_AHB bus 1
	__IOM uint32_t wlan;					//F_WLAN
	__IOM uint32_t apb;						//F_APB
	__IOM uint32_t peri;					//peripheral clock - not used / updated
} CoreClock;

//sets and update system clocks (F_CPU, F_WLAN and F_APB)
//void tls_sys_clk_set(uint32_t clk) {
uint32_t SystemCoreClockConfig(uint32_t clk) {
	SystemClock_Config(clk);
	
	//should wait for the system to clear bit 31?
	//IO_SET(RCC->CLK_DIV, 1<<31); 						//start the clock update process
	while (RCC->CLK_DIV & (1<<31)) continue;			//wait for bit 31 to clear
	return SystemCoreClockUpdate();	//update system core clocks
	//return;
}

/**
 * @brief          	This function is used to get cpu clock
 *
 * @param[out]     *sysclk	point to the addr for system clk output
 *
 * @return         	None
 *
 * @note           	None
 */
//modified from wm_cpu.c
//void tls_sys_clk_get(tls_sys_clk *sysclk) {
uint32_t SystemCoreClockUpdate(void) {
#ifndef TLS_CONFIG_FPGA
	//clk_div_reg clk_div;
	uint32_t clk;

	//clk_div.w = tls_reg_read32(HR_CLK_DIV_CTL);
	clk=RCC->CLK_DIV;
	//sysclk->cpuclk = W800_PLL_CLK_MHZ/(clk_div.b.CPU);
	CoreClock.cpu = F_PLL / ((clk>>0) & 0xff);
	//sysclk->wlanclk = W800_PLL_CLK_MHZ/(clk_div.b.WLAN);
	CoreClock.wlan= F_PLL / ((clk>>8) & 0xff);
	//sysclk->apbclk = sysclk->cpuclk / clk_div.b.BUS2;
	CoreClock.apb = CoreClock.cpu / ((clk>>16) & 0xff);
	//CoreClock.peri= F_PLL / ((clk>>24) & 0x0f);
#else
	CoreClock.apb =				//sysclk->apbclk =
	CoreClock.cpu =				//sysclk->cpuclk =
	CoreClock.wlan= 40000000ul;	//sysclk->wlanclk = 40;	//MHz
#endif
	return CoreClock.cpu;		//returns F_CPU
}

uint32_t SystemCoreClock(void) {
	return CoreClock.cpu;
}

uint32_t WLANClock(void) {
	return CoreClock.wlan;
}

uint32_t APBClock(void) {
	return CoreClock.apb;
}
//systicks
//systick isr
//for time base off SysTick (24-bit counter)
volatile uint32_t systick_ovf = 1ul<<24;						//time base on Systick -> SysTick->VAL being the lowest 24-bits (SysTick is a downcounter)
static void (* _systick_isrptr)(void)=empty_handler;			//systick_ptr pointing to empty_handler by default

//systick handler - to provide time base for millis()/micros()
#define readl(addr) ({unsigned int __v = (*(volatile unsigned int *) (addr)); __v;})
void ISR CORET_IRQHandler(void) {
	//clear the flag
    //readl(0xE000E010);
	//(*(volatile unsigned int *) (0xE000E010));
	CORET->CTRL;										//read it clears bit 16
#if defined(USE_HALTICK)
	HAL_IncTick();										//so hal tick functions work
#else
	systick_ovf += SysTick_PR;							//increment systick counter - 24bit, 1:1 prescaler
#endif
	_systick_isrptr();									//execute user handler
}

//install systick isr
//activate the isr handler
void systickAttachISR(void (*isrptr)(void)) {
	_systick_isrptr = isrptr;
	//systick isr always on -> not needed
	//NVIC_SetPriority(SYS_TICK_IRQn, -1);				//set the priority
	//NVIC_EnableIRQ(SYS_TICK_IRQn);					//enable the irq
}

//return timer clicks
//execution time = 30 ticks, no optimization
uint32_t systicks(void) {
#if defined(USE_HALTICK)
	return HAL_GetTick();
#else
	volatile uint32_t m;
	volatile uint32_t f;

	//do a double read
	do {
		m = systick_ovf;								//read the overflow counter
		f = CORET->VAL;									//read the least significant 16-bits
	}
	while (m != systick_ovf);							//guard against overflow

	return (m - f) << 0;								//systick is a 24-bit downcounter
#endif
}

//delay ticks
void delayTks(uint32_t tks) {
	uint32_t start_time = ticks();
	while (ticks() - start_time < tks) continue;
}

//reset the mcu
void mcuInit(void) {

	//configure clock gating
	//tmp = REG_GET(HR_CLK_GATE_EN);			//tls_reg_read32(HR_CLK_GATE_EN);		//read clk_gate_en
	//tls_reg_write32(HR_CLK_GATE_EN, 0);		//0->disable clock for all
	//tls_reg_write32(HR_CLK_GATE_EN, 1<<11);	//1->enable clock, bit 11=gpio, 11=timer, 6..1=uart5..0
	RCC->CLK_EN = 	(0<< 9) |					//1->enable rf (bit 9). manual says not to change this. default is 1 -> changing it to 0 works as well
					(1<<11) |					//1->enable clock, bit 11=gpio, 10=timer, 6..1=uart5..0
					0x00;

	//configure systick/coretimer
	//a down counter

	//update systemcoreclock
	SystemCoreClockConfig(CPU_CLK);				//set clocks and updates clocks
	//SystemCoreClockUpdate();
#if defined(USE_HALTICK)
	HAL_Init();
#else
	//reconfigure systick / coretimer
	_systick_isrptr = empty_handler;			//point to the empty handler / do nothing
	systick_ovf = SysTick_PR;					//reset systick_ovf to its initial value -> 24bit downcounter
	//SysTick_Config(0);						//tops at 0xfffffful -> free running
    CORET->LOAD  = SysTick_PR-1;				/* set reload register */
    CORET->VAL   = 0UL;							/* Load the CORET Counter Value */
    CORET->CTRL  = CORET_CTRL_CLKSOURCE_Msk |
                   CORET_CTRL_TICKINT_Msk |
                   CORET_CTRL_ENABLE_Msk;		/* Enable CORET IRQ and CORET Timer */
#endif	//use_haltick

	NVIC_ClearPendingIRQ(SYS_TICK_IRQn);		//clear pend flag
	//NVIC_SetPriority(SYS_TICK_IRQn, -1);		//set the priority
	NVIC_EnableIRQ(SYS_TICK_IRQn);				//enable the irq

	//ei();										//enable interrupts - do nothing actually
}

//arduino functions

//empty interrupt handler
void empty_handler(void) {
	//do nothing here
}

//C main loop
int main(void) {

	mcuInit();									//reset the mcu
	setup();									//run the setup code
	while (1) {
		loop();									//run the default loop
	}
}

//arduino gpio
//Arduino Functions: GPIO
//set a pin mode to INPUT or OUTPUT
//no error checking on PIN
inline void pinMode(PIN_TypeDef pin, uint8_t mode) {
	if (mode==OUTPUT) GIO_OUT(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
	else GIO_IN(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
}

//set / clear a pin
inline void digitalWrite(PIN_TypeDef pin, uint8_t val) {
#if defined(USE_HALGPIO)
	HAL_GPIO_WritePin(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask, (val==HIGH)?GPIO_PIN_SET:GPIO_PIN_RESET);
#else			//baremetal
	if (val==LOW) GIO_CLR(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
	else GIO_SET(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask);
#endif			//use_halgpio
}

//read a pin
inline int digitalRead(PIN_TypeDef pin) {
#if defined(USE_HALGPIO)
	return (HAL_GPIO_ReadPin(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask))?HIGH:LOW;
#else
	return (GIO_GET(GPIO_PinDef[pin].gpio, GPIO_PinDef[pin].mask))?HIGH:LOW;
#endif			//use_halgpio
}

//enable pull-up
//use PULLUP or !PULLUP
//set PULLUP_EN to disable pullup, clear pullup_en to enable pullup
inline void pinPullup(PIN_TypeDef pin, uint8_t en) {
	if (en) IO_CLR(GPIO_PinDef[pin].gpio->PULLUP_EN, GPIO_PinDef[pin].mask);				//0->enable pull up
	else IO_SET(GPIO_PinDef[pin].gpio->PULLUP_EN, GPIO_PinDef[pin].mask);
}

//enable pull-down
//use PULLDOWN or !PULLDOWN
//set pulldown_en to enable pulldown, clear PULLDOWN_EN to disable pulldown
inline void pinPulldown(PIN_TypeDef pin, uint8_t en) {
	if (en) IO_SET(GPIO_PinDef[pin].gpio->PULLDOWN_EN, GPIO_PinDef[pin].mask);				//1->enable pull down
	else IO_CLR(GPIO_PinDef[pin].gpio->PULLDOWN_EN, GPIO_PinDef[pin].mask);
}

//enable alternative functions
//af=0..3, for af option 0..3
//deprecated
inline void pinAFIO_(PIN_TypeDef pin, uint8_t af) {
	//configure af_s1 and af_s0
	if (af & (1<<1)) IO_SET(GPIO_PinDef[pin].gpio->AF_S1, GPIO_PinDef[pin].mask); else IO_CLR(GPIO_PinDef[pin].gpio->AF_S1, GPIO_PinDef[pin].mask);	//1->enable af_s1
	if (af & (1<<0)) IO_SET(GPIO_PinDef[pin].gpio->AF_S0, GPIO_PinDef[pin].mask); else IO_CLR(GPIO_PinDef[pin].gpio->AF_S0, GPIO_PinDef[pin].mask);	//1->enable af_s0
	IO_SET(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);	//1->enable af
}

//enable alternative functions for touch
//deprecated
inline void pinTouch(PIN_TypeDef pin) {
	//configure af_s1 and af_s0
	IO_CLR(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);	//1->enable af, 0->gpio
	IO_CLR(GPIO_PinDef[pin].gpio->DIR, GPIO_PinDef[pin].mask);		//1->output, 0->input
	IO_SET(GPIO_PinDef[pin].gpio->PULLUP_EN, GPIO_PinDef[pin].mask);		//set PULLUP_EN to disable pullup, clear pullup_en to enable pullup
	IO_CLR(GPIO_PinDef[pin].gpio->PULLDOWN_EN, GPIO_PinDef[pin].mask);		//set pulldown_en to enable pulldown, clear PULLDOWN_EN to disable pulldown
}

//enable alternative functions, option 1..7, as with the sdk
inline void pinAFIO(PIN_TypeDef pin, uint8_t opt) {
	switch (opt) {
		case 1:
			//af mode 0
			IO_SET(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);		//1->af, 0->gpio
			IO_CLR(GPIO_PinDef[pin].gpio->AF_S1 , GPIO_PinDef[pin].mask);
			IO_CLR(GPIO_PinDef[pin].gpio->AF_S0 , GPIO_PinDef[pin].mask);
			break;
		case 2:
			//af mode 1
			IO_SET(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);		//1->af, 0->gpio
			IO_CLR(GPIO_PinDef[pin].gpio->AF_S1 , GPIO_PinDef[pin].mask);
			IO_SET(GPIO_PinDef[pin].gpio->AF_S0 , GPIO_PinDef[pin].mask);
			break;
		case 3:
			//af mode 2
			IO_SET(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);		//1->af, 0->gpio
			IO_SET(GPIO_PinDef[pin].gpio->AF_S1 , GPIO_PinDef[pin].mask);
			IO_CLR(GPIO_PinDef[pin].gpio->AF_S0 , GPIO_PinDef[pin].mask);
			break;
		case 4:
			//af mode 3
			IO_SET(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);		//1->af, 0->gpio
			IO_SET(GPIO_PinDef[pin].gpio->AF_S1 , GPIO_PinDef[pin].mask);
			IO_SET(GPIO_PinDef[pin].gpio->AF_S0 , GPIO_PinDef[pin].mask);
			break;
		case 5:
			//gpio,
			IO_CLR(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);		//1->af, 0->gpio
			//IO_CLR(GPIO_PinDef[pin].gpio->AF_S1 , GPIO_PinDef[pin].mask);
			//IO_CLR(GPIO_PinDef[pin].gpio->AF_S2 , GPIO_PinDef[pin].mask);
			break;
		case 6:
			//gpio, floating input, disable both pull-down / pullup (???)
			//for adc
			IO_CLR(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);		//1->af, 0->gpio
			IO_CLR(GPIO_PinDef[pin].gpio->DIR   , GPIO_PinDef[pin].mask);		//1->output, 0->input
			IO_SET(GPIO_PinDef[pin].gpio->PULLUP_EN , GPIO_PinDef[pin].mask);	//1->disable pullup, 0->enable pullup
			IO_CLR(GPIO_PinDef[pin].gpio->PULLDOWN_EN, GPIO_PinDef[pin].mask);	//1->enable pulldown, 0->>disable pulldown
			break;
		case 7:
			//gpio, floating input, disable both pull-down / pull-up (??? identical to opt 6)
			//for touch
			IO_CLR(GPIO_PinDef[pin].gpio->AF_SEL, GPIO_PinDef[pin].mask);		//1->af, 0->gpio
			IO_CLR(GPIO_PinDef[pin].gpio->DIR   , GPIO_PinDef[pin].mask);		//1->output, 0->input
			IO_SET(GPIO_PinDef[pin].gpio->PULLUP_EN , GPIO_PinDef[pin].mask);	//1->disable pullup, 0->enable pullup
			IO_CLR(GPIO_PinDef[pin].gpio->PULLDOWN_EN, GPIO_PinDef[pin].mask);	//1->enable pulldown, 0->disable pulldown
			break;
		default: break;
	}
}

//gpioa isr
static void (* _gpioa_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default

//gpioa isr
void ISR GPIOA_IRQHandler(void) {
	_gpioa_isrptr();						//execute user isr - it has to clear its own flags
	//optional
	//GPIOA->IC = GPIOA->IC;				//write 1 to clear
}

//default setting
void GPIOAAttachISR(void (*isrptr)(void), PIN_TypeDef pin, uint8_t mode) {
	uint32_t tmp=1ul<<(pin-PA0);			//pin
	_gpioa_isrptr = isrptr;					//install user handler

	//configure triggering mode
	//IO_CLR(GPIOA->IS, tmp);				//1->level triggered, 0->edge triggered
	//IO_CLR(GPIOA->IBE, tmp);				//1->both edge triggered, 0->single edge triggered (see IEV)
	//IO_CLR(GPIOA->IEV, tmp);				//1->triggered by high level / rising edge, 0->triggered by low level / falling edge
	switch (mode) {
		case CHANGE:	IO_CLR(GPIOA->IS, tmp); IO_SET(GPIOA->IBE, tmp);                           break;	//both edge triggered
		case FALLING:	IO_CLR(GPIOA->IS, tmp); IO_CLR(GPIOA->IBE, tmp);  IO_CLR(GPIOA->IEV, tmp); break;	//falling edge only
		case RISING:	IO_CLR(GPIOA->IS, tmp); IO_CLR(GPIOA->IBE, tmp);  IO_SET(GPIOA->IEV, tmp); break;	//rising edge only
	}
	IO_SET(GPIOA->IE, tmp);					//1->enable interrupt, 0->disable interrupt
	
	//configure nvic
	//NVIC_ClearPendingIRQ(GPIOA_IRQn);
	NVIC_ClearPendingIRQ(GPIOA_IRQn);
	NVIC_EnableIRQ(GPIOA_IRQn);

}

//gpiob isr
static void (* _gpiob_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default

//gpioa isr
void ISR GPIOB_IRQHandler(void) {
	_gpiob_isrptr();						//execute user isr - it has to clear its own flags
	//optional
	//GPIOB->IC = GPIOB->IC;				//write 1 to clear
}

//default setting
void GPIOBAttachISR(void (*isrptr)(void), PIN_TypeDef pin, uint8_t mode) {
	uint32_t tmp=1ul<<(pin-PB0);			//pin
	_gpiob_isrptr = isrptr;					//install user handler

	//configure triggering mode
	//IO_CLR(GPIOB->IS, tmp);				//1->level triggered, 0->edge triggered
	//IO_CLR(GPIOB->IBE, tmp);				//1->both edge triggered, 0->single edge triggered (see IEV)
	//IO_CLR(GPIOB->IEV, tmp);				//1->triggered by high level / rising edge, 0->triggered by low level / falling edge
	switch (mode) {
		case CHANGE:	IO_CLR(GPIOB->IS, tmp); IO_SET(GPIOB->IBE, tmp);                           break;	//both edge triggered
		case FALLING:	IO_CLR(GPIOB->IS, tmp); IO_CLR(GPIOB->IBE, tmp);  IO_CLR(GPIOB->IEV, tmp); break;	//falling edge only
		case RISING:	IO_CLR(GPIOB->IS, tmp); IO_CLR(GPIOB->IBE, tmp);  IO_SET(GPIOB->IEV, tmp); break;	//rising edge only
	}
	IO_SET(GPIOB->IE, tmp);					//1->enable interrupt, 0->disable interrupt
	
	//configure nvic
	//NVIC_ClearPendingIRQ(GPIOB_IRQn);
	NVIC_ClearPendingIRQ(GPIOB_IRQn);
	NVIC_EnableIRQ(GPIOB_IRQn);

}
//end arduino gpio

//uart
#define UART_RXEN_BIT			(1<<7)					//1->enable TX
#define UART_TXEN_BIT			(1<<6)					//1->enable RX
#define UART_BRKEN_BIT			(1<<5)					//1->send break
#define UART_BRKDIS_BIT			(0<<5)					//1->send break
#define UART_PARITYODD_BIT		(1<<4)					//1->odd partity
#define UART_PARITYEVEN_BIT		(0<<4)					//0->even partity
#define UART_PARITYEN_BIT		(1<<3)					//1->enable partity
#define UART_PARITYDIS_BIT		(0<<3)					//0->disable partity
#define UART_STOP1_BIT			(0<<2)					//0->1 stop bit
#define UART_STOP2_BIT			(1<<2)					//1->2 stop bits
#define UART_5BITS_VAL			(0x00)                  //0->5 bits
#define UART_6BITS_VAL			(0x01)                  //0->6 bits
#define UART_7BITS_VAL			(0x02)                  //0->7 bits
#define UART_8BITS_VAL			(0x03)                  //0->8 bits

//char uRAM[uRAM_SIZE];			//transmission buffer, 40-1 char max

//uart0
volatile char *_U0TX_ptr;									//buffer pointer
UART_HandleTypeDef huart0;

//8 data bits, 1 stop bit, no parity, tx/rx enabled
void uart0Init (unsigned long baudrate) {
	//enable clock to uart
	RCC->CLK_EN |= (1<<1);									//1->enable clock. bit6..1 = uart5..0
	//enable the clock to uart0
	//REG_SET(HR_CLK_GATE_EN, 1<<1);						//1->enable clock, bit 11=gpio, 10=timer, 6..1=uart5..0

	NVIC_DisableIRQ(UART0_IRQn);
	NVIC_ClearPendingIRQ(UART0_IRQn);

#if defined(USE_HALUART)
	//UART_HandleTypeDef huart0;

	huart0.Instance = UART0;
	huart0.Init.BaudRate = baudrate;
	huart0.Init.WordLength = UART_WORDLENGTH_8B;
	huart0.Init.StopBits = UART_STOPBITS_1;
	huart0.Init.Parity = UART_PARITY_NONE;
	huart0.Init.Mode = UART_MODE_TX | UART_MODE_RX;
	huart0.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	if (HAL_UART_Init(&huart0) != HAL_OK) {
        empty_handler();									//Error_Handler();
    }
#else		//baremetal
	unsigned long bd;

	//make sure that the baudrate isn't too high for F_UART
	if (F_UART/(16*baudrate)) {
		bd = (F_UART/(16*baudrate) - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (F_UART/(16*baudrate) - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	} else {
		bd = (1                   - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (1                   - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	}
	UART0->BAUDR = bd;									//tls_reg_write32(HR_UART0_BAUD_RATE_CTRL, bd);

	//UART0->LC = UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT;	//tls_reg_write32(HR_UART0_LINE_CTRL, UART_BITSTOP_VAL | UART_TXEN_BIT | UART_RXEN_BIT);
	UART0->LC = 
				UART_RXEN_BIT |								//0->disable rx, 1->enable rx	//tls_reg_write32(HR_UART5_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
				UART_TXEN_BIT |								//0->disable tx, 1->enable tx
				UART_BRKDIS_BIT |							//0->disable break; 1->enable break;
				UART_PARITYEVEN_BIT |						//0->even parity, 1->odd parity
				UART_PARITYDIS_BIT |						//0->disable parity, 1->enable parity
				UART_STOP1_BIT |							//0->1 stop bit, 1->2 stop bits
				UART_8BITS_VAL |							//0->5 bits, 1->6 bits, 2->7 bits, 3->8 bits
				0x00;

	UART0->FC = 0x00;										//tls_reg_write32(HR_UART0_FLOW_CTRL, 0x00);   			/* Disable afc */
	UART0->DMAC=0x00;										//tls_reg_write32(HR_UART0_DMA_CTRL, 0x00);             		/* Disable DMA */
	//UART0->FIFOC=0x00;									//tls_reg_write32(HR_UART0_FIFO_CTRL, 0x00);             		/* one byte TX/RX */
	UART0->INTM=0x00;										//tls_reg_write32(HR_UART0_INT_MASK, 0x00);             		/* Disable INT */
#endif	//use_haluart

	//uart0 rx/tx pin assignment
#if defined(UART0TX2PIN)
	UART0TX2PIN();
#endif

#if defined(UART0RX2PIN)
	UART0RX2PIN();
#endif

}

//put a string
void uart0Puts(char *str) {
#ifndef UART_TXISR
#if defined(USE_HALUART)
	HAL_UART_Transmit(&huart0, (uint8_t *)str, strlen(str), 1000);
#else		//baremetal
    //polling transmission
    while(*str) {
        uart0Putch(*str++);	//send the ch and advance the pointer
    }
#endif		//use_haluart
#else
    //interrupt transmission
    if (*str) {								//if the string isn't empty to begin with
        uart0Wait();						//for compatability with polling transmission
        //U1TXREG = 0;						//clear the buffer
        //_U1TX_BUSY  = 1;					//transmission in progress
        _U0TX_ptr=str;						//point to the string to be transmitted
        IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
        //U1STAbits.UTXEN = 1;				//enable transmission - always enabled
        //tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
        UART0->TDW = *_U0TX_ptr++;			//U1TXREG = *_U1TX_ptr++;
        IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
    }
#endif
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
//void uart1Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart1Puts(ln);
//	//USARTWriteString("\r\n");
//	uart1Puts((char *)"\r\n");
//}

//get the received char
//uint8_t uart1Getch(void) {
//	return U1RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart1Available(void) {
//	return U1STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart1Busy(void) {
//	return U1STAbits.UTXBF;
//}

//print to uart0
void u0Print(char *str, int32_t dat) {
    static char uRAM[uRAM_SIZE];		//uart print buffer
	
	//uart0Wait();						//wait for the prior transmission to finish
    //while (IEC1bits.U1TXIE) continue;

    //form the string
    strcpy(uRAM, str);					//copy to uram
    if (dat < 0) {
        uRAM[6]='-';
        dat = -dat;
    }
    uRAM[19]='0'+(dat % 10); dat /= 10;
    uRAM[18]='0'+(dat % 10); dat /= 10;
    uRAM[17]='0'+(dat % 10); dat /= 10;
    uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[15]='0'+(dat % 10); dat /= 10;
    uRAM[14]='0'+(dat % 10); dat /= 10;
    uRAM[13]='0'+(dat % 10); dat /= 10;
    uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[11]='0'+(dat % 10); dat /= 10;
    uRAM[10]='0'+(dat % 10); dat /= 10;
    uRAM[ 9]='0'+(dat % 10); dat /= 10;
    uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[ 7]='0'+(dat % 10); dat /= 10;
    uart0Puts(uRAM);	//send a message on uart1
}

//circular buffer for uart0 transmission
//initialize uart0 using cb
void u0CBInit(CB_TypeDef *cb, uint32_t bps) {
	uart0Init(bps);
	cbInit(cb);
}

// transmit on uart0 using CB
void u0CBTX(CB_TypeDef *cb) {
	while ((!cbEmpty(cb)) && (!uart0TXFull())) uart0Putch(cbRead(cb));
}
//end uart0

//uart1
volatile char *_U1TX_ptr;									//buffer pointer
UART_HandleTypeDef huart1;

//8 data bits, 1 stop bit, no parity, tx/rx enabled
void uart1Init (unsigned long baudrate) {
	unsigned long bd;

	//enable clock to uart
	RCC->CLK_EN |= (1<<2);									//1->enable clock. bit6..1 = uart5..0
	//enable the clock to uart1
	//REG_SET(HR_CLK_GATE_EN, 1<<2);						//1->enable clock, bit 11=gpio, 10=timer, 6..1=uart5..0

	NVIC_DisableIRQ(UART1_IRQn);
	NVIC_ClearPendingIRQ(UART1_IRQn);

#if defined(USE_HALUART)
	//UART_HandleTypeDef huart1;

	huart1.Instance = UART1;
	huart1.Init.BaudRate = baudrate;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX | UART_MODE_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	if (HAL_UART_Init(&huart1) != HAL_OK) {
        empty_handler();									//Error_Handler();
    }
#else		//baremetal

	//make sure that the baudrate isn't too high for F_UART
if (F_UART/(16*baudrate)) {
		bd = (F_UART/(16*baudrate) - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (F_UART/(16*baudrate) - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	} else {
		bd = (1                   - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (1                   - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	}
	UART1->BAUDR = bd;										//tls_reg_write32(HR_UART1_BAUD_RATE_CTRL, bd);

	//tls_reg_write32(HR_UART1_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
	UART1->LC = 
				UART_RXEN_BIT |								//0->disable rx, 1->enable rx	//tls_reg_write32(HR_UART5_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
				UART_TXEN_BIT |								//0->disable tx, 1->enable tx
				UART_BRKDIS_BIT |							//0->disable break; 1->enable break;
				UART_PARITYEVEN_BIT |						//0->even parity, 1->odd parity
				UART_PARITYDIS_BIT |						//0->disable parity, 1->enable parity
				UART_STOP1_BIT |							//0->1 stop bit, 1->2 stop bits
				UART_8BITS_VAL |							//0->5 bits, 1->6 bits, 2->7 bits, 3->8 bits
				0x00;

	//tls_reg_write32(HR_UART1_FLOW_CTRL, 0x00);   			/* Disable afc */
	UART1->FC = 0x00;
	//tls_reg_write32(HR_UART1_DMA_CTRL, 0x00);             /* Disable DMA */
	UART1->DMAC=0x00;
	//tls_reg_write32(HR_UART1_FIFO_CTRL, 0x00);            /* one byte TX/RX */
	//tls_reg_write32(HR_UART1_INT_MASK, 0x00);             /* Disable INT */
	UART1->INTM=0x00;
#endif	//use-haluart

	//uart0 rx/tx pin assignment
#if defined(UART1TX2PIN)
	UART1TX2PIN();
#endif

#if defined(UART1RX2PIN)
	UART1RX2PIN();
#endif
}

//put a string
void uart1Puts(char *str) {
#ifndef UART_TXISR
#if defined(USE_HALUART)
	HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen(str), 1000);
#else		//baremetal
    //polling transmission
    while(*str) {
        uart1Putch(*str++);	//send the ch and advance the pointer
    }
#endif		//use_haluart
#else
    //interrupt transmission
    if (*str) {								//if the string isn't empty to begin with
        uart1Wait();						//for compatability with polling transmission
        //U1TXREG = 0;						//clear the buffer
        //_U1TX_BUSY  = 1;					//transmission in progress
        _U0TX_ptr=str;						//point to the string to be transmitted
        IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
        //U1STAbits.UTXEN = 1;				//enable transmission - always enabled
        //tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
        UART1->TDW = *_U0TX_ptr++;			//U1TXREG = *_U1TX_ptr++;
        IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
    }
#endif	//uart_txisr
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
//void uart1Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart1Puts(ln);
//	//USARTWriteString("\r\n");
//	uart1Puts((char *)"\r\n");
//}

//get the received char
//uint8_t uart1Getch(void) {
//	return U1RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart1Available(void) {
//	return U1STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart1Busy(void) {
//	return U1STAbits.UTXBF;
//}

//print to uart1
void u1Print(char *str, int32_t dat) {
    static char uRAM[uRAM_SIZE];		//uart print buffer

    //uart1Wait();						//wait for the prior transmission to finish
    //while (IEC1bits.U1TXIE) continue;

    //form the string
    strcpy(uRAM, uRAM);					//copy to uram
    if (dat < 0) {
        uRAM[6]='-';
        dat = -dat;
    }
    uRAM[19]='0'+(dat % 10); dat /= 10;
    uRAM[18]='0'+(dat % 10); dat /= 10;
    uRAM[17]='0'+(dat % 10); dat /= 10;
    uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[15]='0'+(dat % 10); dat /= 10;
    uRAM[14]='0'+(dat % 10); dat /= 10;
    uRAM[13]='0'+(dat % 10); dat /= 10;
    uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[11]='0'+(dat % 10); dat /= 10;
    uRAM[10]='0'+(dat % 10); dat /= 10;
    uRAM[ 9]='0'+(dat % 10); dat /= 10;
    uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[ 7]='0'+(dat % 10); dat /= 10;
    uart1Puts(uRAM);	//send a message on uart1
}

//circular buffer for uart1 transmission
//initialize uart0 using cb
void u1CBInit(CB_TypeDef *cb, uint32_t bps) {
	uart1Init(bps);
	cbInit(cb);
}

// transmit on uart1 using CB
void u1CBTX(CB_TypeDef *cb) {
	while ((!cbEmpty(cb)) && (!uart1TXFull())) uart1Putch(cbRead(cb));
}
//end uart1

//uart2
volatile char *_U2TX_ptr;									//buffer pointer
UART_HandleTypeDef huart2;

//8 data bits, 1 stop bit, no parity, tx/rx enabled
void uart2Init (unsigned long baudrate) {
	unsigned long bd;

	//enable clock to uart
	RCC->CLK_EN |= (1<<3);									//1->enable clock. bit6..1 = uart5..0
	//enable the clock to uart2
	//REG_SET(HR_CLK_GATE_EN, 1<<3);						//1->enable clock, bit 11=gpio, 10=timer, 6..1=uart5..0

	NVIC_DisableIRQ(UART2_5_IRQn);
	NVIC_ClearPendingIRQ(UART2_5_IRQn);

#if defined(USE_HALUART)
	//UART_HandleTypeDef huart2;

	huart2.Instance = UART2;
	huart2.Init.BaudRate = baudrate;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX | UART_MODE_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	if (HAL_UART_Init(&huart2) != HAL_OK) {
        empty_handler();									//Error_Handler();
    }
#else		//baremetal

	//make sure that the baudrate isn't too high for F_UART
if (F_UART/(16*baudrate)) {
		bd = (F_UART/(16*baudrate) - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (F_UART/(16*baudrate) - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	} else {
		bd = (1                   - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (1                   - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	}
	UART2->BAUDR = bd;										//tls_reg_write32(HR_UART2_BAUD_RATE_CTRL, bd);

	//tls_reg_write32(HR_UART2_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
	UART2->LC = 
				UART_RXEN_BIT |								//0->disable rx, 1->enable rx	//tls_reg_write32(HR_UART5_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
				UART_TXEN_BIT |								//0->disable tx, 1->enable tx
				UART_BRKDIS_BIT |							//0->disable break; 1->enable break;
				UART_PARITYEVEN_BIT |						//0->even parity, 1->odd parity
				UART_PARITYDIS_BIT |						//0->disable parity, 1->enable parity
				UART_STOP1_BIT |							//0->1 stop bit, 1->2 stop bits
				UART_8BITS_VAL |							//0->5 bits, 1->6 bits, 2->7 bits, 3->8 bits
				0x00;

	//tls_reg_write32(HR_UART2_FLOW_CTRL, 0x00);   			/* Disable afc */
	UART2->FC = 0x00;
	//tls_reg_write32(HR_UART2_DMA_CTRL, 0x00);             /* Disable DMA */
	UART2->DMAC=0x00;
	//tls_reg_write32(HR_UART2_FIFO_CTRL, 0x00);            /* one byte TX/RX */
	//tls_reg_write32(HR_UART2_INT_MASK, 0x00);            	/* Disable INT */
	UART2->INTM=0x00;
#endif	//use_haluart

	//uart0 rx/tx pin assignment
#if defined(UART2TX2PIN)
	UART2TX2PIN();
#endif

#if defined(UART2RX2PIN)
	UART2RX2PIN();
#endif

}//end uart2

//put a string
void uart2Puts(char *str) {
#ifndef UART_TXISR
#if defined(USE_HALUART)
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
#else		//baremetal
    //polling transmission
    while(*str) {
        uart2Putch(*str++);	//send the ch and advance the pointer
    }
#endif		//use_haluart
#else
    //interrupt transmission
    if (*str) {								//if the string isn't empty to begin with
        uart1Wait();						//for compatability with polling transmission
        //U1TXREG = 0;						//clear the buffer
        //_U1TX_BUSY  = 1;					//transmission in progress
        _U0TX_ptr=str;						//point to the string to be transmitted
        IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
        //U1STAbits.UTXEN = 1;				//enable transmission - always enabled
        //tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
        UART1->TDW = *_U0TX_ptr++;			//U1TXREG = *_U1TX_ptr++;
        IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
    }
#endif
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
//void uart1Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart1Puts(ln);
//	//USARTWriteString("\r\n");
//	uart1Puts((char *)"\r\n");
//}

//get the received char
//uint8_t uart1Getch(void) {
//	return U1RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart1Available(void) {
//	return U1STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart1Busy(void) {
//	return U1STAbits.UTXBF;
//}

//print to uart2
void u2Print(char *str, int32_t dat) {
    static char uRAM[uRAM_SIZE];		//uart print buffer

    //uart1Wait();						//wait for the prior transmission to finish
    //while (IEC1bits.U1TXIE) continue;

    //form the string
    strcpy(uRAM, str);					//copy to uram
    if (dat < 0) {
        uRAM[6]='-';
        dat = -dat;
    }
    uRAM[19]='0'+(dat % 10); dat /= 10;
    uRAM[18]='0'+(dat % 10); dat /= 10;
    uRAM[17]='0'+(dat % 10); dat /= 10;
    uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[15]='0'+(dat % 10); dat /= 10;
    uRAM[14]='0'+(dat % 10); dat /= 10;
    uRAM[13]='0'+(dat % 10); dat /= 10;
    uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[11]='0'+(dat % 10); dat /= 10;
    uRAM[10]='0'+(dat % 10); dat /= 10;
    uRAM[ 9]='0'+(dat % 10); dat /= 10;
    uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[ 7]='0'+(dat % 10); dat /= 10;
    uart2Puts(uRAM);	//send a message on uart1
}

//circular buffer for uart2 transmission
//initialize uart2 using cb
void u2CBInit(CB_TypeDef *cb, uint32_t bps) {
	uart2Init(bps);
	cbInit(cb);
}

// transmit on uart2 using CB
void u2CBTX(CB_TypeDef *cb) {
	while ((!cbEmpty(cb)) && (!uart2TXFull())) uart2Putch(cbRead(cb));
}
//uart3
volatile char *_U3TX_ptr;									//buffer pointer
UART_HandleTypeDef huart3;

//8 data bits, 1 stop bit, no parity, tx/rx enabled
void uart3Init (unsigned long baudrate) {
	unsigned long bd;

	//enable clock to uart
	RCC->CLK_EN |= (1<<4);									//1->enable clock. bit6..1 = uart5..0
	//enable the clock to uart3
	//REG_SET(HR_CLK_GATE_EN, 1<<4);						//1->enable clock, bit 11=gpio, 10=timer, 6..1=uart5..0

	NVIC_DisableIRQ(UART2_5_IRQn);
	NVIC_ClearPendingIRQ(UART2_5_IRQn);

#if defined(USE_HALUART)
	//UART_HandleTypeDef huart3;

	huart3.Instance = UART3;
	huart3.Init.BaudRate = baudrate;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX | UART_MODE_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	if (HAL_UART_Init(&huart3) != HAL_OK) {
        empty_handler();									//Error_Handler();
    }
#else		//baremetal
	//make sure that the baudrate isn't too high for F_UART
if (F_UART/(16*baudrate)) {
		bd = (F_UART/(16*baudrate) - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (F_UART/(16*baudrate) - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	} else {
		bd = (1                   - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (1                   - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	}
	UART3->BAUDR = bd;									//tls_reg_write32(HR_UART3_BAUD_RATE_CTRL, bd);

	//tls_reg_write32(HR_UART3_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
	UART3->LC = 
				UART_RXEN_BIT |								//0->disable rx, 1->enable rx	//tls_reg_write32(HR_UART5_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
				UART_TXEN_BIT |								//0->disable tx, 1->enable tx
				UART_BRKDIS_BIT |							//0->disable break; 1->enable break;
				UART_PARITYEVEN_BIT |						//0->even parity, 1->odd parity
				UART_PARITYDIS_BIT |						//0->disable parity, 1->enable parity
				UART_STOP1_BIT |							//0->1 stop bit, 1->2 stop bits
				UART_8BITS_VAL |							//0->5 bits, 1->6 bits, 2->7 bits, 3->8 bits
				0x00;

	//tls_reg_write32(HR_UART3_FLOW_CTRL, 0x00);   			/* Disable afc */
	UART3->FC = 0x00;
	//tls_reg_write32(HR_UART3_DMA_CTRL, 0x00);             /* Disable DMA */
	UART3->DMAC=0x00;
	//tls_reg_write32(HR_UART3_FIFO_CTRL, 0x00);            /* one byte TX/RX */
	//tls_reg_write32(HR_UART3_INT_MASK, 0x00);            	/* Disable INT */
	UART3->INTM=0x00;
#endif	//use_haluart

	//uart3 rx/tx pin assignment
#if defined(UART3TX2PIN)
	UART3TX2PIN();
#endif

#if defined(UART3RX2PIN)
	UART3RX2PIN();
#endif

}


//put a string
void uart3Puts(char *str) {
#ifndef UART_TXISR
#if defined(USE_HALUART)
	HAL_UART_Transmit(&huart3, (uint8_t *)str, strlen(str), 1000);
#else		//baremetal
    //polling transmission
    while(*str) {
        uart3Putch(*str++);	//send the ch and advance the pointer
    }
#endif		//use_haluart
#else
    //interrupt transmission
    if (*str) {								//if the string isn't empty to begin with
        uart1Wait();						//for compatability with polling transmission
        //U1TXREG = 0;						//clear the buffer
        //_U1TX_BUSY  = 1;					//transmission in progress
        _U0TX_ptr=str;						//point to the string to be transmitted
        IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
        //U1STAbits.UTXEN = 1;				//enable transmission - always enabled
        //tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
        UART1->TDW = *_U0TX_ptr++;			//U1TXREG = *_U1TX_ptr++;
        IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
    }
#endif
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
//void uart1Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart1Puts(ln);
//	//USARTWriteString("\r\n");
//	uart1Puts((char *)"\r\n");
//}

//get the received char
//uint8_t uart1Getch(void) {
//	return U1RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart1Available(void) {
//	return U1STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart1Busy(void) {
//	return U1STAbits.UTXBF;
//}

//print to uart3
void u3Print(char *str, int32_t dat) {
    static char uRAM[uRAM_SIZE];		//uart print buffer

    //uart1Wait();						//wait for the prior transmission to finish
    //while (IEC1bits.U1TXIE) continue;

    //form the string
    strcpy(uRAM, str);					//copy to uram
    if (dat < 0) {
        uRAM[6]='-';
        dat = -dat;
    }
    uRAM[19]='0'+(dat % 10); dat /= 10;
    uRAM[18]='0'+(dat % 10); dat /= 10;
    uRAM[17]='0'+(dat % 10); dat /= 10;
    uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[15]='0'+(dat % 10); dat /= 10;
    uRAM[14]='0'+(dat % 10); dat /= 10;
    uRAM[13]='0'+(dat % 10); dat /= 10;
    uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[11]='0'+(dat % 10); dat /= 10;
    uRAM[10]='0'+(dat % 10); dat /= 10;
    uRAM[ 9]='0'+(dat % 10); dat /= 10;
    uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[ 7]='0'+(dat % 10); dat /= 10;
    uart3Puts(uRAM);	//send a message on uart1
}

//circular buffer for uart5 transmission
//initialize uart3 using cb
void u3CBInit(CB_TypeDef *cb, uint32_t bps) {
	uart3Init(bps);
	cbInit(cb);
}

// transmit on uart3 using CB
void u3CBTX(CB_TypeDef *cb) {
	while ((!cbEmpty(cb)) && (!uart3TXFull())) uart3Putch(cbRead(cb));
}
//end uart3

//uart4
volatile char *_U4TX_ptr;									//buffer pointer
UART_HandleTypeDef huart4;

//8 data bits, 1 stop bit, no parity, tx/rx enabled
void uart4Init (unsigned long baudrate) {
	unsigned long bd;

	//enable clock to uart
	RCC->CLK_EN |= (1<<5);									//1->enable clock. bit6..1 = uart5..0
	//enable the clock to uart4
	//REG_SET(HR_CLK_GATE_EN, 1<<5);						//1->enable clock, bit 11=gpio, 10=timer, 6..1=uart5..0

	NVIC_DisableIRQ(UART2_5_IRQn);
	NVIC_ClearPendingIRQ(UART2_5_IRQn);

#if defined(USE_HALUART)
	//UART_HandleTypeDef huart4;

	huart4.Instance = UART2;
	huart4.Init.BaudRate = baudrate;
	huart4.Init.WordLength = UART_WORDLENGTH_8B;
	huart4.Init.StopBits = UART_STOPBITS_1;
	huart4.Init.Parity = UART_PARITY_NONE;
	huart4.Init.Mode = UART_MODE_TX | UART_MODE_RX;
	huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	if (HAL_UART_Init(&huart4) != HAL_OK) {
        empty_handler();									//Error_Handler();
    }
#else		//baremetal
	//make sure that the baudrate isn't too high for F_UART
if (F_UART/(16*baudrate)) {
		bd = (F_UART/(16*baudrate) - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (F_UART/(16*baudrate) - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	} else {
		bd = (1                   - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (1                   - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	}
	UART4->BAUDR = bd;									//tls_reg_write32(HR_UART4_BAUD_RATE_CTRL, bd);

	//tls_reg_write32(HR_UART4_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
	UART4->LC = 
				UART_RXEN_BIT |								//0->disable rx, 1->enable rx	//tls_reg_write32(HR_UART5_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
				UART_TXEN_BIT |								//0->disable tx, 1->enable tx
				UART_BRKDIS_BIT |							//0->disable break; 1->enable break;
				UART_PARITYEVEN_BIT |						//0->even parity, 1->odd parity
				UART_PARITYDIS_BIT |						//0->disable parity, 1->enable parity
				UART_STOP1_BIT |							//0->1 stop bit, 1->2 stop bits
				UART_8BITS_VAL |							//0->5 bits, 1->6 bits, 2->7 bits, 3->8 bits
				0x00;

	//tls_reg_write32(HR_UART4_FLOW_CTRL, 0x00);   			/* Disable afc */
	UART4->FC = 0x00;
	//tls_reg_write32(HR_UART4_DMA_CTRL, 0x00);             /* Disable DMA */
	UART4->DMAC=0x00;
	//tls_reg_write32(HR_UART4_FIFO_CTRL, 0x00);            /* one byte TX/RX */
	//tls_reg_write32(HR_UART4_INT_MASK, 0x00);            	/* Disable INT */
	UART4->INTM=0x00;
#endif			//use_haluart

	//uart0 rx/tx pin assignment
#if defined(UART4TX2PIN)
	UART4TX2PIN();
#endif

#if defined(UART4RX2PIN)
	UART4RX2PIN();
#endif

}


//put a string
void uart4Puts(char *str) {
#ifndef UART_TXISR
#if defined(USE_HALUART)
	HAL_UART_Transmit(&huart4, (uint8_t *)str, strlen(str), 1000);
#else		//baremetal
    //polling transmission
    while(*str) {
        uart4Putch(*str++);	//send the ch and advance the pointer
    }
#endif		//use_haluart
#else
    //interrupt transmission
    if (*str) {								//if the string isn't empty to begin with
        uart1Wait();						//for compatability with polling transmission
        //U1TXREG = 0;						//clear the buffer
        //_U1TX_BUSY  = 1;					//transmission in progress
        _U0TX_ptr=str;						//point to the string to be transmitted
        IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
        //U1STAbits.UTXEN = 1;				//enable transmission - always enabled
        //tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
        UART1->TDW = *_U0TX_ptr++;			//U1TXREG = *_U1TX_ptr++;
        IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
    }
#endif
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
//void uart1Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart1Puts(ln);
//	//USARTWriteString("\r\n");
//	uart1Puts((char *)"\r\n");
//}

//get the received char
//uint8_t uart1Getch(void) {
//	return U1RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart1Available(void) {
//	return U1STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart1Busy(void) {
//	return U1STAbits.UTXBF;
//}

//print to uart4
void u4Print(char *str, int32_t dat) {
    static char uRAM[uRAM_SIZE];		//uart print buffer

    //uart1Wait();						//wait for the prior transmission to finish
    //while (IEC1bits.U1TXIE) continue;

    //form the string
    strcpy(uRAM, str);					//copy to uram
    if (dat < 0) {
        uRAM[6]='-';
        dat = -dat;
    }
    uRAM[19]='0'+(dat % 10); dat /= 10;
    uRAM[18]='0'+(dat % 10); dat /= 10;
    uRAM[17]='0'+(dat % 10); dat /= 10;
    uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[15]='0'+(dat % 10); dat /= 10;
    uRAM[14]='0'+(dat % 10); dat /= 10;
    uRAM[13]='0'+(dat % 10); dat /= 10;
    uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[11]='0'+(dat % 10); dat /= 10;
    uRAM[10]='0'+(dat % 10); dat /= 10;
    uRAM[ 9]='0'+(dat % 10); dat /= 10;
    uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[ 7]='0'+(dat % 10); dat /= 10;
    uart4Puts(uRAM);	//send a message on uart1
}

//circular buffer for uart4 transmission
//initialize uart4 using cb
void u4CBInit(CB_TypeDef *cb, uint32_t bps) {
	uart4Init(bps);
	cbInit(cb);
}

// transmit on uart4 using CB
void u4CBTX(CB_TypeDef *cb) {
	while ((!cbEmpty(cb)) && (!uart4TXFull())) uart4Putch(cbRead(cb));
}
//end uart4

//it is not clear if this chip has a uart5.
//uart5
volatile char *_U5TX_ptr;									//buffer pointer
UART_HandleTypeDef huart5;

//8 data bits, 1 stop bit, no parity, tx/rx enabled
void uart5Init (unsigned long baudrate) {
	unsigned long bd;

	//enable clock to uart
	RCC->CLK_EN |= (1<<6);									//1->enable clock. bit6..1 = uart5..0
	//enable the clock to uart4
	//REG_SET(HR_CLK_GATE_EN, 1<<5);						//1->enable clock, bit 11=gpio, 10=timer, 6..1=uart5..0

	NVIC_DisableIRQ(UART2_5_IRQn);
	NVIC_ClearPendingIRQ(UART2_5_IRQn);

#if defined(USE_HALUART)
	//UART_HandleTypeDef huart5;

	huart5.Instance = UART5;
	huart5.Init.BaudRate = baudrate;
	huart5.Init.WordLength = UART_WORDLENGTH_8B;
	huart5.Init.StopBits = UART_STOPBITS_1;
	huart5.Init.Parity = UART_PARITY_NONE;
	huart5.Init.Mode = UART_MODE_TX | UART_MODE_RX;
	huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	if (HAL_UART_Init(&huart5) != HAL_OK) {
        empty_handler();									//Error_Handler();
    }
#else		//baremetal
	//make sure that the baudrate isn't too high for F_UART
	if (F_UART/(16*baudrate)) {
		bd = (F_UART/(16*baudrate) - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (F_UART/(16*baudrate) - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	} else {
		bd = (1                   - 1)|((((F_UART%(baudrate*16))*16+(baudrate*8))/(baudrate*16))<<16);	//improved version, with rounding up
		//bd = (1                   - 1)|(((F_UART%(baudrate*16))*16/(baudrate*16))<<16);					//original version, no rounding up
	}
	UART5->BAUDR = bd;									//tls_reg_write32(HR_UART5_BAUD_RATE_CTRL, bd);

	UART5->LC = 
				UART_RXEN_BIT |								//0->disable rx, 1->enable rx	//tls_reg_write32(HR_UART5_LINE_CTRL, UART_8BITS_VAL | UART_TXEN_BIT | UART_RXEN_BIT | UART_STOP1_BIT | UART_PARITYEVEN_BIT | UART_PARITYDIS_BIT);
				UART_TXEN_BIT |								//0->disable tx, 1->enable tx
				UART_BRKDIS_BIT |							//0->disable break; 1->enable break;
				UART_PARITYEVEN_BIT |						//0->even parity, 1->odd parity
				UART_PARITYDIS_BIT |						//0->disable parity, 1->enable parity
				UART_STOP1_BIT |							//0->1 stop bit, 1->2 stop bits
				UART_8BITS_VAL |							//0->5 bits, 1->6 bits, 2->7 bits, 3->8 bits
				0x00;

	//tls_reg_write32(HR_UART5_FLOW_CTRL, 0x00);   			/* Disable afc */
	UART5->FC = 0x00;
	//tls_reg_write32(HR_UART5_DMA_CTRL, 0x00);            	/* Disable DMA */
	UART5->DMAC=0x00;
	//tls_reg_write32(HR_UART5_FIFO_CTRL, 0x00);         	/* one byte TX/RX */
	//tls_reg_write32(HR_UART5_INT_MASK, 0x00);            	/* Disable INT */
	UART5->INTM=0x00;
#endif		//use_haluart

	//uart0 rx/tx pin assignment
#if defined(UART5TX2PIN)
	UART5TX2PIN();
#endif

#if defined(UART5RX2PIN)
	UART5RX2PIN();
#endif

}


//put a string
void uart5Puts(char *str) {
#ifndef UART_TXISR
#if defined(USE_HALUART)
	HAL_UART_Transmit(&huart5, (uint8_t *)str, strlen(str), 1000);
#else		//baremetal
    //polling transmission
    while(*str) {
        uart5Putch(*str++);	//send the ch and advance the pointer
    }
#endif		//use_haluart
#else
    //interrupt transmission
    if (*str) {								//if the string isn't empty to begin with
        uart1Wait();						//for compatability with polling transmission
        //U1TXREG = 0;						//clear the buffer
        //_U1TX_BUSY  = 1;					//transmission in progress
        _U0TX_ptr=str;						//point to the string to be transmitted
        IFS1bits.U1TXIF = 0;				//UxTXIF = 0;							//clear the flag
        //U1STAbits.UTXEN = 1;				//enable transmission - always enabled
        //tmp = *_UxTX_ptr++;	UxTXREG = tmp;						//*_UxTX_ptr++;				//load up the 1st char. advance to the next char
        UART1->TDW = *_U0TX_ptr++;			//U1TXREG = *_U1TX_ptr++;
        IEC1bits.U1TXIE = 1;				//UxTXIE = 1;							//enable the interrupt
    }
#endif
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

*/

//put a line termined with ln
//void uart1Putline(char *ln) {
//	//USARTWriteString(ln);
//	uart1Puts(ln);
//	//USARTWriteString("\r\n");
//	uart1Puts((char *)"\r\n");
//}

//get the received char
//uint8_t uart1Getch(void) {
//	return U1RXREG;		//return it
//}

//test if data rx is available
//uint16_t uart1Available(void) {
//	return U1STAbits.URXDA;
//}

//test if uart tx is busy
//uint16_t uart1Busy(void) {
//	return U1STAbits.UTXBF;
//}

//print to uart5
void u5Print(char *str, int32_t dat) {
    static char uRAM[uRAM_SIZE];		//uart print buffer

    //uart1Wait();						//wait for the prior transmission to finish
    //while (IEC1bits.U1TXIE) continue;

    //form the string
    strcpy(uRAM, str);					//copy to uram
    if (dat < 0) {
        uRAM[6]='-';
        dat = -dat;
    }
    uRAM[19]='0'+(dat % 10); dat /= 10;
    uRAM[18]='0'+(dat % 10); dat /= 10;
    uRAM[17]='0'+(dat % 10); dat /= 10;
    uRAM[16]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[15]='0'+(dat % 10); dat /= 10;
    uRAM[14]='0'+(dat % 10); dat /= 10;
    uRAM[13]='0'+(dat % 10); dat /= 10;
    uRAM[12]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[11]='0'+(dat % 10); dat /= 10;
    uRAM[10]='0'+(dat % 10); dat /= 10;
    uRAM[ 9]='0'+(dat % 10); dat /= 10;
    uRAM[ 8]=',';	//'0'+(dat % 10); dat /= 10;
    uRAM[ 7]='0'+(dat % 10); dat /= 10;
    uart5Puts(uRAM);	//send a message on uart1
}

//circular buffer for uart5 transmission
//initialize uart5 using cb
void u5CBInit(CB_TypeDef *cb, uint32_t bps) {
	uart5Init(bps);
	cbInit(cb);
}

// transmit on uart5 using CB
void u5CBTX(CB_TypeDef *cb) {
	while ((!cbEmpty(cb)) && (!uart5TXFull())) uart5Putch(cbRead(cb));
}
//end uart5

//end uart

//timer
static void (* _tmr0_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default
static void (* _tmr1_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default
static void (* _tmr2_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default
static void (* _tmr3_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default
static void (* _tmr4_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default
static void (* _tmr5_isrptr)(void)=empty_handler;				//tmr_ptr pointing to empty_handler by default

//tmr isr
void ISR TIM0_5_IRQHandler(void) {
	//tmr0 isr
	if (TIM->CR & ((1<<4) << (0*5))) {
		TIM->CR |=((1<<4) << (0*5));	//1->clear the flag, 0->no effect
		_tmr0_isrptr();					//execute user isr
	}

	//tmr1 isr
	if (TIM->CR & ((1<<4) << (1*5))) {
		TIM->CR |=((1<<4) << (1*5));	//1->clear the flag, 0->no effect
		_tmr1_isrptr();					//execute user isr
	}

	//tmr2 isr
	if (TIM->CR & ((1<<4) << (2*5))) {
		TIM->CR |=((1<<4) << (2*5));	//1->clear the flag, 0->no effect
		_tmr2_isrptr();					//execute user isr
	}

	//tmr3 isr
	if (TIM->CR & ((1<<4) << (3*5))) {
		TIM->CR |=((1<<4) << (3*5));	//1->clear the flag, 0->no effect
		_tmr3_isrptr();					//execute user isr
	}

	//tmr4 isr
	if (TIM->CR & ((1<<4) << (4*5))) {
		TIM->CR |=((1<<4) << (4*5));	//1->clear the flag, 0->no effect
		_tmr4_isrptr();					//execute user isr
	}

	//tmr5 isr
	if (TIM->CR & ((1<<4) << (5*5))) {
		TIM->CR |=((1<<4) << (5*5));	//1->clear the flag, 0->no effect
		_tmr5_isrptr();					//execute user isr
	}
}

//tmr0
void tmr0Init(void) {
	//enable clock to timer
	RCC->CLK_EN |= (1<<10);				//1->enable clock. bit 10 = timer

	//disable the interrupt
	NVIC_DisableIRQ(TIM_IRQn);
	NVIC_ClearPendingIRQ(TIM_IRQn);

	//configure the timer
	_tmr0_isrptr = empty_handler;		//reset timer isr pointer
	TIM->CR = 	(TIM->CR &~(0x1f<<(0*5))) |
	            (0x00 << (0*5));		//0x00->stop / reset the timer
	//TIM->TIM0_CNT=0;					//clear the counter -> read only :)
	//TIM->TMR_CONFIG = 0;				//F_CPU/1000000-1;			//set the prescaler to f_cpu/1000000-1 so timer increments once per us
	TIM->TIM0_PRD = 0xfffffffful;		//set the timer period - maximum @ 32-bit
	TIM->CR|= 	((1<<4) |				//1->clear the interrupt flag, 0->no effect
	             (0<<3) |				//1->enable the interrupt, 0->disable the interrupt
	             (1<<2) | 				//1->enable the timer, 0->disable the timer
	             (0<<1) |				//0->periodic timer, 1->single shot
	             (0<<0)) << (0*5);		//1->timing unit is ms, 0->timing unit is us
}

//install user handler
void tmr0AttachISR(void (*isrptr)(void)) {
	TIM->CR|=	(1<<4) << (0*5);		//1->clear the interrupt flag, 0->no effect
	//NVIC_DisableIRQ(TIM_IRQn);
	//NVIC_ClearPendingIRQ(TIM_IRQn);

	_tmr0_isrptr=isrptr;				//install user isr
	TIM->CR|= (1<<3) << (0*5);			//1->enable the interrupt, 0->disable the interrupt
	//NVIC_SetPriority(TIM_IRQn, 0);	//set priority
	NVIC_ClearPendingIRQ(TIM_IRQn);		//clear pending flag
	NVIC_EnableIRQ(TIM_IRQn);			//enable the interrupt
}

//tmr1
void tmr1Init(void) {
	//enable clock to timer
	RCC->CLK_EN |= (1<<10);				//1->enable clock. bit 10 = timer

	//disable the interrupt
	NVIC_DisableIRQ(TIM_IRQn);
	NVIC_ClearPendingIRQ(TIM_IRQn);

	//configure the timer
	_tmr1_isrptr = empty_handler;		//reset timer isr pointer
	TIM->CR = 	(TIM->CR &~(0x1f<<(1*5))) |
	            (0x00 << (1*5));		//0x00->stop / reset the timer
	//TIM->TIM0_CNT=0;					//clear the counter -> read only :)
	//TIM->TMR_CONFIG = 0;				//F_CPU/1000000-1;			//set the prescaler to f_cpu/1000000-1 so timer increments once per us
	TIM->TIM1_PRD = 0xfffffffful;		//set the timer period - maximum @ 32-bit
	TIM->CR|= 	((1<<4) |				//1->clear the interrupt flag, 0->no effect
	             (0<<3) |				//1->enable the interrupt, 0->disable the interrupt
	             (1<<2) | 				//1->enable the timer, 0->disable the timer
	             (0<<1) |				//0->periodic timer, 1->single shot
	             (0<<0)) << (1*5);		//1->timing unit is ms, 0->timing unit is us
}

//install user handler
void tmr1AttachISR(void (*isrptr)(void)) {
	TIM->CR|=	(1<<4) << (1*5);		//1->clear the interrupt flag, 0->no effect
	//NVIC_DisableIRQ(TIM_IRQn);
	//NVIC_ClearPendingIRQ(TIM_IRQn);

	_tmr1_isrptr=isrptr;				//install user isr
	TIM->CR|= (1<<3) << (1*5);			//1->enable the interrupt, 0->disable the interrupt
	//NVIC_SetPriority(TIM_IRQn, 0);	//set priority
	NVIC_ClearPendingIRQ(TIM_IRQn);		//clear pending flag
	NVIC_EnableIRQ(TIM_IRQn);			//enable the interrupt
}

//tmr2
void tmr2Init(void) {
	//enable clock to timer
	RCC->CLK_EN |= (1<<10);				//1->enable clock. bit 10 = timer

	//disable the interrupt
	NVIC_DisableIRQ(TIM_IRQn);
	NVIC_ClearPendingIRQ(TIM_IRQn);

	//configure the timer
	_tmr2_isrptr = empty_handler;		//reset timer isr pointer
	TIM->CR = 	(TIM->CR &~(0x1f<<(2*5))) |
	            (0x00 << (2*5));		//0x00->stop / reset the timer
	//TIM->TIM0_CNT=0;					//clear the counter -> read only :)
	//TIM->TMR_CONFIG = 0;				//F_CPU/1000000-1;			//set the prescaler to f_cpu/1000000-1 so timer increments once per us
	TIM->TIM2_PRD = 0xfffffffful;		//set the timer period - maximum @ 32-bit
	TIM->CR|= 	((1<<4) |				//1->clear the interrupt flag, 0->no effect
	             (0<<3) |				//1->enable the interrupt, 0->disable the interrupt
	             (1<<2) | 				//1->enable the timer, 0->disable the timer
	             (0<<1) |				//0->periodic timer, 1->single shot
	             (0<<0)) << (2*5);		//1->timing unit is ms, 0->timing unit is us
}

//install user handler
void tmr2AttachISR(void (*isrptr)(void)) {
	TIM->CR|=	(1<<4) << (2*5);		//1->clear the interrupt flag, 0->no effect
	//NVIC_DisableIRQ(TIM_IRQn);
	//NVIC_ClearPendingIRQ(TIM_IRQn);

	_tmr2_isrptr=isrptr;				//install user isr
	TIM->CR|= (1<<3) << (2*5);			//1->enable the interrupt, 0->disable the interrupt
	//NVIC_SetPriority(TIM_IRQn, 0);	//set priority
	NVIC_ClearPendingIRQ(TIM_IRQn);		//clear pending flag
	NVIC_EnableIRQ(TIM_IRQn);			//enable the interrupt
}

//tmr3
void tmr3Init(void) {
	//enable clock to timer
	RCC->CLK_EN |= (1<<10);				//1->enable clock. bit 10 = timer

	//disable the interrupt
	NVIC_DisableIRQ(TIM_IRQn);
	NVIC_ClearPendingIRQ(TIM_IRQn);

	//configure the timer
	_tmr3_isrptr = empty_handler;		//reset timer isr pointer
	TIM->CR = 	(TIM->CR &~(0x1f<<(3*5))) |
	            (0x00 << (3*5));		//0x00->stop / reset the timer
	//TIM->TIM0_CNT=0;					//clear the counter -> read only :)
	//TIM->TMR_CONFIG = 0;				//F_CPU/1000000-1;			//set the prescaler to f_cpu/1000000-1 so timer increments once per us
	TIM->TIM3_PRD = 0xfffffffful;		//set the timer period - maximum @ 32-bit
	TIM->CR|= 	((1<<4) |				//1->clear the interrupt flag, 0->no effect
	             (0<<3) |				//1->enable the interrupt, 0->disable the interrupt
	             (1<<2) | 				//1->enable the timer, 0->disable the timer
	             (0<<1) |				//0->periodic timer, 1->single shot
	             (0<<0)) << (3*5);		//1->timing unit is ms, 0->timing unit is us
}

//install user handler
void tmr3AttachISR(void (*isrptr)(void)) {
	TIM->CR|=	(1<<4) << (3*5);		//1->clear the interrupt flag, 0->no effect
	//NVIC_DisableIRQ(TIM_IRQn);
	//NVIC_ClearPendingIRQ(TIM_IRQn);

	_tmr3_isrptr=isrptr;				//install user isr
	TIM->CR|= (1<<3) << (3*5);			//1->enable the interrupt, 0->disable the interrupt
	//NVIC_SetPriority(TIM_IRQn, 0);	//set priority
	NVIC_ClearPendingIRQ(TIM_IRQn);		//clear pending flag
	NVIC_EnableIRQ(TIM_IRQn);			//enable the interrupt
}

//tmr4
void tmr4Init(void) {
	//enable clock to timer
	RCC->CLK_EN |= (1<<10);				//1->enable clock. bit 10 = timer

	//disable the interrupt
	NVIC_DisableIRQ(TIM_IRQn);
	NVIC_ClearPendingIRQ(TIM_IRQn);

	//configure the timer
	_tmr4_isrptr = empty_handler;		//reset timer isr pointer
	TIM->CR = 	(TIM->CR &~(0x1f<<(4*5))) |
	            (0x00 << (4*5));		//0x00->stop / reset the timer
	//TIM->TIM0_CNT=0;					//clear the counter -> read only :)
	//TIM->TMR_CONFIG = 0;				//F_CPU/1000000-1;			//set the prescaler to f_cpu/1000000-1 so timer increments once per us
	TIM->TIM4_PRD = 0xfffffffful;		//set the timer period - maximum @ 32-bit
	TIM->CR|= 	((1<<4) |				//1->clear the interrupt flag, 0->no effect
	             (0<<3) |				//1->enable the interrupt, 0->disable the interrupt
	             (1<<2) | 				//1->enable the timer, 0->disable the timer
	             (0<<1) |				//0->periodic timer, 1->single shot
	             (0<<0)) << (4*5);		//1->timing unit is ms, 0->timing unit is us
}

//install user handler
void tmr4AttachISR(void (*isrptr)(void)) {
	TIM->CR|=	(1<<4) << (4*5);		//1->clear the interrupt flag, 0->no effect
	//NVIC_DisableIRQ(TIM_IRQn);
	//NVIC_ClearPendingIRQ(TIM_IRQn);

	_tmr4_isrptr=isrptr;				//install user isr
	TIM->CR|= (1<<3) << (4*5);			//1->enable the interrupt, 0->disable the interrupt
	//NVIC_SetPriority(TIM_IRQn, 0);	//set priority
	NVIC_ClearPendingIRQ(TIM_IRQn);		//clear pending flag
	NVIC_EnableIRQ(TIM_IRQn);			//enable the interrupt
}

//tmr5
void tmr5Init(void) {
	//enable clock to timer
	RCC->CLK_EN |= (1<<10);				//1->enable clock. bit 10 = timer

	//disable the interrupt
	NVIC_DisableIRQ(TIM_IRQn);
	NVIC_ClearPendingIRQ(TIM_IRQn);

	//configure the timer
	_tmr5_isrptr = empty_handler;		//reset timer isr pointer
	TIM->CR = 	(TIM->CR &~(0x1f<<(5*5))) |
	            (0x00 << (5*5));		//0x00->stop / reset the timer
	//TIM->TIM0_CNT=0;					//clear the counter -> read only :)
	//TIM->TMR_CONFIG = 0;				//F_CPU/1000000-1;			//set the prescaler to f_cpu/1000000-1 so timer increments once per us
	TIM->TIM5_PRD = 0xfffffffful;		//set the timer period - maximum @ 32-bit
	TIM->CR|= 	((1<<4) |				//1->clear the interrupt flag, 0->no effect
	             (0<<3) |				//1->enable the interrupt, 0->disable the interrupt
	             (1<<2) | 				//1->enable the timer, 0->disable the timer
	             (0<<1) |				//0->periodic timer, 1->single shot
	             (0<<0)) << (5*5);		//1->timing unit is ms, 0->timing unit is us
}

//install user handler
void tmr5AttachISR(void (*isrptr)(void)) {
	TIM->CR|=	(1<<4) << (5*5);			//1->clear the interrupt flag, 0->no effect
	//NVIC_DisableIRQ(TIM_IRQn);
	//NVIC_ClearPendingIRQ(TIM_IRQn);

	_tmr5_isrptr=isrptr;					//install user isr
	TIM->CR|= (1<<3) << (5*5);				//1->enable the interrupt, 0->disable the interrupt
	//NVIC_SetPriority(TIM_IRQn, 0);		//set priority
	NVIC_ClearPendingIRQ(TIM_IRQn);			//clear pending flag
	NVIC_EnableIRQ(TIM_IRQn);				//enable the interrupt
}
//end timer

//pwm
//initialize pwm0
void pwm0Init(void) {
	//enable clock to pwm
	RCC->CLK_EN |= (1<<13);					//1->enable clock. bit 13 = pwm

	//reset devider
	//PWM->CLKDIV01 = 0;
	//PWM->CLKDIV23 = 0;
	//disable pwm
	PWM->CR &=~(1<<27);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0
	PWM->CR  = 	(PWM->CR &~(0x03<<16)) |	//bit17..16=ch0, bit 19..18=ch1, bit 21..20=ch2, bit 23..22=ch3
	            (0x01 << 16);				//pwm mode: 0b01->edge aligned, 0b10-> center aligned (downcounter)
	PWM->CR |= (1<<8);						//1->auto reload, 0->single shot. bit 11..8 for ch3..0
	//W801 boards are active low - so reverse polarity
	PWM->CR |= (1<<2);						//1->reverse polarity, 0->normal polarity. bit 5..2 for ch3..0
	//PWM->CR &=~(1<<0);					//1->complimentary output, 0->single pole

	//set period
	PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (0*8))) |
	                (0xff << (0*8));		//period, 8 bit only
	//PWM->PNUM =		(PWM->PNUM &~(0xff << (0*8))) |
	//				(0x00 << (0*8));		//pnum is 0
	//enable pwm
	PWM->CR |= (1<<27);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0

#if defined(PWM02PIN)
	PWM02PIN();
#endif
}

//initialize pwm1
void pwm1Init(void) {
	//enable clock to pwm
	RCC->CLK_EN |= (1<<13);					//1->enable clock. bit 13 = pwm

	//reset devider
	//PWM->CLKDIV01 = 0;
	//PWM->CLKDIV23 = 0;
	//disable pwm
	PWM->CR &=~(1<<28);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0
	PWM->CR  = 	(PWM->CR &~(0x03<<18)) |	//bit17..16=ch0, bit 19..18=ch1, bit 21..20=ch2, bit 23..22=ch3
	            (0x01 << 18);				//pwm mode: 0b01->edge aligned, 0b10-> center aligned (downcounter)
	PWM->CR |= (1<<9);						//1->auto reload, 0->single shot. bit 11..8 for ch3..0
	//W801 boards are active low - so reverse polarity
	PWM->CR |= (1<<3);						//1->reverse polarity, 0->normal polarity. bit 5..2 for ch3..0
	//PWM->CR &=~(1<<0);					//1->complimentary output, 0->single pole

	//set period
	PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (1*8))) |
	                (0xff << (1*8));		//period, 8 bit only
	//PWM->PNUM =		(PWM->PNUM &~(0xff << (0*8))) |
	//				(0x00 << (0*8));		//pnum is 0
	//enable pwm
	PWM->CR |= (1<<28);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0

#if defined(PWM12PIN)
	PWM12PIN();
#endif
}

//initialize pwm2
void pwm2Init(void) {
	//enable clock to pwm
	RCC->CLK_EN |= (1<<13);					//1->enable clock. bit 13 = pwm

	//reset devider
	//PWM->CLKDIV01 = 0;
	//PWM->CLKDIV23 = 0;
	//disable pwm
	PWM->CR &=~(1<<29);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0
	PWM->CR  = 	(PWM->CR &~(0x03<<20)) |	//bit17..16=ch0, bit 19..18=ch1, bit 21..20=ch2, bit 23..22=ch3
	            (0x01 << 20);				//pwm mode: 0b01->edge aligned, 0b10-> center aligned (downcounter)
	PWM->CR |= (1<<10);						//1->auto reload, 0->single shot. bit 11..8 for ch3..0
	//W801 boards are active low - so reverse polarity
	PWM->CR |= (1<<4);						//1->reverse polarity, 0->normal polarity. bit 5..2 for ch3..0
	//PWM->CR &=~(1<<0);					//1->complimentary output, 0->single pole

	//set period
	PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (2*8))) |
	                (0xff << (2*8));		//period, 8 bit only
	//PWM->PNUM =		(PWM->PNUM &~(0xff << (0*8))) |
	//				(0x00 << (0*8));		//pnum is 0
	//enable pwm
	PWM->CR |= (1<<29);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0

#if defined(PWM22PIN)
	PWM22PIN();
#endif
}

//initialize pwm3
void pwm3Init(void) {
	//enable clock to pwm
	RCC->CLK_EN |= (1<<13);					//1->enable clock. bit 13 = pwm

	//reset devider
	//PWM->CLKDIV01 = 0;
	//PWM->CLKDIV23 = 0;
	//disable pwm
	PWM->CR &=~(1<<30);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0
	PWM->CR  = 	(PWM->CR &~(0x03<<22)) |	//bit17..16=ch0, bit 19..18=ch1, bit 21..20=ch2, bit 23..22=ch3
	            (0x01 << 22);				//pwm mode: 0b01->edge aligned, 0b10-> center aligned (downcounter)
	PWM->CR |= (1<<11);						//1->auto reload, 0->single shot. bit 11..8 for ch3..0
	//W801 boards are active low - so reverse polarity
	PWM->CR |= (1<<5);						//1->reverse polarity, 0->normal polarity. bit 5..2 for ch3..0
	//PWM->CR &=~(1<<0);					//1->complimentary output, 0->single pole

	//set period
	PWM->PERIOD = 	(PWM->PERIOD &~(0xff << (3*8))) |
	                (0xff << (3*8));		//period, 8 bit only
	//PWM->PNUM =		(PWM->PNUM &~(0xff << (0*8))) |
	//				(0x00 << (0*8));		//pnum is 0
	//enable pwm
	PWM->CR |= (1<<30);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0

#if defined(PWM32PIN)
	PWM32PIN();
#endif
}

//initialize pwm4
//***pwm4*** is special - code below is bespoke to pwm4
void pwm4Init(void) {
	//enable clock to pwm
	RCC->CLK_EN |= (1<<13);					//1->enable clock. bit 13 = pwm

	//reset devider
	//PWM->CLKDIV01 = 0;
	//PWM->CLKDIV23 = 0;
	//disable pwm
	PWM->CR &=~(1<<31);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0
	PWM->CH4CR2 = 	(PWM->CH4CR2 &~(0x03 << 3)) |
	            (0x01 << 3);				//pwm mode: 0b01->edge aligned, 0b10-> center aligned (downcounter)
	PWM->CH4CR2 |= (1 << 1);				//1->auto reload, 0->single shot. bit 11..8 for ch4..0
	//W801 boards are active low - so reverse polarity
	PWM->CH4CR2 |= (1 << 0);				//1->reverse polarity, 0->normal polarity. bit 5..2 for ch4..0
	//PWM->CR &=~(1<<0);					//1->complimentary output, 0->single pole

	//set period
	PWM->CH4CR1 = 	(PWM->CH4CR1 &~(0xff << (1*8))) |
	                (0xff << (1*8));		//period, 8 bit only
	//PWM->PNUM =		(PWM->PNUM &~(0xff << (0*8))) |
	//				(0x00 << (0*8));		//pnum is 0
	//enable pwm
	PWM->CR |= (1<<31);						//1->enable cnt, 0->disable cnt. bit 31..27 for channel 4..0

#if defined(PWM42PIN)
	PWM42PIN();
#endif
}

//write pwm to a pin
void analogWrite(uint8_t pin, uint16_t dc) {
	dc = dc & 0xff;							//8-bit wide
	switch (pin) {
		//pwm ch0
		case PB0: pwm0Init(); PWM0SetDC(dc); PWM02PB0(); break;
		case PB19:pwm0Init(); PWM0SetDC(dc); PWM02PB19();break;
		case PB12:pwm0Init(); PWM0SetDC(dc); PWM02PB12();break;
		case PA2: pwm0Init(); PWM0SetDC(dc); PWM02PA2(); break;
		case PA10:pwm0Init(); PWM0SetDC(dc); PWM02PA10();break;

		//pwm ch1
		case PB1: pwm1Init(); PWM1SetDC(dc); PWM12PB1(); break;
		case PB20:pwm1Init(); PWM1SetDC(dc); PWM12PB20();break;
		case PB13:pwm1Init(); PWM1SetDC(dc); PWM12PB13();break;
		case PA3: pwm1Init(); PWM1SetDC(dc); PWM12PA3(); break;
		case PA11:pwm1Init(); PWM1SetDC(dc); PWM12PA11();break;

		//pwm ch2
		case PA0: pwm2Init(); PWM2SetDC(dc); PWM22PA0(); break;
		case PB2: pwm2Init(); PWM2SetDC(dc); PWM22PB2();break;
		case PB14:pwm2Init(); PWM2SetDC(dc); PWM22PB14(); break;
		case PA12:pwm2Init(); PWM2SetDC(dc); PWM22PA12();break;
		case PB24:pwm2Init(); PWM2SetDC(dc); PWM22PB24();break;

		//pwm ch3
		case PA1: pwm3Init(); PWM3SetDC(dc); PWM32PA1(); break;
		case PB3: pwm3Init(); PWM3SetDC(dc); PWM32PB3();break;
		case PB15:pwm3Init(); PWM3SetDC(dc); PWM32PB15(); break;
		case PA13:pwm3Init(); PWM3SetDC(dc); PWM32PA13();break;
		case PB25:pwm3Init(); PWM3SetDC(dc); PWM32PB25();break;

		//pwm ch4
		case PA4: pwm4Init(); PWM4SetDC(dc); PWM42PA4(); break;
		case PA7: pwm4Init(); PWM4SetDC(dc); PWM42PA7();break;
		case PA14:pwm4Init(); PWM4SetDC(dc); PWM42PA14(); break;
		case PB16:pwm4Init(); PWM4SetDC(dc); PWM42PB16();break;
		case PB26:pwm4Init(); PWM4SetDC(dc); PWM42PB26();break;

		default: break;	//do nothing
	}
}
//end pwm

//pmu
//initialize pmu
void pmuInit(void) {
	//route the clock to pmu
	//RCC->CLK_EN |= (1<<0);				//1->enable pmu, 0->disable pmu. bit 0 = pmu
	
	IO_SET(PMU->CR, 1<<4);					//1->clock from 40Mhz oscillator, 0->32Khz RC oscillator (default)
	//IO_CLR(PMU->CR, 1<<4);				//1->clock from 40Mhz oscillator, 0->32Khz RC oscillator (default)
	//0->1 to start calibration of the 32Khz rc oscillator
	IO_CLR(PMU->CR, 1<<3); 
	IO_SET(PMU->CR, 1<<3);					//1->start rc calibration, 0->no effect
	//while (PMU->CR & (1<<3)) continue;	//wait for it to clear?
	
	PMU->TIMER0 |= (1<<16);					//1->start timer0
	PMU->RSV    |= (1<<16);					//1->start timer1

	PMU->RTCCR0 &=~(1<<31);					//1->enable interrupt, 0->disable interrupt
	PMU->RTCCR1 |= (1<<16);					//1->enable alarm, 0->disable alartm
}

//void pmuStartT0(uint32_t sec) {
//	PMU->TIMER0  = 	(1<<16) |				//1->start timer
//					(sec & 0xffff);			//set sec
//}

//void pmuStartT1(uint32_t sec) {
//	PMU->TIMER1  = 	(1<<16) |				//1->start timer
//					(sec & 0xffff);			//set sec
//}

//end pmu

//watchdog timer
static void (* _wdg_isrptr)(void)=empty_handler;				//wdg timer pointing to empty_handler by default

//wdg isr
void ISR WDG_IRQHandler(void) {
	wdgIFClr();								//WDG->CLR = 0;							//write any value to clear the status
	_wdg_isrptr();							//execute user isr
}

//reset the watchdog timer
void wdgInit(void) {
	_wdg_isrptr = empty_handler;			//reset the handler
	
	//NVIC_SetPriority(WDG_IRQn, 0);		//set priority
	NVIC_ClearPendingIRQ(WDG_IRQn);			//clear pending flag
	NVIC_DisableIRQ(WDG_IRQn);				//enable the interrupt

	WDG->CLR = 0;							//write any value to clear interrupts
	//no reset, period timer
	WDG->CR =	(0<<1) |					//1->enable wdg reset, 0->disable wdg reset
				(1<<0) |					//1->enable periodic timer, 0->disable periodic timer
				0x00;
}

//attach usr isr
void wdgAttachISR(void (*isrptr)(void)) {
	//NVIC_SetPriority(WDG_IRQn, 0);		//set priority
	NVIC_ClearPendingIRQ(WDG_IRQn);			//clear pending flag
	NVIC_DisableIRQ(WDG_IRQn);				//disable the interrupt

	WDG->CLR = 0;							//write any value to clear interrupts
	
	_wdg_isrptr = isrptr;					//install user handler

	//NVIC_SetPriority(WDG_IRQn, 0);		//set priority
	NVIC_ClearPendingIRQ(WDG_IRQn);			//clear pending flag
	NVIC_EnableIRQ(WDG_IRQn);				//enable the interrupt
}
//end watchdog timer

//adc
//initialize adc
void adcInit(void) {
	uint32_t tmp=0;
	
	//enable clock to adc
	RCC->CLK_EN |= (1<<12);					//1->enable adc, 0->disable adc. bit 12 = adc
	
	//calculate adc clock divider
	tmp = F_PHB / F_ADC / 1024; if (tmp) tmp-=1;	// "/1000" is required. "/1024" is OK
	RCC->CLK_SEL = (RCC->CLK_SEL &~(0xff << 8)) | ((tmp & 0xff) << 8);
	RCC->CLK_EN |= (1<<31);					//set the en bit to make the clock effective
	
	//configure the adc
	ADC->ADC_CR = 	(0x50 <<20) |			//sampling time after channel switch, default 0x50
					(0x50 << 8) |			//time for the analog circuit to be stable after adc start, default 0x50
					(0 << 5) |				//0->disable comparator interrupt, 1->enable comparator interrupt
					(0 << 4) |				//0->disable analog comp, 1->enable analog comp
					(0 << 1) |				//1->enable interrupt, 0->disable interrupt
					(0 << 0) |				//0->disable dma, 1->enable dma
					0x00;
	ADC->PGA_CR =	(0 << 4) |				//pga gain, 0..1023 / 0x3ff
					(0 << 3) |				//0-> don't bypass PGA, 1->bypass PGA
					(0 << 2) |				//0-> don't bypass internal Vref, 1->bypass internal Vref
					(1 << 1) |				//1-> enable chopper, 0->disable chopper
					(1 << 0) |				//1-> enable pga, 0->disable pga
					0x00;

	//calculate offset
	ADC->ANA_CR =	(0b1110 << 8) |			//0b1110 = offset channel
					(0 << 2) |				//pd_sdadc: 0->enable, 1->disable
					(1 << 1) |				//rstn_sdadc: 1->normal, 0->disable
					(1 << 0) |				//1->enable adc ldo, 0->disable adc ldo
					0x00;
	//adcOffset(8);							//calibrate the adc for offset
}

//read adc
//support SE and diff inputs
uint32_t adcRead(uint8_t ch) {
	uint32_t tmp;
	
	//select the pipns
	switch (ch) {
		case ADC_CH0: ADC02PIN(); break;	//ch0 input
		case ADC_CH1: ADC12PIN(); break;	//ch1 input
		case ADC_CH2: ADC22PIN(); break;	//ch2 input
		case ADC_CH3: ADC32PIN(); break;	//ch3 input
		case ADC_CH01:ADC02PIN(); ADC12PIN(); break;	//ch 0-1 input
		case ADC_CH23:ADC22PIN(); ADC32PIN(); break;	//ch 2-3 input
	}
	//set the adc channel
	ADC->ANA_CR = 	(ADC->ANA_CR &~(0b1111 << 8)) |	
					((ch & 0b1111) << 8);
	ADC->ANA_CR|= (1<<0);					//1->enable adc ldo, 0->disable adc ldo
	ADC_DLY();
	//ADC->IF |= (1<< 0);						//1->clear adc interrupt flag
	//ADC_DLY();		//while ((ADC->IF & (1<<0)) == 0) continue;	//wait for ADC->IF bit 0 to be set -> indicating end of conversion
	//ADC->IF |= (1<< 0);						//1->clear adc interrupt flag
	
	tmp = ADC->DR;							//read the adc value
	ADC->ANA_CR&=~(1<<0);					//1->enable adc ldo, 0->disable adc ldo
	//needs to do conversion - datasheet not clear
	//tmp ^= 0x20000ul;						//flip the highest bit (bit 18)
	if (tmp & 0x20000ul) tmp = tmp & 0x1fffful; else tmp |=0x20000ul;
	//ADC->ANA_CR |= (1<<2);				//pd_sdadc: 0->enable, 1->disable
	return tmp;
}

//calibarte adc offset
//average over N runs - N should be power of 2
uint32_t adcReadN(uint8_t ch, uint8_t N) {
	uint32_t tmp=0, avg=0;
	
	for (avg=0, tmp=0; tmp<N; tmp++) avg+=adcRead(ch);
	return avg /= N;				//return the average over 8 runs
}

//read vtemp: a very convoluted process, per the datasheet
//reading returned here is 16x that in the datasheet
//8x oversampling
//calibration: 
//1. 74180@65.5F/18.6C
//2. 74300@66.2F/
//3. 74330@66.4F/
//4. 74500@66.9F/
//5. 74800@68.0F/
int32_t adcReadTempx16(void) {
	uint32_t code_out1, code_out2;
	
	adcSetGain(PGAx4);						//set gain to 4x
	ADC->TEMP_CR = 	(0 << 4) |				//temp gain. 0->2x, 1->4x, 2->6x, 3=8x
					(0 << 1) |				//temp calib bit, 0->for code_out1, 1->for code_out2
					(1 << 0) |				//1->enable the temp module, 0->disable the temp module
					0x00;
	code_out1 = adcReadN(ADC_TEMP, 8);		//read code_out1.
	ADC->TEMP_CR = 	(0 << 4) |				//temp gain. 0->2x, 1->4x, 2->6x, 3=8x
					(1 << 1) |				//temp calib bit, 0->for code_out1, 1->for code_out2
					(1 << 0) |				//1->enable the temp module, 0->disable the temp module
					0x00;
	code_out2 = adcReadN(ADC_TEMP, 8);		//read code_out2.
	
	//disable the temp module
	ADC->TEMP_CR&=~(1<<0);					//1->enable the temp module, 0->disable the temp module
	return code_out1 - code_out2;			//reading is 16x Vtemp shown in the datasheet
}

#define ADC2mv(adc)			((int32_t) (adc) / 4 * 685/10000)		//first formula
//#define ADC2mv(adc)			((int32_t) (adc) / 4 * 1011/2/10000)	//second formula
//read the chip's own power supply / Vcc, in mv: a very convoluted process, per the datasheet
//8x oversampling
//per datasheet: 
//Vcc = (codeout - offset)*68.5uv/2 + 1.2v, codeout and offset in 16 bit form, or
//Vcc = (codeout - offset) * 685 / 20000 + 1200, in mv
//Note to self: I think 1200mv here is wrong. it should be 1311mv (=default Vcmin)
//Vcc = 2.389v using 1200mv, and 2.500v (=LDO output voltage) using 1311mv (=default Vcmin)
uint32_t adcReadVcc(void) {
	uint32_t offset, codeout;
	
	adcSetGain(PGAx2);						//set the gain to 2x
	offset = adcOffset(8);					//read the offset, 
	codeout= adcReadN(ADC_VLDO, 8);			//read the adc_comp
	//return (codeout - offset) * 685 / 20000 + Vcmx1k();	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
	return ADC2mv(codeout - offset) * 4 / 2 + Vcmx1k();	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
}

//deprecated
//read analog input
//return in mv
//gain fixed at 2x
 int32_t adcReadmv0(uint8_t ch) {
	uint32_t offset, codeout;
	
	adcSetGain(PGAx2);						//set the gain to 2x
	offset = adcOffset(8);					//read the offset, 
	codeout= adcReadN(ch, 8);				//read the adc_comp
	//code uses a slope of LSB = (126364/1000.0), constant of 1196, on 16-bit results
	//return (int32_t) (codeout - offset) / 4 * 685 / 20000 + Vcmx1k();	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
	return ADC2mv(codeout - offset) / 2 + Vcmx1k();
}

//read analog input
//return in mv
//user specified gain
 int32_t adcReadmv(uint8_t ch, uint8_t gain) {
	uint32_t offset, codeout;
	 int32_t tmp;
	
	adcSetGain(gain);						//set the gain to 2x
	offset = adcOffset(8);					//read the offset, 
	codeout= adcReadN(ch, 8);				//read the adc_comp
	tmp = ADC2mv(codeout - offset);	//tmp = (int32_t) (codeout - offset) / 4 * 685 / 10000;
	switch (gain) {
		case PGAx1   : tmp /= 1   ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx2   : tmp /= 2   ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx3   : tmp /= 3   ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx4   : tmp /= 4   ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx16  : tmp /= 16  ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx32  : tmp /= 32  ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx48  : tmp /= 48  ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx64  : tmp /= 64  ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx96  : tmp /= 96  ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx128 : tmp /= 128 ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx192 : tmp /= 192 ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx256 : tmp /= 256 ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx384 : tmp /= 384 ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx512 : tmp /= 512 ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx768 : tmp /= 768 ; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
		case PGAx1024: tmp /= 1024; break;	//return in mv, using default Vcmin of 1311mv, vs. 1200mv per datasheet vs. 1196mv per code
	}
	switch (ch) {
		//add back Vcm for single ended channels
		case ADC_CH0:
		case ADC_CH1:
		case ADC_CH2:
		case ADC_CH3:
		case ADC_VLDO:
		case ADC_TEMP:
		case ADC_OFST:
			tmp+= Vcmx1k();					//add the offset for single ended channels
			break;
	}
	return tmp;
}

//generate 4-bit random numbers
uint8_t arand4(void) {
	uint8_t tmp=arand1();
	
	//tmp = (tmp << 1) | arand1();
	tmp = (tmp << 1) | arand1();
	tmp = (tmp << 1) | arand1();
	tmp = (tmp << 1) | arand1();
	return tmp;
}

//generate 8-bit random number
uint8_t arand8(void) {
	return (arand4() << 4) | arand4();
}

//return 16-bit random number
uint16_t arand16(void) {
	return ((uint16_t) arand8() << 8) | arand8();
}


//return 32-bit random number
uint32_t arand32(void) {
	return ((uint32_t) arand16() << 16) | arand16();
}

//end adc

//touch
//initialize touch sensors
void TSInit(void) {
	//enable clock
	RCC->CLK_EN |= (1<<21);					//1->enable touch sensors, 0->disable touch sensors. bit 21 = touch sensors
	
	TOUCH->CR =		(10 <<26) |				//scan period, in 16ms. 0..0x3f. default 10
					(20 <<20) |				//capdet windows. 2..3f. default 20
					(0  << 4) |				//touch sensor, 0x0000..0xffff
					(0  << 0) |				//1->enable touch, 0->disable touch
					0x00;

	//configure interrupt
	TOUCH->IE_IF = 	0xffff;					//ie (31.16): 0->disable interrupt, 1->enable interrupt. if (15..0): write 1 to clear
	
	//NVIC_SetPriority(TOUCH_IRQn, 0);		//set priority
	NVIC_ClearPendingIRQ(TOUCH_IRQn);		//clear pending flag
	NVIC_DisableIRQ(TOUCH_IRQn);			//disable the interrupt

	TOUCH->CR|=		(1  << 0);				//1->enable touch, 0->disable touch
}

//set threshold. default = 50
void TSSetTHS(PIN_TypeDef pin, uint8_t ths) {
	ths = ths & 0x3f;									//0..63
	//configure touch registers / pins (afio opt7)
	switch (pin) {
		case PA0: TOUCH->CH0CR = (TOUCH->CH0CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA1: TOUCH->CH1CR = (TOUCH->CH1CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA2: TOUCH->CH2CR = (TOUCH->CH2CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA3: TOUCH->CH3CR = (TOUCH->CH3CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA4: TOUCH->CH4CR = (TOUCH->CH4CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA5: TOUCH->CH5CR = (TOUCH->CH5CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA6: TOUCH->CH6CR = (TOUCH->CH6CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA7: TOUCH->CH7CR = (TOUCH->CH7CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA8: TOUCH->CH8CR = (TOUCH->CH8CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA9: TOUCH->CH9CR = (TOUCH->CH9CR &~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA10:TOUCH->CH10CR= (TOUCH->CH10CR&~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA11:TOUCH->CH11CR= (TOUCH->CH11CR&~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA12:TOUCH->CH12CR= (TOUCH->CH12CR&~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA13:TOUCH->CH13CR= (TOUCH->CH13CR&~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA14:TOUCH->CH14CR= (TOUCH->CH14CR&~0x3f) | ths; pinAFIO(pin, 7); break;
		case PA15:TOUCH->CH15CR= (TOUCH->CH15CR&~0x3f) | ths; pinAFIO(pin, 7); break;
		default: break;	//do nothing
	}
}

//get threshold. default = 50
uint8_t TSGetTHS(PIN_TypeDef pin) {
	uint8_t ths=0;									//0..63
	switch (pin) {
		case PA0:  ths = TOUCH->CH0CR ; break;
		case PA1:  ths = TOUCH->CH1CR ; break;
		case PA2:  ths = TOUCH->CH2CR ; break;
		case PA3:  ths = TOUCH->CH3CR ; break;
		case PA4:  ths = TOUCH->CH4CR ; break;
		case PA5:  ths = TOUCH->CH5CR ; break;
		case PA6:  ths = TOUCH->CH6CR ; break;
		case PA7:  ths = TOUCH->CH7CR ; break;
		case PA8:  ths = TOUCH->CH8CR ; break;
		case PA9:  ths = TOUCH->CH9CR ; break;
		case PA10: ths = TOUCH->CH10CR; break;
		case PA11: ths = TOUCH->CH11CR; break;
		case PA12: ths = TOUCH->CH12CR; break;
		case PA13: ths = TOUCH->CH13CR; break;
		case PA14: ths = TOUCH->CH14CR; break;
		case PA15: ths = TOUCH->CH15CR; break;
		default: break; //do nothing
	}
	return ths & 0x3f;
}

//enable touch on a pin
void TSEnable(PIN_TypeDef pin) {
	//ths = ths & 0x3f;									//0..63
	if ((pin >= PA0) && (pin <= PA15)) {				//touch pins are pa0..15
		pinTouch(pin);									//change pin setting
		//TOUCH->CH0CR = (TOUCH->CH0CR &~0x3f) | ths; 	//set touch thresholds
		TOUCH->CR |= GPIO_PinDef[pin].mask;				//add pin to scan
	}
}
//end touch

//lcd
//initialize lcd
void LCDInit(void) {
	//enable clock
	RCC->CLK_EN |= (1<<14);					//1->enable lcd, 0->disable lcd. bit 14 = lcd
}
//end lcd

//spi
//initialize spi
void spiInit(void) {
	//enable clock
	RCC->CLK_EN |= (1<<7);					//1->enable clock, 0->disable clock. bit 7 = spi
	
	//disable interrupts
	NVIC_ClearPendingIRQ(SPI_LS_IRQn);		//clear pend flag
	//NVIC_SetPriority(SPI_LS_IRQn, 0);		//set the priority
	NVIC_DisableIRQ(SPI_LS_IRQn);			//disable the irq

	//disable spi
	SPI->CH_CFG&=~(1<<0);					//1->enable spi, 0->disable spi
	//configure spi
	SPI->CH_CFG = 	(0 << 23) |				//invalid bits
					(1 << 22) |				//1->clear fifo, 0->no effect
					(0 << 21) |				//1->continous mode, 0->transmit only if fifo has data (default)
					(0 << 20) |				//1->enable rx, 0->disable rx
					(1 << 19) |				//1->enable tx, 0->disable tx
					(8 <<  3) |				//bit length. bit 18..3
					(0 <<  2) |				//1->spi_cs effective high, 0->spi_cs effective low
					(1 <<  1) |				//1->spi_cs software controlled, 0->spi_cs hardware controlled
					(0 <<  0) |				//1->enable spi, 0->disable spi
					0x00;
	SPI->SPI_CFG=	(0b00 << 17) |			//spi format: 0b00->motorolla, 0b01->TI, 0b10->microwire, 0b11->reserved
					(1 << 16) |				//1->spi pin always driven, 0->spi pin tri-stated
					(0 << 12) |				//spi_cs hold time post transmission, 0..7, in APB clock cycles (0..127)
					(0 <<  9) |				//spi_cs hold time before transmission, 0..7, in APB clock cycles (0..127)
					(0 <<  7) |				//spi output delay, 0..3, in APB clock cycles
					(0 <<  4) |				//frame delay (in between spi_cs edges). 0..7, in APB clock cycles (0..127)
					(0 <<  3) |				//0->least significant bit first, 1->most significant bit first
					(1 <<  2) |				//1->this device is a master, 0->this device is a slave
					(0 <<  1) |				//spi phase: 1->phase A, 0->phase b
					(0 <<  0) |				//spi polarity: 1->sck idles high, 0->sck idles low
					0x00;
	SPI->CLK_CFG=	(F_PHB / F_SPI / 2 - 1) & 0xffff;	//set up the clock divider. 16 bits wide
	SPI->MODE_CFG=	(4 << 6) |				//rx int / dma threshold: if rx fifo has more data than specified here. 0..7
					(4 << 2) |				//tx int / dma threshold: if tx fifo has more data than specified here. 0..7
					(0 << 1) |				//1->rx dma on, 0->rx dma off
					(0 << 0) |				//1->tx dma on, 0->tx dma off
					0x00;
	SPI->INT_MASK=	(1 << 7) |				//spi timeout: 0->allows interrupts, 1->disallows interrupts
					(1 << 6) |				//spi done: 0->allows interrupts, 1->disallows interrupts
					(1 << 5) |				//spi rx overrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 4) |				//spi rx underrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 3) |				//spi tx overrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 2) |				//spi tx underrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 1) |				//spi rx fifo ready: 0->allows interrupts, 1->disallows interrupts
					(1 << 0) |				//spi tx fifo ready: 0->allows interrupts, 1->disallows interrupts
					0x00;
	//write 1 to clear
	SPI->INT_SRC=	(1 << 7) |				//spi timeout: 0->allows interrupts, 1->disallows interrupts
					(1 << 6) |				//spi done: 0->allows interrupts, 1->disallows interrupts
					(1 << 5) |				//spi rx overrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 4) |				//spi rx underrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 3) |				//spi tx overrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 2) |				//spi tx underrun: 0->allows interrupts, 1->disallows interrupts
					(1 << 1) |				//spi rx fifo ready: 0->allows interrupts, 1->disallows interrupts
					(1 << 0) |				//spi tx fifo ready: 0->allows interrupts, 1->disallows interrupts
					0x00;
	SPI->TRANS_MODE=(8 <<24) |				//transmission block length. 4..32 bits
					(0 <<16) |				//1->allows microburst, 0->does not allow microburst
					(8 << 8) |				//microwire block length under microburst. 1..32 bits
					(8 << 0) |				//microwire command length, 1..32 bits
					0x00;
	//SPI->SLV_LEN=	0x00;					//slave length - set to default
	//enable spi
	SPI->CH_CFG |=	(1 <<  0);				//1->enable spi, 0->disable spi
	
	//enable the pins
#if defined(SPISCK2PIN)
	SPISCK2PIN();
#endif

#if defined(SPIMOSI2PIN)
	SPIMOSI2PIN();
#endif

#if defined(SPIMISO2PIN)
	SPIMISO2PIN();
#endif
}

//transmit a byte
uint8_t spiWrite(uint8_t dat) {
	spiWait();								//wait if the tx buffer is full
	SPI->TXDATA = (dat);					//transmit a byte
	return SPI->RXDATA;						//return received data
}

//transmit a buffer
void spiWrites(uint8_t *dat, uint32_t bytes) {
	uint8_t *tmp=dat;
	while (bytes--) spiWrite(*tmp++);
}

//end spi

//i2c
#define I2CWait()		while (I2C->CR_SR & (1<<1)) continue	//wait for i2c transmission to end
//initialize i2c
void i2cInit(void) {
	//enable clock
	RCC->CLK_EN |= (1<<0);						//1->enable clock, 0->disable clock. bit 0 = i2c

	//disable interrupts
	NVIC_ClearPendingIRQ(I2C_IRQn);				//clear pend flag
	//NVIC_SetPriority(I2C_IRQn, 0);			//set the priority
	NVIC_DisableIRQ(I2C_IRQn);					//disable the irq

	//disable i2c
	I2C->EN &=~(1<<7);							//1->enable i2c, 0->disable i2c
	
	//configure i2c
	//configure the clock
	I2C->PRESCALE_L = ((F_PHB / F_I2C - 1) >> 0) & 0xff;
	I2C->PRESCALE_H = ((F_PHB / F_I2C - 1) >> 8) & 0xff;
	/****** write 1 to disable interrupt on bit 6*******/
	I2C->EN |= (1<<6);							//1->disable interrupt, 0->enable interrupt
	
	//enable i2c
	I2C->EN |= (1<<7);							//1->enable i2c, 0->disable i2c
	
	//enable the pins
#if defined(I2CSCL2PIN)
	I2CSCL2PIN();
#endif

#if defined(I2CSDA2PIN)
	I2CSDA2PIN();
#endif
}

//send a stop condition
uint8_t i2cStop(void) {
    I2C->CR_SR = (1<<6);
    I2CWait();									//while (I2C->CR_SR & I2C_SR_TIP) continue;
	return I2C->CR_SR & (1<<1);
}

//write one byte to slave
uint8_t i2cWrite(uint8_t dat, uint8_t ifstart) {
	I2C->DATA = dat;							//load the data
	I2C->CR_SR = ((ifstart)?(1<<7):0) | (1<<4);
	I2CWait();									//while (I2C->CR_SR & I2C_SR_TIP) continue;	//wait for the transmission to complete
	return (I2C->CR_SR & (1<<7))?I2C_ACK:I2C_NOACK;	//return ack/noack status
}

//write multiple bytes byte to slave
uint8_t i2cWrites(uint8_t devaddr, uint8_t regaddr, uint8_t *dat, uint32_t bytes) {
	uint8_t *tmp=dat;
	if (i2cWrite(devaddr & 0xfe, 1) == I2C_NOACK) return i2cStop();
	if (i2cWrite(regaddr       , 0) == I2C_NOACK) return i2cStop();
	while (bytes--) i2cWrite(*tmp++, 0);
	i2cStop();
	return 0;
}

//read one byte from slave
uint8_t i2cRead(uint8_t ack_noack, uint8_t ifstop) {
	uint8_t tmp=0;
	tmp |= (ack_noack == I2C_ACK)?(1<<3) :0;
	tmp |= (ifstop              )?(1<<6):0;
	I2C->CR_SR = tmp;							//write to cr/sr
	I2CWait();									//while (I2C->CR_SR & I2C_SR_TIP) continue;	//wait for the transmission to complete
	return I2C->DATA;							//return the data
}

//read multiple bytes from slave
uint8_t i2cReads(uint8_t devaddr, uint8_t regaddr, uint8_t *dat, uint32_t bytes) {
	uint8_t *tmp=dat;
	if (i2cWrite(devaddr & 0xfe, 1) == I2C_NOACK) return i2cStop();
	if (i2cWrite(regaddr       , 0) == I2C_NOACK) return i2cStop();
	//restart
	if (i2cWrite(devaddr | 0x01, 1) == I2C_NOACK) return i2cStop();
	while (bytes--) if (bytes==1) *tmp++= i2cRead(I2C_ACK, 1); else *tmp++ = i2cRead(I2C_NOACK, 0);
	return 0;
}

//end i2c

//software i2c
#define sI2C_HIGH(pin)				do {                        pinMode(pin, INPUT);  sI2C_DLY();} while (0)	//let pin float to high
#define sI2C_LOW(pin)				do {digitalWrite(pin, LOW); pinMode(pin, OUTPUT); sI2C_DLY();} while (0)	//pull pin low
#define sI2C_GET(pin)				digitalRead(pin)			//read a pin
#define sI2C_DLY()					delayTks(F_CPU / F_sI2C / 4)								//software I2C delay for half of the period to achieve F_sI2C

//initialize i2c
void sI2CInit(void) {
	//pins idle high / as input
	sI2C_HIGH(sI2CSDAPIN); sI2C_HIGH(sI2CSCLPIN);				//clear the bus (idles high)
}


//-----------------START Condition-----------------------
void sI2CStart(void) {
	sI2C_HIGH(sI2CSDAPIN);						//let sda high
	sI2C_HIGH(sI2CSCLPIN);						//let scl high
	sI2C_LOW(sI2CSDAPIN);						//pull i2c_sda low
	sI2C_LOW(sI2CSCLPIN);						//pull i2c_scl low
}

//------------------STOP Condition--------------------------
void sI2CStop(void) {
	sI2C_LOW(sI2CSCLPIN);						//let scl float high
	sI2C_LOW(sI2CSDAPIN);
	sI2C_HIGH(sI2CSCLPIN);						//let scl float high
	sI2C_HIGH(sI2CSDAPIN);						//let sda  high
}

//------------------restart condition---------------------

//-------------------I2C Write---------------------------
uint8_t sI2CWrite(uint8_t dat) {
	unsigned char i;

	sI2C_HIGH(sI2CSDAPIN);						//let sda float
	i=0x80;
	do {
		sI2C_LOW(sI2CSCLPIN);					//clear i2c_scl
	  	if(dat & i)
			{sI2C_HIGH(sI2CSDAPIN);}			//set i2c_sda
		else
			{sI2C_LOW(sI2CSDAPIN);}				//clear i2c_sda
		sI2C_HIGH(sI2CSCLPIN);					//set i2c_scl
	  	i = i >> 1;								//shift out the highest bit
	} while (i);
	sI2C_LOW(sI2CSCLPIN);						//clear i2c_scl

	sI2C_HIGH(sI2CSDAPIN);						//float sda, let the slave control it
	sI2C_HIGH(sI2CSCLPIN);
	i=0;
	while (sI2C_GET(sI2CSDAPIN)&&(i<I2C_ACK_ERROR))
		i++;									//wait for ack from the slave (ack = sda pulled to low by the slave
	sI2C_LOW(sI2CSCLPIN);
	if (i<I2C_ACK_ERROR) return I2C_ACK;		//no trouble
	else return I2C_NOACK;						//trouble! ack timed out
}

//-----------------------i2c read------------------------------
//to be consistent with i2c protocol, use negative logic
//ack = 0 -> send ack
//ack = 1 -> no ack
uint8_t sI2CRead(uint8_t ack) {
	unsigned char i, data_t=0;

	sI2C_HIGH(sI2CSDAPIN);						//let sda float
	i=0x80;
	do {
		sI2C_LOW(sI2CSCLPIN);					//clear i2c_scl
		data_t <<=1;							//left shift the data
		i = i >> 1;
		//i2c_delay(0); i2c_delay(0);i2c_delay(0);i2c_delay(0);
		sI2C_HIGH(sI2CSCLPIN);					//let scl float to high
		if (sI2C_GET(sI2CSDAPIN)) data_t |= 0x01;	//set the last bit high
		else data_t |= 0x00;
		//i2c_delay(0);
	} while (i);
	sI2C_LOW(sI2CSCLPIN);						//pull scl low
	if (ack==I2C_ACK)
		{sI2C_LOW(sI2CSDAPIN);}					//send ack
	else
		{sI2C_HIGH(sI2CSDAPIN);}				//send no-ack
	sI2C_HIGH(sI2CSCLPIN);						//send ack/no-ack
	sI2C_LOW(sI2CSCLPIN);
	return data_t;
}

//write from a buffer
uint8_t sI2CWrites(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToWrite) {
	sI2CStart();							//send start condition
	sI2CWrite(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	sI2CWrite(RegAddr);					//send register addr
	while (NumByteToWrite) {
		sI2CWrite(*pBuffer);				//send data
		pBuffer++;							//increment buffer pointer
		NumByteToWrite--;					//decrement counter
	}
	sI2CStop();							//send stop condition
	return 0;								//indicating success
}

//read to a buffer
uint8_t sI2CReads(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t *pBuffer, uint16_t NumByteToRead) {
	sI2CStart();							//send start condition
	sI2CWrite(DeviceAddr | I2C_CMD_WRITE);	//send device addr, for write operations
	sI2CWrite(RegAddr);					//send register addr
	sI2CStart();							//send restart
	sI2CWrite(DeviceAddr | I2C_CMD_READ);	//send device addr, for read operations
	while (NumByteToRead) {
		if (NumByteToRead==1) {
			*pBuffer=sI2CRead(I2C_NOACK);
			sI2CStop();							//send the stop condition
			break;
		}
		*pBuffer=sI2CRead(I2C_ACK);		//read the data
		pBuffer++;							//increment buffer
		NumByteToRead--;					//decrement count
	}
	return 0;
}

//end software i2c

//true random number generator
//initialize the 32-bit random number generator
//the following must be true:
//  CP bits: 1..7
//  digital post processing enabled: bit 2 = 0
//  generate true random numbers: bit 1 = 1
void trngInit(void) {
	//enable the lock
	RCC->CLK_EN |= 1<<17;				//1->enable clock to gpsec, 0->disable clock to gpsec
	
	//seed the generator
	GPSEC->KEY0 = 31415926ul;			//just some random numbers
	//disable the trng module
	//GPSEC->TRNG_CR &=~(1<<0);			//1->enable the trng module, 0->disable the trng module
	GPSEC->TRNG_CR =	(4<<3) |		//CP - not sure what this is. W801 demo used this value (4). 1..7 valid values
						(0<<2) |		//0->enable digital post process, 1->disable digital post process
						(1<<1) |		//0->produce pseudo random numbers, 1->produce true random numbers
						(1<<0) |		//1->enable the trng module, 0->disable the trng module
						0x00;
	//now trng is running
}

//random number generator
//initialize the 32-bit pseudo random number generator
//the following must be true:
//  CP bits: 1..7
//  digital post processing enabled: bit 2 = 0
//  generate pseudo random numbers: bit 1 = 0
void prngInit(void) {
	//enable the lock
	RCC->CLK_EN |= 1<<17;				//1->enable clock to gpsec, 0->disable clock to gpsec
	
	//seed the generator
	GPSEC->KEY0 = 0x31415926ul;			//just some random numbers
	GPSEC->CFG =	(1<<30) |			//1->enable rng, 0->disable rng
					(1<<29) |			//1->load the seed, 0->use 0 as seed
					(1<<28) |			//1->32 bit rng, 0->16bit rng
					0x00;
	//disable the trng module
	//GPSEC->TRNG_CR &=~(1<<0);			//1->enable the trng module, 0->disable the trng module
	GPSEC->TRNG_CR =	(4<<3) |		//CP - not sure what this is. W801 demo used this value (4). 1..7 valid values
						(0<<2) |		//0->enable digital post process, 1->disable digital post process
						(0<<1) |		//0->produce pseudo random numbers, 1->produce true random numbers
						(1<<0) |		//1->enable the trng module, 0->disable the trng module
						0x00;
	//now prng is running
}

//end trng

//circular buffer
//global defines
#define cBUFF_SIZE_MASK 	(cBUFF_SIZE-1U)		//mask

//global variables
//reset the cbuffer
void cbInit(CB_TypeDef *cbuffer) {
	cbuffer->writeIndex = cbuffer->readIndex = -1;
}

//returns true if cbuffer is empty
char cbEmpty(CB_TypeDef *cbuffer) {
	return (cbuffer->writeIndex & cBUFF_SIZE_MASK) == (cbuffer->readIndex & cBUFF_SIZE_MASK);
}

//returns true if cbuffer is full;
char cbFull(CB_TypeDef *cbuffer) {
	return ((cbuffer->writeIndex + 1) & cBUFF_SIZE_MASK) == (cbuffer->readIndex & cBUFF_SIZE_MASK);
}

//write to the buffer - needs to test if the buffer is full before writing to it
cbuffer_t cbWrite(CB_TypeDef *cbuffer, cbuffer_t dat) {
	cbuffer->buffer[(++cbuffer->writeIndex) & cBUFF_SIZE_MASK] = dat;
	return dat;
}

//read from the buffer - needs to test if the buffer is empty before reading from it
cbuffer_t cbRead(CB_TypeDef *cbuffer) {
	return cbuffer->buffer[(++cbuffer->readIndex) & cBUFF_SIZE_MASK];
}

//write string to CB
void str2cb(CB_TypeDef *cb, char *str) {
	while (!cbFull(cb) && (*str)) cbWrite(cb, *str++);
}

//write CB to string
void cb2str(char *str, CB_TypeDef *cb) {
	while (!cbEmpty(cb)) *str++=cbRead(cb);
}


//end circular buffer

//input capture - untested
//initialize input capture on pwm0
void ic0Init(void) {
	pwm0Init();						//initialize pwm0
	PWM->CR |= (1<<24);			//1->enable capture on pwm0, 0->disable capture
	
	//disable interrupt
}

//initialize input capture on pwm4
void ic4Init(void) {
	pwm4Init();						//initialize pwm4
	PWM->CH4CR2 |= (1<<1);			//1->enable capture on pwm4, 0->disable capture
	
	//disable interrupt
}

//end input capture

//fake fputc, if you want to to exclude libc_port.c 
//this reduces the size significantly (13KB+ footprint)
//if you use libc_port.c in the build, this version will be overwritten
__attribute__((weak)) int fputc(int ch, FILE *stream) {
    (void)stream;
    uart0Put(ch);						////sendchar(ch);
	return 0;
}
//end fake fputc

//end

