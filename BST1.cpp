#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class Bst {
public:
    node* root;
    Bst() {
        root = nullptr;
    }

void create() {
    char ch;
    do {
        node* nn = new node;
        cout << "Enter data for node: ";
        cin >> nn->data;
        nn->left = nn->right = nullptr;

        if (root == nullptr) {
            root = nn;
        } else {
            insert(root, nn);
        }

        cout << "Do you want to add more nodes (y/n)? ";
        cin >> ch;
    } while (ch == 'y');
}

void insert(node* root, node* nn) {
    if (nn->data < root->data) {
        if (root->left == nullptr)
            root->left = nn;
        else
            insert(root->left, nn);
    } else {
        if (root->right == nullptr)
            root->right = nn;
        else
            insert(root->right, nn);
    }
}

void inorder(node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void display() {
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}
void minval(node *root) {
    node *temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    if(temp) {
        cout << "Min node: " << temp->data << endl;
    }
}
int height(node *root) {
    if(root == NULL) {
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    return (hr > hl ? hr : hl) + 1;
}
};

int main() {
    Bst bst;
    int choice;
    char ch;

    do {
        cout << "\nMENU:\n"
             << "1. Insert\n"
             << "2. Display (Inorder)\n"
             << "3. Height of Tree\n"
             << "4. Find Min\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bst.create();
                break;
            case 2:
                bst.display();
                break;
            case 3:
                cout << "Height of the BST is: " << bst.height(bst.root) << endl;
                break;
            case 4:
            bst.minval(bst.root);
            break;
            default:
                cout << "Invalid choice.\n";
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
