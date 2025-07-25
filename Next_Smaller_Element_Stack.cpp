#include <bits/stdc++.h>
using namespace std;

// ✅ Previous Smaller Element
vector<int> previousSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1); // Sentinel for no smaller element
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int curr = arr[i];

        // Pop all >= curr
        while (s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();  // Top is the previous smaller
        s.push(curr);
    }
    return ans;
}

// ✅ Next Smaller Element
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1); // Sentinel
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        // Pop all >= curr
        while (s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();  // Top is the next smaller
        s.push(curr);
    }
    return ans;
}

// ✅ Previous Greater Element
vector<int> previousGreaterElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1); // Sentinel for no greater element
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int curr = arr[i];

        // Pop all <= curr
        while (s.top() <= curr) {
            s.pop();
        }

        ans[i] = s.top();  // Top is the previous greater
        s.push(curr);
    }
    return ans;
}

// ✅ Next Greater Element
vector<int> nextGreaterElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1); // Sentinel for no greater element
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        // Pop all <= curr
        while (s.top() <= curr) {
            s.pop();
        }

        ans[i] = s.top();  // Top is the next greater
        s.push(curr);
    }
    return ans;
}

// ✅ Utility function to print a vector
void printVector(const vector<int> &v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {4, 2, 5, 1, 3};
    int n = arr.size();

    cout << "Array: ";
    printVector(arr);

    vector<int> prevSmall = previousSmallerElement(arr, n);
    vector<int> nextSmall = nextSmallerElement(arr, n);
    vector<int> prevGreat = previousGreaterElement(arr, n);
    vector<int> nextGreat = nextGreaterElement(arr, n);

    cout << "\nPrevious Smaller: ";
    printVector(prevSmall);

    cout << "Next Smaller: ";
    printVector(nextSmall);

    cout << "Previous Greater: ";
    printVector(prevGreat);

    cout << "Next Greater: ";
    printVector(nextGreat);

    return 0;
}
