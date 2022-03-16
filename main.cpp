#include <opencv2/opencv.hpp>
#include <iostream>

int main ()
{
  cv::Mat Frame; //Declare the matrix for the video frame
  cv::namedWindow("Video Capture");

  cv::VideoCapture capture(0);

  if (!capture.isOpened())
  {
    std::cout << "No Video stream available" << std::endl;
    std::system("pause");
  
    return -1;
  }

  while (true)
  {
    capture >> Frame;

    if (Frame.empty())
      break;

    cv::imshow("Video Capture", Frame);
    char c = (char) cv::waitKey(25);

    if (c == 27)
      break;
  }

  capture.release();
  return 0;
}