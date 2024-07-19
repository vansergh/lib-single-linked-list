#include <iostream>
#include <stack>
#include "../lib/sll.hpp"

void TestSLListString() {
    using namespace std::literals;
    auto print_fnc{
        [](const auto& item) {
            std::cout << item;
        }
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
    bool from_back_first = true;
    auto from_back{
        [&from_back_first](const auto& node) {
            if (!from_back_first) {
                std::cout << ", ";
            }
            from_back_first = false;
            std::cout << node->GetData();
        }
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
    auto print_fnc{
        [](const auto& item) {
            std::cout << item;
        }
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
    bool from_back_first = true;
    auto from_back{
        [&from_back_first](const auto& node) {
            if (!from_back_first) {
                std::cout << ", ";
            }
            from_back_first = false;
            std::cout << node->GetData();
        }
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

void TestCopyMove() {
    using namespace std::literals;
    auto print_fnc{
        [](const auto& item) {
            std::cout << item;
        }
    };

    
    std::cout << "==============================\n";
    std::cout << "> Initialization\n";
    std::cout << "==============================\n";
    std::cout << "> SLList<std::string> list1 = SLList<std::string>({ \"hello\"s,\"world\"s }); // std::initializer_list&& <- move" << std::endl;
    SLList<std::string> list1 = SLList<std::string>({ "hello"s,"world"s });
    std::cout << "> SLList<std::string> list2 = {\"blue\"s,\"red\"s}; // std::initializer_list&& <- move" << std::endl;
    SLList<std::string> list2 = {"blue"s,"red"s};
    std::cout << "> SLList<std::string> list3({ \"cat\", \"dog\" }); // std::initializer_list&& <- move" << std::endl;
    SLList<std::string> list3({ "cat", "dog" });
    std::cout << "> SLList<std::string> list4; // <- default empty constructor" << std::endl;
    SLList<std::string> list4;
    std::cout << "> list4.PushBack(\"one\");" << std::endl;
    std::cout << "> list4.PushBack(\"two\");" << std::endl;
    std::cout << "> list4.PushBack(\"five\");" << std::endl;
    list4.PushBack("one");
    list4.PushBack("two");
    list4.PushBack("five");
    std::cout << "==============================\n";
    std::cout << "> Print list1: ";list1.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list3: ";list3.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list4: ";list4.Print(print_fnc);std::cout << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Copy\n";
    std::cout << "==============================\n";
    std::cout << "> Print list1: ";list1.Print(print_fnc);std::cout << std::endl;
    std::cout << "> {" << std::endl;
    std::cout << "> \tSLList<std::string> list_r1 = list1;" << std::endl;
    {
        SLList<std::string> list_r1 = list1;
        std::cout << "> \tPrint list_r1: ";list_r1.Print(print_fnc);std::cout << std::endl;
        std::cout << "> \tPrint list1: ";list1.Print(print_fnc);std::cout << std::endl;        
    }
    std::cout << "> }" << std::endl;
    std::cout << "> Print list1: ";list1.Print(print_fnc);std::cout << std::endl;
    std::cout << "> list_r1 deleted" << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> SLList<std::string> list_r2(list2);" << std::endl;
    SLList<std::string> list_r2(list2);
    std::cout << "> Print list_r2: ";list_r2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> list_r2.Clear();" << std::endl;
    list_r2.Clear();
    std::cout << "> Print list_r2: ";list_r2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;    
    std::cout << "==============================\n";
    std::cout << "> Move\n";
    std::cout << "==============================\n";
    std::cout << "> Print list3: ";list3.Print(print_fnc);std::cout << std::endl;    
    std::cout << "> SLList<std::string> list_r3;" << std::endl;
    SLList<std::string> list_r3;
    std::cout << "> list_r3 = std::move(list3);" << std::endl;
    list_r3 = std::move(list3);
    std::cout << "> Print list3: ";list3.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list_r3: ";list_r3.Print(print_fnc);std::cout << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Print list4: ";list4.Print(print_fnc);std::cout << std::endl;    
    std::cout << "> SLList<std::string> list_r4(std::move(list4));" << std::endl;
    SLList<std::string> list_r4(std::move(list4));
    std::cout << "> Print list4: ";list4.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list_r4: ";list_r4.Print(print_fnc);std::cout << std::endl;
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
    std::cout << "\n//////////////////////////////\n";
    std::cout << "// Copy & Move test         //\n";
    std::cout << "//////////////////////////////\n\n";
    TestCopyMove();    
    return 0;
}