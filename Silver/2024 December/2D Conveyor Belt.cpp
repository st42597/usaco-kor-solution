#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, char> tiic;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int N, Q, cnt;
char dir[1003][1003];
bool check[1003][1003];
vector<pii> query;
vector<int> ans;
bool isUnusable(int x, int y) {
    if(x < 1 || x > N || y < 1 || y > N) return false;
    if(dir[x][y] == 0) {
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 1 || nx > N || ny < 1 || ny > N) return true;
            if(check[nx][ny]) return true;
        }
    } else {
        int nx = x, ny = y;
        if(dir[x][y] == 'L') ny -= 1;
        else if(dir[x][y] == 'R') ny += 1;
        else if(dir[x][y] == 'U') nx -= 1;
        else if(dir[x][y] == 'D') nx += 1;
        if(nx < 1 || nx > N || ny < 1 || ny > N) return true;
        if(check[nx][ny]) return true;
    }
    return false;
}
void dfs(int x, int y) {
    if(check[x][y] || !isUnusable(x, y)) return;
    check[x][y] = true;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < Q; i++) {
        int x, y; char c; cin >> x >> y >> c;
        dir[x][y] = c;
        query.push_back({x, y});
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dfs(i, j);
        }
    }
    reverse(query.begin(), query.end());
    ans.push_back(N * N - cnt);
    for(pii q : query) {
        int x = q.first, y = q.second;
        dir[x][y] = 0;
        dfs(x, y);
        ans.push_back(N * N - cnt);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";
    
    return 0;
}