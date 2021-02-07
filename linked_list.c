#include "list.h"
#include <stdlib.h>
#define newnode Node* node = malloc(sizeof(Node));
// В узле списка хранится само значение value и указатель на следующий узел.
// Эту структуру пользователи списка не должны видеть, так как она относится к внутренней реализации.
typedef struct Node_ {
  int value; // само значение, которое хранит узел
  struct Node_ *next; // указатель на следующий узел
} Node;

// Пользовательская структура, которая скрывает механизм хранения данных.
typedef struct List_ {
  Node *head; // указатель на голову списка
  Node *tail; // указатель на хвост списка
  int size;
  // если нужно, то добавьте дополнительные поля
} List;


List* NewList() {
    List* lst = malloc(sizeof(List));
    lst->head = lst->tail = NULL;
    lst->size = 0;
    return lst;
}

void DestroyList(List* this) {
    //TODO: напиши меня!

}

void Append(List *this, int value) {
    //TODO: напиши меня!
    newnode
    node->value = value;
    node->next = NULL;

    if(this->tail == NULL){
        this->head = node;
    }else{
        this->tail->next = node;
    }
    this->tail = node;
    this->size++;
}
void Prepend(List *this, int value) {
    //TODO: напиши меня!
    newnode
    node->value = value;
    node->next = this->head;
    this->head = node;
    this->size++;

}
void AppendAll(List *this, const List *that) {
    //TODO: напиши меня!
    this->tail->next = that->head;
    this->size += that->size;
    this->tail = that->tail;
}
void InsertAt(List *this, int index, int value) {
    //TODO: напиши меня!

}

void RemoveAt(List *this, int index) {
    //TODO: напиши меня!

}
void RemoveAll(List *this) {
    //TODO: напиши меня!

}

int Pop(List *this) {
    //TODO: напиши меня!

}
int Dequeue(List *this) {
    //TODO: напиши меня!

}

int Length(const List *this) {
    //TODO: напиши меня!

}
int GetAt(const List *this, int index) {
    //TODO: напиши меня!

}
