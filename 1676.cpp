#include <iostream>
#include <vector>

using namespace std;

void Input();
void Solution();


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}


void Solution()
{
    long long N;
    cin >> N;
    int result = 0;
    for(int i = 5; i <= N; i *= 5)
    {
        result += (N / i);
    }

    cout << result << endl;
}