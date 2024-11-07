#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString fileName;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_downloadFromFile_triggered();   // actionOpen

    void on_saveInFile_triggered();     // actionSave

    void on_deleteAll_triggered();      // actionNew

    void on_saveAs_triggered();     // actionSaveAs

    void save();

private:
    Ui::MainWindow *ui;
};
