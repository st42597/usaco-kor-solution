#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1e18;

ll arr[100003], psum[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
            psum[i] = psum[i - 1] + arr[i];
        }
        if(N == 1){
            cout << 0 << "\n";
            continue;
        }
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        ll ans = INF;
        for(int i = 1; i <= N; i++){
            if(psum[i] > 0) pq.push({psum[i] * 2, psum[i]});
            while(!pq.empty() && pq.top().first < psum[i]) pq.pop();
            while(!pq.empty() && pq.top().first == psum[i]){
                if(i == N) ans = min(ans, pq.top().second);
                pq.push({pq.top().first + pq.top().second, pq.top().second});
                pq.pop();
            }
        }
        if(ans == INF) ans = psum[N];
        ll cnt = 0, num = ans;
        for(int i = 1; i <= N; i++){
            if(psum[i] == num){
                cnt++;
                num += ans;
            }
        }
        cout << N - cnt << "\n";
    }

    return 0;
}
