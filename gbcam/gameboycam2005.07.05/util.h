/**
 * @file       util.h
 * @brief      Miscellaneous utilities
 * 
 * @author     Laurent Saint-Marcel (lstmarcel@yahoo.fr)
 * @date       2004/07/25
 */

#ifndef __UTIL_H__
#define __UTIL_H__

/** @brief Boolean */
typedef enum Boolean {
	 /** @brief Boolean False */
	 FALSE=0,
	 /** @brief Boolean True */
	 TRUE=1
} Boolean;

/** @brief Pointer on a function */
typedef void (*UtilFnPtr)();

#ifndef NULL
/** @brief NULL pointer = 0 */
#define NULL 0
#endif

#endif /* __UTIL_H__ */
