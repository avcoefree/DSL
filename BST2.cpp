#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
class BST{
    public:
    node* root;
    BST(){
        root=NULL;
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
    void insert(node *root ,node *nn){
        if(nn->data < root->data){
            if(root->left==NULL){
                root->left = nn;
            }
            else{
                insert(root->left,nn);
            }
        }
        else{
            if(root->right==NULL){
                root->right = nn;
            }
            else{
                insert(root->right,nn);
            }
        }
    }
    void inorder(node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void display(){
        cout<<"inorder :";
        inorder(root);
        cout<<endl;
    }
    bool search(node* root, int key) {
        node* temp = root;
        while (temp != nullptr) {
            if (key == temp->data)
                return true;
            else if (key < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }
    void mirror(node* root) {
        if (root == nullptr)
            return;
        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
};
int main(){
    BST bst;
    int choice;
    char ch;

    do {
        cout << "\nMENU:\n"
             << "1. Insert\n"
             << "2. Display (Inorder, Preorder, Postorder)\n"
             << "3. Search a Node\n"
             << "4. Mirror the Tree\n"
            
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bst.create();
                break;
            case 2:
                bst.display();
                break;
            case 3: {
                int key;
                cout << "Enter the node to search: ";
                cin >> key;
                if (bst.search(bst.root, key))
                    cout << "Node found.\n";
                else
                    cout << "Node not found.\n";
                break;
            }
            case 4:
                bst.mirror(bst.root);
                cout << "Tree mirrored successfully.\n";
                break;
            
            default:
                cout << "Invalid choice.\n";
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
