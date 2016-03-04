/*
Author: Erin Williams
Course: 136
Instructor: Ilya Korsunskiy
Assignment: Lab 5

This program ...
 */

#include <iostream>
#include <cmath>
using namespace std;

// Precondition: num > 0
// Postcondition: the return value is num read backwards (in decimal)
int reversePos(int num);

// Precondition: num > 0
// Postcondition: the return value is the number of digits in num
int numDigits(int num);

// Precondition: num > 0, index > 0
// Postcondition: returns the digit of num located at index
int getDigit(int num, int index);


int main()
{
	int n;

	cout << "Enter a positive number: ";
	cin >> n;

	// Precondition: num > 0
	// Postcondition: Outputs a table of multiples of num up to 1023 and their reverses
	int multiple = n;
	for (int i=1; i<=1023 && multiple<=1023; i++)
	{
		multiple = n*i;
		cout << multiple << "\t" << reversePos(multiple) << endl;
	}

return 0;
}

int numDigits(int number)
{
	int counter = 0;
	for (int i=number; i>0; i/=10)
	{
		counter++;
	}
	return counter;
}

int getDigit(int num, int index)
{
	int numAtIndex = 0;
	for (int i=0; i<index; i++)
	{
		num /= 10;
	}
	numAtIndex = num % 10; 
	return numAtIndex;
}

int reversePos(int num)
{
	int numDig = numDigits(num);
	cout << "Number of digits: " << numDig << endl;
	int sum = 0;
	for (int i=0; i<numDig; i++)
	{
		int numAtIndex = getDigit(num, i);
		int reverseNum = numAtIndex * (pow(10, numDig-(i+1)));
		sum += reverseNum;
	}
	return sum;
}
