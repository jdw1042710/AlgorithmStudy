#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void Input();
void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    int ex_num;
    string result = "mixed";
    cin >> ex_num;
    if(ex_num == 1)
    {
        bool flag = true;
        int cur_num;
        for(int i = 0; i < 7; ++i)
        {
            cin >> cur_num;
            if(ex_num + 1 != cur_num)
            {
                flag = false;
                break;
            }
            ex_num = cur_num;
        }
        if(flag)
        {
            result = "ascending";
        }
    }
    else if(ex_num == 8)
    {
        bool flag = true;
        int cur_num;
        for(int i = 0; i < 7; ++i)
        {
            cin >> cur_num;
            if(ex_num - 1 != cur_num)
            {
                flag = false;
                break;
            }
            ex_num = cur_num;
        }
        if(flag)
        {
            result = "descending";
        }
    }
    cout << result << endl;
}