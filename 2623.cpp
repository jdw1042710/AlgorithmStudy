#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin.ignore();
    Solution();
}

void Solution()
{
    vector<vector<int>> graph = vector<vector<int>>(N + 1, vector<int>());
    queue<int> pq;
    vector<int> inDegree = vector<int>(N + 1, 0);

    for(int i = 0; i < M; ++i)
    {
        int len;
        cin >> len;
        vector<int> inputs;
        for(int j = 0; j < len; ++j)
        {
            int num;
            cin >> num;
            inputs.push_back(num);
        }
        cin.ignore();
        for(int j = 1; j < inputs.size(); ++j)
        {
            int a = inputs[j - 1], b = inputs[j];
            graph[a].push_back(b);
            ++inDegree[b];
        }
    }
    for(int i = 1; i <= N; ++i)
    {
        if(inDegree[i] == 0)
            pq.push(i);
    }
    vector<int> result;
    while(!pq.empty())
    {
        int num = pq.front();
        pq.pop();
        result.push_back(num);
        for(auto adj : graph[num])
        {
            --inDegree[adj];
            if(inDegree[adj] == 0)
                pq.push(adj);
        }

    }
    if(result.size() == N)
    {
        for(auto num : result) 
        {
            cout << num << '\n';
        }
    }
    else
    {
        cout << '0';
    }
}
