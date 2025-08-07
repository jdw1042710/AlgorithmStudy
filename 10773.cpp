#include <iostream>
#include <stack>

using namespace std;


void Solution();

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    int K;
    cin >> K;
    cin.ignore();
    long long result = 0;
    stack<int> st;
    for(int i = 0; i < K; ++i)
    {
        int num;
        cin >> num;
        cin.ignore();
        if(num == 0)
        {
            result -= st.top();
            st.pop();
        }
        else
        {
            result += num;
            st.push(num);
        }
    }
    cout << result << endl;
}
