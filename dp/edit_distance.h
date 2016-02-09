#ifndef DP_EDIT_DISTANCE_H_
#define DP_EDIT_DISTANCE_H_

#include <string>

// EditDistance returns the minimum number of edits (insertion,
// deletion, and replacement) needed to change string a to string b.
int EditDistance(const std::string& a, const std::string& b);

#endif  // DP_EDIT_DISTANCE_H_
