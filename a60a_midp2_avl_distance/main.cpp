#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(5*10e5);

int nAtLevel(int root, int level, int side){
    if(level < 0) return 0;
    if(level == 0) return 1;
    int ans = 0;
    if(side == 2){
        for(int child: v[root]){
            ans += nAtLevel(child, level-1, 2);
        }
    }
    else if(v[root].size() > side){
        ans += nAtLevel(v[root][side], level-1, 2);
    }
    return ans;
}

int nPairAt(int root, int k){
    int ans = 0;
    for(int i = 0; i <= k; i++){
        int left_level = i, right_level = k - i;
        ans += nAtLevel(root, left_level, 0) * nAtLevel(root, right_level, 1);
    }
    return ans;
}

int main()
{
    int n, k, ans = 0;
    cin>>n>>k;
    for(int i = 0; i < n-1; i++){
        int p,c;
        cin>>p>>c;
        v[p].push_back(c);
    }
    for(int i = 1; i <= n; i++){
        ans += nPairAt(i, k);
    }
    cout<<ans;
}
