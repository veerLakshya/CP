#include<bits/stdc++.h>
using namespace std;

long long powerRecursive(long long a, long long b) {
    if (b == 0) return 1;
    long long res = binpow1(a, b / 2);
    long long result = res*res;
    if (b % 2)
        return result *= a;
    else
        return result;
}

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)   //same as (b%2 ==1);
            res *= a;
        a *= a;
        b >>= 1;    //same as b/=2;
    }
    return res;
}

int main()
{
    long long a, n;
    cin >> a >> n;
    cout << power(a, n);
}
