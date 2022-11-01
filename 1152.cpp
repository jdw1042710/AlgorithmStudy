#include <iostream>

using namespace std;

int solution(){
    int result = 0;
    bool isWord = false;
    string input;
    getline(cin, input);
    if (input.empty()){
        return 0;
    }

    for(int i = 0; i < input.length(); i++){
        if(input[i] != ' ' && !isWord){
            result++;
            isWord = true;
        }else if(input[i] == ' '){
            isWord = false;
        }
    }
    
    return result;
}

int main(){
    int result = solution();
    cout << result << endl;
}