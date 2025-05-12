#include <iostream>
#include <vector>

using namespace std;

long long N = 1000;
// vector<long long> digits;
long long digits[10] = {0};

void Solution();
void CountDigitsBetween(int A, int B, int adder);

void CountDigit(int n, int adder) {
	while (n > 0) {
		digits[n % 10] += adder;
		n /= 10;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	cin >> N;

    Solution();

    return 0;
}

void Solution()
{
    //digits = vector<long long>(10, 0);

    CountDigitsBetween(1, N, 1);
    for (int i = 0; i < 10; ++i) 
    {
        cout << digits[i] << ' ';
    }
}

void CountDigitsBetween(int A, int B, int adder) {

	//A의 일의 자리수를 0으로 맞춘다.
	while (A % 10 != 0 && A <= B) {
		CountDigit(A, adder);
		++A;
	}

	if (A > B) return;
	
	//B의 일의 자리수를 9로 맞춘다.
	while (B % 10 != 9 && A <= B) {
		CountDigit(B, adder);
		--B;
	}

    int new_A = A / 10;
    int new_B = B / 10;
	long long multipler = (new_B - new_A + 1);
	
	for (int i = 0; i < 10; ++i)
		digits[i] += adder * multipler;

	CountDigitsBetween(new_A, new_B, adder * 10);
}