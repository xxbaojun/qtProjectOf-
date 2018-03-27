#include "mainwindow.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle (tr("SVG Viewer"));
    createMenu ();


    svgWindow = new SvgWindow;
    setCentralWidget (svgWindow);

}


void MainWindow::createMenu ()
{

    QMenu *fileMenu = menuBar ()->addMenu (QString::fromLocal8Bit("文件"));
    QAction *openAct = new QAction(QString::fromLocal8Bit("文件"), this);
    connect (openAct, SIGNAL(triggered(bool)), this, SLOT(slotOpenFile()));
    fileMenu->addAction(openAct);

    QMenu *paintMenu = menuBar()->addMenu(QString::fromLocal8Bit("画图"));
    QAction *paintAct = new QAction(QString::fromLocal8Bit("画图"),this);
    connect (paintAct, SIGNAL(triggered(bool)), this, SLOT(slotPaint()));
    paintMenu->addAction(paintAct);

}


void MainWindow::slotOpenFile ()
{
    QString name = QFileDialog::getOpenFileName (this,QString::fromLocal8Bit("打开文件"), "/", "svg file(*.svg)");
    svgWindow->setFile (name);
}
void MainWindow::slotPaint ()
{
    PaintedWidget *pw = new PaintedWidget();
    pw->show();
}

MainWindow::~MainWindow()
{

}
