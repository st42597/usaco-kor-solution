#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[100003];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K, L; cin >> N >> K >> L;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int s = 0, e = N + 1;
    while(s + 1 < e){
        int m = (s + e) / 2;
        int i = N - m, cnt = 0;
        ll sv = (ll)K * L;
        if(m - arr[i] > K) e = m;
        else{
            while(i < N && arr[i] < m && sv >= 0){
                sv -= m - arr[i];
                i++;
            }
            if(sv >= 0) s = m;
            else e = m;
        }
    }
    cout << s;

    return 0;
}
