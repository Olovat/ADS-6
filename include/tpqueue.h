// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
   private:
static const int MAX_SIZE = 100;
T data[MAX_SIZE];
int size;

   public:
TPQueue() : size(0) {}
void push(const T& value) {
    int pos = 0;
    while (pos < size && data[pos].prior >= value.prior)
        pos++;
    for (int i = size; i > pos; i--)
        data[i] = data[i-1];
    data[pos] = value;
    size++;
}
T pop() {
    T result = data[0];     
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i+1];
    }
    size--;
    return result;
}
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
