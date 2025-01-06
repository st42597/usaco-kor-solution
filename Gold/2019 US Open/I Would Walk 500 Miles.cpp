#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, K; cin >> N >> K;
    cout << (2019201913 * (K - 1) + 2019201949 * N) % 2019201997 << "\n";

    return 0;
}