#include <iostream>
#include <string.h>
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
    int ind, prev;
    node S;
    cout << "Enter name and mobile number of a person:" << endl;
    cin >> S.name >> S.mobno;
    ind = hashfun(S.mobno);
    if (ht[ind].mobno == 0) {
        ht[ind] = S;
    } else {
        prev = ind;
        while (ht[ind].mobno != 0) {
            ind = (ind + 1) % max;  
        }
        ht[ind] = S;
        ht[prev].chain = ind;    
    }
}
void display() {
    cout << "Index\tName\t\tMobile Number\tChain" << endl;
    for (int i = 0; i < max; i++) {
        cout << i << "\t" << ht[i].name << "\t\t" << ht[i].mobno << "\t\t" << ht[i].chain << endl;
    }
}
void search(){
    long int num;
    int ind;
    cout<<"enter the no. which you want to be search:";
    cin>>num;
    ind=hashfun(num);
    while(ind != -1){
        if(num==ht[ind].mobno){
            cout<<"mobile no. is present at index: "<<num<<endl;
            return ;
        }
        ind=ht[ind].chain;
    }
}void del() {
        long int num;
        cout << "Which mobile number do you want to delete (without replacement): ";
        cin >> num;
        int index = hashfun(num);
        int prev = -1;
        int curr = index;
        while (curr != -1 && ht[curr].mobno != 0) {
            if (ht[curr].mobno == num) {
                if (prev != -1) {
                    ht[prev].chain = ht[curr].chain;
                }
                strcpy(ht[curr].name, "-");
                ht[curr].mobno = 0;
                ht[curr].chain = -1;
                cout << "Record deleted successfully (without replacement).\n";
                return;
            }
            prev = curr;
            curr = ht[curr].chain;
        }
        cout << "Record not found.\n";
    }
};
int main(){
    int cho;
    hasht h;
    char a,y,Y;
    do{
        cout<<"1.insert \n2.display\n3.search\n4.delete\n5.exit\nenter the choice: ";
        cin>>cho;
        switch(cho){
            case 1:
              h.insert();
              break;
            case 2:
               h.display();
               break;
            case 3:
               h.search();
               break;
            case 4:
               h.del();
               break;
            case 5:
              cout<<"exit"<<endl;
              break;
            default :
               cout<<"invalid  choice"<<endl;
                break;
        }
    }while(a ='y');
     return 0 ;
}
