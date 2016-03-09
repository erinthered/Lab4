/*
Author: Erin Williams
Course: 136
Instructor: Ilya Korsunskiy
Assignment: Lab 5

This program takes an integer as input and outputs a table of values of all
multiples of the number between -1023 and 1023 inclusive in the first column
and the reverse of the multiple in the second column.
 */

#include <iostream>
#include <cstdlib>
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

// Precondition: null
// Postconditon: the return value is num reversed, with same sign as original num
int reverse(int num); 

// Precondition: variable n exists outside of function
// Postcondition: the value of n is the reverse of n
void reverseInPlace(int &n);

int main()
{
	// Driver program for Tasks 1 and 2 (rewritten per instructions in Task 2
	// to handle the range of multiples of n between -1023-1023 inclusive).
        // Tested on a range of values including both ends of the range, 0, and +-1
	int n;
	char ans;

	do
	{
		// Get integer input from user
		cout << "Enter an integer: ";
		cin >> n;

                // Handles special case of n=0, which causes infinite loop
		if (n==0)
		{
			cout << n << "\t" << n << endl;
		}
		else
		{
			int multiple = n;
			for (int i=-1023; i<=1023; i++)
			{
				multiple = n*i;

				if (multiple<=1023 && multiple>=-1023)  // Range between -1023 and 1023
				{
					if (n<0)
					{
						// Requirements were to print a table between -1023 to 1023, so this
                                                // lists neg multiples first for neg num, then counts up toward pos. 
						multiple = multiple * -1;  
					}
					cout << multiple << "\t" << reverse(multiple) << endl;
				}
			}
		} 
		cout << "Do you want to test again? (y/n)";
		cin >> ans;
		cout << endl;
	} while (ans == 'y' || ans == 'Y');

	// Driver program for Task 3, producing a table of multiples of the input 
	// number n, between -1023 and 1023 inclusive
        // Tested on a range of values including both ends of the range, 0, and +-1
	do
	{
		cout << "Enter an integer: ";
		cin >> n;

                // Handles special case of n=0, which causes infinite loop
		if (n==0)
		{
			cout << n << "\t" << n << endl;
		}
		else
		{
			int multiple = n;
			for (int i=-1023; i<1023; i++)  // Range between -1023 and 1023
			{
				multiple = n*i;

				if (multiple<=1023 && multiple>=-1023)
				{
					if (n<0)
					{
                                                // Requirements were to print a table between -1023 to 1023, so this
                                                // lists neg multiples first for neg num, then counts up toward pos.
						multiple = multiple * -1;
					}
              
					cout << multiple << "\t";  // Print original multiple result
					reverseInPlace(multiple);  // Reverse value of multiple
					cout << multiple << endl;  // Print reverse of multiple
				}
			}
		}
		cout << "Do you want to test again? (y/n)";
		cin >> ans;
		cout << endl;
	} while (ans == 'y' || ans == 'Y');

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
	int sum = 0;
	for (int i=0; i<numDig; i++)
	{
		int numAtIndex = getDigit(num, i);
		int reverseNum = numAtIndex * (pow(10, numDig-(i+1)));
		sum += reverseNum;
	}
	return sum;
}

int reverse(int num)
{
	int absNum = abs(num);
	int revNum = reversePos(absNum);
	if (num < 0)
	{
		revNum = revNum * (-1);
	}
	return revNum;
}

void reverseInPlace(int& n)
{
	n = reverse(n);
	return;
}
