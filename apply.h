#include <utility>     // std::index_sequence, std::make_index_sequence
#include <tuple>       // std::tuple
#include <cstdint>     // size_t
#include <type_traits> // std::integral_constant
#include <iostream>


template <typename Func, size_t... Is>
constexpr auto index_apply_impl(Func func, std::index_sequence<Is...>) {
    return func(std::integral_constant<size_t, Is>{}...);
}

template <size_t N, typename Func>
constexpr auto index_apply(Func func) {
    return index_apply_impl(func, std::make_index_sequence<N>{});
}

template <typename Tuple, typename Func>
constexpr auto apply(Tuple t, Func f) {
    return index_apply<std::tuple_size<Tuple>::value>(
        [&](auto... Is) { auto list __attribute__((unused)) = 
                {(f(std::get<Is>(t)), 0)...}; });
}

