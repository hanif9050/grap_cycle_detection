#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
vector<int>parent(N,-1);
vector<bool>vis(N,false);
bool flag =false;


void dfs(int src){
    vis[src]=true;
    for(int child:v[src]){
        if(vis[child]==true && parent[src] != child){
            flag = true;
        }
        if(vis[child]==false){
            parent[child]=src;
            dfs(child);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
        dfs(0);
        if(flag){
            cout<<"Cycle detected";
        }else{
            cout<<"Cycle Not detected";
        }
    return 0;
}
