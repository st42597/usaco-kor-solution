#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> ti4;

int M;
int st[103];
vector<ti4> cond;
vector<ti4> tmp;
int ans = 1e9;

void bt(int cnt){
    if(cnt == M){
        int temp[103] = {0};
        int cost = 0;
        for(ti4 t : tmp){
            for(int i = get<0>(t); i <= get<1>(t); i++){
                temp[i] += get<2>(t);
            }
            cost += get<3>(t);
        }
        for(int i = 1; i <= 100; i++){
            if(st[i] - temp[i] > 0) break;
            if(i == 100) ans = min(ans, cost);
        }

        return;
    }
    bt(cnt + 1);
    tmp.push_back(cond[cnt]);
    bt(cnt + 1);
    tmp.pop_back();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N >> M;
    for(int i = 0; i < N; i++){
        int s, t, c; cin >> s >> t >> c;
        for(int j = s; j <= t; j++){
            st[j] = max(st[j], c);
        }
    }
    for(int i = 0; i < M; i++){
        int a, b, p, m; cin >> a >> b >> p >> m;
        cond.push_back({a, b, p, m});
    }
    bt(0);
    cout << ans;

    return 0;
}