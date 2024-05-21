#include <iostream>


int randomAccess(int* nums, int size);
void insert(int* nums, int size, int num, int index);
void remove(int* nums, int size, int index);
int find(int* nums, int size, int target);
int* extend(int* nums, int size, int enlarge);
void printArray(int* nums, int size);

int main() {
    /* 初始化数组 */
    int size = 5;
    int *arr = new int[size];
    std::cout << "数组 arr = ";
    printArray(arr, size);

    int *nums = new int[size]{1, 3, 2, 5, 4};
    std::cout << "数组 nums = ";
    printArray(nums, size);

    /* 随机访问 */
    int randomNum = randomAccess(nums, size);
    std::cout << "在 nums 中获取随机元素 " << randomNum << std::endl;

    /* 长度扩展 */
    int enlarge = 3;
    nums = extend(nums, size, enlarge);
    size += enlarge;
    std::cout << "将数组长度扩展至 8 ，得到 nums = ";
    printArray(nums, size);

    /* 插入元素 */
    insert(nums, size, 6, 3);
    std::cout << "在索引 3 处插入数字 6 ，得到 nums = ";
    printArray(nums, size);

    /* 删除元素 */
    remove(nums, size, 2);
    std::cout << "删除索引 2 处的元素，得到 nums = ";
    printArray(nums, size);

    /* 查找元素 */
    int index = find(nums, size, 3);
    std::cout << "在 nums 中查找元素 3 ，得到索引 = " << index << std::endl;

    // 释放内存
    delete[] arr;
    delete[] nums;

    return 0;
}

int randomAccess(int* nums, int size) {
    int randomIndex = rand() % size;
    int randomNumber = nums[randomIndex];
    return randomNumber;
}

void insert(int* nums, int size, int num, int index) {
    for (int i = size - 1; i > index ; i--) {
        nums[i-1] = nums[i];
    }
    nums[index] = num;
}
void remove(int* nums, int size, int index) {
    //删除index处的元素
    for (int i = index; i < size -1; i++) {
        nums[i] = nums[i+1];
    }
}
int find(int* nums, int size, int target) {
    for (int i = 0; i < size-1; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}
int* extend(int* nums, int size, int enlarge) {
    int* res = new int[size + enlarge];
    for(int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    //记得释放原数组的内存空间
    delete[] nums;
    return res;
}
void printArray(int* nums, int size) {
    for (int i = 0; i < size-1; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}