/********************************************************************************** 
*
*问题：给出需要走的步数n，每次只能走1或者2步，问有多少种走法。
*方法一：列出前5个步数，就发现有规律，F[n] = F[n-1] + F[n-2];。
*
*
**********************************************************************************/

//方法一
//2MS
class Solution {
public:
	int climbStairs(int n) {
		int F[1000] = {0, 1, 2};
		for(int i=3; i<=n; i++)
		{
			F[i] = F[i-1] + F[i-2];
		}
		return F[n];
	}
};
