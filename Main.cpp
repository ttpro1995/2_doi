#pragma once
using namespace std;
#include <iostream>
#include "Lap_header.h"
#define NUM_OF_TEST_CASE 10
int main()
{

	for (int i = 0; i < NUM_OF_TEST_CASE; i++)
	{
		Play(i);
		
		cout << "\nDONE TEST CASE " << i << " \n";
	}

}