#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


size_t N, M;
vector<vector<int>> graph;
pair<int, int> shark_pos;
int shark_size = 2;
void Input();
void Solution();

struct BFSItem
{
    int distance;
    int row;
    int col;
    BFSItem(int _distance, int _row, int _col)
    : distance(_distance), row(_row), col(_col) {}
    BFSItem(int _distance, pair<int, int> _pos)
    : distance(_distance), row(_pos.first), col(_pos.second) {}

    
};

struct CompareBFSItem
{
    bool operator()(const BFSItem& lhs, const BFSItem& rhs)
    {
        if(lhs.distance != rhs.distance)
        {
            return lhs.distance < rhs.distance;
        }
        if(lhs.row != rhs.row)
        {
            return lhs.row < rhs.row;
        }
        return lhs.col < rhs.col;
    }
};


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
    graph = vector<vector<int>>(N + 2, vector<int>(N + 2, -1));
    for(size_t i = 1; i <= N; ++i)
    {
        for(size_t j = 1; j <= N; ++j)
        {
            int val;
            cin >> val;
            if(val == 9)
            {
                shark_pos = {i, j};
                val = 0;
            }
            graph[i][j] = val;
        }
        cin.ignore();
    }
}

int dirR[] = {-1, 0, 0, 1};
int dirC[] = {0, -1, 1, 0};
vector<BFSItem> FindEatableFish(pair<int, int> shark_pos, int shark_size, const vector<vector<int>>& graph)
{
    vector<BFSItem> ret;
    vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
    // priority_queue<BFSItem, vector<BFSItem>, CompareBFSItem> pq;
    queue<BFSItem> q;
    visited[shark_pos.first][shark_pos.second] = true;
    q.push(BFSItem(0, shark_pos));
    while(!q.empty())
    {
        int cur_dis = q.front().distance;
        int cur_row = q.front().row;
        int cur_col = q.front().col;
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int next_row = cur_row + dirR[i];
            int next_col = cur_col + dirC[i];
            if(visited[next_row][next_col]) continue;
            if(graph[next_row][next_col] == -1) continue;
            if(graph[next_row][next_col] > shark_size) continue;
            if(graph[next_row][next_col] != 0
            && graph[next_row][next_col] < shark_size)
            {
                ret.push_back(BFSItem(cur_dis + 1 ,next_row, next_col));
            }
            visited[next_row][next_col] = true;
            q.push(BFSItem(cur_dis + 1 ,next_row, next_col));
        }
    }
    return ret;
}

void PrintGraph()
{
    static int iter = 1;
    cout << "Iter : " << iter++ << ", Size : " << shark_size << endl;
    for(size_t i = 1; i <= N; ++i)
    {
        for(size_t j = 1; j <= N; ++j)
        {
            if(shark_pos.first == static_cast<int>(i) && shark_pos.second == (int)j)
            {
                cout << "9 ";
                continue;
            }
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}

int GetResult()
{
    int result = 0;
    int eaten_fish = 0;
    vector<BFSItem> fishes = FindEatableFish(shark_pos, shark_size, graph);
    while(fishes.size() > 0)
    {
        sort(fishes.begin(), fishes.end(), CompareBFSItem());
        result += fishes.front().distance;
        graph[fishes.front().row][fishes.front().col] = 0;
        shark_pos = {fishes.front().row, fishes.front().col};
        
        // PrintGraph();
        
        ++eaten_fish;
        if(eaten_fish == shark_size)
        {
            eaten_fish = 0;
            ++shark_size;
        }
        fishes = FindEatableFish(shark_pos, shark_size, graph);
    }
    return result;
}

void Solution()
{
    Input();
    vector<int> indexes;
    int result = GetResult();
    cout << result << endl;
}