#include <iostream>
#include <queue>

using namespace std;


int main()
{
    int n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    cin>>n;
    int s[n], f[n], MAX = 0, lastClass = 0, nClass = 0;
    for(int i = 0; i < n; i++) cin>>s[i];
    for(int i = 0; i < n; i++) cin>>f[i];
    for(int i = 0; i < n; i++) pq.push({f[i], s[i]});
    while(!pq.empty()){
        pair<int, int> t = pq.top(); pq.pop();
        if(t.second >= lastClass){
            nClass++;
            lastClass = t.first;
        }
    }
    cout<<nClass;
    return 0;
}
