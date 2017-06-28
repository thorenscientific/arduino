/**
 * @file       adc.c
 * @brief      Analog To Digital Converter interface for AT90S4433
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2005/07/05
 */

#include <io.h>
#include <sig-avr.h>
#include <interrupt.h>

#include "adc.h"


/**
 * @brief Select the pin wich is converted
 * @param pinId is the PORTC pin Id [0..5]
 */
void adcSelectInput(unsigned char pinId);

/**
 * @brief Return the value of the last conversion on the first 10 bits of a 
 *        short
 */
unsigned short adcGetShortData();

/**
 * @brief Return the value of the last conversion on char. The 2 less 
 *        significant bits are removed. (It is a 10bits ADC)
 */
unsigned char adcGetCharData();

/**
 * @brief Return ADC_CONVERTING is there is a conversion running and no valid
 *        data yet, else it returns ADC_CONVERSION_DONE
 */
unsigned char adcIsConversionDone();


/* ------------------------------------------------------------------------ */
/* static                                                                  */
/* ------------------------------------------------------------------------ */
#define ADC_NBR 6

static unsigned char adcValues_[ADC_NBR];
static unsigned char adcCurrentPin_=0;
static UtilFnPtr     adcTreamentCB_=NULL;

/* ------------------------------------------------------------------------ */
/* adcInit                                                                  */
/* ------------------------------------------------------------------------ */
void adcInit()
{
	outp((1 << ADEN) /* enable ADC */
		| (ADC_SINGLE_CONVERSION << ADFR)  /* free run or single conversion */
		| (ADC_ENABLE_INTERRUPT << ADIE) /* enable ADC interruption */
		| (0x06), /* scale factor : XTAL / 64 < 200 kHz */
		ADCSR);
}

/* ------------------------------------------------------------------------ */
/* adcStart                                                                 */
/* ------------------------------------------------------------------------ */
void adcStart()
{
	sbi(ADCSR, ADSC);
}

/* ------------------------------------------------------------------------ */
/* adcSelectInput                                                           */
/* ------------------------------------------------------------------------ */
void adcSelectInput(unsigned char pinId)
{
	adcCurrentPin_=pinId;
	outp(pinId, ADMUX);
}

/* ------------------------------------------------------------------------ */
/* adcGetShortData                                                          */
/* ------------------------------------------------------------------------ */
unsigned short adcGetShortData()
{
	return (unsigned short)inp(ADCL) 
	       + (((unsigned short)inp(ADCH)) << 8);
}

/* ------------------------------------------------------------------------ */
/* adcGetCharData                                                           */
/* ------------------------------------------------------------------------ */
unsigned char adcGetCharData()
{
	unsigned char dataL=0, dataH=0;
	dataL = inp(ADCL);
	dataH = inp(ADCH);
	return (dataL >> 2) + (dataH << 6);
}


/* ------------------------------------------------------------------------ */
/* adcIsConversionDone                                                      */
/* ------------------------------------------------------------------------ */
unsigned char adcIsConversionDone()
{
	return  !(inp(ADCSR) & (1 << ADCSR));
}

/* ------------------------------------------------------------------------ */
/* adcGetValue                                                              */
/* ------------------------------------------------------------------------ */
unsigned char adcGetValue(unsigned char pin)
{
	return adcValues_[pin];
}

/* ------------------------------------------------------------------------ */
/* adcRegisterTreatment                                                     */
/* ------------------------------------------------------------------------ */
void adcRegisterTreatmentCB(UtilFnPtr callback)
{
	adcTreamentCB_ = callback;
}

/* ------------------------------------------------------------------------ */
/* INTERRUPT(SIG_ADC)                                                       */
/* ------------------------------------------------------------------------ */
/* Interrupt when ADC conversion finished                                   */
/* ------------------------------------------------------------------------ */
INTERRUPT(SIG_ADC)  
{
	adcValues_[adcCurrentPin_] = adcGetCharData();
	if (adcTreamentCB_) adcTreamentCB_();
}
