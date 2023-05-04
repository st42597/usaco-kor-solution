#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[200003];
ll hb[200003];
int degree[200003];
vector<tuple<int, int, ll>> ans1, ans2;
bool visited[200003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    ll mean = 0;
    for(int i = 1; i <= N; i++){
        cin >> hb[i];
        mean += hb[i];
    }
    mean /= N;
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= N; i++) if(degree[i] == 1) q.push(i);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(int next : adj[curr]){
            if(visited[next]) continue;
            if(--degree[next] == 1) q.push(next);
            if(hb[curr] > mean){
                ans1.push_back({curr, next, hb[curr] - mean});
                hb[next] += hb[curr] - mean;
                hb[curr] = mean;
            }else if(hb[curr] < mean){
                ans2.push_back({next, curr, mean - hb[curr]});
                hb[next] -= mean - hb[curr];
                hb[curr] = mean;
            }
        }
        visited[curr] = true;
    }
    cout << ans1.size() + ans2.size() << "\n";
    for(int i = 0; i < int(ans1.size()); i++) cout << get<0>(ans1[i]) << " " << get<1>(ans1[i]) << " " << get<2>(ans1[i]) << "\n";
    for(int i = int(ans2.size()) - 1; i >= 0; i--) cout << get<0>(ans2[i]) << " " << get<1>(ans2[i]) << " " << get<2>(ans2[i]) << "\n";

    return 0;
}
