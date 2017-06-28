/**
 * @file       adc.h
 * @brief      Analog To Digital Converter interface for AT90S4433
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2005/07/05
 */

#ifndef __ADC_H__
#define __ADC_H__

#include "util.h"

#define ADC_SINGLE_CONVERSION 0
#define ADC_FREE_RUN          1

#define ADC_ENABLE_INTERRUPT  1
#define ADC_DISABLE_INTERRUPT 0

#define ADC_CONVERTING      0
#define ADC_CONVERSION_DONE 1

/**
 * @brief Initialize the ADC
  */
void adcInit();

/**
 * @brief Select the pin wich is converted
 * @param pinId is the PORTC pin Id [0..5]
 */
void adcSelectInput(unsigned char pinId);

/**
 * @brief Start a measurment of an ADC entry: the one selected by adcSelectInput
 * Run the function register with adcRegisterTreatmentCB when the measyre is completed
 */
void adcStart();

/**
 * @brief return the last measure of a pin
 * @param pin Id of the pin [0..5]
 * @return last analogic value of the pin
 */
unsigned char adcGetValue(unsigned char pin);

/**
 * @brief Register a callback that will be run after processing each 'adc read'
 */
void adcRegisterTreatmentCB(UtilFnPtr callback);


#endif /* __ADC_H__ */
