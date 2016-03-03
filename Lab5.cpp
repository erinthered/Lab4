/*
Author: Erin Williams
Course: 136
Instructor: Ilya Korsunskiy
Assignment: Lab 5

This program ...
*/

#include <iostream>
#include <math>
using namespace std;

// Precondition: num > 0
// Postcondition: the return value is num read backwards (in decimal)
int reversePos(int num);

int numDigits(int num);            // return the number of digits in num

int getDigit(int num, int index);  // return the index'th digit of num

int main()
{
cout << "Enter a positive number: ";
cin >> num;

cout << reversePos(num);

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
    for (i=0; i<numDig; i++)
    {
       int numAtIndex = getDigit(num, i)
       int reverseNum = numAtIndex * (pow(10, numDig-i))
       sum += reverseNum;
    }
    return sum;
}
