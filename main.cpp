#include "solomon_scanner.h"

int main() {
    try {
        Problem p("examples/C101.txt"); 
    } catch (const std::exception& e) {
        std::cerr << "[Error]: " << e.what() << std::endl;
    }
}

