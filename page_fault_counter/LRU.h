/*
* @author zachary benjamin
*/

#ifndef _LRU_H
#define _LRU_H

#include <iostream>
#include "ReplacementAlgorithm.h"
#include <list>

class LRU : public ReplacementAlgorithm {
public:
    LRU(int numPageFrames);
    void insert(int pageNumber) override;
    

private:
    // data structure to store the int page frame list
    //list of int 
    int pageFrames;
    std::list<int> list;
    bool fault;
};

#endif
