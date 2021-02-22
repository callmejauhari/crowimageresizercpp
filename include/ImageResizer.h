/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImageResizer.h
 * Author: ped
 *
 * Created on February 22, 2021, 6:03 AM
 */

#ifndef IMAGERESIZER_H
#define IMAGERESIZER_H
#include <cstdlib>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
using namespace cv;

class ImageResizer {
public:
    ImageResizer();
    ImageResizer(const ImageResizer& orig);
    virtual ~ImageResizer();

    bool ResizeImage(std::string& base64Image, long width, long height);
private:
    std::string base64_decode(std::string const& encoded_string);
    std::string base64_encode(uchar const* bytes_to_encode, unsigned int in_len);
    static inline bool is_base64(unsigned char c);
};

#endif /* IMAGERESIZER_H */

