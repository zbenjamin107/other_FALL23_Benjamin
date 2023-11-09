#include <iostream>
#include "ReplacementAlgorithm.h"
#include <vector>
#include <iostream>
#include "ReplacementAlgorithm.h"

using namespace std;
class OPT : public ReplacementAlgorithm {
public:
    OPT(int numPageFrames);
    //void insert(int pageNumber) override;

    void insertOPT(int pageNumber, vector<int> remain);
    int placesTill(int page, vector<int> remain) ;
    

private:
    // data structure to store the int page frame list
    //list of ints to hold page numbers 
    int pageFrames;
    std::list<int> list;
    bool fault;
    
    
    };
