// Valid_Anagram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> sFreq(26, 0);
		vector<int> tFreq(26, 0);

		if (s.length() != t.length())
		{
			return false;
		}

		for (int i=0;i<s.length();i++)
		{
			sFreq[s[i]-'a']++;
			tFreq[t[i]-'a']++;
		}

		//两个vector可以通过==来比较存储内容是否相等
		if (sFreq==tFreq)
		{
			return true;
		}

		return false;
	}
};

class Solution2 {
public:
	bool isAnagram(string s, string t) {

		int count[26] = { 0 };

		if (s.length() != t.length())
		{
			return false;
		}

		for (int i = 0;i < s.length();i++)
		{
			count[s[i] - 'a']++;
			count[t[i] - 'a']--;
		}
		
		for (int i=0;i<s.length();i++)
		{
			if (count[i]!=0)
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
	string s = "anagram";
	string t = "nagaram";
	
	if (Solution().isAnagram(s,t))
	{
		cout << "the Two String is Valid Anagram!\n";
	}
	else
		cout << "the Two String is not  Valid Anagram!\n";

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
