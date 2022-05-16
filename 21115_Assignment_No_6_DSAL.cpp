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
class Stack
{
	char top;
	int s[20];
	public:
		Stack()
		{
			top = -1;
		}
		void push(int p)
		{
			if (top == 19)
			{
				cout << "Stack is Full!!" << endl;
			}
			else
			{
				s[++top] = p;

			}
		}

		int pop()
		{
			int x;
			if (top == -1)
			{
				cout << "Stack is Empty" << endl;
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
			if (top == -1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

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
public:
	Graph(int v, int e)
	{
		this->v = v;
		this->e = e;
		visited = new bool[v];
		for (int i = 0; i < v; i++)
		{
			adjlist[i] = NULL;
			visited[i] = false;

		}
	}
	void read();
	void display();
	void DFS(int);
	void DFSr(int,Stack);
	void BFS(int);
};
void Graph::read()
{
	int s, d,n;
	string n1, n2;
	cout << "Enter Name of Landmarks: ";
	for (int i = 0; i < v; i++)
	{
		cin >> name[i];
	}
	for (int i = 0; i < e; i++)
	{
		cout << "Enter source and destination : " << endl;
		cin >> n1 >> n2;
		for (int i = 0; i < v; i++)
		{
			if (n1 == name[i])
			{
				s = i;
				break;
			}
		}
		for (int i = 0; i < v; i++)
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

	node* temp = adjlist[s];
	cout << name[s] << " -> ";
	visited[s] = true;
	for(temp;temp!=NULL;temp=temp->next)
	//while (temp != NULL)
	{
		s = temp->x;
		if (!visited[s])
		{
			DFS(s);
		}
		//temp = temp->next;
	}
}
void Graph::DFSr(int s, Stack st)
{
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	node* temp;
	cout << name[s] << " -> ";
	st.push(s);
	visited[s] = true;
	while (!st.isempty())
	{
		int a = st.pop();
		if (visited[a] == false)
		{
			cout << name[a] << " -> ";
			visited[a] = true;

		}
		temp = adjlist[a];
		while (temp != NULL)
		{
			if (visited[temp->x] == false)
			{
				//cout << name[temp->x] << " -> ";
				st.push(temp->x);
				//visited[temp->x] = true;

			}
			temp = temp->next;
		}
	}
}
void Graph::BFS(int s)
{
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	Queue q;
	visited[s] = true;
	q.enqueue(s);
	node* head;
	while (!q.isempty())
	{
		s = q.dequeue();
		cout << name[s] << " -> ";
		head = adjlist[s];
		for (head; head != NULL; head = head->next)
		{
			if (!visited[head->x])
			{
				q.enqueue(head->x);
				visited[head->x] = true;
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
	Stack st;
	int ch;
	while(true)
	{
		cout << "\n----------Menu----------" << endl;
		cout << "1.Read the Graph" << endl;
		cout << "2.Display the graph" << endl;
		cout << "3.DFS Traversal with recursion" << endl;
		cout << "4.DFS Traversal without Recursion" << endl;
		cout << "5.BFS Traversal" << endl;
		cout << "6.Exit " << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
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
			cout << endl;
			break;
		case 4:
			cout << "DFS traversal without recursion: " << endl;
			g.DFSr(0,st);
			break;
		case 5:
			cout << "\nBFS traversal" << endl;
			g.BFS(0);
			break;
		case 6:
			cout << "Code Exited" << endl;
			exit('0');
		default:
			cout << "\nEnter correct choice!!" << endl;
			break;
		}
	}
	return 0;
}

