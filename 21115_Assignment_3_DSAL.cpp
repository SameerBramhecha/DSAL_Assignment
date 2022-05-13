/*Create an In-ordered threaded binary tree and perform In-order and Pre-order traversals.
 *  Analyze time and space complexity of the algorithm.*/

#include<iostream>
using namespace std;
class node
{
	int data;
	bool lbit,rbit;
	node* left,*right;
public:
	node()
	{
		data= 0;
		lbit=rbit=0;
		left=right=NULL;
	}
	friend class TBT;
};

class TBT
{

public:
	node* New,*root,*dummy,*temp,*parent;
	TBT()
	{
		New = root = dummy = temp = parent = NULL;
	}
	void create();//
	void insert(node*,node*);//
	void inorder();//
	node* insuccessor(node*);//
	node* inpredecessor(node*);
	void preorder(node*, node*);//
	void display();
	node* search(node*,node*,int,node**);//
	void find();//
	void delt(node*,node*,int);
	void delt();
};
void TBT::create()
{
	int n;
	cout<<"Enter no. of elements to enter in Threaded Binary Tree : "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		New = new node();         //Creating a new node
		New->left = NULL;		  //Setting default Values
		New->right = NULL;
		New->lbit = 0;
		New->rbit = 0;
		cout<<"Enter Data: "<<endl;
		cin>>New->data;			//Accepting Data Value
		if(root==NULL)			//If No Node is present create an root node
		{
			root=New;
			dummy = new node();
			dummy->data = -999;
			dummy->right = root;
			dummy->rbit=1;
			root->left = dummy;
			root->right = dummy;
		}
		else
		{
			insert(root,New);       	//If root is present then insert New->data
		}
	}
}
void TBT::insert(node* root, node* New)	//function to insert a new node
{
	if(New->data<root->data) 	// if New->data<root->data then insert in left subtree
	{
		if(root->lbit==0)
		{
			New->left = root->left;
			New->right = root;
			root->left = New;
			root->lbit = 1;
		}
		else
		{
			insert(root->left,New);
		}
	}
	if(New->data>root->data)	// if New->data>root->data then insert in right subtree
	{
		if(root->rbit==0)
		{
			New->right = root->right;
			New->left= root;
			root->rbit= 1;
			root->right = New;
		}
		else
		{
			insert(root->right,New);
		}
	}
}
void TBT::inorder()
{
	node* temp = dummy;
	while(temp)
	{
		temp = insuccessor(temp);
		if(temp==dummy)
		{
			return;
		}
		else
		{
			cout<<temp->data<<" ";
		}
	}
}
node* TBT::insuccessor(node* curr)
{
	node* s = curr->right;
	if(curr->rbit==1)
	{
		while(s->lbit==1)
		{
			s = s->left;
		}
	}
	return s;
}
void TBT::preorder(node* root, node* dummy)
{
	node* temp = root;
	int flag=0;
	while(temp!=dummy)
	{
		if(flag == 0)
		{
			cout<<temp->data<<" ";
		}
		if(flag == 0 && temp->lbit==1)
		{
			temp = temp->left;
		}
		else
		{
			while(1)
			{
				if(temp->rbit==1)
				{
					temp = temp->right;
					flag = 0;
					break;
				}
				else
				{
					temp = temp->right;
					flag =1 ;
					break;
				}
			}
		}
	}
}
void TBT::display()
{
	while(true)
	{
		int ch;
		cout<<"1. In-order Traversal"<<endl;
		cout<<"2. Pre-order Traversal"<<endl;
		cout<<"3. Exit Code"<<endl;
		cout<<"Enter Choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			inorder();
			cout<<endl;
			break;
		case 2:
			preorder(root,dummy);
			cout<<endl;
			break;
		case 3:
			return;
			break;
		default:
			cout<<"Wrong choice!!!!!"<<endl;
			break;
		}
	}
}
node* TBT::search(node* root,node* dummy,int key,node** parent)
{
	node* temp = root;
	while(temp!=dummy)
	{
		if(temp->data == key)
		{
			cout<<"Element "<<temp->data<<" found\n"<<endl;
			return temp;
			break;
		}
		*parent = temp;
		if(temp->data<key)
		{
			temp = temp->right;
		}
		else if(temp->data>key)
		{
			temp = temp->left;
		}
	}
	return NULL;
}
void TBT::find()
{
	node* temp;int key;
	cout<<"Enter element you want to find : ";
	cin>>key;
	temp = search(root,dummy,key,&parent);
	if(temp==NULL)
	{
		cout<<"Element not found\n"<<endl;
	}
	else if(temp == root)
	{
		cout<<"Element "<<key<<" is root node\n"<<endl;
	}
	else
	{
		cout<<"It's parent element is "<<parent->data<<"\n"<<endl;
	}
}
void TBT::delt(node* root,node* dummy,int key)
{
	node* temp,*parent,*temp_succ;
	int flag=0;
	temp = search(root,dummy,key,&parent);
	if(root==temp)
	{
		cout<<"\n Its Root Node Which cannot be deleted"<<endl;
		return;
	}
	//deleting a node with two children
	if(temp->lbit==1 && temp->rbit==1)
	{
		parent = temp;
		temp_succ=  temp->right;
		while(temp_succ->lbit==1)
		{
			flag=1;
			parent = temp_succ;
			temp_succ = temp_succ->left;
		}
		if(flag==0)
		{
			temp->data = temp_succ->data;
			parent->right = temp_succ->right;
			parent->rbit = 0;
		}
		else
		{
			temp->data = temp_succ->data;
			parent->rbit=0;
			parent->lbit=0;
			parent->left = temp_succ->left;
		}
		cout<<"Deleted It"<<endl;
		return;
	}
	//deleting node with one child
	if(temp->lbit==1 && temp->rbit==0)
	{
		if(parent->left==temp)
		{
			(temp->left)->right = parent;
			parent->left = temp->left;
		}
		else
		{
			(temp->left)->right = temp->right;
			parent->right = temp->left;
		}
		temp=NULL;
		delete temp;
		cout<<"Deleted It"<<endl;
		return;
	}
	//node to be deleted has right child
	if(temp->lbit==0 && temp->rbit==1)
	{
		if(parent->left==temp)
		{
			parent->left = temp->right;
			(temp->right)->left = temp->left;
			(temp->right)->right=parent;
		}
		else
		{
			parent->right = temp->right;
			(temp->right)->left = parent;
		}
		temp=NULL;
		delete temp;
		cout<<"Deleted It"<<endl;
		return;
	}
	//deleting node with no children
	if(temp->lbit==0 && temp->rbit==0)
	{
		if(parent->left==temp)
		{
			parent->left=temp->left;
			parent->lbit=0;
		}
		else
		{
			parent->right = temp->right;
			parent->rbit=0;
		}
		cout<<"Deleted It"<<endl;
		return;
	}
}
void TBT::delt()
{
	int key;
	cout<<"Enter the element: ";
	cin>>key;
	delt(root,dummy,key);
}
int main()
{
	TBT t;
	int ch;
	t.create();
	while(true)
	{
		cout<<"------------THREADED BINARY TREE------------"<<endl;
		cout<<"1. Insert an element in TBT"<<endl;
		cout<<"2. Traversals of TBT"<<endl;
		cout<<"3. Search an element in TBT"<<endl;
		cout<<"4. Delete an element from TBT"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter Choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			t.create();
			break;
		case 2:
			t.display();
			cout<<endl;
			break;
		case 3:
			t.find();
			break;
		case 4:
			t.delt();
			t.inorder();
			break;
		case 5:
			exit('0');
		default:
			cout<<"Wrong Choice!!!"<<endl;
			break;
		}
	}
	return 0;
}

