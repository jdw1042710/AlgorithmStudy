#include <iostream>

using namespace std;

void Solution(string str, int n);

int main()
{
    string str;
    int n;
    cin >> str;
    cin.ignore();
    cin >> n;
    cin.ignore();
    Solution(str, n);
}

void Solution(string str, int n)
{
    cout << str[n - 1] << endl;
}
