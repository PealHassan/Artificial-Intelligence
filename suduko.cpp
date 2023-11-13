#include<bits/stdc++.h> 
using namespace std;  
vector<string>maze(9);  
bool isSafe(int row, int col, int val) {
    int bR = (row/3)*3, bC = (col/3)*3, cnt = 0;    
    for(int i = 0; i < 9; i++) {
        if(maze[row][i] == val+'0') return false;   
        if(maze[i][col] == val+'0') return false;    
        if(maze[bR][bC] == val+'0') return false;   
        cnt++;   
        bC++;  
        if(cnt == 3) {
            cnt = 0;   
            bR++;  
            bC-=3;
        } 
    }
    return true;  
}
int solCnt = 0,flag = 0;    
void suduko(int row, int col) {
    if(col == 9) {
        row++;
        col = 0;   
    }
    if(row == 9) {
        cout << "Solution " << ++solCnt << ":" << endl;   
        for(int i = 0; i < 9; i++) cout << maze[i] << endl;
        flag = 1;
        return;  
    }
    if(maze[row][col] != '.') {
        suduko(row,col+1);   
        return;   
    }
    for(int i = 1; i <= 9; i++) {
        if(isSafe(row,col,i)) {
            maze[row][col] = i + '0';    
            suduko(row,col+1);
            maze[row][col] = '.';   
        }
        if(flag) return;
    } 
}
int main() {
    for(int i = 0; i < 9; i++) cin >> maze[i];
    suduko(0,0);       
    return 0;    
}