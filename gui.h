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
#include "PaintVisitor.h"
#include "GraphicsFactory.h"

#include <iostream>
#include <string>
#include <sstream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "DescriptionVisitor.h"

using namespace std;


class gui: public QMainWindow
{
    Q_OBJECT
    public:
        gui();
        virtual ~gui();
        QGraphicsView *graphicsView;
        QGraphicsScene *scene;
        QWidget *widget;

        void Display();
        void CreateView();
        void MessageBox(const QString _message);
        void CreateActions();
        void CreateMenus();
        void CreateTools();
        void SetActionConnection();

    protected:
    private:
        QAction *aboutDeveloper, *loadFile, *saveFile;
        QMenu *about, *file;
        PaintVisitor pv;
        Graphics *currentGraphics;
    private slots:
        void LoadFileDialog();
        void MessageDialog();
        void SaveFileDialog();
};

#endif // GUI_H
