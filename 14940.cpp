#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

int n, m;

pair<int, int> dir[4] = 
{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

void MakeMap(vector<vector<int>>& map, vector<vector<long long>>& result, int& start_row, int& start_col);
void Solution(int start_row, int start_col, const vector<vector<int>>& map, vector<vector<long long>>& result);

void Split(string str, vector<int>& output)
{
    stringstream ss(str);
    string temp;
    while(getline(ss, temp, ' '))
    {
        output.push_back(stoi(temp));
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int start_row = -1, start_col = -1;
    vector<vector<int>> map;
    vector<vector<long long>> result;
    cin >> n >> m;
    cin.ignore();
    MakeMap(map, result, start_row, start_col);
    Solution(start_row, start_col, map, result);
}

void MakeMap(vector<vector<int>>& map, vector<vector<long long>>& result, int& start_row, int& start_col)
{
    result = vector<vector<long long>> (n, vector<long long>(m, -1));
    for(int i = 0; i < n; ++i)
    {
        string str_row;
        vector<int> row;
        getline(cin, str_row);
        Split(str_row, row);
        map.push_back(row);

        for(int j = 0; j < row.size(); ++j)
        {
            if(row[j] == 2)
            {
                start_row = i;
                start_col = j;
            }
            if(row[j] == 0)
            {
                result[i][j] = 0;
            }
        }
        
    }
}

void Solution(int start_row, int start_col, const vector<vector<int>>& map, vector<vector<long long>>& result)
{
    queue<pair<int, int>> next_q;
    next_q.push({start_row, start_col});
    long long step = 0;
    while(next_q.size() != 0)
    {
        queue<pair<int, int>> q;
        q = next_q;
        next_q = {};
        while(q.size() != 0)
        {
            int row, col;
            row = q.front().first;
            col = q.front().second;
            q.pop();
            if(row < 0 || n <= row || col < 0 || m <= col)
                continue;
            long long& num = result[row][col];
            if(map[row][col] == 0)
            {
                num = 0;
                continue;
            }
            if(num != -1)
            {
                continue;
            }
            num = step;
            for(int i = 0; i < 4; ++i)
            {
                next_q.push({row + dir[i].first, col + dir[i].second});  
            }
        
        }
        ++step;
    }
    for(auto row : result)
    {
        for(auto num : row)
        {
            cout << num << " ";
        }
        cout << '\n';
    }
    
}