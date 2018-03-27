#include "paintedwidget.h"
#include "QPainter"
#include "digit2.h"
#include <QTimer>
#include <QTime>
//#include <synchapi.h>
//#include <Qsy
#include <QCoreApplication>
void waitSec(int s)
{
//#ifdef WIN32
//        Sleep(1000);
//#else
//        sleep(1);
//#endif

    QTime t;
    t.start();
    while(t.elapsed()<1000*s)
        QCoreApplication::processEvents();
}




PaintedWidget::PaintedWidget(QWidget *parent):QWidget(parent)
{
    resize(800, 600);
    setWindowTitle(tr("Paint Demo"));
}


void PaintedWidget::paintEvent(QPaintEvent *event)
{


    QPainter painter(this);
    painter.drawLine(80, 100, 650, 500);
    //painter.drawText(80,100,QString::fromLocal8Bit("时间26是这样999吧"));
    //painter.drawText(80,100,QString::fromLocal8Bit("第二段字"));   会造成重叠

    painter.drawLine(80, 98, 98, 98);

    QPoint startPoint(80,100);

    drawDigit(startPoint,painter,18,'0');
    drawDigit(startPoint,painter,18,'1','0');
    drawDigit(startPoint,painter,18,'2','1');
    drawDigit(startPoint,painter,18,'3','2');
    drawDigit(startPoint,painter,18,'4','3');
    drawDigit(startPoint,painter,18,'5','4');
    drawDigit(startPoint,painter,18,'6','5');
    drawDigit(startPoint,painter,18,'9','6');
    drawDigit(startPoint,painter,18,'8','9');
    //drawDigit(startPoint,painter,18,':','8');
    //for(int i = 0;i<1000;i++)
    //{
    //    char pre = i-1>=0?(i-1)%10+'0':' ';
    //    drawDigit(startPoint,painter,18,i%10+'0',pre);
    //    waitSec(3);
    //}

    //drawDigit(startPoint,painter,18,'1','8');
    QPoint endPoint(650,500);
    drawDigit(endPoint,painter,18,':');

    //painter.setPen(Qt::red);  //杩欎釜
    //painter.drawRect(10, 10, 100, 400);
    //painter.setPen(QPen(Qt::green, 5));
    //painter.setBrush(Qt::blue);
    //painter.drawEllipse(50, 150, 400, 200);

}
