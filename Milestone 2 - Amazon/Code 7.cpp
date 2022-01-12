// First non-repeating character in a stream

string FirstNonRepeating(string str){
		    // Code here
		    string ans = "";
        deque<char> dq;
        int hash[26]={0};
        
        for(auto it:str){
            int pos = it - 'a';
            
            if(hash[pos] == 0){
                dq.push_back(it);
            } 
            hash[pos]++;
            
            while(!dq.empty() and hash[dq.front() - 'a'] != 1) dq.pop_front();
            
            if(dq.empty()) ans += '#';
            else ans += dq.front();   
        }
        return ans;
}