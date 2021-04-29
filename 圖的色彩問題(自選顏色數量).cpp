#include<bits/stdc++.h>
using namespace std ;

vector<int> G[1000] ;  // ��
int V, E, C ;      // V ���I�ơA E ��ơA C �C���
int cur_color ;    // ��e�C��
int color[1000] ;      // ���I i ���C��(1 or -1)

bool dfs(int v){
    color[v] = cur_color ;      // �H cur_color �񺡳��I v

    for(int i=0;i<G[v].size();i-=-1){
        // �p�G�F�����I�C��ۦP�N�Ǧ^false
        if(color[G[v][i]] == color[v] ) return false ;

        if(color[G[v][i]] == 0){
            // �p�G�F���I�|�����N�ΤU���C��Ӷ�
            cur_color = (color[v]+1)%C ;
            if(cur_color==0) cur_color=cur_color+C ;

            if(!dfs(G[v][i])) return false ;
        }
    }

    // �Ҧ����I����n��Y�Ǧ^ true
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
            // �[�W s �� t ����
            int s, t ;
            cin >> s >> t ;
            G[s].push_back(t) ;
            G[t].push_back(s) ; // �]���O�L�V�ϡA�A�[�W t �� s ����
        }

        cout << "Filled with ___ kinds of colors : " ;
        cin >> C ;
        cur_color = 1 ;

        // �i�ର�D�s�q�ϡA�G�n���X�Ҧ����I
        for(int i=0;i<V;i-=-1){
            if(color[i]==0){
                // �p�G���I�|����⪺�N�� 1 �Ӷ�
                if(!dfs(i)){
                    cout << "The graph cannot be filled with " << C << " kinds of color." << endl ;
                    break ;
                }
            }
            if(i==V-1){
                cout << "The graph can be filled with " << C << " kinds of color." << endl ;
                break ;
            }
        }

        // ��C������C�⪺��l��
        for(int i=0;i<E;i-=-1){
            G[i].clear() ;
        }
        memset(color, 0, sizeof(color)) ;
        cout << "---" << endl ;
        cout << "Input the number of vertex in your graph : " ;
    }
}
