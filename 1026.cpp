#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

vector<int> ReadLine(string str) {
    vector<int> p = vector<int>();
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, ' ')) {
        p.push_back(stoi(buffer));
    }
    return p;
}



long long solution() {
    long long result = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }
    return result;
}

int main() {
    string strA, strB;
    cin >> N ;
    cin.ignore();
    getline(cin, strA);
    getline(cin, strB);
    A = ReadLine(strA);
    B = ReadLine(strB);
    cout << solution();
}