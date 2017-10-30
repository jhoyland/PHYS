#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <function.h>
#include <QDoubleValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QDoubleValidator* validator;
     functionGenerator* sig;

public slots:

    void sinButtonClicked();
    void turnOnButtonClicked();
    void identifyButtonClicked();
    void turnOffButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
