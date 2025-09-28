#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N;

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
    cin >> N;
    cin.ignore();
}

void Solution()
{
    vector<long long> padovan(100 , 1);
    for(int i = 3; i < 100; ++i)
    {
        padovan[i] = padovan[i - 2] + padovan[i - 3];
    }
    int T;
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        cout << padovan[N - 1] << endl;
    }
}