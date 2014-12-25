#include "new_board.h"

#include <cstdlib>
#include <cstring>


block::block()
{
	memset(weight, 0, sizeof(weight));
	freedom = 0;
	influence = 0;
}

block::~block(){}
