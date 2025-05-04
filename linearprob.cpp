#include <iostream>
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
        int start = index;
        int comp = 1; 
        if (arr[index] == 0) {
            arr[index] = num;
            comparisons[index] = comp;
            cout << "Number " << num << " inserted with " << comp << " comparisons." << endl;
            return;
        }
        while (arr[index] != 0) {
            index = (index + 1) % MAX;
            comp++;
            if (index == start) {
                cout << "Hash table is full. Unable to insert " << num << endl;
                return;
            }
        }
        arr[index] = num;
        comparisons[index] = comp; 
        cout << "Number " << num << " inserted with " << comp << " comparisons." << endl;
    }
    void display() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i] == 0)
                cout << i << " ------> NULL" << endl;
            else
                cout << i << " ------> " << arr[i] << endl;
        }
    }
    void displayComparisons() {
        int totalComparisons = 0;

        cout << "\nComparisons for each key:" << endl;
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != 0) {
                cout << "Key " << arr[i] << " required " << comparisons[i] << " comparisons." << endl;
                totalComparisons += comparisons[i];
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


