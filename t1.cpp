#include <iostream>
using namespace std;

class Node {
public:
    int pid;
    int execTime;
    int remTime;
    Node* next;
    bool completed;

    Node(int pid, int execTime) {
        this->pid = pid;
        this->execTime = execTime;
        this->remTime = execTime;
        this->next = next;
        this->completed = false;
    }
};

class circularLinkedList {
public:
    Node* head;
    Node* tail;

    circularLinkedList(int pid, int execTime) {
        Node* newNode = new Node(pid, execTime);
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }

    void append(int pid, int execTime) {
        if (!head) {
            Node* newNode = new Node(pid, execTime);
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            Node* newNode = new Node(pid, execTime);
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void removeNode(Node* node) {
        if (!head) return;
        if (head == node && head->next == head) {
            head = nullptr;
            tail = nullptr;
            delete node;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp == node) {
                if (prev) {
                    prev->next = temp->next;
                }
                if (temp == head) {
                    head = head->next;
                    tail->next = head;
                }
                if (temp == tail) {
                    tail = prev;
                    tail->next = head;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            if(temp->remTime != 0) {
               cout << "\t[pID: " << temp->pid << " execTime: " << temp->execTime << " remTime: " << temp->remTime<<"]"<<endl;
            }

            if (temp->remTime == 0 && !temp->completed) {
                cout << "\t[pID: " << temp->pid << " is completed]" << endl;
                temp->completed = true;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void scheduler(int quantum) {
        if (!head) return;

        Node* current = head;
        do {
            if (current->remTime > 0) {
                if (current->remTime > quantum) {
                    current->remTime -= quantum;
//                    cout << "pID " << current->pid << " running for " << quantum << " seconds" << endl;
                } else {
//                    cout << "pID " << current->pid << " running for " << current->remTime << " seconds" << endl;
                    current->remTime = 0;
                }
            }
            current = current->next;
        } while (current != head);
    }

    bool ifAllRemainingsAreZero() {
        if (!head) return true;

        Node* temp = head;
        do {
            if (temp->remTime != 0) {
                return false;
            }
            temp = temp->next;
        } while (temp != head);
        return true;
    }
};

int main() {
    int quantum = 3;
    int i;
    circularLinkedList* cll = new circularLinkedList(1, 10);
    cll->append(2, 5);
    cll->append(3, 8);
    cll->append(4, 6);
    cout << "Initial State of the Processes" << endl;
    cll->display();
    for (i = 0; i < 5; i++) {
        cout << "\nCycle " << i + 1 << ": " << endl;
        cll->scheduler(quantum);
        cll->display();
        if (cll->ifAllRemainingsAreZero()) {
            cout << "All Processes are completed" << endl;
            break;
        }
    }
    cout << "\nNew process arrives: P5 (Remaining: 9)" << endl;
    cll->append(5, 9);
    for (i = 5; i < 10; i++) {
        cout << "\nCycle " << i + 1 << ": " << endl;
        cll->scheduler(quantum);
        cll->display();
        if (cll->ifAllRemainingsAreZero()) {
            cout << "\nAll Processes are completed" << endl;
            break;
        }
    }

    return 0;
}
