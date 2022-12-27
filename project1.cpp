#include <iostream>

using namespace std;
const int maxV = 4;
int i, j, n;
int GR[maxV][maxV];

void Dijkstra(int GR[maxV][maxV], int start, int end)
{
    int distance[maxV], index, i;
    int visited[maxV];
    for (i = 0; i < maxV; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[start-1] = 0;
    for (i = 0; i < maxV - 1; i++)
    {
        int min = INT_MAX;
        for (i = 0; i < maxV; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i]; 
                index = i;
            }
        //u = index;
        visited[index] = 1;
        for (i = 0; i < maxV; i++)
            if (!visited[i] && GR[index][i] && distance[index] != INT_MAX &&
                distance[index] + GR[index][i] < distance[i])
                distance[i] = distance[index] + GR[index][i];
    }
    cout << "\nКратчайший путь (Дейкстра):\t\n";
    cout << distance[end - 1];
    /*for (i = 0; i < maxV; i++) if (distance[i] != INT_MAX)
        cout << m << " > " << i + 1 << " = " << distance[i] << endl;
    else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;*/
}

//алгоритм Флойда-Уоршелла
void FU(int D[maxV][maxV], int V, int start, int end)
{
    int k;
    for (i = 0; i < V; i++) D[i][i] = 0;

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (D[i][k] && D[k][j] && i != j)
                    if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
                        D[i][j] = D[i][k] + D[k][j];

    cout << "Кратчайший путь (Флойд):" << endl;
    cout << D[start - 1][end - 1];
    
    /*for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++) cout << D[i][j] << "\t";
        cout << endl;
    }*/
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Количество вершин в графе > "; 
    cin >> n;
    cout << "Введите матрицу весов ребер:\n";
    for (i = 0; i < n; i++) {
        GR[i][i] = 0;
        for (j = i + 1; j < n; j++)
        {
            int temp;
            cout << "GR[" << i + 1 << "][" << j + 1 << "] > ";
            cin >> temp;
            GR[i][j] = temp;
            GR[j][i] = temp;
        }
    }

    int start, end;
    cout << "Введите начальную и конечную вершины:\n";
    cin >> start >> end;

    FU(GR, n, start, end);
    //Dijkstra(GR, start, end);

    //cin >> n;
    //stoer_wagner(n);

    return 0;
}
