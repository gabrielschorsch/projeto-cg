#include "window.h"

Window::Window()
{

}


QPoint Window::convertToViewport(int x_w, int y_w, int x_wmax, int y_wmax, int x_wmin, int y_wmin, int x_vmax, int y_vmax, int x_vmin, int y_vmin){

    int x_v, y_v;


    x_w =  x_w + (x_wmax - x_wmin) / 2;
    y_w = y_w + (y_wmax - y_wmin) / 2;

    // scaling factors for x coordinate and y coordinate
    float sx, sy;

    // calculating Sx and Sy
    sx = (float)(x_vmax - x_vmin) / (x_wmax - x_wmin);
    sy = 1 - (float)(y_vmax - y_vmin) / (y_wmax - y_wmin);

    // calculating the point on viewport
    x_v = (float)((x_w - x_wmin) * sx);
    y_v = ((float)((y_w - y_wmin)) * sy);
    QPoint p = QPoint(x_v,y_v);
    return p;
}
