#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
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
    cin >> N >> M;
    cin.ignore();
    nums = vector<int>(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
}

void PrintSequence(size_t lower_bound, const size_t n, const size_t m, vector<int>& st)
{
    if(st.size() == m) 
    {
        for(auto iter : st)
        {
            cout << iter << ' ';
        }
        cout << '\n';
        return;
    }
    for(size_t i = lower_bound; i < n; ++i)
    {
        if(i > 0 && nums[i - 1] == nums[i]) continue;
        st.push_back(nums[i]);
        PrintSequence(i, n, m, st);
        st.pop_back();
    }
}

void Solution()
{
    Input();
    vector<int> st;
    PrintSequence(0, N, M, st);
    // cout << endl;
}