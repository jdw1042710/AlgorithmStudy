#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<long long> nums, tree;


void Input();
void Solution();


void SetNumOnSegTree(int left, int right, int node, const int index, const long long diff)
{
    if(left > index || right < index) return;
    tree[node] += diff;
    if(left == right) return;
    int mid = (left + right) / 2;
    SetNumOnSegTree(left, mid, node * 2, index, diff);
    SetNumOnSegTree(mid + 1, right, node * 2 + 1, index, diff);
}

void SetNumOnSegTree(int index, long long num)
{
    SetNumOnSegTree(0, N - 1, 1, index, num - nums[index]);
    nums[index] = num;
}


long long GetNumFromSegTree(int left, int right, int node, const int start, const int end)
{
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return tree[node];
    int mid = (left + right) / 2;
    return GetNumFromSegTree(left, mid, node * 2, start, end) 
        + GetNumFromSegTree(mid + 1, right, node * 2 + 1, start, end);
}

long long GetNumFromSegTree(int start, int end)
{
    return GetNumFromSegTree(0, N - 1, 1, start, end);
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> M >> K;
    cin.ignore();
    tree = vector<long long>(4 * N, 0);
    nums = vector<long long>(N, 0);
    for(int i = 0; i < N; ++i)
    {
        long long num;
        cin >> num;
        cin.ignore();
        SetNumOnSegTree(i, num);
    }
}

void Solution()
{
    Input();
    for(int i = 0; i < M + K; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cin.ignore();
        if(a == 1)
        {
            SetNumOnSegTree(b - 1, c);
        }
        else
        {
            cout << GetNumFromSegTree(b - 1, c - 1) << '\n';
        }
    }
}