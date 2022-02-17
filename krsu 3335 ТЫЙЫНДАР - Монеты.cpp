/*
by: senb1
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define ll long long
#define str string
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(x) x.begin(), x.end()

using namespace std;

int bp(int a, int n) {
    if (n == 0) return 1;
    if (n % 2) return bp(a, n - 1) * a;
    int b = bp(a, n / 2);
    return b * b;
}

const int catN = 51;
ll cat[catN];

void catnums(int n) {
    cat[0] = cat[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            cat[i] += cat[j] * cat[i - j - 1];
    cout << cat[n];
}

const int N = 1e6;
ll n, dp[N];
void solve() {
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i - 1];
    }
    for (int i = 5; i <= n; i++) {
        dp[i] += dp[i - 5];
    }
    for (int i = 10; i <= n; i++) {
        dp[i] += dp[i - 10];
    }
    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}