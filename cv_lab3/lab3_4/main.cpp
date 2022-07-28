#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat img;

static void onMouse(int event, int x, int y, int, void*){

    Vec3b p;
    float meanB = 0;
    float meanG = 0;
    float meanR = 0;
    int neighborhood = 0;
    int T = 50;
    Mat mask;
    img.copyTo(mask);
    Vec3b pixel;

    if(event == EVENT_LBUTTONDOWN){
        p = img.at<Vec3b>(x,y);
        for(int i = x-4; i <= x+4; i++){
            
            if(i < 0 || i >= img.cols) {continue;}
            for(int j = y-4; j <= y+4; j++){

                if(j < 0 || j >= img.rows) {continue;}
                meanB += (int)img.at<Vec3b>(i,j)[0];
                meanG += (int)img.at<Vec3b>(i,j)[1];
                meanR += (int)img.at<Vec3b>(i,j)[2];
                neighborhood++;
                //cout << "[" << (int)img.at<Vec3b>(i,j)[0] << "," << (int)img.at<Vec3b>(i,j)[1] << "," << (int)img.at<Vec3b>(i,j)[2] << "]" << endl;
            }

        }
        meanB /= neighborhood;
        meanG /= neighborhood;
        meanR /= neighborhood;

        cout << "color: " << p << " - mean: " << "B=" << meanB << " G=" << meanG << " R=" << meanG << endl;

        for(int i = 0; i < img.rows; i++){

            for(int j = 0; j < img.cols; j++){

                pixel = img.at<Vec3b>(i,j);
                if( (abs(pixel[0]-meanB) <= T) && (abs(pixel[1]-meanG) <= T) && (abs(pixel[2]-meanR) <= T)){
                    mask.at<Vec3b>(i,j)[0] = 255;
                    mask.at<Vec3b>(i,j)[1] = 255;
                    mask.at<Vec3b>(i,j)[2] = 255;
                }else{
                    mask.at<Vec3b>(i,j)[0] = 0;
                    mask.at<Vec3b>(i,j)[1] = 0;
                    mask.at<Vec3b>(i,j)[2] = 0;
                }

            }

        }
        namedWindow("Mask", WINDOW_NORMAL);
        imshow("Mask", mask);
        waitKey(0);
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
