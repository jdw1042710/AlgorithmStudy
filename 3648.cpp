#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int>> adjacence; // 함의 그래프의 인접성을 나타낸 배열
vector<int> discovered; // 각 노드별 방문 순서
vector<int> sccGroup; // 각 노드별 scc 그룹 번호

int order = 0; // SSC시 방문 순서
int id = 0; // SSC시 결합 순서

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

int GetTrueNode(int num)
{
    return (num << 1); // 곱하기 2;
}

int GetFalseNode(int num)
{
    return (num << 1 | 1); // 곱하기 2 + 1;
}

void MergeOr(int a, int b)
{
    adjacence[a ^ 1].push_back(b);
    adjacence[b ^ 1].push_back(a);
}

int SCC(int index, stack<int>& st)
{
    int ret = discovered[index] = order++;
    st.push(index);
    for(auto next : adjacence[index])
    {
        if(discovered[next] == -1)
            ret = min(ret, SCC(next, st));
        else if(sccGroup[next] == -1)
            ret = min(ret, discovered[next]);
    }
    if(ret == discovered[index])
    {
        while(true)
        {
            int v = st.top();
            st.pop();
            sccGroup[v] = id;
            if(v == index) break;
        }
        ++id;
    }

    return ret;
}

bool Solve2Sat()
{
    stack<int> stack; // SCC용 스택;
    order = 0;
    id = 0;
    for(int i = 0; i < (N << 1); ++i)
    {
        if(discovered[i] != -1) continue;
        SCC(i, stack);
    }
    if(sccGroup[0] > sccGroup[1])
        return false;
    for(int i = 0; i < N; ++i)
    {
        int notI = i ^ 1;
        if(sccGroup[i] == sccGroup[notI])
            return false;
    }

    return true;
}

void Input()
{
    adjacence = vector<vector<int>>(N << 1, vector<int>()); // 2N 크기의 배열 생성
    discovered = sccGroup = vector<int>(N << 1, -1);
    
    for(int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        // 참노드는 절댓값 * 2, 거짓노드는 절댓값 * 2 + 1;
        a = a > 0 ? GetTrueNode(a - 1) : GetFalseNode(-a - 1);
        b = b > 0 ? GetTrueNode(b - 1) : GetFalseNode(-b - 1);
        MergeOr(a, b);
    }
    MergeOr(1, 0); // if 상근 false -> true 추가
}

void Solution()
{
    while(cin >> N >> M)
    {
        Input();
        cout << (Solve2Sat() ? "yes" : "no") << '\n';
    }
    cout << endl;
}