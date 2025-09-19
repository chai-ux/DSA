#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargest(vector<int> arr) {
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        if (num > first) {
            second = first;
            first = num;
        } 
        else if (num > second && num < first) {
            second = num;
        }
    }

    if (second == INT_MIN) {
        return -1; // means no second largest
    } else {
        return second;
    }
}

int main() {
    vector<int> arr = {2, 4, 8, 1, 6, 3};
    cout << "Second Largest Element: " << secondLargest(arr);
    return 0;
}
