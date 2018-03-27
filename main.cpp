#include "mainwindow.h"
#include <QApplication>

#include   <iostream>    //这个里面包好cout

//#include <qtextcodec.h>


//#include "stdlib.h"
//#include "string.h"
//#include <string>
//#include <unistd.h>
//#include "stdio.h"

//文件夹相关的
#include <QDir>
#include <QFileInfo>

using namespace  std;


//获取文件夹信息；  初始化的时候获取信息
QStringList ListFileInfo( QString strdir, QString strfilter )
{
    QDir File_Dir( strdir  );
     QFileInfoList list = File_Dir.entryInfoList();
    QStringList File_List;
    for (int i = 0; i < list.size(); ++i) {
         QFileInfo fileInfo = list.at(i);
         if(fileInfo.isFile() == false)continue;
         if(fileInfo.fileName().right(strfilter.length()) != strfilter)continue;
         File_List.push_back(fileInfo.fileName().append("   ").append(fileInfo.lastModified().toString("yyyy-mm-dd hh:mm:ss")));
     }
    return File_List;
}



int main(int argc, char *argv[])
{

    //QTextCodec::codecForName("");
    //QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "GBK" ) );
    //QTextCodec::setCodecForTr( QTextCodec::codecForName( "GBK" ) );
    //QTextCodec::setCodecForLocale( QTextCodec::codecForName( "GBK" ) );


    QApplication a(argc, argv);



    MainWindow w;
    w.show();
#if 0


    //my personal test
    //3  获取目录文件相关信息
    //QString path = ;
    QString path =QString::fromLocal8Bit("E:\\南瑞job\\各图像倒换\\转图错误\\配网错误问题\\1svg导入");
    QString FileType = ".svg";
    ListFileInfo( path, FileType );



    //1,
    //std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
     //                                           .arg(fileInfo.fileName()));
    //std::cout << std::endl;

    QString s = "translate(100,0) rotate(20,10,0) scale(1,1) ";
    string t = s.toLocal8Bit().data();
    //cout<<t<<endl;
    int pos_a = t.find( "rotate" );
    if( pos_a >= 0 )
    {
        string rotate_str = t.substr( pos_a );
        QString qrotate = QString( rotate_str.c_str() );
        //QStringList  str_list = QStringList::split( QRegExp( "[a-z(), ]" ), qrotate );
        //QStringList::iterator str_iter = str_list.begin();
        //QString qtmpstr = *str_iter;
        s = qrotate;
    }
    //2
    string filename = string("ttttt.sln.h.edg");
    string typeTmp = filename.substr(0,filename.find(".h.edg"));

    string type = typeTmp.substr(typeTmp.find('.')+1,typeTmp.length() - typeTmp.find('.'));
    type +="\n";
    string ttt;
    if(ttt.empty())
    {
        int c=0;
        c++;
    }
    //3


    QMessageBox box(QMessageBox::NoIcon,"biaoti",type.c_str());
    box.show();



#endif




    return a.exec();
}
