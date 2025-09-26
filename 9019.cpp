#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int A, B;
const string opVariations = "DSLR";

void Input();
void Solution();

int Calculate(int num, char op)
{
    int result = 0;
    switch (op)
    {
    case 'D':
    {
        result = (num * 2) % 10000;
    }
    break;
    case 'S':
    {
        result = (num - 1 + 10000) % 10000;
    }
    break;
    case 'L':
    {
        int lNum = (num * 10) / 10000;
        result = ((num * 10) % 10000) + lNum;
    }
    break;
    case 'R':
    {
        int rNum = num % 10;
        result = num / 10 + rNum * 1000;
    }
    break;
    default:
        result = -1; // error result
        break;
    }
    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> A >> B;
    cin.ignore();
}

void Solution()
{
    int T;
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        queue<pair<int, string>> q;
        vector<bool> visited(10000, false);
        q.push({A, ""});
        visited[A] = true;
        pair<int, string> result;
        while(!q.empty())
        {
            int curNum = q.front().first;
            string curOps = q.front().second;
            if(curNum == B)
            {
                result = q.front();
                break;
            }
            q.pop();
            for(auto op : opVariations)
            {
                int nextNum = Calculate(curNum, op);
                if(visited[nextNum]) continue;
                string nextOps = curOps + op;
                q.push({nextNum, nextOps});
                visited[nextNum] = true;
            }
        }
        cout << result.second << '\n';
    }
}