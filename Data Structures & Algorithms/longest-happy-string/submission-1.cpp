class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)
            pq.push({a,'a'});
        if(b>0)
            pq.push({b,'b'});
        if(c>0)
            pq.push({c,'c'});

        
        string ans = "";


        while(!pq.empty()){
            auto [remaining_count,character] = pq.top();
            pq.pop();

            int n = ans.size();

            if(n>=2 && ans[n-1]==character && ans[n-2]==character)
            {
                if(pq.size()==0)
                    break;
                auto [next_remaining_count,next_character] = pq.top();
                pq.pop();
                ans += next_character;
                next_remaining_count--; 
                if(next_remaining_count>0)
                    pq.push({next_remaining_count,next_character});
                pq.push({remaining_count,character});
            }
            else{
                ans += character;
                remaining_count--;
                if(remaining_count>0)
                    pq.push({remaining_count,character});
            }
        }
        return ans;
    }
};

