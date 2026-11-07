/*struct Task {
    string description; 
    Task* next;

    Task(string desc) {
        description = desc;
        next = NULL;
    }
};
void addTask(Task* &head, string desc) {
    Task* newTask = new Task(desc);

    if (head == NULL) {
        head = newTask;
        return;
    }

    Task* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTask;
}
void completeTask(Task* &head, string desc) {
    if (head == NULL) return;

    if (head->description == desc) {
        Task* temp = head;
        head = head->next;
        delete temp;
        cout << desc << " completed!\n";
        return;
    }

    Task* temp = head;
    while (temp->next != NULL && temp->next->description != desc) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Task not found.\n";
        return;
    }

    Task* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    cout << desc << " completed!\n";
}
//structure
*/