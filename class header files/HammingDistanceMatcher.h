#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "PlagiarismDetector.h"
class HammingDistanceMatcher : public PlagiarismDetector {
public:
    HammingDistanceMatcher(std::string corpus_dir); //constructor
    std::set<std::string> match(std::string sentence); //matches sentence using hamming distance algorithm

private:
    std::string matcher;
};