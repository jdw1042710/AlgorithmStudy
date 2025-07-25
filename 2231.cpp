#include <iostream>
#include <vector>

using namespace std;

int N;

void Input();
void Solution();

int ParsedSum(int num)
{
    int sum = 0;
    while(num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

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
    int answer = 0;
    for(int i = 1; i < N; ++i)
    {
        int parsedSum = ParsedSum(i);
        if(i + parsedSum == N)
        {
            answer = i;
            break;
        }
    }
    cout << answer << endl;
}