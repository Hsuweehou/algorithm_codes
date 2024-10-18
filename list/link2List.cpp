#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
/*
    合并有序链表
*/
struct myList{
    int val;
    myList* next;
    myList(int _val) :val(_val), next(nullptr){}
};

myList* merge(myList* l1, myList* l2){
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    myList head(0);
    myList* node = &head;
    while(l1 != nullptr && l2 != nullptr){
        if(l1->val < l2->val){
            node->next = l1;
            l1 = l1->next;
        }else{
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }
    if(l1 == nullptr)
        node->next = l2;
    if(l2 == nullptr)
        node->next = l1;
    
    return head.next;
};

void mergeList(){
    myList* node0 = new myList(1);
    myList* node1 = new myList(1);
    myList* node2 = new myList(2);
    myList* node3 = new myList(3);
    myList* node4 = new myList(1);
    myList* node5 = new myList(4);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;
    node4->next = node5;
    node5->next = nullptr;
    auto node = merge(node0,node4);
    std::cout << "begin!" << std::endl;
    while (node != nullptr){
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
    std::cout << "done!" << std::endl;
    delete node0;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
}

/*
    反转链表
*/
//构造一个列表
struct myList* init(){
    myList* head = new myList(1);
    myList* node1 = new myList(2);
    myList* node2 = new myList(3);
    myList* node3 = new myList(4);
    myList* node4 = new myList(5);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    return head;
}
//法一：原地旋转
struct myList* reverse(myList* head)
{
    struct myList* pre = new myList(-1);
    struct myList* temp = new myList(-1);
    pre = head;
    temp = head->next;
    pre->next = nullptr;
    struct myList* cur = new myList(-1);
    cur = temp;
    while(cur != nullptr){
        temp = cur;
        cur = cur->next;
        temp->next = pre;
        pre = temp;
    }
    return pre;   
}

//法二：头插法
struct myList* reverse_head(myList* pHead){
    if(pHead == nullptr || pHead->next == nullptr)
        return pHead;
    myList dummyNode = myList(0);
    myList* pre = &(dummyNode);
    pre->next = pHead;
    myList* cur = pHead->next;
    pHead->next = nullptr;
    //pre = cur;
    myList* temp = nullptr;
    while(cur != nullptr){
        temp = cur;
        cur = cur->next;
        temp->next = pre->next;
        pre->next = temp;
    }
    return dummyNode.next;
}

void reverseList(){

    myList* head = init();
    myList* keepHead = head;//记录头指针
    std::cout << "original list" << std::endl;
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    head = keepHead;//返回开头
    std::cout << "reverse list" << std::endl;
    //head = reverse(head);
    head = reverse_head(head);

    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;

    delete head;
    delete keepHead;

}


/*
exec: g++ -o cameratest camera_device.cpp -ludev
so:   g++ camera_device.cpp -fPIC -shared -o libgetCamId.so
*/

int main(void){
    //mergeList();
    reverseList();
    return 0;
}