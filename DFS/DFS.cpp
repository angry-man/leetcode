/*�� LeetCode �̵��У� �� n �����۵���Ʒ��ÿ����Ʒ���ж�Ӧ�ļ۸�Ȼ����Ҳ��һЩ�������ÿ����������Żݵļ۸���������һ����Ʒ��

����һ���������� price ��ʾ��Ʒ�۸����� price[i] �ǵ� i ����Ʒ�ļ۸�����һ���������� needs ��ʾ�����嵥������ needs[i] ����Ҫ����� i ����Ʒ��������

����һ������ special ��ʾ�������special[i] �ĳ���Ϊ n + 1 ������ special[i][j] ��ʾ�� i ����������ں��� j ����Ʒ���������� special[i][n] ��Ҳ���������е����һ��������Ϊ�� i ��������ļ۸�

���� ȷ�� ���㹺���嵥���軨�ѵ���ͼ۸�����Գ�����ô�������Żݻ���㲻�ܹ��򳬳������嵥ָ����������Ʒ����ʹ�����ή������۸��������������޴ι���

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/shopping-offers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

����������ȱ��� ��DFS �� 10.24
*/


#include<iostream>
#include<vector>
#include<map>

using namespace std;


int DFS(vector<int>& price, vector<vector<int>>& filter_special, vector<int>& cur_needs)
{
	int minPrice = 0;
	int n = cur_needs.size();
	//���ȼ�������ô����ʱ�� �ܼ۸���Ϊ��С�۸�
	for (int i = 0;i < n;i++)
	{
		minPrice += cur_needs[i] * price[i];
	}
	//����ÿһ�������
	for (auto fil_spe : filter_special)
	{
		vector<int> next_need;
		for (int i = 0;i < n;i++)
		{
			if (fil_spe[i] > cur_needs[i])
				break;
			next_need.emplace_back(cur_needs[i] - fil_spe[i]);//�������������е�����ʱ�����ȥ��Ϊ�´�����
		}
		if (next_need.size() == n)
		{
			//����������ȱ��� ���Ѽ���������������뺯�����б���
			minPrice = min(minPrice, DFS(price, filter_special, next_need) + fil_spe[n]);
		}
	}
	return minPrice;
}


//������������޳���special�� �����ܴ����Żݵ���� ֮���ڽ���DFS
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
	int n = price.size();
	vector<vector<int>> filter_special;
	for (auto& spe : special)
	{
		int total = 0;
		for (int i = 0;i < n;i++)
		{
			total += (spe[i] * price[i]);
		}
		if (total > spe[n])
			filter_special.emplace_back(spe);
	}
	return DFS(price, filter_special, needs);

}



int main()
{
	vector<int> price = { 2, 6, 7, 10, 2, 4 };
	vector<vector<int>> special = { {0,3,1,4,4,3,12} ,{3,3,3,3,4,5,25},{4,6,0,2,1,1,5},{1,3,0,4,4,2,6},{0,3,1,0,5,0,2},{0,3,1,3,4,4,24},{6,0,1,3,4,2,19},{5,1,4,5,3,4,22} };
	vector<int> need = { 0,4,5,0,0,6 };
	shoppingOffers(price, special, need);
	return 0;
}