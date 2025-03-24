#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Vector;
struct Line
{
    Vector start, end;
    Line(Vector p1, Vector p2)
    {
        if(p1 > p2) swap(p1, p2);
        start = p1;
        end = p2;
    }

    bool Intersect(Line other)
    {
        int ccw1 = CCW(start, end, other.start) * CCW(start, end, other.end);
        int ccw2 = CCW(other.start, other.end, start) * CCW(other.start, other.end, end);
        if(ccw1 == 0 && ccw2 == 0) return (other.start <= end) && (start <= other.end);
        return ccw1 <= 0 && ccw2 <= 0;
    }

    static int CCW(Vector p1, Vector p2, Vector p3)
    {
        Vector v1 = {p2.first - p1.first, p2.second - p1.second};
        Vector v2 = {p3.first - p2.first, p3.second - p2.second};
        long long cross = v1.first * v2.second - v1.second * v2.first;
        if(cross > 0) return 1;
        else if (cross == 0) return 0;
        else return -1;
    }

    // friend ostream& operator<<(ostream& os, const Line& line);
};

// ostream& operator<<(ostream& os, const Line& line)
// {
//     os << '(' << line.start.first << ", " << line.start.second << ")~(" << line.end.first << ", " << line.end.second << ')';
//     return os;
// }

int N, maxGroup;
vector<Line> lines;
vector<int> parents;

int GetParent(int index)
{
    if(parents[index] != index) return GetParent(parents[index]);
    return index;
}

void Union(int a, int b)
{
    if(a > b) swap(a, b);
    parents[GetParent(a)] = b;
}

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
    maxGroup = 0;
    for(int i = 0; i < N; ++i)
    {
        int p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;
        cin.ignore();
        lines.push_back(Line({p1, p2}, {p3, p4}));
        parents.push_back(i);
    }


    for(int i = 0; i < lines.size(); ++i)
    {
        for(int j = i + 1; j < lines.size(); ++j)
        {
            if(lines[i].Intersect(lines[j]) && (GetParent(i) != GetParent(j)))
            {
                // cout << "Intersect: " << lines[i] << ' ' << lines[j] << endl;
                Union(i, j);
            }
        }
    }
    vector<int> count = vector(N, 0);
    for(int i = 0; i < lines.size(); ++i)
    {
        ++count[GetParent(i)];
    }

    int group = 0;
	int maxLines = 0;
	for (int i = 0; i < N; ++i) {
		if (count[i] != 0) ++group;
		maxLines = max(maxLines, count[i]);
	}
    
    cout << group << '\n' << maxLines;
}
