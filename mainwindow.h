#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "svgwindow.h"
#include "paintedwidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createMenu();
public slots:
    void slotOpenFile();
    void slotPaint();

private:
    SvgWindow *svgWindow;
    PaintedWidget *pw;


};

#endif // MAINWINDOW_H
