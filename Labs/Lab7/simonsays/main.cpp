/*
Kattis - Simon Says

Updated By: Dawson Pease

Problem Statement: https://open.kattis.com/problems/simonsays 
Algorithm steps:
1. Read N
2. Loop N times:
  i. Read a line
  ii. If the line starts with "Simon says",
    print the rest of the string. Note: print the leading space after says as well!
  iii. Otherwise, skip the line
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test") {
        testAnswer();
    } else {
        solve();
    }
}

string answer(const string &line)   {
    if (line.find("Simon says ") == 0) {
        return line.substr(11);
    } else {
        return "";
    }
}

void testAnswer() {
    string ans = answer("Simon says jump!");
    cerr << "ans = " << ans << endl;
    assert(ans == " jump!");

    assert(answer("Write more programs.") == "");
    assert(answer("Simon says sing a song!") == " sing a song!");

    cerr << "All test cases passed!\n";
}

void solve() {
    string line;
    int N;
    cin >> N;
    cin.ignore(); // Discard remaining newline character

    while (N--) {
        getline(cin, line);
        string ans = answer(line);
        if (!ans.empty()) {
            cout << ans << endl;
        }
    }
}