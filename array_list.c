#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Пользовательская структура, которая скрывает механизм хранения данных.
typedef struct List_ {
  int *array;  // динамический массив, в котором будут раниться все данные
  int length;  // размер списка: последний занятый индекс в array
  int capacity;  // ёмкость списка: реальный размер массива array
  // если нужно, то добавьте дополнительные поля
} List;

// Создание пустого листа
List *NewList() {
  List *lst = (List *)malloc(sizeof(List));
  lst->array = (int *)calloc(2, sizeof(int));
  lst->length = 0;
  lst->capacity = 2;
  return lst;
}

void DestroyList(List *this) {
  free(this->array);
  free(this);
}

// Вставка элемента в конец списка
void Append(List *this, int value) {
  if (this->length == this->capacity) {
    this->array = (int *)realloc(this->array, this->capacity * 2 * sizeof(int));
    this->capacity *= 2;
  }

  *(this->array + this->length) = value;
  this->length++;
}

// Вставка элемента в начало списка
void Prepend(List *this, int value) {
  if (this->length == this->capacity) {
    this->array = (int *)realloc(this->array, this->capacity * 2 * sizeof(int));
    this->capacity *= 2;
  }

  this->length++;
  for (int i = this->length - 1; i > 0; i--) {
    *(this->array + i) = *(this->array + i - 1);
  }
  *(this->array) = value;
}

// Вставить все элементы одного списка в конец другого
void AppendAll(List *this, const List *that) {
  if (this->length + that->length == 0) {
    return;
  }
  if (this->capacity - this->length < that->length) {
    while (this->capacity - this->length < that->length) {
      this->capacity *= 2;
    }
    this->array = (int *)realloc(this->array, sizeof(int) * this->capacity);
  }

  int *cur_elem = this->array + this->length;
  for (int i = 0; i < that->length; i++, cur_elem++) {
    *cur_elem = GetAt(that, i);
  }
  this->length += that->length;
}

// Вставка элемента после индекса
void InsertAt(List *this, int index, int value) {
  if (index > this->length - 1 || index < 0) {
    printf("Ошибка:Индекс недоступен");
    exit(-1);
  }

  if (this->length == this->capacity) {
    this->array = (int *)realloc(this->array, this->capacity * 2 * sizeof(int));
    this->capacity *= 2;
  }

  this->length++;
  for (int i = this->length - 1; i > index; i--) {
    *(this->array + i) = *(this->array + i - 1);
  }
  *(this->array + index) = value;
}

// Удаление элемента по индексу
void RemoveAt(List *this, int index) {
  if (index > this->length - 1 || index < 0) {
    printf("Ошибка:Индекс недоступен");
    exit(-1);
  }

  this->length--;
  for (int i = index; i < this->length; i++) {
    *(this->array + i) = *(this->array + i + 1);
  }

  if (this->length < this->capacity / 4) {
    this->capacity /= 2;
    this->array = (int *)realloc(this->array, this->capacity * sizeof(int));
  }
}

// Удаление всех элементов из списка
void RemoveAll(List *this) {
  free(this->array);
  this->array = (int *)calloc(2, sizeof(int));
  this->length = 0;
  this->capacity = 2;
}

// Удаление элемента с конца списка (функция возвращает удаленный элемент)
int Pop(List *this) {
  if (this->length == 0) {
    printf("Ошибка:Пустой лист");
    exit(-1);
  }

  int value = GetAt(this, this->length - 1);
  this->length--;

  if (this->length < this->capacity / 4) {
    this->capacity /= 2;
    this->array = (int *)realloc(this->array, this->capacity * sizeof(int));
  }

  return value;
}

//  Удаление элемента с начала списка (функция возвращает удаленный элемент)
int Dequeue(List *this) {
  if (this->length == 0) {
    printf("Ошибка:Пустой лист");
    exit(-1);
  }

  int value = GetAt(this, 0);
  this->length--;
  for (int i = 0; i < this->length; i++) {
    *(this->array + i) = *(this->array + i + 1);
  }

  if (this->length < this->capacity / 4) {
    this->capacity /= 2;
    this->array = (int *)realloc(this->array, this->capacity * sizeof(int));
  }

  return value;
}

// Вычисление длины списка
int Length(const List *this) { 
	return this->length;
}

// Взятие элемента из списка по индексу
int GetAt(const List *this, int index) {
  if (this->length == 0) {
    printf("Ошибка:Пустой лист");
    exit(-1);
  }
  if (index > this->length - 1 || index < 0) {
    printf("Ошибка:Элемент # %d не существует", index);
    exit(-1);
  }
  return *(this->array + index);
}
