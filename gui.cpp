#include "gui.moc"
#include <QDebug>
#include <fstream>
gui::gui()
{
//    ctor
    CreateView();
    CreateActions();
    CreateMenus();
    CreateTools();
    SetActionConnection();
    QString title = "Sample";
    setWindowTitle(title);
    setMinimumSize(800, 600);
    model = new Model();
    iniX = 0;
    iniY = 0;
    moveX = 0;
    moveY = 0;
    moveAtIndex = 0;
    selectRectangle = new SimpleGraphics(new Rectangle(0,0,0,0));
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
//    pv.setWidget(widget);
    graphicsView = new QGraphicsView(widget);//要調整生成的位置
    QString gView = "graphicView";
    graphicsView->setObjectName(gView);

    scene = new GraphicsScene(this, QRect(-400,-300,800,600));//管理painter item的物件
    graphicsView->setScene(scene);
    QVBoxLayout *layout = new QVBoxLayout;//呈現畫面
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
}

void gui::SetActionConnection()
{
    connect(aboutDeveloper, SIGNAL(triggered()), this, SLOT(MessageDialog()));
    connect(loadFile, SIGNAL(triggered()), this, SLOT(LoadFileDialog()));
    connect(saveFile, SIGNAL(triggered()), this, SLOT(SaveFileDialog()));
    connect(createCircle, SIGNAL(triggered()), this, SLOT(CreateCircle()));
    connect(createRectangle, SIGNAL(triggered()), this, SLOT(CreateRectangle()));
    connect(createSquare, SIGNAL(triggered()), this, SLOT(CreateSquare()));
    connect(undo, SIGNAL(triggered()), this, SLOT(Undo()));
    connect(redo, SIGNAL(triggered()), this, SLOT(Redo()));
    connect(deleteGraphics, SIGNAL(triggered()), this, SLOT(DeleteGraphics()));
    connect(compose, SIGNAL(triggered()), this, SLOT(Compose()));
    connect(decompose, SIGNAL(triggered()), this, SLOT(Decompose()));
    connect(up, SIGNAL(triggered()), this, SLOT(Up()));
    connect(down, SIGNAL(triggered()), this, SLOT(Down()));
}

void gui::CreateActions()
{
    QPixmap loadPic("pic/load.png");
    QPixmap savePic("pic/save.png");
    QPixmap circle("pic/circle.png");
    QPixmap rectangle("pic/rectangle.png");
    QPixmap square("pic/square.png");
    QPixmap undoPic("pic/undo.png");
    QPixmap redoPic("pic/redo.png");
    QPixmap deletePic("pic/delete.png");
    QPixmap composePic("pic/compose.png");
    QPixmap decomposePic("pic/decompose.png");
    QPixmap upPic("pic/up.png");
    QPixmap downPic("pic/down.png");
    loadFile = new QAction(loadPic, "loadFile", widget);
    saveFile = new QAction(savePic, "saveFile", widget);
    saveFile->setEnabled(false);
    aboutDeveloper = new QAction("aboutDeveloper", widget);
    createCircle = new QAction(circle, "createCircle", widget);
    createRectangle = new QAction(rectangle, "createRectangle", widget);
    createSquare = new QAction(square, "createSquare", widget);
    undo = new QAction(undoPic, "undo", widget);
    undo->setEnabled(false);
    redo = new QAction(redoPic, "redo", widget);
    redo->setEnabled(false);
    deleteGraphics = new QAction(deletePic, "delete", widget);
    deleteGraphics->setEnabled(false);
    compose = new QAction(composePic, "compose", widget);
    compose->setEnabled(false);
    decompose = new QAction(decomposePic, "decompose", widget);
    decompose->setEnabled(false);
    up = new QAction(upPic, "up", widget);
    down = new QAction(downPic, "down", widget);
}

void gui::CreateMenus()
{
    file = menuBar()->addMenu("File");
    file->addAction(loadFile);
    file->addAction(saveFile);
    about = menuBar()->addMenu("About");
    about->addAction(aboutDeveloper);
    createShape = menuBar()->addMenu("Create Shape");
    createShape->addAction(createSquare);
    createShape->addAction(createRectangle);
    createShape->addAction(createCircle);
}

void gui::CreateTools()
{
    QToolBar *fileToolBar = addToolBar("tool bar");
    fileToolBar->addAction(loadFile);
    fileToolBar->addAction(saveFile);
    fileToolBar->addSeparator();
    fileToolBar->addAction(createCircle);
    fileToolBar->addAction(createRectangle);
    fileToolBar->addAction(createSquare);
    fileToolBar->addAction(undo);
    fileToolBar->addAction(redo);
    fileToolBar->addAction(deleteGraphics);
    fileToolBar->addAction(compose);
    fileToolBar->addAction(decompose);
    fileToolBar->addAction(up);
    fileToolBar->addAction(down);
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

void gui::LoadFileDialog()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Load File"),
                   "./",
                   tr("txt (*.txt)"));
    if(file != "")
    {
        QByteArray ba = file.toLatin1();
        const char *c_str = ba.data();
        model->buildGraphicFromFile(c_str);
        Update();
    }
}

void gui::UpdateScene()
{
    scene->clear();
    scene->update();
    scene->addItem(selectRectangle->createPainter());
    for(int i = 0; i < model->getGraphics()->size(); i++)
    {
        Graphics *g = model->getGraphics()->at(i);
        scene->addItem(g->createPainter());
        scene->update();
    }
}

void gui::SaveFileDialog()
{
    QString file = QFileDialog::getSaveFileName(this, tr("Save File"),
                   "./",
                   tr("txt (*.txt)"));
    QByteArray ba = file.toLatin1();
    const char *c_str = ba.data();

    ofstream myfile (c_str);
    if (myfile.is_open())
    {
        myfile << model->getDescription();
        myfile.close();
    }
    Update();
}

void gui::CreateCircle()
{
    model->createCircle();
    Update();
}

void gui::CreateRectangle()
{
    model->createRectangle();
    Update();
}

void gui::CreateSquare()
{
    model->createSquare();
    Update();
}

void gui::Undo()
{
    model->undo();
    Update();
}

void gui::Redo()
{
    model->redo();
    Update();
}

void gui::Update()
{
    UpdateScene();
    UpdateButtonEnable();
}

void gui::UpdateButtonEnable()
{
    undo->setEnabled(model->isUndoEnable());
    redo->setEnabled(model->isRedoEnable());
    deleteGraphics->setEnabled(model->isGraphicsSelect());
    compose->setEnabled(model->isComposeEnable());
    decompose->setEnabled(model->isDecomposeEnable());
    saveFile->setEnabled(!model->getGraphics()->empty());
}

void gui::mousePressEvent (QGraphicsSceneMouseEvent * event )
{
    iniX = event->scenePos().x();
    iniY = event->scenePos().y();

    model->MousePressEvent(iniX, iniY);
    moveAtIndex = model->select(iniX, iniY);
    Update();
}

void gui::mouseMoveEvent ( QGraphicsSceneMouseEvent * event )
{
    if(moveAtIndex == -1)
    {
        delete selectRectangle;
        selectRectangle = new SimpleGraphics(new Rectangle(iniX,iniY,moveX,moveY));
    }
    model->MouseMoveEvent(event->scenePos().x(), event->scenePos().y());
    Update();
}

void gui::mouseReleaseEvent (QGraphicsSceneMouseEvent * event )
{
    delete selectRectangle;
    selectRectangle = new SimpleGraphics(new Rectangle(0,0,0,0));
    model->MouseReleseEvent(event->scenePos().x(), event->scenePos().y());
    Update();
}

void gui::DeleteGraphics()
{
    model->deleteGraphics();
    Update();
}

void gui::Compose()
{
    model->composeGraphic();
    Update();
}

void gui::Decompose()
{
    model->decomposeGraphic();
    Update();
}

void gui::Up()
{
    model->up();
    Update();
}

void gui::Down()
{
    model->down();
    Update();
}
