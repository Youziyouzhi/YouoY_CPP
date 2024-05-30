#include <iostream>
#include <stack>
#include <vector>
#include <exception>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int num):val(num),next(nullptr){}
};

void freeMemoryLinkedList(ListNode *cur) {
    // 释放内存
    ListNode *pre;
    while (cur != nullptr) {
        pre = cur;
        cur = cur->next;
        delete pre;
    }
}

class LinkedListStack {
private:
    ListNode *stackTop;
    int stSize;
public:
    LinkedListStack() {
        stackTop = nullptr;
        stSize = 0;
    }
    ~LinkedListStack() {
        freeMemoryLinkedList(stackTop);
    }
    int size() {
        return stSize;
    }
    bool isEmpty(){
        return size()==0;
    }
    void push(int num) {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        ++stSize;
    }
    int pop() {
        int tmp = top();
        ListNode *p = stackTop;
        stackTop = p->next;
        delete p;
        --stSize;
        return tmp;
    }
    int top() {
        if(isEmpty()) {
            throw std::out_of_range("栈为空");
        }
        return stackTop->val;
    }
    std::vector<int> toVector() {
        ListNode *node = stackTop;
        std::vector<int> vec (size());
        for(size_t i = vec.size()-1; i >= 0; i--) {
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

void printVector(std::vector<int>  vec) {
    for(auto num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void test1() {
    std::stack<int> stack;
    stack.push(1);
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(4);

    std::cout << stack.top() << " " << stack.size() << " " << stack.empty() << std::endl;

}

void test2() {
    /* 初始化栈 */
    LinkedListStack *stack = new LinkedListStack();

    /* 元素入栈 */
    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    std::cout << "栈 stack = ";
    
    /* 访问栈顶元素 */
    int top = stack->top();
    std::cout << "栈顶元素 top = " << top << std::endl;

    /* 元素出栈 */
    top = stack->pop();
    std::cout << "出栈元素 pop = " << top << "，出栈后 stack = ";

    /* 获取栈的长度 */
    int size = stack->size();
    std::cout << "栈的长度 size = " << size << std::endl;

    /* 判断是否为空 */
    bool empty = stack->isEmpty();
    std::cout << "栈是否为空 = " << empty << std::endl;

    // 释放内存
    delete stack;
    
}