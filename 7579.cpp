#include <iostream>
#include <vector>

using namespace std;

long long N, M;

vector<int> capacities, prices;
vector<vector<long long>> cache;

void Solution();

long long GetMemory(int index, int price);

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin.ignore();
    for(int i = 0; i < N; ++i) 
    {
        int val;
        cin >> val;
        capacities.push_back(val);
    }
    cin.ignore();
    for(int i = 0; i < N; ++i) 
    {
        int val;
        cin >> val;
        prices.push_back(val);
    }
    cin.ignore();
    Solution();
}

// 푸는중인 문제
void Solution()
{
    cache = vector<vector<long long>>(N, vector<long long>(10001, -1));
    int result = -1;
    for(int i = 0; i < 10001; ++i)
    {
        long long mem = GetMemory(0, i);
        // cout << mem << endl;
        if(mem >= M) 
        {
            result = i;
            break;
        }
    }
    cout << result;
}

long long GetMemory(int index, int price)
{
    if(index == N) return 0;
    long long& ret = cache[index][price];
    if(ret != -1) return ret;
    ret = 0;
    if(price >= prices[index])
        ret = max(ret, GetMemory(index + 1, price - prices[index]) + capacities[index]);
    ret = max(ret, GetMemory(index + 1, price));
    return ret;
}
