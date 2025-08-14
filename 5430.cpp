#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

void Input();
void Solution();

string commands;
deque<int> arr;

deque<int> Split(string str)
{
    deque<int> result;
    stringstream ss(str.substr(1, str.size() - 2));
    string temp;
    while(getline(ss, temp, ','))
    {
        result.push_back(stoi(temp));
    }

    return result;
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
    getline(cin, commands);

    int N;
    cin >> N;
    cin.ignore();

    string arr_str;
    getline(cin, arr_str);
    arr = Split(arr_str); 
}

void Solution()
{
    int T;
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        bool isReversed = false;
        bool isError = false;
        for(const auto& command : commands)
        {
            if(command == 'R')
            {
                isReversed = !isReversed;
            }
            else //if(command == 'D')
            {
                if(arr.size() == 0)
                {
                    isError = true;
                    break;
                }
                if(isReversed)
                {
                    arr.pop_back();
                }
                else
                {
                    arr.pop_front();
                }
            }
        }

        if(isError)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << '[';
            if(isReversed)
            {
                for(int j = arr.size() - 1; j >= 0; --j)
                {
                    cout << arr[j];
                    if(j != 0) cout << ',';
                }
            }
            else
            {
                for(size_t j = 0; j < arr.size(); ++j)
                {
                    cout << arr[j];
                    if(j != arr.size() - 1) cout << ',';
                }
            }
            cout << ']' << endl;
        }
    }

}