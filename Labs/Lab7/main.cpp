/*
Kattis - Hissing Microphone Problem

Updated By: Dawson Pease
Date: 11/13/24

Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read a string
2. Search for "ss" substring in the string
    i. if found, print "hiss"
    ii. otherwise, print "no hiss"
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
  if (argc == 2 && string(argv[1]) == "test") {
    testAnswer();
  } else {
    solve();
  }
}

string answer(const string &line) {
  // Find the position of the first occurrence of "ss"
  size_t found = line.find("ss");
  if (found != string::npos) {
    return "hiss";
  } else {
    return "no hiss";
  }
}

// Unit testing answer()
void testAnswer() {
  assert(answer("this is a test") == "no hiss");
  assert(answer("this is a hissing test") == "hiss");
  cerr << "All test cases passed!\n";
}

// Solving the problem for Kattis
void solve() {
  string line;
  getline(cin, line);
  cout << answer(line) << endl;
}