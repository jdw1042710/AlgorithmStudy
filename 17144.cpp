#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int R, C, T;
vector<vector<int>> graph;
vector<int> row_of_air_cleaner;
int num_of_dust = 0;

int dirR[] = {0, 1, 0, -1};
int dirC[] = {1, 0, -1, 0};

void Input();
void Solution();


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> R >> C >> T;
    cin.ignore();
    graph = vector<vector<int>>(R, vector<int>(C, 0));
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            int num;
            cin >> num;
            graph[i][j] = num;
            if(num == -1)
            {
                row_of_air_cleaner.push_back(i);
            }
            else
            {
                num_of_dust += num;
            }
        }
        cin.ignore();
    }
}

bool CheckValid(int row, int col)
{
    if(row < 0 || row >= R || col < 0 || col >= C)
        return false;
    if(graph[row][col] == -1) 
        return false;
    return true;
}

void Spread(int row, int col, int exDust, vector<vector<int>>& graph)
{
    int spreadedDust = exDust / 5;
    for(int i = 0; i < 4; ++i)
    {
        int adjRow = row + dirR[i];
        int adjCol = col + dirC[i];
        if(CheckValid(adjRow, adjCol))
        {
            graph[adjRow][adjCol] += spreadedDust;
            graph[row][col] -= spreadedDust;
        }
    }
}

void Circulate(int row, bool clockwise, vector<vector<int>>& graph)
{
    int col = 0;
    int dir = 0;
    int moved_dust = 0;
    while(dir < 4)
    {
        int next_row = row + dirR[dir] * (clockwise ? 1 : -1);
        int next_col = col + dirC[dir];
        if(!CheckValid(next_row, next_col))
        {
            ++dir;
            continue;
        }
        swap(moved_dust, graph[next_row][next_col]);
        row = next_row;
        col = next_col;
    }
    num_of_dust -= moved_dust;
}

// void Print()
// {
//     static int time = 0;
//     cout << (time % 2 == 0 ? "Spreaded, " : "Circulated, ") << "time : " << time / 2 << endl;
//     time++;
//     for(int i = 0; i < R; ++i)
//     {
//         for(int j = 0; j < C; ++j)
//         {
//             cout.width(2);
//             cout.fill(' ');
//             cout << graph[i][j] << ' ';
//         }
//         cout << endl;
//     }
// }

void Simulate()
{
    vector<vector<int>> exGraph(graph);
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            if(graph[i][j] > 0)
                Spread(i, j, exGraph[i][j], graph);
        }
    }
    // Print();
    Circulate(row_of_air_cleaner[0], false, graph);
    Circulate(row_of_air_cleaner[1], true, graph);
    // Print();
}

void Solution()
{
    Input();
    for(int i = 0; i < T; ++i)
    {
        Simulate();
    }
    cout << num_of_dust << endl;
}