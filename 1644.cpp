#include <iostream>
#include <vector>

using namespace std;

long long N;
vector<int> primes;

void FindPrimes();
long long Solution();

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    long long result = N == 1 ? 0 :Solution();
    cout << result;
}

void FindPrimes()
{
    vector<bool> bPrime(N + 1, true);
    for(long long i = 2; i * i <= N; ++i)
    {
        if(bPrime[i])
        {
            for(long long j = i * i; j <= N; j += i) 
                bPrime[j] = false;
        }
    }
    for(int i = 2; i <= N; ++i)
    {
        if(bPrime[i]) primes.push_back(i);
    }
}

long long Solution()
{
    long long count = 0;
    FindPrimes();
    long long sum = 0;
    int low = 0, high = 0;
    while(high <= primes.size())
    {
        if(sum >= N)
        {
            sum -= primes[low];
            ++low;
        }
        else
        {
            sum += primes[high];
            ++high;
        }
        if(sum == N) ++count;
        /*
        cout << "sum:" << sum;
        for(int i = low; i < high; i++)
        {
            cout << ' ' << primes[i];
        }
        cout << endl;
        */
    }
    return count;
}