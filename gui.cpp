#include "gui.moc"
#include <QDebug>
#include <fstream>
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
    connect(loadFile, SIGNAL(triggered()), this, SLOT(LoadFileDialog()));
    connect(saveFile, SIGNAL(triggered()), this, SLOT(SaveFileDialog()));
}

void gui::CreateActions()
{
    loadFile = new QAction("loadFile", widget);
    saveFile = new QAction("saveFile", widget);
    saveFile->setEnabled(false);
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

        currentGraphics->accept(pv);

        for(int i = 0 ; i < pv.getGraphics().size(); i++)
        {
            scene->addItem(pv.getGraphics().at(i));
        }
        scene->update();
        saveFile->setEnabled(true);
    }
}

void gui::SaveFileDialog()
{
    DescriptionVisitor dv;
    currentGraphics->accept(dv);
    cout << "description = " << dv.getDescription() << endl;

    QString file = QFileDialog::getSaveFileName(this, tr("Load File"),
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
