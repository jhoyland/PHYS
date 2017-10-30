#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    validator= new QDoubleValidator(-1e9,1e9,4,NULL);
    ui->lineEditPhase->setValidator(validator);
    ui->lineEditVoltage->setValidator(validator);
    ui->lineEditOffset->setValidator(validator);
    ui->lineEditFrequency->setValidator(validator);


    sig = new functionGenerator();

    ui->turnOnButtonclicked->setEnabled(false);
    ui->turnOffButtonClicked->setEnabled(false);
    ui->sinButtonClicked->setEnabled(false);
    ui->lineEditFrequency->setEnabled(false);
    ui->lineEditOffset->setEnabled(false);
    ui->lineEditPhase->setEnabled(false);
    ui->lineEditVoltage->setEnabled(false);


}
void MainWindow::sinButtonClicked()
{
    QString thetext=ui->lineEditVoltage->text();
    double v=thetext.toDouble();

    QString thetext1=ui->lineEditPhase->text();
    double p=thetext1.toDouble();

    QString thetext2=ui->lineEditFrequency->text();
    double f=thetext2.toDouble();

    QString thetext3=ui->lineEditOffset->text();
    double o=thetext3.toDouble();

    QString type;



    // f = read value from ui
    sig->setVoltage(v);

    sig->setFreq(f);

    sig->setPhase(p);

    sig->setOffset(o);

    if (ui->comboBox->currentText() == "Sin wave")
    {
        type = "SIN ";
    }
    if (ui->comboBox->currentText() == "Square wave")
    {
        type = "SQU ";
    }
    if (ui->comboBox->currentText() == "Ramp wave")
    {
        type = "RAMP";
    }
    if (ui->comboBox->currentText() == "Pulse")
    {
        type = "PULS";
    }

    sig->generateSin(type.toStdString().c_str());
}

void MainWindow::turnOffButtonClicked()
{
    sig ->turnoff();
}

void MainWindow::turnOnButtonClicked()
{
    sig ->turnon();
}

void MainWindow::identifyButtonClicked()
{
    sig ->identify();
    ui->turnOnButtonclicked->setEnabled(true);
    ui->turnOffButtonClicked->setEnabled(true);
    ui->sinButtonClicked->setEnabled(true);
    ui->lineEditFrequency->setEnabled(true);
    ui->lineEditOffset->setEnabled(true);
    ui->lineEditPhase->setEnabled(true);
    ui->lineEditVoltage->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete validator;
}
