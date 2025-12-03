#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
const long long INF = 1000 * 1000 + 1;
const int NumOfColors = 3;
enum class Color
{
    R = 0,
    G, 
    B, 
    None
};

struct Cost
{
    int r, g, b;
    Cost(int _r, int _g, int _b) 
    : r(_r), g(_g), b(_b) {}

    int& operator[](int idx)
    {
        if(idx == 0) return r;
        if(idx == 1) return g;
        return b; // idx == 2;
    }
};

vector<Cost> costs;
vector<vector<vector<int>>> cache;

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
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int r, g, b;
        cin >> r >> g >> b;
        cin.ignore();

        Cost cost(r, g, b);
        costs.push_back(cost);
    }
    cache = vector<vector<vector<int>>>(NumOfColors, vector<vector<int>>(NumOfColors, vector<int>(N, -1)));
}

int GetMinCost(int index, Color exColor, Color firstColor)
{
    if(index == N) return 0;
    int& ret = cache[static_cast<int>(firstColor)][static_cast<int>(exColor)][index];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < NumOfColors; ++i)
    {
        Color cur = static_cast<Color>(i);
        if(cur == exColor) continue;
        if(index == N - 1 && cur == firstColor) continue;
        ret = min(ret, costs[index][i] + GetMinCost(index + 1, cur, firstColor));
    }
    return ret;
}

void Solution()
{
    Input();
    int result = INF;
    for(int i = 0; i < NumOfColors; ++i)
    {
        Color first = static_cast<Color>(i);
        cache[i][i][0] = costs[0][i] + GetMinCost(1, first, first);
        result = min(result, cache[i][i][0]);
    }
    cout << result << endl;
}