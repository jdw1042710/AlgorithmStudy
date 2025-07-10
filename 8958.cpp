#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
}

void Solution()
{
    Input();
    for(int i = 0; i < N; ++i)
    {
        int result = 0;
        int ex_score = 0;
        string test;
        getline(cin, test);
        for(auto ch : test)
        {
            if(ch == 'O')
            {
                ++ex_score;
                result += ex_score;
            }
            else
            {
                ex_score = 0;
            }
        }
        cout << result << endl;
    }
}