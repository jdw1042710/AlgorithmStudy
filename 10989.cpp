#include <iostream>
#include <vector>

using namespace std;


int N;
vector<int> nums;

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
    nums = vector<int>(10001, 0);
    for(int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        cin.ignore();
        nums[a] += 1;
    }

}

void Solution()
{
    Input();
    for(int i = 1; i < 10001; ++i)
    {
        for(int j = 0; j < nums[i]; ++j)
            cout << i << '\n';
    }
}
