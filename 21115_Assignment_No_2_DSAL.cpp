/*
A Dictionary stores keywords and its meanings.
Provide facility for
1. adding new keywords,
2. deleting keywords,
3. updating values of any entry.
4. Provide facility to display whole data sorted in ascending/ Descending order.
5. Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation.*/

#include<iostream>
#include<cstring>
using namespace std;

class node
{
public:
	string word,meaning;
	node* left;
	node* right;
	node(string word,string meaning)
	{
		this->word = word;
		this->meaning = meaning;
		left=right=NULL;
	}
};
class Dictionary
{
public:
	node* root,*q;
	Dictionary()
	{
		root=NULL;
		q=NULL;
	}
	void accept();
	bool insert(string,string);
	void inorder(node*);
	node* search(node*,string);
	void update();
	void revinorder(node*);
	node* successor(node*);
	void delnode(node*,string);
	void comparisons(node* p,string);
};
void Dictionary::accept()
{
	int n;
	string word1,meaning1;
	cout<<"\nHow many words to insert?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Word: "<<endl;
		cin>>word1;
		cout<<"Enter it's meaning: "<<endl;
		cin.ignore();
		cin>>meaning1;
		insert(word1,meaning1);
	}
}
bool Dictionary::insert(string word,string meaning)
{
	node* p = new node(word,meaning);
	if(root==NULL)
	{
		root = p;
		return true;
	}
	node *curr=root;
	node *parent=root;
	while(curr!=NULL)
	{
		if(word>curr->word)
		{
			parent = curr;
			curr = curr->right;
		}
		else if(word<curr->word)
		{
			parent = curr;
			curr = curr->left;
		}
		else
		{
			cout<<"\n Word is Already in Dictionary"<<endl;
			return false;
		}

	}
	if(word>parent->word)
	{
		parent->right = p;
		return true;
	}
	else
	{
		parent->left = p;
		return true;
	}

}
void Dictionary::inorder(node *p)
{
	if(p)
	{
		inorder(p->left);
		cout<<" "<<p->word<<":"<<p->meaning<<endl;
		inorder(p->right);
	}
}
void Dictionary::revinorder(node *p)
{
	if(p)
	{
		revinorder(p->right);
		cout<<" "<<p->word<<":"<<p->meaning<<endl;
		revinorder(p->left);
	}
}
node* Dictionary::search(node* p,string n)
{

	if(p==NULL)
	{
		return NULL;
	}
	else if(p->word==n)
	{
		return p;
	}
	if(p->word<n)
	{
		return search(p->right,n);
	}
	else if(p->word>n)
	{
		return search(p->left,n);
	}
}
void Dictionary::update()
{
	string n,mean;
	cout<<"Enter Word to update its meaning: "<<endl;
	cin>>n;
	node *x = search(root,n);
	if(x)
	{
		cout<<"Enter New Meaning:"<<endl;
		cin>>mean;
		x->meaning = mean;
	}
	else
	{
		cout<<"Word Is Not Present"<<endl;
	}

}
node* Dictionary::successor(node* p)
{
	p=p->right;
	while(p->left)
	{
		p=p->left;
	}
	return p;
}
void Dictionary::delnode(node* p,string n)
{
		while(p!=NULL)							//searching for word
		{
			if(n < p->word)
			{
				q = p;
				p = p->left;
			}
			else if(n > p->word)
			{
				q=p;
				p = p->right;
			}
			else if(n == p->word)				//word found
			{
				if(p->left==NULL && p->right==NULL)	//no child
				{
					if(q->left==p)
					{
						delete p;
						q->left=NULL;
						return;
					}
					if(q->right==p)
					{
						delete p;
						q->right=NULL;
						return;
					}
				}
				if(p->right!=NULL && p->left==NULL)	//right child only
				{
					if(q->right == p)
					{
						q->right = p->right;
						delete p;
						return;
					}
					else if(q->left == p)
					{
						q->left = p->right;
						delete p;
						return;
					}
				}
				else if(p->left!=NULL && p->right==NULL)	//left child only
				{
					if(q->right == p)
					{
						q->right = p->left;
						delete p;
						return;
					}
					else if(q->left == p)
					{
						q->left=p->left;
						delete p;
						return;
					}
				}
				else if(p->left!=NULL && p->right!=NULL)
				{
					node *s = successor(p->right);
					p->word = s->word;
					p->meaning = s->meaning;
					delnode(s, s->word);
					return;
				}
			}
		}
		cout<<"\nWord NOT found!";
}
void Dictionary::comparisons(node* p,string n)
{
	node* x;
	x = search(p,n);
	if(x)
	{
		static int count=0;
		while(p)
		{
			if(p->word>n)
			{
				count++;
				p = p->left;
			}
			else if(p->word<n)
			{
				count++;
				p=p->right;
			}
			else if(p->word==n)
			{
				count++;
				cout<<"No. of Comparisons to find "<<n<<" are: "<<count<<endl;
				count =0;
				return;
			}
		}
	}
	else
	{
		cout<<"Word Not Found"<<endl;
	}
}
int main()
{
	int ch;
	string n,a,c;
	node* b;
	Dictionary d;
	d.accept();
	while(true)
	{
		cout<<"\nBinary Search Tree"<<endl;
		cout<<"1. Insert a Word"<<endl;
		cout<<"2. Display in Ascending Order."<<endl;
		cout<<"3. Display in Descending Order"<<endl;
		cout<<"4. Update an Word's Meaning"<<endl;
		cout<<"5. Delete an Word"<<endl;
		cout<<"6. Find Comparisons"<<endl;
		cout<<"7. Search Word"<<endl;
		cout<<"8.Exit"<<endl;
		cout<<"Enter Choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			d.accept();
			break;
		case 2:
			d.inorder(d.root);
			break;
		case 3:
			d.revinorder(d.root);
			break;
		case 4:
			d.update();
			break;
		case 5:
			cout<<"Enter Word to delete:"<<endl;
			cin>>a;
			d.delnode(d.root,a);
			break;
		case 6:
			cout<<"Enter The Word To find Comparisons:"<<endl;
			cin>>n;
			d.comparisons(d.root,n);
			break;
		case 7:
			cout<<"Enter Word to search it's Meaning"<<endl;
			cin>>c;
			b = d.search(d.root,c);
			cout<<"Word is: "<<b->word<<endl;
			cout<<"Meaning is: "<<b->meaning<<endl;
			break;
		case 8:
			cout<<"Code Exited"<<endl;
			exit('0');
		default:
			cout<<"Wrong Choice!!"<<endl;
			break;


		}
	}
	return 0;
}
