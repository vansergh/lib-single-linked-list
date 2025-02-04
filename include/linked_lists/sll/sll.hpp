#ifndef SLL_HPP
#define SLL_HPP

#include <initializer_list>

namespace linked_lists {

    ////////////////////////////////////
    // forward_list declaration
    //////////////////////////////////  

    template <typename DataType>
    class forward_list {
    private:

        ////////////////////////////////////
        // Node declaration
        //////////////////////////////////  

        class Node {
        private:
            friend class forward_list;

            Node() = default;

            Node(DataType&& in_data, Node* in_next);
            Node(const DataType& in_data, Node* in_next);

            DataType data;
            Node* next;
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

            friend class forward_list;

            explicit ForwardIterator(NodePtr node, bool is_before_begin = false);

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

            NodePtr node_;
            bool is_before_begin_;

        };

        ////////////////////////////////////
        // forward_list private fields and members
        //////////////////////////////////       

        size_t size_{ 0 };
        NodePtr front_;

        template <typename Container>
        void CopyAndSwap_(const Container& container, std::size_t size);

    public:

        ////////////////////////////////////
        // forward_list public fields and members
        //////////////////////////////////

        forward_list();
        forward_list(std::initializer_list<DataType> init_list);
        forward_list(const forward_list& other);
        forward_list(forward_list&& other);
        ~forward_list();

        forward_list& operator=(const forward_list& other);
        forward_list& operator=(forward_list&& other);

        using value_type = DataType;
        using reference = value_type&;
        using const_reference = const value_type&;
        using Iterator = ForwardIterator<DataType>;
        using ConstantIterator = ForwardIterator<const DataType>;

        [[nodiscard]] Iterator before_begin() noexcept;
        [[nodiscard]] Iterator begin() noexcept;
        [[nodiscard]] Iterator end() noexcept;
        [[nodiscard]] ConstantIterator before_begin() const noexcept;
        [[nodiscard]] ConstantIterator cbefore_begin() const noexcept;
        [[nodiscard]] ConstantIterator begin() const noexcept;
        [[nodiscard]] ConstantIterator end() const noexcept;
        [[nodiscard]] ConstantIterator cbegin() const noexcept;
        [[nodiscard]] ConstantIterator cend() const noexcept;

        void clear() noexcept;
        void push_front(DataType&& data);
        void push_front(const DataType& data);
        Iterator insert_after(ConstantIterator pos, DataType&& data);
        Iterator insert_after(ConstantIterator pos, const DataType& data);
        Iterator erase_after(ConstantIterator pos);
        void pop_front() noexcept;
        bool empty() const noexcept;
        size_t size() const noexcept;

        void swap(forward_list& other) noexcept;
    };

    ////////////////////////////////////
    // Node defenition
    //////////////////////////////////  

    template<typename DataType>
    inline forward_list<DataType>::Node::Node(DataType&& in_data, forward_list<DataType>::Node* in_next) :
        data{ std::move(in_data) },
        next{ in_next }
    {
        // Parametrized move constructor
    }

    template<typename DataType>
    inline forward_list<DataType>::Node::Node(const DataType& in_data, forward_list<DataType>::Node* in_next) :
        data{ DataType(in_data) },
        next{ in_next }
    {
        // Parametrized copy constructor
    }

    ////////////////////////////////////
    // ForwardIterator defenition
    //////////////////////////////////  

    template<typename DataType>
    template<typename IteratorDataType>
    forward_list<DataType>::ForwardIterator<IteratorDataType>::ForwardIterator(forward_list<DataType>::NodePtr node, bool is_before_begin) :
        node_{ node },
        is_before_begin_{ is_before_begin }
    {
        // Parametrized constructor
    }

    template<typename DataType>
    template<typename IteratorDataType>
    forward_list<DataType>::ForwardIterator<IteratorDataType>::ForwardIterator() noexcept :
        node_{ nullptr },
        is_before_begin_{ false }
    {
        // Default constructor
    }

    template<typename DataType>
    template<typename IteratorDataType>
    forward_list<DataType>::ForwardIterator<IteratorDataType>::ForwardIterator(const ForwardIterator<DataType>& other) noexcept :
        node_{ other.node_ },
        is_before_begin_{ other.is_before_begin_ }
    {

    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool forward_list<DataType>::ForwardIterator<IteratorDataType>::operator==(const ForwardIterator<const DataType>& rhs) const noexcept {
        return this->node_ == rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool forward_list<DataType>::ForwardIterator<IteratorDataType>::operator!=(const ForwardIterator<const DataType>& rhs) const noexcept {
        return this->node_ != rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool forward_list<DataType>::ForwardIterator<IteratorDataType>::operator==(const ForwardIterator<DataType>& rhs) const noexcept {
        return this->node_ == rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    bool forward_list<DataType>::ForwardIterator<IteratorDataType>::operator!=(const ForwardIterator<DataType>& rhs) const noexcept {
        return this->node_ != rhs.node_;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    forward_list<DataType>::ForwardIterator<IteratorDataType>& forward_list<DataType>::ForwardIterator<IteratorDataType>::operator++() noexcept {
        this->node_ = this->node_->next;
        return *this;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    forward_list<DataType>::ForwardIterator<IteratorDataType> forward_list<DataType>::ForwardIterator<IteratorDataType>::operator++(int) noexcept {
        ForwardIterator<IteratorDataType> old_value(*this);
        ++(*this);
        return old_value;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    typename forward_list<DataType>::ForwardIterator<IteratorDataType>::value_type forward_list<DataType>::ForwardIterator<IteratorDataType>::operator*() const noexcept {
        return node_->data;
    }

    template<typename DataType>
    template<typename IteratorDataType>
    typename forward_list<DataType>::ForwardIterator<IteratorDataType>::pointer forward_list<DataType>::ForwardIterator<IteratorDataType>::operator->() const noexcept {
        return node_;
    }

    ////////////////////////////////////
    // forward_list defenition
    //////////////////////////////////  

    template <typename DataType>
    template <typename Container>
    void forward_list<DataType>::CopyAndSwap_(const Container& container, std::size_t size) {
        forward_list<DataType> tmp_list;

        Node* tmp{ nullptr };
        for (const auto& node : container) {
            Node* new_node = new Node(node, nullptr);
            if (tmp) {
                tmp->next = new_node;
            }
            else {
                tmp_list.front_ = new_node;
            }
            tmp = new_node;
        }
        tmp_list.size_ = size;

        swap(tmp_list);
    }

    template<typename DataType>
    inline forward_list<DataType>::forward_list() :
        size_{ 0 },
        front_{ nullptr }
    {
        // Default constructor
    }

    template<typename DataType>
    inline forward_list<DataType>::forward_list(std::initializer_list<DataType> init_list) :
        size_{ 0 },
        front_{ nullptr }
    {
        CopyAndSwap_(init_list, init_list.size());
    }

    template<typename DataType>
    inline forward_list<DataType>::forward_list(const forward_list& other) :
        size_{ 0 },
        front_{ nullptr }
    {
        CopyAndSwap_(other, other.size_);
    }

    template<typename DataType>
    inline forward_list<DataType>::forward_list(forward_list&& other) :
        size_{ other.size_ },
        front_{ other.front_ }
    {
        other.front_ = nullptr;
        other.clear();
    }

    template<typename DataType>
    inline forward_list<DataType>::~forward_list() {
        clear();
    }

    template<typename DataType>
    inline forward_list<DataType>& forward_list<DataType>::operator=(const forward_list& other) {
        if (this == &other) {
            clear();
            size_ = other.size_;
            front_ = CopyNodes_(other);
        }
        return *this;
    }

    template<typename DataType>
    inline forward_list<DataType>& forward_list<DataType>::operator=(forward_list&& other) {
        if (this != &other) {
            clear();
            front_ = other.front_;
            size_ = other.size_;
            other.front_ = nullptr;
            other.clear();
        }
        return *this;
    }

    template<typename DataType>
    inline typename forward_list<DataType>::Iterator forward_list<DataType>::before_begin() noexcept {
        return Iterator(nullptr, true);
    }

    template<typename DataType>
    inline typename forward_list<DataType>::Iterator forward_list<DataType>::begin() noexcept {
        if (empty()) {
            return end();
        }
        return Iterator(front_);
    }

    template<typename DataType>
    inline typename forward_list<DataType>::Iterator forward_list<DataType>::end() noexcept {
        return Iterator(nullptr);
    }

    template<typename DataType>
    inline forward_list<DataType>::ConstantIterator forward_list<DataType>::before_begin() const noexcept {
        return ConstantIterator(nullptr, true);
    }

    template<typename DataType>
    inline typename forward_list<DataType>::ConstantIterator forward_list<DataType>::cbefore_begin() const noexcept {
        return before_begin();
    }

    template<typename DataType>
    inline typename forward_list<DataType>::ConstantIterator forward_list<DataType>::begin() const noexcept {
        if (empty()) {
            return end();
        }
        return ConstantIterator(const_cast<Node*>(front_));
    }

    template<typename DataType>
    inline typename forward_list<DataType>::ConstantIterator forward_list<DataType>::end() const noexcept {
        return ConstantIterator(nullptr);
    }

    template<typename DataType>
    inline typename forward_list<DataType>::ConstantIterator forward_list<DataType>::cbegin() const noexcept {
        return begin();
    }

    template<typename DataType>
    inline typename forward_list<DataType>::ConstantIterator forward_list<DataType>::cend() const noexcept {
        return end();
    }

    template<typename DataType>
    inline void forward_list<DataType>::clear() noexcept {
        NodePtr current{ nullptr };
        while (front_ != nullptr) {
            current = front_;
            front_ = front_->next;
            delete current;
        }
        size_ = 0;
    }

    template<typename DataType>
    inline void forward_list<DataType>::push_front(DataType&& data) {
        NodePtr new_node = new Node(std::move(data), front_);
        front_ = new_node;
        ++size_;
    }

    template<typename DataType>
    inline void forward_list<DataType>::push_front(const DataType& data) {
        NodePtr new_node = new Node(data, front_);
        front_ = new_node;
        ++size_;
    }

    template<typename DataType>
    inline forward_list<DataType>::Iterator forward_list<DataType>::insert_after(forward_list<DataType>::ConstantIterator pos, DataType&& data) {
        if (pos == end()) {
            return end();
        }
        Node* new_node{ nullptr };
        if (pos.is_before_begin_) {
            new_node = new Node(std::move(data), nullptr);
            if (front_) {
                new_node->next = front_;
            }
            front_ = new_node;
        }
        else {
            new_node = new Node(std::move(data), pos.node_->next_node);
            pos.node_->next_node = new_node;
        }
        ++size_;
        return Iterator(new_node);
    }

    template<typename DataType>
    inline forward_list<DataType>::Iterator forward_list<DataType>::insert_after(forward_list<DataType>::ConstantIterator pos, const DataType& data) {
        if (pos == end() && !pos.is_before_begin_) {
            return end();
        }
        Node* new_node{ nullptr };
        if (pos.is_before_begin_) {
            new_node = new Node(data, nullptr);
            if (front_) {
                new_node->next = front_;
            }
            front_ = new_node;
        }
        else {
            new_node = new Node(data, pos.node_->next_node);
            pos.node_->next_node = new_node;
        }
        ++size_;
        return Iterator(new_node);
    }

    template<typename DataType>
    inline forward_list<DataType>::Iterator forward_list<DataType>::erase_after(forward_list<DataType>::ConstantIterator pos) {
        if (empty() || (pos == end() && !pos.is_before_begin_)) {
            return end();
        }        
        Node* next_node;
        if (pos.is_before_begin_) {
            next_node = front_->next;
            delete front_;
            front_ = next_node;
            --size_;
            return Iterator(front_);
        }
        else {
            next_node = pos.node_->next;
            pos.node_->next = next_node->next;
            delete next_node;
            --size_;
            return Iterator(pos.node_->next);
        }
    }

    template<typename DataType>
    inline void forward_list<DataType>::pop_front() noexcept {
        if (empty()) {
            return;
        }
        NodePtr front_node = front_->next;
        delete front_;
        front_ = front_node;
        --size_;
    }

    template<typename DataType>
    inline bool forward_list<DataType>::empty() const noexcept {
        return size_ == 0;
    }

    template<typename DataType>
    void forward_list<DataType>::swap(forward_list& other) noexcept {
        Node* tmp_back = other.front_;
        std::size_t tmp_size = other.size_;
        other.front_ = front_;
        other.size_ = size_;
        front_ = tmp_back;
        size_ = tmp_size;
    }

    template<typename DataType>
    typename forward_list<DataType>::size_t forward_list<DataType>::size() const noexcept {
        return size_;
    }

}
#endif