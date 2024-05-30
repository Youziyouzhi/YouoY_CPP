#include <iostream>
#include <deque>
#include <vector>
#include <exception>
#include "../utils/common.hpp"

struct DoublyListNode {
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(int num):val(num), next(nullptr), prev(nullptr){}
};

class LinkedListDeque {

private:
    DoublyListNode *front, *rear;
    int queSize;
public:
    LinkedListDeque() : front(nullptr), rear(nullptr){}
    ~LinkedListDeque() {
        DoublyListNode *pre, *cur = front;
        while (cur != nullptr){
            pre = cur;
            cur = cur->next;
            delete pre;
        }
        
    }
    int size() {
        return queSize;
    }
    bool isEmpty() {
        return size() == 0;
    }
    void push(int num, bool isFront) {
        DoublyListNode *node = new DoublyListNode(num);
        if(isEmpty()) {
            front = rear = node;
        }
        else if(isFront) {
            front->prev = node;
            node->next = front;
            front = node;
        }
        else{
            rear->next =node;
            node->prev = rear;
            rear = node;
        }
        queSize++;
    }
    void pushFirst(int num) {
        push(num, true);
    }
    void pushLast(int num) {
        push(num, false);
    }
    int pop(bool isFront) {
        if(isEmpty()) {
            throw std::out_of_range("双向队列为空");
        }
        int val;
        if (isFront) {
            //对首出列
            val = front->val;
            DoublyListNode *tmp = front->next;
            if (tmp != nullptr) {
                tmp->prev = nullptr;
                front->next = nullptr; 
            }
            delete front;
            front = tmp;
        }
        else {
            val = rear->val;
            DoublyListNode *tmp = rear->prev;
            if (tmp != nullptr) {
                rear->prev = nullptr;
                tmp->next = nullptr;
            }
            delete rear;
            rear = tmp;
        }
        queSize--;
        return val;
    }
    int popFirst() {
        return pop(true);
    }
    int popLast() {
        return pop(false);
    }
    int peekFirst() {
        if(isEmpty()) {
            throw std::out_of_range("双向队列为空");
        }
        return front->val;
    }
    int peekLast() {
        if(isEmpty()) {
            throw std::out_of_range("双向队列为空");
        }
        return rear->val;
    }
    std::vector<int> toVector() {
        DoublyListNode *node = front;
        std::vector<int> vec(size());
        for(int i = 0; i < vec.size(); i++) {
            vec[i] = node->val;
            node = node->next;
        }
        return vec;
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
    std::deque<int> deque;
    deque.push_back(2);
    deque.push_back(1);
    deque.push_back(0);
    deque.push_front(5);
    deque.push_front(4);
    deque.push_front(3);


    std::cout << deque.front() << " " << deque.back() << std::endl;
    deque.pop_front();
    deque.pop_back();
    std::cout << deque.front() << " " << deque.back() << std::endl;

}

void test2() {
     /* 初始化双向队列 */
    LinkedListDeque *deque = new LinkedListDeque();
    deque->pushLast(3);
    deque->pushLast(2);
    deque->pushLast(5);
    cout << "双向队列 deque = ";
    printVector(deque->toVector());

    /* 访问元素 */
    int peekFirst = deque->peekFirst();
    cout << "队首元素 peekFirst = " << peekFirst << endl;
    int peekLast = deque->peekLast();
    cout << "队尾元素 peekLast = " << peekLast << endl;

    /* 元素入队 */
    deque->pushLast(4);
    cout << "元素 4 队尾入队后 deque =";
    printVector(deque->toVector());
    deque->pushFirst(1);
    cout << "元素 1 队首入队后 deque = ";
    printVector(deque->toVector());

    /* 元素出队 */
    int popLast = deque->popLast();
    cout << "队尾出队元素 = " << popLast << "，队尾出队后 deque = ";
    printVector(deque->toVector());
    int popFirst = deque->popFirst();
    cout << "队首出队元素 = " << popFirst << "，队首出队后 deque = ";
    printVector(deque->toVector());

    /* 获取双向队列的长度 */
    int size = deque->size();
    cout << "双向队列长度 size = " << size << endl;

    /* 判断双向队列是否为空 */
    bool isEmpty = deque->isEmpty();
    cout << "双向队列是否为空 = " << boolalpha << isEmpty << endl;

    // 释放内存
    delete deque;
}
