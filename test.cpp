#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


int main(){
    cv::Mat frame = cv::imread("image.png");
    cv::namedWindow("Output", 0);
    cv::namedWindow("Input", 0);

    cv::Mat output;
    
    cv::Mat resized_image(frame.rows *0.5, frame.cols * 0.5, CV_8UC3);

    cv::resize(frame, resized_image, cv::Size(), 0.5, 0.5);

    cv::imshow("Output", output);
    cv::imshow("Input", frame);
    
    cv::waitKey(0);
    return 0;
}
