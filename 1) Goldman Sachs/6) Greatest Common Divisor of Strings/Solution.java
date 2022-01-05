class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // string str to keep track of the current string length and comparison
        // string to keep adding the characters if no matching patterns are found
        if(!(str1 + str2).equals(str2 + str1)) 
            return "";
        
        else if (str1.equals(str2))
            return str1;
        
        else if (str1.length() > str2.length())
            return gcdOfStrings(str1.substring(str2.length()), str2);
        
        else 
            return gcdOfStrings(str2.substring(str1.length()), str1);
        
    }
}