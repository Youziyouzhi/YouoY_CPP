#include <iostream>
#include <stdexcept>
#include <vector>

class MyList {
private:
    int* arr;
    int arrCapacity = 10;//初始容量
    int arrSize = 0;
    int expendRatio = 2; //列表扩容倍数
public:
    MyList() {
        arr = new int[arrCapacity];
    }
    ~MyList() {
        delete[] arr;
    }
    int size() {
        return arrSize;
    }
    int capacity() {
        return arrCapacity;
    }
    int get(int index) {
        //访问元素
        if (index < 0 || index >= size()) {
            throw std::out_of_range("索引越界！");
        }
        return arr[index];
    }
    void set(int index, int num) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("索引越界！");
        }
        arr[index] = num;
    }
    void expendCapacity() {
        //数组扩容
        int newCapacity = expendRatio * arrCapacity;
        int* tmp = arr;
        arr = new int[newCapacity];
        for (int i = 0; i < size(); i++) {
            arr[i] = tmp[i];
        }
        delete[] tmp;
        arrCapacity = newCapacity;
    }
    void add(int num) {
        if (size() == capacity()) {
            expendCapacity();
        }
        arr[size()] = num;
        arrSize++;
    }
    void insert(int index, int num) {
        if (index < 0 || index > size()) {
            throw std::out_of_range("索引越界");
        }
        if (size() == capacity()) {
            expendCapacity();
        }
        for(int i = size()-1; i >= index; i--) {
            arr[i+1] = arr[i]; 
        }
        arr[index] = num;
        arrSize++;
    }
    int remove(int index) {
        if (index < 0 || index > size()) {
            throw std::out_of_range("索引越届");
        }
        int num = arr[index];
        for (int i = index; i < size()-1; i++) {
            arr[i] = arr[i+1];
        }
        arrSize--;
        return num;
    }
    std::vector<int> toVector() {
        std::vector<int> vec(size());
        for(int i = 0; i < size(); i++){
            vec[i] = arr[i];
        }
        return vec;
    }
};

void printVector(std::vector<int>& res);

int main() {
    /* 初始化列表 */
    MyList *nums = new MyList();
    /* 在尾部添加元素 */
    nums->add(1);
    nums->add(3);
    nums->add(2);
    nums->add(5);
    nums->add(4);
    std::cout << "列表 nums = ";
    std::vector<int> vec = nums->toVector();
    printVector(vec);
    std::cout << "容量 = " << nums->capacity() << " ，长度 = " << nums->size() << std::endl;

    /* 在中间插入元素 */
    nums->insert(3, 6);
    std::cout << "在索引 3 处插入数字 6 ，得到 nums = ";
    vec = nums->toVector();
    printVector(vec);

    /* 删除元素 */
    nums->remove(3);
    std::cout << "删除索引 3 处的元素，得到 nums = ";
    vec = nums->toVector();
    printVector(vec);

    /* 访问元素 */
    int num = nums->get(1);
    std::cout << "访问索引 1 处的元素，得到 num = " << num << std::endl;

    /* 更新元素 */
    nums->set(1, 0);
    std::cout << "将索引 1 处的元素更新为 0 ，得到 nums = ";
    vec = nums->toVector();
    printVector(vec);

    /* 测试扩容机制 */
    for (int i = 0; i < 10; i++) {
        // 在 i = 5 时，列表长度将超出列表容量，此时触发扩容机制
        nums->add(i);
    }
    std::cout << "扩容后的列表 nums = ";
    vec = nums->toVector();
    printVector(vec);
    std::cout << "容量 = " << nums->capacity() << " ，长度 = " << nums->size() << std::endl;

    // 释放内存
    delete nums;

    return 0;
}
void printVector(std::vector<int>& res) {
    for (int num : res) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}