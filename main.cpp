#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <assert.h> 
#include <utility>
#include <fstream>

#include "helpers.cpp"
#include "Cord.cpp"
#include "Permute.cpp"
#include "MST.cpp"

// Vector with all the cities and substations (Nodes)
std::vector<Cord> NODES = { 
    Cord(0, 2), Cord(1, 2), Cord(1, 0), Cord(0, 0)
};

Cord min;
Cord max;

// Test substations from [0, MAX_SUBSTATIONS]
short MAX_SUBSTATIONS = 8;

int main() {
    assert ( NODES.size() > 0 );

    // Stores the max and min cordinates
    min = NODES[0];
    max = NODES[0];

    // Get the max and min cordinates to search through
    for(std::vector<Cord>::iterator i = NODES.begin()+1; i != NODES.end(); i += 1)
    {
        if( max.x > i->x )
            max.x = i->x;
        
        if(min.x < i->x)
            min.x = i->x;

        if( max.y > i->y )
            max.y = i->y;
        
        if(min.y < i->y)
            min.y = i->y;
        
    }

    MST forest = MST(NODES);

    for(short nSubs = 0; nSubs < MAX_SUBSTATIONS; ++nSubs)
    {

    }


    // std::ofstream out;
    // out.open ("points.out");

    // for(int i = 0; i < forest.forest.size(); ++i)
    // {
    //     out << NODES[forest.forest[i].u].x << " " << NODES[forest.forest[i].u].y << " " << NODES[forest.forest[i].v].x << " " << NODES[forest.forest[i].v].y << " " << std::endl;
    // }

    // out.close();
}