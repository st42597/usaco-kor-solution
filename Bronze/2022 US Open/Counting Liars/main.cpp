#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pic;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<pic> arr(N);
    for(auto& [a, b] : arr) cin >> b >> a;
    sort(arr.begin(), arr.end());
    int ans = 1e9;
    for(int i = 0; i <= N; i++){
        int cnt = 0;
        for(int j = 0; j < i; j++) if(arr[j].second == 'L') cnt++;
        for(int j = i; j < N; j++) if(arr[j].second == 'G') cnt++;
        ans = min(ans, cnt);
    }
    cout << ans;

    return 0;
}