#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twosum(std::vector<int> &nums, int target){
	int l=nums.size();
	std::unordered_map<int,int> m;
	for(int i=0;i<l;i++){
		auto it = m.find(target-nums[i]);
		if(it != m.end())
			return {(*it).second,i};
		m[nums[i]] = i;
	}
	return {-1};
}

int main(){
	std::vector<int> nums={2,7,11,15};
	int target=9;
	auto ans = twosum(nums,target);
	for(auto it:ans)
		std::cout<<it<<" ";
	std::cout<<"\n";

}
