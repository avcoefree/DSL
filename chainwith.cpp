#include <iostream>
#include <cstring>
#define max 10
using namespace std;
struct node {
    char name[15];
    long int mobno;
    int chain;
    node() {
        strcpy(name, "-");
        mobno = 0;
        chain = -1;
    }
};
class hasht {
    node ht[max];
public:
    int hashfun(long int num) {
        return (num % max);
    }
    void insert() {
        node S;
        cout << "Enter name and mobile number of a person:\n";
        cin >> S.name >> S.mobno;
        int home = hashfun(S.mobno);
        if (ht[home].mobno == 0) {
            ht[home] = S;
            return;
        }
        int existingHome = hashfun(ht[home].mobno);
        if (existingHome == home) {
            int i = (home + 1) % max;
            while (ht[i].mobno != 0 && i != home)
                i = (i + 1) % max;
            if (ht[i].mobno == 0) {
                ht[i] = S;
                int last = home;
                while (ht[last].chain != -1)
                    last = ht[last].chain;
                ht[last].chain = i;
            } else {
                cout << "Hash table is full\n";
            }
        } else {
            node tempNode = ht[home];
            int tempChain = ht[home].chain;
            int tempHome = hashfun(tempNode.mobno);
            ht[home] = S;
            ht[home].chain = -1;
            int i = (home + 1) % max;
            while (ht[i].mobno != 0 && i != home)
                i = (i + 1) % max;
            if (ht[i].mobno == 0) {
                ht[i] = tempNode;
                ht[i].chain = tempChain;
                int j = tempHome;
                while (ht[j].chain != home && j != home)
                    j = ht[j].chain;

                if (j != home)
                    ht[j].chain = i;
            } else {
                cout << "Hash table is full\n";
            }
        }
    }
    void display() {
        cout << "Index\tName\t\tMobile Number\tChain\n";
        for (int i = 0; i < max; i++) {
            cout << i << "\t" << ht[i].name << "\t\t" << ht[i].mobno << "\t\t" << ht[i].chain << endl;
        }
    }
    void search() {
        long int num;
        cout << "Enter the mobile number to search: ";
        cin >> num;
        int ind = hashfun(num);
        while (ind != -1) {
            if (ht[ind].mobno == num) {
                cout << "Mobile number found at index: " << ind << endl;
                return;
            }
            ind = ht[ind].chain;
        }
        cout << "Mobile number not found.\n";
    }

    void del() {
        long int num;
        cout << "Enter mobile number to delete: ";
        cin >> num;
        int index = hashfun(num);
        int prev = -1, curr = index;

        while (curr != -1 && ht[curr].mobno != 0) {
            if (ht[curr].mobno == num) {
                if (prev != -1)
                    ht[prev].chain = ht[curr].chain;

                strcpy(ht[curr].name, "-");
                ht[curr].mobno = 0;
                ht[curr].chain = -1;

                cout << "Record deleted successfully.\n";
                return;
            }
            prev = curr;
            curr = ht[curr].chain;
        }
        cout << "Record not found.\n";
    }
};

int main() {
    int cho;
    hasht h;
    char cont = 'y';
    do {
        cout << "\n1. Insert \n2. Display\n3. Search\n4. Delete\n5. Exit\nEnter your choice: ";
        cin >> cho;
        switch (cho) {
            case 1: h.insert(); break;
            case 2: h.display(); break;
            case 3: h.search(); break;
            case 4: h.del(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice\n"; break;
        }
       cout<<"do yo want to continue (y/n):";
       cin>>cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
