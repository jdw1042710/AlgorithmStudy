#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

struct Permutation
{

    int p = 0;
    // vector<int> nums;
    int size = 0;

    void AddNum(int num)
    {
        if(size == 0)
        {
            p = num;
        }
        else
        {
            p = p * 10 + num;
        }
        // nums.push_back(num);
        ++size;
    }

    // GetNum/SetNum에 사용되는 변수
    static long long indexing[11]; // 1, 10, 100 ....
    int GetNum(const int index)
    {
        return p % indexing[index] / indexing[index + 1];
    }

    void SetNum(const int index, const int num)
    {
        p -= GetNum(index) * indexing[index  + 1];
        p += num * indexing[index + 1];
    }

    int ToInt() const
    {
        return p;
    }

    bool IsNonDecreasing()
    {
        if(size == 0) return true;
        int exNum = GetNum(0);
        for(int i = 1; i < size; ++i)
        {
            int curNum = GetNum(i);
            if(exNum > curNum) return false;
            exNum = curNum;
        }
        return true;
    }
    // bool operator<(const Permutation& other) const
    // {
    //     return p < other.p;
    // }
};
long long Permutation::indexing[11];

struct Operation
{
    size_t indexA;
    size_t indexB;
    int cost;

    int Swap(Permutation& p)
    {
        int temp = p.GetNum(indexA);
        p.SetNum(indexA, p.GetNum(indexB));
        p.SetNum(indexB, temp);
        return cost;
    }
};

int N, M;
Permutation permutation;
vector<Operation> ops;
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

    long long temp = 1;
    for (int i = N; i >= 0; --i)
    {
        Permutation::indexing[i] = temp;
        temp *= 10;
    }

    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        --num;
        permutation.AddNum(num);
    }
    cin.ignore();
    cin >> M;
    cin.ignore();
    ops = vector<Operation>(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> ops[i].indexA >> ops[i].indexB >> ops[i].cost;
        cin.ignore();
        --ops[i].indexA;
        --ops[i].indexB;
    }
}

struct Compare
{
    bool operator()(const pair<int, Permutation>& lhs, const pair<int, Permutation>& rhs)
    {
        return lhs.first > rhs.first;
    }
};

int Dijkstra(Permutation start)
{
    int ret = -1;
    map<int, int> visited;
    priority_queue<pair<int, Permutation>, vector<pair<int, Permutation>>, Compare> pq;
    visited[start.ToInt()] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        int curCost = pq.top().first;
        Permutation p = pq.top().second;
        pq.pop();
        if(p.IsNonDecreasing())
        {
            ret = curCost;
            break;
        }
        for(auto op : ops)
        {
            Permutation nextP(p);
            int nextCost = curCost + op.cost;
            op.Swap(nextP);
            auto iter = visited.find(nextP.ToInt());
            if(iter != visited.end() && (*iter).second <= nextCost) continue;
            visited[nextP.ToInt()] = nextCost;
            pq.push({nextCost, nextP});
        }
    }
    return ret;
}

/** 문제 풀이*/
void Solution()
{
    Input();
    cout << Dijkstra(permutation);
    cout << endl;
}