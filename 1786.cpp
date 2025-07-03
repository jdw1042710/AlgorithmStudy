#include <iostream>
#include <vector>
#include <string>

using namespace std;

string T, P;


void Input();
void Solution();

void SetPi(string str, vector<int>& pi)
{
    pi = vector<int>(str.length(), 0);
    int index = 0;
    for(size_t i = 1; i < str.length(); ++i)
    {
        while(index > 0 && str[i] != str[index])
        {
            index = pi[index - 1];
        }
        if(str[i] == str[index])
        {
            ++index;
            pi[i] = index;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    getline(cin, T);
    getline(cin, P);
}

void Solution()
{
    Input();
    vector<int> pi;
    SetPi(P, pi);

    vector<int> results;
    int n = T.length();
    int m = P.length();
    int j = 0;
    for(int i = 0; i < n; ++i)
    {
        while(j > 0 && T[i] != P[j])
        {
            j = pi[j - 1];
        }
        if(T[i] == P[j])
        {
            if(j == m - 1)
            {
                results.push_back(i - m + 1);
                j = pi[j];
            }
            else
            {
                ++j;
            }
        }
    }

    cout << results.size()<< endl;
    for(size_t i = 0; i < results.size(); ++i)
    {
        cout << results[i] + 1 << ' ';
    }
}
