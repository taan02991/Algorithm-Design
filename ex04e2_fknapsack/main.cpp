#include <iostream>
#include <queue>

using namespace std;

int main()
{
    double W, V = 0;
    int N;
    cin>>W>>N;
    double v[N], w[N];
    priority_queue<pair<double, int>> pq;
    for(int i = 0; i < N; i++) cin>>v[i];
    for(int i = 0; i < N; i++) cin>>w[i];
    for(int i = 0; i < N; i++) pq.push({v[i]/w[i], i});
    while(W > 0 && !pq.empty()){
        pair<double, int> m = pq.top();
        if(w[m.second] < W){
            W -= w[m.second];
            V += v[m.second];
            pq.pop();
        }
        else{
            V += m.first*W;
            break;
        }
    }
    printf("%.4f", V);
}
