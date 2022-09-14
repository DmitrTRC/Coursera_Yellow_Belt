//
// Created by Dmitry Morozov on 15/9/22.
//

#include "shared/Region.hpp"
#include "shared/RegionsBase.hpp"

#include <map>
#include <tuple>
#include <vector>


using namespace std;


/**
 * It compares two regions by comparing their standard names, then their parent standard names, then their names, and
 * finally their populations
 *
 * @param lhs left-hand side operand
 * @param rhs right-hand side
 */
bool operator< (const Region &lhs, const Region &rhs) {
    return tie (lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
           tie (rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

/**
 * It creates a map of regions to their repetition counts, and then finds the maximum repetition count
 *
 * @param regions a vector of Region objects.
 *
 * @return The maximum number of times a region is repeated in the vector.
 */
int FindMaxRepetitionCount (const vector<Region> &regions) {
    int result = 0;
    map<Region, int> repetition_count;
    for (const Region &region: regions) {
        result = max (result, ++repetition_count[region]);
    }
    return result;
}
