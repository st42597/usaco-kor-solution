#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int alpha2num[26], p[20][20], dp[1 << 20];
bool alpha[26];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    for(char c : str) alpha[c - 'a'] = true;
    int cnt = 0;
    for(int i = 0; i < 26; i++){
        if(!alpha[i]) continue;
        alpha2num[i] = cnt++;
    }
    fill(dp, dp + (1 << cnt), INF);
    for(int i = 0; i < str.size() - 1; i++){
        p[alpha2num[str[i] - 'a']][alpha2num[str[i + 1] - 'a']]++;
    }
    queue<int> q;
    q.push(0);
    dp[0] = 1;
    while(!q.empty()){
        int bit = q.front(); q.pop();
        vector<int> onBit, offBit;
        for(int i = 0; i < cnt; i++){
            if(bit & (1 << i)) onBit.push_back(i);
            else offBit.push_back(i);
        }
        for(int off : offBit){
            if(dp[bit | (1 << off)] == INF) q.push(bit | (1 << off));
            int sum = 0;
            for(int on : onBit) sum += p[on][off];
            sum += p[off][off];
            dp[bit | (1 << off)] = min(dp[bit | (1 << off)], dp[bit] + sum);
        }
    }
    cout << dp[(1 << cnt) - 1];

    return 0;
}