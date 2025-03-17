#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;

struct Forest
{
    struct Edge{
        pair<int, int> node;
        int value;

        bool Compare(Edge l, Edge r)
        {
            return l.value > r.value;
        }
    };

    vector<int> parents, ranks;

    Forest(int n): parents(n), ranks(n, 1) 
    {
        for (int i = 0; i < n; ++i)
            parents[i] = i;
    }

    int FindParent(int a){
        if (parents[a] == a){
            return a;
        }
        return FindParent(parents[a]);
    }

    void Merge(int a, int b){
        int p1 = FindParent(a);
        int p2 = FindParent(b);
        if(p1 == p2) return;
        if(ranks[p1] > ranks[p2])
            swap(p1, p2);
        parents[p1] = p2;
        if(ranks[p1] == ranks[p2])
            ++ranks[p2];
    }
};

void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin.ignore();

    Solution();
}


void Solution()
{
    vector<int> least;
    vector<vector<int>> edges;
    for(int i = 0; i < M; ++i)
    {
        int from, to, value;
        cin >> from >> to >> value;
        cin.ignore();
        // 1 ~ N까지 들어오는 도시 번호를 0 ~ N-1로 내림
        --from;
        --to;
        if(from > to) 
            swap(from, to);
        edges.push_back({from, to, value});
    }
    Forest forest(N);
    long long weight = 0;
    int numOfTrees = N;
    int maxWeight = 0;
    while(numOfTrees > 1)
    {
        least = vector<int>(N , -1);
        for(int i = 0; i < edges.size(); ++i)
        {
            int p1 = forest.FindParent(edges[i][0]), p2 = forest.FindParent(edges[i][1]);
            if(p1 == p2) continue;
            // 각 노드에 연결된 엣지 중 최소 가중치를 가진 엣지를 저장한다. 
            if (least[p1] == -1 || edges[least[p1]][2] > edges[i][2])
                least[p1] = i;
                
            if (least[p2] == -1 || edges[least[p2]][2] > edges[i][2])
                least[p2] = i;
        }

        for(int i = 0; i < N; ++i)
        {
            int minEdge = least[i];
            if(minEdge == -1) continue;
            int p1 = forest.FindParent(edges[minEdge][0]), p2 = forest.FindParent(edges[minEdge][1]);
            // cout << "MinEdge:" << edges[minEdge][0] + 1 << '~'<< edges[minEdge][1] + 1 << ':' << edges[minEdge][2] << endl;
            if(p1 == p2) continue;
            forest.Merge(p1, p2);
            weight += edges[minEdge][2];
            maxWeight = max(maxWeight, edges[minEdge][2]);
            // cout << "Merge:" << edges[minEdge][0] + 1 << '~'<< edges[minEdge][1] + 1 << ':' << edges[minEdge][2] << endl;
            --numOfTrees;     
        }

    }
    weight -= maxWeight;
    cout << weight;
}
