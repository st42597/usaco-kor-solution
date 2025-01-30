#include <bits/stdc++.h>
using namespace std;
int cntx[1003][1003], cnty[1003][1003], cntz[1003][1003];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    int ans = 0;
    while(Q--) {
        int x, y, z; cin >> x >> y >> z;
        cntx[y][z] += 1;
        cnty[z][x] += 1;
        cntz[x][y] += 1;
        if(cntx[y][z] == N) ans++;
        if(cnty[z][x] == N) ans++;
        if(cntz[x][y] == N) ans++;
        cout << ans << "\n";
    }

    return 0;
}