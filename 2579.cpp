#include <iostream>

using namespace std;

int dp [300] = {0};
int stairs[300] = {0}; 

int solution(int n){
    if (n < 0){
        return 0;
    }
    if (n == 0){
        return stairs[0];
    }
    if (dp[n] != 0){
        return dp[n];
    }
    int temp_a = solution(n-2);
    int temp_b = stairs[n-1] + solution(n-3); 
    dp[n] = stairs[n] + (temp_a > temp_b ? temp_a: temp_b);
    return dp[n];
}

int main(){
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
        cin >> stairs[i];
        cin.ignore();
    }
    cout << solution(N - 1) << endl;
    /*
    cout << "DP 값 목록:" << endl;
    for(int i = 0 ; i < N; i++){
        cout << dp[i] << endl;
    }
    */
}