#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, result;
vector<int> parents;
vector<bool> done, visited;

void Input();
void Solution();
void CheckGroup(int cur);

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        Solution();
    }
}

void Input()
{
    cin >> N;
    cin.ignore();
    parents = vector<int>(N + 1);
    for(int i = 1; i <= N; ++i)
    {
        int input;
        cin >> input;
        parents[i] = input;
    }
    cin.ignore();
    done = vector<bool>(N + 1, false);
    visited = vector<bool>(N + 1, false);
}

void Solution()
{
    result = N;
    for(int i = 1; i <= N; ++i)
    {
        if(visited[i]) continue;
        CheckGroup(i);
    }
    cout << result << '\n';
}

void CheckGroup(int cur)
{
    visited[cur] = true;
    int next = parents[cur];
    if(!visited[next])
    {
        CheckGroup(next);
    }
    else if(!done[next])
    {
        for(int i = next; i != cur; i = parents[i])
        {
            done[i] = true;
            --result;
        }
        --result;
    }
    done[cur] = true;
}