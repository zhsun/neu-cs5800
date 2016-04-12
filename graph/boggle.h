#ifndef GRAPH_BOGGLE_H_
#define GRAPH_BOGGLE_H_

#include <string>
#include <unordered_set>
#include <vector>

// Boggle returns the number of words found in the *board*, and
// populate *words* accordingly.
int Boggle(const std::unordered_set<std::string>& dict,
           const std::vector<std::string>& board,
           std::unordered_set<std::string>* words);

#endif  // GRAPH_BOGGLE_H_
