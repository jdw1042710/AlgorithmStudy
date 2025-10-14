#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;
map<int, int> ladders;
map<int, int> snakes;

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
    ladders.clear();
    snakes.clear();
    for(int i = 0; i < N; ++i)
    {
        int from, to;
        cin >> from >> to;
        cin.ignore();
        ladders[from] = to;
    }

    for(int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        cin.ignore();
        snakes[from] = to;
    }

}

void Solution()
{
    Input();
    vector<bool> visited(101, false);
    queue<pair<int, int>> q;
    visited[1] = true;
    q.push({1, 0});

    int result = -1;
    while(!q.empty() && result == -1)
    {
        int pos = q.front().first;
        int count = q.front().second;
        q.pop();

        for(int i = 1; i <= 6; ++i)
        {
            int next_pos = pos + i;
            int next_count = count + 1;
            if(next_pos > 100) continue;
            if(ladders.find(next_pos) != ladders.end()) 
                next_pos = ladders[next_pos];
            else if(snakes.find(next_pos) != snakes.end())
                next_pos = snakes[next_pos];
            if(visited[next_pos]) continue;
            
            if(next_pos == 100)
            {
                result = next_count;
                break;
            }

            visited[next_pos] = true;
            q.push({next_pos, next_count});
        }
    }
    cout << result << endl;
}