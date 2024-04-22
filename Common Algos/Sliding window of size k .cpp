#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySumOfSizeK(vector<long long> v, long long k) {
    long long n = v.size();
    if (k == 1 || n == 1) return *max_element(v.begin(), v.end());
    long long sum = 0;
    for (int i = 0;i < k;i++)sum += v[i];
    long long ans = sum;
    for (int i = k;i < n;i++) {
        sum += v[i];
        sum -= v[i - k];
        ans = max(ans, sum);
    }
    return ans;
}
//shorter code for above algo-
long long algo(vector<long long> v, long long k) {
    long long n = v.size();
    long long sum = 0,ans=-1e9;
    for (int i = 0;i < n;i++){
        sum += v[i];
        if(i>=k)sum -= v[i - k];
        if(i>=k-1)ans = max(ans, sum);
    }
    return ans;
}
/*
    *Step1 calculate sum of first k elements as our first window
    *Step2 initialize ans as sum
    *Step3 looping from i=k to i<n while
            *1 adding arr[i] to sum
            *2 subtracting arr[i-k] from sum
            *3 updating ans [ ans= max(sum,ans); ]
    *Step4 returning ans
*/
int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0;i < n;i++)
        cin >> arr[i];

    cout << maxSubarraySumOfSizeK(arr, k);
    return 0;
}
