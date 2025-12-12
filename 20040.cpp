#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> parents; // 각 노드의 상위노드

void Input();
void Solution();

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

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> M;
    cin.ignore();

    parents = vector<int>(N);
    for(int i = 0; i < N; ++i)
    {
        parents[i] = i;
    }
}

void Solution()
{
    Input();
    int result = 0;
    for(int i = 0; i < M; ++i)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        cin.ignore();

        if(GetParent(nodeA) == GetParent(nodeB))
        {
            result = i + 1; // 현재 차례
            break;
        }
        Merge(nodeA, nodeB);
    }

    cout << result << endl;
}