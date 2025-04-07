#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> mat;
vector<vector<long long>> cache;

void Solution();
long long GetMinCalNum(int start, int end);

int main()
{
    string str_nums;
    vector<int> nums;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int r, c;
        cin >> r >> c;
        cin.ignore();
        mat.push_back({r, c});
    }
    cache = vector<vector<long long>>(N, vector<long long>(N, -1));
    Solution();
}

void Solution()
{
    cout << GetMinCalNum(0, N - 1);
}

long long GetMinCalNum(int start, int end)
{
    if(start == end) return 0;
    long long& ret = cache[start][end];
    if(ret != -1) return ret;
    ret = GetMinCalNum(start, start) + GetMinCalNum(start + 1, end) + mat[start].first * mat[start + 1].first * mat[end].second;
    for(int k = 1; start + k + 1 <= end; ++k)
    {
        ret = min(ret,
                GetMinCalNum(start, start + k) + GetMinCalNum(start + k + 1, end) + mat[start].first * mat[start + k + 1].first * mat[end].second);
    }
    // cout << "start: " << start << ", end: " << end << ", value: " << ret << endl;
    return ret;
}