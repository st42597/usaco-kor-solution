#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;

const int MAX_N=305;
const int INF=1e9;
const int MOD=1'000'000'007;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,b,s,d;
    int arr[MAX_N]={0};
    int dp[MAX_N][MAX_N]={0};
    pair<int,int> boots[MAX_N];
    cin>>n>>b;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<b;i++){
        cin>>s>>d;
        boots[i]={s,d};
    }
    // 0번에는 어느 부츠로든 갈 수 있다
    for(int i=0;i<b;i++){
        dp[0][i]=1;
    }
    for(int cur=0;cur<n;cur++){
        for(int boot=0;boot<b;boot++){
            /* 이전에 단 한 부츠로라도 여기로 도달 가능하면 된다 */
            int p=0;
            for(int i=0;i<=boot;i++){
                if(dp[cur][i]){p=1;}
            }
            if(p==0){continue;}
            for(int i=1;i<=boots[boot].second;i++){
                if(cur+i >= n || arr[cur]>boots[boot].first || arr[cur+i]>boots[boot].first){continue;}
                dp[cur+i][boot]=1;
            }
        }
    }
    int ans=-1;
    for(int i=0;i<b;i++){
        if(dp[n-1][i]){ans=i; break;}
    }
    cout<<ans<<"\n";
    return 0;
}
