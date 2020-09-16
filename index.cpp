#include <utility>     // std::index_sequence, std::make_index_sequence
#include <tuple>       // std::tuple
#include <cstdint>     // size_t
#include <type_traits> // std::integral_constant
#include <iostream>

template <typename... Types>
struct index_matcher;

template <typename T, typename... Types>
struct index_matcher<T, T, Types...> {
    static constexpr size_t value = 0;
};

template <typename T, typename U, typename... Types>
struct index_matcher<T, U, Types...> {
    static constexpr size_t value = 1 + index_matcher<T, Types...>::value;
};

template<typename T, typename... Types>
constexpr size_t index_of(std::tuple<Types...>) {
    return index_matcher<T, Types...>::value;
}

int main(int argc, char *argv[]) {
    std::tuple<int, double, char> tup(1, 2.0, 'a');    
    
    std::cout << index_of<int>(tup) << std::endl;
    std::cout << index_of<double>(tup) << std::endl;
    std::cout << index_of<char>(tup) << std::endl;
    
    return 0;
}
