#include <iostream>
#include <vector>

using namespace std;

int N;
const int MaxNum = 1'000'001;

vector<int> cards;
vector<int> ids(MaxNum, -1);
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
    cards = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cards[i];
        ids[cards[i]] = i;
    }
}

/** 문제 풀이*/
void Solution()
{
    Input();
    vector<int> result(N);
    for (int i = 0; i < N; ++i)
    {
        int curNum = cards[i];
        for (long long j = curNum * 2; j < MaxNum; j += curNum)
        {
            if(ids[j] == -1) continue;
            ++result[i];
            --result[ids[j]];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
}