#include <iostream>
#include <cassert>
#include "../src/solomon_scanner.h"

void test_valid_file() {
    Problem p("examples/C101.txt");
    assert(p.vehicles_num == 25);
    assert(p.vehicle_capacity == 200);
    assert(p.customers.size() == 101);
}

void test_invalid_file() {
    bool exception_thrown = false;

    try {
        Problem p("examples/DOES_NOT_EXIST.txt");
    } catch (const std::runtime_error&) {
        exception_thrown = true;
    } catch (...) {
        assert(false && "Unexpected exception type thrown");
    }

    assert(exception_thrown && "Expected exception was not thrown");
}


int main() {
    test_valid_file();
    test_invalid_file();
    std::cout << "All tests passed.\n";
    return 0;
}
