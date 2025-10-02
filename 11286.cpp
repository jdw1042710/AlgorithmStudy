#include <iostream>
#include <vector>
#include <queue>

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
    Input();
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        cin.ignore();
        if(input == 0)
        {
            if(pq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top().first * pq.top().second << '\n';
                pq.pop();
            }
        }
        else
        {
            if(input < 0)
            {
                pq.push({input, 1});
            }
            else
            {
                pq.push({-input, -1});
            }
        }
    }
}