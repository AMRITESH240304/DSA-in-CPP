#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        
        int element = nums[index];
        solve(nums, output, index + 1, ans);
        output.push_back(element);
        solve(nums, output, index + 1, ans);
        output.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    vector<vector<int>> subsets = solution.subsets(nums);

    for (const vector<int>& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
