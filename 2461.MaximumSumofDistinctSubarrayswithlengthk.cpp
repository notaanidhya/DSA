class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
    if (k > nums.size()) {
        return 0;
    }
    std::unordered_map<int, int> counts;
    long long current_sum = 0;
    long long max_sum = 0;
    for (int i = 0; i < k; ++i) {
        current_sum += nums[i];
        counts[nums[i]]++;
    }
    if (counts.size() == k) {
        max_sum = current_sum;
    }
    for (int i = k; i < nums.size(); ++i) {
        current_sum += nums[i];
        counts[nums[i]]++;
        int old_element = nums[i - k];
        current_sum -= old_element;
        counts[old_element]--;
        if (counts[old_element] == 0) {
            counts.erase(old_element);
        }

        if (counts.size() == k) {
            max_sum = std::max(max_sum, current_sum);
        }
    }
    return max_sum;
}
};
