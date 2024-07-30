#include <ostream>
#include <algorithm>

#include <linked_lists/sll/sll.hpp>

namespace linked_lists {

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

    template <typename DataType>
    void swap(SLList<DataType>& lhs, SLList<DataType>& rhs) noexcept {
        lhs.swap(rhs);
    }

    template <typename DataType>
    bool operator==(const SLList<DataType>& lhs, const SLList<DataType>& rhs) {
        return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin());
    }

    template <typename DataType>
    bool operator!=(const SLList<DataType>& lhs, const SLList<DataType>& rhs) {
        return !(lhs == rhs);
    }

    template <typename DataType>
    bool operator<(const SLList<DataType>& lhs, const SLList<DataType>& rhs) {
        return std::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
    }

    template <typename DataType>
    bool operator<=(const SLList<DataType>& lhs, const SLList<DataType>& rhs) {
        return (lhs < rhs) || (lhs == rhs);
    }

    template <typename DataType>
    bool operator>(const SLList<DataType>& lhs, const SLList<DataType>& rhs) {
        return !(lhs < rhs) && (lhs != rhs);
    }

    template <typename DataType>
    bool operator>=(const SLList<DataType>& lhs, const SLList<DataType>& rhs) {
        return (lhs > rhs) || (lhs == rhs);
    }


}