#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/hal/interface.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

    Mat vertical_g = Mat(256, 256, CV_8U);
    Mat horizontal_g = Mat(256, 256, CV_8U);

    for(int i = 0; i < 256; i++){
        for(int j = 0; j < 256; j++){
            vertical_g.at<uchar>(i,j) = 255 - i;
            horizontal_g.at<uchar>(i,j) = 255 - j;
        }
    }

    namedWindow("Vertical_gradient");
    imshow("Vertical_gradient", vertical_g);
    waitKey(0);
    cout << "Vertical gradient: done" << endl;

    namedWindow("Horizontal_gradient");
    imshow("Horizontal_gradient", horizontal_g);
    waitKey(0);
    cout << "Horizontal gradient: done" << endl;

    Mat chess_20 = Mat(300, 300, CV_8U);
    Mat chess_50 = Mat(300, 300, CV_8U);

    for (int i = 0; i < 300; i++){
        for(int j = 0; j < 300; j++){

            if((((i / 20) % 2)+((j / 20) % 2)) % 2 == 0){
                chess_20.at<uchar>(i,j) = 255;
            }else{
                chess_20.at<uchar>(i,j) = 0;
            }

            if((((i / 50) % 2)+((j / 50) % 2)) % 2 == 0){
                chess_50.at<uchar>(i,j) = 255;
            }else{
                chess_50.at<uchar>(i,j) = 0;
            }

        }
    }

    namedWindow("chessboard_20");
    imshow("chessboard_20", chess_20);
    waitKey(0);
    cout << "Chessboard - Size 20: done" << endl;

    namedWindow("chessboard_50");
    imshow("chessboard_50", chess_50);
    waitKey(0);
    cout << "Chessboard - Size 50: done" << endl;


    return 0;
}