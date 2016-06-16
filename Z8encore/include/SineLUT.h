// =====================================================================
//
//	Exported by Cearn's excellut v1.0
//	(comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================

#ifndef SINELUT_H
#define SINELUT_H

// === LUT SIZES ===
#define SIN_SIZE 512

// === LUT DECLARATIONS ===
extern const signed short SIN[SIN_SIZE];

long expand(long);
void printFix(long);
long cos(int);
long sin(int);


#endif	// SINELUT_H
