#ifndef SSL_HPP
#define SSL_HPP

////////////////////////////////////
// SSLNode declaration
//////////////////////////////////  

template <class DataType>
struct SSLNode {
public:
    
    SSLNode();
    SSLNode(const SSLNode<DataType>&) = delete;
    SSLNode(const DataType& in_data, SSLNode<DataType>* in_prev);
    ~SSLNode();

    SSLNode<DataType>* Push(const DataType& in_data);
    SSLNode<DataType>* Pop();
    DataType Top();
    void Destroy();

    DataType data;
    SSLNode* prev{ nullptr };
};

////////////////////////////////////
// SSList declaration
//////////////////////////////////  

template <class DataType>
class SSList {
public:
    SSList();
    SSList(const SSList&) = delete;
    SSList(SSList&&) = delete;
    ~SSList();
    void Push(const DataType& data);
    void Pop();
    DataType Top();
    bool IsEmpty();
    unsigned long long int Size();
private:
    SSLNode<DataType>* root_{ nullptr };
    unsigned long long int size_{ 0 };
};

////////////////////////////////////
// SSLNode defenition
//////////////////////////////////  

template<class DataType>
inline SSLNode<DataType>::SSLNode() :
    data{ DataType() },
    prev{ nullptr }
{
    // Default constructor
}

template<class DataType>
inline SSLNode<DataType>::SSLNode(const DataType& in_data, SSLNode<DataType>* in_prev) :
    data{ DataType(in_data) },
    prev{ in_prev }
{
    // Parametrized constructor
}

template<class DataType>
inline SSLNode<DataType>::~SSLNode() {
    data.~DataType();
}

template<class DataType>
inline SSLNode<DataType>* SSLNode<DataType>::Push(const DataType& in_data) {
    return new SSLNode<DataType>(in_data, this);
}

template<class DataType>
inline SSLNode<DataType>* SSLNode<DataType>::Pop() {
    SSLNode<DataType>* res = prev;
    delete this;
    return res;
}

template<class DataType>
inline DataType SSLNode<DataType>::Top() {
    return data;
}

template<class DataType>
inline void SSLNode<DataType>::Destroy() {
    if (prev) {
        prev->Destroy();
    }
    delete this;
}

////////////////////////////////////
// SSList defenition
//////////////////////////////////  

template<class DataType>
inline SSList<DataType>::SSList() :
    root_{ new SSLNode<DataType>() },
    size_{ 0 }
{
    // Default constructor
}

template<class DataType>
inline SSList<DataType>::~SSList() {
    if (root_) {
        root_->Destroy();
    }
    else {
        delete root_;
    }
}

template<class DataType>
inline void SSList<DataType>::Push(const DataType& data) {
    root_ = root_->Push(data);
    ++size_;
}

template<class DataType>
inline void SSList<DataType>::Pop() {
    root_ = root_->Pop();
}

template<class DataType>
inline DataType SSList<DataType>::Top() {
    return root_->Top();
}

template<class DataType>
inline bool SSList<DataType>::IsEmpty() {
    return size_ == 0;
}

template<class DataType>
inline unsigned long long int SSList<DataType>::Size(){
    return size_;
}

#endif // SSL_HPP
