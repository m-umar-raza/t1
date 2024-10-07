#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Node {
public:
    uint64_t data;
    Node* next;

    Node(uint64_t data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        clear();
    }

    void append(uint64_t data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Appended node with value: " << data << endl;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    void concatenateToString(string& number) {
        number.clear();
        Node* current = head;
        while (current) {
            number += to_string(current->data);
            current = current->next;
        }
        cout << "Concatenated number: " << number << endl;
    }
};

int main() {
    LinkedList list;

    cout << "Enter a 1024-bit or small number: ";
    string userInput;
    cin >> userInput;

    for (size_t i = 0; i < userInput.size(); i += 19) {
        string segmentStr = userInput.substr(i, 19);
        uint64_t segment = stoull(segmentStr);
        list.append(segment);
    }

    string completeNumberStr;
    list.concatenateToString(completeNumberStr);

    bool isPrime = true;
    uint64_t completeNumber = stoull(completeNumberStr.substr(0, 19));
    if (completeNumber < 2) isPrime = false;
    for (uint64_t i = 2; i * i <= completeNumber; ++i) {
        if (completeNumber % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        cout << completeNumber << " is probably prime." << endl;
    } else {
        cout << completeNumber << " is definitely not prime." << endl;
    }

    list.clear();
    return 0;
}

