/**
GeolUread
February 24. 2021
Array Expander
Write a function that accepts an int array and the array's size as arguments. The function should create a new array that is twice the size the argument array. The function should copy the contents of the argument array to a new array and initialize the unused elements of the second array with 0. The function should return a pointer to the new array.
**/

#include<iostream>
using namespace std; 

//Functions
void printArray(const int* list, int size);
int* arrayExpander(const int* list, int size);

int main()
{
	cout << "Array Expander - Problem #11\n\n" << endl;

	int size;
	cout << "Please enter the size of array: "; cin >> size;
	cout << "\n" << endl;

	int* arrayPtr = new int[size]; //This is the size of the array
	for (int i = 0; i < size; i++)
	{
		cout << "Enter value for " << i+1 << ": "; cin >> *(arrayPtr + i);
	}
	cout << "\n" << endl;


	//Print out original array
	cout << "Array\n" << endl;
	printArray(arrayPtr, size);
	cout << "\n" << endl;

	//Insert extended array into a pointer
	int* ptr = nullptr;
	int twice = size * 2;
	ptr = arrayExpander(arrayPtr, twice);
	
	//Print out extended array
	cout << "Expanded Array\n" << endl;
	printArray(ptr, twice);
	cout << "\n" << endl;

	//Delete dynamic memory
	delete[] arrayPtr;
	delete ptr;

	system("pause");
	return 0;
}

void printArray(const int *list, int size)
{
	//This function will print out the array
	for (int i = 0; i < size; i++)
	{
		cout << *(list + i) << " ";
	}
}

int* arrayExpander(const int* list, int size)
{
	if (size == 0)
	{
		return nullptr;
	}
	int half = size / 2;
	int *expandArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		if (i >= half)
		{
			*(expandArray + i) = 0;
		}
		else
		{
			*(expandArray + i) = list[i];
		}
	}
	return expandArray;
}
