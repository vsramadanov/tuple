#include <tuple>       // std::tuple, std::make_tuple
#include <cstdint>     // size_t
#include <type_traits> // std::integral_constant
#include <iostream>

#include "apply.h"

template <typename Tuple>
constexpr auto reverse(Tuple t) {
    return index_apply<std::tuple_size<Tuple>::value>([&](auto... Is) {
        return std::make_tuple(
            std::get<std::tuple_size<Tuple>::value - 1 - Is>(t)...);
    });
}

int main(int argc, char *argv[]) {
    std::tuple<int, double, char, const char*> tup(1, 2.0, 'a', "hello");
    auto rev_tup = reverse(tup);
    
    apply(rev_tup, [](auto element) { std::cout << element << " "; });
    std::cout << std::endl;
    
    return 0;
}
