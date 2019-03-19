#include <iostream>
#include <queue>

using namespace std;

int n, m, q, p[5005], ans[5005], h[5005] = {0};

class edge{
public:
    int a, b, c;
    edge(int a, int b, int c): a(a), b(b), c(c){}
    bool operator<(const edge other)const{
        return c > other.c;
    }
};
priority_queue<edge> pq;

int findSet(int s){
    if(p[s] == s) return s;
    return findSet(p[s]);
}

void unionSet(int a, int b){
    if(h[a] < h[b]) p[b] = a;
    else{
        p[a] = b;
        if(h[a] == h[b]) h[a]++;
    }
}

void Kruskal(){
    int nCom = n;
    for(int i = 0; i < n; i++) p[i] = i;
    while(!pq.empty()){
        edge e = pq.top(); pq.pop();
        if(findSet(e.a) != findSet(e.b)){
            ans[--n] = e.c;
            unionSet(findSet(e.a), findSet(e.b));
        }
    }
}

int main()
{
    cin>>n>>m>>q;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({a, b ,c});
    }
    Kruskal();
    for(int i = 0; i < q; i++){
        int t;
        cin>>t;
        cout<<ans[t]<<endl;
    }
    return 0;
}
