#include <tuple>
#include <iostream>

int main(int argc, char *argv[]) {
    std::tuple<int, double, char, const char*> tup(1, 2.0, 'a', "hello");
    // std::apply([](auto element) { std::cout << element << " "; }, tup);
    
    std::apply([](const auto... elements){ ((std::cout << elements << " "), ...); }, tup);
    std::cout << std::endl;
    
    return 0;
}
