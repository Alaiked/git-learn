#include <stdio.h>  
#include <stdlib.h>  
#include "LinkedList.h"
#include "Node.h"

// ��������  
DoublyLinkedList* create_list()
{
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// ��ͷ����ӽڵ�  
void push_front(DoublyLinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    else {
        list->tail = new_node; // �������Ϊ�գ��½ڵ�Ҳ��β�ڵ�  
    }

    list->head = new_node;
}

// ��β����ӽڵ�  
void push_back(DoublyLinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    else {
        list->head = new_node; // �������Ϊ�գ��½ڵ�Ҳ��ͷ�ڵ�  
    }

    list->tail = new_node;
}

// ɾ���ڵ�  
void deleteNode(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            else {
                list->head = current->next; // ɾ��ͷ�ڵ�  
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            else {
                list->tail = current->prev; // ɾ��β�ڵ�  
            }

            free(current);
            return;
        }
        current = current->next;
    }
}

// ���ҽڵ�  
Node* find(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// ��������  
void printList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ��������  
void destoryList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
