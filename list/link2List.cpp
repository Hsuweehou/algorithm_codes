#include <iostream>

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

/*
exec: g++ -o cameratest camera_device.cpp -ludev
so:   g++ camera_device.cpp -fPIC -shared -o libgetCamId.so
*/

int main(void){
    std::cout << "begin!" << std::endl;
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
    while (node != nullptr){
        std::cout << node->val << std::endl;
        node = node->next;
    }
    std::cout << "done!" << std::endl;
    return 0;
}