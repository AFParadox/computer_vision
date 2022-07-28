#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

int main(int, char**) {
    
    Mat img = imread("robocup.jpg");
    namedWindow("Robocup");
    imshow("Robocup", img);
    waitKey(0);

    return 0;
}
