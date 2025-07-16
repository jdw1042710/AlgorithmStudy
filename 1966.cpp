#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M;
queue<pair<int, int>> q;
priority_queue<int, vector<int>> pq;

void Input();
void Solution();


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> M;
    cin.ignore();
    q = queue<pair<int, int>>();
    pq = priority_queue<int, vector<int>>();
    for(int i = 0; i < N; ++i)
    {
        int priority;
        cin >> priority;
        q.push({i, priority});
        pq.push(priority);
    }
    cin.ignore();
}

void Solution()
{
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        int result = 0;
        while(!q.empty())
        {
            int doc = q.front().first;
            int doc_priority = q.front().second;
            q.pop();
            if(doc_priority == pq.top())
            {
                pq.pop();
                ++result;
                if(doc == M)
                {
                    cout << result << endl;
                    break;
                }
            }
            else
            {
                q.push({doc, doc_priority});
            }
        }
    }
}