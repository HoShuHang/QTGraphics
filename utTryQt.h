#ifndef UTTRYQT_H_INCLUDED
#define UTTRYQT_H_INCLUDED

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QLabel>

int argc = 0;
char a[2]={'0','1'};
char * argv[1]={a};
//
//TEST (TryQt, first) {
//    QApplication app(argc, argv);
//    QPushButton quit("Quit");
//    quit.resize(75, 30);
//    quit.setFont(QFont("Times", 18, QFont::Bold));
//    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
//    quit.show();
//}
//
//#include <QVBoxLayout>
//#include <QGraphicsView>
//#include <QGraphicsItem>
//
//TEST (TryQt, second) {
//    QApplication app(argc, argv);
//    QWidget * window = new QWidget;
//    window->setWindowTitle("Graphics App");
//
//    QVBoxLayout *wLayout = new QVBoxLayout(window);
//
//    QGraphicsView *gv = new QGraphicsView;
//    QGraphicsScene *gs = new QGraphicsScene();
//    gv->setScene(gs);
//    gs->addRect(-2, -2, 4, 3);
//    gs->addRect(-2,-2,3,3);
//    gs->addEllipse(0,0,1,1);
//    gs->addRect(-2,-2,2,2);
//    gs->addRect(-1,-1,1,3);
//
//    QPushButton *quit = new QPushButton("Quit");
//
//    wLayout->addWidget(gv);
//    wLayout->addWidget(quit);
//
//    quit->resize(75, 30);
//    quit->setFont(QFont("Times", 18, QFont::Bold));
//
//    QObject::connect(quit, SIGNAL(clicked()), &app, SLOT(quit()));
//
//    window->show();
//
//    app.exec();
//
//}

#include "gui.h"
TEST (TryQt, third) {
    QApplication app(argc, argv);
    gui gui;
    gui.show();
    app.exec();
}

#endif // UTTRYQT_H_INCLUDED
