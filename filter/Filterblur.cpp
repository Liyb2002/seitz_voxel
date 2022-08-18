#include "FilterBlur.h"
#include <iostream>
#include "glm.hpp"


FilterBlur ::FilterBlur(){
}

FilterBlur::~FilterBlur()
{
}




void FilterBlur::startWork(Canvas2D *canvas,
                       std::vector<RGBA> data1, std::vector<RGBA> data2
                       ) {

 //   std::cout << "canvas height" << canvas->height() << std::endl;
 //   std::cout << "canvas width" << canvas->width() << std::endl;

  //  showColor(data1);

    //only start create box when we have three images
    std::cout <<"Startwork" <<std::endl;

    if(data1.size() > 1 && data2.size()>1){
        process(canvas, data1,data2);
    }


}

void FilterBlur::process(Canvas2D *canvas, std::vector<RGBA> data1,
                         std::vector<RGBA> data2){
    int inputWidth = canvas -> width();
    int inputHeight = canvas -> height();
    std::cout << "inputWidth" << inputWidth << std::endl;
    std::cout << "inputHeight" << inputHeight << std::endl;

    RGBA* dataBox = new RGBA[inputHeight*inputWidth*inputWidth];
    int planeSize = inputHeight*inputWidth;
    std::cout << "Create box!";

    //go through data2, which is the front face
    for(int i=0; i<data2.size(); i++){
        if(data2[i].r!= 0 || data2[i].g!= 0 || data2[i].b!= 0){
            for(int j=0; j<inputWidth; j++){
                dataBox[planeSize*j + i] = data2[i];
            }
        }
    }

    std::cout << "dataBox.size()" << (float)dataBox[7775000].r;

    //go through data1
    for(int i=0; i<data1.size(); i++){
        int toTop = i/inputWidth;
        int toleft = i%inputWidth;
        if(data1[i].r == 0 && data1[i].g == 0 && data1[i].b == 0){

           for(int j=0; j<inputWidth; j++){
                dataBox[planeSize*(inputWidth-toleft-1) + (toTop-1)*inputWidth + j] = RGBA(0,0,0,0);
            }
        }
    }

 //   std::cout << "databox[23232]" << (float)dataBox[23232].r << std::endl;

   render(canvas, dataBox, inputHeight, inputWidth);



    delete [] dataBox;


}

RGBA FilterBlur::rayMarch(glm::vec3 ro, glm::vec3 rd, RGBA* dataBox, int inputHeight, int inputWidth){
//set the front upper left corner as (0,0,0), we have a scene with:

    // x /in (0,71)
    // y /in (0,39)
    // z /in (0,71)

    //goal: uvz' coordinate -> xyz coordinate -> dataBox position

    //step1: u(-0.5,0.5) -> x(0,71)
    //x = (u+0.5) * 72, y = (0.5-v) * 40, z = z'*72

    //step2: xyz -> dataBox
    //i = x + y*72 + z*40*72

 //    std::cout << "databox[986]" << (float)dataBox[986].r << std::endl;
 //   std::cout << "rd is" << rd.x << " " << rd.y <<" " << rd.z << std::endl;

    float depth = 0.0;
    for(int i=0; i<10; i++){
        glm::vec3 p = ro + depth * rd;
  //      std::cout << "p is" << p.x << " " << p.y <<" " << p.z << std::endl;

        //step1: uvz' -> xyz
        float x = (p.x+0.5) * inputWidth;
        float y = (0.5-p.y) * inputHeight;
        float z = p.z * inputWidth;

        //step2: xyz -> dataBox
        int dataPos = (int)x + (int)y*inputWidth + (int)z*inputHeight*inputWidth;
         if(0 < dataPos < inputHeight*inputWidth*inputWidth){
             if( (float)dataBox[dataPos].r != 0){
             //    std::cout <<"red is "<< (float)dataBox[dataPos].r <<std ::endl;
             //    std::cout <<"g is "<< (float)dataBox[dataPos].g <<std ::endl;
             //    std::cout <<"b is "<< (float)dataBox[dataPos].b <<std ::endl;

                 return dataBox[dataPos];
             }
         }


        depth += 0.1;
}

 //   std:: cout<<"nothing" <<std ::endl;
    return RGBA(0,0,0,0);

}

void FilterBlur::render(Canvas2D *canvas, RGBA* dataBox, int inputHeight, int inputWidth){
  //  std::cout << "databox[986]" << (float)dataBox[986].r << std::endl;
     std::cout << "render!";

     int size = inputWidth * inputHeight;
     RGBA* pix0 = canvas->data();

     for(int i=0; i<size; i++){
         pix0[i] = RGBA(0,0,0,0);
     }
     canvas -> update();


    RGBA* pix = canvas->data();
    glm::vec3 ro = glm::vec3(0.1, 0.1, -0.5);
    for(int i=0; i<size; i++){


        float x = (float)(i%canvas->width() - canvas->width()/2)/inputWidth;
        float y = (float)(canvas->height()/2 - i/canvas->width() )/inputHeight;

        glm::vec3 rd = glm::normalize(glm::vec3(x, y, 1));

        pix[i] = rayMarch(ro, rd, dataBox, inputHeight, inputWidth );




    }
    canvas->update();

}
/*
void FilterBlur::checkBox(Canvas2D *canvas, RGBA* dataBox){
    RGBA *pix = canvas->data();
    for(int i=0; i<canvas->width()*canvas->height();i++){
        int intersect = 0;
        for(int j=0; j<72; i++){
            if(dataBox[j*72*40 + i].r != 0){

               intersect=1;
               break;
            }
        }
        if(intersect ==1){
            pix[i] = RGBA(255,0,0,0);
        }

    }

    canvas -> update();
}
*/
Canvas2D FilterBlur::removeAll(Canvas2D *canvas){
    std:: cout <<"remove all color" <<std::endl;
    int size = canvas->width() * canvas->height();
    RGBA* pix = canvas->data();

    for(int i=0; i<size; i++){
        pix[i] = RGBA(0,0,0,0);
    }
    canvas -> update();

}




void FilterBlur::showColor(std::vector<RGBA> data){
    if(data.size() > 2){

    std::cout << "data3 middle" << (float)data[13068].r << std::endl;
    std::cout << "data3 middle" << (float)data[13068].g << std::endl;
    std::cout << "data3 middle" << (float)data[13068].b << std::endl;
        }
}




