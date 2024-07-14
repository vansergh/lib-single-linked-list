#ifndef SLL_HPP
#define SLL_HPP

#include <iostream>

////////////////////////////////////
// SLLNode declaration
//////////////////////////////////  

template <class DataType>
struct SLLNode {
public:
    SLLNode(const SLLNode<DataType>&) = delete;
    SLLNode(SLLNode<DataType>&&) = delete;

    SLLNode();
    ~SLLNode();

    DataType data;
    SLLNode* prev{ nullptr };
};

////////////////////////////////////
// SLList declaration
//////////////////////////////////  

template <class DataType>
class SLList {
public:
    typedef SLLNode<DataType> Node;
    typedef SLLNode<DataType>* NodePtr;

    SLList(const SLList&) = delete;
    SLList(SLList&&) = delete;
    
    SLList();
    ~SLList();

    void Clear();
    void PushBack(const DataType& data);
    void PopBack();
    SLLNode<DataType>* Back();
    template <class OperationFnc>
    void FromBack(OperationFnc& operation_fnc);
    bool IsEmpty();
    unsigned long long int Size();
    void Print();
private:
    NodePtr back_{ nullptr };
    unsigned long long int size_{ 0 };
};

////////////////////////////////////
// SLLNode defenition
//////////////////////////////////  

template<class DataType>
inline SLLNode<DataType>::SLLNode() :
    prev{ nullptr }
{
    // Default constructor
}

template<class DataType>
inline SLLNode<DataType>::~SLLNode() {
    data.~DataType();
}

////////////////////////////////////
// SLList defenition
//////////////////////////////////  

template<class DataType>
inline SLList<DataType>::SLList() :
    back_{ new Node() },
    size_{ 0 }
{
    back_->data = DataType();
}

template<class DataType>
inline SLList<DataType>::~SLList() {
    Clear();
    delete back_;
}

template<class DataType>
inline void SLList<DataType>::Clear() {
    if (IsEmpty()) {
        return;
    }
    NodePtr index = back_->prev;
    NodePtr current;
    while (index != nullptr) {
        current = index;
        index = index->prev;
        delete current;
    }
    back_->prev = nullptr;
    size_ = 0;
}

template<class DataType>
inline void SLList<DataType>::PushBack(const DataType& data) {
    NodePtr newbie = new Node();
    newbie->data = DataType(data);
    NodePtr back_node = back_->prev;
    newbie->prev = back_node;
    back_->prev = newbie;
    ++size_;
}

template<class DataType>
inline void SLList<DataType>::PopBack() {
    if (IsEmpty()) {
        return;
    }
    NodePtr back_node = back_->prev;
    back_->prev = back_node->prev;
    delete back_node;
    --size_;
}

template<class DataType>
inline SLLNode<DataType>* SLList<DataType>::Back() {
    return IsEmpty() ? back_ : back_->prev;
}

template<class DataType>
template<class OperationFnc>
inline void SLList<DataType>::FromBack(OperationFnc& operation_fnc) {
    if (IsEmpty()) {
        return;
    }
    NodePtr index = back_->prev;
    NodePtr current;
    while (index != nullptr) {
        current = index;
        index = index->prev;
        operation_fnc(current);
    }    
}

template<class DataType>
inline bool SLList<DataType>::IsEmpty() {
    return size_ == 0;
}

template<class DataType>
inline unsigned long long int SLList<DataType>::Size() {
    return size_;
}

template<class DataType>
inline void SLList<DataType>::Print() {
    if (IsEmpty()) {
        std::cout << "List is empty";
        return;
    }
    NodePtr index = back_->prev;
    while (index != nullptr) {
        std::cout << "[" << index->data << "]";
        if (index->prev != nullptr) {
            std::cout << "<-";
        }
        index = index->prev;
    }    
}

#endif
