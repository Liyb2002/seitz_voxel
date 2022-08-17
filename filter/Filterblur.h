
#include "Filter.h"

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



};

