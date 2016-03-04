// CSE 101 Winter 2016, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 4th, 2016 at 11:59 PM

#include "TSP.hpp"

// TODO: Write a comparator struct for your MST priority queue

// MST should be rooted at point id 0
std::vector<int> MST(const std::vector<std::pair<int, int>>& points) {
    int size = points.size();
    // initialize all prev fields in the mst to -1 to indicate unvisited
    std::vector<int> mst (size, -1);
    
    // TODO: Perform MST calculations

    return mst;
}

std::vector<int> TwoOPT(const std::vector<std::pair<int, int>>& points) {
    std::vector<int> visit_order;

    // TODO: Perform 2-OPT calculations

    return visit_order;
}
