
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> arr, parents;

void Solution();
int GetIndex(int low, int high, int target, const vector<int>& lis);


int main()
{
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        cin.ignore();
        arr.push_back(num);
        parents.push_back(i);
    }
    Solution();
}

void Solution()
{
    vector<int> lis, lis_index;
    lis = vector<int>({arr[0]});
    lis_index = vector<int>({0});
    int last_index = 0;
    // cout << "value: " << arr[0] << " ->";
    // for(auto num : lis) cout << ' ' << num;
    // cout << endl;
    for(int i = 1; i < N; ++i)
    {
        if(lis.back() < arr[i])
        {
            // cout << "New Value Push\n";
            parents[i] = lis_index.back();
            lis.push_back(arr[i]);
            lis_index.push_back(i);
            last_index = i;
        }
        else
        {
            int index = GetIndex(0, lis.size() - 1, arr[i], lis);
            // cout << "Inset Value : " << index << '\n';
            lis[index] = arr[i];
            lis_index[index] = i;
            parents[i] = lis_index[max(0, index - 1)];
        }
        // cout << "value: " << arr[i] << " ->";
        // for(auto num : lis) cout << ' ' << num;
        // cout << endl;
    }
    cout << lis.size() << '\n';
    stack<int> st;
    st.push(last_index);
    while(st.top() != parents[st.top()])
    {
        st.push(parents[st.top()]);
    }
    
    while(!st.empty())
    {
        cout << arr[st.top()] << ' ';
        st.pop();
    }
}

int GetIndex(int low, int high, int target, const vector<int>& lis)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(target <= lis[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}