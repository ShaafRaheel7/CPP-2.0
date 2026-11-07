#include <iostream>
#include <string>
using namespace std;

struct EmployeeNode {
    int id;
    string name;
    double salary;
    EmployeeNode *subordinate, *peer;

    EmployeeNode(int i, string n, double s) {
        id = i; name = n; salary = s;
        subordinate = peer = nullptr;
    }
};

// Post-order
double totalBudget(EmployeeNode* root) {
    if (!root) return 0;
    return root->salary + totalBudget(root->subordinate) + totalBudget(root->peer);
}

// Find reporting chain
bool printReportingChain(EmployeeNode* root, string target) {
    if (!root) return false;
    if (root->name == target || printReportingChain(root->subordinate, target)) {
        cout << root->name << " <- ";
        return true;
    }
    return printReportingChain(root->peer, target);
}

int main() {
    EmployeeNode* ceo = new EmployeeNode(1, "CEO Alice", 200000);
    ceo->subordinate = new EmployeeNode(2, "Dept Head Bob", 120000);
    ceo->subordinate->subordinate = new EmployeeNode(3, "Manager Eve", 80000);
    ceo->subordinate->peer = new EmployeeNode(4, "Dept Head Charlie", 115000);

    cout << "Total Company Salary Budget: $" << totalBudget(ceo) << endl;
    
    cout << "Reporting Chain for Manager Eve: ";
    printReportingChain(ceo, "Manager Eve");
    cout << "END" << endl;

    return 0;
}