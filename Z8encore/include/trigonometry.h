// =====================================================================
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================

#ifndef _TRIGONOMETRY_H
#define _TRIGONOMETRY_H

// === LUT SIZES ===
#define SIN_SIZE 512

// === LUT DECLARATIONS ===
extern const signed short SIN[SIN_SIZE];

long expand(long);
void printFix(long);
long cos(int);
long sin(int);


#endif	// SINELUT_H
