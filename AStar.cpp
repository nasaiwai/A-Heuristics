// CSE 101 Winter 2016, PA 4
//
// Name: Nasa Iwai 
// PID: A91431033
// Sources of Help: TODO
// Due: March 4th, 2016 at 11:59 PM

#ifndef __A_STAR_CPP__
#define __A_STAR_CPP__

#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include "AStar.hpp"
using namespace std;

std::pair<int, float> a_star(TwoDArray<Coordinate>& g, Coordinate s, 
                             Coordinate d, float heuristic_weight) {
    // tbr indicates (number of vertices, length of best path found)
    std::pair<int, float> tbr;

    // TODO: Perform A* calculations
    std::priority_queue<Coordinate, std::vector<Coordinate>, CoordinateCompare> openList;
    std::priority_queue<Coordinate> closedList;
    //std::priority_queue<Coordinate> successors;
    std::queue<Coordinate> successors;
    float temp_g;
    float temp_f;

    //Initialize source vertex    
    g.at(s).g_score = 0;
    g.at(s).f_score = heuristic_weight * ( (d.r - s.r) + (d.c - s.c) );
    g.at(s).open_set = true;

    Coordinate successor;
    Coordinate goal;
    Coordinate current = g.at(s);

    openList.push(s);

    while( !openList.empty() ) {
        current = openList.top();
        openList.pop();
        closedList.push(g.at(current));
        g.at(current).closed_set = true;
 
std::cout << "Whileloop1" << std::endl;
        if(g.at(current).r >= 1)
            successors.push( g.at(g.at(current).r-1, g.at(current).c) ); 
        if(g.at(current).r < g.getNumRows() - 1)
            successors.push( g.at(g.at(current).r+1, g.at(current).c) ); 
        if(g.at(current).c >= 1)
            successors.push( g.at(g.at(current).r, g.at(current).c-1) ); 
        if(g.at(current).c < g.getNumCols() - 1)
            successors.push( g.at(g.at(current).r, g.at(current).c+1) ); 
      
        while( !successors.empty() ) {
std::cout << "Whileloop2" << std::endl;
            //successor = successors.top();
            successor = successors.front();
            //successor = g.at(current.r-1, current.c);
            //if successor is the destination, stop search            
            if( g.at(successor).r == g.at(d).r && g.at(successor).c == g.at(d).c ) {
                g.at(successor).g_score = g.at(current).g_score + 1; 
                g.at(successor).f_score = g.at(current).g_score + 1; 
                    openList.push(g.at(successor));     
                g.at(successor).open_set = true;
        current = openList.top();
        openList.pop();
        closedList.push(g.at(current));
        g.at(current).closed_set = true;
                goal = successor;
std::cout << "goal is within successor " << g.at(successor).f_score << std::endl;
                break;
            }
            if(g.at(successor).obstacle == false) {            
                //set successor's g_score    
                temp_g = g.at(current).g_score + 1;
                temp_f = temp_g + heuristic_weight * 
                            ((g.at(d).r - g.at(successor).r) + (g.at(d).c - g.at(successor).c));
std::cout << "just got temp values for f and g" << std::endl;
                if(g.at(successor).open_set == true ) {
std::cout << "open_set was true" << std::endl;        
                    if( temp_f < g.at(successor).f_score ) {
                        g.at(successor).g_score = temp_g;
                        g.at(successor).f_score = temp_f;
std::cout << "successor was already in openList. and this is smaller f value" << std::endl;
                    }
                }
                else {
                    g.at(successor).g_score = temp_g;
                    g.at(successor).f_score = temp_f;
                    openList.push(g.at(successor));     
                    g.at(successor).open_set = true;
std::cout << "This is the first time successor was visited" << std::endl;
                }
/*
                if(g.at(successor).closed_set == true ) {
std::cout << "closed_set was true" << std::endl;
                    if( temp_f < g.at(successor).f_score ) {        
                        g.at(successor).g_score = temp_g;
                        g.at(successor).f_score = temp_f;
std::cout << "closed_set if" << std::endl;
                    }
                }
                else {
                    g.at(successor).g_score = temp_g;
                    g.at(successor).f_score = temp_f;     
std::cout << "closed_set else" << std::endl; 
                }
*/            }
            successors.pop();
            g.printOut();
        } //end of inner while loop
        //closedList.push(g.at(current));
        //g.at(current).closed_set = true;
        if( g.at(successor).r == g.at(d).r && g.at(successor).c == g.at(d).c ) {
            break;
        }
    }
    if(g.at(d).closed_set == true) {
        tbr.first = closedList.size();
        tbr.second = g.at(d).f_score;
    }
    else {
        tbr.first = -1;
        tbr.second = -1.0;
    }
            g.printOut();
    // -1 is returned if the destination is not reachable
    //tbr.first = -1;
    //tbr.second = -1.0;

    return tbr;
}


#endif
