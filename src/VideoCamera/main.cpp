#include <opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture cap;
    if (cap.open(0)) {
        cv::Mat frame;
        for (;;) {
            cap >> frame;
            if (frame.empty()) {
                continue;
            }
            cv::imshow("v", frame);
            if (cv::waitKey() == 'q') {
                break;
            }
        }
    }
    cap.release();

    return 0;
}
