/*����һ���ַ������� words ��ֻ���ؿ���ʹ���� ��ʽ���� ͬһ�е���ĸ��ӡ�����ĵ��ʡ���������ͼ��ʾ��

��ʽ���� �У�

��һ�����ַ� "qwertyuiop" ��ɡ�
�ڶ������ַ� "asdfghjkl" ��ɡ�
���������ַ� "zxcvbnm" ��ɡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/keyboard-row
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

�� 2021.10.31
*/

#include<iostream>
#include<vector>
#include <string>
#include<map>
#include<cctype>
 using namespace std;

 vector<string> findWords(vector<string>& words)
 {
	 vector<string> result;
	 map<char, int> m;
	 vector<string> word_seed =
	 { "qwertyuiop","asdfghjkl","zxcvbnm" };
	 for (int i = 0;i < 3;i++)
		 for (int j = 0;j < word_seed[i].size();j++)
		 {
			 m.insert(pair<char, int>(word_seed[i][j], i));
			 m.insert(pair<char, int>(word_seed[i][j] - 32, i));
		 }
	 for (int i = 0;i < words.size();i++)
	 {
		 int j;
		 for (j = 1;j < words[i].size();j++)
		 {
			 if (m[words[i][j]] != m[words[i][j - 1]])
				 break;
		 }
		 if (j == words[i].size())
			 result.emplace_back(words[i]);
	 }
	 return result;
 }

 int main()
 {
	 vector<string> word = { "Hello","Alaska","Dad","Peace" };
	 vector<string> w;
	 tolower(word[0][0]);
	 w = findWords(word);
 }