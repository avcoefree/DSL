#include<iostream>
using namespace std;

struct node
{
char label[60];
int chcount;
node *child[50];
}*root;

class general
{
public:

general()
{
root = NULL;
}

void insert()
{
int secount;
root = new node();
cout<<"Enter the name of book: "<<endl;
cin>>root->label;
cout<<"Enter the total number of chapters in book: "<<endl;
cin>>root->chcount;
for(int i=0;i<root->chcount;i++)
{
root->child[i] = new node();
cout<<"Enter the name of chapter:  "<<i+1<<endl;
cin>>root->child[i]->label;

cout<<"Enter the number of sections:"<<endl;
cin>>root->child[i]->chcount;
for(int j=0;j<root->child[i]->chcount;j++)
{
root->child[i]->child[j] = new node();
cout<<"Enter the name of section "<<j+1<<endl;
cin>>root->child[i]->child[j]->label;

cout<<"Enter the number of sub sections "<<endl;
cin>>root->child[i]->child[j]->chcount;
for(int k=0; k<root->child[i]->child[j]->chcount; k++)
{
root->child[i]->child[j]->child[k] = new node();
cout<<"Enter the name of sub section "<<endl;
cin>>root->child[i]->child[j]->child[k]->label;
}
}
}
}

void display()
{
if(root != NULL)
{
cout<<"**** Hierarchy of Book ****"<<endl;
cout<<"Book Name is"<<root->label<<endl;
for(int i=0; i<root->chcount; i++)
{
cout<<"chapter "<<root->child[i]->label<<endl;
for(int j=0; j<root->child[i]->chcount; j++)
{
cout<<"Section "<<root->child[i]->child[j]->label<<endl;
for(int k=0; k<root->child[i]->child[j]->chcount; k++)
{
cout<<"Sub section "<<root->child[i]->child[j]->child[k]->label<<endl;
}
}
}
}
}
};
int main()
{
general g;
int ch;
do
{
cout<<"~~ MENU ~~"<<endl;
cout<<"1. Insert."<<endl;
cout<<"2. Display."<<endl;
cout<<"Enter the choice:"<<endl;
cin>>ch;

switch(ch)
{
case 1: g.insert();
break;
case 2: g.display();
break;
}
}while(ch<3);
}