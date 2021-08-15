/*
A Simple Solution is to consider all m digit numbers and keep track of minimum number with digit sum as s. 
A close upper bound on time complexity of this solution is O(10^m).


*/


#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int S, int D)
    {
        // code here
        string ans=" ";
        
        for(int i=0;i<10;i++)   //i and j are digits [0----9]
        {
            for(int j=0;j<10;j++)
            {
                if((i+j)==S)
                {
                    //text += std::to_string(i);
                    ans=ans+to_string(i);
                    ans=ans+to_string(j);
                    break;
                }
            }
            break;
        }
        
        return ans;
}

// Driver code
int main()
{
    int S = 9, D=2;
    cout<<"\n"<<smallestNumber(S,D);
    return 0;
}
