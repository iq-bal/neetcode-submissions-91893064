class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string min_len_str = strs[0];
        for(auto& str : strs){
            if(str.size()<min_len_str.size())
                min_len_str = str;
        }
        for(int i=0; i<min_len_str.size(); i++){
            int flag = 0; 
            for(int j=0; j<strs.size(); j++){
                if(min_len_str.substr(0,min_len_str.size()-i)==strs[j].substr(0,min_len_str.size()-i))
                    continue;
                flag=1;
                break;
            }
            if(!flag)
                return min_len_str.substr(0,min_len_str.size()-i);
        }
        return "";
    }
};