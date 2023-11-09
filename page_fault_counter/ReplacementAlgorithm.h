#ifndef _REPLACEMENTALGORITHM_H
#define _REPLACEMENTALGORITHM_H

#include <list>
#include <vector>

using namespace std;
class ReplacementAlgorithm
{
public:
    // numPageFrames - the number of physical page frames
    ReplacementAlgorithm(int numPageFrames) : pageFrameCount(numPageFrames) {};

    // returns the number of page faults that occured
    int getPageFaultCount() { return pageFaultCount; }

    // pageNumber - the page number to be inserted
    virtual void insert(int pageNumber) {};
    // for opt. I had to create an insert method for OPT method. this one took the page number and remaining of the vector
    virtual void insertOPT(int page, vector<int> remain) {};
    // places till used page number and remaining part of the vector to see how far away the next equivalent value was 
    virtual int placesTill(int page, vector<int> ramain) { return 0; };

protected:
    int pageFaultCount;
    int pageFrameCount;
};

#endif // !PPD_REPLACEMENTALGORITHM_H
