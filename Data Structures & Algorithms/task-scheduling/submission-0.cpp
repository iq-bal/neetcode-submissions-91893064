class Solution {
public:
    vector<int> freq = vector<int>(26, 0);

    int leastInterval(vector<char>& tasks, int n) {
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        int max_freq = *max_element(freq.begin(), freq.end());
        int max_freq_count = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == max_freq)
                max_freq_count++;
        }

        int slot = (max_freq - 1) * (n + 1) + max_freq_count;
        return max(slot, (int)tasks.size());
    }
};