#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long T;
vector<long long> aSubSum, bSubSum;

void Solution();
int Search(int low, int high, const long long target, bool isLowerBound);

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    cin >> T;
    cin.ignore();

    int n, m, num;
    vector<int> a, b;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i)
    {
        cin >> num;
        a.push_back(num);
    }
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        long long sum = a[i];
        aSubSum.push_back(sum);
        for (int j = i + 1; j < n; ++j) {
            sum += a[j];
            aSubSum.push_back(sum);
        }
    }

    cin >> m;
    cin.ignore();
    for(int i = 0; i < m; ++i)
    {
        cin >> num;
        b.push_back(num);
    }
    cin.ignore();
    for (int i = 0; i < m; ++i) {
        long long sum = b[i];
        bSubSum.push_back(sum);
        for (int j = i + 1; j < m; ++j) {
            sum += b[j];
            bSubSum.push_back(sum);
        }
    }
    sort(bSubSum.begin(), bSubSum.end());

    long long result = 0;
    for(int i = 0; i < aSubSum.size(); ++i)
    {
        int lower, upper;
        lower = Search(0, bSubSum.size() - 1, T - aSubSum[i], true);
        upper = Search(0, bSubSum.size() - 1, T - aSubSum[i], false);
        result += (upper - lower);
    }
    cout << result;
}

int Search(int low, int high, const long long target, bool isLowerBound)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        bool flag = isLowerBound ? (target <= bSubSum[mid]) : (target < bSubSum[mid]);
        if(flag) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}