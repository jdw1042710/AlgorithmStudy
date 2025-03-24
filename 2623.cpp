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

// 푸는중인 문제
void Solution()
{
    vector<vector<int>> graph = vector<vector<int>>(N + 1, vector<int>());
    priority_queue<int, vector<int>, greater<int>> pq;
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
    int mask = 0;
    while(!pq.empty())
    {
        int num = pq.top();
        pq.pop();
        for(auto adj : graph[num])
        {
            if(mask & (1 << num)) continue;
            --inDegree[adj];
            if(inDegree[adj] == 0)
                pq.push(adj);
        }
        result.push_back(num);
        mask |= (1 << num);
    }
    if(mask & (1 << (N + 1)) - 2)
    {
        for(auto num : result) cout << num << '\n';
    }
    else
    {
        cout << '0';
    }
}
