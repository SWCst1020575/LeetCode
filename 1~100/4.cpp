#include <iostream>
#include <vector>
// time: pr31 space: pr97

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2){
	int sum = nums1.size()+nums2.size();
	int left=0,right=0;
	if(sum%2){
		int count = sum/2;
		for(int i=0;i<count;i++){
			if(left>=nums1.size()){
				right++;
				continue;
			}
			else if(right>=nums2.size()){
				left++;
				continue;
			}
			if(nums1[left]<nums2[right])
				left++;
			else
				right++;
		}
		if(left>=nums1.size())
			return nums2[right];
		else if(right>=nums2.size())
			return nums1[left];

		if(nums1[left]<nums2[right])
			return nums1[left];
		else
			return nums2[right];
	}
	else{
		int count = sum/2 - 1;
		for(int i=0;i<count;i++){
			if(left>=nums1.size()){
				right++;
				continue;
			}
			else if(right>=nums2.size()){
				left++;
				continue;
			}

			if(nums1[left]<nums2[right])
				left++;
			else
				right++;
		}
		double ans=0;
		if(left>=nums1.size()){
			ans += nums2[right];
			right++;
		}
		else if(right>=nums2.size()){
			ans += nums1[left];
			left++;
		}
		else{
			if(nums1[left]<nums2[right]){
				ans += nums1[left];
				left++;
			}
			else{		
				ans += nums2[right];
				right++;
			}
		}
		if(left>=nums1.size())
			ans += nums2[right];
		else if(right>=nums2.size())
			ans += nums1[left];
		else{
			if(nums1[left]<nums2[right])
				ans += nums1[left];
			else
				ans += nums2[right];
		}
		return ans/2.0;
	}
}
int main(){
		
//	std::cout<<findMedianSortedArrays();
	std::cout<<"\n";

}
