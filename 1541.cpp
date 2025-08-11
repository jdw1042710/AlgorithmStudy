#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Solution();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    Solution();

    return 0;
}

void Solution()
{
    string expression;
    cin >> expression;

    int result = 0;
    string str_num = "";
    bool isMinus = false;
    for(size_t i = 0; i <= expression.size(); ++i)
    {


        bool isParsed = expression[i] == '-' || expression[i] == '+' || i == expression.size();
        if(isParsed)
        {
            if(isMinus)
            {
                result -= stoi(str_num);
                str_num = "";
            }
            else
            {
                result += stoi(str_num);
                str_num = "";
            }

            if(expression[i] == '-') isMinus = true;
        }
        else
        {
            str_num += expression[i];
        }
    }

    cout << result << endl;
}