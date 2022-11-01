#include <iostream>
#include <vector>

using namespace std;

long findAns(long N, const vector<long> &lens, long upper, long lower){
        if (lower > upper){
            return lower - 1;
        }

        long mid = (upper + lower) / 2;
        long long count = 0;
        for (auto iter = lens.begin(); iter < lens.end(); iter++){
            count += (*iter)/ mid;
        }
        if (count < N){
            return findAns(N, lens, mid - 1, lower);
        }else{
            return findAns(N, lens, upper, mid + 1);
        }

}




int main(){
    long K, N, maxLen = 0;
    vector<long> lens;
    cin >> K >> N;
    for (int i = 0; i < K; i++){
        long temp;
        cin.ignore();
        cin >> temp;
        if (maxLen < temp){
            maxLen = temp;
        }
        lens.push_back(temp);
    }

    cout << findAns(N, lens, maxLen, 1) << endl;
}