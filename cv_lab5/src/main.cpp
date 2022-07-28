#include <iostream>
#include <fstream>
#include "lab5_tasks.hpp"
#include <stdexcept>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {

    Mat img = imread("../doc/Asphalt-1.png");
    namedWindow("img");
    imshow("img", img);
    waitKey(0);
    
    if(argc != 3){
        throw invalid_argument("Usage: <path>/cv_lab5 <task> <path/to/image>");
    }

    FILE *file;
    string filename = argv[2];

    if(!(file = fopen(argv[2], "r"))){
        throw invalid_argument(filename + " not found.");
    }
    fclose(file);

    int task = 0;
    if(isdigit(*argv[1])){
        task = std::stoi(argv[1]);
    }

    switch(task){
        case 1:
            task1(filename);
            break;
        case 2:
            task2(filename);
            break;
        case 3:
            task3(filename);
            break;
        default:
            throw std::invalid_argument("The task number must be an integer 1-3.");
            break;
    }
}
