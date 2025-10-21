#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    nums.clear();
    int num;
    while(cin >> num)
        nums.push_back(num);

}

int FindBigger(int start, int end, int num)
{
    while(start < end)
    {
        if(nums[start] > num)
            break;
        ++start;
    }
    return start;
}

void PrintPostOrderUsingPreOrder(int start, int end)
{
    if(start >= end) return;
    int firstBiggerIndex = FindBigger(start + 1, end, nums[start]);
    PrintPostOrderUsingPreOrder(start + 1, firstBiggerIndex);
    PrintPostOrderUsingPreOrder(firstBiggerIndex, end);
    cout << nums[start] << '\n';
}

void Solution()
{
    Input();
    PrintPostOrderUsingPreOrder(0, nums.size());
}