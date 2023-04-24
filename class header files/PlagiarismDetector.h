#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "Document.h"
class PlagiarismDetector
{
public:
    PlagiarismDetector(std::string corpus_dir);
    void load_corpus();
    virtual std::set<std::string> match(std::string sentence) = 0;

protected:
    std::string corpus_dir;
    std::vector<Document> corpus;
};

