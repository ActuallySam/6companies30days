#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/#
*/
int missingNumber(const string& str){

    int len = str.length() ;
    //maximum possible digits = 6
    for(int i = 1;i<=6;i++){
        //if stirng length is lessthan digits
        if(i>len) break ;
        //boolean for finding pattern
        bool ismissed = false;
        //mis_no = missing number
        int prev = 0,mis_no = -1 ;
        int j = 0;
        string temp = str.substr(j,i) ;
        //finding first number
        prev = stoi(temp) ;
        j = j+i ;
        
        while(j<len){
            //cout<<prev<<endl;
            int n1 = prev+1 ; //first possbility
            int n2 = prev+2 ; //second possbility

            int l1 = log10(n1)+1 ; //length
            int l2 = log10(n2)+1 ; //length

            string s1 = str.substr(j,l1);
            string s2 = str.substr(j,l2);

            int nxt1 = stoi(s1);
            int nxt2 = stoi(s2) ;
           
            if(n1 == nxt1){
                //if in pattern just go to other number
                prev = nxt1 ;
                j = j+l1 ;
            }
            else if(n2 == nxt2 && mis_no == -1){
                //if missing number = -1 which implies we didnot find missing number
                //so update
                mis_no = n1 ;
                prev = nxt2 ;
                j = j+l2 ;
            }
            else if(mis_no!=-1 && n1!=nxt1){
                //possibilty of missing pattern
                ismissed = true ;
                break;
            }
            
            else{
                 break ;
            }
        }
        if(mis_no !=-1 && !ismissed){
            //if pattern is there as well as we found missing no then we return
            return mis_no ;
        }
        
    }
    return -1;
    /*
    Time : O(N)
    Space : O(1)
    */
    
}
int main() {
/**/
    cout<<missingNumber("121315")<<endl;
return 0;
}