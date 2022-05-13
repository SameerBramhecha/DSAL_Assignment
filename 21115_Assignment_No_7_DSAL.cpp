/*
You have a business with several offices; you want to lease
phone lines to connect them up with each other; and the
phone company charges different amounts of money to
connect different pairs of cities. You want a set of
lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate
data structures.
*/
#include<iostream>
using namespace std;
class PrimsMST
{
	int a[20][20];
	int b[20][20];
	string name[20];
public:
	PrimsMST()
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				a[i][j] = 0;
				b[i][j] = 0;
			}
		}
	}
	void read(int, int);
	void add_edge(int, int, int);
	void prims(int);
	void display(int);
};
void PrimsMST::read(int ver, int e)
{
	int u, v, w;
	string n1, n2;
	cout << "Enter Name of Landmarks: ";
	for (int i = 0; i < ver; i++)
	{
		cin >> name[i];
	}
	for (int i = 0; i < e; i++)
	{
		cout << "Enter enter source, destination and it's weight: ";
		cin >> n1 >> n2 >> w;
		for (int i = 0; i < ver; i++)
		{
			if (n1 == name[i])
			{
				u = i;
				break;
			}
		}
		for (int i = 0; i < ver; i++)
		{
			if (n2 == name[i])
			{
				v = i;
				break;
			}
		}
		add_edge(u, v, w);
	}

}
void PrimsMST::add_edge(int u, int v, int w)
{
	a[u][v] = w;
	a[v][u] = w;
}
void PrimsMST::display(int v)
{
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void PrimsMST::prims(int ver)
{
	int inf = 9999999; int cost = 0;
	bool selected[20];
	for (int i = 0; i < ver; i++)
	{
		selected[i] = false;
	}
	int no_edge = 0;
	int x, y;
	selected[0] = true;
	while (no_edge < (ver - 1))
	{
		int min = inf;
		x = 0; y = 0;
		for (int i = 0; i < ver; i++)
		{
			if (selected[i])
			{
				for (int j = 0; j < ver; j++)
				{
					if (!selected[j] && a[i][j])
					{
						if (min > a[i][j])
						{
							min = a[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		cout << name[x] << " - " << name[y] << " : " << a[x][y];
		b[x][y] = a[x][y];
		b[y][x] = a[x][y];
		cost = cost + a[x][y];
		cout << endl << endl;
		selected[y] = true;
		no_edge++;
	}
	cout << "MINIMUM SPANNING TREE:- " << endl;
	for (int i = 0; i < ver; i++)
	{
		for (int j = 0; j < ver; j++)
		{
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Minimum cost: " << cost << endl;
}
int main()
{
	PrimsMST p;
	int ver, e;
	cout << "Enter no. of vertices: " << endl;
	cin >> ver;
	cout << "Enter no. of edges: " << endl;
	cin >> e;
	p.read(ver, e);
	p.display(ver);
	p.prims(ver);
	return 0;
}

