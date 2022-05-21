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
    for (int i = 1; i < N_vertex; i++)
        Colors[i] = -1;

    vector <bool> is_available(N_vertex); 
    for (int j = 0; j < N_vertex; j++)
        is_available[j] = false;

    vector <int> Size_smeg(N_vertex);
    for (int i = 0; i < N_vertex; i++)
        Size_smeg[i] = Smeg[i].size();

    sort(Size_smeg.begin(), Size_smeg.end(), std::greater<int>());
    

}
