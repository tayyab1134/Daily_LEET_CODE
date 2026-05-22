class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

   
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int maxLength = 0;

   
        for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            int num = it->first;

            if (freq.find(num + 1) != freq.end()) {
                maxLength = max(maxLength, freq[num] + freq[num + 1]);
            }
        }

        return maxLength;
    }
};