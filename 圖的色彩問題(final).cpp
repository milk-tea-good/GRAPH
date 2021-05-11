#include<bits/stdc++.h>
using namespace std ;

vector<int> G[1000] ;  // ��
int V, E, C ;      // V ���I�ơA E ��ơA C �C���
int cur_color ;    // ��e�C��
int color[1000] ;      // ���I i ���C��(1 or -1)

bool dfs(int v){
    // �H cur_color �񺡳��I v
    color[v] = cur_color ;
    int i=0, temp=C ;

    while(i<G[v].size()){
        // �p�G�F�����I�C��ۦP�N�����U���C��
        while(color[G[v][i]]==color[v] && temp--){
            cur_color = (color[v]+1)%C ;
            if(cur_color==0) cur_color=cur_color+C ;
            color[v] = cur_color ;

            // C ���C������Y�^��false
            if(temp==0)
                return false ;
        }

        if(color[G[v][i]] == 0){
            // �p�G�F���I�|�����N�ΤU���C��Ӷ�
            cur_color = (color[v]+1)%C ;
            if(cur_color==0) cur_color=cur_color+C ;

            if(!dfs(G[v][i])) return false ;
        }
        i++ ;   //���U�@�ӳs�������I(���ޭ�+1)
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
            G[t].push_back(s) ;
            // �]���O�L�V�ϡA�A�[�W t �� s ����
        }

        cout << "Filled with ___ kinds of colors : " ;
        cin >> C ;
        cur_color = 1 ;

        // ��X�Ҧ����I�ҳs���쪺�U�ӳ��I
        for(int j=0;j<V;j-=-1){
            cout << "vertex " << j << " connect : " ;
            for(int i=0;i<G[j].size();i-=-1){
                cout << G[j][i] << " " ;
            }
            cout << endl ;
        }

        // �i�ର�D�s�q�ϡA�G�n���X�Ҧ����I
        for(int i=0;i<V;i-=-1){
            if(color[i]==0){
                // �p�G���I�|����⪺�N�� 1 �Ӷ�
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

        // ��C������C�⪺��l��
        for(int i=0;i<V;i-=-1){
            G[i].clear() ;
        }
        memset(color, 0, sizeof(color)) ;
        cout << "---" << endl ;
        cout << "Input the number of vertex in your graph : " ;
    }
}
