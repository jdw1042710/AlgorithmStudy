#include <iostream>
#include <string>
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
    string input;
    while(true)
    {
        getline(cin, input);
        stack<char> st;
        for(auto ch : input)
        {
            if(ch == '(' || ch == '[')
            {                
                st.push(ch);
            }
            else if (ch == ')')
            {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                {
                    st.push('.');
                    break;
                }

            }
            else if (ch == ']')
            {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                {
                    st.push('.');
                    break;
                }
            }
        }
        if(input == ".") 
            break;

        if(st.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        

    }
}
