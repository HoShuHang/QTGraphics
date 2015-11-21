#include "gui.moc"
#include <QDebug>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
gui::gui()
{
//    ctor
    CreateView();
    CreateActions();
    CreateMenus();
    SetActionConnection();
    QString title = "Sample";
    setWindowTitle(title);
    setMinimumSize(800, 600);
//    Display();

}

gui::~gui()
{
    delete widget;
    delete scene;
    //dtor
}

void gui::CreateView()
{
    widget = new QWidget();//繪製painter item的物件
    setCentralWidget(widget);
    pv.setWidget(widget);
    graphicsView = new QGraphicsView(widget);//要調整生成的位置
    QString gView = "graphicView";
    graphicsView->setObjectName(gView);

    scene = new QGraphicsScene();//管理painter item的物件
    graphicsView->setScene(scene);
    QVBoxLayout *layout = new QVBoxLayout;//呈現畫面
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
}

void gui::SetActionConnection()
{
    connect(aboutDeveloper, SIGNAL(triggered()), this, SLOT(MessageDialog()));
    connect(loadFile, SIGNAL(triggered()), this, SLOT(FileDialog()));
}

void gui::CreateActions()
{
    loadFile = new QAction("loadFile", widget);
    saveFile = new QAction("saveFile", widget);
    aboutDeveloper = new QAction("aboutDeveloper", widget);
}

void gui::CreateMenus()
{
    file = menuBar()->addMenu("File");
    file->addAction(loadFile);
    file->addAction(saveFile);
    about = menuBar()->addMenu("About");
    about->addAction(aboutDeveloper);
}
void gui::Display()
{
    Painter *item = new Painter(-2,-2, 3, 4, widget);
    scene->addItem(item);
    scene->update();
}

void gui::MessageDialog()
{
    QMessageBox msgbox;
    std::string message("104598008\n");
    message += std::string("author:Kevin\n");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();
}

void gui::FileDialog()
{
    QFileDialog d;
    QStringList fileName;
    if(d.exec())
        fileName = d.selectedFiles();
    GraphicsFactory gf;
    Graphics * graphics;
    foreach (QString s, fileName)
    {
        QByteArray ba = s.toLatin1();
        const char *c_str = ba.data();
        graphics = gf.buildGraphicsFromFile(c_str);
        qDebug() << "Working on file " << s;
    }
    graphics->accept(pv);

//    CompositeGraphics g;
//    g.add(new SimpleGraphics(new Circle(0,0,1)));
//    g.add(new SimpleGraphics(new Square(-2,-2,2)));
//
//    SimpleGraphics r(new Rectangle (-1,-1,1,3));
//
//    CompositeGraphics h;
//    h.add(&g);
//    h.add(&r);
//
//    g.accept(pv);

    for(int i = 0 ; i < pv.getGraphics().size(); i++){
        scene->addItem(pv.getGraphics().at(i));
    }
    scene->update();
}


