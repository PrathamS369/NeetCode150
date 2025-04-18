class Solution {
    // Speed up I/O operations
    bool init=[](){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return true;
    }();
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> mp;
        vector<vector<string>> s1;
        
        for (const string& str : strs) {
        string s = str;
        sort(s.begin(), s.end());  // Sort the string to generate the key
        mp[s].push_back(str);  // Group the original string by its sorted version
    }
         // Second loop: Iterate through the map and add the groups to the result
    for (const auto& pair : mp) {
        s1.push_back(pair.second);  // Add the group of anagrams directly
    }

    return s1;
        
   
        
    }
};
