#include <bits/stdc++.h>
using namespace std;
long long dp[500003];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        long long sum = 0;
        fill(dp, dp + N + 1, 0);
        for(int i = 0; i < N; i++) {
            cin >> dp[i + 1];
            sum += dp[i + 1];
        }
        for(int i = 0; i < N; i++) {
            dp[i + 1] += dp[i];
        }
        long long ans1 = 0, ans2 = 0;
        for(int i = 0; i <= N / 2 - 1; i++) {
            ans2 = max(ans2, dp[i] + dp[N] - dp[N - (N / 2 - 1) + i]);
        }
        ans1 = sum - ans2;
        cout << ans1 << " " << ans2 << "\n";
    }
    
    return 0;
}