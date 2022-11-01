#include <iostream>

using namespace std;

int w, h;
int arr[50][50];
bool isVisited[50][50] = {false};
int dir_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dir_r[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void DFS(int, int);

void DFS(int r, int c){
    isVisited[r][c] = true;
    for (int i = 0 ; i < 8; i++){
        int nxt_r = r + dir_r[i];
        int nxt_c = c + dir_c[i]; 
        if (nxt_r > -1 && nxt_r < h && nxt_c > -1 && nxt_c < w){
            //cout << "CHECK : " << nxt_r << " " << nxt_c << endl;
            if(arr[nxt_r][nxt_c] == 1 && !isVisited[nxt_r][nxt_c]){
                DFS(nxt_r, nxt_c);
            }
        }
    }
}

int solution(){
    int result = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(arr[i][j] == 1 && !isVisited[i][j]){
                //cout << "탐색" << i << " " << j << endl;
                DFS(i, j);
                result++;
            }
        }
    }
    return result;
}

int main(){
    while(true){
        cin >> w >> h;
        cin.ignore();
        if (w == 0 && h == 0){
            break;
        }
        for(int i = 0; i < h; i++){
            string temp;
            getline(cin, temp);
            for (int j = 0; j < w; j++){
                arr[i][j] = temp[j * 2] - '0';
                isVisited[i][j] = false;
            }
        }

        cout << solution() << endl;
    }
    
}