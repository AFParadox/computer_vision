#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
    
    Mat img = imread("DL_gurus.jpg");
    namedWindow("Original_img");
    imshow("Original_img", img);
    waitKey(0);

    Mat dst;

    Point2f center(img.rows/2, img.cols/2);
    Mat rotation_matrix = getRotationMatrix2D( center, 90, 1);

    warpAffine(img, dst, rotation_matrix, img.size());

    namedWindow("Rotated_img");
    imshow("Rotated_img", dst);
    waitKey(0);

    return 0;
}