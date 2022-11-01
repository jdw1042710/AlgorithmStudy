#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> split(string input, char delimiter){
    vector<int> result;
    stringstream ss(input);
    string temp;
    while(getline(ss, temp, delimiter)){
        result.push_back(stoi(temp));
    }
    return result;
}

int travel(int n, const unordered_map<int, vector<int>> &graph, const vector<int> &cost){
    int max_cost = 0;
    vector<int> children = graph[n];
    for(auto child : children){
        int temp = travel(child, graph, cost);
        if (temp > max_cost){
            max_cost = temp;
        }
    }
    
    return cost[n] + max_cost;
}

int main(){
    int T, N, K;
    cin >> T;
    cin.ignore();
    
    for(int i = 0 ; i < T; i++){
        int start_node;
        string temp;
        unordered_map<int, vector<int>> graph;
        vector<int> cost;
        cin >> N >> K;
        cin.ignore();
        
        for (int j = 0; j < N; j++){
            graph.insert({j+1, vector<int>()});
        }
        
        cin >> temp;
        cin.ignore();
        
        cost = split(temp, ' ');
        for (int j = 0; j < K; j++){
            int a, b;
            cin >> a >> b;
            cin.ignore();
            graph[b].push_back(a);
        }
        
        cin >> start_node;
        cin.ignore();
        cout << travel(start_node, graph, cost) << endl;
        
    }
    
}
////////// 이 코드는 이전버전임
//////////  백준 통과 코드에서 가져와함