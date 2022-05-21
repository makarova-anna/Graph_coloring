#include "Graph.h"


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


    int count = 0;
    int w = 0;
    set <int> used_column;  
    while (count < N_vertex)
    {
        for (w = 0; w< N_vertex; w++)
        {
            auto search = used_column.find(w);
            if (Smeg[w].size() == Size_smeg[count] && inside(used_column, w) == 0)
            {
                used_column.insert(w);
                break;
            }
            //cout << "nice" << endl;
        }

        auto iter = Smeg[w].begin();
        while (iter != Smeg[w].end())
        {
            if (Colors[*iter] != -1)
                is_available[Colors[*iter]];
            iter++;
        }
        //прроходим по всем веришнам, соединенным с i-й
        for (iter = Smeg[w].begin(); iter != Smeg[w].end(); iter++)  
            if (Colors[*iter] != -1)
                is_available[Colors[*iter]] = true;

        // Ищем первый доступный нам цвет
        int current;
        for (current = 0; current < N_vertex; current++)
            if (is_available[current] == false)
                break;

        Colors[w] = current; // добавляем в массив

        // Для следующей итерации меняем
        for (iter = Smeg[w].begin(); iter != Smeg[w].end(); iter++)
            if (Colors[*iter] != -1)
                is_available[Colors[*iter]] = false;

        count++;
        w = 0;
    }




}
