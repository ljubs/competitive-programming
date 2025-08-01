class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left, right;
        left = 0;
        right = numbers.size() - 1;
        while (left <= right) {
            if (numbers[left] + numbers[right] < target) left++;
            else if (numbers[left] + numbers[right] > target) right--;
            else return {left + 1, right + 1}; // Return the indices (1-indexed) of the two numbers...
        }
        return {};
    }
};