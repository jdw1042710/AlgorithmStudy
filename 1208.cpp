#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int N, S;
vector<int> p;
map<int, int> leftSum;

vector<int> ReadLine(string str) {
    vector<int> p = vector<int>();
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, ' ')) {
        p.push_back(stoi(buffer));
    }
    return p;
}

void leftBF(int index, int sum) {
    if (index == N / 2) {
        leftSum[sum] += 1;
        return;
    }
    leftBF(index + 1, sum);
    leftBF(index + 1, sum + p[index]);
}

long long rightBF(int index, int sum) {
    if (index == N) {
        return leftSum[S - sum];
    }
    return rightBF(index + 1, sum) + rightBF(index + 1, sum + p[index]);
}


long long solution() {
    long long result;
    leftBF(0, 0);
    result = rightBF(N / 2, 0);
    if (S == 0) result--;
    return result;
}

int main() {
    string str;
    cin >> N >> S;
    cin.ignore();
    getline(cin, str);
    p = ReadLine(str);
    cout << solution();
}