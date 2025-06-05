#include "src/solomon_scanner.h"
#include <cmath>

//===========================temp======================================
auto euclidean_distance = [](const customer& a, const customer& b) -> double {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return std::sqrt(dx*dx + dy*dy);
};

auto weighted_distance = [](const customer& a, const customer& b) -> double {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    double distance = std::sqrt(dx * dx + dy * dy);
    
    double weight_service_time = 0.5;
    return distance + weight_service_time * std::abs(a.service_time - b.service_time);
};

auto rich_weighted_distance = [](const customer& a, const customer& b) -> double {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    double distance = std::sqrt(dx * dx + dy * dy);

    double weight_demand = 0.3;
    double weight_window = 0.1;

    int demand_diff = std::abs(a.demand - b.demand);
    int window_diff = std::abs(a.ready_time - b.ready_time);

    return distance + weight_demand * demand_diff + weight_window * window_diff;
};

// =================================================================

int main() {
    try {
        SolomonInstance p("examples/instances/C101.txt"); 
        
        std::cout << p;
        //===============================temp========================
        auto distance_matrix= p.adjacency_matrix(euclidean_distance);
        for(int i=0;i<4; i++){
            for (int j=0;j<4; j++){
                std::cout<< distance_matrix[i][j] << " "; 
            }
            std::cout<<"\n";
        }
        //==============================================================

    } catch (const std::exception& e) {
        std::cerr << "[Error]: " << e.what() << std::endl;
    }
}

