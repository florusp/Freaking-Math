#include"WorkingWithLevel.h"

void updateLevel(Diem &diem, Capdo &capdo)
{
	if (diem.score % 10 == 0)
	{
		capdo.level++;
		if (diem.score % 20 == 0)
			capdo.range = 10;
	}
	else
		capdo.range++;
}

void resetLevel(Diem &diem, Capdo &capdo)
{
	diem.score = 0;
	capdo.level = 1;
	capdo.range = 3;
}