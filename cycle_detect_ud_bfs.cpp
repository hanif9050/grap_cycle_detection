#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
vector<int>parent(N,-1);
vector<bool>vis(N,false);

bool flag=false;
void bfs(int src){
vis[src]=true;
queue<int>q;
q.push(src);
while(!q.empty()){
    int par=q.front();
    q.pop();
    for(int child:v[par]){
        if(vis[child]==true && parent[par] != child){
            flag=true;
        }
        if(vis[child]==false){
            vis[child]=true;
            parent[child]=par;
            q.push(child);
        }
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
        bfs(0);
        if(flag ==true){
            cout<<"cycle detected";
        }else{
            cout<<"cycle not detected";
        }
    return 0;
}
