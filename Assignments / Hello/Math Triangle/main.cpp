/*
  Triangle Math program
  Author: Dawson Pease
  Date: Aug-26-2024
 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
  //declares all the variable to be used in the program
  double sside, lside, rside, perimeter, sperimeter, area;

  //promts the user to input the smallest side length
  cout << "Please input the smallest side length of the triangle: ";
  cin >> sside;

  //promts user to input another side
  cout << "Please input the largest side length of the triangle: ";
  cin >> lside;

  //and another
  cout << "Please input the remaining side length of the triangle: ";
  cin >> rside;

  //if statement determines if the triangle is valid
  if (lside < sside + rside){
    //if the triangle is valid the perimeter and area (according to Herons Formula) are calculated
    perimeter = sside + lside + rside;
    sperimeter = perimeter / 2;
    area = sqrt(sperimeter*(sperimeter-sside)*(sperimeter-lside)*(sperimeter-rside));
    cout << "Here are youre results: " << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
  }
  else {
    //if th triangle is invalid the apropriate following response is outputed
    cout << "You have entered lengths of an invalid triangle (does not exist). Please run the program again with valid lengths" << endl;
  }
}