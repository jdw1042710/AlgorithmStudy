#include <iostream>
#include <string>
#include <deque>

using namespace std;

string input;
string explosion_word;

void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    getline(cin, input);
    getline(cin, explosion_word);
}

void Solution()
{
    Input();
    deque<char> st, temp;

    for(const auto& ch : input)
    {
        st.push_back(ch);
        if(ch == explosion_word.back())
        {
            int idx = explosion_word.length() - 1;
            while(idx >= 0 && st.size())
            {
                if(st.back() != explosion_word[idx])
                    break;
                temp.push_back(st.back());
                st.pop_back();
                --idx;
            }
            if(idx >= 0)
            {
                while(temp.size())
                {
                    st.push_back(temp.back());
                    temp.pop_back();
                }
            }
            temp.clear();
        }
    }

    if(st.size())
    {
        for(const auto& iter : st)
        {
            cout << iter;
        }
    }
    else
    {
        cout << "FRULA";
    }
    cout << endl;
}