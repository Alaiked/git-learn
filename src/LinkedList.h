#ifndef LINKEDLIST__H
#define LINKEDLIST__H

#include <stdio.h>
#include "Node.h"

/*
    @author:    fung
    @brief:     ����Ļ�����������ʵ��, �Լ��߼���������ʵ��
    @todo:      �������Ĳ������Լ������ļ�
*/

//-------------------------  ����������   -------------------------
DoublyLinkedList* create_list();
// ͷ�巨����Ԫ��
void push_front(DoublyLinkedList* list, int data);

// β�巨����Ԫ��
void push_back(DoublyLinkedList* list, int data)

// ɾ��indexλ�õĽڵ�
void deleteNode(Node** head, int index);

// ���ҽڵ� (��ֵ����), ���ؽڵ�λ��, ���û�ҵ�, ����Ϊ��
Node* find(Node* head, int data);

// ��������
void printList(Node* head);

// ��������
void destoryList(DoublyLinkedList* list);

//-------------------------  ����������   -------------------------


#endif  // LINKEDLIST__H

