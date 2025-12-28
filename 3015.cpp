#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint32_t;

int N, M;

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
}

void Solution()
{
    Input();
    long long result = 0;
    vector<pair<uint32_t, uint32_t>> st; // 스택
    for(int i = 0; i < N; ++i)
    {
        uint32_t h;
        cin >> h;
        cin.ignore();
        uint32_t depth = 1;
        while(!st.empty() && st.back().first <= h)
        {
            result += st.back().second;
            if(st.back().first == h)
                depth = st.back().second + 1;
            st.pop_back();
        }
        result += st.empty() ? 0 : 1;
        st.push_back({h, depth});
    }
    cout << result << endl;
}