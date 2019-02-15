#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

int n, chef[1000];

ll getQ(ll t){
    ll Q = 0;
    for(int i = 0; i < n; i++) Q += t/chef[i];
    return Q;
}

ll getTime(ll &c, ll l, ll r){
    if(l > r) return -1;
    ll mid = (l + r)/2;
    ll Q1 = getQ(mid), Q2 = getQ(mid + 1);
    if(Q1 < c && c <= Q2) return mid + 1;
    if(c <= Q1) return getTime(c, l, mid - 1);
    else return getTime(c, mid + 1, r);
}

int main()
{
    int a;
    cin>>n>>a;
    long long c;
    for(int i = 0; i < n; i++){
        cin>>chef[i];
    }
    sort(chef, chef + n);
    for(int i = 0; i < a; i++){
        cin>>c;
        c -= n;
        if(c <= 0) cout<<0<<endl;
        else cout<<getTime(c, 0, c*chef[0])<<endl;
    }
    return 0;
}
