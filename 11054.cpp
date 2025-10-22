#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
long long B;
vector<int> seq, rev_seq, lis, lis_cache, lds, lds_cache;

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
    cin >> N;
    cin.ignore();
    seq = vector<int>(N, 0);
    rev_seq = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        seq[i] = num;
        rev_seq[N - i - 1] = num;
    }
    lis.clear(); lds.clear();
    lis_cache = vector<int>(N, 1);
    lds_cache = vector<int>(N, 1);
}

int bin_search(const vector<int>& seq, int num)
{
    int start = 0;
    int end = seq.size();
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(num > seq[mid])
            start = mid + 1;
        else
            end = mid;
    }
    return end;
}

void Solution()
{
    Input();
    
    lis.push_back(seq[0]);
    lds.push_back(rev_seq[0]);
    for(int i = 1; i < N; ++i)
    {
        int idx = lis.size();
        if(lis.back() < seq[i])
            lis.push_back(seq[i]);
        else
        {
            idx = bin_search(lis, seq[i]);
            lis[idx] = seq[i];
        }
        lis_cache[i] = idx + 1;
    }
    for(int i = 1; i < N; ++i)
    {
        int idx = lds.size();
        if(lds.back() < rev_seq[i])
            lds.push_back(rev_seq[i]);
        else
        {
            idx = bin_search(lds, rev_seq[i]);
            lds[idx] = rev_seq[i];
        }
        lds_cache[N - i - 1] = idx + 1;
    }
    int result = 0;
    for(int i = 0; i < N; ++i)
    {
        result = max(result, lis_cache[i] + lds_cache[i] - 1);
    }
    cout << result << endl;
}
