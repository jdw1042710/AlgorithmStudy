#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
vector<int> parents;

struct Edge{
    pair<int, int> node;
    int val;
};

struct Compare{
    bool operator()(Edge l, Edge r){
        return l.val > r.val;
    }
};

int FindParent(int a){
    if (parents[a] == a){
        return a;
    }
    return FindParent(parents[a]);
}

bool IsCycle(const Edge& e){
    int p1 = FindParent(e.node.first);
    int p2 = FindParent(e.node.second);
    //cout << "Cycle 여부 : " << p1 == p2 << endl;
    return p1 == p2;
}

void Merge(int a, int b){
    int p1 = FindParent(a);
    int p2 = FindParent(b);
    if(p1 < p2)
    {
        parents[p1] = p2;
    }
    else
    {
        parents[p2] = p1;
    }
}

void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> V >> E;
    cin.ignore();
    parents = vector<int> (V + 1);
    for(int i = 1; i <= V; ++i){
        parents[i] = i;
    }
    Solution();
}

void Solution()
{
    priority_queue<Edge, vector<Edge>, Compare> pq;
    for (int i = 0; i < E; ++i)
    {
        int a, b, value;
        cin >> a >> b >> value;
        cin.ignore();
        pq.push({{a, b}, value});
    }
    int num_of_edges = 0;
    long long weight = 0;
    while(num_of_edges < V - 1)
    {
        Edge min_edge = pq.top();
        pq.pop();
        if(!IsCycle(min_edge)){
            Merge(min_edge.node.first, min_edge.node.second);
            weight += min_edge.val;
            ++num_of_edges;
        }
    }
    cout << weight;
}
