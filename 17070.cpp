#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int N;
vector<vector<int>> graph;
vector<vector<vector<int>>> cache;

enum class PipeType
{
    Horizontal = 0,
    Diagonal,
    Vertical,
};

struct Pipe
{
    int row;
    int col;
    PipeType type;

    Pipe(int _row, int _col, PipeType _type)
    : row(_row), col(_col), type(_type)
    {}

    pair<int, int> GetPipeTip() const
    {
        pair<int, int> ret;
        switch(type)
        {
            case PipeType::Horizontal:
                ret = {row, col + 1};
                break;
            case PipeType::Diagonal:
                ret = {row + 1, col + 1};
                break;
            case PipeType::Vertical:
                ret = {row + 1, col};
                break;
        }
        return ret;
    }

    bool CheckValid()
    {
        pair<int, int> tip = GetPipeTip();
        for(int i = row; i <= tip.first; ++i)
        {
            for(int j = col; j <= tip.second; ++j)
            {
                if(graph[i][j] == 1)
                    return false;
            }
        }
        return true;
    }
};

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
    cin >> N;
    cin.ignore();
    graph = vector<vector<int>>(N + 2, vector<int>(N + 2, 1));
    cache = vector<vector<vector<int>>>(N + 2, vector<vector<int>>(N + 2, vector<int>(3, -1)));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            int num;
            cin >> num;
            graph[i][j] = num;
        }
        cin.ignore();
    }
}

int GetPipeMove(Pipe pipe)
{
    if(!pipe.CheckValid()) return 0;
    int type_num = static_cast<int>(pipe.type);
    int& ret = cache[pipe.row][pipe.col][type_num];
    if(ret != -1) return ret;
    pair<int, int> tip = pipe.GetPipeTip();
    if(tip.first == N && tip.second == N) 
    {
        ret = 1;
        return ret;
    };
    ret = 0;
    for(int i = max(0, type_num - 1); i <= min(2, type_num + 1); ++i)
    {
        ret += GetPipeMove(Pipe(tip.first, tip.second, static_cast<PipeType>(i)));
    }
    return ret;
}


void Solution()
{
    Input();
    Pipe pipe(1, 1, PipeType::Horizontal);
    int result = GetPipeMove(pipe);
    cout << result << endl;
}