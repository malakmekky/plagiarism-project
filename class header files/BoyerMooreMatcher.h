#include "PlagiarismDetector.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
class BoyerMooreMatcher :
    public PlagiarismDetector
{
public:
    BoyerMooreMatcher(std::string corpus_dir);
    std::set<std::string> match(std::string sentence);

private:
    std::string matcher;
};

//reason for using 'std::' even though i included the libraries is that i kept on getting errors without using 'std::'
