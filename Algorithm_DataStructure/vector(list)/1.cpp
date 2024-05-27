#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int>& res);

int main() {

    //std::vector<int> nums1;
    std::vector<int> nums = { 1, 3, 2, 5, 4};

    int num = nums[1];
    nums[1] = 0;

    nums.clear();

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);

    //在索引位添加或者删除元素
    nums.insert(nums.begin() + 3, 6);
    nums.erase(nums.begin() + 3);

    int count = 0;
    for(int num : nums) { // 遍历列表
        count += num;
    }

    //列表拼接
    std::vector<int> nums1 = { 6, 7, 8, 9, 10 };
    nums.insert(nums.end(), nums1.begin(), nums1.end());

    //列表排序(从小到大)
    sort(nums.begin(), nums.end());
    printVector(nums);
    return 0;
}

void printVector(std::vector<int>& res) {
    for(int num : res) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

