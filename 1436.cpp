#include <iostream>
#include <string>

using namespace std;

bool is666(long num);

long solution(int N){
    long result = 666;
    int count = 0;
    while(count < N){
        if(is666(result)){
            count++;
        }
        result++;
    }

    return result - 1;
}

bool is666(long num){
    string str = to_string(num);
    for (int i = 0; i < (str.length() - 2); i++){
        if (str.substr(i,3) == "666")
        {
            return true;
        }
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    cout << solution(N) << endl;
}