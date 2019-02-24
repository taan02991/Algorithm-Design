#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    set<int> s;
    cin>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        if(k < 1 || k > n){
            cout<<"NO";
            return 0;
        }
        s.insert(k);
    }
    if(s.size() == n) cout<<"YES";
    else cout<<"NO";
    return 0;
}
