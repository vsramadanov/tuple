#include "apply.h"

int main(int argc, char *argv[]) {
    std::tuple<int, double, char, const char*> tup(1, 2.0, 'a', "hello");
    apply(tup, [](auto element) { std::cout << element << " "; });
    std::cout << std::endl;
    
    return 0;
}
