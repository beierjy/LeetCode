#include <iostream>
#include <vector>

using namespace std;

//use merge sort method
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int len = nums1.size() + nums2.size();
	int medium = len / 2;
	int x = 0; int y = 0;
	vector<int> tmp(medium + 1, 0);
	for (int i = 0; i <= medium; i++){
		if (x < nums1.size() && y<nums2.size()){
			if (nums1[x]<nums2[y]){
				tmp[i] = nums1[x++];
			}
			else{
				tmp[i] = nums2[y++];
			}
		}
		else if (x<nums1.size()){
			tmp[i] = nums1[x++];
		}
		else{
			tmp[i] = nums2[y++];
		}
	}
	if (len % 2 == 0){
		return (((double)tmp[medium - 1]) +((double)tmp[medium]))/2;
	}
	else
		return (double)(tmp[medium]);
}
//Binary solution idea,please see the solution detail by the same name file 

int max(const int& a, const int& b){
	return a > b ? a : b;
}
int min(const int& a, const int& b){
	return a < b ? a : b;
}
double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if (m > n){
		swap(nums1, nums2);
		int a = m;
		m = n;
		n = a;
	}
	if (n == 0)
		return -1;
	int i = 0;
	int j = 0;
	int imin = 0;
	int imax = m;
	int half = (m + n + 1) / 2;
	int max_of_left = 0;
	int min_of_right = 0;
	while (imin <= imax){
		i = ((imin + imax) >> 1);//记录中位数分割的位置
		j = half - i;
		if (i < m && nums2[j - 1] > nums1[i])
			imin = i + 1;
		else if (i > 0 && nums1[i - 1] > nums2[j]){
			imax = i - 1;
		}
		else{
			if (i == 0)
				max_of_left = nums2[j - 1];
			else if (j == 0)
				max_of_left = nums1[i - 1];
			else
				max_of_left = max(nums1[i - 1], nums2[j - 1]);

			if ((m + n) % 2 == 1){
				return max_of_left;
			}
			if (i == m)
				min_of_right = nums2[j];
			else if (j == n)
				min_of_right = nums1[i];
			else
				min_of_right = min(nums1[i], nums2[j]);
			return (max_of_left + min_of_right) / 2.0;
		}
	}
}

void Test(){
	int a1[2] = { 1, 2 };
	int a2[3] = { 3 ,4,5};
	vector<int> nums1(a1, a1 + 2);
	vector<int> nums2(a2, a2 + 2);
	double res = findMedianSortedArrays_1(nums1, nums2);
	cout << res << endl;
}