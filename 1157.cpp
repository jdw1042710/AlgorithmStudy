#include <iostream>
#include <cctype>

using namespace std;

int main(){
    int count[26] = {0};
    int max = -1;
    string input;
    char result = '?';
    cin >> input;
    for(char& alpha : input){
        char temp = toupper(alpha);
        count[temp - 'A'] += 1;
        //cout << temp << " : " << temp - 'A' << endl;
    }
    //cout << "result:" << endl;
    for(int i  = 0; i < 26; i++){
        //cout << (char)('A' + i) << " : " << count[i] << endl;
        if (count[i] > max){
            result = 'A' + i;
            max = count[i];
        }else if (count[i] == max){
            result = '?';
        }
        //cout << result << endl;
    }

    cout << result << endl;
}