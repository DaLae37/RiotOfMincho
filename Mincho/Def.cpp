#include "stdafx.h"
#include "Def.h"


Def::Def()
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (i < 5 && j < 5)
				map[i][j] = false;
			else if (i < 5 && j >= 10)
				map[i][j] = false;
			else if (i >= 10 && j < 5)
				map[i][j] = false;
			else if (i >= 10 && j >= 10)
				map[i][j] = false;
			else
				map[i][j] = true;
		}
	}
}


Def::~Def()
{
}
