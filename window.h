
#ifndef WINDOW_H
#define WINDOW_H
#include <QPoint>
#include "matrix.h"




class Window
{
public:
    Window();
    QPoint convertToViewport(int x_w, int y_w, int x_wmax, int y_wmax, int x_wmin, int y_wmin, int x_vmax, int y_vmax, int x_vmin, int y_vmin);
};

#endif // WINDOW_H
