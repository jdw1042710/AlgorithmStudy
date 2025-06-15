#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Point
{
    long long x, y;
    Point(){}
    Point(long long _x, long long _y) : x(_x), y(_y) {}

    static long long CCW(Point a, Point b, Point c)
    {
        return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
    }
};


long long N;
vector<Point> points;
Point standard;

void Input();
void Solution();
bool Compare(Point lhs, Point rhs)
{
    long long ccw = Point::CCW(points.front(), lhs, rhs);
    if(ccw) return ccw > 0;
    else if (lhs.y != rhs.y) return lhs.y < rhs.y;
    else return lhs.x < rhs.x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    Solution();

    return 0;
}

void Input()
{

    cin >> N;
    cin.ignore();

    points = vector<Point>();
    for(int i = 0; i < N; ++i)
    {
        Point p;
        cin >> p.x >> p.y;
        cin.ignore();
        points.push_back(p);
        if(i > 0 
        && (points[i].y < points[0].y 
            || (points[i].y == points[0].y && points[i].x < points[0].x)))
        {
            Point temp = points[0];
            points[0] = points[i];
            points[i] = temp;
        }
    }
    sort(points.begin() + 1, points.end(), Compare);
}

void Solution()
{
    Input();
    stack<Point> st;
    st.push(points[0]);
    st.push(points[1]);
    
    for(int i = 2; i < N; ++i)
    {
        const Point& p = points[i];
        while(st.size() > 1)
        {
            Point p2 = st.top(); 
            st.pop();
            Point p1 = st.top();
            if(Point::CCW(p1, p2, p) > 0)
            {
                st.push(p2);
                break;
            }
        }
        st.push(p);
    }

    cout << st.size();
}