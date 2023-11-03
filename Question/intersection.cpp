// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;

// class Solution {
//     vector<int> binarysearch(int target, vector<int>& nums1) {
//         int s = 0;
//         int e = nums1.size() - 1;
//         vector<int> ans;
        
//         while (s <= e) {
//             int mid = s + (e - s) / 2; 
//             if (nums1[mid] == target) {
//                 ans.push_back(target);
//                 break;
//             } else if (nums1[mid] > target) {
//                 e = mid - 1;
//             } else {
//                 s = mid + 1;
//             }
//         }
//         return ans;
//     }

// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> result;
//         vector<int> ans;
//         set<int> uniqueSe(nums2.begin(), nums2.end());
//         nums2.assign(uniqueSe.begin(), uniqueSe.end());
//         for (int i = 0; i < nums2.size(); i++) {
//             result = binarysearch(nums2[i], nums1);
//             ans.insert(ans.end(), result.begin(), result.end());
//         }
//         set<int> uniqueSet(ans.begin(), ans.end());
//         ans.assign(uniqueSet.begin(), uniqueSet.end());
//         return ans;
//     }
// };

// int main() {
//     vector<int> nums1 = {2,1};
//     vector<int> nums2 = {1,1};

//     Solution solution;
//     vector<int> result = solution.intersection(nums1, nums2);

//     cout << "nums1: ";
//     for (int num : nums1) {
//         cout << num << " ";
//     }
//     cout << endl;

//     cout << "nums2: ";
//     for (int num : nums2) {
//         cout << num << " ";
//     }
//     cout << endl;

//     cout << "Intersection: ";
//     for (int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums1Set.count(num) > 0) {
                ans.push_back(num);
            }
        }
        set<int> uniqueSet(ans.begin(), ans.end());
        ans.assign(uniqueSet.begin(), uniqueSet.end());
        return ans;
    }
};

int main() {
    vector<int> nums1 = {2, 1};
    vector<int> nums2 = {1, 1};

    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
