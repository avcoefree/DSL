#include <iostream>
using namespace std;
#define MAX 10
struct Node {
    long int data;
    Node* next;
    Node(long int val) {
        data = val;
        next = nullptr;
    }
};
class Hash {
    Node* table[MAX];
    int comparisons[MAX];
public:
    Hash() {
        for (int i = 0; i < MAX; i++) {
            table[i] = nullptr;
            comparisons[i] = 0;
        }
    }
    int hashFun(long int num) {
        return num % MAX;
    }
    void insert() {
        long int num;
        cout << "Enter the number: ";
        cin >> num;
        int index = hashFun(num);
        int comp = 1;
        Node* newNode = new Node(num);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
                comp++;
            }
            temp->next = newNode;
            comp++; 
        }
        comparisons[index] += comp;
        cout << "Number " << num << " inserted with " << comp << " comparisons." << endl;
    }
    void display() {
        for (int i = 0; i < MAX; i++) {
            cout << i << " ------> ";
            Node* temp = table[i];
            if (!temp) {
                cout << "NULL";
            } else {
                while (temp) {
                    cout << temp->data;
                    if (temp->next) cout << " -> ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
    void displayComparisons() {
        int totalComparisons = 0;
        cout << "\nComparisons for each key:" << endl;

        for (int i = 0; i < MAX; i++) {
            Node* temp = table[i];
            while (temp) {
                cout << "Key " << temp->data << " required " << comparisons[i] << " comparisons (bucket " << i << ")." << endl;
                totalComparisons += comparisons[i];
                temp = temp->next;
            }
        }
        cout << "Total comparisons: " << totalComparisons << endl;
    }
};
int main() {
    int choice;
    Hash h;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Display Comparisons\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.displayComparisons();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
