#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maps;
        vector<int> answer;
        int vec1, vec2 = 0;
        maps[nums[0]] = 0;
        int com = 0;
        for (int num = 0; num < nums.size(); num++) {
            com = target-nums[num];
           if(maps.count(com) && maps[com] !=num){
                return {maps[com],num};
           }
           maps[nums[num]] = num;
        }
        return {-1,-1};
    }
};

int main(){
    vector<int> input = {-11,7,3,2,1,7,-10,11,21,3};
    int target = 11;
    Solution Solutions;
    vector<int> res = Solutions.twoSum(input,target);
    std::cout << res[0]<<" "<<res[1] << std::endl;
}

