#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, string> passwords;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> M;
    cin.ignore();
    passwords.clear();
    for(int i = 0; i < N; ++i)
    {
        string address, password;
        cin >> address >> password;
        cin.ignore();
        passwords[address] = password;
    }
}

void Solution()
{
    Input();
    for(int i = 0; i < M; ++i)
    {
        string address;
        cin >> address;
        cin.ignore();
        cout << passwords[address] << '\n';
    }
}