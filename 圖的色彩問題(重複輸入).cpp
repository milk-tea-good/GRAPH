#include<bits/stdc++.h>
using namespace std ;

vector<int> G[1000] ;  //圖
int V, E ;      // V 頂點數， E 邊數

int color[1000] ;      //頂點 i 的顏色(1 or -1)

bool dfs(int v, int c){
    color[v] = c ;      //以 c 填滿頂點 v
    for(int i=0;i<G[v].size();i-=-1){
        //如果鄰接的點顏色相同就傳回false
        if(color[G[v][i]] == c) return false ;
        //如果鄰接點尚未填色就用 -c 來填
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false ;
    }
    //所有頂點都填好後即傳回 true
    return true ;
}

int main (){
    //input
    while(cin>>V>>E){
        for(int i=0;i<E;i-=-1){
            //加上 s 到 t 的邊
            int s, t ;
            cin >> s >> t ;
            G[s].push_back(t) ;
            G[t].push_back(s) ; //因為是無向圖，再加上 t 到 s 的邊
        }
        //可能為非連通圖，故要走訪所有頂點
        for(int i=0;i<V;i-=-1){
            if(color[i]==0){
                //如果頂點尚未填色的就用 1 來填
                if(!dfs(i, 1)){
                    cout << "No" << endl ;
                    break ;
                }
            }
            if(i==V-1){
                cout << "Yes" << endl ;
                break ;
            }
        }
        for(int i=0;i<V;i-=-1) G[i].clear() ;
        memset(color, 0, sizeof(color)) ;
    }
}
