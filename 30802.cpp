#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void Solution(int n, int t, int p, const vector<int> sizes);

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
    int n, t, p;
    string str_sizes;
    vector<int> sizes;
    cin >> n;
    cin.ignore();
    getline(cin, str_sizes);
    sizes = Split(str_sizes);
    cin >> t >> p;
    cin.ignore();
    Solution(n, t, p, sizes);
}

void Solution(int n, int t, int p, const vector<int> sizes)
{
    int tBundle = 0, pBundle = 0, pRest = 0;
    for(auto size : sizes)
    {
        tBundle += size / t;
        tBundle += size % t != 0 ? 1 : 0;
    }
    pBundle = n / p;
    pRest = n % p;
    cout << tBundle << endl;
    cout << pBundle << ' ' << pRest << endl;
}
