#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector<int> nums;

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
    cin >> N >> X;
    cin.ignore();
    nums = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
}

void Solution()
{
    Input();
    for(int i = 0; i < N; ++i)
    {
        if(nums[i] < X) cout << nums[i] << ' ';
    }
}
