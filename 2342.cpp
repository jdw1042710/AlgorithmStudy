#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Feet;

int N;
const int INF = 400001;
vector<vector<int>> cache;
vector<int> steps;

int GetStepCost(int cur, int next)
{
    if(next == 0) return 0;
    if(cur == next) return 1;
    if(cur == 0) return 2;
    if(abs(cur - next) == 2) return 4;
    return 3;
}

int FeetToBitmask(Feet feet)
{
    return (1 << feet.first) | (1 << feet.second);
}

int GetMinStepsCost(int index, Feet feet)
{
    // if(index != 0 && feet.first == feet.second) return 400001;
    if(index == N - 1) return 0;
    int& ret = cache[index][FeetToBitmask(feet)];
    if(ret != -1) return ret;
    int next_step = steps[index];
    int leftCost = GetStepCost(feet.first, next_step);
    int nextLeft = GetMinStepsCost(index + 1, {next_step, feet.second});
    int rightCost = GetStepCost(feet.second, next_step);
    int nextRight = GetMinStepsCost(index + 1, {feet.first, next_step});
    ret = min(leftCost + nextLeft, rightCost + nextRight);
    return ret;
}


void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    int step = 0;
    do
    {
        cin >> step;
        steps.push_back(step);
    } 
    while (step != 0);
    N = steps.size();
    cache = vector<vector<int>>(N - 1, vector<int>(((1 << 4 | 1 << 3) + 1), -1));
}

void Solution()
{
    Input();
    cout << GetMinStepsCost(0, {0, 0}) << endl;
    cout << endl;
}