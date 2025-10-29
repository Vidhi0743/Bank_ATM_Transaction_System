#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int accountNumber;
    double balance;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(string name, int accNo, double bal) {
        Node* temp = new Node{name, accNo, bal, nullptr};
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "No customers in queue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        cout << "Customer " << temp->name << " served and removed from queue.\n";
        delete temp;
    }

    void display() {
        Node* temp = front;
        cout << "\n--- Current Queue ---\n";
        while (temp != nullptr) {
            cout << "Name: " << temp->name
                 << " | Acc No: " << temp->accountNumber
                 << " | Balance: " << temp->balance << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Queue atmQueue;
    int choice;
    do {
        cout << "\n=== BANK ATM TRANSACTION SYSTEM ===";
        cout << "\n1. Add Customer (Enqueue)";
        cout << "\n2. Serve Customer (Dequeue)";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int acc;
            double bal;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Account Number: ";
            cin >> acc;
            cout << "Enter Balance: ";
            cin >> bal;
            atmQueue.enqueue(name, acc, bal);
        }
        else if (choice == 2) {
            atmQueue.dequeue();
        }
        else if (choice == 3) {
            atmQueue.display();
        }

    } while (choice != 4);

    cout << "\nExiting system. Thank you!\n";
    return 0;
}
