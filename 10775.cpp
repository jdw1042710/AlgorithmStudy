#include <iostream>
#include <vector>

using namespace std;

int G, P;
vector<int> parents;
vector<int> planes;

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
    cin >> G;
    cin.ignore();
    parents = vector<int>(G + 1, 0);
    for(int i = 1; i < G + 1; ++i)
    {
        parents[i] = i;
    }
    cin >> P;
    cin.ignore();
    planes = vector<int>(P);
    for(int i = 0; i < P; ++i)
    {
        int gate;
        cin >> gate;
        cin.ignore();
        planes[i] = gate;
    }
}

int GetParent(int n)
{
    if(parents[n] == n) return n;
    return parents[n] = GetParent(parents[n]);
}

void Solution()
{
    Input();
    int index = 0;
    while(index != P)
    {
        int gate = GetParent(planes[index]);
        // 비행기를 도킹하지 못하는 경우
        if(gate == 0) break;
        parents[gate] = gate - 1;
        ++index;
    }
    cout << index << endl;
}