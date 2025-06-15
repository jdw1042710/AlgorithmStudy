
#include <iostream>
#include <cstring>

using namespace std;

int C, N;
int cities[20][2], cache[1000 * 100 + 1];

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> C >> N;
    cin.ignore();
    memset(cities, 0, sizeof(cities));
    memset(cache, 0, sizeof(cache));
    for(int i = 0; i < N; ++i)
    {
        int cost, customer;
        cin >> cost >> customer;
        cin.ignore();
        cities[i][0] = cost;
        cities[i][1] = customer;
    }
}

void Solution()
{
    Input();
    for(int maxCost = 1; maxCost < 100001; ++maxCost)
    {
        for(int i = 0; i < N; ++i)
        {
            if(maxCost >= cities[i][0])
            {
                cache[maxCost] = max(cache[maxCost], cache[maxCost - cities[i][0]] + cities[i][1]);
            }
        }
        if(cache[maxCost] >= C)
        {
            cout << maxCost << endl;
            return;
        }
    }
}
