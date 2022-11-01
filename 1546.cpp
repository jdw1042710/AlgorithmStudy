#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    double  max_score = 0, result = 0;
    vector<int> inputs;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        //cout << temp << endl;
        if(temp > max_score){
            max_score = temp;
        }
        inputs.push_back(temp);
    }
    for (int i : inputs){
        double temp = i/max_score * 100;
        //cout << i/max_score << endl;
        result += temp;
    }
    cout << result / N << endl;
}