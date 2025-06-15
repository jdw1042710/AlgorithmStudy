
#include <iostream>

using namespace std;

int nums[5];

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    for (int i = 0; i < 5; ++i)
    {
        cin >> nums[i];
    }
}

void Solution()
{
    Input();
    int result = 0;
    for(int i = 0; i < 5; ++i)
    {
        result += (nums[i] * nums[i] % 10);
        result %= 10;
    }
    cout << result << endl;
    
}
