class Solution {
public:
    bool isPalindrome(string s) {
        for(char& c: s)
        {
            c = tolower(c);
        }

        string alphaNumericString = "";
        for(const char& c: s)
        {
            if(isalnum(c))
            {
               alphaNumericString += c; 
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
