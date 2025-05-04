#include<iostream>
#include<stack>
using namespace std;
class Node
{
	public:
	char val;
	Node* left;
	Node* right;
	Node(char x)
	{
		val = x;
		left = NULL;
		right = NULL;
	}
};
class Tree
{
	Node* root;
	public:
	Tree()
	{
		root = NULL;
	}
	void insert(string str)
	{
		stack<Node*> st;
		for(int i=str.length()-1;i>=0;i--)
		{
		
			Node* n = new Node(str[i]);
			if(!isalpha(str[i]))
			{
				n->left = st.top();
				st.pop();
				n->right = st.top();
				st.pop();
			}
			st.push(n);
		}
		root = st.top();
	}
	void post()
	{
		if(!root)
		{
			cout<<"No tree ";
			return;
		}
		stack<Node*> st1,st2;
		st1.push(root);
		while(!st1.empty())
		{
			Node* curr = st1.top();
			st1.pop();
			st2.push(curr);
			if(curr->left) st1.push(curr->left);
			if(curr->right) st1.push(curr->right);
		}
		while(!st2.empty())
		{
			cout<<st2.top()->val<<" ";
			st2.pop();
		}
	}
	void Deleteroot()
	{
		delete root;
		cout<<"root node is deleted ";
		return;
	}
};
int main()
{
	Tree t;
	t.insert("+--a*bc/def");
	t.post();
	return 0;
}
