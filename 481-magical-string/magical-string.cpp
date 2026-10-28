class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int cnt=1;
        int flag=0;
        for(int i=2;i<n;i++){
            if(s[i]=='1') cnt++;
            s.push_back('1'+flag);
            if(s[i]=='2'){
                s.push_back('1'+flag);
            }
            flag^=1;
        }
        return cnt;                
    }
};