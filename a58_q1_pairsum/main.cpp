#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n,k,q;
    unordered_map<int,int> m;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    for(int i = 0; i < k; i++){
        cin>>q;
        bool check = false;
        for(int j = 0; j < n; j++){
            if(q - arr[j] == arr[j] && m[q-arr[j]] > 1){
                cout<<"YES\n";
                check = true;
                break;
            }
            else if(q - arr[j] != arr[j] && m[q - arr[j]] > 0){
                cout<<"YES\n";
                check = true;
                break;
            }
        }
        if(!check) cout<<"NO\n";
    }
    return 0;
}
