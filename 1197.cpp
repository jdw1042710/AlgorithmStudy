#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct edge{
    pair<int, int> node;
    long long val;
};

struct cmp{
    bool operator()(edge l, edge r){
        return l.val > r.val;
    }
};

int findParent(int a, const vector<int>& nodes){
    if (nodes[a] == a){
        return a;
    }
    return findParent(nodes[a], nodes);
}

bool isCycle(const edge& e, const vector<int>& nodes){
    int p1 = findParent(e.node.first, nodes);
    int p2 = findParent(e.node.second, nodes);
    //cout << "Cycle 여부 : " << p1 == p2 << endl;
    return p1 == p2;
}

void merge(int a, int b, vector<int>& nodes){
    int p1 = findParent(a, nodes);
    int p2 = findParent(b, nodes);
    nodes[p2] = p1;
}

int main(){
    int V, E, cnt = 0;
    long long sum = 0;
    cin >> V >> E;
    cin.ignore();
    vector<int> nodes(V + 1);
    priority_queue<edge, vector<edge>, cmp> pq;
    for(int i = 1; i < V + 1; i++){
        nodes[i] = i;
    }
    for (int i = 0; i < E; i++){
        long long a, b, c;
        edge temp;
        cin >> a >> b >> c;
        cin.ignore();
        temp = {{a, b}, c};
        pq.push(temp);
    }
    while(cnt < V - 1){
        edge min_edge = pq.top();
        /*
        cout << ""<< "선택된 노드 (" << nodes.size() << "개) : ";
        for(auto i : nodes){
            cout << i << " ";
        }
        cout << endl;
        cout << min_edge.node.first << " " << min_edge.node.second << endl; 
        */
        pq.pop();
        if(!isCycle(min_edge, nodes)){
            merge(min_edge.node.first, min_edge.node.second, nodes);
            sum += min_edge.val;
            cnt++;
        }
        /*
        string ss;
        getline(cin,ss);
        */
    }
    cout << sum << endl;
}
