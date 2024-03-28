#include <bits/stdc++.h>
using namespace std;

int C[200003], T[200003], cnt[1000003], ans[1000003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> T[i];
    int total = 0;
    for(int i = 0; i < N; i++) if(C[i] - T[i] >= 0) {cnt[C[i] - T[i]]++; total++;}
    for(int i = 0; i <= 1000000; i++){
        total -= cnt[i];
        ans[i] = total;
    }
    for(int i = 0; i < Q; i++){
        int V, S; cin >> V >> S;
        if(ans[S] >= V) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}