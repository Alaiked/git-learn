#include <stdio.h>  
#include "LinkedList.h"  
#include "Node.h"

int main() {
    DoublyLinkedList* list = create_list();

    push_front(list, 1);
    push_front(list, 2);
    push_back(list, 3);
    push_back(list, 4);

    printf("��ӽڵ�������");
    printList(list);

    printf("ɾ���ڵ�2\n");
    deleteNode(list, 2);
    printf("ɾ���ڵ�������");
    printList(list);

    Node* found = find(list, 3);
    if (found) {
        printf("�ҵ�����Ϊ%d�Ľڵ�\n", found->data);
    }
    else {
        printf("û���ҵ���Ӧ�Ľڵ�\n");
    }

    destoryList(list);
    return 0;
}

