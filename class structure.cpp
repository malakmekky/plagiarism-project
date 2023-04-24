#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

class Document {
public:
    Document(string file_path); // constructor
    void parse_sentences(); //parses every sentence in the doc and stores it in the sentences vector
    vector<string> get_sentences(); // getter: returns the sentences vector
    void set_plagiarism_percentage(float percentage); //setter: sets the plagiarism percentage
    float get_plagiarism_percentage(); //getter: returns the plagiarism percentage

private:
    string file_path;
    vector<string> sentences; //stores all the sentences in the document
    float plagiarism_percentage;
};

class PlagiarismDetector {
public:
    PlagiarismDetector(string corpus_dir); //constructor
    void load_corpus(); //loads all the documents in the corpus
    virtual set<string> match(string sentence) = 0; //matches sentence with the corpus

protected:
    string corpus_dir;
    vector<Document> corpus;
};

class HammingDistanceMatcher : public PlagiarismDetector {
public:
    HammingDistanceMatcher(string corpus_dir);//constructor
    set<string> match(string sentence); //matches sentence using Hamming Distance algorithm
    //a set is used since it has to be stored in a specific manner and cannot be orverrided

private:
    string matcher; //stores the sentence to be matched
};

class RabinKarpMatcher : public PlagiarismDetector {
public:
    RabinKarpMatcher(string corpus_dir); //constructor
    set<string> match(string sentence); //matches sentence using Rabin Karp algorithm

private:
    string matcher;
};

class KMPMatcher : public PlagiarismDetector {
public:
    KMPMatcher(string corpus_dir);//constructor 
    set<string> match(string sentence);//matches sentence using KMP algorithm

private:
    string matcher;
};

class BoyerMooreMatcher : public PlagiarismDetector {
public:
    BoyerMooreMatcher(string corpus_dir);//constructor
    set<string> match(string sentence); //matches sentence using Boyer Moore algorithm

private:
    string matcher;
};
