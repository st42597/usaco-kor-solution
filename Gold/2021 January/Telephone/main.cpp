#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> pii;
int dist[51][50001], breed[50001];
bool check[51][51];
struct Data{
    int d, b, idx;
};
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    for(int i = 1; i <= k; i++) fill(dist[i] + 1, dist[i] + n + 1, INF);
    for(int i = 1; i <= n; i++) cin >> breed[i];
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            char c; cin >> c;
            if(c == '1') check[i][j] = true;
        }
    }
    deque<Data> dq;
    dist[breed[1]][1] = 0;
    dq.push_back({0, breed[1], 1});
    while(!dq.empty()){
        Data curr = dq.front(); dq.pop_front();
        if(check[curr.b][breed[curr.idx]]){
            if(dist[breed[curr.idx]][curr.idx] == INF){
                dist[breed[curr.idx]][curr.idx] = curr.d;
                dq.push_front({curr.d, breed[curr.idx], curr.idx});
            }
        }
        for(int i = -1; i <= 1; i += 2){
            if(curr.idx + i < 1) continue;
            if(dist[curr.b][curr.idx + i] == INF){
                dist[curr.b][curr.idx + i] = curr.d + 1;
                dq.push_back({curr.d + 1, curr.b, curr.idx + i});
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= k; i++){
        if(!check[i][breed[n]]) continue;
        ans = min(ans, dist[i][n]);
    }
    cout << (ans == INF ? -1 : ans);

    return 0;
}