#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<long long> split(string s){
    vector<long long> result;
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, ' ')){
        result.push_back(stoi(temp));
    }
    return result;
}

long long CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C){
    long long result = A.first * B.second + B.first * C.second + C.first * A.second;
    result -= A.second * B.first + B.second * C.first + C.second * A.first;
    if (result > 0){
        return 1;
    }
    if (result < 0){
        return -1;
    }
    return 0;
}

int main(){
    string s;
    vector<long long> v;
    pair<long long, long long> A, B, C, D;
    getline(cin, s);
    v = split(s);
    A.first = v[0], A.second = v[1], B.first = v[2], B.second = v[3];
    getline(cin, s);
    v = split(s);
    C.first = v[0], C.second = v[1], D.first = v[2], D.second = v[3];

    long long ans1, ans2;
    ans1 = CCW(A, B, C) * CCW(A, B, D);
    ans2 = CCW(C, D, A) * CCW(C, D, B);

    if(ans1 == 0 && ans2 == 0){
        if(A > B){
            swap(A, B);
        }
        if(C > D){
            swap(C, D);
        }
        if (A <= D && B >= C) {
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        if (ans1 <= 0 && ans2 <= 0){
            cout << 1;
        }else{
            cout << 0;
        }
    }

}
