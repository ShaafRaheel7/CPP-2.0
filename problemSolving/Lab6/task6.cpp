#include <iostream>
using namespace std;

#define n 100

class stack {
    public:
    int arr[n];
    int top;

public:
    stack() {
        top = -1;
    }

    void push(char x) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << arr[top] << " popped" << endl;
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void quickSort(int ar[], int low, int high) {
    int i = low, j = high;
    //int pivot = arr[(low + high) / 2];
    int pivot = arr[low];
    while (i <= j) {
        while (arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
            j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--; }
        }
        
    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}

};

int main() {
 stack st;
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
