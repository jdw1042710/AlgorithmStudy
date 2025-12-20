#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1'000'001;

int N;

// n번째 요소 : n만큼 맛있는 캔디의 개수
vector<long long> arr(MAX);

// (왼쪽부터) n번째 리프노드 : arr[n]과 동일, 부모노드: 자식노드 값의 합
vector<long long> tree(4 * MAX);

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

}

/** tasty를 하위노드로 가지는 tree의 노드를 수정*/
void UpdateSegment(int tasty, long long num, int node, int start, int end)
{
    if(tasty < start || tasty > end) return;
    if(start == end)
    {
        tree[node] = num;
        return;
    }
    int mid = (start + end) / 2;
    int lNode = node * 2;
    int rNode = node * 2 + 1;
    UpdateSegment(tasty, num, lNode, start, mid);
    UpdateSegment(tasty, num, rNode, mid + 1, end);
    tree[node] = tree[lNode] + tree[rNode];
}

/** arr와 tree의 데이터를 수정*/
void Update(int tasty, long long num)
{
    arr[tasty] += num;
    UpdateSegment(tasty, arr[tasty], 1, 1, MAX - 1);
}

/** tree에서 rank번째 개수의 tasty를 찾기*/
long long FindWithSegment(long long rank, int node, int start, int end)
{
    if(start == end) return end;
    int mid = (start + end) / 2;
    // 왼쪽 노드가 rank개보다 크면
    if(tree[node * 2] >= rank)
        // 왼쪽노드 탐색
        return FindWithSegment(rank, node * 2, start, mid);
    else    
        // 오른쪽 노드 탐색
        return FindWithSegment(rank - tree[node * 2], node * 2 + 1, mid + 1, end);
}

long long Find(long long rank)
{
    long long ret = FindWithSegment(rank, 1, 1, MAX - 1);
    Update(ret, -1);
    return ret;
}



/** 문제 풀이*/
void Solution()
{
    Input();
    int type;
    long long tasty, num;
    for (int i = 0; i < N; ++i)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> num;
            cout << Find(num) << '\n';
        }
        else
        {
            cin >> tasty >> num;
            Update(tasty, num);
        }
        cin.ignore();
    }
    // cout << endl;
}