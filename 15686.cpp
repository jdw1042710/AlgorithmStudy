#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


size_t N, M;
const int INF = 50 * 50 * 100 + 1;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

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
    for(size_t i = 0; i < N; ++i)
    {
        for(size_t j = 0; j < N; ++j)
        {
            int val;
            cin >> val;
            if(val == 1)
            {
                houses.push_back({i, j});
            }
            else if( val == 2)
            {
                chickens.push_back({i, j});
            }
        }
        cin.ignore();
    }
}

int GetChickenRoad(const vector<int>& chicken_indexes)
{
    int ret = 0;
    for(const auto& house : houses)
    {
        int min_road = INF;
        for(const auto& index : chicken_indexes)
        {
            pair<int, int> chicken = chickens[index];
            int road = abs(house.first - chicken.first) + abs(house.second - chicken.second);
            min_road = min(min_road, road);
        }
        ret += min_road;
    }
    return ret;
}

int GetMinChickenRoad(size_t index, vector<int>& chicken_indexes)
{
    if(chicken_indexes.size() == M)
        return GetChickenRoad(chicken_indexes);
    if(index == chickens.size())
        return INF;
    int ret = INF;
    ret = min(ret, GetMinChickenRoad(index + 1, chicken_indexes));
    chicken_indexes.push_back(index);
    ret = min(ret, GetMinChickenRoad(index + 1, chicken_indexes));
    chicken_indexes.pop_back();
    return ret;
}

void Solution()
{
    Input();
    vector<int> indexes;
    int result = GetMinChickenRoad(0, indexes);
    cout << result << endl;
}