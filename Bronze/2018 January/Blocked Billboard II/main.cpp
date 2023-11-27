#include <bits/stdc++.h>
using namespace std;

int arr[2003][2003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    for(int x = x1; x < x2; x++) for(int y = y1; y < y2; y++) arr[x + 1000][y + 1000] = 1;
    for(int x = x3; x < x4; x++) for(int y = y3; y < y4; y++) arr[x + 1000][y + 1000] = 2;
    int minx = 1001, miny = 1001, maxx = -1001, maxy = -1001;
    bool check = false;
    for(int x = -1000; x < 1000; x++){
        for(int y = -1000; y < 1000; y++){
            if(arr[x + 1000][y + 1000] != 1) continue;
            check = true;
            minx = min(minx, x);
            miny = min(miny, y);
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        }
    }
    if(check) cout << (maxx - minx + 1) * (maxy - miny + 1);
    else cout << 0;

    return 0;
}