/*
Description: This Code will get ADC value from the ARM Cortex M3 controller through DMA Access n continous Mode
Target: Stellaris ARM CORTEX M3 LM3S328 Microcontroller
Firmware Version : V1
Author: Shivaprakash Pasupathibalan
@ 08 April 2020
*/ 
#define RCGC0          (*((volatile unsigned long *)0x400FE100))      //ADC Clock Enable for Run Mode Clock Gating Register
#define ADCACTSS       (*((volatile unsigned long *)0x40038000))      //setting Active Sample Sequencer
#define ADCEMUX        (*((volatile unsigned long *)0x40038014))      //ADC Event Multiplexer Select Register
#define ADCSSMUX3      (*((volatile unsigned long *)0x400380A0))      //ADC Sample Sequence Input Multiplexer select
#define ADCSSCTL3      (*((volatile unsigned long *)0x400380A4))      //ADC SS3 Control Register
#define ADCSSFIFO3     (*((volatile unsigned long *)0x400380A8))      //ADC Result Register for SS0
#define ADC    (1<<16)                                                //set ADC Clock in RCGC0 Register
#define ADC_SAMPLE_500  (1 << 9)                                      //set RCGC0 with 500 samples per sec ADC
#define ADC_SAMPLE_250  (1 << 8)                                      //set RCGC0 with 250 samples per sec ADC
#define ADC_SAMPLE_125  (0 << 8) | (0 << 9)                           //set RCGC0 with 125 samples per sec ADC
#define ADC_SS0         (1 << 0)                                      //Enable ADC_SS0 Sample Sequencer
#define ADC_SS1         (1 << 1)                                      //Enable ADC_SS1 Sample Sequencer
#define ADC_SS2         (1 << 2)                                      //Enable ADC_SS2 Sample Sequencer
#define ADC_SS3         (1 << 3)                                      //Enable ADC_SS3 Sample Sequencer
#define ADC_MUX_LOOP    (0x0F << 0)                                   //sets Sample sequencer 0 in continous mode
#define ADC_PIN         (0x01 << 0)                                   //Enables ADC1 as input
#define ADC_CTRL        (0x02 << 0)                                   //sets the control to Register ADCSSCTL3
unsigned int val = 0;
void main() 
{
  RCGC0 = ADC | ADC_SAMPLE_125;                                       //set ADC bit and default speed
  ADCACTSS = ADC_SS3;                                                 //Enable SSO Sample Sequencer
  ADCEMUX = ADC_MUX_LOOP;                                             //setting the Mode
  ADCSSMUX3 = ADC_PIN;                                                //Setting ADC1 as input
  ADCSSCTL3 = ADC_CTRL;
  val = (ADCSSFIFO3 & 0xFF);
  while(1)
  {
  
  } 
}
