class Solution{
    static String decodedString(String s){
        // code here
        Stack<Character> st = new Stack();
        for(int i = 0; i < s.length(); i++){
        
        // Till we reach ']' we are going to push the elements in the stack.
            if(!st.isEmpty() && s.charAt(i) == ']'){
                StringBuilder sb = new StringBuilder();
                // As soon as we reach ']' we are going to create a string that will keep popping characters and storing in the string.
                // For example our stack is ['3', '[', 'a', 'b'] so after this loop the string will be "ba" and the stack will be ['3', '[' ] 
                
                while(st.peek() != '['){
                    sb.append(st.pop());
                }
                st.pop();
 				// Now we reverse the string "ba" to "ab" as givin in original string s.
                sb.reverse();
                StringBuilder str = new StringBuilder();
                int k = 0;
                int m = 0;
 				// This step is done to calculate k in k[ab] and we use this to cover a case such as 100[ab] so that value of m becomes 100.
                while(!st.isEmpty() && st.peek() >= '0' && st.peek() <= '9'){
                    m += (st.pop() - '0')*Math.pow(10,k);
                    k++;
                }
                for(int j = 0; j < m; j++){
                    str.append(sb.toString());
                }

                for(int j = 0; j < str.length(); j++){
                    st.push(str.charAt(j));
                }
            }else{
                st.push(s.charAt(i));
            }
        }
        StringBuilder ans = new StringBuilder();
        for(char ch : st){
            ans.append(ch);
        }
        return ans.toString();
    }
}