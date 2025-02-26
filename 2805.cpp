#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

void Solution(int m, const vector<int>& trees);
int DivCon(int min, int max, int m, const vector<int>& trees);

vector<int> Split(string str)
{
    vector<int> result;
    stringstream ss(str);
    string temp;
    while(getline(ss, temp, ' '))
    {
        result.push_back(stoi(temp));
    }
    return result;
}

int main()
{
    int n, m;
    string str_trees;
    vector<int> trees;
    cin >> n >> m;
    cin.ignore();
    getline(cin, str_trees);
    trees = Split(str_trees);
    Solution(m, trees);
}

void Solution(int m, const vector<int>& trees)
{
    int answer = 0;
    int max = trees[0];
    for(int i = 1; i < trees.size(); ++i)
    {
        max = std::max(max, trees[i]);
    }
    answer = DivCon(0, max, m, trees);
    cout << answer << endl;
}

int DivCon(int min, int max, int m, const vector<int>& trees)
{
    long long sum = 0;
    int h = (min + max) / 2;
    if (min == h || max == h) return h;
    for(int tree : trees)
    {
        sum += std::max(0, tree - h);
    }
    // cout << min << "," << max << " : " <<  sum << endl;
    if(sum == m) return h;
    else if(sum > m) return DivCon(h, max, m, trees);
    else return DivCon(min, h, m, trees);
}