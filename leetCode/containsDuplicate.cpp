class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> found;
        for (auto num : nums) {
            if (found.find(num) != found.end())
                return true;
            found.insert(num);
        }
        return false;
    }
};