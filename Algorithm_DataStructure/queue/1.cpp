#include <iostream> 
#include <queue>
#include <vector>
#include <exception>
#include "../utils/common.hpp"


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int num):val(num), next(nullptr){}
// };

class LinkedListQueue {

private:
    ListNode *front, *rear;
    int queSize;
public:
    LinkedListQueue(){
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }
    ~LinkedListQueue(){

    }
    int size() {
        return queSize;
    }
    bool isEmpty() {
        return size() == 0;
    }
    void push(int num){
        ListNode *node = new ListNode(num);
        if(front == nullptr) {
            front = node;
            rear = node;
        }
        else {
            rear->next = node;
            rear = node;    
        }
        ++queSize;
    }
    int pop() {
        int res = front->val;
        ListNode *tmp = front;
        front = front->next;
        delete tmp;
        --queSize;
        return res;
    }
    int peek() {
        if(size() == 0) {
            throw std::out_of_range("队列为空");
        }
        return front->val;
    }

    std::vector<int> toVector() {
        ListNode *node = front;
        std::vector<int> res(size());
        for(int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }

};

void test1();
void test2();

int main() {
    // test1();
    test2();
    return 0;
}

void test1() {
    std::queue<int> queue;
    queue.push(1);
    queue.push(3);
    queue.push(2);
    queue.push(5);
    queue.push(4);
    
    queue.pop();

    std::cout << queue.front() << " " << queue.size() <<std::endl; 
}
void test2() {
        /* 初始化队列 */
    LinkedListQueue *queue = new LinkedListQueue();

    /* 元素入队 */
    queue->push(1);
    queue->push(3);
    queue->push(2);
    queue->push(5);
    queue->push(4);
    cout << "队列 queue = ";
    printVector(queue->toVector());

    /* 访问队首元素 */
    int peek = queue->peek();
    cout << "队首元素 peek = " << peek << endl;

    /* 元素出队 */
    peek = queue->pop();
    cout << "出队元素 pop = " << peek << "，出队后 queue = ";
    printVector(queue->toVector());

    /* 获取队列的长度 */
    int size = queue->size();
    cout << "队列长度 size = " << size << endl;

    /* 判断队列是否为空 */
    bool empty = queue->isEmpty();
    cout << "队列是否为空 = " << empty << endl;

    // 释放内存
    delete queue;
}
