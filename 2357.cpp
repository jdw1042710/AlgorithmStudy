#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
long long INF = 1'000'000'001ll;

typedef pair<long long, long long> pll;
// 입력된 숫자
vector<long long> arr;

// 0 ~ N - 1번째 arr숫자의 {최소, 최대}값을 가진 세그먼트 트리
vector<pll> tree;

void Input();
void Solution();
void CreateSegment(int node, int start, int end);

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
    cin >> N >> M;
    cin.ignore();
    arr = vector<long long>(N, 0);
    tree = vector<pll>(4 * N);
    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        cin.ignore();
    }
    CreateSegment(1, 0, N - 1);
}

/** arr배열을 통해 세그먼트 트리를 생성 */
void CreateSegment(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = {arr[end], arr[end]};
        return;
    }
    int mid = (start + end) / 2;
    int lNode = node * 2;
    int rNode = node * 2 + 1;
    CreateSegment(lNode, start, mid);
    CreateSegment(rNode, mid + 1, end);
    tree[node] = {min(tree[lNode].first, tree[rNode].first), max(tree[lNode].second, tree[rNode].second)};
}

/** first ~ last 범위 내의 최대 최소값을 세그먼트 트리를 이용해 반환 */
pll FindWithSegment(int first, int last, int node, int start, int end)
{
    if(end < first || last < start) return {INF, -INF};
    if(first <= start && end <= last) return tree[node];

    int mid = (start + end) / 2;
    int lNode = node * 2;
    int rNode = node * 2 + 1;
    pll lSeg = FindWithSegment(first, last, lNode, start, mid);
    pll rSeg = FindWithSegment(first, last, rNode, mid + 1, end);
    return {min(lSeg.first, rSeg.first), max(lSeg.second, rSeg.second)};
}

/** 문제 풀이*/
void Solution()
{
    Input();
    long long first, last;
    for (int i = 0; i < M; ++i)
    {
        cin >> first >> last;
        --first, --last;
        cin.ignore();
        pll ret = FindWithSegment(first, last, 1, 0, N - 1);
        cout << ret.first << ' ' << ret.second << '\n';
    }
    // cout << endl;
}