#include "Header.h"


void Graph::Add_edge(int u, int v)
{
    Smeg[u].push_back(v);
    Smeg[v].push_back(u);
}


void Graph::Print()
{
    for (int i = 0; i < N_vertex; i++)
    {
        cout << i << " columns: ";
        for (int j = 0; j < Smeg[i].size(); j++)
        {
            cout << Smeg[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::Coloring()
{
    vector <int> Colors(N_vertex);

    Colors[0] = 0;
}
