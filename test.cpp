#include <queue>
#include <iostream>
using namespace std;

// 비교연산 선언
// int형인 a와 b가 있을때
// 반환에 a > b 를 입력하면 작은수부터 출력한다.
// (반대로 a < b 를 입력하면 큰수부터 출력한다.) 
struct cmp {
  bool operator()(int a, int b) {
    return a <= b;
  }
};

int main() {
  priority_queue <int, vector<int>, cmp> pq;
  
  pq.push(5);
  pq.push(3);
  pq.push(3);
  pq.push(6);
  pq.push(6);
  pq.push(7);

  while(!pq.empty()) {
    int temp = pq.top();
    cout << temp;
    pq.pop();
  }
  // 출력결과
  // 3567
  return 0;
}