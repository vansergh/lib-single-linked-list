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

    class SLLNode {
    public:
        DataType& GetData();
    private:
        friend SLList;
        SLLNode(const SLLNode&) = delete;
        SLLNode(SLLNode&&) = delete;
        SLLNode() = delete;

        SLLNode(DataType&& in_data, SLLNode* in_prev);

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
    DataType& Back() const;
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
    // Parametrized constructor
}

////////////////////////////////////
// SLList defenition
//////////////////////////////////  

template<typename DataType>
inline SLList<DataType>::SLList() :
    back_{ nullptr },
    size_{ 0 }
{
    // Default constructor
}
 
template<typename DataType>
inline SLList<DataType>::~SLList() {
    Clear();
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
inline DataType& SLList<DataType>::Back() const {
    return back_->data;
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