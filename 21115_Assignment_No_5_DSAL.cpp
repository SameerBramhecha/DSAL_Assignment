/*Implement all the functions of a dictionary (ADT) using hashing and
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
using namespace std;
class node
{
	node* next;
	string word,meaning;
public:
	node(string word,string meaning)
	{
		next=NULL;
		this->word = word;
		this->meaning =meaning;
	}
	friend class SC;
};
class SC
{
	node* list[10];
	string w,m;
public:
	SC()
	{
		for(int i=0;i<10;i++)
		{
			list[i]=NULL;
		}
	}
	void insert();
	int hash(char);
	void display();
	void search(string s);
	void deleteword();
};

int SC::hash(char a)
{
	int key;
	key = (int(a))%10;
	return key;
}
void SC::insert()
{
	char ch = 'y';
	do
	{
		cout<<"Enter Word: "<<endl;
		cin>>w;
		cout<<"Enter Meaning: "<<endl;
		cin>>m;
		node* x = new node(w,m);
			int key = hash(w[0]);
			if(list[key] == NULL)
			{
				list[key] = x;
				list[key]->next = NULL;
			}
			else
			{
				node* head;
				head = list[key];
				while(head->next!=NULL)
				{
					head = head->next;
				}
				head->next = x;
			}
		cout<<"Do you want to continue?[y/n]"<<endl;
		cin>>ch;
	}while(ch=='y');

}
void SC::display()
{
	node* head;
	for(int i=0;i<10;i++)
	{
		head = list[i];
		while(head!=NULL)
		{
			cout<<head->word<<" : "<<head->meaning<<" -> ";
			head=head->next;
		}
		cout<<endl;
	}
}
void SC::search(string s)
{

	bool flag = 0;
	int key = hash(s[0]);
	node* temp;
	temp = list[key];
	while(temp!=NULL)
	{
		if(temp->word == s)
		{
			cout<<"Word Found"<<endl;
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if(flag == 1)
	{
		cout<<"Word: "<<temp->word<<endl;
		cout<<"Meaning: "<<temp->meaning<<endl;
	}
	else if(flag == 0)
	{
		cout<<"Word Not Found!!"<<endl;
	}
}
void SC::deleteword()
{
	string s;
	cout<<"Enter Word to Delete from Dictionary: "<<endl;
	cin>>s;
	int key;
	key = hash(s[0]);
	node* temp;
	temp = list[key];
	node* curr = temp;
	if(temp->word==s)	//if node is first node in list
	{
		node* start = temp;
		start = start->next;
		list[key] = start;
		temp->next=NULL;
		cout<<"Deleting word - "<<temp->word<<endl;
		delete temp;
		return;
	}
	while(temp!=NULL && temp->word!=s)
	{
		curr = temp;
		temp = temp->next;
	}
	if(temp==NULL)
	{
		cout<<"Word Not present!!"<<endl;
		return;
	}
	else if(temp->next==NULL)//node is last node
	{
		curr->next=NULL;
		cout<<"Deleting word - "<<temp->word<<endl;
		delete temp;
		return;
	}
	else // node is in between
	{
		curr->next = temp->next;
		temp->next = NULL;
		cout<<"Deleting word - "<<temp->word<<endl;
		delete temp;
		return;
	}
}
int main()
{
	SC s;
	int ch;string s1;
	while(true)
	{
		cout<<"1. INSERT WORDS"<<endl;
		cout<<"2. DISPLAY ALL WORDS"<<endl;
		cout<<"3. SEARCH WORDS"<<endl;
		cout<<"4. DELETE WORDS"<<endl;
		cout<<"5. EXIT"<<endl;
		cout<<"ENTER CHOICE: "<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			s.insert();
			break;
		case 2:
			s.display();
			break;
		case 3:

			cout<<"Enter Word to search Meaning: "<<endl;
			cin>>s1;
			s.search(s1);
			break;
		case 4:
			s.deleteword();
			break;
		case 5:
			cout<<"Code Exited"<<endl;
			exit('0');
		default:
			cout<<"Enter Correct Choice!!"<<endl;
			break;
		}
	}
	return 0;
}
