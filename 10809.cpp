#include <iostream>
#include <string>

using namespace std;

void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    string str[3];
    int num[3];

    for(int i = 0; i < 3; ++i)
    {
        getline(cin, str[i]);
        num[i] = stoi(str[i]);
    }
    cout << num[0] + num[1] - num[2] << endl;
    cout << stoi(str[0] + str[1]) - num[2] << endl;


}