#include <tuple>       // std::tuple, std::make_tuple
#include <iostream>

#include "apply.h"

template <typename Tuple, typename Func>
auto transform(Tuple t, Func f) {
    return index_apply<std::tuple_size<Tuple>::value>(
        [&](auto... Is) {
            return std::make_tuple(f(std::get<Is>(t))...);
        });
}

struct process_different_types {
    int operator() (int i) { return ++i; }
    double operator() (double d) { return d * 2.0; }
    char operator() (char c) { return c; }
    const char* operator() (const char *str) { return str; }
};

int main(int argc, char *argv[]) {
    std::tuple<int, double, char, const char*> tup(1, 2.0, 'a', "hello");
    auto res = transform(tup, process_different_types{});
    
    apply(res, [](auto element) { std::cout << element << " "; });
    std::cout << std::endl;
    
    return 0;
}
