#include <iostream>
#include <string>

using namespace std;

int num = 0;
int numIndex = 0;

void Input();
void Solution();

long long Round(double num)
{
    return num + 0.5;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    for(int i = 0; i < 3; ++i)
    {
        string str;
        getline(cin, str);
        if(str.find("Fizz") == string::npos 
        && str.find("Buzz") == string::npos)
        {
            num = stoi(str);
            numIndex = i;
        }
    }
}

void Solution()
{
    Input();
    int target = num + 3 - numIndex;
    if(target % 3 == 0 && target % 5 == 0)
    {
        cout << "FizzBuzz" << endl;
    }
    else if(target % 3 == 0)
    {
        cout << "Fizz" << endl;
    }
    else if(target % 5 == 0)
    {
        cout << "Buzz" << endl;
    }
    else
    {
        cout << target << endl;
    }

}