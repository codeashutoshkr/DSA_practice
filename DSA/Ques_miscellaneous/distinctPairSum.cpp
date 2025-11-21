/* You are given a range of integers {L, L+1, …, R}. An integer X is said to be reachable
 if it can be represented as a sum of two not necessarily distinct integers in this range.
  Find the number of distinct reachable integers.
Input :  The first and only line of each test case contains two space-separated integers  L and R.
Output : For each test case, print a single line containing one integer — the number of reachable integers.
Constraints : 1 ≤ T ≤ 10^5 & 1 ≤ L ≤ R ≤ 10^6
Example: L = 2 and R = 6  ---  The possible sums of pairs from this range are: 2+2=4,   4+4=8,  
                                                                               2+3=5,   4+5=9,
                                                                               2+4=6,   4+6=10,
                                                                               2+5=7,   5+5=10,
                                                                               2+6=8,   5+6=11,
                                                                               3+3=6,   6+6=12
                                                                               3+4=7,
                                                                               3+5=8,
                                                                               3+6=9,
 If you list the distinct sums, you get the set:  {4,5,6,7,8,9,10,11,12}
                                                -> The number of distinct sums is 9.
**caution--- Be aware of TLE. Avoid Run time error

Link of the question-> https://www.codechef.com/practice/course/1to2stars/LP1TO201/problems/MANYSUMS?tab=statement     
                                       
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int l,r;
	    cin>>l>>r;
	    cout<<(2*r - 2*l +1)<<endl;
	}

}