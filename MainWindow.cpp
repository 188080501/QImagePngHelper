#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    connect(m_ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(choosePng()));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::choosePng()
{
    const auto paths = QFileDialog::getOpenFileNames(this, "Please choose PNG", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "*.png");
    if(paths.isEmpty()) { return; }

    for(const auto &path: paths)
    {
        QImage image(path);
        if(image.isNull()) { continue; }

        if(!image.save(path, "PNG"))
        {
            QMessageBox::warning(this, "Error", QString("%1 save fail").arg(path));
        }
    }

    QMessageBox::information(this, "Done", "All png image processing is completed");
}
