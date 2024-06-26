#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <thread>

using namespace cv;
using namespace std;


int main(){
    string ascii = " .!/?&W#@M";
    VideoCapture cap("video.mp4");

    double fps = cap.get(CAP_PROP_FPS);

    int frame_duration = 1000 / fps;

    Mat frame, resized_frame;
    while(1){

        cap >> frame;  

        resize(frame, resized_frame, Size(), 0.5, 0.5, INTER_CUBIC);

        string frame_ascii = "";

        for(int i = 0; i < resized_frame.rows; i++){
            for(int j = 0; j < resized_frame.cols; j++){
                frame_ascii += ascii[floor(((resized_frame.at<Vec3b>(i,j)[0]+resized_frame.at<Vec3b>(i,j)[1]+resized_frame.at<Vec3b>(i,j)[2])/3)/(255/ascii.length())-1 )];
            }
            frame_ascii += "\n";   
        }

        system("clear");
        std::cout << frame_ascii;
        std::this_thread::sleep_for(std::chrono::milliseconds(frame_duration));

    }

    return 0;
}
