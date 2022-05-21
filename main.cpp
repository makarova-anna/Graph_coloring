#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
	int N_vertex = 0;
	int M_edges = 0;
	int count = 0;
  string s;
  vector <int> one;
	vector <int> two;

  ifstream fin;
	fin.open("data/gc_4_1");

	while (!fin.eof())
	{
		count++;
		fin >> s;
		if (count == 1)
		{
			N_vertex = stoi(s); // строка в Z-число 
			M_edges = stoi(s);
		}
		else if (count > 2)
		{
			if (count % 2 == 1)
			{
				one.push_back(stoi(s));
			}
			else
				two.push_back(stoi(s));
		}
	}
  
  Graph MyGraph(N_vertex);
	for (int i = 0; i < M_edges; i++)
	{
     MyGraph.Add_edge(one[i], two[i]);
	}
  cout << "nicee";
	fin.close();

	return 0;
}
