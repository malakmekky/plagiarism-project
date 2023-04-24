#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "PlagiarismDetector.h"
class HammingDistanceMatcher : public PlagiarismDetector {
public:
    HammingDistanceMatcher(std::string corpus_dir);
    std::set<std::string> match(std::string sentence);

private:
    std::string matcher;
};