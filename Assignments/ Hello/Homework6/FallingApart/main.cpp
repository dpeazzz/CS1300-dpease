/*
Assingment: Kattis Problem "Falling Apart"
Author: Dawson pease
Date: 11/12/24

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pieces(n);
    for (int i = 0; i < n; ++i) {
        cin >> pieces[i];
    }

    
    sort(pieces.rbegin(), pieces.rend()); 

    int alice = 0, bob = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            alice += pieces[i];
        } else {
            bob += pieces[i];
        }
    }

    cout << alice << " " << bob << endl;

    return 0;
}

