/*
Platform :- CSES
Approach :- So if you carefully analyse the problem you will find you are given an 'Undirected' graph and you need to find a 'cycle of length (>=3)'
            We will DFS to traverse through each path and we will also maintain one count node which store the time at which we visited that node ,
            -- if in future we visit that node again we will be able to knwo the legh of cycle which will ((current_time - first_time_visited_this_node)+1)
            -- If we found a cycle of lenth >=3 we will make and using backtracking we will get the value in an array.

Topics :- DFS + Backtracking 
Time Complexity :- O(n+m) , n = no of node ,m = no of edges
*/
#include<bits/stdc++.h>
using namespace std;

void find(int node,vector<vector<int>>&graph,vector<int>&vis,int k,vector<int>&path,vector<int>&dis,int& stop,int& f,int& done){
    
    //if we have allready found a path and get in our array we don't need to look anymore
    if(done)return;
            
    vis[node]++;
    k++;
            
    dis[node] = k;
    //marking the first time we came to this node for the node  
    for(auto&x:graph[node]){
                
        if(done)return;
        
         if(vis[x]){
            //checking the lenght of cycle
            int cycle_len = (k - dis[x])+1;
            
            if(cycle_len>=3){
                stop = x;
                path.push_back(x);
                f=1;
                return;
            }
        }
        else{
            find(x,graph,vis,k,path,dis,stop,f,done);
            
            //intialising path through backtracking
            if(f){
                path.push_back(x);
              
                if(x == stop){
                    f = 0;
                    done = 1;
                    return;
                }
                //this is for the case when cycle ends at the starting node of dfs
                if(node == stop){
                    path.push_back(node);
                    done = 1;
                    f = 0;
                    return;
                }
                return;
            }
        }
    }
}

int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>>graph(n);
        
        for(int i=0;i<m;++i){
            int u,v;
            cin>>u>>v;
            u--;v--;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
           
        }
        
        /*
        The approach is to find a cycle starting and ending at same node of size n
        */
        
        vector<int>vis(n),dis(n);
       
        vector<int>ans;
        for(int i=0;i<n;++i){
            if(vis[i])continue;
            
            vector<int>temp;
            int k = 0,f = 0,done = 0,stop = -1;
            find(i,graph,vis,k,temp,dis,stop,f,done);
             
            if(temp.size()>=3){
             //this means we have a cycle of length >=3
                reverse(temp.begin(),temp.end());
                ans = temp;
                break;
            }
            else temp.clear();
        }
        
        if(ans.size() == 0)cout<<"IMPOSSIBLE";
        else{
             
            cout<<ans.size()<<"\n";
            for(auto&x:ans)cout<<x+1<<" ";
        }
    }
}
