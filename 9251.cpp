#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[1001][1001];

void Solution(const string str1, const string str2);

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    Solution(str1, str2);
}     

void Solution(const string str1, const string str2)
{
    memset(cache, 0, sizeof(cache));
    for(int i = 1; i <= str1.length(); ++i)
    {
        for(int j = 1; j <= str2.length(); ++j)
        {
            int& dp = cache[i][j];
            if(str1.at(i - 1) == str2.at(j - 1))
            {
                dp = 1 + cache[i - 1][j - 1];
            }
            else
            {
                dp = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }
    cout << cache[str1.length()][str2.length()];
}