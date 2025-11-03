#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;

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
    for(size_t i = lower_bound; i <= n; ++i)
    {
        st.push_back(i);
        PrintSequence(i, n, m, st);
        st.pop_back();
    }
}

void Solution()
{
    Input();
    vector<int> st;
    PrintSequence(1, N, M, st);
    // cout << endl;
}