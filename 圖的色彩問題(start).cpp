#include<bits/stdc++.h>
using namespace std ;

vector<int> G[1000] ;  //��
int V, E ;      // V ���I�ơA E ���

int color[1000] ;      //���I i ���C��(1 or -1)

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
        //�[�W s �� t ����
        int s, t ;
        cin >> s >> t ;
        G[s].push_back(t) ;
        G[t].push_back(s) ; //�]���O�L�V�ϡA�A�[�W t �� s ����
    }
    //�i�ର�D�s�q�ϡA�G�n���X�Ҧ����I
    for(int i=0;i<V;i-=-1){
        if(color[i]==0){
            //�p�G���I�|����⪺�N�� 1 �Ӷ�
            if(!dfs(i, 1)){
                cout << "No" << endl ;
                return 0 ;
            }
        }
    }
    cout << "Yes" << endl ;
    return 0 ;
}
