/*Consider telephone book database of N clients.
Make use of a hash table implementation to quickly look up client‘s telephone number.
Make use of two collision handling techniques and compare them using number of comparisons
required to find a set of telephone numbers (use linear probing with replacement
and without replacement)
*/
#include<iostream>
using namespace std;
class Customer
{
	long long teleno;
	string name;
public:
	Customer()
	{
		name = " ";
		teleno = 0;
	}
	friend class LinearProbing;
};
class LinearProbing
{
	string* name;
	long long* teleno;
	int n;
public:
	LinearProbing(int n)
	{
		this->n = n;
		name = new string[n];
		teleno = new long long[n];
		for(int i=0;i<n;i++)
		{
			name[i] = " ";
			teleno[i] = -1;
		}
	}
	long long hash(long long);
	void insertwor(Customer);
	void insertwr(Customer);
	void search();
	void display();
};

long long LinearProbing::hash(long long num)
{
	long long key;
	key = num%n;
	return key;
}
void LinearProbing::insertwor(Customer c)
{
	long long h;
	int flag;
	for(int i=0;i<n;i++)
	{
		flag = 0;
		cout<<"Enter Name of Customer "<<(i+1)<<" :"<<endl;
		cin>>c.name;
		cout<<"Enter Telephone Number of Customer "<<(i+1)<<" :"<<endl;
		cin>>c.teleno;
		h = hash(c.teleno);
		if(teleno[h] == -1)
		{
			teleno[h] = c.teleno;
			name[h] = c.name;
		}
		else
		{
			for(long long i = (h+1) ; i < n ;i++)
			{
				if(teleno[i] == -1)
				{
					teleno[i] = c.teleno;
					name[i] = c.name;
					flag=1;
					break;
				}
			}
			for(long long i=0;(i<h && flag==0);i++)
			{
				if(teleno[i] == -1)
				{
					teleno[i] = c.teleno;
					name[i] = c.name;
					flag=1;
					break;
				}
			}
		}
	}

}
void LinearProbing::insertwr(Customer c)
{
	long long h;
	int flag;
	for(int i=0;i<n;i++)
	{
		flag=0;
		cout<<"Enter Name of Customer "<<(i+1)<<" :"<<endl;
		cin>>c.name;
		cout<<"Enter Telephone Number of Customer "<<(i+1)<<" :"<<endl;
		cin>>c.teleno;
		h = hash(c.teleno);
		if(teleno[h] == -1)
		{
			teleno[h] = c.teleno;
			name[h] = c.name;
		}
		else if(teleno[h]!= -1 && hash(teleno[h]) == h)
		{
			for(long long i=(h+1);i<n;i++)
			{
				if(teleno[i] == -1)
				{
					teleno[i] = c.teleno;
					name[i] = c.name;
					flag=1;
					break;
				}

			}
			for(long long i=0;(i<h && flag==0);i++)
			{
				if(teleno[i] == -1)
				{
					teleno[i] = c.teleno;
					name[i] = c.name;
					flag=1;
					break;
				}
			}
		}
		else if(teleno[h]!=-1 && hash(teleno[h]) != h)
		{
			string n1;long long t;
			n1 = name[h];
			t = teleno[h];
			name[h] = c.name;
			teleno[h] = c.teleno;
			for(long long  i=(h+1);i<n;i++)
			{
				if(teleno[i] == -1)
				{
					teleno[i] = t;
					name[i] = n1;
					flag=1;
					break;
				}
			}
			for(long long  i=0;(i<h && flag==0);i++)
			{
				if(teleno[i] == -1)
				{
					teleno[i] = t;
					name[i] = n1;
					flag=1;
					break;
				}
			}

		}
	}

}
void LinearProbing::display()
{
	for(int i=0;i<n;i++)
	{
		cout<<"Customer Name: "<<name[i]<<endl;
		cout<<"Customer Number: "<<teleno[i]<<endl;
	}
}

void LinearProbing::search()
{
	long long t;
	cout<<"Enter Telephone Number to Search name:"<<endl;
	cin>>t;
	bool flag = 0;
	long long key = hash(t);
	static int count=0;
	if(teleno[key] == t)
	{
		count++;
		flag =1;
		cout<<"Customer Name: "<<name[key]<<endl;
		cout<<"Customer Number: "<<teleno[key]<<endl;
		cout<<"No. of Comparisons are: "<<count<<endl<<endl;
		count = 0;
	}
	else
	{
		for(long long i = (key+1) ; i < n ;i++)
		{
			count++;
			if(teleno[i] == t)
			{
				count++;flag =1;
				cout<<"Customer Name: "<<name[i]<<endl;
				cout<<"Customer Number: "<<teleno[i]<<endl;
				cout<<"No. of Comparisons are: "<<count<<endl<<endl;
				count = 0;
				break;
			}
		}
		for(long long i=0;i<key;i++)
		{
			count++;
			if(teleno[i] == t)
			{
				count++;flag =1;
				cout<<"Customer Name: "<<name[i]<<endl;
				cout<<"Customer Number: "<<teleno[i]<<endl;
				cout<<"No. of Comparisons are: "<<count<<endl<<endl;
				count = 0;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Record Not Found!!!"<<endl;
	}
}
int main()
{
	int a;
	cout<<"Enter Number of records to enter: "<<endl;
	cin>>a;
	LinearProbing l(a);
	Customer c;
	while (true)
	{
		int ch, x;
		cout << "1. Enter Data" << endl;
		cout << "2. Display Data" << endl;
		cout << "3. Search" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter Choice: " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "1. Insert With Replacement" << endl;
			cout << "2. Insert Without Replacement" << endl;
			cout << "3. Exit" << endl;
			cout << "Enter Choice: " << endl;
			cin >> x;
			switch (x)
			{
			case 1:
				l.insertwr(c);
				break;
			case 2:
				l.insertwor(c);
				break;
			default:
				cout << "Wrong choice" << endl;
				break;
			}
			break;
		case 2:
			l.display();
			break;
		case 3:
			l.search();
			break;
		case 4:
			cout << "Code Exited..." << endl;
			exit('0');
		default:
			cout << "Wrong Choice!!!" << endl;
			break;
		}
	}
	return 0;
}
