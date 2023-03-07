#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, K; cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];
    ll ans = K + 1;
    for(int i = 1; i < N; i++) ans += min(K + 1, arr[i] - arr[i - 1]);
    cout << ans;

    return 0;
}
