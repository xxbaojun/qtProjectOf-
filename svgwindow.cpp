#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent)
    : QScrollArea(parent)
{
    svgWidget = new SvgWidget;
    setWidget (svgWidget);
}


void SvgWindow::setFile (QString fileName)
{

    svgWidget->load (fileName);

    QSvgRenderer *render = svgWidget->renderer ();

    svgWidget->resize (render->defaultSize ());

}


void SvgWindow::mousePressEvent (QMouseEvent *event)
{
    mousePressPos = event->pos ();
    scrollBarValueOnMousePress.rx () = horizontalScrollBar ()->value ();
    scrollBarValueOnMousePress.ry () = verticalScrollBar ()->value ();

    event->accept ();
}


void SvgWindow::mouseMoveEvent (QMouseEvent *event)
{


    horizontalScrollBar ()->setValue (scrollBarValueOnMousePress.x () - event->pos ().x () + mousePressPos.x ());

    verticalScrollBar ()->setValue (scrollBarValueOnMousePress.y () - event->pos ().y () + mousePressPos.y ());
    horizontalScrollBar ()->update ();
    verticalScrollBar ()->update ();
    event->accept ();
}
