/*
3. Longest Substring Without Repeating Characters
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s){
	if (s.size() == 0)
		return 0;
	if (s.size() == 1)
		return 1;
	int max = 1;
	int start = 0;
	int end = 0;
	int now = 1;
	int gap = 1;
	while (now <= s.size()){
		gap = end - start + 1;
		if (gap > max && s[end]!=s[start])
			max = gap;
		for (int i = end; i >= start&&now<s.size(); i--){
			if (s[now] == s[i]){
				start = i + 1;
				break;
			}
		}
		end = now;
		now++;
	}
	return max;
}
//优化,利用hash表方法

>>>>>>> c383d5957de79149e502ad58fb124c1149e85c96
int lengthOfLongestSubstring_1(string s){
	vector<int> ivec(256, -1);
	int max_len = 0;
	int start = -1;
	for (int i = 0; i < s.size(); i++){
		if (ivec[s[i]]>start)
			start = ivec[s[i]];
		ivec[s[i]] = i;
		max_len = (max_len > i - start) ? max_len : i - start;
	}
	return max_len;
}
void test(){
	string s = "auua";
	int res = lengthOfLongestSubstring_1(s);
	cout << res << endl;
}
