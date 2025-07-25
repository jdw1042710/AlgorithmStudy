#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    int N;
    cin >> N;
    cin.ignore();
    vector<int> nums, mode;
    int mode_count = 0;
    map<int, int> num_count;
    double avg = 0;
    for(int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        cin.ignore();
        nums.push_back(num);
        avg += (float)num / N;
        if(num_count.find(num) == num_count.end())
        {
            num_count.insert({num, 0});
        }
        num_count[num] += 1;
        if(num_count[num] > mode_count)
        {
            mode.clear();
            mode.push_back(num);
            mode_count = num_count[num];
        }
        else if(num_count[num] == mode_count)
        {
            mode.push_back(num);
        }
    }
    sort(nums.begin(), nums.end());
    sort(mode.begin(), mode.end());
    auto iter = num_count.begin();
    ++iter;
    cout << (long long)round(avg) << endl;
    cout << nums[N / 2] << endl;
    cout << ((mode.size() != 1) ? mode[1] : mode[0]) << endl;
    cout << abs(nums[N - 1] - nums[0]) << endl;
}