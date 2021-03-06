#ifndef GUI_H
#define GUI_H
#include <QtWidgets/QMainWindow>
#include <Qt>
#include <QGraphicsView>
#include <QtWidgets/QToolBar>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QFileDialog>
#include <QToolBar>

#include "Painter.h"
#include "GraphicsFactory.h"

#include <iostream>
#include <string>
#include <sstream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "DescriptionVisitor.h"
#include "Model.h"
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneDragDropEvent>
#include "GraphicsScene.h"
#include <cmath>
#include "Observer.h"

using namespace std;


class gui: public QMainWindow, public Observer
{
    Q_OBJECT
public:
    gui();
    virtual ~gui();
    QGraphicsView *graphicsView;
    GraphicsScene *scene;
    QWidget *widget;

    void Display();
    void CreateView();
    void MessageBox(const QString _message);
    void CreateActions();
    void CreateMenus();
    void CreateTools();
    void SetActionConnection();
    void mouseReleaseEvent (QGraphicsSceneMouseEvent * event );
    void mousePressEvent (QGraphicsSceneMouseEvent * event );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
private:
    QAction *aboutDeveloper, *loadFile, *saveFile;
    QAction *createRectangle, *createSquare, *createCircle;
    QAction *undo, *redo, *deleteGraphics, *compose, *decompose, *up, *down;
    QMenu *about, *file, *createShape;
    Graphics *selectRectangle;
//    PaintVisitor pv;
    Graphics *currentGraphics;
    Model *model;
    void Update();
    void UpdateScene();
    void UpdateButtonEnable();
    int iniX, iniY, moveX, moveY;
    int moveAtIndex;
private slots:
    void LoadFileDialog();
    void LoadFile();
    void MessageDialog();
    void LoadFileAlertDialog();
    void SaveFileDialog();
    void CreateSquare();
    void CreateRectangle();
    void CreateCircle();
    void DeleteGraphics();
    void Undo();
    void Redo();
    void Compose();
    void Decompose();
    void Up();
    void Down();
};

#endif // GUI_H
