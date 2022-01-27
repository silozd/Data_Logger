#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"

#include <QApplication>
#include <QScreen>
#include <QDesktopWidget>
#include <QDebug>
#include <QScrollArea>
#include <QLabel>
#include <QScrollBar>
#include <QGridLayout>
#include <QMouseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTabWidget>
#include <QTabBar>
#include <QRadioButton>
#include <QDateEdit>
#include <QTimeEdit>
#include <QProgressBar>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

QFile file("/home/sila/Desktop/DL_tab_new/get_password.txt");
QTextStream  in(&file);
QString str;
QRegularExpression rx("(^([0-9]{4})$)"); // TODO : 4ten az da kabul ediyor?
QValidator *validator = new QRegularExpressionValidator(rx);

void DLCalMenu::get_password()
{
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    str = in.readLine();
    file.close();
    qDebug()<<"şifre"<<str;
}
//
void DLCalMenu::on_tabWidget_currentChanged(int index)
{
    switch (index) {
    case 0:
        current_page = SCR_MAIN;
        break;
    case 1:
        current_page = SCR_CALIB;
        break;
    case 2:
        current_page = SCR_SET;
        break;
    case 3:
        current_page = SCR_PORTSET;
        break;
    case 4:
        current_page = SCR_ALERTS;
        break;
    }
}
void DLCalMenu::combo_axis1_indexChanged(int index)     // tek slot olunca index [0]'a donmuyor maalesef
{
    x_change = 1;
    index = ui->combo_axis1->currentIndex();
    if(PreChnNo != index){
        PreChnNo = index;
        customPlot_main -> xAxis -> setLabel(ui->combo_axis1->currentText());
        customPlot_main->graph(0)->data().data()->clear();
        if(ad_main>0){
            for(int i = customPlot_main->graphCount(); i>1; i--){
                customPlot_main->removeGraph(customPlot_main->graph(i-1));
            }
            ad_main = 0;
        }
        customPlot_main -> replot();
    }
}
void DLCalMenu::combo_axis2_indexChanged(int index)     //
{
    index = ui->combo_axis2->currentIndex();
    if(PreChnNo != index){
        PreChnNo = index;
        customPlot_main->yAxis->setLabel(ui->combo_axis2->currentText());
        customPlot_main->graph(0)->data().data()->clear();
        if(ad_main>0){
            for(int i = customPlot_main->graphCount(); i>1; i--){
                customPlot_main->removeGraph(customPlot_main->graph(i-1));
            }
            ad_main = 0;
        }
        customPlot_main->replot();
    }
}
void DLCalMenu::on_btn_plotGraph_clicked()
{
    static int click = 1;
    click++;
    if(click%2 == 0){
        connect(timer_main, SIGNAL(timeout()), this, SLOT(plot_graphMain()));
        timer_main -> start();
        plot_statu =  1;
        ui->combo_axis1 -> setDisabled(true);
        ui->combo_axis2 -> setDisabled(true);
        ui->btn_plotGraph->setText("Pause");
    }
    else if(click%2 == 1){
        plot_statu = 0;
        timer_main -> stop();
        ui->combo_axis1 -> setDisabled(false);
        ui->combo_axis2 -> setDisabled(false);
        ui->btn_plotGraph->setText("Plot");
    }
}
void DLCalMenu::on_btn_graphDialog_clicked()
{
    QGridLayout *grid_dialogGraph = new QGridLayout;
    dialog_setDevice    = new QDialog;
    wdg_dialogSetDev    = new QWidget;
    combo_device        = new QComboBox;
    btn_okDialog        = new QPushButton("OK");
    btn_cancelDialog    = new QPushButton("CANCEL");
    lbl_startDate       = new QLabel("Start :");
    lbl_endDate  = new QLabel("End :");
    lbl_device   = new QLabel("Device :");
    dateEdit_1   = new QDateEdit;
    dateEdit_2   = new QDateEdit;
    timeEdit_1   = new QTimeEdit;
    timeEdit_2   = new QTimeEdit;
//    dialog_setDevice->setStyleSheet(QString("QPushButton, QComboBox, QLabel {font-size: %1pt}").arg(Fontsize));
    combo_device-> addItem("Current device",0);
    combo_device-> addItem("External",1);
    combo_device-> addItem("SD Card",2);
    combo_device-> setCurrentIndex(0);
    dateEdit_1  -> setDateRange(QDate(2021,9,1),QDate::currentDate());
    dateEdit_2  -> setDateRange(QDate(2021,9,1),QDate(2030,01,01));
    dateEdit_1  -> setDisabled(true);
    dateEdit_2  -> setDisabled(true);
    timeEdit_1  -> setDisabled(true);
    timeEdit_2  -> setDisabled(true);
    grid_dialogGraph -> addWidget(lbl_device,0,0);
    grid_dialogGraph -> addWidget(combo_device,0,1);
    grid_dialogGraph -> addWidget(lbl_startDate,1,0);
    grid_dialogGraph -> addWidget(dateEdit_1,1,1);
    grid_dialogGraph -> addWidget(timeEdit_1,1,2);
    grid_dialogGraph -> addWidget(lbl_endDate,2,0);
    grid_dialogGraph -> addWidget(dateEdit_2,2,1);
    grid_dialogGraph -> addWidget(timeEdit_2,2,2);
    grid_dialogGraph -> addWidget(btn_okDialog,3,1);
    grid_dialogGraph -> addWidget(btn_cancelDialog,3,2);
    wdg_dialogSetDev -> setParent(dialog_setDevice);
    dialog_setDevice -> setLayout(grid_dialogGraph);
    dialog_setDevice -> setWindowTitle("Set Device");
    dialog_setDevice -> resize(DialogW,DialogH);
    dialog_setDevice -> exec();
}

void DLCalMenu::on_btn_newPassword_clicked()
{
    QGridLayout *grid_dialogPsw = new QGridLayout;
    dialog_newPswd  =  new QDialog;
    password        =  new QLineEdit;
    password        -> setEchoMode(QLineEdit::Password);
    password        -> setPlaceholderText("Type password");
    password        -> setClearButtonEnabled(true);
    password        -> setMaxLength(4);
    wdg_dialogPsw   =  new QWidget;
    newPswd         =  new QLineEdit ;
    oldPswd         =  new QLineEdit;
    btn_saveNewPswd =  new QPushButton("Apply");
    btn_cancelNewPswd   =  new QPushButton("Cancel");
    keyicon         =  new QLabel(wdg_dialogPsw);

    oldPswd -> setMaxLength(4);
    oldPswd -> setValidator(validator);
    newPswd -> setValidator(validator);

    keyicon -> setPixmap(QPixmap(":/icon/key.png"));
    keyicon -> setAlignment(Qt::AlignCenter);
    oldPswd -> setEchoMode(QLineEdit::PasswordEchoOnEdit);
    newPswd -> setEchoMode(QLineEdit::PasswordEchoOnEdit);
    oldPswd -> setClearButtonEnabled(true);
    newPswd -> setClearButtonEnabled(true);
    oldPswd -> setPlaceholderText("Enter old password");
    newPswd -> setPlaceholderText("Enter new password");

    grid_dialogPsw -> addWidget(keyicon,0,0);
    grid_dialogPsw -> addWidget(oldPswd,1,0);
    grid_dialogPsw -> addWidget(newPswd,2,0);
    grid_dialogPsw -> addWidget(btn_saveNewPswd,3,0);
    grid_dialogPsw -> addWidget(btn_cancelNewPswd,4,0);
    wdg_dialogPsw  -> setParent(dialog_newPswd);
    dialog_newPswd -> setLayout(grid_dialogPsw);
    dialog_newPswd -> resize(DialogW,DialogH);
    dialog_newPswd -> setWindowTitle("New Password");
    dialog_newPswd -> exec();
}

void DLCalMenu::slider_Pressed()                    // Scroll Movement
{
    int pos;
    if(current_page == SCR_MAIN){
        pos = ui->scrollReals->verticalScrollBar()->sliderPosition();}
    if(current_page == SCR_CALIB){
        pos = ui->scrollArea->horizontalScrollBar()->sliderPosition();}
    position[0]=pos;
}
void DLCalMenu::slider_Released()                   // Scroll Movement
{
    int pos;
    if(current_page == SCR_MAIN){
        pos = ui->scrollReals->verticalScrollBar()->sliderPosition();}
    if(current_page == SCR_CALIB){
        pos = ui->scrollArea->horizontalScrollBar()->sliderPosition();}
    position[1]=pos;
}
void DLCalMenu::scroll_movement()                   // Scroll Movement
{
    int factor;
    scroll_main = ui->scrollReals -> verticalScrollBar();
    scroll_bar  = ui->scrollArea  -> horizontalScrollBar();

    if(current_page == SCR_MAIN){
        factor = scroll_main->singleStep();}
    if(current_page == SCR_CALIB){
        factor = scroll_bar->singleStep();}

    int objectW = factor;

    int pos1=position[0];
    int pos2=position[1];
    int movement= pos2-pos1;

    float counter = (float)movement/(float)objectW;
    counter = counter*10;

    if((int)counter%10 >= 5){
        counter = (int)(counter/10)+1;
    }
    else if((int)counter%10 <= -5){
        counter = (int)(counter/10)-1;
    }
    else{
        counter = (int)(counter/10);
    }
    if(current_page == SCR_MAIN){
        scroll_main->setValue(pos1+((objectW)*counter));
    }
    if(current_page == SCR_CALIB){
        scroll_bar->setValue(pos1+((objectW)*counter));
    }
}
