public class Solution {
    public bool IsPalindrome(string s) {
        
        // ToLower on full string type and store the copy returned in a new string
        // Use LINQ to produce an array of alphanumeric characters in a string.
        string lowerCaseString = s.ToLower();
        string alphaNumericString = new string(
            (from c in lowerCaseString
            where char.IsLetterOrDigit(c)
            select c).ToArray()
        );
        // Method syntax
        // string alphaNumericString = new string(lowerCaseString.Where(c => char.IsLetterOrDigit(c)).ToArray());

        int totalChars = alphaNumericString.Length;
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
}
