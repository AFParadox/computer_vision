#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

struct usr{
    Mat img;
    int *i1;
    int *i2;
};

void changeThresh(int pos, void *userdata){

    usr a = *(usr*)userdata;
    *a.i1 = pos;
    Mat new_img;
    //Canny(a.img, edges, pos, *a.i2);
    threshold(a.img, new_img, *a.i1, *a.i2, THRESH_BINARY);
    imshow("threshold", new_img);

}

void changeMaxVal(int pos, void *userdata){

    usr a = *(usr*)userdata;
    *a.i2 = pos;
    Mat new_img;
    //Canny(a.img, edges, *a.i1, pos);
    threshold(a.img, new_img, *a.i1, *a.i2, THRESH_BINARY);
    imshow("threshold", new_img);

}

int main(int, char**) {
    int thresh = 1;
    int maxval = 128;
    int i = 0;
    int *value = &i;
    usr a;
    
    
    Mat img1 = imread("../doc/Asphalt-1.png", IMREAD_GRAYSCALE);
    Mat img2 = imread("../doc/Asphalt-2.png");
    Mat img3 = imread("../doc/Asphalt-3.png");
    namedWindow("img1");
    imshow("img1", img1);
    waitKey(0);

    Mat new_img;
    threshold(img1, new_img, thresh, maxval, THRESH_BINARY);
    namedWindow("threshold");

    a.img = new_img;
    a.i1 = &thresh;
    a.i2 = &maxval;
    void *userdata = &a;

    //TRACKBARS
    createTrackbar("Threshold", "threshold", value, 255, changeThresh, userdata);
    createTrackbar("MaxVal", "threshold", value, 255, changeMaxVal, userdata);
    //---------

    imshow("threshold", new_img);
    waitKey(0);

    

    return 0;
}
