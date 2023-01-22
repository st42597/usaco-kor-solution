#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin >> N;
    vector<ll> arr(N);
    for(ll &in : arr) cin >> in;
    sort(arr.begin(), arr.end());
    ll max_val = 0, ans;
    for(int i = 0; i < N; i++){
        if(max_val < arr[i] * (N - i)){
            max_val = arr[i] * (N - i);
            ans = arr[i];
        }
    }
    cout << max_val << " " << ans << "\n";

    return 0;
}