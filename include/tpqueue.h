// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
 private:
struct Item {
  T data;
  Item* next;
  Item(const T& value) : data(value), next(nullptr) {}
};
Item* head;

 public:
TPQueue() : head(nullptr) {}
void push(const T& value) {
Item* newItem = new Item(value);
if (head == nullptr || value.prior > head->data.prior) {
    newItem->next = head;
    head = newItem;
    return;
}
Item* current = head;
while (current->next != nullptr && current->next->data.prior >= value.prior) {
    current = current->next;
}
newItem->next = current->next;
current->next = newItem;
}
T pop() {
if (head == nullptr)
    throw std::string("Queue is empty");
Item* temp = head;
T result = temp->data;
head = head->next;
delete temp;
return result;
}
~TPQueue() {
while (head != nullptr) {
  Item* temp = head;
  head = head->next;
  delete temp;
}}
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
