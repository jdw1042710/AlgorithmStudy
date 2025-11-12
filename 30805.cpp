#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;



int N, M;
vector<pair<int, int>> A, B;

void Input();
void Solution();

bool Compare(pair<int, int> lhs, pair<int, int> rhs)
{
    if(lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first > rhs.first;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        A.push_back({num, i});
    }
    cin.ignore();
    cin >> M;
    cin.ignore();
    for(int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        B.push_back({num, i});
    }
    cin.ignore();
}

vector<int> FindMaxCommonNumber(size_t indexA, size_t indexB, vector<pair<int, int>>& A, vector<pair<int, int>>& B)
{
    vector<int> DLCS;
    sort(A.begin(), A.end(), Compare);
    sort(B.begin(), B.end(), Compare);
    int lastAIndex = 0;
    int lastBIndex = 0;
    while(indexA < A.size() && indexB < B.size())
    {
        int curANum = A[indexA].first;
        int curAIndex = A[indexA].second;
        int curBNum = B[indexB].first;
        int curBIndex = B[indexB].second;
        if(curANum == curBNum)
        {
            if(curAIndex < lastAIndex)
            {
                ++indexA;
            }
            else if(curBIndex < lastBIndex)
            {
                ++indexB;
            }
            else
            {
                DLCS.push_back(curANum);
                ++indexA;
                ++indexB;
                lastAIndex = curAIndex;
                lastBIndex = curBIndex;
            }

        }
        else if(curANum > curBNum)
        {
            ++indexA;
        }
        else // if(curANum < curBNum)
        {
            ++indexB;
        }

    }
    return DLCS;
}

void Solution()
{
    Input();
    vector<int> result = FindMaxCommonNumber(0, 0, A, B);
    cout << result.size() << endl;
    for(auto iter : result)
        cout << iter << ' ';
    cout << endl;
}