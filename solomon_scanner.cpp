#include "solomon_scanner.h"

Problem::Problem(const std::string& file_name) 
    : file_name(file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file '" + file_name +
             "'. Please check if the file exists and if you have the necessary permissions.");
    }

    skip_lines(file, 4);
    file >> vehicles_num >> vehicle_capacity;
    skip_lines(file, 4);

    customer c;
    while (file >> c.id >> c.x >> c.y >> c.demand >> c.ready_time >> c.due_date >> c.service_time) {
        customers.push_back(c);
    }
}

void Problem::skip_lines(std::ifstream& file, int n) {
    std::string line;
    for (int i = 0; i < n; ++i) {
        std::getline(file, line);
    }
}
