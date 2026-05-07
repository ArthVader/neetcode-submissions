class Solution {
public:
    bool isPalindrome(string s) {

        string alphaNumericString = "";
        for(const char& c: s)
        {
            if(isalnum(c))
            {
               alphaNumericString += tolower(c); 
            }
        }

        int totalChars = alphaNumericString.size();
        int i = 0;
        int j = totalChars - 1;
        for(; i < totalChars && j > -1; ++i, --j)
        {
            if(alphaNumericString[i] != alphaNumericString[j])
            {
                return false;
            }
        }

        return true;
    }
};
