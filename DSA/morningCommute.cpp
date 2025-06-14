/*The Chef commutes to work every day using the city's underground metro. The schedule for the trains has recently been changed
and he wants to know how long it will take to travel from the station nearest to his house and the station nearest to his restaurant.
The Chef doesn't want to change the route he took before, so he simply has to find out how long it will take to reach his restaurant
 along his usual route. This route is given by a sequence of stations s0, s1, ..., sn where s0 is the station where the Chef enters
the metro and sn is the station where the Chef exits the metro.
Trains are scheduled to run between every two consecutive stations si-1 and si. Such a schedule is specified by three integers xi, li,
 and fi. This means that the first train on this line starts operating at time xi. The time it takes this train to travel from si-1 
 and si is exactly li units. Finally, a train departs from station si-1 every fi minutes following the previous train.
 That is, a train departs at time xi, xi+fi, xi+2fi, and so on.
The Chef is very experienced at navigating the metro so the time it takes him to transfer between trains at a given station is
 essentially zero. Thus, if the Chef arrives at a station, say si, the moment that the train from si to si+1 is scheduled to depart,
  he skillfully hops on this next train. However, if the Chef arrives when no train to si+1 is scheduled to depart, he must wait 
  until the scheduled departure time.
Help the Chef figure out how long it will take him to travel from station s0 to station sn. You may assume that the Chef is already 
at station s0 at time 0.

>> Input
The first line consists of a single integer denoting the number of test cases (at most 50). Each test case begins with a line 
containing a single integer n between 1 and 1000 indicating the number of lines the Chef must traverse (so there are n+1 stations
 s0, s1, ..., sn). The next n lines describe the train schedules between stations, one per line. The i'th such line gives the 
 values xi, li, and fi for the train that travels between stations si-1 and si.
The xi values will be between 0 and 1000 and the li and fi values will be between 1 and 1000.

>> Output
For each test case you are to output a single integer denoting the minimum time t for which the Chef can reach station sn
 using the given route. Remember, the Chef starts at s0 at time 0.
*/
//************************************************************************************************************************************

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while (t--)
	{
	  int n;
	  cin>>n;
	  ll tym=0;
	   for (int i = 0; i < n; i++)
	   {
        int x,l,f;
        cin >> x>>l>>f;
        if (tym<x)
        {
            tym=x+l;
        }
        else if (tym==x)
        {
            tym+=l;
        }
        else 
        {
            if (tym>x && tym<=(x+f))
            {
                tym = x+l+f;
            }
            else if (tym>x && tym>(x+f)) 
            {
               int d=tym-x;
               d=d/f;
               if(x+d*f==tym)
               {
                   tym+=l;
               }
               else
               {
                  tym=x+((d+1)*f)+l; 
               }
            }
        }
    }
    cout << tym<<"\n";
  }
}
