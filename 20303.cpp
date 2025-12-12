#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, K;
int maxId;

vector<long long> candies; // 각 노드 + 하위노드들의 캔디 수의 합
vector<long long> groupOfCandies;
// vector<int> people; // 각 노드 + 하위노드들의 수
vector<int> groupOfPeople;
vector<int> parents; // 각 노드의 상위 노드

vector<vector<long long>> cache;

void Input();
void Solution();



int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

/** 각 노드들의 최상위 노드를 반환*/
int GetParent(int node)
{
    if(node == parents[node]) return node;
    return parents[node] = GetParent(parents[node]);
}

/** 두 노드를 하나의 그래프로 합침*/
void Merge(int nodeA, int nodeB)
{
    int parentA = GetParent(nodeA);
    int parentB = GetParent(nodeB);
    if(parentA > parentB)
        swap(parentA, parentB);
    parents[parentB] = parentA;
}

void Input()
{
    cin >> N >> M >> K;
    cin.ignore();
    candies = vector<long long>(N);
    // people = vector<int>(N, 1);
    parents = vector<int>(N);
    for(int i = 0; i < N; ++i)
    {
        int candy;
        cin >> candy;
        candies[i] = candy;
        parents[i] = i;
    }
    cin.ignore();

    maxId = N;
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        cin.ignore();
        Merge(a, b);
    }

    vector<vector<int>> friends(N);
    vector<int> nodes;
    for(int i = 0; i < N; ++i)
    {
        int parent = GetParent(i);
        friends[parent].push_back(i);
        nodes.push_back(parent);
    }
    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
    groupOfCandies.push_back(0); // 캐싱시 인덱싱을 위한 빈 공간
    groupOfPeople.push_back(0); // 캐싱시 인덱싱 위한 빈 공간
    for(auto node : nodes)
    {
        long long sumOfCandies = 0;
        for(auto f : friends[node])
        {
            sumOfCandies += candies[f];
        }
        groupOfCandies.push_back(sumOfCandies);
        groupOfPeople.push_back(friends[node].size());
    }
    maxId = groupOfCandies.size() - 1;
}


// /** DFS와 캐싱을 이용한 가질 수 있는 캔디 값의 최대치를 구하는 함수*/
// long long GetMaxCandies(int node, int crying)
// {
//     if(node == maxId) return 0;
//     long long& ret = cache[node][crying];
//     if(ret != -1) return ret;
//     ret = 0;
//     if(crying + groupOfPeople[node] < K)
//         ret = groupOfCandies[node] + GetMaxCandies(node + 1, crying + groupOfPeople[node]);
//     ret = max(ret, GetMaxCandies(node + 1, crying));
//     return ret;
// }

void Solution()
{
    Input();
    cache = vector<vector<long long>>(maxId + 1, vector<long long>(K + 1, 0));
    // long long result = GetMaxCandies(0, 0);
    for(int i = 1; i <= maxId; ++i)
    {
        for(int j = 0; j <= K; ++j)
        {
            cache[i][j] = cache[i - 1][j];
            if(groupOfPeople[i] < j)
                cache[i][j] = max(cache[i][j], cache[i - 1][j - groupOfPeople[i]] + groupOfCandies[i]);
        }
    }
    long long result = cache[maxId][K];
    cout << result << endl;
}