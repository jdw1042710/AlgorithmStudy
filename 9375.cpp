#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N;
map<string, int> numClothes;


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
    numClothes.clear();
    for(int i = 0; i < N; ++i)
    {
        string name, type;
        cin >> name >> type;
        cin.ignore();
        if(numClothes.find(type) == numClothes.end())
        {
            numClothes[type] = 1;
        }
        else
        {
            ++numClothes[type];
        }
    }
}

void Solution()
{
    int T;
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        int result = 1;
        for(auto data : numClothes)
        {
            result *= (data.second + 1);
        }
        --result; // 알몸 제외

        cout << result << endl;
    }
}