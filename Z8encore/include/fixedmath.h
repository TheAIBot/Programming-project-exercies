#ifndef _FIXEDMATH_H_
#define _FIXEDMATH_H_

//bits dedicated to decimals
#define FIX14_BIT_SHIFT 14

#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_BIT_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_BIT_SHIFT) / (b) )
#define FIX14_TO_INT(a) ((int)(a >> FIX14_BIT_SHIFT))
// need to convert it to a long before bitshift or else the bitshift will be done with an int which will remove data because the int isn't long enough
#define TO_FIX14(a) ((long)a << FIX14_BIT_SHIFT)

#endif