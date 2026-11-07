/*struct Node {
    string action;
    Node* next;

    Node(string a) {
        action = a;
        next = NULL;
    }
};

void push(Node* &head, string action) {
    Node* n = new Node(action);
    n->next = head;
    head = n;
}

string pop(Node* &head) {
    if (!head) return "";
    string action = head->action;
    Node* temp = head;
    head = head->next;
    delete temp;
    return action;
}
//just structure
*/