
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int C, N, M;
vector<int> seats;
vector<vector<int>> cache;

void Input();
void Solution();
int DFS(int row, int exRowState);

bool CheckAdjacency(int bit)
{
    // for (int i = 0; i < M - 1; ++i)
    // {
	// 	int val = (3 << i);
	// 	if ((bit & val) == val) return false;
	// }
    for (int i = 0; i < M; ++i) {
		if ((1 << i) & bit)
        {
			if (i > 0 && ((1 << (i - 1)) & bit)) return false;
			if ((1 << (i + 1)) & bit) return false;
		}
	}
	return true;
} 

bool CheckCheating(int bit, int ex_bit)
{
	for (int i = 0; i < M; ++i) {
		if ((1 << i) & bit)
        {
			if (i > 0 && ((1 << (i - 1)) & ex_bit)) return false; // 왼쪽 앞에 있는 경우
			if ((1 << (i + 1)) & ex_bit) return false; //오른쪽 앞에 있는 경우
		}
	}
    return true;
}

int PopCount(int bit)
{
    int cnt = 0;
    while(bit)
    {
        if(bit & 1) ++cnt;
        bit /= 2;
    }
    return cnt;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    Solution();
}

void Input()
{
    cin >> N >> M;
    cin.ignore();
    seats = vector<int>();
    for(int i = 0; i < N; ++i)
    {
        int input = 0;
        for(int j = 0; j < M; ++j)
        {
            char temp;
            cin >> temp;
            if(temp == 'x') input |= (1 << j);
        }
        seats.push_back(input);
        cin.ignore();
    }
    cache = vector<vector<int>>(N, vector<int>(1 << M, -1));
}

void Solution()
{
    cin >> C;
    cin.ignore();
    for(int i = 0; i < C; ++i)
    {
        Input();
        cout << DFS(0, 0) << '\n';
    }
}

void Wait()
{
    string temp;
    getline(cin, temp);
}

int DFS(int row, int exRowState)
{
    if(row == N) return 0;
    int& ret = cache[row][exRowState];
    if(ret != -1) return ret;
    ret = 0;
    int max_bit = (1 << M) - 1;
    // cout << "Seat:" << bitset<10>(seats[row]) << endl;
    for(int bit = 0; bit < (1 << M); ++bit)
    {
        if(seats[row] & bit) continue;
        // cout << "Pass Seat Check : " <<bitset<10>(bit) << endl;
        if(!CheckAdjacency(bit)) continue;
        // cout << "Pass Adjacency Check" << endl;
        if(!CheckCheating(bit, exRowState)) continue;
        // cout << "Pass Cheating Check" << endl;

        // cout << "cand(" << row << "," <<bitset<10>(exRowState)<<"):"<<bitset<10>(bit) << "=" << bit<<endl;
        // Wait();
        // int cand = DFS(row + 1, bit) + PopCount(bit);
        // if(ret < cand)
        // {
        //     ret = cand;
        //     max_bit = bit;
        // }
        ret = max(ret, DFS(row + 1, bit) + __builtin_popcount(bit));
        
    }
    // cout << row << ", " << bitset<10>(exRowState) << ": " << ret << "=" << bitset<10>(max_bit) << endl;
    return ret;  
}
