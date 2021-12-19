#include "WorldText.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
   ui->actionNew->setShortcut(tr("Ctrl+N"));
    ui->actionOpen->setShortcut(tr("Ctrl+O"));
    ui->actionSave->setShortcut(tr("Ctrl+S"));
    ui->actionSave_As->setShortcut(tr("Ctrl+Shift+S"));
    ui->actionExit->setShortcut(tr("Ctrl+Q"));
    ui->actionCopy->setShortcut(tr("Ctrl+C"));
    ui->actionPaste->setShortcut(tr("Ctrl+V"));
    ui->actionCut->setShortcut(tr("Ctrl+X"));
    ui->actionUndo->setShortcut(tr("Ctrl+Z"));
    ui->actionRedo->setShortcut(tr("Ctrl+Y"));
   this->setWindowTitle("WorldText");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->plainTextEdit->setPlainText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning" , "Cannot open file : " + file.errorString());
        return;

    }
    setWindowTitle(fileName);
    QTextStream in (&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning" , "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setPlainText(text);
       file.close();

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}




void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

