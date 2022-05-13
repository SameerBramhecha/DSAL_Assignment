/*Beginning with an empty binary tree, construct binary tree by inserting the values
in the order given. After constructing a binary tree perform following operations on it-
•	Perform in-order, pre-order and post-order traversal (Implement both recursive and
non-recursive methods)
•	Change a tree so that the roles of the left and right pointers are swapped
 at every node
•	Find the height of tree
•	Copy this tree to another [operator=]
•	Count number of leaves, number of internal nodes.
•	Erase all nodes in a binary tree.
 * */

#include<iostream>
using namespace std;
class node
{
	char data;
	node* rchild;
	node* lchild;
public:
	node(char d)
	{
		data = d;
		lchild = rchild = NULL;
	}
	friend class BT;
	friend class Stack;

};

class Stack
{
	char top;
	node* s[20];
public:
	Stack()
	{
		top = -1;
	}
	void push(node* p)
	{
		if(top==19)
		{
			cout<<"Stack is Full!!"<<endl;
		}
		else
		{
			s[++top] = p;

		}
	}

	node* pop()
	{
		node* x;
		if(top==-1)
		{
			cout<<"Stack is Empty"<<endl;
		}
		else
		{
			x = s[top];
			top--;
			return x;
		}
	}
	bool isempty()
	{
		if(top==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

};


class BT
{
	node* root;
public :
	BT()
	{
		root = NULL;
	}
	node* create();//
	void rinorder(node* p);//
	void nrinorder(node* p,Stack);//
	void rpreorder(node* p);//
	void nrpreorder(node* p,Stack s);//
	void rpostorder(node* p);//
	void nrpostorder(node* p,Stack s);//
	node* mirror(node* p);//
	int height(node* p);//
	int intnodecount(node* p);//
	int leafnode(node* p);//
	void deletetree(node* p);
	node* operator=(node* p);

};


node* BT::create()
{
	char d;
	char ch;
	cin>>d;
	node* root = new node(d);
	cout<<"Do you want to enter Left Child of "<<d<<" ?[y/n]"<<endl;
	cin>>ch;
	if(ch == 'y'||ch == 'Y')
	{
		cout<<"Enter Left Child of "<<d<<endl;
		root->lchild = create();
	}
	cout<<"Do you want to enter Right Child of "<<d<<" ?[y/n]"<<endl;
	cin>>ch;
	if(ch == 'y'||ch == 'Y')
	{
		cout<<"Enter Right Child of "<<d<<endl;
		root->rchild = create();
	}
	return root;

}

void BT::rinorder(node* p)
{
	if(p)
	{
		rinorder(p->lchild);
		cout<<p->data<<" ";
		rinorder(p->rchild);
	}

}
void BT::nrinorder(node* p,Stack s)
{
	while(true)
	{
		while(p)
		{
			s.push(p);
			p = p->lchild;
		}
		if(s.isempty())
		{
			return;
		}
		p = s.pop();
		cout<<p->data<<" ";

		p = p->rchild;
	}
}

void BT::rpreorder(node* p)
{
	if(p)
	{
		cout<<p->data<<" ";
		rpreorder(p->lchild);
		rpreorder(p->rchild);
	}
}

void BT::nrpreorder(node* p,Stack s)
{
	while(true)
	{
		while(p)
		{
			cout<<p->data<<" ";
			if(p->rchild)
			{
				s.push(p->rchild);
			}
			p = p->lchild;
		}
		if(s.isempty())
		{
			return;
		}
		p = s.pop();
	}
}

void BT::rpostorder(node* p)
{
	if(p)
	{
		rpostorder(p->lchild);
		rpostorder(p->rchild);
		cout<<p->data<<" ";
	}
}

void BT::nrpostorder(node* p,Stack s)
{
	node* p1, *temp;
	temp = new node('#');
	while(true)
	{
		while(p!=NULL)
		{
			s.push(p);
			if(p->rchild!=NULL)
			{
				s.push(p->rchild);
				s.push(temp);
			}
			p = p->lchild;
		}
		if(s.isempty())
		{
			return;
		}
		else
		{
			p1 = s.pop();
		}
		while(p1!=temp && !s.isempty())
		{
			cout<<p1->data<<" ";
			p1 = s.pop();
			if(s.isempty())
			{
				cout<<p1->data<<" ";
			}
		}
		if(!s.isempty())
		{
			p = s.pop();
		}
	}
}
node* BT::mirror(node* p)
{
	node* temp;
	if(p)
	{
		temp = new node(p->data);
		temp->lchild = mirror(p->rchild);
		temp->rchild = mirror(p->lchild);
		return temp;
	}
	else
		return NULL;
}
node* BT::operator=(node* p)
{
	if(p==NULL)
		{
			return NULL;
		}
		node* temp = new node(p->data);
		temp->lchild = (p->lchild);
		temp->rchild = (p->rchild);
		return temp;
}
void BT::deletetree(node* p)
{
	if(p==NULL)
	{
		return;
	}
	deletetree(p->lchild);
	deletetree(p->rchild);
	cout<<"\nDeleting node "<<p->data<<endl;
	delete p;
}

int BT::intnodecount(node * p)
{
	int x1,x2;
	if(!p || (p->lchild == NULL&& p->rchild == NULL))
	{
		return 0;
	}
	else
	{
		x1 = intnodecount(p->lchild);
		x2 = intnodecount(p->rchild);
		return (1+x1+x2);
	}
}
int BT::leafnode(node* p)
{
	int x1,x2;
	if(!p)
	{
		return 0;
	}
	if(p->lchild == NULL&& p->rchild == NULL)
	{
		return 1;
	}
	else
	{
		x1 = leafnode(p->lchild);
		x2 = leafnode(p->rchild);
		return (x1+x2);
	}
}


int BT::height(node* p)
{
	int h1,h2;
	if(p==NULL)
	{
		return 0;
	}
	if(p->lchild == NULL && p->rchild == NULL)
	{
		return 0;
	}
	h1 = height(p->lchild);
	h2 = height(p->rchild);
	if(h1>h2)
	{
		return h1+1;
	}
	else
	{
		return h2+1;
	}
}


int main()
{
	BT b;
	Stack s;
	node* root,*temp,*x;
	while(true)
	{
		cout<<"1. Create a Binary Tree"<<endl;
		cout<<"2. In-order Traversal"<<endl;
		cout<<"3. Pre-order Traversal"<<endl;
		cout<<"4. Post-order Traversal"<<endl;
		cout<<"5. Mirror Image of a Tree"<<endl;
		cout<<"6. Height of a Tree"<<endl;
		cout<<"7. Internal And Leaf Node Count"<<endl;
		cout<<"8. Copy tree"<<endl;
		cout<<"9. Delete Tree"<<endl;
		cout<<"10. Exit"<<endl;
		cout<<"Enter Choice:"<<endl;
		int ch;
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter Elements of Binary Tree:"<<endl;
			root = b.create();
			break;
		case 2:
			int a;
			cout<<"1. Recursive In-Order Traversal"<<endl;
			cout<<"2. Non-Recursive In-Order Traversal"<<endl;
			cout<<"Enter Choice"<<endl;
			cin>>a;
				switch(a)
				{
				case 1:
					b.rinorder(root);
					cout<<endl;
					break;
				case 2:
					b.nrinorder(root,s);
					cout<<endl;
					break;
				default: cout<<"Wrong Choice";
					break;
				}
				break;
			case 3:
				int c;
				cout<<"1. Recursive Pre-Order Traversal"<<endl;
				cout<<"2. Non-Recursive Pre-Order Traversal"<<endl;
				cout<<"Enter Choice"<<endl;
				cin>>c;
				switch(c)
				{
				case 1:
					b.rpreorder(root);
					cout<<endl;
					break;
				case 2:
					b.nrpreorder(root, s);
					cout<<endl;
					break;
				default:
					cout<<"Wrong Choice";
					break;
				}
				break;

			case 4:
				int d;
				cout<<"1. Recursive Post-Order Traversal"<<endl;
				cout<<"2. Non-Recursive Post-Order Traversal"<<endl;
				cout<<"Enter Choice"<<endl;
				cin>>d;
				switch(d)
				{
				case 1:
					b.rpostorder(root);
					cout<<endl;
					break;
				case 2:
					b.nrpostorder(root,s);
					cout<<endl;
					break;
				default:
					cout<<"Wrong Choice";
					break;
				}
				break;
			case 5:
				temp = b.mirror(root);
				cout<<"In-order Traversal:- ";
				b.rinorder(temp);cout<<endl;
				cout<<"Pre-order Traversal:- ";
				b.rpreorder(temp);cout<<endl;
				cout<<"Post-order Traversal:- ";
				b.rpostorder(temp);cout<<endl;
				break;
			case 6:
				cout<<"Height of the Binary Tree is: "<<b.height(root)<<endl;
				break;
			case 7:
				cout<<"No of Leaf Nodes are: "<<b.leafnode(root)<<endl;
				cout<<"No of Internal Nodes are: "<< b.intnodecount(root)<<endl;
				break;
			case 8:
				cout<<"Copying Tree"<<endl;
				x = root;
				cout<<"Tree copied!"<<endl;
				cout<<"In-order Traversal of Copied Tree: "<<endl;
				b.rinorder(x);
				break;
			case 9:
				b.deletetree(root);
				cout<<endl;
				break;
			case 10:
				exit('0');
			default:
				cout<<"Wrong Choice"<<endl;
				break;
		}
	}
	return 0;
}
