#include <tuple>       // std::tuple, std::make_tuple
#include <iostream>

int main(int argc, char *argv[]) {
    std::tuple<int, double, char, const char*> tup(1, 2.0, 'a', "hello");
    auto tup2 = std::make_tuple(2, 3.0, 'a', "world");
    
    std::cout << std::get<int>(tup) << "\n";
    std::cout << std::get<double>(tup) << "\n";
    std::cout << std::get<char>(tup) << "\n";
    std::cout << std::get<const char*>(tup) << "\n";
    
    std::cout << "=========================\n";
    
    std::cout << std::get<0>(tup2) << "\n";
    std::cout << std::get<1>(tup2) << "\n";
    std::cout << std::get<2>(tup2) << "\n";
    std::cout << std::get<3>(tup2) << "\n";
    
    return 0;
}
