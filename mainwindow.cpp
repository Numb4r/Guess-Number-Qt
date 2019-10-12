#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize

    srand(static_cast<unsigned int>(time(nullptr)));
    //Generate (1-10)
    secretNumber = rand() %10 +1;
    qDebug()<<"Secret number generate "<< QString::number(secretNumber);
    ui->startOverButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << "guess number "<< QString::number(guessNumber);
    if(guessNumber == secretNumber){
        ui->messageLabel->setText("Congratulations, number is :"+QString::number(secretNumber));
        //Disable guess button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }else{
        if(secretNumber < guessNumber){
            ui->messageLabel->setText("Number is lower than that");
        }else{
            ui->messageLabel->setText("Number is higher than that");
        }
    }
}

void MainWindow::on_startOverButton_clicked()
{
    ui->startOverButton->setDisabled(true);
    ui->guessButton->setDisabled(false);
    ui->spinBox->setValue(1);
    secretNumber = rand()%10 + 1;
    ui->messageLabel->setText("");

}
