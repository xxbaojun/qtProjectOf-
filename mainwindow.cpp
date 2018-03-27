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

    QMenu *fileMenu = menuBar ()->addMenu (QString::fromLocal8Bit("�ļ�"));
    QAction *openAct = new QAction(QString::fromLocal8Bit("�ļ�"), this);
    connect (openAct, SIGNAL(triggered(bool)), this, SLOT(slotOpenFile()));
    fileMenu->addAction(openAct);

    QMenu *paintMenu = menuBar()->addMenu(QString::fromLocal8Bit("��ͼ"));
    QAction *paintAct = new QAction(QString::fromLocal8Bit("��ͼ"),this);
    connect (paintAct, SIGNAL(triggered(bool)), this, SLOT(slotPaint()));
    paintMenu->addAction(paintAct);

}


void MainWindow::slotOpenFile ()
{
    QString name = QFileDialog::getOpenFileName (this,QString::fromLocal8Bit("���ļ�"), "/", "svg file(*.svg)");
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
