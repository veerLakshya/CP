#include <bits/stdc++.h>
using namespace std;

long long sieve(long long n)
{
    vector<long long> isprime(n + 1);
    for (int i = 0;i < n + 1;i++) {
        isprime[i] = i;
    }
    isprime[0] = isprime[1] = 0;

    for (int i = 2;i <= n;i++) {
        if (isprime[i] && (long long)i * i <= n) {
            for (int j = i * i;j <= n;j += i)
                isprime[j] = 0;
        }
    }
    long long count = 0;
    for (int i = 2;i < n;i++) {
        if (isprime[i] > 0)count++;
    }
    return count;
}

int main() {
    long long n;
    cin>>n;
    cout << sieve(n);
  return 0;
}
