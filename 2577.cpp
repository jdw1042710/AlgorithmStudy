#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nums[3];

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    for(int i = 0; i < 3; ++i)
    {
        int input;
        cin >> input;
        cin.ignore();
        nums[i] = input;
    }
}

void Solution()
{
    Input();
    long long mul = 1;
    for(int i = 0; i < 3; ++i) 
        mul *= nums[i];
    int result[10] = {0};
    while(mul != 0)
    {
        int digit = mul % 10;
        result[digit]++;
        mul /= 10;
    }

    for(int i = 0; i < 10; ++i)
    {
        cout << result[i] << endl;
    }
}
