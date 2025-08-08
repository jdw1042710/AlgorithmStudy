#include <iostream>
#include <vector>

using namespace std;

int L;
const long long M = 1234567891LL, r = 31;
vector<char> inputs;
vector<long long> rModm;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> L;
    cin.ignore();
    for(int i = 0; i < L; ++i)
    {
        char ch;
        cin >> ch;
        inputs.push_back(ch);
    }
    rModm = vector<long long>(L, 1);
    for(int i = 1; i < L; ++i)
    {
        rModm[i] = (rModm[i - 1] * r) % M;
    }
}

void Solution()
{
    Input();
    long long sum = 0;
    for(int i = 0; i < L; ++i)
    {
        int a = inputs[i] - 'a' + 1;
        sum += (a * rModm[i]) % M;
        sum %= M;
    }
    cout << sum << endl;
}