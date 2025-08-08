#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N = 0;
long long cuttedCount = 0;
vector<int> ranks;

void Input();
void Solution();

long long Round(double num)
{
    return num + 0.5;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        cin.ignore();
        ranks.push_back(a);
    }
    cuttedCount = Round(N * 0.15);
}

void Solution()
{
    Input();
    sort(ranks.begin(), ranks.end());
    long long sum = 0;
    for(int i = cuttedCount; i < N - cuttedCount; ++i)
    {
        sum += ranks[i];
    }
    if(N == 0) cout << 0 << endl;
    else cout << Round((double)sum / (N - 2 * cuttedCount)) << endl;

}