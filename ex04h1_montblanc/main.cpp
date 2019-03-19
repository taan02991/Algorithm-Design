#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, d, k, now, day;
    cin>>n>>d;
    int points[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &points[i]);
    }
    k = points[n-1]/d;
    now = 0;
    day = 0;
    while(now < points[n-1]){
        now = *(upper_bound(points, points + n, now + k)-1);
        day++;
        if(day > d){
            now = 0;
            day = 0;
            k = k+1;
        }
    }
    cout<<k<<" "<<day<<endl;
}

