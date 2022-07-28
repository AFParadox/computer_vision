#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "minmax_filters.hpp"

using namespace std;
using namespace cv;

Mat max_filter(int kernel_size, Mat img){

    //check kernel_size is odd
    if(kernel_size % 2 == 0){
        cout << "kernel size must be odd!\n";

        return img;
    }

    //create new object that we'll populate with the values we'll compute
    Mat new_img;
    img.copyTo(new_img); //
    //creating a variable for storing the max value found in the kernel
    uchar max = 0;
    //first 2 cycles explore the whole image
    for(int i=0; i < img.rows; i++){

        for(int j=0; j < img.cols; j++){
            
            //we set max as the value of the current pixel
            max = img.at<uchar>(i,j);

            //next 2 cycles explore the kernel of the current pixel
            for(int m = i - kernel_size/2; m <= i + kernel_size/2; m++){

                if(m < 0 || m >= img.rows) {continue;} //check that we don't try to access pixels outside the image
                for(int n = j - kernel_size/2; n <= j + kernel_size/2; n++){

                    if(n < 0 || n >= img.cols) {continue;} //check that we don't try to access pixels outside the image
                    
                    //if the current pixel of the kernel has higher value that the one stored in max we replace it
                    if(img.at<uchar>(m,n) > max) {max = img.at<uchar>(m,n);}

                }

            }
            //update the value of the pixel
            new_img.at<uchar>(i,j) = max;
            
        }

    }

    return new_img;
}

Mat min_filter(int kernel_size, Mat img){

    //check kernel_size is odd
    if(kernel_size % 2 == 0){
        cout << "kernel size must be odd!\n";

        return img;
    }

    //create new object that we'll populate with the values we'll compute
    Mat new_img;
    img.copyTo(new_img); //
    //creating a variable for storing the min value found in the kernel
    uchar min;
    //first 2 cycles explore the whole image
    for(int i=0; i < img.rows; i++){

        for(int j=0; j < img.cols; j++){
            
            //we set min as the value of the current pixel
            min = img.at<uchar>(i,j);
            //next 2 cycles explore the kernel of the current pixel
            for(int m = i - kernel_size/2; m <= i + kernel_size/2; m++){

                if(m < 0 || m >= img.rows) {continue;}//check that we don't try to access pixels outside the image
                for(int n = j - kernel_size/2; n <= j + kernel_size/2; n++){

                    if(n < 0 || n >= img.cols) {continue;}//check that we don't try to access pixels outside the image
                    //if the current pixel of the kernel has smaller value that the one stored in min we replace it
                    if(img.at<uchar>(m,n) < min) {min = img.at<uchar>(m,n);}

                }

            }
            //update the value of the pixel
            new_img.at<uchar>(i,j) = min;
            
        }

    }

    return new_img;
}