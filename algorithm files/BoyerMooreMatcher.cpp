#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include "BoyerMooreMatcher.h"
#include "plagiarismdetector.h"

class BoyerMooreMatcher : public PlagiarismDetector{
public:
    BoyerMooreMatcher(std::string corpus_dir) : PlagiarismDetector(corpus_dir) {}
    std::set<std::string> match(std::string sentence) override{
        std::set<std::string> matchesFound;
        int n = sentence.length();
        char text[n+1];
        strcpy(text, sentence.c_str());
        for (Document& doc : corpus){
            std::vector<std::string> sentences = doc.get_sentences();
            int m = sentences.at(0).length();
            char patternArr[m+1];
            strcpy(patternArr, doc.get_sentences().at(0).c_str());
            std::reverse(patternArr, patternArr + m);
            int border[m+1], shift[m+1];
            preProcess(patternArr, m, border, shift);
            for (int i = 0; i<=m; i++){
                shift[i] = m - border[m];
            }
            for (int i = 1; i<=m; i++){
                int j = border[i];
                if (j>=0 && patternArr[i] == patternArr[j]){
                    shift[i] = shift[j];
                }
            }
            boyerMoore(text, patternArr, n, m, shift, matchesFound);
            float percentage = ((float)matchesFound.size()/(float)m)*100.0;
            doc.set_plagiarism_percentage(percentage);
        }
        return matchesFound;
    }
private:
    void preProcess(char* pattern, int m, int* border, int* shift){
        int i = 0, j = -1;
        border[0] = -1;
        while (i<m){
            while (j>=0 && pattern[i] != pattern[j]){
                j = border[j];
            }
            i++; j++;
            border[i] = j;
        }
    }
    void boyerMoore(char* text, char* pattern, int n, int m, int* shift, std::set<std::string>& matchesFound){
        int i = 0, j = 0;
        while (i<n){
            while (j>=0 && text[i] != pattern[j]){
                j = shift[j];
            }
            i++; j++;
            if (j == m){
                matchesFound.insert(std::string(text + i - j, text + i));
                j = shift[j];
            }
        }
    }
};
