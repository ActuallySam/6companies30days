class GfG {
	String encode(String str)
	{
        //Your code here
        String answer = "";
        int count = 1;
        int i = 0, i1 = 0;
        int n = str.length();
        
        for (i=0; i<n-1; i++) {
            if (str.charAt(i) == str.charAt(i+1)) 
                count++;
                
            else if (str.charAt(i) != str.charAt(i+1)) {
                answer = answer + str.charAt(i) + count;
                count = 1;
                i1 = i + 1;
            }
        }
        
        answer = answer + str.charAt(i1) + count;
        return answer;
	}
}