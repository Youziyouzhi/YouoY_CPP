#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

void insert(ListNode* n, ListNode* P);
void remove(ListNode* n);
ListNode* access(ListNode* head, int index);
int find(ListNode* head, int target);
void printLinkedList(ListNode* head);
void freeMemoryLinkedList(ListNode* head);

int main() {
    /* 初始化链表 */
    // 初始化各个节点
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    // 构建节点之间的引用
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    std::cout << "初始化的链表为" << std::endl;
    printLinkedList(n0);

    /* 插入节点 */
    insert(n0, new ListNode(0));
    std::cout << "插入节点后的链表为" << std::endl;
    printLinkedList(n0);

    /* 删除节点 */
    remove(n0);
    std::cout << "删除节点后的链表为" << std::endl;
    printLinkedList(n0);

    /* 访问节点 */
    ListNode *node = access(n0, 3);
    std::cout << "链表中索引 3 处的节点的值 = " << node->val << std::endl;

    /* 查找节点 */
    int index = find(n0, 2);
    std::cout << "链表中值为 2 的节点的索引 = " << index << std::endl;

    // 释放内存
    freeMemoryLinkedList(n0);

    return 0;
}

void insert(ListNode* n, ListNode* p) {
    //在节点n后插入节点p
    ListNode* tmp = n->next;
    n->next = p;
    p->next = tmp;
}
void remove(ListNode* n) {
    //删除n节点后的首个节点
    if(n->next == nullptr) {
        return;
    }
    ListNode* tmp = n->next;
    n->next = tmp->next;
    delete tmp;
}
ListNode* access(ListNode* head, int index) {
    //访问索引为index的节点
    for(int i = 0; i < index; i++) {
        if(head == nullptr) {
            return nullptr;
        }
        head = head->next;
    }
    return head;
}
int find(ListNode* head, int target) {
    //查找值为target的节点，输出该节点的索引
    int index = 0;
    while(head != nullptr) {
        if(head->val == target) {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}
void printLinkedList(ListNode* head){
    while(head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
void freeMemoryLinkedList(ListNode* head) {
    while(head != nullptr && head->next != nullptr) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
    delete head;
}