#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ret = 0;
        for (int i = g.size() - 1, j = s.size() - 1;i >= 0 && j >= 0;) {
            if (s[j] >= g[i]) {
                ret++;
                i--;
                j--;
            }
            else {
                i--;
            }
        }

        return ret;
    }
};

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        int count = 0;

        for (int i = 1;i <= nums.size();i++) {
            cur = nums[i] - nums[i - 1];
            if ((pre >= 0 && cur < 0) || (pre <= 0 && cur > 0)) {
                //等于的情况会造成歧义，所以pre只在坡向变更时才变更
                count++;
                pre = cur;
            }
        }

        return count;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max = INT_MIN;
        int sum = 0;
        for (auto it : nums) {

            sum += it;
            Max = max(sum, Max);
            if (sum < 0) {
                sum = 0;
            }
            //先更新记录值再初始化
        }

        return Max;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 0;i < prices.size() - 1;i++) {
            int sub = prices[i + 1] - prices[i];
            if (sub>0) {
                ret += sub;
            }
        }

        return ret;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {

        if (nums.size() == 1) {
            return true;
        }

        int MaxRight = 0;
        for (int i = 0;i < nums.size();i++) {
            MaxRight = max(MaxRight, i + nums[i]);
            if (MaxRight >= nums.size() - 1) {
                return true;
            }
        }

        return false;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size() - 1;
        }

        int CurRight = 0;
        int MaxRight = 0;
        int step = 0;
        for (int i = 0;i < nums.size();i++) {
            MaxRight = max(nums[i] + i, MaxRight);
            if (i == CurRight) {//需要走下一步了
                if (CurRight >= nums.size() - 1) {
                    return step;
                }
                else {
                    step++;
                    CurRight = MaxRight;//走了下一步
                    if (CurRight >= nums.size() - 1) {
                        return step;
                    }
                }
            }
        }

        return step;
    }
};

class Solution {
private:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), compare);

        int ret = 0;
        for (int i = 1;i < points.size();i++) {
            if (points[i][0] < points[i - 1][1]) {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
            else {
                ret++;
            }
        }

        return ret;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int maxpos[26];
        for (int i = 0;i < s.size();i++) {
            maxpos[s[i] - 'a'] = i;
        }
        //记录字母出现的最远下标，取的是最后更新的值
        //也可以使用rfind来找到最右边的位置，但是时间复杂度太高

        int left = 0;
        int right = 0;
        vector<int> ret;

        for (int i = 0;i < s.size();i++) {
            right = max(right, maxpos[s[i] - 'a']);
            if (i == right) {
                if (i == s.size() - 1) {
                    ret.push_back(right - left + 1);
                    return ret;
                }
                else {
                    ret.push_back(right - left + 1);
                    left = right + 1;
                }
            }
        }

        return ret;
    }
};


class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int index=s.size();

        for (int i = s.size() - 1;i >= 1;i--) {
            if (s[i - 1] > s[i]) {
                index = i;
                s[i - 1] -= 1;
            }
        }

        for (int i = index;i < s.size();i++) {
            s[i] = '9';
        }

        return stoi(s);
    }
};