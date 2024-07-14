#include <iostream>
#include "../lib/sll.hpp"

void TestSLList() {
    SLList<int> list;
    std::cout << "==============================\n";
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushBack: 7, 9, 12" << std::endl;
    list.PushBack(7);
    list.PushBack(9);
    list.PushBack(12);
    std::cout << "> Print: ";
    list.Print();
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print();
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print();
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print();
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack (list is empty)" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print();
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    bool from_back_first = true;
    auto from_back = [&from_back_first](const SLLNode<int>* node) {
        if (!from_back_first) {
            std::cout << ", ";
        }
        from_back_first = false;
        std::cout << node->data;
        };    
    std::cout << "> FromBack: ";
    list.FromBack(from_back);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Clear" << std::endl;
    list.Clear();
    std::cout << "> Print: ";
    list.Print();
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back()->data << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
}

int main() {
    TestSLList();
    return 0;
}