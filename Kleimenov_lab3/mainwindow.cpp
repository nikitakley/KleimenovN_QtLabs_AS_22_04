#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "Kleimenov_Dish.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<shared_ptr<Kleimenov_Dish>> ptrsDishes;

void MainWindow::on_downloadFromFile_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Выбрать файл"), QDir::currentPath(), "All Files (*)");

    if (fileName.isEmpty()){
        QMessageBox::warning(this, tr("Предупреждение"), tr("Файл не выбран."));
        return;
    }
    else{
        ui->myWidget->load(fileName);
    }
}


void MainWindow::on_saveInFile_triggered()
{
    if(fileName.isEmpty())
        on_saveAs_triggered();
    else
        save();
}


void MainWindow::on_deleteAll_triggered()
{
    ptrsDishes.clear();
    ui->myWidget->clean();
    fileName="";
}


void MainWindow::on_saveAs_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Открыть"), QDir::currentPath(), "All Files (*)");
    if (!fileName.isEmpty())
        save();
}

void MainWindow::save()
{
    ui->myWidget->save(fileName);
}

