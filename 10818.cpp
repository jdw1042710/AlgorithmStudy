#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void Solution(const vector<int>& nums);

vector<int> Split(string s){
    vector<int> result;
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, ' ')){
        result.push_back(stoi(temp));
    }
    return result;
}

int main()
{
    int N = 0;
    string str_nums;
    vector<int> nums;
    cin >> N;
    cin.ignore();
    getline(cin, str_nums);
    nums = Split(str_nums);
    Solution(nums);
}

void Solution(const vector<int>& nums)
{
    int min, max;
    min = max = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        int num = nums[i];
        if(num < min)
        {
            min = num;
        }
        if(num > max)
        {
            max = num;
        }
    }
    cout << min << ' ' << max << endl;
}
