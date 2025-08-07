#include <iostream>
#include <vector>

using namespace std;


void Solution();

bool Compare(pair<int, int> lhs, pair<int, int> rhs)
{
    if(lhs.first >= rhs.first && lhs.second >= rhs.second)
        return lhs.first != rhs.first && lhs.second != rhs.second;
    return false;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    int N;
    cin >> N;
    cin.ignore();
    vector<pair<int, int>> arr;
    for(int i = 0; i < N; ++i)
    {
        int w, h;
        cin >> w >> h;
        cin.ignore();
        arr.push_back({w, h});
    }
    for(int i = 0; i < N; ++i)
    {
        int count = 1;
        for(int j = 0; j < N; ++j)
        {
            if(Compare(arr[j], arr[i]))
            {
                ++count;
            }
        }
        cout << count << ' ';
    }
    // cout << endl;
}
