#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int getPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = (s+e)/2;
        while(s<e){
            if(nums[mid]>nums[0]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
            mid = (s+e)/2;
        }
        return s;
    }

    int binarySearch(vector<int>& nums, int s, int e, int key) {
        int start = s;
        int end = e;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] == key) {
                return mid;
            }
            
            if (key > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        int n = nums.size();
        
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1, target);
        } else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 5;

    int result = solution.search(nums, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
    return 0;
}