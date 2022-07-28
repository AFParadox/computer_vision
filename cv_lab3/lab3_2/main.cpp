#include <iostream>
#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat img;

static void onClick( int event, int x, int y, int, void* ){

    if(event == EVENT_LBUTTONDOWN){
        cout << "Point clicked: (" << x << "," << y << ") -> ";
        Vec3b p = img.at<Vec3b>(x,y);
        cout << "BGR = " << p << endl;
    }

}

int main(int, char**) {
    
    img = imread("robocup.jpg");
    namedWindow("Robocup");
    setMouseCallback("Robocup", onClick, 0);
    imshow("Robocup", img);
    waitKey(0);

    

    return 0;
}
