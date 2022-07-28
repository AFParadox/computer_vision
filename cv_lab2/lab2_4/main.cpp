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

    Mat histogram;
    int histSize = 256;
    float range[] = { 0, 256 } ; //the upper boundary is exclusive
    const float* histRange = { range };
    calcHist(&img_grayscale, 1, 0, Mat(), histogram, 1, &histSize, &histRange);

    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );

    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar(255,255,255));

    normalize(histogram, histogram, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for(int i = 1; i < histSize; i++){
        line(histImage, Point( bin_w*(i-1), hist_h - cvRound(histogram.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(histogram.at<float>(i)) ),
                       Scalar( 0, 0, 0), 2, 8, 0);
    }

    namedWindow("Histogram");
    imshow("Histogram", histImage);
    waitKey(0);

    return 0;
}