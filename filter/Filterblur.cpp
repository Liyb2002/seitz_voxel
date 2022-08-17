#include "FilterBlur.h"
#include <iostream>
#include "glm.hpp"


FilterBlur ::FilterBlur(){
    std::vector<RGBA> *data1;
    std::vector<RGBA> *data2;
}

FilterBlur::~FilterBlur()
{
}




void FilterBlur::read(Canvas2D *canvas,
                       std::vector<RGBA> data1, std::vector<RGBA> data2,
                       std::vector<RGBA> data3) {

   // std::cout << "canvas height" << canvas->height() << std::endl;
  //  std::cout << "canvas width" << canvas->width() << std::endl;

    showColor(data1);






    }





void FilterBlur::showColor(std::vector<RGBA> data){
    if(data.size() > 2){

    std::cout << "data3 middle" << (float)data[13068].r << std::endl;
    std::cout << "data3 middle" << (float)data[13068].g << std::endl;
    std::cout << "data3 middle" << (float)data[13068].b << std::endl;
        }
}




