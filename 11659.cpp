#include <iostream>
#include <vector>

using namespace std;

void Solution(int m, const vector<int>& ac_nums);

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    vector<int> nums = {0};
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; ++i)
    {
        int nth;
        cin >> nth;
        nums.push_back(nums[i] + nth);
    }
    cin.ignore();
    Solution(m, nums);
}

void Solution(int m, const vector<int>& ac_nums)
{
    for (int i = 0; i < m; ++i)
    {
        int j, k;
        cin >> j >> k;
        cin.ignore();
        cout << ac_nums[k] - ac_nums[j - 1] << "\n";
    }
}