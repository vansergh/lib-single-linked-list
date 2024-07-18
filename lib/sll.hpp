#ifndef SLL_HPP
#define SLL_HPP

////////////////////////////////////
// SLList declaration
//////////////////////////////////  

template <typename DataType>
class SLList {
private:

    ////////////////////////////////////
    // SLLNode declaration
    //////////////////////////////////  

    struct SLLNode {
    public:
        SLLNode(const SLLNode&) = delete;
        SLLNode(SLLNode&&) = delete;

        SLLNode();

        DataType data;
        SLLNode* prev;
    };    

    typedef SLLNode Node;
    typedef Node* NodePtr;
    typedef unsigned long long int size_t;

    NodePtr back_{ nullptr };
    size_t size_{ 0 };

public:

    SLList(const SLList&) = delete;
    SLList(SLList&&) = delete;
    
    SLList();
    ~SLList();

    void Clear();
    void PushBack(DataType&& data);
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
inline SLList<DataType>::SLLNode::SLLNode() :
    prev{ nullptr }    
{
    // Default constructor    
}

////////////////////////////////////
// SLList defenition
//////////////////////////////////  

template<typename DataType>
inline SLList<DataType>::SLList() :
    back_{ new Node() },
    size_{ 0 }
{
    back_->data = DataType();
}

template<typename DataType>
inline SLList<DataType>::~SLList() {
    Clear();
    delete back_;
}

template<typename DataType>
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

template<typename DataType>
inline void SLList<DataType>::PushBack(DataType&& data) {
    NodePtr newbie = new Node();
    newbie->data = data;
    NodePtr back_node = back_->prev;
    newbie->prev = back_node;
    back_->prev = newbie;
    ++size_;
}

template<typename DataType>
inline void SLList<DataType>::PopBack() {
    if (IsEmpty()) {
        return;
    }
    NodePtr back_node = back_->prev;
    back_->prev = back_node->prev;
    delete back_node;
    --size_;
}

template<typename DataType>
inline DataType& SLList<DataType>::Back() {
    return IsEmpty() ? back_->data : back_->prev->data;
}

template<typename DataType>
template<typename OperationFnc>
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
    NodePtr index = back_->prev;
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