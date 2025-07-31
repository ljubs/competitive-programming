class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> first;
        std::unordered_map<char, int> second;

        for (auto letter : s)
            first[letter]++;
        for (auto letter : t)
            second[letter]++;
        
        return first == second;
    }
};