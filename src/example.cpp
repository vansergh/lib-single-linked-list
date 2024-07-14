#include <iostream>
#include "../lib/ssl.hpp"

void Print(SingleLinkedList<int>*& stack) {
    std::cout << "==============================\n";
    std::cout << stack->data << std::endl;      
}

int main() {
    SingleLinkedList<int>* stack = new SingleLinkedList<int>(7, nullptr);
    stack = stack->Push(9);
    Print(stack);
    stack = stack->Push(19);
    Print(stack);
    stack = stack->Push(59);
    Print(stack);
    stack = stack->Push(12);
    Print(stack);
    stack = stack->Pop();
    Print(stack);
    stack = stack->Push(17);
    Print(stack);
    stack->Destroy();
    return 0;
}