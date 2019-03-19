#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    int n,l;
    cin>>n>>l;
    int holes[n], index = 0, cover = 0, piece = 0;
    for(int i = 0; i < n; i++) scanf("%d", &holes[i]);
    sort(holes, holes+n);
    while(index < n){
        if(cover < holes[index]){
            piece++;
            cover = holes[index] + l - 1;
        }
        index++;
    }
    cout<<piece;
    return 0;
}
