#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
/*
    奇偶链表：把奇数节点和偶数节点分别排在一起
*/
typedef struct myList{
    int val;
    myList* next;
    myList(int _val) :val(_val), next(nullptr){}
} ListNode;


/*
    法一：传统的正常做法
*/
ListNode* oddEvenList(ListNode* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode* first = head;//奇链表头结点
    ListNode* second = head->next;//偶链表头结点
    ListNode* cur = second;//记录偶链表头结点
    while (second != nullptr && second->next != nullptr)
    {
        first->next = second->next;
        second->next = first->next->next;
        first = first->next;
        second = second->next;
    }
    first->next = cur;
    return head;
}

/*
    法二：传统的正常做法
*/

int main(){
    ListNode* node0 = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;
    auto node = oddEvenList(node0);
        std::cout << "begin!" << std::endl;
    while (node != nullptr){
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
    std::cout << "done!" << std::endl;
    delete node;
    delete node0;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    return 0;
}