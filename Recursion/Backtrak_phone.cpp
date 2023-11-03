#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void solve(string digits, string  output, int index, vector<string>& ans,string mapping[10]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};
int main() {
    Solution sol;
    string digits = "32";
    vector<string> result = sol.letterCombinations(digits);
    cout << "Letter combinations for input " << digits << " are:" << endl;
    for (const string& s : result) {
        cout <<"["<< s <<"]"<< " ";
    }
    cout << endl;
    return 0;
}
