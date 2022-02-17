/*
by: senb1
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long
#define elif else if
#define str string
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

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

void solve() {
    int q;
    cin >> q;
    int ans = 0;
    while (q > 40) {
        ans += 5;
        q -= 200;
        if (q > 0) ans += 3;
    }
    while (q > 0) {
        ans++;
        q -= 20;
        if (q > 0) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}

/*
� 1. ������. ������ � ���� � ������ �������� ���� Q �� �����
(����������� ����� Q < 500), ���� ���� � ������� (���� � �� ����� 200 �� �
���� �������, �������� � ������ - +5, �������� ��� ����� - +3) �
������ (���� � �� ����� 20 �� � ���� �������, �������� +1). �����
����������� ����� (� �����) ��� �������� ���� ����� �� �����.
���� � �������, ������ ��� ���� ��������� ������. ����� �� ����� ��
���������.
��������: Q=21 -> 3.
*/