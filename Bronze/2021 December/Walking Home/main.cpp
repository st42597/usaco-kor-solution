#include <bits/stdc++.h>
using namespace std;

char arr[53][53];
int dp[53][53][2][4];
bool visited[53][53];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) cin >> arr[i][j];
        memset(dp, 0, sizeof(dp));
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;
        if(arr[1][2] == '.'){
            q.push({1, 2});
            dp[1][2][0][0] = 1;
        }
        if(arr[2][1] == '.'){
            q.push({2, 1});
            dp[2][1][1][0] = 1;
        }
        while(!q.empty()){
            int x = q.front().first, y = q.front().second; q.pop();
            if(x + 1 <= N && arr[x + 1][y] == '.'){
                for(int k = 0; k <= K; k++){
                    dp[x + 1][y][1][k] += dp[x][y][1][k];
                    if(k + 1 <= K) dp[x + 1][y][1][k + 1] += dp[x][y][0][k];
                }
                if(!visited[x + 1][y]){
                    visited[x + 1][y] = true;
                    q.push({x + 1, y});
                }
            }
            if(y + 1 <= N && arr[x][y + 1] == '.'){
                for(int k = 0; k <= K; k++){
                    dp[x][y + 1][0][k] += dp[x][y][0][k];
                    if(k + 1 <= K) dp[x][y + 1][0][k + 1] += dp[x][y][1][k];
                }
                if(!visited[x][y + 1]){
                    visited[x][y + 1] = true;
                    q.push({x, y + 1});
                }
            }
        }
        int ans = 0;
        for(int k = 0; k <= K; k++) ans += dp[N][N][0][k] + dp[N][N][1][k];
        cout << ans << "\n";
    }

    return 0;
}
