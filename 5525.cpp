#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, L;
string S;

void Input();
void Solution();

string GetSubStr(int n)
{
    string result = "I";
    for(int i = 0; i < n; ++i)
    {
        result.append("OI");
    }
    return result;
}

vector<int> GetPI(string s)
{
    int n = s.size();
    vector<int> result(n, 0);
    int j = 0;
    for(int i = 1; i < n; ++i)
    {
        while(j > 0 && s[i] != s[j])
            j = result[j - 1];
        if(s[i] == s[j])
            result[i] = ++j;
    }
    return result;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
    cin >> L;
    cin.ignore();
    getline(cin, S);
}

void Solution()
{
    Input();
    string sub_str = GetSubStr(N);
    int answer = 0;
    vector<int> pi = GetPI(sub_str);
    int n = S.size();
    int m = sub_str.size();
    int j = 0;
    for(int i = 0; i < n; ++i)
    {
        while(j > 0 && S[i] != sub_str[j])
            j = pi[j - 1];
        if(S[i] == sub_str[j])
        {
            if(j == m - 1)
            {
                ++answer;
                j = pi[j];
            }
            else
            {
                ++j;
            }
        }
    }
    cout << answer << endl;
}
