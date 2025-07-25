#include <iostream>
#include <vector>

using namespace std;

int N;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N;
}

void Solution()
{
    Input();
    int count = 0;
    int lower_bound = 0;
    int upper_bound = 0;
    while(!(lower_bound <= N - 1 && N - 1 <= upper_bound))
    {
        ++count;
        lower_bound = upper_bound + 1;
        upper_bound += count * 6;
    }
    cout << count + 1 << endl;
}