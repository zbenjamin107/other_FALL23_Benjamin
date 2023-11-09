#ifndef _FIFO_H
#define _FIFO_H

#include <iostream>
#include "ReplacementAlgorithm.h"

class FIFO : public ReplacementAlgorithm {
public:
    FIFO(int numPageFrames);
    void insert(int pageNumber) override;
    
private:
    // data structure to store the int page frame list
    //list of ints to hold page numbers 
    int pageFrames;
    std::list<int> list;
    bool fault;
};

#endif
