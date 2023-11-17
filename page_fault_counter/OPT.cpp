/*
* @author zachary benjamin
*/

#include "OPT.h"

OPT::OPT(int numberPageFrames) : ReplacementAlgorithm(numberPageFrames) {
	pageFaultCount = 0;
	pageFrames = numberPageFrames;

}

void OPT::insertOPT(int pageNumber, vector<int> remain) {
    int greatestLength = 0;
    std::list<int>::iterator indexToRemove;
    std::list<int>::iterator indexOfList = list.begin();
    fault = true;       //assume there will be a fault
    
    for (int i : list) {//loops through the pages and test to see if it is on the list(page frame) already 
        if (i == pageNumber) {
            return;     //if it exist in the list(page frames) then there is no need to do anything 
        }
    }

    if (fault) {//if there is a page fault we need to add the new one and remove the one that will not occure for the longest time
        ++pageFaultCount;           //add to the number of page faults      
        
        
        if (list.size() == pageFrames ) {//if the list is full we want to start taking old pages off the list(page frame)
            for (int i : list) {            //loop through our list and check to see distance till next one in the remaining vector
                
                if (placesTill(i, remain) == -1) {//if it doesnt exist in the remaining vector then remove this from the list and be done
                    list.erase(indexOfList);
                    list.push_front(pageNumber);
                    return;
                }
                else if (placesTill(i,remain) > greatestLength ) {
                    indexToRemove = indexOfList;
                    greatestLength = placesTill(i, remain);
                }
                if(indexOfList != list.end()) ++indexOfList;
            }
            list.erase(indexToRemove);
        }
        list.push_front(pageNumber);//add to the front of the list. doesnt actually matter where it goes if done right
    } 
}



//this function will return the places till a page occurs in the remaining part of the vector. If it doesn't, then it return -1
int OPT::placesTill(int page, vector<int> remain) {
    int placesTill = 0;     //start at 0
    for (int i : remain) {  //for page in ramaining reference vector
        if (i == page) {    //if the page is the same then return the placeTill holder
            return placesTill;
        }
        ++placesTill;       //next place
    }
    return -1 ;             //if it is not found, return -1
} 
