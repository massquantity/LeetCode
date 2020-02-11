#include <iostream>
#include "Vector.h"

template <typename T>
class Stack : public Vector<T> {
public:
    void push(const T & e) { this->insert(this->size(), e); }
    T pop() { this->remove(this->size() - 1); }
    T & top() { return (*this)[this->size() - 1]; }
};


void convert(Stack<char> & S, __int64 n, int base) {
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0) {
        S.push(digit[n % base]);
        n /= base;
    }
}

int main() {

    Stack<char> S;
    int n = 388888;
    int base = 8;
    convert(S, n, base);
    while (!S.empty()) {
        printf("%c", S.pop());
    }
}