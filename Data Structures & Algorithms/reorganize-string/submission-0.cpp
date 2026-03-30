class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Changed:
        // Use pair<int,char> instead of pair<char,int>
        // so the heap is ordered by frequency first.
        priority_queue<pair<int, char>> pq;

        // Changed:
        // Loop over 26 letters, not over the string,
        // so each character is pushed only once.
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], char(i + 'a')});
            }
        }

        string ans = "";

        // Changed:
        // Store previous character outside the heap for one turn.
        int prevCount = 0;
        char prevChar = '#';

        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();

            // Use current character
            ans += ch;
            count--;

            // Changed:
            // Put the previous character back only after
            // we have placed a different character.
            if (prevCount > 0) {
                pq.push({prevCount, prevChar});
            }

            // Current character becomes previous
            prevCount = count;
            prevChar = ch;
        }

        // Changed:
        // Final validation.
        // If reorganization failed, return "".
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] == ans[i - 1]) {
                return "";
            }
        }

        return ans.size() == s.size() ? ans : "";
    }
};