#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int findByU(vector<pair<int,int>> v, int u){
    for(int i = 0; i < v.size(); i++) if(v[i].second == u) return i;
    return -1;
}

int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    int item[n] = {};
    vector<vector<pair<int, int>>> bid(n);
    map<int,vector<int>> ans;
    for(int i = 0; i < n; i++) cin>>item[i];
    for(int k = 0; k < a; k++){
        char task;
        cin>>task;
        int u,i,v;
        if(task == 'B'){
            cin>>u>>i>>v;
            int index = findByU(bid[i-1], u);
            if(index != -1) bid[i-1][index] = {v, u};
            else bid[i-1].push_back({v, u});
        }
        else{
            cin>>u>>i;
            int index = findByU(bid[i-1], u);
            if(index != -1) bid[i-1].erase(bid[i-1].begin() + index);
        }
    }
    for(int i = 0; i < n; i++){
        sort(bid[i].begin(), bid[i].end(), greater<pair<int,int>>() );
        int index = 0;
        while(item[i] != 0 && index < bid[i].size()){
            item[i]--;
            if(bid[i][index].first != 0) ans[bid[i][index++].second].push_back(i+1);
        }
    }
    for(int i = 0; i < m; i++){
        if(ans[i+1].size() == 0) cout<<"NONE\n";
        else{
            for(int it: ans[i+1]) cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
