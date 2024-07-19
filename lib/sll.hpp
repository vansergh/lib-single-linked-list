#ifndef SLL_HPP
#define SLL_HPP

#include <initializer_list>

////////////////////////////////////
// SLList declaration
//////////////////////////////////  

template <typename DataType>
class SLList {
private:

    ////////////////////////////////////
    // SLLNode declaration
    //////////////////////////////////  

    class SLLNode {
    public:
        DataType& GetData();
    private:
        friend SLList;

        SLLNode(const SLLNode&) = delete;
        SLLNode(SLLNode&&) = delete;
        SLLNode() = delete;

        SLLNode(DataType&& in_data, SLLNode* in_prev);
        SLLNode(const DataType& in_data, SLLNode* in_prev);

        DataType data;
        SLLNode* prev;
    };

    typedef SLLNode Node;
    typedef Node* NodePtr;
    typedef unsigned long long int size_t;

    size_t size_{ 0 };
    DataType empty_;
    NodePtr back_;

    NodePtr CopyNodes_(const SLList& other);
    NodePtr InitFromList_(const std::initializer_list<DataType>& init_list);

public:

    SLList();
    SLList(std::initializer_list<DataType>&& init_list);
    SLList(const SLList& other);
    SLList(SLList&& other);
    ~SLList();

    SLList& operator=(const SLList& other);
    SLList& operator=(SLList&& other);

    void Clear();
    void PushBack(DataType&& data);
    void PushBack(const DataType& data);
    void PopBack();
    DataType& Back();
    template <typename OperationFnc>
    void FromBack(OperationFnc& operation_fnc);
    bool IsEmpty() const;
    size_t Size() const;
    template <typename PrintFnc>
    void Print(const PrintFnc& print_fnc) const;
};

////////////////////////////////////
// SLLNode defenition
//////////////////////////////////  

template<typename DataType>
inline DataType& SLList<DataType>::SLLNode::GetData() {
    return data;
}

template<typename DataType>
inline SLList<DataType>::SLLNode::SLLNode(DataType&& in_data, SLList<DataType>::SLLNode* in_prev) :
    data{ std::move(in_data) },
    prev{ in_prev }
{
    // Parametrized move constructor
}

template<typename DataType>
inline SLList<DataType>::SLLNode::SLLNode(const DataType& in_data, SLList<DataType>::SLLNode* in_prev) :
    data{ DataType(in_data) },
    prev{ in_prev }
{
    // Parametrized copy constructor
}

////////////////////////////////////
// SLList defenition
//////////////////////////////////  

template<typename DataType>
inline typename SLList<DataType>::NodePtr SLList<DataType>::CopyNodes_(const SLList& other) {
    if (other.IsEmpty()) {
        return nullptr;
    }
    NodePtr index = other.back_->prev;
    back_ = new Node(other.back_->data, nullptr);
    while (index != nullptr) {
        if (index != nullptr) {
            back_->prev = new Node(index->data, nullptr);
        }
        index = index->prev;
    }
    return back_;
}

template<typename DataType>
inline typename SLList<DataType>::NodePtr SLList<DataType>::InitFromList_(const std::initializer_list<DataType>& init_list) {
    back_ = nullptr;
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        PushBack(DataType(*it));
    }
    return back_;
}

template<typename DataType>
inline SLList<DataType>::SLList() :
    size_{ 0 },
    empty_{ DataType() },
    back_{ nullptr }
{
    // Default constructor
}

template<typename DataType>
inline SLList<DataType>::SLList(std::initializer_list<DataType>&& init_list) :
    size_{ 0 },
    empty_{ DataType() },
    back_{ InitFromList_(init_list) }
{
    // std::initializer_list constructor
}

template<typename DataType>
inline SLList<DataType>::SLList(const SLList& other) :
    size_{ other.size_ },
    empty_{ DataType() },
    back_{ CopyNodes_(other) }
{
    // Copy constructor
}

template<typename DataType>
inline SLList<DataType>::SLList(SLList&& other) :
    size_{ other.size_ },
    empty_{ DataType() },
    back_{ other.back_ }
{
    other.back_ = nullptr;
    other.Clear();
}

template<typename DataType>
inline SLList<DataType>::~SLList() {
    Clear();
}

template<typename DataType>
inline SLList<DataType>& SLList<DataType>::operator=(const SLList& other) {
    if (this == &other) {
        Clear();
        size_ = other.size_;
        back_ = CopyNodes_(other);
    }
    return *this;
}

template<typename DataType>
inline SLList<DataType>& SLList<DataType>::operator=(SLList&& other) {
    if (this != &other) {
        Clear();
        back_ = other.back_;
        size_ = other.size_;
        other.back_ = nullptr;
        other.Clear();
    }
    return *this;
}

template<typename DataType>
inline void SLList<DataType>::Clear() {
    NodePtr current{ nullptr };
    while (back_ != nullptr) {
        current = back_;
        back_ = back_->prev;
        delete current;
    }
    size_ = 0;
}

template<typename DataType>
inline void SLList<DataType>::PushBack(DataType&& data) {
    NodePtr newbie = new Node(std::move(data), back_);
    back_ = newbie;
    ++size_;
}

template<typename DataType>
inline void SLList<DataType>::PushBack(const DataType& data) {
    NodePtr newbie = new Node(data, back_);
    back_ = newbie;
    ++size_;
}

template<typename DataType>
inline void SLList<DataType>::PopBack() {
    if (IsEmpty()) {
        return;
    }
    NodePtr back_node = back_->prev;
    delete back_;
    back_ = back_node;
    --size_;
}

template<typename DataType>
inline DataType& SLList<DataType>::Back() {
    return IsEmpty() ? empty_ : back_->data;
}

template<typename DataType>
template<typename OperationFnc>
inline void SLList<DataType>::FromBack(OperationFnc& operation_fnc) {
    NodePtr index{ back_ };
    NodePtr current{ nullptr };
    while (index != nullptr) {
        current = index;
        index = index->prev;
        operation_fnc(current);
    }
}

template<typename DataType>
inline bool SLList<DataType>::IsEmpty() const {
    return size_ == 0;
}

template<typename DataType>
typename SLList<DataType>::size_t SLList<DataType>::Size() const {
    return size_;
}

template<typename DataType>
template<typename PrintFnc>
inline void SLList<DataType>::Print(const PrintFnc& print_fnc) const {
    if (IsEmpty()) {
        print_fnc("List is empty");
        return;
    }
    NodePtr index = back_;
    while (index != nullptr) {
        print_fnc("[");
        print_fnc(index->data);
        print_fnc("]");
        if (index->prev != nullptr) {
            print_fnc("<-");
        }
        index = index->prev;
    }
}

#endif