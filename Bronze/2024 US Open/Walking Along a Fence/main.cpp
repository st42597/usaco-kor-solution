#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int cnt[1003][1003];
vector<pii> arr;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, P; cin >> N >> P;
    for(int i = 0; i < P; i++) {
        int x, y; cin >> x >> y;
        arr.push_back({x, y});
    }
    arr.push_back(arr[0]);
    int x, y, nx, ny;
    x = nx = arr[0].first;
    y = ny = arr[0].second;
    for(int i = 1; i <= P; i++) {
        while(nx != arr[i].first || ny != arr[i].second) {
            if(nx < arr[i].first) nx++;
            else if(nx > arr[i].first) nx--;
            if(ny < arr[i].second) ny++;
            else if(ny > arr[i].second) ny--;
            cnt[nx][ny] = cnt[x][y] + 1;
            x = nx;
            y = ny;
        }
    }
    for(int i = 0; i < N; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << min(abs(cnt[x1][y1] - cnt[x2][y2]), cnt[x][y] - abs(cnt[x1][y1] - cnt[x2][y2])) << "\n";
    }
    


    return 0;
}