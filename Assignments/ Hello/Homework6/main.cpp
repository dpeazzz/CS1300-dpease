/*
Assignment: Kattis problem "line up"
Author: Dawson Pease
Date: 11/12/24

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    bool increasing = false, decreasing = false;

    for (int i = 1; i < n; ++i) {
        if (names[i] > names[i - 1]) {
            increasing = true;
        } else if (names[i] < names[i - 1]) {
            decreasing = true;
        }

        if (increasing && decreasing) {
            break;
        }
    }

    if (increasing && !decreasing) {
        cout << "INCREASING" << endl;
    } else if (!increasing && decreasing) {
        cout << "DECREASING" << endl;
    } else {
        cout << "NEITHER" << endl;
    }

    return 0;
}