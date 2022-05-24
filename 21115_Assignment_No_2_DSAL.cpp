/*
A Dictionary stores keywords and its meanings.
Provide facility for
1. adding new keywords,
2. deleting keywords,
3. updating values of any entry.
4. Provide facility to display whole data sorted in ascending/ Descending order.
5. Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation.
*/

#include<iostream>
using namespace std;
class node
{
	string word,meaning;
	node* left,*right;
public:
	node(string word, string meaning)
	{
		this->word = word;
		this->meaning = meaning;
		left=right=NULL;
	}
	friend class BST;
};
class BST
{

public:
	node* root, *par;
	BST()
	{
		root = NULL;
		par = NULL;
	}
	void accept();//
	void insert(string,string);//
	void inorder(node*);//
	void revinorder(node*);//
	node* search(node*,string);//
	void update();//
	node* delt(node*,string);//
	void deltnode();
	void comparisons(node* );//
	node* successor(node*);//
	node* getroot();
};
node* BST::getroot()
{
	return root;
}
void BST::accept()
{
	string name,meaning;
	char ch = 'y';
	do
	{
		cout<<"Enter Name to insert: "<<endl;
		cin>>name;
		cout<<"Enter it's Meaning: "<<endl;
		cin.ignore();
		cin>>meaning;
		insert(name,meaning);
		cout<<"Do You Want to continue?[y/n]"<<endl;
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}
void BST::insert(string name,string meaning)
{
	node* p = new node(name,meaning);
	if(root == NULL)
	{
		root = p;
		return;
	}
	node* curr = root;
	node* par = root;
	while(curr!=NULL)
	{
		if(name>curr->word)
		{
			par = curr;
			curr= curr->right;
		}
		else if(name<curr->word)
		{
			par = curr;
			curr = curr->left;
		}
		else
		{
			cout<<"Word Already Present in Dictionary!!!"<<endl;
			return;
		}
	}

	if(name>par->word)
	{
		par->right = p;
		return;
	}
	else if(name<par->word)
	{
		par->left = p;
		return;
	}

}

void BST::inorder(node* p)
{
	if(p)
	{
		inorder(p->left);
		cout<<p->word<<" : "<<p->meaning<<endl;
		inorder(p->right);
	}
}

void BST::revinorder(node* p)
{
	if(p)
	{
		revinorder(p->right);
		cout<<p->word<<" : "<<p->meaning<<endl;
		revinorder(p->left);
	}
}
node* BST::search(node* p,string name)
{
	if(p==NULL)
	{
		return NULL;
	}
	else if(name==p->word)
	{
		return p;
	}
	if(p->word<name)
	{
		return search(p->right,name);
	}
	else if(name<p->word)
	{
		return search(p->left,name);
	}
}
void BST::update()
{
	string n,m;
	cout<<"Enter Word to update Meaning: "<<endl;
	cin>>n;
	node *x = search(root,n);
	if(x)
	{
		cout<<"Enter New Meaning: "<<endl;
		cin>>m;
		x->meaning = m;
	}
	else
	{
		cout<<"Word Not Found!!"<<endl;
	}
}

void BST::comparisons(node* p)
{
	string n;
	cout<<"Enter Word to find no.of comparisons: "<<endl;
	cin>>n;
	node* x = search(p,n);
	if(x)
	{
		static int count=0;
		while(p)
		{
			if(p->word<n)
			{
				count++;
				p=p->right;
			}
			else if(p->word>n)
			{
				count++;
				p=p->left;
			}
			if(p->word==n)
			{
				count++;
				cout<<"No. of Comparisons required to find "<<n<<" are: "<<count<<endl;
				count=0;
				return;
			}
		}
	}
	else
	{
		cout<<"Word Not Found!!"<<endl;
	}
}
node* BST::successor(node* p)
{
	//p=p->right;
	while(p->left)
	{
		par = p;
		p=p->left;
	}
	return p;
}
void BST::deltnode()
{
	string n;
	cout<<"Enter Word to Delete: "<<endl;
	cin>>n;
	node* temp = delt(getroot(),n);
	if(temp==getroot())
	{
		cout<<n<<" deleted"<<endl;
	}
	else
	{
		cout<<n<<" not present"<<endl;
	}

}
node* BST::delt(node* curr, string n)
{
	if(curr==NULL)
		return curr;
	if(n<curr->word)
	{
		curr->left = delt(curr->left,n);
	}
	else if(n>curr->word)
	{
		curr->right = delt(curr->right,n);
	}
	else if(n==curr->word)
	{
		node* temp = curr;
		if(curr->left==NULL )
		{
			curr = curr->right;
			delete temp;
			return curr;
		}
		else if(curr->right==NULL)
		{
			curr = curr->left;
			delete temp;
			return curr;
		}
		//if node has 2 children
		temp= successor(curr->right);
		curr->word = temp->word;
		curr->meaning = temp->meaning;
		curr->right = delt(curr->right,temp->word);
	}
	return curr;
}
int main()
{
	BST b;
	int ch;
	while(true)
	{
		cout<<"----------DICTIONARY----------"<<endl;
		cout<<"1. Insert Words"<<endl;
		cout<<"2. Display in Ascending Order"<<endl;
		cout<<"3. Display in Descending Order"<<endl;
		cout<<"4. Update Meaning of a Word"<<endl;
		cout<<"5. Find Comparisons"<<endl;
		cout<<"6. Delete A Word"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Enter Choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			b.accept();
			break;
		case 2:
			b.inorder(b.root);
			break;
		case 3:
			b.revinorder(b.root);
			break;
		case 4:
			b.update();
			break;
		case 5:
			b.comparisons(b.root);
			break;
		case 6:
			b.deltnode();
			break;
		case 7:
			cout<<"Code Exited"<<endl;
			exit('0');
		}
	}


}
