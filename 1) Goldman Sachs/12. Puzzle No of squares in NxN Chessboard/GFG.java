import java.io.*;
import java.util.*;

class GFG {
	public static void main (String[] args) {
	    int i, fact=1, sum=0;
	    Scanner sc = new Scanner(System.in);
	    int number = sc.nextInt();
	    
	    // Combinations of 1x1, 2x2, 3x3, 4x4, ......., nxn square(s)
		for(i=1;i<=number;i++){    
            fact=fact*i*i;  //
            sum += fact;    // 1x1 + 2x2 + ... + nxn = sum
            fact = 1;       // Resetting value to 1
        } 
        
        System.out.print(sum);
	}
}