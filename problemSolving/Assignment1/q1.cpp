#include <iostream>
using namespace std;

void subsets(int nums[], int n, int index, int subset[], int subSize) {
    if (index == n) {
        cout << "[ ";
        for (int i = 0; i < subSize; i++)
            cout << subset[i] << " ";
        cout << "]" << endl;
        return;
    }

    subsets(nums, n, index + 1, subset, subSize);

    subset[subSize] = nums[index];
    subsets(nums, n, index + 1, subset, subSize + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int nums[20];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int subset[20];

    cout << "\nAll subsets:\n";
    subsets(nums, n, 0, subset, 0);

    return 0;
}
