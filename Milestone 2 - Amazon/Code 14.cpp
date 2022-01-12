// Burning Tree

class Solution {
  public:

int ans=0;
   int diamete(Node* root,int t) {
      if(root==NULL) return 0;
      int x=diamete(root->left,t),y=diamete(root->right,t);
        if(root->data==t)
        {
           ans=max(x,y);
           return -1;
        }
        if(x<0) { x=abs(x);
           ans=max(ans,x+y);
           return -1-x;
        }
        if(y<0) { y=abs(y);
           ans=max(ans,x+y);
           return -1-y;
        }
        if(x<y) return(y+1);
        else return x+1;
  
   }

   int minTime(Node* root, int target) 
   {  
      diamete(root,target);
      return ans;
   }
};