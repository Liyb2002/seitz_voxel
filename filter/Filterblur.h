
#include "Filter.h"
#include "glm.hpp"

class FilterBlur : public Filter {
public:
    FilterBlur();
    virtual ~FilterBlur() override;

    void Convolve2D(Canvas2D *canvas, std::vector< int > conv);

    void startWork(Canvas2D *canvas, std::vector<RGBA>data1,
              std::vector<RGBA>data2);

    void showColor(std::vector<RGBA>data2);

    void process(Canvas2D *canvas,std::vector<RGBA>data1,
                 std::vector<RGBA>data2);

    RGBA rayMarch(glm::vec3 ro, glm::vec3 rd, RGBA* dataBox, int inputHeight, int inputWidth);

    void render(Canvas2D *canvas, RGBA* dataBox, int inputHeight, int inputWidth);

    void checkBox(Canvas2D *canvas, RGBA* dataBox);

    Canvas2D removeAll(Canvas2D *canvas);





};

