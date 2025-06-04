#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

struct customer {
    int id;
    int x, y;
    int demand;
    int ready_time;
    int due_date;
    int service_time;
};

class Problem {
public:
    Problem(const std::string& file_name);

    int vehicles_num{};
    int vehicle_capacity{};
    std::vector<customer> customers;
    const std::string file_name;

private:
    static void skip_lines(std::ifstream& file, int n);
};

inline std::ostream& operator<<(std::ostream& os, const customer& c) {
    os << "id: " << c.id 
        << " x: " << c.x 
        << " y: " << c.y 
        << " demand: " << c.demand 
        << " ready_time: " << c.ready_time 
        << " due_date: " << c.due_date 
        << " service_time: " << c.service_time;
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Problem& p) {
    os << "========== " << p.file_name << " ==========\n"
        << "vehicles fleet size: " << p.vehicles_num << "\n"
        << "vehicle capacity: " << p.vehicle_capacity << "\n";
    for (const auto& c : p.customers) {
        os << c << "\n";
    }
    return os;
}