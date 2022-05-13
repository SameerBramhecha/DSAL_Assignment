/*Write a C++/Java program to implement topological sorting on graph using object
oriented programming features Design necessary class. .( Use of graph)
*/
#include <iostream>
using namespace std;
class Queue
{

public:
	int front, rear;
	int q[20];
	Queue()
	{
		front = -1;
		rear = -1;
	}
	void enqueue(int vertex, int ver)
	{
		if (rear == ver)
		{
			cout << "Queue OverFlow!!\n";
		}
		else
		{
			if (front == -1)
			{
				front = 0;
			}
			rear += 1;
			q[rear] = vertex;
		}
	}
	int delqueue()
	{
		int x;
		if (front == -1 || front > rear)
		{
			cout << "Queue UnderFlow!!\n";
			return -1;
		}
		else
		{
			x = q[front];
			front += 1;
			return x;
		}
	}
};
class TopoSort
{
	int a[20][20];
	int indegree[20];
	int b[20];
public:
	TopoSort(int ver)
	{
		for (int i = 0; i < ver; i++)
		{
			for (int j = 0; j < ver; j++)
			{
				a[i][j] = 0;
			}
		}
		for(int i=0;i<ver;i++)
		{
			indegree[i] = -99;
		}
	}
	void read(int);
	void addedge(int, int);
	void display(int);
	int indegree_calc(int x, int n);
	void toposort(int n);
};
void TopoSort::read(int e)
{
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cout << "Enter source and destination vertex: " << endl;
		cin >> u >> v;
		addedge(u, v);
	}
}
void TopoSort::addedge(int u, int v)
{
	a[u][v] = 1;
}
void TopoSort::display(int ver)
{
	for (int i = 0; i < ver; i++)
	{
		for (int j = 0; j < ver; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
int TopoSort::indegree_calc(int x, int n)
{
	int v1, indegree = 0;
	for (v1 = 0; v1 < n; v1++)
	{
		if (a[v1][x] == 1)
		{
			indegree++;
		}
	}
	return indegree++;
}
void TopoSort::toposort(int n)
{
	Queue q;
	int i, j, k;
	j = 0;
	for (i = 0; i < n; i++)
	{
		indegree[i] = indegree_calc(i, n);
		if (indegree[i] == 0)
		{
			q.enqueue(i, n);
		}
	}
	while (q.front <= q.rear)
	{
		k = q.delqueue();
		b[j++] = k;
		for (i = 0; i < n; i++)
		{
			if (a[k][i] == 1)
			{
				a[k][i] = 0;
				indegree[i] -= 1;
				if (indegree[i] == 0)
				{
					q.enqueue(i, n);
				}
			}
		}
	}
	cout << "Topological sorting of Graph: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << b[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int ver, e;
	cout << "Enter No of Vertices: ";
	cin >> ver;
	cout << "Enter no of edges: ";
	cin >> e;
	TopoSort t(ver);
	t.read(e);
	t.display(ver);
	t.toposort(ver);
}
