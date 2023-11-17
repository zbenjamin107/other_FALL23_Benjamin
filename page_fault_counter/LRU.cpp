/*
* @author zachary benjamin
*/
#include "LRU.h"

LRU::LRU(int numPageFrames) : ReplacementAlgorithm(numPageFrames) {
    pageFaultCount = 0;
    pageFrames = numPageFrames;
}

void LRU::insert(int pageNumber)
{
    // Implement FIFO page replacement algorithm 
    // Increment pageFaultCount if a page fault occurs

    fault = true;       //assume there will be a fault    
    for (int i : list) {//loops through the pages and test to see if it is on the list already         
        
        if (i == pageNumber) {
            fault = false;  //if we do find a match we will set page fault to false
            if (list.size() == pageFrames ) {
                list.remove(pageNumber);//indexOf = list.erase(indexOf);
                   
            }
            list.push_front(pageNumber);
            return;            
        }               
    }

    if (fault) {//if there is a page fault add to page faults and push the new page
        ++pageFaultCount;
        list.push_front(pageNumber);
        if (list.size() == pageFrames + 1) list.pop_back();//this makes sure we add to list until it is size 4
    }

    //else..nothing. we dont arrange the order. we dont add

}


