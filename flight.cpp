#include<iostream>
#include<string>
using namespace std;
class flight{
public:
int n,i,j,m[10][10];
char ch;
string v[20];
void getgraph(){
    cout<<"enter number of cities(max.20)";
    cin>>n;
    cout<<"enter name of city :";
    for (i=0;i<n;i++){
        cin>>v[i];
    }
    for(i=0;i<n;i++){
        for (j=0;j<n;j++){
            cout<<"if path is present between "<<v[i]<<" and "<<v[j]<<" enter y otherwise n : ";
            cin>>ch;
            if(ch=='y'){
                cout<<"enter the time required to reach city "<<v[j]<<" from "<<v[i]<<"(in minutes) :";
                cin>>m[i][j];
            }
            else if(ch=='n'){
                m[i][j]=0;
            }
            else{
                cout<<"unknown entry !!"<<endl;
            }
        }
    }
}
void displaym(){
    cout<<endl;
    for(j=0;j<n;j++){
        cout<<"\t"<<v[j];
    }
    for(i=0;i<n;i++){
        cout<<"\n"<<v[i]<<endl;
        for(j=0;j<n;j++){
            cout<<"\t"<<m[i][j];
        }
        cout<<endl;
    }
}
}; 
int main(){
     int m;
     flight f;
     while(1){
        cout<<"choose form below :"<<endl;
        cout<<"1.create."<<endl;
        cout<<"2.display matrix."<<endl;
        cout<<"3.exit ."<<endl;
        cin>>m;
     
     switch(m){
        case 1: f.getgraph();
                   break;
        case 2: f.displaym();
                   break;
        case 3: exit(0);
        default: cout<<"invalid choice!!";
     }
    }
     return 0;

}