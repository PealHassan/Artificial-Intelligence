#include<bits/stdc++.h> 
using namespace std;  
int goal[3][3] = {1,2,3,4,5,6,7,8,0};  
int cur[3][3];  
int cx[] = {1,-1,0,0};  
int cy[] = {0,0,1,-1};        
struct node {
    int mat[3][3] = {};     
    pair<int,int>empty;  
    int g_score,f_score;      
    node(int arr[3][3]) {
        for(int i = 0; i < 3; i++) 
            for(int j = 0; j < 3; j++) {
                mat[i][j] = arr[i][j];   
                if(mat[i][j] == 0) empty = {i,j};  
            }
    }
};
int h_score(node state) {
    int cnt = 0;   
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(goal[i][j] != state.mat[i][j]) cnt++;   
    return cnt;    
} 
void input() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) 
            cin >> cur[i][j];   
}
void print(node state) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << state.mat[i][j] << ' ';   
        }
        cout << endl;  
    }
    cout << "--------------" << endl;
} 
class cmp {
    public:
        bool operator()(node a, node b)
        {
            if(a.f_score > b.f_score) return true;  
            return false;
        }
};
void aStar() {
    node cur_state(cur); 
    cur_state.g_score = 0;     
    cur_state.f_score = h_score(cur_state) + cur_state.g_score; 
    priority_queue<node, vector<node>, cmp>lis;  
    lis.push(cur_state);
    int cnt = 0;    
    while(lis.size()) {
        node temp = lis.top();  
        print(temp);   
        if(h_score(temp) == 0) break;
        lis.pop();   
        pair<int,int>cell = temp.empty;
        for(int i = 0; i < 4; i++) {
            int nx = cell.first + cx[i];  
            int ny = cell.second + cy[i];  
            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                node temp2 = temp;
                swap(temp2.mat[nx][ny],temp2.mat[cell.first][cell.second]);
                temp2.empty = {nx,ny};
                temp2.g_score++;  
                temp2.f_score = temp.g_score + h_score(temp2);  
                lis.push(temp2);
            }
        }
    }
}
int main() {
    input();   
    aStar();  
    return 0;    
}