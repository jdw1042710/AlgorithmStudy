
#include <iostream>
#include <vector>

using namespace std;

int T, N, W;
vector<vector<int>> sections;
vector<vector<int>> cache;

void Input();
void Solution();
int GetMinPlatoon();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Input()
{
    cin >> N >> W;
    cin.ignore();
    sections = vector<vector<int>>(2, vector<int>());
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            int enemy;
            cin >> enemy;
            sections[i].push_back(enemy);
        }
        cin.ignore();
    }
}

/// 총 3개의 dp 배열(= 3 x N 크기의 cache)로 관리한다.
/// 첫번째 배열(= cache[0])은 dp[x](= cache[0][x])라고 할 때, x번째 column까지 0번째와 1번째 row 모두 탐색을 완료한 경우의 최적해를 저장한다.
/// e.g. 0 1 ... x-1 x x+1 x+2
///  0   O O ...  O  O  X   X
///  1   O O ...  O  O  X   X
/// 두번째 배열(= cache[1])은 dp[x](= cache[1][x])라고 할 때, x-1번째 column까지는 0번째와 1번째 row 모두 탐색을 완료했고, x번째 column의 경우 0번째 row까지만 탐색한 경우의 최적해를 저장한다.
/// e.g. 0 1 ... x-1 x x+1 x+2
///  0   O O ...  O  O  X   X
///  1   O O ...  O  X  X   X
/// 세번째 배열(= cache[2])은 dp[x](= cache[2][x])라고 할 때, x-1번째 column까지는 0번째와 1번째 row 모두 탐색을 완료했고, x번째 column의 경우 1번째 row까지만 탐색한 경우의 최적해를 저장한다.
/// e.g. 0 1 ... x-1 x x+1 x+2
///  0   O O ...  O  X  X   X
///  1   O O ...  O  O  X   X
void Solution()
{
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; ++i)
    {
        Input();
        int answer;
        cache = vector<vector<int>>(3, vector<int>(N, 0));

        // (N - 1) ~ 0번째 column 사이에 아무런 연결이 없는 경우
        answer = GetMinPlatoon();
        // cout << "(N - 1) ~ 0번째 column 사이에 아무런 연결이 없는 경우" << endl;
        // cout << answer << endl;
        if(N > 1)
        {
            int temp1, temp2;
            // (N - 1) ~ 0번째 column 사이에 0번째 row에만 연결이 있는 경우
            if(sections[0][0] + sections[0][N - 1] <= W)
            {
                temp1 = sections[0][0];
                temp2 = sections[0][N - 1];
                sections[0][0] = sections[0][N - 1] = W; // 연결한 section이 다른 section과 연결되지 않도록 임시로 최대 값을 넣어줌
                answer = min(answer, GetMinPlatoon() - 1); // 연결한 section을 각각 세었으므로 하나를 빼줌
                sections[0][0] = temp1;
                sections[0][N - 1] = temp2;
                // cout << "(N - 1) ~ 0번째 column 사이에 0번째 row에만 연결이 있는 경우" << endl;
                // cout << answer << endl;
            }
            // (N - 1) ~ 0번째 column 사이에 1번째 row에만 연결이 있는 경우
            if(sections[1][0] + sections[1][N - 1] <= W)
            {
                temp1 = sections[1][0];
                temp2 = sections[1][N - 1];
                sections[1][0] = sections[1][N - 1] = W; // 연결한 section이 다른 section과 연결되지 않도록 임시로 최대 값을 넣어줌
                answer = min(answer, GetMinPlatoon() - 1); // 연결한 section을 각각 세었으므로 하나를 빼줌
                sections[1][0] = temp1;
                sections[1][N - 1] = temp2;
                // cout << "(N - 1) ~ 0번째 column 사이에 1번째 row에만 연결이 있는 경우" << endl;
                // cout << answer << endl;
            }
            // (N - 1) ~ 0번째 column 사이에 0번째, 1번째 row모두 연결이 있는 경우
            if(sections[0][0] + sections[0][N - 1] <= W
                && sections[1][0] + sections[1][N - 1] <= W)
            {
                sections[0][0] = sections[0][N - 1] = sections[1][0] = sections[1][N - 1] = W; // 연결한 section이 다른 section과 연결되지 않도록 임시로 최대 값을 넣어줌
                answer = min(answer, GetMinPlatoon() - 2); // 연결한 section을 각각 세었으므로 둘을 빼줌
                // cout << "(N - 1) ~ 0번째 column 사이에 0번째, 1번째 row모두 연결이 있는 경우" << endl;
                // cout << answer << endl;
            }
        }
        cout << answer << '\n';
    }
}

int GetMinPlatoon()
{
    // 최초값을 초기화
    // 첫번째 column을 묶을 수 있는지 체크
    // e.g.
    // 20 X X X ....
    // 50 X X X ....
    cache[0][0] = (sections[0][0] + sections[1][0] > W) ? 2 : 1;
    cache[1][0] = cache[2][0] = 1;

    for (int i = 1; i < N; ++i) {
		/// i번째 column의 section들의 침투 방법에 따라 경우의 수를 계산한다.

        /// 0번째 row만 채우는 경우
        cache[1][i] = cache[0][i - 1] + 1;
        //가로로 한번에 채우는
		if (sections[0][i] + sections[0][i - 1] <= W) cache[1][i] = min(cache[1][i], cache[2][i - 1] + 1);

        /// 1번째 row만 채우는 경우
        cache[2][i] = cache[0][i - 1] + 1;
        //가로로 한번에 채우는 경우
		if (sections[1][i] + sections[1][i - 1] <= W) cache[2][i] = min(cache[2][i], cache[1][i - 1] + 1);

		/// 0번째와 1번째 row 모두 채우는 경우
		cache[0][i] = cache[0][i - 1] + 2;
        cache[0][i] = min(cache[0][i], cache[1][i] + 1);
		cache[0][i] = min(cache[0][i], cache[2][i] + 1);

        //세로로 한번에 채우는 경우
		if (sections[0][i] + sections[1][i] <= W) cache[0][i] = min(cache[0][i], cache[0][i - 1] + 1);
		
        //0번째와 1번째 row 각각 가로로 채우는 경우
		if (sections[0][i] + sections[0][i - 1] <= W 
            && sections[1][i] + sections[1][i - 1] <= W)
        {
            cache[0][i] = min(cache[0][i], ((i < 2) ? 0 : cache[0][i - 2]) + 2);
        }
	}
    return cache[0][N - 1];
}
