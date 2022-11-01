#include <iostream>

using namespace std;

int solution(string str, int ptr1, int ptr2, bool chance){
    while (ptr1 < ptr2){
        //cout << "CHECK : " << str[ptr1]  << " " << str[ptr2] << " " << chance << endl;
        if(str[ptr1] != str[ptr2]){
            if(chance){
                chance = false;
                int temp_a = solution(str, ptr1, ptr2 - 1, false);
                int temp_b = solution(str, ptr1 + 1, ptr2, false);
                if(temp_a == 1){
                    ptr2--;
                }else if(temp_b == 1){
                    ptr1++;
                }else{
                    return 2;
                }
            }else{
                return 2;
            }
        }
        ptr1++;
        ptr2--;
    }
    if(chance){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    int T;
    string str;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++){
        cin >> str;
        cin.ignore();
        cout << solution(str, 0, str.length() - 1, true) << endl;
    }
}