#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

double result;

void sum(const vector<bool> &isVisited, const vector<pair<int, int> > &coord, int N){
    //cout << "///SUM///" << endl;
    pair<int, int> x1, x2;
    for(int i = 0; i < N; i++){
        if(isVisited[i]){
    //        cout << i << " ";
            x1.first += coord[i].first;
            x1.second += coord[i].second;
        }else{
            x2.first += coord[i].first;
            x2.second += coord[i].second;
        }
    }
    //cout << endl;
    double temp = sqrt(pow((x2.first - x1.first), 2) + pow((x2.second - x1.second), 2));
    //cout << "결과 : " << temp << endl;
    if (result >temp){
        result = temp;
    }
}


void dfs(int node, int cnt, vector<bool> &isVisited, const int N, const vector<pair<int, int> > &coord){
    isVisited[node] = true;
    if(cnt == N/2){
        sum(isVisited, coord, N);
        isVisited[node] = false;
        return;
    }
    for (int i = node + 1; i < N; i++){
        dfs(i, cnt + 1, isVisited, N, coord);
    }
    isVisited[node] = false;
}

int main(){
    int T, N;
    cin >> T;
    cin.ignore();
    for (int t = 0; t < T; t++){
        cin >> N;
        cin.ignore();

        result = numeric_limits<double>::max();
        vector<pair<int, int> > coord;
        vector<bool> isVisited(N, false);
        for (int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            cin.ignore();
            coord.push_back(make_pair(x, y));
        }
        for(int i = 0; i < N; i++){
            dfs(i, 1, isVisited, N, coord);
        }
        printf("%.12f\n", result);
    }
}
