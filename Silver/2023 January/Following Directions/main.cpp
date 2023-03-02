#include <bits/stdc++.h>
using namespace std;

int N;
char arr[1503][1503];
int cnt[1503][1503];
int rc[1503], bc[1503];

int calc(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        ret += cnt[i][N] * rc[i];
        ret += cnt[N][i] * bc[i];
    }

    return ret;
}

void update(int x, int y, int c){
    while(1){
        cnt[x][y] += c;
        if(!(arr[x][y] == 'R' || arr[x][y] == 'D')) break;
        if(arr[x][y] == 'R') y += 1;
        else x += 1;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
        cin >> rc[i];
    }
    for(int i = 0; i < N; i++) cin >> bc[i];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cnt[i][j]++;
            if(arr[i][j] == 'R') cnt[i][j + 1] += cnt[i][j];
            else cnt[i + 1][j] += cnt[i][j];
        }
    }

    cout << calc() << "\n";
    int Q; cin >> Q;
    while(Q--){
        int x, y; cin >> x >> y;
        if(arr[x - 1][y - 1] == 'R'){
            update(x - 1, y, -cnt[x - 1][y - 1]);
            update(x, y - 1, cnt[x - 1][y - 1]);
        }else{
            update(x, y - 1, -cnt[x - 1][y - 1]);
            update(x - 1, y, cnt[x - 1][y - 1]);
        }
        arr[x - 1][y - 1] = ((arr[x - 1][y - 1] == 'R') ? 'D' : 'R');
        cout << calc() << "\n";
    }

    return 0;
}