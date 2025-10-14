#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> skewer;

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
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        skewer.push_back(num);
    }

}

void Solution()
{
    Input();
    int result = 0;
    int type_count = 0;
    vector<int> fruit_count(10, 0);
    int start = 0, end = -1;
    while(true)
    {
        // end를 증가시킴
        ++end;
        if(end == N) break;
        if(fruit_count[skewer[end]] == 0)
            ++type_count;
        ++fruit_count[skewer[end]];
        // type이 3을 넘어간다면 start를 증가시킴
        if(type_count > 2)
        {
            --fruit_count[skewer[start]];
            if(fruit_count[skewer[start]] == 0)
                --type_count;
            ++start;
        }
        result = max(result, end - start + 1);
    }
    cout << result << endl;
}