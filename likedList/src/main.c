/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..//testing//inc//main_test.h"
#include "..//inc//LinkedList.h"


int main(void)
{
	startTesting(1);  // ll_newLinkedList  X
	startTesting(2);  // ll_len X
	startTesting(3);  // getNode - test_getNode X
	startTesting(4);  // addNode - test_addNode X
	startTesting(5);  // ll_add   X
	startTesting(6);  // ll_get   X
	startTesting(7);  // ll_set   X
	startTesting(8);  // ll_remove  X
	startTesting(9);  // ll_clear  X
	startTesting(10); // ll_deleteLinkedList X
	startTesting(11); // ll_indexOf   X
	startTesting(12); // ll_isEmpty  X
	startTesting(13); // ll_push   X
	startTesting(14); // ll_pop   X
	startTesting(15); // ll_contains  X
	startTesting(16); // ll_containsAll X
	startTesting(17); // ll_subList  X
	startTesting(18); // ll_clone X
	startTesting(19); // ll_sort  X
    return 0;
}
