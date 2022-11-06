#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> is_pd;
vector<int> dp;

int main(){
    string input;
    getline(cin, input);
    int N = input.length();
    is_pd = vector<vector<bool>>(N, vector<bool>(N, false));
    dp = vector<int>(N + 1, 2500);
    for(int i = 0; i < N; i++){
        is_pd[i][i] = true;
    }
    for(int i = 0; i < N - 1; i++){
        is_pd[i][i + 1] = input[i] == input[i + 1];
    }
    for(int j = 2; j < N; j++){
        for(int i = 0; i + j < N; i++){
            if(input[i] == input[i + j]){
                is_pd[i][i + j] = is_pd[i + 1][i + j - 1];
            }
        }
    }
    dp[0] = 0;
    for (int i = 1; i < N + 1; i++){
        for(int j = i; j > 0; j--){
            //cout << "check : " << j - 1 << " ~ " << i - 1 << endl;
            if(is_pd[j - 1][i - 1]){
                //cout << dp[j - 1] + 1 << " vs " << dp[i] << endl;
                dp[i] = min(dp[j - 1] + 1, dp[i]);

            }
        }
        //cout << "////" << dp[i] << "////" << endl;
    }
    cout << dp[N];
}
