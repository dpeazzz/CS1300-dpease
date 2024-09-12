/*
Library Functions Lab
Updated By: Dawson Pease
CSCI 111
Date: 9/11/24

Program prompts user to enter a decimal number. It then finds various trig and mathematical values 
of the number using library functions and prints the results using cstdio's printf function.

Algorithm:
    1. Prompt user to enter a decmial number
    2. Store the number into a variable
    3. Find and print various results form the number
*/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath> // various math functions: https://cplusplus.com/reference/cmath
using namespace std;

int main()
{
    double number, result;

    cout << "Program calculates various results from a given number" << endl;
    cout << "Enter a decimal number: ";
    cin >> number;
    // Find ceiling of the number
    result = ceil(number);
    printf("ceiling(%f) = %.1f\n", number, result);
    // Find floor of the number
    result = floor(number);
    printf("Floor(%f) = %.1f\n", number, result);
    //FIXMEd - Using library function, find and print the square root of the number upto 2 decimal points
    result = sqrt(number);
    printf("sqrt(%f) = %.1f/n", number, result);
    //FIXME4 - Using library function, find and print the cube root of the number upto 2 decimal points
    result = cbrt(number);
    printf("cbrt(%f) = %.2f/n", number, result);
    //FIXMEd - Using library function, find and print the 10th power of the number upto 2 decimal points
    result = pow(number, 10);
    printf("pow(%f) = %.2f/n", number, result);
    //FIXMEd - Using library function, find and print the log_2 of the number upto 2 decimal points
    result = log2(number);
    printf("log2(%f) = %.2f/n", number, result);
    //FIXME7 - Using library function, find and print the log_10 of the number upto 2 decimal points
    result = log10(number);
    printf("log10(%f) = %.2f/n", number, result);
    //FIXME8 - Convert number into radians and store into a variable
    result = M_PI*((number)/180);
    printf("M_PI*/180(%f) = %.2f/n", number, result);
    //FIXME9 - Using library function, find and print the sine of the radian value in FIXME 8 upto 2 decimal points
    result = sin(M_PI*((number)/180));
    printf("sin(M_PI*/180(%f) = %.2f/n", number, result);
    //FIXME10 - Using library function, find and print the cosine of the radian value in FIXME 8 upto 2 decimal points
    result = cos(M_PI*((number)/180));
    printf("cos(M_PI*/180(%f) = %.2f/n", number, result);

    cin.ignore(1000, '\n');
    cout << "Enter to quit the program: ";
    cin.get();
    cout << "Good bye..." << endl;
    return 0;
}