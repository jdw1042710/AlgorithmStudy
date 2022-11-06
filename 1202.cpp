#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    long long result = 0;
    priority_queue<int>pq;
    vector<pair<int, int>> gems;
    vector<int> packs;
    cin >> N >> K;
    cin.ignore();
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        cin.ignore();
        gems.push_back({a, b});
    }
    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        cin.ignore();
        packs.push_back(a);
    }
    sort(gems.begin(), gems.end());
    sort(packs.begin(), packs.end());
    int idx = 0;
    for (int k = 0; k < K; k++){
        int pack = packs[k];
        //cout << pack << endl;
        while(idx < N && gems[idx].first <= pack){
            //cout << idx;
            pq.push(gems[idx].second);
            idx++;
        }
        if(!pq.empty()){
            result += pq.top();
            //cout << pq.top() << endl;
            pq.pop();
        } 
    }
    cout << result;
}
