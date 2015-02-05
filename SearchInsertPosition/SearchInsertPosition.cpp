/********************************************************************************** 
*
*问题：给出一个有序的数组A[]，个数为n，一个值target。找出target在数组的位置，
*		如果数组A没有target请按照顺序插入数组A中，返回当前位置。
*方法一：遍历数组，如果A[i]大于等于target，则返回i。
*方法二：利用二分法遍历数组。
*
*
**********************************************************************************/

//方法一
//9MS
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		for(int i=0; i<n; i++)
		{
			if(A[i] >= target)
			{
				return i;
			}
		}
		return n;
	}
};


//方法二
//15MS
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int left = 0;
		int right = n - 1;
		int mid;
		while(left <= right)
		{
			mid = (left + right) / 2;
			if(A[mid] > target)
			{
				right = mid - 1;
			}
			else if(A[mid] < target)
			{
				left = mid + 1;
			}
			else if(A[mid] == target)
			{
				return mid;
			}
		}
		if(A[mid] > target)
		{
			return mid;
		}
		else
		{
			return mid + 1;
		}
	}
};