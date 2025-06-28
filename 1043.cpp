#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
//vector<int> parents;
int parents[51] = {0};
vector<vector<int>> parties;

void Input();
void Solution();

int GetParent(int n)
{
    if(parents[n] == n) return n;
    return GetParent(parents[n]);
}

void Union(int a, int b)
{
    int aP = GetParent(a);
    int bP = GetParent(b);

    if(aP == bP) return;
    if(aP > bP) swap(aP, bP);
    parents[bP] = aP;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> M;
    cin.ignore();

    // parents = vector<int>(N + 1);
    for(int i = 0; i < N + 1; ++i) parents[i] = i;

    int num = 0;
    cin >> num;
    // 진실을 아는 사람들의 부모를 0으로 설정
    for(int i = 0; i < num; ++i)
    {
        int input;
        cin >> input;
        parents[input] = 0;
    }
    cin.ignore();

    parties = vector<vector<int>>(M);
    for(int i = 0; i < M; ++i)
    {
        cin >> num;
        for(int j = 0; j < num; ++j)
        {
            int people;
            cin >> people;
            parties[i].push_back(people);
        }
        cin.ignore();
        // 파티에 참석만 모든 사람을 하나의 집합으로 합친다
        for(int j = 1; j < num; ++j)
        {
            Union(parties[i][j - 1], parties[i][j]);
        }
    }
}

void Solution()
{
    Input();
    int result = 0;
    for(int i = 0; i < M; ++i)
    {
        if(GetParent(parties[i][0]) != 0) ++result;
    }
    cout << result << endl;;
}
