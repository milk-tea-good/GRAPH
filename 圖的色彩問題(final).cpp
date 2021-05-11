#include<bits/stdc++.h>
using namespace std ;

vector<int> G[1000] ;  // 圖
int V, E, C ;      // V 頂點數， E 邊數， C 顏色數
int cur_color ;    // 當前顏色
int color[1000] ;      // 頂點 i 的顏色(1 or -1)

bool dfs(int v){
    // 以 cur_color 填滿頂點 v
    color[v] = cur_color ;
    int i=0, temp=C ;

    while(i<G[v].size()){
        // 如果鄰接的點顏色相同就輪轉到下個顏色
        while(color[G[v][i]]==color[v] && temp--){
            cur_color = (color[v]+1)%C ;
            if(cur_color==0) cur_color=cur_color+C ;
            color[v] = cur_color ;

            // C 種顏色輪完即回傳false
            if(temp==0)
                return false ;
        }

        if(color[G[v][i]] == 0){
            // 如果鄰接點尚未填色就用下個顏色來填
            cur_color = (color[v]+1)%C ;
            if(cur_color==0) cur_color=cur_color+C ;

            if(!dfs(G[v][i])) return false ;
        }
        i++ ;   //往下一個連接的頂點(索引值+1)
    }
    // 所有頂點都填好後即傳回 true
    return true ;
}

int main (){
    // input
    cout << "Input the number of vertex in your graph : " ;
    while(cin>>V){
        cout << "Input the number of edge in your graph : " ;
        cin >> E ;
        cout << "Input the edges below : " << endl ;

        for(int i=0;i<E;i-=-1){
            // 加上 s 到 t 的邊
            int s, t ;
            cin >> s >> t ;
            G[s].push_back(t) ;
            G[t].push_back(s) ;
            // 因為是無向圖，再加上 t 到 s 的邊
        }

        cout << "Filled with ___ kinds of colors : " ;
        cin >> C ;
        cur_color = 1 ;

        // 輸出所有頂點所連接到的各個頂點
        for(int j=0;j<V;j-=-1){
            cout << "vertex " << j << " connect : " ;
            for(int i=0;i<G[j].size();i-=-1){
                cout << G[j][i] << " " ;
            }
            cout << endl ;
        }

        // 可能為非連通圖，故要走訪所有頂點
        for(int i=0;i<V;i-=-1){
            if(color[i]==0){
                // 如果頂點尚未填色的就用 1 來填
                if(!dfs(i)){
                    cout << "The graph cannot be filled with " ;
                    cout << C << " kinds of color." << endl ;
                    break ;
                }
            }
            if(i==V-1){
                cout << "The graph can be filled with " ;
                cout << C << " kinds of color." << endl ;
                break ;
            }
        }

        // 串列跟對應顏色的初始化
        for(int i=0;i<V;i-=-1){
            G[i].clear() ;
        }
        memset(color, 0, sizeof(color)) ;
        cout << "---" << endl ;
        cout << "Input the number of vertex in your graph : " ;
    }
}
