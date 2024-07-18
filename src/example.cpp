#include <iostream>
#include "../lib/sll.hpp"

void TestSLListString() {
    using namespace std::literals;
    auto print_fnc = [](const auto& item) {
        std::cout << item;
        };    
    SLList<std::string> list;
    std::cout << "==============================\n";
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushBack: cow, elephant, lion" << std::endl;
    list.PushBack("cow"s);
    list.PushBack("elephant"s);
    list.PushBack("lion"s);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack (list is empty)" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushBack: dolphin, shark, cow, elephant, lion" << std::endl;
    list.PushBack("dolphin"s);
    list.PushBack("shark"s);
    list.PushBack("cow"s);
    list.PushBack("elephant"s);
    list.PushBack("lion"s);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";    
    bool from_back_first = true;
    auto from_back = [&from_back_first](const auto& node) {
        if (!from_back_first) {
            std::cout << ", ";
        }
        from_back_first = false;
        std::cout << node->data;
        };    
    std::cout << "> FromBack: ";
    list.FromBack(from_back);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Clear" << std::endl;
    list.Clear();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
}

void TestSLListInt() {
    auto print_fnc = [](const auto& item) {
        std::cout << item;
        };    
    SLList<int> list;
    std::cout << "==============================\n";
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushBack: 7, 9, 12" << std::endl;
    list.PushBack(7);
    list.PushBack(9);
    list.PushBack(12);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack (list is empty)" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    bool from_back_first = true;
    auto from_back = [&from_back_first](const auto& node) {
        if (!from_back_first) {
            std::cout << ", ";
        }
        from_back_first = false;
        std::cout << node->data;
        };    
    std::cout << "> FromBack: ";
    list.FromBack(from_back);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Clear" << std::endl;
    list.Clear();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
}

int main() {
    std::cout << "//////////////////////////////\n";
    std::cout << "// Scalar test              //\n";
    std::cout << "//////////////////////////////\n\n";
    TestSLListInt();
    std::cout << "\n//////////////////////////////\n";
    std::cout << "// Class (std::string) test //\n";
    std::cout << "//////////////////////////////\n\n";    
    TestSLListString();
    return 0;
}