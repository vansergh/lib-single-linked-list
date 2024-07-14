#include <iostream>
#include "../lib/ssl.hpp"

void Print(int value) {
    std::cout << "> " << value << std::endl;
}

int main() {
    std::cout << "==============================\n";
    SSList<int> stack;
    if (stack.IsEmpty()) {
        std::cout << "> Empty" << std::endl;
    }
    stack.Push(9);
    Print(stack.Top());
    stack.Push(19);
    Print(stack.Top());
    stack.Push(39);
    Print(stack.Top());
    stack.Push(19);
    Print(stack.Top());
    if (!stack.IsEmpty()) {
        std::cout << "> Not Empty" << std::endl;
    }
    std::cout << "> Size: " << stack.Size() << std::endl;
    Print(stack.Top());
    stack.Pop();
    Print(stack.Top());
    stack.Push(79);
    Print(stack.Top());
    std::cout << "> Size: " << stack.Size() << std::endl;
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop(); // <= stack is empty, trying to Pop
    std::cout << "> Size: " << stack.Size() << std::endl;
    return 0;
}