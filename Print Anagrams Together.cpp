#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> map; // To store sorted string as key and anagram groups as value
        for (int i = 0; i < arr.size(); i++) {
            string temp = arr[i];
            sort(temp.begin(), temp.end()); // Sort the string to find its canonical form
            map[temp].push_back(arr[i]);   // Group anagrams by their sorted form
        }

        vector<vector<string>> answer; // To store the result
        for (auto it : map) {
            answer.push_back(it.second); // Push each group of anagrams into the result
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.anagrams(arr);

    // Print the result
    for (auto group : result) {
        for (auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
