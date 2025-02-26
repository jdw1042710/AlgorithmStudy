#include <iostream>
#include <vector>

using namespace std;

void Solution(string num);

int main()
{
    int N = 0;
    string num;
    cin >> N;
    cin.ignore();
    cin >> num;
    cin.ignore();
    Solution(num);
}

void Solution(string num)
{
    long long answer = 0;
    for(auto c : num)
    {
        int digit = c - '0';
        answer += digit;
    }
    cout << answer << endl;
}
