#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// vector<string> split(string input, char delimiter);

int main(){
    int a, b;
    //vector<string> inputs;
    cin >> a >> b; 
    cout << a + b << endl;
}
/*
vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    return result;
}
*/