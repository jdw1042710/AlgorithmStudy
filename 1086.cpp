#include <iostream>
#include <vector>

using namespace std;


int N, K;
vector<string> nums;
vector<vector<long long>> cache;
vector<long long> cache_digits, cache_nums;

void Input();
void Solution();
long long GetPermutationsNum(int mask, long long remain);

int GetStringMod(string s, int dividor)
{
    int ret = 0;
    for(size_t i = 0; i < s.length(); ++i)
    {
        ret *= 10;
        ret += s[i] - '0';
        ret %= dividor;
    }
    return ret;
}

long long GetFactorial(int n) 
{
	if(n < 1) return 1;
    return GetFactorial(n - 1) * n;
}

long long GetGCD(long long a, long long b)
{
    return b ? GetGCD(b, a % b) : a;
}

// int GetDigits(int n)
// {
//     int digits = 0;
//     for(digits = 1; n > 9; ++digits) n /= 10;
//     return digits;
// }

// long long Pow(int a, int b)
// {
//     long long ret = 1;
//     while(b > 0)
//     {
//         ret *= a;
//         --b;
//     }
//     return ret;
// }

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
    nums = vector<string>(N);
    cache_nums = vector<long long>(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> nums[i];
        cin.ignore();
    }
    cin >> K;
    cin.ignore();
    cache = vector<vector<long long>>(1 << N, vector<long long>(K, -1));
    cache_digits = vector<long long>(51);
    cache_digits[0] = 1 % K;
    for(int i = 1; i < 51; ++i)
    {
        cache_digits[i] = (cache_digits[i - 1] * 10) % K;
    }
    for(int i = 0; i < N; ++i)
    {
        cache_nums[i] = GetStringMod(nums[i], K);
    }
}

void Solution()
{
    Input();
    long long num, denom, gcd;
    num = 0;
    for(int i = 0; i < N; ++i)
    {
        num += GetPermutationsNum((1 << i), cache_nums[i]);
    }
    denom = num ? GetFactorial(N) : 1ll;
    gcd = GetGCD(denom, num);
    num /= gcd;
    denom /= gcd;
    cout << num << '/' << denom;
}

long long GetPermutationsNum(int mask, long long remain)
{
    if(mask == (1 << N) - 1) return remain ? 0 : 1;
    long long& ret = cache[mask][remain];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < N; ++i)
    {
        int ith_mask = (1 << i);
        if(ith_mask & mask) continue;
        long long new_remain = (
                                ((remain * cache_digits[nums[i].length()]) % K) 
                                + cache_nums[i]
                                ) % K;
        ret += GetPermutationsNum(mask | ith_mask, new_remain);
    }
    return ret;
}