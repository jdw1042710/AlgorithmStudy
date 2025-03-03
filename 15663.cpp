#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int n, m;

void Solution(const vector<int>& nums);

void MakeSeq(int mask, vector<int>& seq, const vector<int>& nums);
void PrintSeq(const vector<int>& seq);

void Split(string str, vector<int>& output)
{
    stringstream ss(str);
    string temp;
    while(getline(ss, temp, ' '))
    {
        output.push_back(stoi(temp));
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str_nums;
    vector<int> nums;
    cin >> n >> m;
    cin.ignore();
    getline(cin, str_nums);
    Split(str_nums, nums);
    sort(nums.begin(), nums.end());
    Solution(nums);
}     

void Solution(const vector<int>& nums)
{
    vector<int> seq;
    MakeSeq(0, seq, nums);
}

void MakeSeq(int mask, vector<int>& seq, const vector<int>& nums)
{
    // cout << index << ":" << mask << ":" << count << endl;
    if(seq.size() == m)
    {
        PrintSeq(seq);
        return;
    }
    int ex_num = -1;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(mask & (1 << i)) continue;
        if(ex_num == nums[i]) continue;
        ex_num = nums[i];
        mask |= (1 << i);
        seq.push_back(nums[i]);
        MakeSeq(mask, seq, nums);
        seq.pop_back();
        mask &= ~(1 << i);
    }
}

void PrintSeq(const vector<int>& seq)
{
    for(auto num : seq)
        cout << num << ' ';
    cout << '\n';
}