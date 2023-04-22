#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

class Document {
public:
    Document(string file_path);
    void parse_sentences();
    vector<string> get_sentences();
    void set_plagiarism_percentage(float percentage);
    float get_plagiarism_percentage();

private:
    string file_path;
    vector<string> sentences;
    float plagiarism_percentage;
};

class PlagiarismDetector {
public:
    PlagiarismDetector(string corpus_dir);
    void load_corpus();
    virtual set<string> match(string sentence) = 0;

protected:
    string corpus_dir;
    vector<Document> corpus;
};

class HammingDistanceMatcher : public PlagiarismDetector {
public:
    HammingDistanceMatcher(string corpus_dir);
    set<string> match(string sentence) override;

private:
    string matcher;
};

class RabinKarpMatcher : public PlagiarismDetector {
public:
    RabinKarpMatcher(string corpus_dir);
    set<string> match(string sentence) override;

private:
    string matcher;
};

class KMPMatcher : public PlagiarismDetector {
public:
    KMPMatcher(string corpus_dir);
    set<string> match(string sentence) override;

private:
    string matcher;
};

class BoyerMooreMatcher : public PlagiarismDetector {
public:
    BoyerMooreMatcher(string corpus_dir);
    set<string> match(string sentence) override;

private:
    string matcher;
};
