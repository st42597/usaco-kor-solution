#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int L, N, rf, rb; cin >> L >> N >> rf >> rb;
    vector<pii> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), [&](pii a, pii b) {
        return a.second > b.second;
    });
    int pos = 0;
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i].first < pos) continue;
        ans += (ll)(arr[i].first - pos) * (ll)(rf - rb) * (ll)arr[i].second;
        pos = arr[i].first;
    }
    cout << ans;

    return 0;
}