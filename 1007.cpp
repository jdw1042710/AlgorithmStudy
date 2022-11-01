#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    int T, N;
    cin >> T;
    cin.ignore();
    for (int t = 0; t < T; t++){
        cin >> N;
        cin.ignore();

        double result = 0;
        vector<pair<int, int>> coord;
        vector<bool> isVisited(N, false);
        for (int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            cin.ignore();
            coord.push_back({x, y});
        }
        for (int i = 0; i < N; i++){
            if(isVisited[i]){
                continue;
            }

            double min = 200000 * sqrt(2);
            int min_idx = -1;
            for (int j = 0; j < N; j++){
                if(i == j){
                    continue;
                }
                if(isVisited[j]){
                    continue;
                }
                double temp = sqrt(pow(coord[i].first - coord[j].first, 2) + pow(coord[i].second - coord[j].second, 2));
                if (temp < min){
                    min = temp;
                    min_idx = j;
                }
            }
            isVisited[i] = true;
            isVisited[min_idx] = true;
            result += min;
        }
        cout << result << endl;
    }
}