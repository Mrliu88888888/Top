#include <opencv2/opencv.hpp>

#if 0
#    define CAPTURE_SOURCE 0
#else
#    define CAPTURE_SOURCE R"(D:\LiuMeng\Admin\Study\Pr\Pr.mp4)"
#endif

int main()
{
    cv::VideoCapture cap;
    if (cap.open(CAPTURE_SOURCE)) {
        cv::Mat frame;
        for (;;) {
            cap >> frame;
            if (frame.empty()) {
                continue;
            }
            cv::imshow("v", frame);
            if (cv::waitKey(1) == 'q') {
                break;
            }
        }
    }
    cap.release();

    return 0;
}
