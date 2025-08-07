#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> lines;

void Input();
void Solution();

int GetLowerBound(int start, int end, int target, const vector<int>& arr)
{
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(arr[mid] < target )
        {
            start = mid + 1;
        }
        else
        {

            end = mid;
        }
    }
    return end;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        cin.ignore();
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end());
}

void Solution()
{
    Input();
    vector<int> lis({lines[0].second});
    vector<int> lis_index({0});
    for(int i = 1; i < N; ++i)
    {
        int val = lines[i].second;
        if(lis.back() < val)
        {
            lis.push_back(val);
            lis_index.push_back(lis.size() - 1);
        }
        else
        {
            int index = GetLowerBound(0, lis.size() - 1, val, lis);
            lis[index] = val;
            lis_index.push_back(index);
        }
    }

    cout << N - lis.size() << '\n';

    vector<int> cut_line;
    int cur = lis.size() - 1;
    for(int i = N - 1; i >= 0; --i)
    {
        if(cur == lis_index[i])
        {
            --cur;
        }
        else
        {
            cut_line.push_back(lines[i].first);
        }
    }
    sort(cut_line.begin(), cut_line.end());
    for(auto l : cut_line)
    {
        cout << l << '\n';
    }
}
