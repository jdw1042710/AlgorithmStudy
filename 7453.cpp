#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<long long> A, B, C, D, AB, CD;

void Solution();
int Search(int low, int high, const long long target, bool isLowerBound);

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cin.ignore();
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    Solution();
}

// 푸는중인 문제
void Solution()
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            AB.push_back(A[i] + B[j]);
        }
    }
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            CD.push_back(C[i] + D[j]);
        }
    }
    // sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long result = 0;
    for(int i = 0; i < AB.size(); ++i)
    {
        int lower, upper;
        lower = Search(0, CD.size() - 1, -1 * AB[i], true);
        upper = Search(0, CD.size() - 1, -1 * AB[i], false);
        result += (upper - lower);
    }
    cout << result;
}
int Search(int low, int high, const long long target, bool isLowerBound)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        bool flag = isLowerBound ? (target <= CD[mid]) : (target < CD[mid]);
        if(flag) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
