#include <iostream>
#include <vector>

using namespace std;

unsigned long long A, B;
vector<unsigned long long> powerSum;

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
    cin >> A >> B;
    powerSum = vector<unsigned long long>(55, 1);
    for(int i = 1; i < 55; ++i)
    {
        powerSum[i] = powerSum[i - 1] * 2 + (1LL << i);
    }
    cin.ignore();
}

unsigned long long GetOneCount(unsigned long long num)
{
    unsigned long long ret = num & 1;
    for(int i = 54; i > 0; --i)
    {
        if(num & (1LL << i))
        {
            num -= (1LL << i);
            ret += powerSum[i - 1] + num + 1;
        }
    }
    return ret;
}

void Solution()
{
    Input();
    cout << GetOneCount(B) - GetOneCount(A - 1) << endl;
}