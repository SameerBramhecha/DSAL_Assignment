/*Represent a given graph using adjacency list to perform DFS and BFS.
Use the map of the area around the college as the graph.
Identify the prominent landmarks as nodes and perform DFS
and BFS on that.*/
#include <iostream>
#define size 20
using namespace std;
class node
{
	int x;
	//string name;
	node* next;
public:
	node(int x)
	{
		this->x = x;
		//name = n;
		next = NULL;
	}
	friend class Graph;
};
class Queue
{
	int front, rear;
	int q[size];
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	bool isempty();
	bool isfull();
	void enqueue(int);
	int dequeue();
};
bool Queue::isempty()
{
	if (rear == -1 && front == -1)
	{
		return true;
	}
	return false;
}
bool Queue::isfull()
{
	if (rear == size - 1)
	{
		return true;
	}
	return false;
}
void Queue::enqueue(int s)
{
	if (isfull())
	{
		cout << "\nOveflow condition!!" << endl;
		return;
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
		q[front] = s;
	}
	else
	{
		rear++;
		q[rear] = s;
	}
}
int Queue::dequeue()
{
	int r;
	if (isempty())
	{
		cout << "\nUnderflow condition!!" << endl;
	}
	else
	{
		if (front == rear)
		{
			r = q[front];
			front = rear = -1;
		}
		else
		{
			r = q[front];
			front++;
		}
		return r;
	}
}
class Graph
{
	node* adjlist[10];
	int v, e;
	string name[10];
	bool* visited;
	bool* visited1;
public:
	Graph(int v, int e)
	{
		this->v = v;
		this->e = e;
		visited = new bool[v];
		visited1 = new bool[v];
		for (int i = 0; i < v; i++)
		{
			adjlist[i] = NULL;
			visited[i] = false;
			visited1[i] = false;

		}
	}
	void read();
	void display();
	void DFS(int);
	void BFS(int);
};
void Graph::read()
{
	int s, d,n;
	string n1, n2;
	cout << "Enter No of Landmarks: " << endl;
	cin >> n;
	cout << "Enter Name of Landmarks: ";
	for (int i = 0; i < n; i++)
	{
		cin >> name[i];
	}
	for (int i = 0; i < e; i++)
	{
		cout << "Enter source and destination : " << endl;
		cin >> n1 >> n2;
		for (int i = 0; i < n; i++)
		{
			if (n1 == name[i])
			{
				s = i;
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (n2 == name[i])
			{
				d = i;
				break;
			}
		}
		node* t1 = new node(s);
		node* t2 = new node(d);
		if (adjlist[s] == NULL)
		{
			adjlist[s] = t1;
			adjlist[s]->next = t2;
		}
		else
		{
			node* head = adjlist[s];
			while (head->next != NULL)
			{
				head = head->next;
			}
			head->next = t2;
		}
	}
}


void Graph::display()
{
	node* temp;
	for (int i = 0; i < v; i++)
	{
		temp = adjlist[i];
		while (temp != NULL)
		{
			cout << name[temp->x] << "-> ";
			temp = temp->next;
		}
		cout << endl;
	}
}
void Graph::DFS(int s)
{
	string n;
	visited[s] = true;
	node* temp = adjlist[s];
	cout << name[s]<<"-> ";
	while (temp != NULL)
	{
		s = temp->x;
		if (!visited[s])
		{
			DFS(s);
		}
		temp = temp->next;
	}
}
void Graph::BFS(int s)
{
	Queue q;
	visited1[s] = true;
	q.enqueue(s);
	node* head;
	while (!q.isempty())
	{
		s = q.dequeue();
		cout << name[s] << "-> ";
		head = adjlist[s];
		for (head; head != NULL; head = head->next)
		{
			if (!visited1[head->x])
			{
				q.enqueue(head->x);
				visited1[head->x] = true;
			}
		}
	}
}
int main()
{
	int ne, nv;
	cout << "Enter number of vertices: ";
	cin >> nv;
	cout << "\nEnter number of edges: ";
	cin >> ne;
	cout << endl;
	Graph g(nv, ne);
	int n;
	char choice;
	do
	{
		cout << "\n----------Menu----------" << endl;
		cout << "1.Read the Graph" << endl;
		cout << "2.Display the graph" << endl;
		cout << "3.DFS Traversal" << endl;
		cout << "4.BFS Traversal" << endl;
		cout << "Enter your choice: ";
		cin >> n;
		switch (n)
		{
		case 1:
			g.read();
			break;
		case 2:
			g.display();
			break;
		case 3:
			cout << "DFS traversal" << endl;
			g.DFS(0);
			break;
		case 4:
			cout << "\nBFS traversal" << endl;
			g.BFS(0);
			break;
		default:
			cout << "\nEnter correct choice!!" << endl;
			break;
		}
		cout << "\nDo you want to continue?(y/n): ";
		cin >> choice;
	} while (choice == 'y');
	return 0;
}

