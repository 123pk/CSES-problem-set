/*
Platform :- CSES
Approach :- We will do bfs and maintain one dist array which store the minimum distance to reach out to each oother node starting from '0'th node,
            we will greedily do our bfs usign priority queue (min heap) on distance.
Time Complexity :- O(n+m log (n+m))
*/
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,long long>>graph[n];
    int u,v;
    long long w;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        u--;
        v--;
        graph[u].push_back({v,w});
        //graph[v].push_back({u,w});
    }
    
    vector<long long>dist(n,1e18);
    dist[0]=0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>> > bfs;
    bfs.push({0ll,0});
    vector<int>used(n);
    
    while(!bfs.empty()){
        int c = bfs.size();
        for(int i=0;i<c;++i){
            pair<long long,int> temp = bfs.top();
            bfs.pop();
            int x = temp.second;
            long long cost = temp.first;
            if(used[x])continue;
            used[x]=1;
            
            for(int j=0;j<graph[x].size();++j){
                
                long long tot = cost + graph[x][j].second;
                int val = graph[x][j].first;
                
                if(tot<dist[val]){
                    dist[val]=tot;
                    bfs.push({tot,val});
                }
            }
        }
    }
    
    for(int i=0;i<n;++i)cout<<dist[i]<<" ";
    
    
}
