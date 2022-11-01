#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n, count = 1;
    vector<int> stack;
    string answer = "";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cin.ignore();

        if(temp >= count){
            while (temp >= count){
                answer += "+\n";
                stack.push_back(count);
                count++;
            }
            stack.pop_back();
            answer += "-\n";

        }else if(temp == stack.back()){
            answer += "-\n";
            stack.pop_back();
        }else{
            answer = "NO";
            break;
        }
    }

    cout << answer;
}