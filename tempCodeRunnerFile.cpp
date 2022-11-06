#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

struct cmp{
bool operator()(pair<int, int> a, pair<int, int> b){
    if (a.second != b.second){
        return a.second < b.second;
    }
    return a.first < b.first;
}
};

int main(){
    int N, K, result = 0;
    priority_queue<int, greater<int>>pq;
    priority_queue<pair<int, int>> gems;
    priority_queue<int> packs;
    cin >> N >> K;
    cin.ignore();
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        cin.ignore();
        gems.push({a, b});
    }
    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        cin.ignore();
        packs.push(a);
    }
    for (int k = 0; k < K; k++){
        int pack = packs.top();
        packs.pop();
        while(gems.top().first < pack){
            pq.push(gems.top().second);
            gems.pop();
        }
        result += pq.top();
        //cout << gems.top().first << " " << gems.top().second << endl;
    }
    cout << result;
}
