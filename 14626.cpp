#include <iostream>
#include <vector>

using namespace std;


int Index = 0;
vector<int> nums;
int mul3[10] = {0};

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
    for(int i = 0; i < 13; ++i)
    {
        char ch;
        cin >> ch;
        if(ch == '*')
        {
            Index = i;
            nums.push_back(0);
        }
        else
        {
            nums.push_back(ch - '0');
        }
    }

    for(int i = 0; i < 10; ++i)
    {
        int rest = (i * 3) % 10;
        mul3[rest] = i * 3;
    }

}

void Solution()
{
    Input();
    int result = 0;
    for(int i = 0; i < 12; i += 2)
    {
        result = (nums[i] + result) % 10;
    }
    for(int i = 1; i < 12; i += 2)
    {
        result = (nums[i] * 3 + result) % 10;
    }

    if(Index == 12)
    {
        result = 10 - result;
    }
    else if(Index % 2 == 1)
    {
        int mod = (10 - nums[12] - result) % 10;
        if(mod < 0) mod += 10;
        result = mul3[mod] / 3;
    }
    else
    {
        int mod = (10 - nums[12] - result) % 10;
        if(mod < 0) mod += 10;
        result = mod;
    }
    cout << result << endl;
}