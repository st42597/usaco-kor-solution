#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

struct uf{
    vector<int> p, s;
    uf() : p(55,-1), s(55,1) {}
    int f(int x){ return p[x]==-1 ? x : p[x]=f(p[x]); }
    bool u(int x, int y){
        x=f(x), y=f(y);
        if(x==y) return true;
        p[x]=y;
        s[y]+=s[x];
        return false;
    }
};

int tc;
string s1, s2;
bool A[55][55];

void fastio(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}

inline int f(char a){
    if(a>='a' && a<='z') return a-'a';
    return a-'A'+26;
}

void solve(){
    cin >> s1 >> s2;
    memset(A,false,sizeof(A));
    vector<int> cnt(55), nxt(55,-1);
    int tmp=0;
    for(int i=0 ; i<s1.length() ; i++){
        int v1=f(s1[i]);
        int v2=f(s2[i]);
        A[v1][v2]=true;
        nxt[v1]=v2;
        cnt[v2]++;
        if(cnt[v2]==1) tmp++;
    }
    int ans=0;
    for(int i=0 ; i<52 ; i++){
        int c=0;
        for(int j=0 ; j<52 ; j++){
            if(A[i][j]) c++;
        }
        if(c>1){
            cout << "-1\n"; return;
        }
        if(c==1) ans++;
    }
    if(tmp==52){
        for(int i=0 ; i<s2.length() ; i++){
            if(s1[i]!=s2[i]){
                cout << "-1\n"; return;
            }
        }
    }
    uf T;
    vector<bool> chk(55);
    for(int i=0 ; i<52 ; i++){
        if(nxt[i]==-1) continue;
        if(i==nxt[i]){
            ans--;
            continue;
        }
        if(T.u(i,nxt[i])){
            ans++;
            chk[i]=true;
        }
    }
    for(int i=0 ; i<52 ; i++){
        if(!chk[i]) continue;
        int cur=i, cnt=0;
        do{
            cnt++; cur=nxt[cur];
        }while(cur!=i);
        if(cnt!=T.s[T.f(i)]) ans--;
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    for(cin >> tc ; tc ; tc--){
        solve();
    }
    return 0;
}