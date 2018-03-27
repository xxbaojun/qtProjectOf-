#ifndef DIGIT1_H
#define DIGIT1_H

#include "QWidget"
#include "QPainter"

 const char *getSegments(char ch)               // gets list of segments for ch
{
    static const char segments[30][8] =
       { { 0, 1, 2, 4, 5, 6,99, 0},             // 0    0 / O
         { 2, 5,99, 0, 0, 0, 0, 0},             // 1    1
         { 0, 2, 3, 4, 6,99, 0, 0},             // 2    2
         { 0, 2, 3, 5, 6,99, 0, 0},             // 3    3
         { 1, 2, 3, 5,99, 0, 0, 0},             // 4    4
         { 0, 1, 3, 5, 6,99, 0, 0},             // 5    5 / S
         { 0, 1, 3, 4, 5, 6,99, 0},             // 6    6
         { 0, 2, 5,99, 0, 0, 0, 0},             // 7    7
         { 0, 1, 2, 3, 4, 5, 6,99},             // 8    8
         { 0, 1, 2, 3, 5, 6,99, 0},             // 9    9 / g
         { 3,99, 0, 0, 0, 0, 0, 0},             // 10   -
         { 7,99, 0, 0, 0, 0, 0, 0},             // 11   .
         { 0, 1, 2, 3, 4, 5,99, 0},             // 12   A
         { 1, 3, 4, 5, 6,99, 0, 0},             // 13   B
         { 0, 1, 4, 6,99, 0, 0, 0},             // 14   C
         { 2, 3, 4, 5, 6,99, 0, 0},             // 15   D
         { 0, 1, 3, 4, 6,99, 0, 0},             // 16   E
         { 0, 1, 3, 4,99, 0, 0, 0},             // 17   F
         { 1, 3, 4, 5,99, 0, 0, 0},             // 18   h
         { 1, 2, 3, 4, 5,99, 0, 0},             // 19   H
         { 1, 4, 6,99, 0, 0, 0, 0},             // 20   L
         { 3, 4, 5, 6,99, 0, 0, 0},             // 21   o
         { 0, 1, 2, 3, 4,99, 0, 0},             // 22   P
         { 3, 4,99, 0, 0, 0, 0, 0},             // 23   r
         { 4, 5, 6,99, 0, 0, 0, 0},             // 24   u
         { 1, 2, 4, 5, 6,99, 0, 0},             // 25   U
         { 1, 2, 3, 5, 6,99, 0, 0},             // 26   Y
         { 8, 9,99, 0, 0, 0, 0, 0},             // 27   :
         { 0, 1, 2, 3,99, 0, 0, 0},             // 28   '
         {99, 0, 0, 0, 0, 0, 0, 0} };           // 29   empty

    if (ch >= '0' && ch <= '9')
        return segments[ch - '0'];
    if (ch >= 'A' && ch <= 'F')
        return segments[ch - 'A' + 12];
    if (ch >= 'a' && ch <= 'f')
        return segments[ch - 'a' + 12];

    int n;
    switch (ch) {
        case '-':
            n = 10;  break;
        case 'O':
            n = 0;   break;
        case 'g':
            n = 9;   break;
        case '.':
            n = 11;  break;
        case 'h':
            n = 18;  break;
        case 'H':
            n = 19;  break;
        case 'l':
        case 'L':
            n = 20;  break;
        case 'o':
            n = 21;  break;
        case 'p':
        case 'P':
            n = 22;  break;
        case 'r':
        case 'R':
            n = 23;  break;
        case 's':
        case 'S':
            n = 5;   break;
        case 'u':
            n = 24;  break;
        case 'U':
            n = 25;  break;
        case 'y':
        case 'Y':
            n = 26;  break;
        case ':':
            n = 27;  break;
        case '\'':
            n = 28;  break;
        default:
            n = 29;  break;
    }
    return segments[n];
}

 void addPoint(QPolygon &a, const QPoint &p)
{
    uint n = a.size();
    a.resize(n + 1);
    a.setPoint(n, p);
}

 void drawSegment(const QPoint &pos, char segmentNo, QPainter &p,
                                    int segLen, bool erase=false)
{
    //Q_Q(QLCDNumber);
    QPoint ppt;
    QPoint pt = pos;
    int width = segLen/5;

    //const QPalette &pal = q->palette();
    QColor lightColor,darkColor,fgColor;
    if (erase){
        lightColor = QColor(255, 255, 255);  //默认背景是白色的，当需要清除字符时，设置颜色为白色
        darkColor  = lightColor;
        fgColor    = lightColor;
    } else {
        lightColor =  QColor(0, 0, 0);        //亮是黑色
        darkColor  =  QColor(255, 255, 255);  //黑是白色
        fgColor    =  QColor(0, 0, 0);        //前景色是黑色
    }


#define LINETO(X,Y) addPoint(a, QPoint(pt.x() + (X),pt.y() + (Y)))
#define LIGHT
#define DARK

    if (1) {
        QPolygon a(0);
        //The following is an exact copy of the switch below.
        //don't make any changes here
        switch (segmentNo) {
        case 0 :
            ppt = pt;
            LIGHT;
            LINETO(segLen - 1,0);
            DARK;
            LINETO(segLen - width - 1,width);
            LINETO(width,width);
            LINETO(0,0);
            break;
        case 1 :
            pt += QPoint(0 , 1);
            ppt = pt;
            LIGHT;
            LINETO(width,width);
            DARK;
            LINETO(width,segLen - width/2 - 2);
            LINETO(0,segLen - 2);
            LIGHT;
            LINETO(0,0);
            break;
        case 2 :
            pt += QPoint(segLen - 1 , 1);
            ppt = pt;
            DARK;
            LINETO(0,segLen - 2);
            LINETO(-width,segLen - width/2 - 2);
            LIGHT;
            LINETO(-width,width);
            LINETO(0,0);
            break;
        case 3 :
            pt += QPoint(0 , segLen);
            ppt = pt;
            LIGHT;
            LINETO(width,-width/2);
            LINETO(segLen - width - 1,-width/2);
            LINETO(segLen - 1,0);
            DARK;
            if (width & 1) {            // adjust for integer division error
                LINETO(segLen - width - 3,width/2 + 1);
                LINETO(width + 2,width/2 + 1);
            } else {
                LINETO(segLen - width - 1,width/2);
                LINETO(width,width/2);
            }
            LINETO(0,0);
            break;
        case 4 :
            pt += QPoint(0 , segLen + 1);
            ppt = pt;
            LIGHT;
            LINETO(width,width/2);
            DARK;
            LINETO(width,segLen - width - 2);
            LINETO(0,segLen - 2);
            LIGHT;
            LINETO(0,0);
            break;
        case 5 :
            pt += QPoint(segLen - 1 , segLen + 1);
            ppt = pt;
            DARK;
            LINETO(0,segLen - 2);
            LINETO(-width,segLen - width - 2);
            LIGHT;
            LINETO(-width,width/2);
            LINETO(0,0);
            break;
        case 6 :
            pt += QPoint(0 , segLen*2);
            ppt = pt;
            LIGHT;
            LINETO(width,-width);
            LINETO(segLen - width - 1,-width);
            LINETO(segLen - 1,0);
            DARK;
            LINETO(0,0);
            break;
        case 7 :
            if (false)   // if smallpoint place'.' between other digits
                pt += QPoint(segLen + width/2 , segLen*2);
            else
                pt += QPoint(segLen/2 , segLen*2);
            ppt = pt;
            DARK;
            LINETO(width,0);
            LINETO(width,-width);
            LIGHT;
            LINETO(0,-width);
            LINETO(0,0);
            break;
        case 8 :
            pt += QPoint(segLen/2 - width/2 + 1 , segLen/2 + width);
            ppt = pt;
            DARK;
            LINETO(width,0);
            LINETO(width,-width);
            LIGHT;
            LINETO(0,-width);
            LINETO(0,0);
            break;
        case 9 :
            pt += QPoint(segLen/2 - width/2 + 1 , 3*segLen/2 + width);
            ppt = pt;
            DARK;
            LINETO(width,0);
            LINETO(width,-width);
            LIGHT;
            LINETO(0,-width);
            LINETO(0,0);
            break;
        default :
            //qWarning("drawSegment: (%s) Illegal segment id: %d\n",
            //         q->objectName().toLocal8Bit().constData(), segmentNo);
            ;
        }
        // End exact copy
        p.setPen(Qt::NoPen);
        p.setBrush(fgColor);
        p.drawPolygon(a);
        p.setBrush(Qt::NoBrush);

        pt = pos;
    }
#undef LINETO
#undef LIGHT
#undef DARK

#define LINETO(X,Y) p.drawLine(ppt.x(), ppt.y(), pt.x()+(X), pt.y()+(Y)); \
                    ppt = QPoint(pt.x()+(X), pt.y()+(Y))
#define LIGHT p.setPen(lightColor)
#define DARK  p.setPen(darkColor)
    if (1)
        switch (segmentNo) {
        case 0 :
            ppt = pt;
            LIGHT;
            LINETO(segLen - 1,0);
            DARK;
            LINETO(segLen - width - 1,width);
            LINETO(width,width);
            LINETO(0,0);
            break;
        case 1 :
            pt += QPoint(0,1);
            ppt = pt;
            LIGHT;
            LINETO(width,width);
            DARK;
            LINETO(width,segLen - width/2 - 2);
            LINETO(0,segLen - 2);
            LIGHT;
            LINETO(0,0);
            break;
        case 2 :
            pt += QPoint(segLen - 1 , 1);
            ppt = pt;
            DARK;
            LINETO(0,segLen - 2);
            LINETO(-width,segLen - width/2 - 2);
            LIGHT;
            LINETO(-width,width);
            LINETO(0,0);
            break;
        case 3 :
            pt += QPoint(0 , segLen);
            ppt = pt;
            LIGHT;
            LINETO(width,-width/2);
            LINETO(segLen - width - 1,-width/2);
            LINETO(segLen - 1,0);
            DARK;
            if (width & 1) {            // adjust for integer division error
                LINETO(segLen - width - 3,width/2 + 1);
                LINETO(width + 2,width/2 + 1);
            } else {
                LINETO(segLen - width - 1,width/2);
                LINETO(width,width/2);
            }
            LINETO(0,0);
            break;
        case 4 :
            pt += QPoint(0 , segLen + 1);
            ppt = pt;
            LIGHT;
            LINETO(width,width/2);
            DARK;
            LINETO(width,segLen - width - 2);
            LINETO(0,segLen - 2);
            LIGHT;
            LINETO(0,0);
            break;
        case 5 :
            pt += QPoint(segLen - 1 , segLen + 1);
            ppt = pt;
            DARK;
            LINETO(0,segLen - 2);
            LINETO(-width,segLen - width - 2);
            LIGHT;
            LINETO(-width,width/2);
            LINETO(0,0);
            break;
        case 6 :
            pt += QPoint(0 , segLen*2);
            ppt = pt;
            LIGHT;
            LINETO(width,-width);
            LINETO(segLen - width - 1,-width);
            LINETO(segLen - 1,0);
            DARK;
            LINETO(0,0);
            break;
        case 7 :
            if (false)   // if smallpoint place'.' between other digits
                pt += QPoint(segLen + width/2 , segLen*2);
            else
                pt += QPoint(segLen/2 , segLen*2);
            ppt = pt;
            DARK;
            LINETO(width,0);
            LINETO(width,-width);
            LIGHT;
            LINETO(0,-width);
            LINETO(0,0);
            break;
        case 8 :
            pt += QPoint(segLen/2 - width/2 + 1 , segLen/2 + width);
            ppt = pt;
            DARK;
            LINETO(width,0);
            LINETO(width,-width);
            LIGHT;
            LINETO(0,-width);
            LINETO(0,0);
            break;
        case 9 :
            pt += QPoint(segLen/2 - width/2 + 1 , 3*segLen/2 + width);
            ppt = pt;
            DARK;
            LINETO(width,0);
            LINETO(width,-width);
            LIGHT;
            LINETO(0,-width);
            LINETO(0,0);
            break;
        default :
            //qWarning("drawSegment: (%s) Illegal segment id: %d\n",
            //         q->objectName().toLocal8Bit().constData(), segmentNo);
            ;
        }

#undef LINETO
#undef LIGHT
#undef DARK
}


 void drawDigit(const QPoint &pos, QPainter &p, int segLen,
                      char newCh, char oldCh = ' ')
{
    // Draws and/or erases segments to change display of a single digit
    // from oldCh to newCh

        char updates[18][2];        // can hold 2 times number of segments, only
                                    // first 9 used if segment table is correct
        int  nErases;
        int  nUpdates;
        const char *segs;
        int  i,j;

        const char erase      = 0;
        const char draw       = 1;
        const char leaveAlone = 2;

        segs = getSegments(oldCh);
        for (nErases=0; segs[nErases] != 99; nErases++) {
            updates[nErases][0] = erase;            // get segments to erase to
            updates[nErases][1] = segs[nErases];    // remove old char
        }
        nUpdates = nErases;
        segs = getSegments(newCh);
        for(i = 0 ; segs[i] != 99 ; i++) {
            for (j=0;  j<nErases; j++)
                if (segs[i] == updates[j][1]) {   // same segment ?
                    updates[j][0] = leaveAlone;     // yes, already on screen
                    break;
                }
            if (j == nErases) {                   // if not already on screen
                updates[nUpdates][0] = draw;
                updates[nUpdates][1] = segs[i];
                nUpdates++;
            }
        }
        for (i=0; i<nUpdates; i++) {
            if (updates[i][0] == draw)
                drawSegment(pos, updates[i][1], p, segLen);
            if (updates[i][0] == erase)
                drawSegment(pos, updates[i][1], p, segLen, true);
        }
}



#endif // DIGIT1_H
