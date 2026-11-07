#include <iostream>
using namespace std;

#define n 100

class Stack {
public:
    int arr[n];
    int top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return;
        }
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // QuickSort
    void quickSort(int a[], int low, int high) {
        int i = low, j = high;
        int pivot = a[(low + high) / 2];

        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;

            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }

        if (low < j) quickSort(a, low, j);
        if (i < high) quickSort(a, i, high);
    }
};

int main() {
    Stack st;
    int v;

    cout << "Enter number of values to push: ";
    cin >> v;

    cout << "Enter Stack Elements:\n";
    for (int i = 0; i < v; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Stack before sorting: ";
    st.display();

    st.quickSort(st.arr, 0, st.top);

    cout << "Stack after sorting (ascending): ";
    st.display();

    return 0;
}
