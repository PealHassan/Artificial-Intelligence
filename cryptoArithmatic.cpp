#include<bits/stdc++.h>  
using namespace std;  
set<char>s;   
vector<char>ch;  
vector<int>assign(30,-1);
string word1, word2, word3;  
int findVal(string x) {
    int l = 1, res = 0;  
    for(int i = x.size()-1; i>=0; i--) {
        res += (assign[x[i]-'a']*l);  
        l *= 10;
    }
    return res;   
}
void printMagic(string x) {
    for(int i = 0; i < x.size(); i++) {
        if(i == 0 && assign[x[i]-'a'] == 0) continue;
        else cout << assign[x[i]-'a'];   
    }

}
int solCnt = 0;   
void crypto(int pos, int pat) {
    if(pos == ch.size()) {
        int u = findVal(word1);  
        int v = findVal(word2);  
        int w = findVal(word3);    
        if(u+v == w) {
            solCnt++; 
            cout << "Solution " << solCnt << ": ";   
            printMagic(word1);
            cout << " + ";  
            printMagic(word2);
            cout << " = ";  
            printMagic(word3);
            cout << endl;
        }
        return;   
    }
    for(int i = 0; i <= 9; i++) {
        if(((pat >> i) & 1) == 0) {
            assign[ch[pos]-'a'] = i;
            pat |= (1 << i);
            crypto(pos+1,pat);
            pat ^= (1 << i);    
            assign[ch[pos]] = -1;
        }
    }
} 
int main() {
    cin >> word1 >> word2 >> word3;       
    for(int i = 0; i < word1.size(); i++) s.insert(word1[i]);  
    for(int i = 0; i < word2.size(); i++) s.insert(word2[i]);  
    for(int i = 0; i < word3.size(); i++) s.insert(word3[i]);  
    for(auto e: s) ch.push_back(e);     
    crypto(0,0);
    return 0;     
}