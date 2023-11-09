// testPR.cpp
// Patrick P. Dudenhofer
// CS3310 - Operating System
// Page Replacement
// 2015 October 12
//
// Testing program for the page replacement algorithms.
//

#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "ReplacementAlgorithm.h"
#include "LRU.h"
#include "FIFO.h"
#include "OPT.h"
using namespace std;
std::vector<int> referenceString;
std::vector<int> remain;    //for opt
using namespace std;
const int MAX_PAGE_NUMBER = 100;

// testPR <reference string size> <number of page frames> [fileName]
// The "reference string size" parameter is ignored if a filename is provided.
int main(int argc, char** argv)
{
    int count;
    int numPageFrames;
    bool useRefFile = false;
    std::string fileName = "";
    std::ifstream in;

    srand((unsigned int)time(0));

    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0]
            << " <reference string size> <number of page frames> "
            << "[reference string filename]"
            << std::endl;
        exit(1);
    }

    count = atoi(argv[1]);
    numPageFrames = atoi(argv[2]);

    // input reference string from file or just randomly generate
    if (argc == 4) {
        useRefFile = true;

        //open the input file
        in.open(argv[3]);
        if (!in.is_open()) {
            std::cerr << "Error opening file " << fileName
                << ". Exiting..." << std::endl;
            exit(1);
        }

        int n;
        while (!in.eof())
        {
            in >> n;
            if (n >= 0 && n < MAX_PAGE_NUMBER) {
                
                referenceString.push_back(n);
            }
        }
        in.close();
    }
    else {
        for (int i = 0; i < count; i++) {
            referenceString.push_back(rand() % MAX_PAGE_NUMBER);
        }
    }

    ReplacementAlgorithm* lru = new LRU(numPageFrames); 
    ReplacementAlgorithm* fifo = new FIFO(numPageFrames);
    ReplacementAlgorithm* opt = new OPT(numPageFrames); //EXTRA CRERDIT
    remain = referenceString;   //create another vector that will be the remaining part of the vector

    for (int i : referenceString) {
        lru->insert(i);
        fifo->insert(i);
        opt->insertOPT(i,remain); // EXTRA CREDIT. 
        
        remain.erase(remain.begin()); // everytime one element from the vector is passed we will remove the front of copy to keep trac of remaining     
        
    }

    
    std::cout << "LRU faults  = " << lru->getPageFaultCount() << std::endl;
    std::cout << "FIFO faults = " << fifo->getPageFaultCount() << std::endl;
    std::cout << "OPT faluts = " << opt->getPageFaultCount() << std::endl;  // PRINTS THE EXTRA CREDIT PART

    return 0;
}
// TEST CASES FOR referece_string.txt

// 1 3 0 3 5 6 3 FIFO=6
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1 FIFO=15, OPT=9(notes), LRU=12
// 3 1 2 1 6 5 1 3 LRU=6
// 0 1 2 3 0 1 4 0 1 2 3 4 LRU=10
// 1 2 3 4 1 2 5 1 2 3 4 5 FIFO 3pageframe=9, 4pageFrame=10(notes)
// 7 0 1 2 0 3 0 4 2 3 0 3 2 3 OPT=6(4page frames)
// 1 2 3 2 1 4 3 5 6 4 3 5 3 5 6 7 2 1 5 7 OPTIMAL=10,FIFO=12,LRU=16

 

