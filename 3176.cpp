#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, K, LogN;
const int Root = 0;
const int MinValue = -1, MaxValue = 1'000'001;
vector<vector<pair<int, int>>> adjacency;
// [n][k] : n번 노드의 2^k번째 조상
vector<vector<int>> parents;
// [n][k] : n번 노드부터 2^k번째 조상까지의 경로가 있을 때, 그 경로를 구성하는 edge들의 최소 weight
vector<vector<int>> minWeight; 
// [n][k] : n번 노드부터 2^k번째 조상까지의 경로가 있을 때, 그 경로를 구성하는 edge들의 최대 weight
vector<vector<int>> maxWeight;
// [n] : n번째 노드의 depth (root : 0)
vector<int> depths;

void Input();
void Solution();
/** adjacency를 통해 DFS 탐색을 하며, 
 * depth[n], parent[n][0], minWeight[n][0], maxWeight[n][0]을 기록
*/
void MakeTree(int root, int depth, vector<bool>& visited);
/** 모든 노드의 parents, minWeight, maxWeight를 기록 */
void Connect();

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
    LogN = log2(N);
    adjacency = vector<vector<pair<int, int>>>(N);
    parents = vector<vector<int>>(N, vector<int>(LogN + 1));
    minWeight = vector<vector<int>>(N, vector<int>(LogN + 1, MaxValue));
    maxWeight = vector<vector<int>>(N, vector<int>(LogN + 1, MinValue));
    depths = vector<int>(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        cin.ignore();
        --from; --to;
        adjacency[from].push_back({to, weight});
        adjacency[to].push_back({from, weight});
    }

    vector<bool> visited(N);
    MakeTree(Root, 0, visited);
    Connect();
}

void MakeTree(int root, int depth, vector<bool>& visited)
{
    visited[root] = true;
    depths[root] = depth;
    for(const auto& next : adjacency[root])
    {
        if(visited[next.first]) continue;
        const int& nextNode = next.first;        
        const int& weight = next.second;

        parents[nextNode][0] = root;
        minWeight[nextNode][0] = maxWeight[nextNode][0] = weight;

        MakeTree(nextNode, depth + 1, visited);
    }
}

void Connect()
{
    for(int k = 1; k < LogN + 1; ++k)
    {
        for(int node = 0; node < N; ++node)
        {
            const auto& exParent = parents[node][k-1];
            parents[node][k] = parents[exParent][k - 1];

            const auto& exParentMin = minWeight[exParent][k-1];
            const auto& exMin = minWeight[node][k-1];
            minWeight[node][k] = min(exParentMin, exMin);
        
            const auto& exParentMax = maxWeight[exParent][k-1];
            const auto& exMax = maxWeight[node][k-1];
            maxWeight[node][k] = max(exParentMax, exMax);
        }
    }
}

/**
 * LCA를 이용하여 lNode와 rNode간의 경로상의 edge들에서 최소/최대 Weight를 찾는다.
*/

pair<int, int> FindMinMaxWithLCA(int lNode, int rNode)
{
    int resultMin = MaxValue;
    int resultMax = MinValue;

    // 항상 lNode의 depth가 크도록 유지
    if(depths[lNode] < depths[rNode])
        swap(lNode, rNode);
    
    // 두 노드의 depth를 일치 시키기
    int diff = depths[lNode] - depths[rNode];
    for(int k = 0; diff > 0; ++k)
    {
        if(diff % 2 == 1)
        {
            resultMin = min(resultMin, minWeight[lNode][k]);
            resultMax = max(resultMax, maxWeight[lNode][k]);
            lNode = parents[lNode][k];
        }
        diff >>= 1;
    }

    // 일치된 depth에서 희소배열을 사용해 공통조상을 탐색
    if(lNode != rNode)
    {
        for(int k = LogN; k >= 0; --k)
        {
            if(parents[lNode][k] == Root || parents[lNode][k] == parents[rNode][k])
                continue;
            resultMin = min(resultMin, minWeight[lNode][k]);
            resultMin = min(resultMin, minWeight[rNode][k]);

            resultMax = max(resultMax, maxWeight[lNode][k]);
            resultMax = max(resultMax, maxWeight[rNode][k]);

            lNode = parents[lNode][k];
            rNode = parents[rNode][k];
        }

        resultMin = min(resultMin, minWeight[lNode][0]);
        resultMin = min(resultMin, minWeight[rNode][0]);

        resultMax = max(resultMax, maxWeight[lNode][0]);
        resultMax = max(resultMax, maxWeight[rNode][0]);
    }

    return {resultMin, resultMax};
}

void Solution()
{
    Input();
    cin >> K;
    cin.ignore();
    for(int i = 0; i < K; ++i)
    {
        int from, to;
        cin >> from >> to;
        cin.ignore();
        --from; --to;
        auto result = FindMinMaxWithLCA(from, to);
        cout << result.first << ' ' << result.second << '\n';
    }
    // cout << endl;
}