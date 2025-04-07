
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr, lis;

void Solution();
int GetIndex(int low, int high, int target);

int main()
{
    string str_nums;
    vector<int> nums;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        cin.ignore();
        arr.push_back(num);
    }
    Solution();
}

void Solution()
{
    lis = vector<int>({arr[0]});
    // cout << "value: " << arr[0] << " ->";
    // for(auto num : lis) cout << ' ' << num;
    // cout << endl;
    for(int i = 1; i < N; ++i)
    {
        if(lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
        }
        else
        {
            int index = GetIndex(0, lis.size() - 1, arr[i]);
            lis[index] = arr[i];
        }
        // cout << "value: " << arr[i] << " ->";
        // for(auto num : lis) cout << ' ' << num;
        // cout << endl;
    }
    cout << lis.size();
}

int GetIndex(int low, int high, int target)
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