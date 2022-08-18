
#include "Filter.h"
#include "glm.hpp"

class FilterBlur : public Filter {
public:
    FilterBlur();
    virtual ~FilterBlur() override;

    void Convolve2D(Canvas2D *canvas, std::vector< int > conv);

    void startWork(Canvas2D *canvas, std::vector<RGBA>data1,
              std::vector<RGBA>data2, std::vector<RGBA>data3);

    void showColor(std::vector<RGBA>data2);

    void process(Canvas2D *canvas,std::vector<RGBA>data1,
                 std::vector<RGBA>data2, std::vector<RGBA>data3);

    float rayMarch(glm::vec3 ro, glm::vec3 rd, RGBA* dataBox);

    void render(Canvas2D *canvas, RGBA* dataBox);

    void checkBox(Canvas2D *canvas, RGBA* dataBox);




};

