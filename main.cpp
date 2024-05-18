#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdio.h>
#include <iostream>


//This is a picture to ASCII converter i made.
//Now i'll just have to remake it so it can capture a video from webcamera
//and than convert the frames from the captured video


using namespace cv;
using namespace std;


int main(){
    string ascii = "  .!/?&W#@M";
    string path = "das.png";
    Mat img = imread(path);
    Mat imge = imread(path);
    
    for(int i = 0; i < img.rows; i++){
        vector<double> temp;
        for(int j = 0; j < img.cols; j++){
            cout << ascii[floor(((img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3)/(255/ascii.length()))]; //I dont even know how a made this abomination of a line
        }
        cout << "\n";
    }

    imshow("mod", img);
    imshow("org", imge);
    waitKey(0);

    return 0;
}
