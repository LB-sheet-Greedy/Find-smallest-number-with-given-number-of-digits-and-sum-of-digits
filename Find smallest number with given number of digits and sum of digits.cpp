/*
A Simple Solution is to consider all m digit numbers and keep track of minimum number with digit sum as s. 
A close upper bound on time complexity of this solution is O(10^m).


NOTE: first place pe 0 mat rakna galti se bhi bcoz phir usse digits kam ho jaayenge
*/


/*
U TUbE REFER KIYA 

There is a Greedy approach to solve the problem. The idea is to one by one fill all digits from rightmost to leftmost 
(or from least significant digit to most significant). 
We initially deduct 1 from sum s so that we have smallest digit at the end. After deducting 1, 
we apply greedy approach. We compare remaining sum with 9, if remaining sum is more than 9, we put 9 at the current position, 
else we put the remaining sum. Since we fill digits from right to left, 
we put the highest digits on the right side. Below is implementation of the idea.

EX: 8999


    100899
*/

#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int S, int D)
    {
        // code here
        string ans=" ";
        
        //agar saare digits 9 hone pe bhi sum nhi aari iska matlab not possible hoga ex: 9999 < 40
        if((9*D)<S)
        {
        	ans=ans+to_string(-1);
        	return ans;
		}
		else if((9*D)>S)
		{
			// deduct sum by one to account for cases later (There must be 1 left for the most significant digit) ex: 
    		S -= 1;
    		
    		// Fill last m-1 digits (from right to left)
    		for (int i=D-1; i>0; i--)                                 //TC = O(D)
    		{
        		// If sum is still greater than 9, digit must be 9.
        		if (S > 9)
        		{
            		ans=ans+to_string(9);
            		S -= 9;
        		}
        		else if(S<9)
        		{
            		ans=ans+to_string(S);
            		S = 0;
        		}
    		}
    	
    		// Whatever is left should be the most significant digit.
    		ans=ans+to_string(1);  // The initially subtracted 1 is incorporated here.
			reverse(ans.begin(), ans.end());  //TC = O(D)
			return ans;
		}
}

// Driver code
int main()
{
    int S = 70, D=5;
    cout<<"\n"<<smallestNumber(S,D);
    return 0;
}
