#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


int main(){
    string ascii = " .!/?&W#@MMM";
    string path = "image.png";
    Mat img = imread(path);
    Mat imge = imread(path);
    
    //frame to ASCII converter
    for(int i = 0; i < img.rows; i++){
        vector<double> temp;
        for(int j = 0; j < img.cols; j++){
            cout << ascii[floor(((img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3)/(255/ascii.length()))];
        }
        cout << "\n";
    }

    imshow("mod", img);
    imshow("org", imge);
    waitKey(0);

    return 0;
}