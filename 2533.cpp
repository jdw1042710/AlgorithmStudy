#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> adj;
vector<vector<int>> tree;
vector<vector<int>> cache;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

/** 데이터 입력 및 전처리*/
void Input()
{
    cin >> N;
    cin.ignore();
    adj = vector<vector<int>>(N);
    tree = vector<vector<int>>(N);
    for(int i = 0; i < N - 1; ++i)
    {
        int from, to;
        cin >> from >> to;
        cin.ignore();
        --from; --to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

/**
 * 트리 생성
 * @param root 루트 노드
*/
void MakeTree(int root, vector<bool>& visited)
{
    visited[root] = true;
    for(const auto& next: adj[root])
    {
        if(visited[next]) continue;
        tree[root].push_back(next);
        MakeTree(next, visited);
    }
}

/** 
 * DP를 이용한 DFS 
 * @param node 탐색하고 있는 트리 상의 현재 노드
 * @param flag 현재 노드가 얼리어뎁터인지 여부 (true : 1, false : 0)
 * @return 현재 상태에서 얻을 수 있는 최소 얼리어뎁터의 수
 */
int DFS(int node, int flag)
{
    int& ret = cache[node][flag];
    if(ret != -1) return ret;
    ret = flag;
    for(const auto& next : tree[node])
    {
        ret += flag ? min(DFS(next, 1), DFS(next, 0)): DFS(next, 1);
    }
    return ret;
}

/** 문제 풀이*/
void Solution()
{
    Input();
    vector<bool> visited(N, false);
    MakeTree(0, visited);
    cache = vector<vector<int>>(N, vector<int>(2, -1));
    int result = min(DFS(0, 0), DFS(0, 1));
    cout << result << endl;
}