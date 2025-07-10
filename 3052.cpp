#include <iostream>
#include <vector>

using namespace std;

vector<bool> flags;
const int N = 42;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    flags =  vector<bool>(N, false);
    int answer = 0;
    for(int i = 0; i < 10; ++i)
    {
        int num;
        cin >> num;
        cin.ignore();
        if(!flags[num % N])
        {
            ++answer;
        }
        flags[num % N] = true;
    }
    cout << answer << endl;
}