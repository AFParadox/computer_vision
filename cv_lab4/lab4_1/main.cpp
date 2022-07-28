#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

struct usr{
    Mat img;
    int *i1;
    int *i2;
};

void onChange1(int pos, void *userdata){

    usr a = *(usr*)userdata;
    *a.i1 = pos;
    Mat edges;
    Canny(a.img, edges, pos, *a.i2);
    imshow("Canny_version", edges);

}

void onChange2(int pos, void *userdata){

    usr a = *(usr*)userdata;
    *a.i2 = pos;
    Mat edges;
    Canny(a.img, edges, *a.i1, pos);
    imshow("Canny_version", edges);

}


int main(int, char**) {

    // TASK 1 ###########################################################################
    //VARS NEEDED
    int i = 100;
    int *value = &i;    //initial value for the trackbars
    void *userdata;
    Mat edges;          //outputarray for canny 
    Mat blurImg;        //outputarray for blurring
    int threshold1 = 100; //thresholds for canny
    int threshold2 = 100; //--------------------
    //-----------
    
    Mat img = imread("street_scene.png");
    namedWindow("Street");
    imshow("Street", img);
    waitKey(0);
 
    //we blur the image before applying Canny
    blur(img, blurImg, Size(3,3));

    //we create and populate the struct to pass the data to the trackbars' callbacks
    usr a;
    a.img = blurImg;
    a.i1 = &threshold1;
    a.i2 = &threshold2;
    userdata = &a;

    Canny(blurImg, edges, threshold1, threshold2);
    namedWindow("Canny_version");

    //TRACKBARS
    createTrackbar("Threshold 1", "Canny_version", value, 1000, onChange1, userdata);
    createTrackbar("Threshold 2", "Canny_version", value, 1000, onChange2, userdata);
    //---------


    imshow("Canny_version", edges);
    waitKey(0);
    //####################################################################################

    // TASK 3 ############################################################################
    Mat img_grayscale, lines;
    cvtColor(img, img_grayscale, COLOR_BGR2GRAY);
    HoughLines(img_grayscale, lines, 1, CV_PI/180, 50);

    return 0;
}
