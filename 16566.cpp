#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

vector<int> deck;
vector<int> parents;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

int GetParent(int n)
{
    if(parents[n] == n) return n;
    return parents[n] = GetParent(parents[n]);
}

void Input()
{
    cin >> N >> M >> K;
    cin.ignore();
    deck.clear();
    for(int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        deck.push_back(num);
    }
    cin.ignore();
    sort(deck.begin(), deck.end());
    parents = vector<int>(N + 2, 0);
    int index = 1;
    for(int i = 0; i < M; ++i)
    {
        int card = deck[i];
        while(index <= card)
        {
            parents[index] = card;
            ++index;
        }
    }
}

int TryDraw(int card)
{
    int ret = GetParent(card);
    parents[ret] = GetParent(ret + 1);
    return ret;
}

void Solution()
{
    Input();
    for(int i = 0; i < K; ++i)
    {
        int op_card;
        cin >> op_card;
        cout << TryDraw(op_card + 1) << '\n';
    }
    // cout << endl;
}