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
        current_page = SCR_GRAPH;
        break;
    case 3:
        current_page = SCR_SET;
        break;
    case 4:
        current_page = SCR_PORTSET;
        break;
    case 5:
        current_page = SCR_ALERTS;
        break;
    }
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
