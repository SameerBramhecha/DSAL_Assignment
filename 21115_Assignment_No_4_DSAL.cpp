/*
Consider telephone book database of N clients.
Make use of a hash table implementation to quickly look up client‘s telephone number.
Make use of two collision handling techniques and compare them using number of comparisons
required to find a set of telephone numbers (use linear probing with replacement
and without replacement)
*/
#include <iostream>
#include <string.h>
using namespace std;
class Customer
{
	string name;
	string teleno;
	int id;
public:
	Customer()
	{
		name = "";
		teleno = "";
		id = 0;
	}
	friend class Hash;
};
class Hash
{
	int max = 5;
	string n[5];
	string t[5];
	int id[5];
public:
	Hash()
	{
		for (int i = 0; i < max; i++)
		{
			id[i] = -1;
		}
	}
	void insertwor(Customer);
	void insertwr(Customer);
	int hash(int num);
	void display();
	void search();
};
int Hash::hash(int num)
{
	int key;
	key = num % 5;
	return key;
}
void Hash::insertwor(Customer c)
{
	int key, flag = 0, j = 0;
	while (j < 5)
	{
		cout << "Enter Customer ID: ";
		cin >> c.id;
		cout << "Enter Customer Name: ";
		cin >> c.name;
		cout << "Enter Customer Telephone Number: ";
		cin >> c.teleno;
		key = hash(c.id);
		if (id[key] == -1)
		{
			id[key] = c.id;
			t[key] = c.teleno;
			n[key] = c.name;
		}
		else
		{
			for (int i = key + 1; i < max; i++)
			{
				if (id[i] == -1)
				{
					id[i] = c.id;
					t[i] = c.teleno;
					n[i] = c.name;
					flag = 1;
					break;
				}
			}
			for (int i = 0; (i < key && flag == 0); i++)
			{
				if (id[i] == -1)
				{
					id[i] = c.id;
					t[i] = c.teleno;
					n[i] = c.name;
					flag = 1;
					break;
				}
			}
		}
		j++;
	}
}
void Hash::insertwr(Customer c)
{
	int key, flag = 0, j = 0, temp;
	string a, b;
	while (j < max)
	{
		cout << "Enter Customer ID: ";
		cin >> c.id;
		cout << "Enter Customer Name: ";
		cin >> c.name;
		cout << "Enter Customer Telephone Number: ";
		cin >> c.teleno;
		key = hash(c.id);
		if (id[key] == -1)
		{
			id[key] = c.id;
			n[key] = c.name;
			t[key] = c.teleno;
		}
		else if (id[key] != -1 && hash(id[key]) == key)
		{
			for (int i = key + 1; i < max; i++)
			{
				if (id[i] == -1)
				{
					id[i] = c.id;
					n[i] = c.name;
					t[i] = c.teleno;
					flag = 1;
					break;
				}
			}
			for (int i = 0; (i < key && flag == 0); i++)
			{
				if (id[i] == -1)
				{
					id[i] = c.id;
					n[i] = c.name;
					t[i] = c.teleno;
					flag = 1;
					break;
				}
			}
		}
		else if (id[key] != -1 && (hash(id[key]) != key))
		{
			temp = id[key];
			a = n[key];
			b = t[key];
			id[key] = c.id;
			n[key] = c.name;
			t[key] = c.teleno;
			for (int i = key + 1; i < max; i++)
			{
				if (id[i] == -1)
				{
					id[i] = temp;
					n[i] = a;
					t[i] = b;
					flag = 1;
					break;
				}
			}
			for (int i = 0; (i < key); i++)
			{
				if (id[i] == -1)
				{
					id[i] = temp;
					n[i] = a;
					t[i] = b;
					flag = 1;
					break;
				}
			}
		}
		j++;
	}
}
void Hash::search()
{
	int x;
	cout << "Enter Customer ID: ";
	cin >> x; static int count = 0;
	int key = hash(x);
	if (id[key] == x)
	{
		count++;
		cout << "Customer Name   : " << n[key] << endl;
		cout << "Telephone Number: " << t[key] << endl;
		cout << "Customer ID     : " << id[key] << endl;
		cout << "No of comparisons: " << count << endl;
		cout << endl; count = 0;
		cout << endl;
	}
	else
	{
		for (int i = key + 1; i < max; i++)
		{
			count++;
			if (id[i] == x)
			{
				count++;
				cout << "Customer Name   : " << n[i] << endl;
				cout << "Telephone Number: " << t[i] << endl;
				cout << "Customer ID     : " << id[i] << endl;
				cout << "No of comparisons: " << count << endl;
				cout << endl;
				count = 0;
				cout << endl;
				break;
			}
		}
		for (int i = 0; i < key; i++)
		{
			count++;
			if (id[i] == x)
			{
				count++;
				cout << "Customer Name   : " << n[i] << endl;
				cout << "Telephone Number: " << t[i] << endl;
				cout << "Customer ID     : " << id[i] << endl;
				cout << "No of comparisons: " << count << endl;
				cout << endl;
				count = 0;
				cout << endl;
				break;
			}
		}
	}
}
void Hash::display()
{
	for (int i = 0; i < max; i++)
	{
		cout << "Customer Name   : " << n[i] << endl;
		cout << "Telephone Number: " << t[i] << endl;
		cout << "Customer ID     : " << id[i] << endl;
	}
}
int main()
{
	Hash h;
	Customer c1;
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
				h.insertwr(c1);
				break;
			case 2:
				h.insertwor(c1);
				break;
			default:
				cout << "Wrong choice" << endl;
				break;
			}
			break;
		case 2:
			h.display();
			break;
		case 3:
			h.search();
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

