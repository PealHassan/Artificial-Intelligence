#include<bits/stdc++.h>
using namespace std;
int main() {

    while(1) {
        vector<string>ques;
        string temp2;
        getline(cin,temp2);
        string word = "";
        for(int i = 0; i < temp2.size(); i++) {
                if(temp2[i] == ' ' || temp2[i] == '?') {
                    ques.push_back(word);
                    word = "";
                }
                else word += temp2[i];
        }
        if(word.size()) ques.push_back(word);
        freopen("input.txt", "r", stdin);



        string x;
        vector<string>ans;
        vector< pair<double,int> > compare;
        vector<string>lis;
        string temp = "";
        while(cin >> x) {
            if(ans.size() == 0) temp += x;
            else temp += (" " + x);
            ans.push_back(x);
            if(x[x.size()-1] == '.') {
                int cnt = 0;
                for(int i = 0; i < ans.size(); i++) {
                    for(int j = 0; j < ques.size(); j++) {
                        if(ques[j] == ans[i]) cnt++;
                    }
                }
                double fact = (cnt/(ans.size()*1.0))*100;
                compare.push_back({fact,lis.size()});
                lis.push_back(temp);
                temp = "";
                ans.clear();
            }
        }
        sort(compare.rbegin(),compare.rend());
        cout << lis[compare[0].second] << endl;
        break;
    }


}
