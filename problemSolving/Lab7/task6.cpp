#include <iostream>
using namespace std;

string steps[5];
int currentStep = 0;

void enterData() {
    cout << "Enter data for Step " << currentStep + 1 << ": ";
    cin.ignore();
    getline(cin, steps[currentStep]);
}

void nextStep() {
    if (currentStep < 4)
        currentStep++;
    else
        cout << "Last Step Reached\n";
}

void prevStep() {
    if (currentStep > 0)
        currentStep--;
    else
        cout << "First Step\n";
}

void showData() {
    cout << "Step " << currentStep + 1 << " Data: " << steps[currentStep] << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Form Wizard ---\n";
        cout << "1. Enter Data\n";
        cout << "2. Next Step\n";
        cout << "3. Previous Step\n";
        cout << "4. Show Current Step Data\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enterData(); break;
            case 2: nextStep(); break;
            case 3: prevStep(); break;
            case 4: showData(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 5);

    return 0;
}
