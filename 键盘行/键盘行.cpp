/*给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keyboard-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

殷健 2021.10.31
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