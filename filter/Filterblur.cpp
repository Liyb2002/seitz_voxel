#include "FilterBlur.h"
#include <iostream>
#include "glm.hpp"


FilterBlur ::FilterBlur(){
}

FilterBlur::~FilterBlur()
{
}




void FilterBlur::startWork(Canvas2D *canvas,
                       std::vector<RGBA> data1, std::vector<RGBA> data2,
                       std::vector<RGBA> data3) {

 //   std::cout << "canvas height" << canvas->height() << std::endl;
 //   std::cout << "canvas width" << canvas->width() << std::endl;

  //  showColor(data1);

    //only start create box when we have three images
    if(data1.size() > 1 && data2.size()>1 && data3.size()>1){
        process(canvas, data1,data2,data3);
    }


}

void FilterBlur::process(Canvas2D *canvas, std::vector<RGBA> data1,
                         std::vector<RGBA> data2, std::vector<RGBA> data3){
    RGBA* dataBox = new RGBA[40*72*72];
    std::cout << "Create box!";
    //go through data2
    int planeSize = 40*72;
    for(int i=0; i<data2.size(); i++){
        if(data2[i].r!= 0 || data2[i].g!= 0 || data2[i].b!= 0){
            for(int j=0; j<72; j++){
                dataBox[planeSize*j + i] = data2[i];
            }
        }
    }


}






void FilterBlur::showColor(std::vector<RGBA> data){
    if(data.size() > 2){

    std::cout << "data3 middle" << (float)data[13068].r << std::endl;
    std::cout << "data3 middle" << (float)data[13068].g << std::endl;
    std::cout << "data3 middle" << (float)data[13068].b << std::endl;
        }
}




