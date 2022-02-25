/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<int>indegrees(n,1);
        indegrees[0] = 0;
        queue<int> room;
        for(auto i : rooms.front())
            room.push(i);
        while(!room.empty())
        {
            auto temp = room.front();
            room.pop();
            if(indegrees[temp] == 0)
                continue;
            indegrees[temp] = 0;
            for(auto edge : rooms[temp])
                if(edge != temp && indegrees[edge] != 0)
                    room.push(edge);
        }
        for(int i = 0;i < n;++i)
            if(indegrees[i] == 1)
                return false;
        return true;
    }
};
// @lc code=end

