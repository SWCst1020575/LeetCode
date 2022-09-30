#include <iostream>
// time: pr93 space: pr96
int lengthOfLongestSubstring(std::string s) {
	int l = s.size();
	int start=0,end=0;
	int max=0;
	bool map[128] = {0};
	for(start=0;start<l;start++){
		while(map[(int)s[end]]==0){
			map[(int)s[end]]=1;
			end++;
			if(end-start>max)
				max= end-start;
			if(end>=l)
				break;
		}
		map[(int)s[start]]=0;
		if(end>=l)
			break;
	}
	return max;
}

int main(){
	std::string s = "abcabcbb";
	std::cout<<lengthOfLongestSubstring(s);
	std::cout<<"\n";

}
