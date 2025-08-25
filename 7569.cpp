#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Vector3
{
    int x, y, z;
    Vector3(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    const Vector3 operator+(const Vector3& rhs)
    {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }
} Vector3;

int N, M, H;
vector<vector<vector<int>>> tomatoes;
int num_tomatoes = 0;
vector<Vector3> start_points;



void Input();
void Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    Solution();
}

void Input()
{
    cin >> M >> N >> H;

    tomatoes = vector<vector<vector<int>>>(H + 2,
                vector<vector<int>>(N + 2,
                vector<int>(M  + 2, -1)));
    num_tomatoes = 0;
    start_points = vector<Vector3>();
    for(int i = 1; i <= H; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            for(int k = 1; k <= M; ++k)
            {
                int val;
                cin >> val;
                tomatoes[i][j][k] = val;
                if(val != -1)
                    ++num_tomatoes;
                if(val == 1)
                    start_points.push_back({k, j, i});
            }
            cin.ignore();
        }
    }
}

void Solution()
{
    Input();
    Vector3 dir[6] = {{1, 0, 0},
                      {-1, 0, 0},
                      {0, 1, 0},
                      {0, -1, 0},
                      {0, 0, 1},
                      {0, 0, -1}};
    vector<vector<vector<bool>>> visited(H + 2, 
        vector<vector<bool>>(N + 2, 
            vector<bool>(M + 2, false)));
    queue<Vector3> q, next_q;
    for(auto point : start_points)
    {
        next_q.push(point);
        visited[point.z][point.y][point.x] = true;
    }
    int answer = -1, count_tomatoes = 0;
    while(!next_q.empty())
    {
        q = next_q;
        next_q = queue<Vector3>();
        ++answer;
        while(!q.empty())
        {
            Vector3 pos = q.front();
            q.pop();
            tomatoes[pos.z][pos.y][pos.x] = 1;
            ++count_tomatoes;
            for(int i = 0; i < 6; ++i)
            {
                Vector3 next_pos = pos + dir[i];
                if(visited[next_pos.z][next_pos.y][next_pos.x]) continue;
                if(tomatoes[next_pos.z][next_pos.y][next_pos.x] != 0) continue;
                visited[next_pos.z][next_pos.y][next_pos.x] = true;
                next_q.push(next_pos);
            }
        }
    }
    cout << (num_tomatoes == count_tomatoes ? answer : -1) << endl;
}
