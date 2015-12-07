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
    GraphicsFactory gf;

    QString file = QFileDialog::getOpenFileName(this, tr("Load File"),
                   "./",
                   tr("txt (*.txt)"));
    if(file != "")
    {
        QByteArray ba = file.toLatin1();
        const char *c_str = ba.data();
        currentGraphics = gf.buildGraphicsFromFile(c_str);

        qDebug() << "Working on file " << file;

        scene->addItem(currentGraphics->createPainter());

        scene->update();
        saveFile->setEnabled(true);
    }
}

void gui::UpdateScene()
{
    scene->clear();
    scene->update();
    for(int i = 0; i < model->getGraphics()->size(); i++)
    {
        Graphics *g = model->getGraphics()->at(i);
        scene->addItem(g->createPainter());
        scene->update();
    }
}

void gui::SaveFileDialog()
{
    DescriptionVisitor dv;
    currentGraphics->accept(dv);
    cout << "description = " << dv.getDescription() << endl;

    QString file = QFileDialog::getSaveFileName(this, tr("Save File"),
                   "./",
                   tr("txt (*.txt)"));
    QByteArray ba = file.toLatin1();
    const char *c_str = ba.data();

    ofstream myfile (c_str);
    if (myfile.is_open())
    {
        myfile << dv.getDescription();
        myfile.close();
    }
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
}

void gui::mouseMoveEvent ( QGraphicsSceneMouseEvent * event )
{
    cout << "mouseMoveEvent";
}

void gui::mousePressEvent (QGraphicsSceneMouseEvent * event )
{
    cout << "mousePressEvent";
}

void gui::mouseReleaseEvent (QGraphicsSceneMouseEvent * event )
{
    cout << "mouseReleaseEvent";
    Update();
}
