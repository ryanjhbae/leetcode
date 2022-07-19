class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.length() != t.length()) return false;
        
        std::unordered_map<char, char> ST;
        std::unordered_map<char, char> TS;
        
        for (int i = 0; i < s.length(); ++i) {
            auto SMapping = ST.find(s[i]);
            auto TMapping = TS.find(t[i]);
            
            if ((SMapping == ST.end() && TMapping != TS.end()) ||
                (TMapping == TS.end() && SMapping != ST.end())) {
                std::cout << "here" << std::endl;
                return false;
            } else if (SMapping == ST.end() && TMapping == TS.end()) {
                ST[s[i]] = t[i];
                TS[t[i]] = s[i];
            } else if (SMapping->second != t[i]) {
                std::cout << "there" << std::endl;
                return false;   
            }
        }
        return true;
    }
};