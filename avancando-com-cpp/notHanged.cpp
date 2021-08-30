#include "notHanged.hpp"
#include <vector>

extern std::vector<char> wrongGuesses;

bool notHanged() { return wrongGuesses.size() < 6; }
