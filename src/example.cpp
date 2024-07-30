#include <iostream>
#include <string>
#include <stack>
#include "../lib/sll.hpp"

using namespace linked_lists;

template<typename DataType>
std::ostream& operator<<(std::ostream& out, const SLList<DataType>& list) {

    if (list.empty()) {
        out << "List is empty";
        return out;
    }
    bool is_first = true;
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (!is_first) {
            out << "<-";
        }
        is_first = false;
        out << '[' << *it << ']';
    }
    return out;
}

void TestSLListString() {
    using namespace std::literals;
    SLList<std::string> list;
    std::cout << "==============================\n";
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> push_back: cow, elephant, lion" << std::endl;
    list.push_back("cow"s);
    list.push_back("elephant"s);
    list.push_back("lion"s);
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back (list is empty)" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> push_back: dolphin, shark, cow, elephant, lion" << std::endl;
    list.push_back("dolphin"s);
    list.push_back("shark"s);
    list.push_back("cow"s);
    list.push_back("elephant"s);
    list.push_back("lion"s);
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> push_back: cow, elephant, lion" << std::endl;
    list.push_back("cow"s);
    list.push_back("elephant"s);
    list.push_back("lion"s);
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Clear" << std::endl;
    list.clear();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : *list.begin()) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
}

void TestSLListInt() {
    SLList<int> list;
    std::cout << "==============================\n";
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> push_back: 7, 9, 12" << std::endl;
    list.push_back(7);
    list.push_back(9);
    list.push_back(12);
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> pop_back (list is empty)" << std::endl;
    list.pop_back();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> push_back: 7, 9, 12" << std::endl;
    list.push_back(7);
    list.push_back(9);
    list.push_back(12);
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Clear" << std::endl;
    list.clear();
    std::cout << "> Print: " << list;
    std::cout << std::endl;
    std::cout << "> Back: " << (list.empty() ? "" : std::to_string(*list.begin())) << std::endl;
    std::cout << "> Size: " << list.size() << std::endl;
    std::cout << "> Empty: " << (list.empty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
}

void TestCopyMove() {
    using namespace std::literals;


    std::cout << "==============================\n";
    std::cout << "> Initialization\n";
    std::cout << "==============================\n";
    std::cout << "> SLList<std::string> list1 = SLList<std::string>({ \"hello\"s,\"world\"s }); // std::initializer_list&& <- move" << std::endl;
    SLList<std::string> list1 = SLList<std::string>({ "hello"s,"world"s });
    std::cout << "> SLList<std::string> list2 = {\"blue\"s,\"red\"s}; // std::initializer_list&& <- move" << std::endl;
    SLList<std::string> list2 = { "blue"s,"red"s };
    std::cout << "> SLList<std::string> list3({ \"cat\", \"dog\" }); // std::initializer_list&& <- move" << std::endl;
    SLList<std::string> list3({ "cat", "dog" });
    std::cout << "> SLList<std::string> list4; // <- default empty constructor" << std::endl;
    SLList<std::string> list4;
    std::cout << "> list4.push_back(\"one\");" << std::endl;
    std::cout << "> list4.push_back(\"two\");" << std::endl;
    std::cout << "> list4.push_back(\"five\");" << std::endl;
    list4.push_back("one");
    list4.push_back("two");
    list4.push_back("five");
    std::cout << "==============================\n";
    std::cout << "> Print list1: " << list1 << std::endl;
    std::cout << "> Print list2: " << list2 << std::endl;
    std::cout << "> Print list3: " << list3 << std::endl;
    std::cout << "> Print list4: " << list4 << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Copy\n";
    std::cout << "==============================\n";
    std::cout << "> Print list1: " << list1 << std::endl;
    std::cout << "> {" << std::endl;
    std::cout << "> \tSLList<std::string> list_r1 = list1;" << std::endl;
    {
        SLList<std::string> list_r1 = list1;
        std::cout << "> \tPrint list_r1: " << list_r1 << std::endl;
        std::cout << "> \tPrint list1: " << list1 << std::endl;
    }
    std::cout << "> }" << std::endl;
    std::cout << "> Print list1: " << list1 << std::endl;
    std::cout << "> list_r1 deleted" << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Print list2: " << list2 << std::endl;
    std::cout << "> SLList<std::string> list_r2(list2);" << std::endl;
    SLList<std::string> list_r2(list2);
    std::cout << "> Print list_r2: "<< list_r2 << std::endl;
    std::cout << "> Print list2: "<< list2 << std::endl;
    std::cout << "> list_r2.clear();" << std::endl;
    list_r2.clear();
    std::cout << "> Print list_r2: "<< list_r2 << std::endl;
    std::cout << "> Print list2: "<< list2 << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Move\n";
    std::cout << "==============================\n";
    std::cout << "> Print list3: "<< list3 << std::endl;
    std::cout << "> SLList<std::string> list_r3;" << std::endl;
    SLList<std::string> list_r3;
    std::cout << "> list_r3 = std::move(list3);" << std::endl;
    list_r3 = std::move(list3);
    std::cout << "> Print list3: "<< list3 << std::endl;
    std::cout << "> Print list_r3: "<< list_r3 << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Print list4: "<< list4 << std::endl;
    std::cout << "> SLList<std::string> list_r4(std::move(list4));" << std::endl;
    SLList<std::string> list_r4(std::move(list4));
    std::cout << "> Print list4: "<< list4 << std::endl;
    std::cout << "> Print list_r4: "<< list_r4 << std::endl;
    std::cout << "==============================\n";
}

int main() {
/*     std::cout << "//////////////////////////////\n";
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
    TestCopyMove(); */
    return 0;
}