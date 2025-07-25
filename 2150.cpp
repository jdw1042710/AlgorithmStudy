#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int V, E, id;
vector<vector<int>> adjacent, groups;
vector<int> parents;
vector<bool> finished;
stack<int> st;

void Input();
void Solution();

int DFS(int cur)
{
    parents[cur] = ++id;
    st.push(cur);

    int parent = parents[cur];
    for(auto next : adjacent[cur])
    {
        if(parents[next] == 0)
        {
            parent = min(parent, DFS(next));
        }
        else if(!finished[next])
        {
            parent = min(parent, parents[next]);
        }
    }

    if(parent == parents[cur])
    {
        vector<int> scc;
        while(true)
        {
             int vertex = st.top();
             st.pop();

             scc.push_back(vertex);
             finished[vertex] = true;

             if(vertex == cur)
                break;
        }

        sort(scc.begin(), scc.end());
        groups.push_back(scc);
    }

    return parent;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> V >> E;
    cin.ignore();
    adjacent = vector<vector<int>>(V + 1);
    parents = vector<int>(V + 1, 0);
    for(int i = 0; i < E; ++i)
    {
        int from, to;
        cin >> from >> to;
        cin.ignore();
        adjacent[from].push_back(to);
    }
    for(int i = 1; i < V + 1; ++i)
    {
        sort(adjacent[i].begin(), adjacent[i].end());
    }
}

void Solution()
{
    Input();
    finished = vector<bool>(V + 1, false);
    st = stack<int>();
    id = 0;
    for(int i = 1; i < V + 1; ++i)
    {
        if(parents[i] == 0)
            DFS(i);
    }
    sort(groups.begin(), groups.end());
    cout << groups.size() << '\n';
    for(size_t i = 0; i < groups.size(); ++i)
    {
        for(auto element : groups[i])
        {
            cout << element << ' ';
        }
        cout << -1 << '\n';
    }
}