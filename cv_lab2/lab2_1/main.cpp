#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int, char**) {

    Mat img = imread("image.jpg");
    namedWindow("original_Img");
    imshow("original_Img", img);
    waitKey(0);

    Mat img_grayscale;
    cvtColor(img, img_grayscale, COLOR_BGR2GRAY, 1);
    namedWindow("grayscale_Img");
    imshow("grayscale_Img", img_grayscale);
    waitKey(0);

    imwrite("image_grayscale.jpg", img_grayscale);

    return 0;
}
