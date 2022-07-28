#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <panoramic_utils.h>

using namespace cv;
using namespace std;

int main() {
    
    //JUST SOME STUFF----------------------------------------------------
    Mat img = imread("../Datasets/dataset_dolomites/dolomites/i01.png");
    Mat new_img = cylindricalProj(img, 27);

    namedWindow("img");
    imshow("img", img);
    waitKey(0);

    namedWindow("new_img");
    imshow("new_img", new_img);
    waitKey(0);
    //-------------------------------------------------------------------

    

    return 0;
}
