#include "mainwindow.h"
#include "ui_mainwindow.h"

double calcVal =0.0;
bool ButtonBTrigger =false;
bool ButtonCTrigger =false;
bool ButtonTTrigger =false;
bool ButtonETrigger =false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui-> Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i=0; i< 10; i++){
        QString butName = "Button" + QString::number(i);
        numButtons[i]= MainWindow:: findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()),this,
                SLOT(NumPressed()));
    }

    connect(ui->ButtonT, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonE, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonC, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));
    connect(ui->ButtonB, SIGNAL(released()),this,
            SLOT(MathButtonPressed()));

    connect(ui->Buttone, SIGNAL(released()),this,
            SLOT(EqualButtonPressed()));
    connect(ui->Temizle, SIGNAL(released()), this,
            SLOT(MathTemizlePressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble()==0) || (displayVal.toDouble()==0.0)){
        ui->Display->setText(butVal);
    }else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal,'g', 16));
    }
}

void MainWindow::MathButtonPressed(){
    ButtonBTrigger =false;
    ButtonCTrigger =false;
    ButtonTTrigger =false;
    ButtonETrigger =false;
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button =(QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive)== 0){
        ButtonBTrigger =true;
    }else if(QString::compare(butVal, "*",Qt::CaseInsensitive)== 0){
        ButtonCTrigger =true;
    } else if(QString ::compare(butVal, "+", Qt::CaseInsensitive)== 0){
        ButtonTTrigger= true;
    }else {
        ButtonETrigger=true;
    }
    ui->Display->setText("");
}

void MainWindow:: EqualButtonPressed(){
    double solution =0.0;
    QString displayVal =ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(ButtonTTrigger || ButtonETrigger || ButtonCTrigger || ButtonBTrigger){
        if(ButtonTTrigger){
            solution = calcVal + dblDisplayVal;
        }else if (ButtonETrigger){
            solution = calcVal - dblDisplayVal;
        }else if(ButtonCTrigger){
            solution = calcVal * dblDisplayVal;
        }else{
            solution = calcVal / dblDisplayVal;
        };


    }
    ui->Display->setText(QString::number(solution));

}


void MainWindow::on_Temizle_clicked(bool checked)
{
    ui->Display->setText("0");
}



