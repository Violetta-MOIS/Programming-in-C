#include <iostream>
#include "sort.h"
//#include "sort.cpp"
using namespace std;

int findSmallestPosition(int list[], int startPosition, int listLength){
	int smallestPosition = startPosition;

	for (int i = startPosition; i < listLength; i++)
	{
		if (list[i] < list[smallestPosition])
			smallestPosition = i;
	}
	return smallestPosition;
}

void selectionSort(int list[], int listLength) {
	for (int i = 0; i < listLength; i++)
	{
		int smallestPosition = findSmallestPosition(list, i, listLength);
		swap(list[i], list[smallestPosition]);
	}
	return;
}
int main ()
{
	int list[5] = {10, 0, 20, 5, 15};
	
	cout << " " << endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
	
	selectionSort(list, 5);
	
	cout << " " << endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
}