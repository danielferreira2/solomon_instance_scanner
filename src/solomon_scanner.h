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

class SolomonInstance {
public:
    SolomonInstance(const std::string& file_name);
    int vehicles_num{};
    int vehicle_capacity{};
    std::vector<customer> customers;
    const std::string file_name;



    template<typename DistanceFunc>
    std::vector<std::vector<double>> adjacency_matrix(DistanceFunc func) const {
        size_t n = customers.size();
        std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                matrix[i][j] = func(customers[i], customers[j]);
            }
        }
        return matrix;
    }

};


inline void skip_lines(std::ifstream& file, int n) {
    std::string line;
    for (int i = 0; i < n; ++i) {
        std::getline(file, line);
    }
}


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

inline std::ostream& operator<<(std::ostream& os, const SolomonInstance& p) {
    os << "========== " << p.file_name << " ==========\n"
        << "vehicles fleet size: " << p.vehicles_num << "\n"
        << "vehicle capacity: " << p.vehicle_capacity << "\n";
    for (const auto& c : p.customers) {
        os << c << "\n";
    }
    return os;
}