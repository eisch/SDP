#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::vector;

struct Vertex
{
	int number;
	vector<int> n;
	Vertex(int _v, vector<int> _n=vector<int>()) : number(_v), n(_n)
	{
	}
};

class Graph
{
	vector<Vertex> vs;
public:
	Graph(vector<Vertex> _vs = vector<Vertex>()) : vs(_vs) {}
	void addVertex(int v)
	{
		Vertex newV(v);
		vs.push_back(newV);
	}
	void addEdge(int a, int b)
	{
		for (Vertex &c : vs)
		{
			if (c.number == a)
			{
				c.n.push_back(b);
			}
		}
		for (Vertex &c : vs)
		{
			if (c.number == b)
			{
				c.n.push_back(a);
			}
		}
	}
	void dfs(int v, vector<int>& visited)
	{
		bool flag;
		visited.push_back(v);
		cout << v << "  ";
		for (Vertex c : vs)
		{
			if (c.number == v)
			{
				for (int w : c.n)
				{
					flag = false;
					for (int z : visited)
					{
						if (z == v)
						{
							flag = true;
							break;
						}
						dfs(w, visited);
					}
				}
			}
		}

	}
};
int main()
{
	
}
