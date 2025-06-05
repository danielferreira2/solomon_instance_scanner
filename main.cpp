#include "src/solomon_scanner.h"

int main() {
    try {
        SolomonInstance p("examples/instances/C101.txt"); 
        std::cout << p;
    } catch (const std::exception& e) {
        std::cerr << "[Error]: " << e.what() << std::endl;
    }
}

