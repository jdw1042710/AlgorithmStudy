#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, W;
vector<pair<int, int>> cases;
vector<vector<int>> cache;
vector<vector<int>> cache_car;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

/** 데이터 입력 및 전처리*/
void Input()
{
    cin >> N;
    cin.ignore();
    cin >> W;
    cin.ignore();
    cases = vector<pair<int, int>>(W + 1);
    for(int i = 0; i < W; ++i)
    {
        int row, col;
        cin >> row >> col;
        cin.ignore();
        cases[i + 1] = {row, col};
    }

    cache = vector<vector<int>>(W + 1, vector<int>(W + 1, -1));
    cache_car = vector<vector<int>>(W + 1, vector<int>(W + 1));
}

int GetDistance(pair<int, int> from, pair<int, int> to)
{
    return abs(from.first - to.first) + abs(from.second - to.second);
}

/**
 * DP를 이용한 DFS
 * @param car1 car1이 마지막으로 처리한 case의 번호
 * @param car2 car2가 마지막으로 처리한 case의 번호
 * @return 모든 사건을 처리한 후, 이동하는데 걸린 거리들의 최소 합
*/
int DFS(int car1, int car2)
{
    if (car1 == W || car2 == W) return 0;
    int& ret = cache[car1][car2];
    if (ret != -1) return ret;
    int curCase = max(car1, car2) + 1;
    int dist1, dist2;
    dist1 = GetDistance((car1 == 0 ? pair<int, int>(1, 1) : cases[car1]), cases[curCase]);
    dist2 = GetDistance((car2 == 0 ? pair<int, int>(N, N) : cases[car2]), cases[curCase]);
    int ret1, ret2;
    ret1 = dist1 + DFS(curCase, car2);
    ret2 = dist2 + DFS(car1, curCase);
    ret = min(ret1, ret2);
    cache_car[car1][car2] = ret1 < ret2 ? 1 : 2;
    return ret;
}

/**
 * cache_car 값을 기반으로 DFS를 통해 각 case를 해결한 car의 번호를 출력
 * @param car1 car1이 마지막으로 처리한 case의 번호
 * @param car2 car2가 마지막으로 처리한 case의 번호
*/
void PrintRoute(int car1, int car2)
{
    if (car1 == W || car2 == W) return;
    int ret = cache_car[car1][car2];
    cout << ret << '\n';
    int next = max(car1, car2) + 1;
    if(ret == 1) car1 = next;
    else car2 = next;
    PrintRoute(car1, car2);
}

/** 문제 풀이*/
void Solution()
{
    Input();
    int result = DFS(0, 0);
    cout << result << '\n';
    PrintRoute(0, 0);
    cout << endl;
}