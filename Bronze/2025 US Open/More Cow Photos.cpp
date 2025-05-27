#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<int> cnt(N + 1);
        for(int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            cnt[tmp]++;
        }
        int ans = 0;
        bool flag = false;
        for(int i = N; i >= 1; i--) {
            if(cnt[i] == 0) continue;
            if(!flag) {
                ans++;
                flag = true;
            } else if(cnt[i] >= 2) {
                ans += 2;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}