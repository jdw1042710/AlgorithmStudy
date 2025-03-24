#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vector
{
    long long x, y;
    Vector(int val_x, int val_y) : x(val_x), y(val_y) {}
    Vector(pair<int, int> val) : x(val.first), y(val.second) {}

    Vector operator-(Vector other)
    {
        return Vector(x - other.x, y - other.y);
    }

    static long long CrossAbs(Vector a, Vector b, Vector c)
    {
        return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
    }
};

int N, maxGroup;
vector<Vector> poly;

void Solution();

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solution();
}

void Solution()
{
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        cin.ignore();
        poly.push_back({x, y});
    }
    double result = 0;
    for(int i = 1; i + 1 < N; ++i)
    {
        result += Vector::CrossAbs(poly[0], poly[i], poly[i + 1]) / 2.L;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(result);
}
