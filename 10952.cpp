#include <iostream>

using namespace std;

void Solution();

int main()
{
    Solution();
}

void Solution()
{
    int a = 0, b = 0;
    while(true)
    {
        cin >> a >> b;
        cin.ignore();
        if (a == 0 && b == 0)
            break; 
        cout << a + b << endl;
    }
}
