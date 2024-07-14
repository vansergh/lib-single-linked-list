#ifndef SSL_HPP
#define SSL_HPP

////////////////////////////////////
// Single-Linked List declaration
//////////////////////////////////  

template <class DataType>
struct SingleLinkedList {

    SingleLinkedList() = delete;
    SingleLinkedList(const SingleLinkedList<DataType>&) = delete;
    SingleLinkedList(const DataType& in_data, SingleLinkedList<DataType>* in_prev);
    ~SingleLinkedList();

    SingleLinkedList<DataType>* Push(const DataType& in_data);
    SingleLinkedList<DataType>* Pop();
    void Destroy();

    DataType data;
    SingleLinkedList* prev{ nullptr };
};

////////////////////////////////////
// Single-Linked List defenition
//////////////////////////////////  

template<class DataType>
inline SingleLinkedList<DataType>::SingleLinkedList(const DataType& in_data, SingleLinkedList<DataType>* in_prev) :
    data{ DataType(in_data) },
    prev{ in_prev }
{
    // Default constructor
}

template<class DataType>
inline SingleLinkedList<DataType>::~SingleLinkedList() {
    data.~DataType();
}

template<class DataType>
inline SingleLinkedList<DataType>* SingleLinkedList<DataType>::Push(const DataType& in_data) {
    return new SingleLinkedList<DataType>(in_data, this);
}

template<class DataType>
inline SingleLinkedList<DataType>* SingleLinkedList<DataType>::Pop() {
    SingleLinkedList<DataType>* res = prev;
    delete this;
    return res;
}

template<class DataType>
inline void SingleLinkedList<DataType>::Destroy() {
    if (prev) {
        prev->Destroy();
    }
    delete this;
}

#endif // SSL_HPP