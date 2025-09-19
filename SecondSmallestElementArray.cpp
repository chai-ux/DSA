#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondSmallest(vector<int> arr) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        if (num < first) {
            second = first;
            first = num;
        } 
        else if (num < second && num > first) {
            second = num;
        }
    }

    if (second == INT_MAX) {
        return -1; // means no second largest
    } else {
        return second;
    }
}

int main() {
    vector<int> arr = {2, 4, 8, 1, 6, 3};
    cout << "Second Smallest Element: " << secondSmallest(arr);
    return 0;
}
