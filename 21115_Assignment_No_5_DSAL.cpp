/*
Implement all the functions of a dictionary (ADT) using hashing and
handle collisions using separate chaining using linked list.
Data: Set of (key, value) pairs, Keys are mapped to values,
Keys must be comparable, Keys must be unique.
Standard Operations:
Insert (key, value),
Find(key),
Delete(key)
ASCII Value:-
a-097	A-065
z-122	Z-090
*/
#include<iostream>
#include<cstring>
using namespace std;
class node
{
	node* next;
	string word,meaning;
public:
	node(string w,string m)
	{
		next = NULL;
		word = w;
		meaning = m;
	}
	friend class Dictionary;
};
class Dictionary
{
	node* dict[20];
	string w,m;
public:
	node* head[20];
	Dictionary()
	{

		for(int i=0;i<20;i++)
		{
			head[i] = NULL;
			dict[i] = NULL;
		}
	}
	int hash(string);
	void insert();
	void find();
	void delt();
};

int Dictionary::hash(string a)
{
	int key = 0;
	for(int i=0;i<a.length();i++)
	{
		key = key + int(a[i]);
	}
	return (key%20);
}
void Dictionary::insert()
{
	node* x;
	int y;
	cout<<"Enter Word to be inserted: "<<endl;
	cin>>w;
	cout<<"Enter Meaning of "<<w<<" : "<<endl;
	cin>>m;
	y=hash(w);
	if(head[y]==NULL)
	{
		head[y] = new node(w,m);
		dict[y] = head[y];
		head[y]->next=NULL;
	}
	else if(head[y]->next==NULL)
	{
		x = new node(w,m);
		head[y]->next = x;
		x->next=NULL;
	}
	else if(head[y]->next!=NULL)
	{
		while(head[y]->next!=NULL)
		{
			head[y] = head[y]->next;
		}
		x = new node(w,m);
		head[y]->next = x;
		x->next=NULL;
	}
}
void Dictionary::find()
{
	cout<<"Enter word to find meaning: "<<endl;
	cin>>w;
	int flag;
	int s = hash(w);
	node* b;
	b = dict[s];
	while(b!=NULL)
	{
		if(b->word==w)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
		b = b->next;
	}
	if(flag==1)
	{
		cout<<"Word "<<w<<" found"<<endl;
		cout<<"Word: "<<b->word<<endl;
		cout<<"Meaning: "<<b->meaning<<endl;
		cout<<"Hash value of "<<b->word<<" = "<<s<<endl;
	}
	else
	{
		cout<<"Word "<<w<<" not found"<<endl;
	}
}
void Dictionary::delt()
{
	cout<<"Enter word to delete: "<<endl;
	cin>>w;
	int flag=0;
	int s = hash(w);
	node *b,*curr;
	b = dict[s];
	curr = b;
	while(b!=NULL && b->word!=w)
	{
		curr = b;
		b = b->next;
	}
	if(b==NULL)
	{
		cout<<"Word not present!!!!"<<endl;
		return;
	}
	if(b->next==NULL)
	{
		curr->next = NULL;
		cout<<"Deleting Word "<< b->word<<endl;
		delete b;
	}
	else
	{
		curr->next = b->next;
		b->next = NULL;
		cout<<"Deleting Word "<< b->word<<endl;
		delete b;
	}
}
int main()
{
	Dictionary d;int a,ch;
	while(true)
	{
		cout<<"DICTIONARY ADT"<<endl;
		cout<<"1. Insert Words"<<endl;
		cout<<"2. Search a Word"<<endl;
		cout<<"3. Delete a Word"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter Choice"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter Words to be inserted: "<<endl;
			cin>>a;
			for(int i=0;i<a;i++)
			{
				d.insert();
			}
			break;
		case 2:
			d.find();
			break;
		case 3:
			d.delt();
			break;
		case 4:
			cout<<"Code Exited"<<endl;
			exit('0');
		default:
			cout<<"Wrong choice!!"<<endl;
			break;
		}
	}
	return 0;
}

