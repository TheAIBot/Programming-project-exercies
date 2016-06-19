#include <eZ8.h>
#include <sio.h>
#include "fixedmath.h"
#include "trigonometry.h"
#include "tests.h"

void printFix14(long i)
{
	if ((i & 0x80000000) != 0) 
	{
		printf("-");
		i = ~i + 1;
	}
	printf("%ld.%04ld", i >> 16 , 10000 * (unsigned long) (i & 0xffff) >> 16); // magic
}

void areLongsEqual(long a, long b, char error[])
{
	if(a != b)
	{
		printFix14(a);
		printf(" != ");
		printFix14(b);
		printf("; %s\n", error);
	}
	else
	{
		printFix14(a);
		printf(" == ");
		printFix14(b);
		printf("\n");
		//printf("works\n");
	}	
}

void areIntsEqual(int a, int b, char error[])
{
	if(a != b)
	{
		printf("%d != %d; %s\n", a, b, error);
	}
	else
	{
		printf("%d", a);
		printf(" == ");
		printf("%d", b);
		printf("\n");
		//printf("works\n");
	}
}

void testMath()
{
	printf("testing FIX14 math\n");

	printf("\n\ntesting int conversion to FIX14 format:\n");
	areLongsEqual(TO_FIX14(1), 1 << FIX14_BIT_SHIFT, "TO_FIX14 doesn't work");
	areLongsEqual(TO_FIX14(3), 3 << FIX14_BIT_SHIFT, "TO_FIX14 doesn't work");
	areLongsEqual(TO_FIX14(213), 213 << FIX14_BIT_SHIFT, "TO_FIX14 doesn't work");
	areLongsEqual(TO_FIX14(432), 432 << FIX14_BIT_SHIFT, "TO_FIX14 doesn't work");
	areLongsEqual(TO_FIX14(-1), -1 << FIX14_BIT_SHIFT, "TO_FIX14 doesn't work");


	printf("\n\ntesting conversion form int to FIX14 and back to int again:\n");
	areIntsEqual(FIX14_TO_INT(TO_FIX14(-324)), -324, "FIX14_TO_INT doesn't work");
	areIntsEqual(FIX14_TO_INT(TO_FIX14(-3)), -3, "FIX14_TO_INT doesn't work");
	areIntsEqual(FIX14_TO_INT(TO_FIX14(0)), 0, "FIX14_TO_INT doesn't work");
	areIntsEqual(FIX14_TO_INT(TO_FIX14(1)), 1, "FIX14_TO_INT doesn't work");
	areIntsEqual(FIX14_TO_INT(TO_FIX14(51)), 51, "FIX14_TO_INT doesn't work");
	areIntsEqual(FIX14_TO_INT(TO_FIX14(431)), 431, "FIX14_TO_INT doesn't work");

	printf("\n\ntesting FIX14 division:\n");
	areLongsEqual(FIX14_DIV(TO_FIX14(1), TO_FIX14(2)), (TO_FIX14(1) >> 1), "FIX14_DIV doesn't work");
	areLongsEqual(FIX14_DIV(TO_FIX14(5), TO_FIX14(2)), TO_FIX14(2) + (TO_FIX14(1) >> 1), "FIX14_DIV doesn't work");
	areLongsEqual(FIX14_DIV(TO_FIX14(1), TO_FIX14(1)), TO_FIX14(1), "FIX14_DIV doesn't work");
	areLongsEqual(FIX14_DIV(TO_FIX14(-5), TO_FIX14(2)), TO_FIX14(-2) + (TO_FIX14(-1) >> 1), "FIX14_DIV doesn't work");

	printf("\n\ntesting multiplication:\n");
	areLongsEqual(FIX14_MULT(TO_FIX14(1), TO_FIX14(2)), (TO_FIX14(2)), "FIX14_MULT doesn't work");
	areLongsEqual(FIX14_MULT(TO_FIX14(2), TO_FIX14(1) >> 1), (TO_FIX14(1)), "FIX14_MULT doesn't work");
	areLongsEqual(FIX14_MULT(TO_FIX14(2), TO_FIX14(1) >> 1), (TO_FIX14(1)), "FIX14_MULT doesn't work");


	//testing vector math using sin/cos

}

void runAllTests()
{
	testMath();
}
