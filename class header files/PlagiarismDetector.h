#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "Document.h"
class PlagiarismDetector
{
public:
    PlagiarismDetector(std::string corpus_dir); //constructor
    void load_corpus(); //loads all the documents in the corpus
    virtual std::set<std::string> match(std::string sentence) = 0; //matches senctence with the corpus

protected:
    std::string corpus_dir;
    std::vector<Document> corpus;
};

