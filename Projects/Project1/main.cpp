/*
  Author: Dawson Pease
    Date 10/7/2024
    Projectile Motion 
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cassert>
using namespace std;
const double g = 9.81;
int main() {

    double velocity, Angle, height, distance, time, target;
    char velocityUnit, angleUnit, targetUnit;

    cout << "Enter initial velocity (m/s(m) or ft/s(f)): ";
    cin >> velocity >> velocityUnit;
    cout << "Enter launch angle (Rad or Deg(d))(between 0 and 90 Deg): ";
    cin >> Angle >> angleUnit;
    cout << "Enter target distance (m or f): "; 
    cin >> target >> targetUnit;


    if (velocityUnit == 'f') {
        velocity *= 0.3048;
    }
    if (angleUnit == 'd') {
        Angle = Angle * M_PI / 180.0;
    }
    if (targetUnit == 'f') {
        target *= 0.3048;
    }

    time = 2 * velocity * sin(Angle) / g;
    distance = (velocity * velocity) * sin(2 * Angle) / 2 * g;
    height = (velocity * velocity) * (sin(Angle) * sin(Angle)) / 2 * g;

    if (target <= distance) {
        cout << " Target is within range" << endl;
    }

    if (target > distance) {
        cout << "Target is out of range" << endl;
    }

    cout << "Time: " << time << "s " << endl;
    cout << "Max height: " << height << "m  " << (height / 0.3048) << " ft" << endl;
    cout << "distance in X-direction: " << distance << " m  " << (distance / 0.3048) << "ft" << endl;

    return 0; 
}