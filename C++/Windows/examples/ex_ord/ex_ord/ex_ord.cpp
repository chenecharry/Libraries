
#include ".\include\ex_order.h"
#include ".\include\fuzz_slice.h"
#include ".\include\fuzz_dice.h"

int main()
{

	ex_order();
	fuzz_slice();

	fuzz_dice();

    return 0;
}
