#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Data {
    ll x, y, t;
};
vector<Data> arr1, arr2;

inline bool cmp(const Data &a, const Data &b){
    return a.t < b.t;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int G, N; cin >> G >> N;
    for(int i = 0; i < G; i++){
        int x, y, t; cin >> x >> y >> t;
        arr1.push_back({x, y, t});
    }
    for(int i = 0; i < N; i++){
        int x, y, t; cin >> x >> y >> t;
        arr2.push_back({x, y, t});
    }
    sort(arr1.begin(), arr1.end(), cmp);
    sort(arr2.begin(), arr2.end(), cmp);
    int p = -1, cnt = N;
    for(int i = 0; i < N; i++){
        if(p == -1 && arr1[0].t <= arr2[i].t) p++;
        while(p >= 0 && p + 1 < G && arr1[p + 1].t < arr2[i].t) p++;
        bool flag = true;
        if(p >= 0 && abs(arr1[p].x - arr2[i].x) * abs(arr1[p].x - arr2[i].x) + abs(arr1[p].y - arr2[i].y) * abs(arr1[p].y - arr2[i].y) > abs(arr1[p].t - arr2[i].t) * abs(arr1[p].t - arr2[i].t)) flag = false;
        if(p + 1 < G && abs(arr1[p + 1].x - arr2[i].x) * abs(arr1[p + 1].x - arr2[i].x) + abs(arr1[p + 1].y - arr2[i].y) * abs(arr1[p + 1].y - arr2[i].y) > abs(arr1[p + 1].t - arr2[i].t) * abs(arr1[p + 1].t - arr2[i].t)) flag = false;
        if(flag) cnt--;
    }
    cout << cnt;

    return 0;
}
