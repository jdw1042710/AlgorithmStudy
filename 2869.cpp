#include <iostream>
#include <cmath>

using namespace std;


void Solution();


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    int A, B, V;
    cin >> A >> B >> V;
    int day = ceil((double)(V - A) / (double)(A - B)) + 1;
    cout << day << endl;
}
