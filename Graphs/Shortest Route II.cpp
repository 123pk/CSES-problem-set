/*
Algorithm :- Floyd Warshall
Approach :- We try every possible path and maintain  one 2d matrix which store the min cost to rech (i,j) and(j,i)
Time Complexity :- O(n^3)
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void find(int node,vector<vector<pair<int,int>>>&graph,vector<vector<int>>&dist,vector<int>&used,vector<int>&d){
    
    queue<pair<int,int>>bfs;
    bfs.push({node,0});
    //dist[node][node] = 0;
    int n = graph.size();
     
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
  
d[i] = 1e18;  }
  //  if(node <= 1)cout<<"\n";
}

int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;
    
    vector<vector<int>>dist(n,vector<int>(n,1e14));
    
   // vector<vector<pair<int,int>>>graph(n);
    for(int i=0;i<m;++i){
        int u,v,d;
        cin>>u>>v>>d;
        u--;
        v--;
        if(d<dist[u][v]){
         
        dist[u][v] = dist[v][u] = min(dist[u][v],d);
        }
    }
    for(int i=0;i<n;++i)dist[i][i] = 0;
    
    for(int i=0;i<n;++i){
         for(int j=0;j<n;++j){
             for(int l=j+1;l<n;++l){
                 if((dist[j][i] + dist[i][l])<dist[j][l]){
                     dist[j][l] = dist[l][j] = dist[j][i] + dist[i][l];
                 }
             }
         }
    }
    
    for(int i=0;i<q;++i){
        int u,v;
        cin>>u>>v;
        u--;v--;
        int d = dist[u][v];
        if(d == 1e14)d = -1;
        cout<<d<<"\n";
    }
    
}
