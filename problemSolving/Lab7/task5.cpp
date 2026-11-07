#include <iostream>
using namespace std;

struct Order {
    int id;
    int time;
};

Order pq[50];
int orderCount = 0;

void addOrder() {
    int id, time;
    cout << "Enter Order ID: ";
    cin >> id;
    cout << "Enter Delivery Time: ";
    cin >> time;

    int i = orderCount;
    pq[i] = {id, time};
    orderCount++;

    while (i > 0 && pq[i].time < pq[i - 1].time) {
        swap(pq[i], pq[i - 1]);
        i--;
    }
}

void processOrder() {
    if (orderCount == 0) {
        cout << "No Orders\n";
        return;
    }

    cout << "Processing Order ID: " << pq[0].id << endl;

    for (int i = 0; i < orderCount - 1; i++)
        pq[i] = pq[i + 1];

    orderCount--;
}

void displayOrders() {
    if (orderCount == 0) {
        cout << "Queue Empty\n";
        return;
    }

    for (int i = 0; i < orderCount; i++)
        cout << "Order " << pq[i].id << " | Time " << pq[i].time << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- Food Delivery System ---\n";
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addOrder(); break;
            case 2: processOrder(); break;
            case 3: displayOrders(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 4);

    return 0;
}
