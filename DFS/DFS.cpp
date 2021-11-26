/*在 LeetCode 商店中， 有 n 件在售的物品。每件物品都有对应的价格。然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。

给你一个整数数组 price 表示物品价格，其中 price[i] 是第 i 件物品的价格。另有一个整数数组 needs 表示购物清单，其中 needs[i] 是需要购买第 i 件物品的数量。

还有一个数组 special 表示大礼包，special[i] 的长度为 n + 1 ，其中 special[i][j] 表示第 i 个大礼包中内含第 j 件物品的数量，且 special[i][n] （也就是数组中的最后一个整数）为第 i 个大礼包的价格。

返回 确切 满足购物清单所需花费的最低价格，你可以充分利用大礼包的优惠活动。你不能购买超出购物清单指定数量的物品，即使那样会降低整体价格。任意大礼包可无限次购买。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shopping-offers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

采用深度优先遍历 即DFS 殷健 10.24
*/


#include<iostream>
#include<vector>
#include<map>

using namespace std;


int DFS(vector<int>& price, vector<vector<int>>& filter_special, vector<int>& cur_needs)
{
	int minPrice = 0;
	int n = cur_needs.size();
	//首先计算出不用大礼包时的 总价格作为最小价格
	for (int i = 0;i < n;i++)
	{
		minPrice += cur_needs[i] * price[i];
	}
	//遍历每一个大礼包
	for (auto fil_spe : filter_special)
	{
		vector<int> next_need;
		for (int i = 0;i < n;i++)
		{
			if (fil_spe[i] > cur_needs[i])
				break;
			next_need.emplace_back(cur_needs[i] - fil_spe[i]);//当需求大于礼包中的数的时候则减去成为下次需求
		}
		if (next_need.size() == n)
		{
			//进行深度优先遍历 并把减掉礼包后的需求放入函数进行遍历
			minPrice = min(minPrice, DFS(price, filter_special, next_need) + fil_spe[n]);
		}
	}
	return minPrice;
}


//这个函数首先剔除掉special中 并不能带来优惠的组合 之后在进行DFS
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