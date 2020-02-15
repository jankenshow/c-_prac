#include <opencv2/opencv.hpp>

int main(){
    cv::Mat a = cv::imread("../data/img.png", 1); 
    cv::imshow("hello", a); 
    cv::waitKey();
}
