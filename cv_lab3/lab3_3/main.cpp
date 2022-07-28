#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

Mat img;

static void onMouse(int event, int x, int y, int, void*){

    Vec3b p;
    double meanB = 0;
    double meanG = 0;
    double meanR = 0;
    int neighborhood = 0;
    if(event == EVENT_LBUTTONDOWN){
        p = img.at<Vec3b>(x,y);
        for(int i = x-4; i <= x+4; i++){
            
            if(i < 0 || i >= img.cols) {continue;}
            for(int j = y-4; j <= y+4; j++){

                if(j < 0 || j >= img.rows) {continue;}
                meanB += img.at<Vec3b>(i,j)[0];
                meanG += img.at<Vec3b>(i,j)[1];
                meanR += img.at<Vec3b>(i,j)[2];
                neighborhood++;
            }

        }
        
        cout << "Pixel (" << x << "," << y << ") - ";
        cout << "value: " << p << " Pixels explored: " << neighborhood;
        cout << " B: "<< meanB/neighborhood << " G: " << meanG/neighborhood << " R: " << meanR/neighborhood << endl;
    }

}

int main(int, char**) {
    
    img = imread("robocup.jpg");
    namedWindow("Robocup");
    setMouseCallback("Robocup", onMouse);
    imshow("Robocup", img);
    waitKey(0);

    return 0;
}
