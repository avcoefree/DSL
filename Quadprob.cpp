#include<iostream>
#define MAX 10
using namespace std;

class Hash {
    long int arr[MAX];
    int comparisons[MAX]; 

public:
    Hash() {
        for (int i = 0; i < MAX; i++) {
            arr[i] = 0;
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
        int i = 0, comp = 1;

        if (arr[index] == 0) {
            arr[index] = num;
            comparisons[index] = comp;
            return;
        }

        
        while (arr[(index + i * i) % MAX] != 0) {
            comp++;
            i++;
            if (i == MAX) {
                cout << "Hash table is full" << endl;
                return;
            }
        }

        arr[(index + i * i) % MAX] = num;
        comparisons[(index + i * i) % MAX] = comp; 
    }

    void displayComparisons() {
        int totalComparisons = 0;
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != 0) {
                cout << "Key " << arr[i] << " required " << comparisons[i] << " comparisons." << endl;
                totalComparisons += comparisons[i];
            }
        }
        cout << "Total comparisons for all keys: " << totalComparisons << endl;
    }

    void display() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i] == 0)
                cout << i << " ------> NULL" << endl;
            else
                cout << i << " ------> " << arr[i] << endl;
        }
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













