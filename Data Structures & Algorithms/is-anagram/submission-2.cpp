class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        map<char,int>m1,m2;
        for(auto& ch: s){
            m1[ch]++;
        }
        for(auto& ch: t){
            m2[ch]++;
        }
        for(auto& ch: s){
            if(m2[ch]==m1[ch])
                continue;
            return false;
        }
        return true;
    }
};
