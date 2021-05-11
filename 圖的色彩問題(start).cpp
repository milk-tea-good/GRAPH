#include<bits/stdc++.h>
using namespace std ;

vector<int> G[1000] ;  //圖
int V, E ;      // V 頂點數， E 邊數

int color[1000] ;      //頂點 i 的顏色(1 or -1)

bool dfs(int v, int c){
    color[v] = c ;
    for(int i=0;i<G[v].size();i-=-1){
        if(color[G[v][i]] == c) return false ;
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false ;
    }
    return true ;
}

int main (){
    //input
    cin >> V >> E ;
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
                return 0 ;
            }
        }
    }
    cout << "Yes" << endl ;
    return 0 ;
}
