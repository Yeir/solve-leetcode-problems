/********************************************************************************** 
*
*问题：给出一个数组A[]，个数为n。每个数都会出现两次，除了一个特别的数出现一次，找出这个数。
*方法一：先将数组排序，从0到n-1相邻两个判断是否相等，每次循环i+2，如果不等，则A[i]为single number。
*方法二：从1到n，A[i] ^= A[i-1]。最后输出A[n-1]。利用按位异或来作判断，两个相同的数异或等于0，所以异或整个数组，最后就是出现一次的数。
*
*
**********************************************************************************/

//19MS
//方法一
class Solution {
public:
	int singleNumber(int A[], int n) {
		if(n == 0) return 0;
		for(int i=1; i<n; i++)
		{
			A[i] ^= A[i-1];
		}
		return A[n-1];
	}
};

//36MS
//方法二
class Solution {
public:
	int singleNumber(int A[], int n) {
		if(n == 0) return 0;
		else if(n == 1) return A[0];
		sort(A, A+n);
		int i;
		for(i=0; i<n-1; i+=2)
		{
			if(A[i] != A[i+1])
			{
				break;
			}
		}
		if(i == 0) return A[0];
		return A[i];
	}
};