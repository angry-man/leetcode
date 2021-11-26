/*
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-add-and-search-words-data-structure
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

殷健 2021 10 19
*/


#include <iostream>
#include <vector>
#include<string>
#define MAXNODE 500
using namespace std;

class WordDictionary {
public:
	WordDictionary() 
	{
		nodenum = 1;
		vector <int> w(MAXNODE);
		for (int i = 0;i < 26;i++)
			WD.push_back(w);
	}

	void addWord(string word) {
		int wlen = word.size();
		int p = 0;
		for (int i = 0;i < wlen;i++)
		{
			int temp = word[i] - 'a';
			if (WD[temp][p] == 0)
			{
				WD[temp][p] = nodenum;
				nodenum++;
			}
			p = WD[temp][p];
		}
		EndNode[p] = 1;
	}

	bool search_index(string word,int index) {
		int wlen = word.size();
		int p = index;
		for (int i = 0;i < wlen;i++)
		{
			if (word[i] == '.')
			{
				/*if (i == wlen - 1)
				{
					return true;
				}*/
				string temp_w = "";
				int k = i;
				while (k < wlen - 1)
				{
					k++;
					temp_w += word[k];
				}
				for (int j = 0;j < 26;j++)
				{
					if (WD[j][p] != 0)
					{
						 int next_p= WD[j][p];						
						if (search_index(temp_w, next_p))
							return true;
					}
				}
				return false;
			}
			else
			{
				int temp = word[i] - 'a';
				if (WD[temp][p] == 0)
				{
					return false;
				}
				else
				{
					p = WD[temp][p];
				}
			}	
		}
		return EndNode[p] == 1;
	}
	bool search(string word) {
		return search_index(word, 0);

	}
private:
	vector<vector<int>> WD;
	int nodenum;
	int EndNode[MAXNODE] = { 0 };
};

int main()
{
	WordDictionary worddict;
	worddict.addWord(string("at"));
	//worddict.addWord(string("and"));
	//worddict.addWord(string("an"));
	//worddict.addWord(string("add"));
	worddict.addWord(string("bat"));
	cout << worddict.search(string(".at")) << endl;//1
	cout << worddict.search(string("b.")) << endl;//0
	
	return 0;
}