#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // Sort the numbers using the built-in sort function
    int nums[] = {a, b};
    sort(nums, nums + 2);

    // Print the sorted numbers
    cout << nums[0] << " " << nums[1] << endl;

    return 0;
}