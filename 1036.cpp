#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;


// long long을 초과하므로 이를 해결하기 위해 BigInteger를 써야하나 미구현함
// 사람들이 왜 C++로 안풀었는지 알거 같음...

int N, K;
int row, col;
vector<string> nums;
map<char, unsigned long long> recode;


int charToInt(char num) {
    int result = 0;
    if (isdigit(num)) {
        result = num - '0';
    }
    else {
        result = num - 'A' + 10;
    }
    return result;
}

// num is must reversed
unsigned long long dec36ToInt(string num) {
    unsigned long long result = 0;
    for (int i = 0; i < num.length(); i++) {
        int temp = charToInt(num[i]);
        result += temp * pow(36, i);
    }
    return result;
}

string intToDec36(unsigned long long num) {
    string result = "";
    while (num > 0) {
        int temp = num % 36;
        if (temp < 10) {
            result += '0' + temp;
        }
        else {
            result += 'A' + temp - 10;
        }
        num /= 36;
    }
    reverse(result.begin(), result.end());
    if (result.empty()) return "0";
    return result;
}

bool compare(string a, string b) {
    if (a.length() != b.length())
        return a.length() > b.length();
    return a < b;
    
}

bool compareRecode(pair<char, unsigned long long> a, pair<char, unsigned long long> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;

}

set<char> selectToZ()
{
    set<char> candidates;
    vector<pair<char, unsigned long long>> recodeVector(recode.begin(), recode.end());
    
    sort(recodeVector.begin(), recodeVector.end(), compareRecode);
    //overflow check
    /*
    for (auto i : recodeVector) {
        cout << i.first << " : " << i.second << endl;
    }
    */
    for (int i = 0; i < K; i++) {
        candidates.insert( recodeVector[i].first);
    }
    return candidates;
}

void changeToZ(const set<char> &candidates) {
    // set같은거 사용해서 미리 뽑아놓은 친구들 Z로 바꿔야함
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < nums[i].length(); j++) {
            if (candidates.find(nums[i][j]) != candidates.end()) {
                nums[i][j] = 'Z';
            }
        }
        // cout << nums[i] << endl;
    }
}

string solution() {
    string result;
    set<char> candidates;
    candidates = selectToZ();
    changeToZ(candidates);
    unsigned long long sum = 0;
    for (auto num : nums) {
        sum += dec36ToInt(num);
    }
    result = intToDec36(sum);
    return result;
}

int main() {
    string str;
    for (int i = 0; i < 10; i++) {
        recode['0' + i] = 0;
    }
    for (int i = 0; i < 26; i++) {
        recode['A' + i] = 0;
    }
    cin >> N ;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        nums.push_back(str);
    }
    sort(nums.begin(), nums.end(), compare);
    cin >> K;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        reverse(nums[i].begin(), nums[i].end());
        for (int j = 0; j < nums[i].length(); j++) {
            recode[nums[i][j]] += (35 - charToInt(nums[i][j])) * pow(36, j);
        }
    }
    cout << solution();
}