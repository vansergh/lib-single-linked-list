#ifndef SLL_HPP
#define SLL_HPP

#include <initializer_list>
#include <ostream>


namespace linked_lists {

    ////////////////////////////////////
    // SLList declaration
    //////////////////////////////////  

    template <typename DataType>
    class SLList {
    private:

        ////////////////////////////////////
        // Node declaration
        //////////////////////////////////  

        class Node {
        private:
            friend class SLList;

            Node() = default;

            Node(DataType&& in_data, Node* in_prev);
            Node(const DataType& in_data, Node* in_prev);

            DataType data;
            Node* prev;
        };

        typedef Node* NodePtr;
        typedef Node& NodeRef;
        typedef unsigned long long int size_t;

        ////////////////////////////////////
        // ForwardIterator declaration
        //////////////////////////////////      

        template <typename IteratorDataType>
        class ForwardIterator {
        private:

            friend class SLList;

            explicit ForwardIterator(NodePtr node);

        public:

            using iterator_category = std::forward_iterator_tag;
            using value_type = DataType;
            using difference_type = std::ptrdiff_t;
            using pointer = NodePtr;
            using reference = NodeRef;

            ForwardIterator() noexcept;
            ForwardIterator(const ForwardIterator<DataType>& other) noexcept;

            ForwardIterator& operator=(const ForwardIterator& rhs) = default;
            [[nodiscard]] bool operator==(const ForwardIterator<const DataType>& rhs) const noexcept;
            [[nodiscard]] bool operator!=(const ForwardIterator<const DataType>& rhs) const noexcept;
            [[nodiscard]] bool operator==(const ForwardIterator<DataType>& rhs) const noexcept;
            [[nodiscard]] bool operator!=(const ForwardIterator<DataType>& rhs) const noexcept;
            ForwardIterator& operator++() noexcept;
            ForwardIterator operator++(int) noexcept;
            [[nodiscard]] value_type operator*() const noexcept;
            [[nodiscard]] pointer operator->() const noexcept;

        private:

            NodePtr node_ = nullptr;

        };

        ////////////////////////////////////
        // SLList private fields and members
        //////////////////////////////////       

        size_t size_{ 0 };
        DataType empty_;
        NodePtr back_;

        NodePtr CopyNodes_(const SLList& other);
        NodePtr InitFromList_(std::initializer_list<DataType> init_list);

    public:

        ////////////////////////////////////
        // SLList public fields and members
        //////////////////////////////////

        SLList();
        SLList(std::initializer_list<DataType> init_list);
        SLList(const SLList& other);
        SLList(SLList&& other);
        ~SLList();

        SLList& operator=(const SLList& other);
        SLList& operator=(SLList&& other);

        using value_type = DataType;
        using reference = value_type&;
        using const_reference = const value_type&;
        using Iterator = ForwardIterator<DataType>;
        using ConstantIterator = ForwardIterator<const DataType>;

        [[nodiscard]] Iterator begin() noexcept;
        [[nodiscard]] Iterator end() noexcept;
        [[nodiscard]] ConstantIterator begin() const noexcept;
        [[nodiscard]] ConstantIterator end() const noexcept;
        [[nodiscard]] ConstantIterator cbegin() const noexcept;
        [[nodiscard]] ConstantIterator cend() const noexcept;

        void clear() noexcept;
        void push_back(DataType&& data);
        void push_back(const DataType& data);
        void pop_back() noexcept;
        bool empty() const noexcept;
        size_t size() const noexcept;
    };

    ////////////////////////////////////
    // Node defenition
    //////////////////////////////////  

    template<typename DataType>
    inline SLList<DataType>::Node::Node(DataType&& in_data, SLList<DataType>::Node* in_prev) :
        data{ std::move(in_data) },
        prev{ in_prev }
    {
        // Parametrized move constructor
    }

    template<typename DataType>
    inline SLList<DataType>::Node::Node(const DataType& in_data, SLList<DataType>::Node* in_prev) :
        data{ DataType(in_data) },
        prev{ in_prev }
    {
        // Parametrized copy constructor
    }

    ////////////////////////////////////
    // ForwardIterator defenition
    //////////////////////////////////  

    template<typename DataType>
    template<typename IteratorDataType>
    SLList<DataType>::ForwardIterator<IteratorDataType>::ForwardIterator(SLList<DataType>::NodePtr node) :
        node_{ node }
    {
        // Parametrized constructor
    }

    template<typename DataType>
    template<typename IteratorDataType>
    SLList<DataType>::ForwardIterator<IteratorDataType>::ForwardIterator() noexcept :
        node_{ nullptr }
    {
        // Default constructor
    }

    template<typename DataType>
    template<typename IteratorDataType>
    SLList<DataType>::ForwardIterator<IteratorDataType>::ForwardIterator(const ForwardIterator<DataType>& other) noexcept :
        node_{ other.node_ }
    {
        node_->prev = other.node_->prev;
        node_->data = other.node_->data;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool SLList<DataType>::ForwardIterator<IteratorDataType>::operator==(const ForwardIterator<const DataType>& rhs) const noexcept {
        return this->node_ == rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool SLList<DataType>::ForwardIterator<IteratorDataType>::operator!=(const ForwardIterator<const DataType>& rhs) const noexcept {
        return this->node_ != rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool SLList<DataType>::ForwardIterator<IteratorDataType>::operator==(const ForwardIterator<DataType>& rhs) const noexcept {
        return this->node_ == rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool SLList<DataType>::ForwardIterator<IteratorDataType>::operator!=(const ForwardIterator<DataType>& rhs) const noexcept {
        return this->node_ != rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    SLList<DataType>::ForwardIterator<IteratorDataType>& SLList<DataType>::ForwardIterator<IteratorDataType>::operator++() noexcept {
        this->node_ = this->node_->prev;
        return *this;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    SLList<DataType>::ForwardIterator<IteratorDataType> SLList<DataType>::ForwardIterator<IteratorDataType>::operator++(int) noexcept {
        ForwardIterator<IteratorDataType> old_value(*this);
        ++(*this);
        return old_value;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    typename SLList<DataType>::ForwardIterator<IteratorDataType>::value_type SLList<DataType>::ForwardIterator<IteratorDataType>::operator*() const noexcept {
        return node_->data;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    typename SLList<DataType>::ForwardIterator<IteratorDataType>::pointer SLList<DataType>::ForwardIterator<IteratorDataType>::operator->() const noexcept {
        return node_;
    }

    ////////////////////////////////////
    // SLList defenition
    //////////////////////////////////  

    template<typename DataType>
    inline typename SLList<DataType>::NodePtr SLList<DataType>::CopyNodes_(const SLList& other) {
        if (other.empty()) {
            return nullptr;
        }
        NodePtr index = other.back_->prev;
        back_ = new Node(other.back_->data, nullptr);
        while (index != nullptr) {
            back_->prev = new Node(index->data, nullptr);
            index = index->prev;
        }
        return back_;
    }

    template<typename DataType>
    inline typename SLList<DataType>::NodePtr SLList<DataType>::InitFromList_(std::initializer_list<DataType> init_list) {
        back_ = nullptr;
        for (auto it = init_list.begin(); it != init_list.end(); ++it) {
            push_back(*it);
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
    inline SLList<DataType>::SLList(std::initializer_list<DataType> init_list) :
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
        other.clear();
    }

    template<typename DataType>
    inline SLList<DataType>::~SLList() {
        clear();
    }

    template<typename DataType>
    inline SLList<DataType>& SLList<DataType>::operator=(const SLList& other) {
        if (this == &other) {
            clear();
            size_ = other.size_;
            back_ = CopyNodes_(other);
        }
        return *this;
    }

    template<typename DataType>
    inline SLList<DataType>& SLList<DataType>::operator=(SLList&& other) {
        if (this != &other) {
            clear();
            back_ = other.back_;
            size_ = other.size_;
            other.back_ = nullptr;
            other.clear();
        }
        return *this;
    }

    template<typename DataType>
    inline typename SLList<DataType>::Iterator SLList<DataType>::begin() noexcept {
        if (empty()) {
            return end();
        }
        return Iterator(back_);
    }

    template<typename DataType>
    inline typename SLList<DataType>::Iterator SLList<DataType>::end() noexcept {
        return Iterator(nullptr);
    }

    template<typename DataType>
    inline typename SLList<DataType>::ConstantIterator SLList<DataType>::begin() const noexcept {
        if (empty()) {
            return end();
        }
        return ConstantIterator(back_);
    }

    template<typename DataType>
    inline typename SLList<DataType>::ConstantIterator SLList<DataType>::end() const noexcept {
        return ConstantIterator(nullptr);
    }

    template<typename DataType>
    inline typename SLList<DataType>::ConstantIterator SLList<DataType>::cbegin() const noexcept {
        if (empty()) {
            return end();
        }
        return ConstantIterator(back_);
    }

    template<typename DataType>
    inline typename SLList<DataType>::ConstantIterator SLList<DataType>::cend() const noexcept {
        return ConstantIterator(nullptr);
    }

    template<typename DataType>
    inline void SLList<DataType>::clear() noexcept {
        NodePtr current{ nullptr };
        while (back_ != nullptr) {
            current = back_;
            back_ = back_->prev;
            delete current;
        }
        size_ = 0;
    }

    template<typename DataType>
    inline void SLList<DataType>::push_back(DataType&& data) {
        back_ = new Node(std::move(data), back_);
        ++size_;
    }

    template<typename DataType>
    inline void SLList<DataType>::push_back(const DataType& data) {
        back_ = new Node(data, back_);
        ++size_;
    }

    template<typename DataType>
    inline void SLList<DataType>::pop_back() noexcept {
        if (empty()) {
            return;
        }
        NodePtr back_node = back_->prev;
        delete back_;
        back_ = back_node;
        --size_;
    }

    template<typename DataType>
    inline bool SLList<DataType>::empty() const noexcept {
        return size_ == 0;
    }

    template<typename DataType>
    typename SLList<DataType>::size_t SLList<DataType>::size() const noexcept {
        return size_;
    }

}
#endif