
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void find(int node,vector<vector<pair<int,int>>>&graph,vector<vector<int>>&dist,vector<int>&used){
    
    queue<pair<int,int>>bfs;
    bfs.push({node,0});
    //dist[node][node] = 0;
    int n = graph.size();
    vector<int>d(n,1e18);
    d[node] = 0;
    
    
    while(!bfs.empty()){
        pair<int,int>temp = bfs.front();
        bfs.pop();
        int cur = temp.first;
        int cost = temp.second;
         
        
        for(auto&x:graph[cur]){
            int city = x.first;
            int len = x.second;
            int cur_len = len + cost;
            
            if(used[city] && cur == node){
                
                d[city] = dist[city][cur];
                //cout<<city+1<<" "<<d[city]<<" "<<cur+1<<"-- \n";
                for(int j=0;j<n;++j){
                    int through = dist[city][j];
                    int fin_len = d[city] + through;
                    if(fin_len<d[j]){
                        d[j] = fin_len;
                        bfs.push({j,fin_len});
                    }
                }
                
                continue;
            }
            
            
            if(d[city]>cur_len){
                
                d[city] = cur_len;
               // cout<<cur+1<<" "<<city+1<<" "<<dist[cur][city]<<"\n";
                bfs.push({city,cur_len});
            }
        }
    }
    
    for(int i=0;i<n;++i){
      //  if(node <= 1)cout<<d[i]<<" ";
        dist[node][i] = d[i];
    }
  //  if(node <= 1)cout<<"\n";
}
 
int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;
    
    vector<vector<int>>dist(n,vector<int>(n,1e18));
    
    vector<vector<pair<int,int>>>graph(n);
    for(int i=0;i<m;++i){
        int u,v,d;
        cin>>u>>v>>d;
        u--;
        v--;
        graph[u].push_back({v,d});
        graph[v].push_back({u,d});
    }
    
    vector<int>used(n);
    for(int i=0;i<n;++i){
        find(i,graph,dist,used);
        used[i]++;
    }
    
    for(int i=0;i<q;++i){
        int u,v;
        cin>>u>>v;
        u--;v--;
        int d = dist[u][v];
        if(d == 1e18)d = -1;
        cout<<d<<"\n";
    }
    
}
