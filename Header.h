#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;


class Graph
{
	int N_vertex;
	vector <int>* Smeg; // списки смежности будем хранить в этом массиве
  public:
	  Graph(int V)
	  {
      this->num_vert = V;
		  Smeg = new vector <int>[V];
	  }

	  ~Graph()
	  {
		  delete[] Smeg;
	  }

	  void Add_edge(int u, int v);
	  void Print();
    void Coloring();
};
