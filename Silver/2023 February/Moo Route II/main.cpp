#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int INF = 2e9;

struct Raw{
    int c, r, d, s;
};

struct Data{
    int r, d, s;
};

vector<Raw> arr;
queue<Data> q[200003];
int layover[200003], ans[200003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    fill(ans + 2, ans + N + 1, INF);
    for(int i = 0; i < M; i++){
        int c, r, d, s; cin >> c >> r >> d >> s;
        arr.push_back({c, r, d, s});
    }
    for(int i = 1; i <= N; i++) cin >> layover[i];
    sort(arr.begin(), arr.end(), [](const Raw &a, const Raw &b){
        return a.r > b.r;
    });
    for(Raw r : arr) q[r.c].push({r.r, r.d, r.s});
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({-layover[1], 1});
    while(!pq.empty()){
        int t = pq.top().first, curr = pq.top().second; pq.pop();
        if(ans[curr] < t) continue;
        while(!q[curr].empty()){
            if(t + layover[curr] > q[curr].front().r) break;
            pq.push({q[curr].front().s, q[curr].front().d});
            ans[q[curr].front().d] = min(ans[q[curr].front().d], q[curr].front().s);
            q[curr].pop();
        }
    }
    for(int i = 1; i <= N; i++) cout << ((ans[i] == INF) ? -1 : ans[i]) << "\n";

    return 0;
}
