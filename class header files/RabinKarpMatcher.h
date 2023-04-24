#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "PlagiarismDetector.h"
class RabinKarpMatcher :
    public PlagiarismDetector
{
public:
    RabinKarpMatcher(std::string corpus_dir);
    std::set<std::string> match(std::string sentence);

private:
    std::string matcher;
};

