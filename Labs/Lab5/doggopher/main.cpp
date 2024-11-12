/*
Kattis - Dog & Gopher
Loop Lab
Updated By: Dawson Pease
CSCI 111
Date: 11/12/24

Read and solve the Kattis problem: https://open.kattis.com/problems/doggopher 

Algorithm Steps:
		1. Read gopher and dog's coordinates
		2. Define a function to find and return the Euclidean distance between the two points
    3. For each gopher hole coordinate:
      3.a find the distance between the gopher position and the hole
      3.b find the distance between the dog position and the hole
      4.c if the dog's distance is larger or equal to twice the distance of gopher, 
          gopher can get away through that hole. 
          4.c.1 Stop testing other holes.
    4. If no safe hole is found, the gopher cannot escape.
*/

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

// Function prototypes
float distance(const float x1, const float y1, const float x2, const float y2);
void testDistance();

#define TOLERANCE 1e-6 // 10^-6 or 0.000001

int main(int argc, char* argv[]) {
  if (argc == 2 && string(argv[1]) == string("test")) {
    testDistance();
  } else {
    float gopherX, gopherY, dogX, dogY;
    string answer = "The gopher cannot escape.";

    cin >> gopherX >> gopherY >> dogX >> dogY;

    float x, y;
    while (cin >> x >> y) {
      float gopher_dist = distance(gopherX, gopherY, x, y);
      float dog_dist = distance(dogX, dogY, x, y);

      if (dog_dist >= 2 * gopher_dist) {
        ostringstream oss;
        oss << fixed << showpoint << setprecision(3);
        oss << "The gopher can escape through the hole at (" << x << "," << y << ").";
        answer = oss.str();
        break;
      }
    }
    cout << answer << endl;
  }
  return 0;
}

// Function implementation
float distance(const float x1, const float y1, const float x2, const float y2) {
  float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  return d;
}

// Function to test distance function
void testDistance() {
  float x1, y1, x2, y2, answer, expected;

  // Test case 1
  x1 = 1.000f;
  y1 = 1.000f;
  x2 = 2.000f;
  y2 = 2.000f;
  answer = distance(x1, y1, x2, y2);
  expected = 1.4142135623731;
  cout << fixed << showpoint << setprecision(3) << endl;
  cout << answer << " " << expected << endl;
  assert(abs(answer - expected) < TOLERANCE);

  // Test case 2
  x1 = 0.0f;
  y1 = 0.0f;
  x2 = 3.0f;
  y2 = 4.0f;
  answer = distance(x1, y1, x2, y2);
  expected = 5.0f;
  cout << answer << " " << expected << endl;
  assert(abs(answer - expected) < TOLERANCE);

  // Test case 3
  x1 = -2.0f;
  y1 = 1.0f;
  x2 = 1.0f;
  y2 = -1.0f;
  answer = distance(x1, y1, x2, y2);
  expected = 3.0f;
  cout << answer << " " << expected << endl;
  assert(abs(answer - expected) < TOLERANCE);

  // Test case 4
  x1 = 5.0f;
  y1 = 5.0f;
  x2 = 5.0f;
  y2 = 0.0f;
  answer = distance(x1, y1, x2, y2);
  expected = 5.0f;
  cout << answer << " " << expected << endl;
  assert(abs(answer - expected) < TOLERANCE);

  cerr << "All test cases passed!\n";
}
