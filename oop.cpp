#include "stdafx.h"
#include "Set.h"

void Initialize(Set *mySet, const size_t size);

Set MaxSum(Set *mySet, const size_t size);
Set MinSum(Set *mySet, const size_t size);
void GetArrayNegativeSet(Set *mySet, const size_t size);

int main()
{
    setlocale(LC_ALL, "rus");
	const size_t size = 10;
	Set mySet[size];
	Initialize(mySet, size);

	for (size_t i = 0; i < size; i++)
	{
		mySet[i].Print();
	}
