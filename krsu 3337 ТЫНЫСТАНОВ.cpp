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

char ch[] = { 'A','E','I','O','o','U','u','Y' };
map<char, char> nxt;
vector<string> dict;

void brute(string t) {
    if (t.size() == 5) {
        dict.push_back(t);
        return;
    }
    if (t.empty()) {
        for (int i = 0; i < 8; i++) {
            brute(t + ch[i]);
        }
        return;
    }
    brute(t + t.back());
    brute(t + nxt[t.back()]);
}

int getpos(char c) {
    for (int i = 0; i < 8; i++) {
        if (ch[i] == c) return i;
    }
}

bool cmp(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        int x = getpos(a[i]);
        int y = getpos(b[i]);
        if (x == y) continue;
        return x < y;
    }
    return 0;
}

void solve() {
    nxt['A'] = 'Y';
    nxt['E'] = 'I';
    nxt['I'] = 'E';
    nxt['O'] = 'U';
    nxt['o'] = 'u';
    nxt['U'] = 'A';
    nxt['u'] = 'o';
    nxt['Y'] = 'A';
    brute("");
    sort(all(dict), cmp);
    string s;
    cin >> s;
    for (int i = 0; i < dict.size(); i++) {
        if (dict[i] == s) {
            cout << dict[i + 1] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}