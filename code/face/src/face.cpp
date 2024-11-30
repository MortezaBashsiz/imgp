#include "face.hpp"

face::face() {
}

face::~face() {
}

void face::find(Mat& frame, std::string faceCascadeXml) {
    static cv::CascadeClassifier faceCascade;
    if (faceCascade.empty()) {
        faceCascade.load(faceCascadeXml);
        if (faceCascade.empty()) {
            throw std::runtime_error("Failed to load faceCascade xml");
        }
    }

    Mat grayFrame;
    cv::cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

    std::vector<Rect> faces;
    faceCascade.detectMultiScale(grayFrame, faces, 1.1, 10, 0, Size(30, 30));

    for (const Rect& face: faces) {
        cv::rectangle(grayFrame, face, Scalar(255, 0, 0), 2);
    }
    frame = grayFrame;
}