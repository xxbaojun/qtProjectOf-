#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include "QWidget"

class PaintedWidget : public QWidget
{
public:
        PaintedWidget(QWidget *parent = 0);

protected:
        void paintEvent(QPaintEvent *event);
};



#endif // PAINTEDWIDGET_H
