#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<pair<int, int>> coord[3];
vector<pair<long long, pair<int ,int>>> edges;

vector<int> parents;

void Input();
void Solution();


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
    coord[0] = vector<pair<int, int>>(N);
    coord[1] = vector<pair<int, int>>(N);
    coord[2] = vector<pair<int, int>>(N);
    parents = vector<int>(N);
    for(int i = 0; i < N; ++i)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        cin.ignore();

        coord[0][i] = {x, i};
        coord[1][i] = {y, i};
        coord[2][i] = {z, i};

        parents[i] = i;
    }
    sort(coord[0].begin(), coord[0].end());
    sort(coord[1].begin(), coord[1].end());
    sort(coord[2].begin(), coord[2].end());
    edges.clear();
    for(int i = 0; i < N - 1; ++i)
    {
        for(int j = 0; j < 3; ++j)
            edges.push_back({coord[j][i + 1].first - coord[j][i].first ,{coord[j][i].second, coord[j][i + 1].second}});
    }
    sort(edges.begin(), edges.end());
}

int GetParent(int node)
{
    if(parents[node] == node)
        return node;
    return GetParent(parents[node]);
}

int Merge(int lNode, int rNode)
{
    int lParent, rParent;
    lParent = GetParent(lNode);
    rParent = GetParent(rNode);
    if(lParent > rParent)
        swap(lParent, rParent);
    parents[rParent] = lParent;
    return lParent;
}

void Solution()
{
    Input();
    int num_of_edges = 0;
    long long min_cost = 0;
    size_t index = 0;
    while(num_of_edges < N - 1 && index < edges.size())
    {
        long long length = edges[index].first;
        int nodeA = edges[index].second.first;
        int nodeB = edges[index].second.second;
        int parentA = GetParent(nodeA);
        int parentB = GetParent(nodeB);
        if(parentA != parentB)
        {
            min_cost += length;
            Merge(parentA, parentB);
            ++num_of_edges;
        }
        ++index;
    }
    cout << min_cost << endl;
}