#include "list.h"
#include <stdlib.h>
#define newnode Node* node = malloc(sizeof(Node)); node->value = value;
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
    RemoveAll(this);
    free(this);
}

void Append(List *this, int value) {
    //TODO: напиши меня!
    newnode
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
    newnode
    Node* Prev = NULL;
    Node* Next = this->head;
    int i = 0;
    
    while (i != index) {
        Prev = Next;
        Next = Prev->next;
        i++;
    }
    
    if (Prev) {
        Prev->next = node;
    } else {
        this->head = node;
    }

    node->next = Next;
    this->size++;
}

void RemoveAt(List *this, int index) {
    //TODO: напиши меня!
    if (this->size == NULL) {
        printf("Нет элементов для удаления");
        exit(0);
    }

    Node* Prev = NULL;
    Node* Removed = this->head;
    int i = 0;

    while (i != index) {
        Prev = Removed;
        Removed = Removed->next;
        i++;
    }
    Prev->next = Removed->next;
    free(Removed);
    this->size--
}
void RemoveAll(List *this) {
    //TODO: напиши меня!
    Node* temp1 = this->head;
    Node* temp2;

     while (temp1) {
       temp2 = temp1->next;
       free(temp1);
       temp1 = temp2;
    }

  this->size = 0;
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
