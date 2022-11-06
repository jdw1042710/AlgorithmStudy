#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<long long> split(string s){
    vector<long long> result;
    string temp;
    stringstream ss(s);
    while(getline(ss, temp,' ')){
        result.push_back(stoi(temp));
    }

    return result;
}

int main(){
    int N, ptr1, ptr2;
    string input;
    vector<long long> liq, result(3);// 0에 가까운 값, 그때의 ptr1, ptr2;
    cin >> N;
    cin.ignore();
    getline(cin, input);
    liq = split(input);
    ptr1 = 0;
    ptr2 = N-1;
    result[0] = abs(liq[ptr1] + liq[ptr2]);
    result[1] = ptr1;
    result[2] = ptr2;
    while(ptr1 < ptr2){
        //cout << ptr1 << " " << ptr2 << endl;
        long long temp = liq[ptr1] + liq[ptr2];
        if(result[0] >= abs(temp)){
            result[0] = abs(temp);
            result[1] = ptr1;
            result[2] = ptr2;
        }
        if(temp > 0){
            ptr2--;
        }else if(temp < 0){
            ptr1++;
        }else{
            break;
        }
    }
    cout << liq[result[1]] << ' ' << liq[result[2]];
}
