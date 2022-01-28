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
    qDebug()<<"SIFRE"<<str;
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
void DLCalMenu::combo_diaCh_indexChanged(int index)     // Additional graphics' combo
{
   index = combo_diaMain->currentIndex();
   if(PreChnNo != index){
       PreChnNo = index;
       customPlot_main->replot();
   }
}
void DLCalMenu::combo_portType_indexChanged(int index)
{
    switch(index){
    case 0:
        port_index = 0;
        ui->COMport     -> setDisabled(true); // TODO : disable etmiyor ?
        ui->adres       -> setDisabled(true);
        ui->timeout     -> setDisabled(true);
        ui->IP          -> setDisabled(true);
        ui->COMport     -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->adres       -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->timeout     -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->IP          -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->lbl_COMport -> setStyleSheet("color: rgb(120,120,120); border : none");
        ui->lbl_adres   -> setStyleSheet("color: rgb(120,120,120); border : none");
        ui->lbl_timeout -> setStyleSheet("color: rgb(120,120,120); border : none");
        ui->lbl_IP      -> setStyleSheet("color: rgb(120,120,120); border : none");

    case 1:
        port_index = 1;
        ui->COMport     -> setDisabled(false);
        ui->adres       -> setDisabled(true);
        ui->timeout     -> setDisabled(true);
        ui->IP          -> setDisabled(true);
        ui->COMport     -> setStyleSheet("background-color : rgb(255,255,255); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->adres       -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->timeout     -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->IP          -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->lbl_COMport -> setStyleSheet("border : none;");
        ui->lbl_adres   -> setStyleSheet("color: rgb(120,120,120); border : none");
        ui->lbl_timeout -> setStyleSheet("color: rgb(120,120,120); border : none");
        ui->lbl_IP      -> setStyleSheet("color: rgb(120,120,120); border : none");
        break;
    case 2:
        port_index = 2;
        ui->COMport     -> setDisabled(false);
        ui->adres       -> setDisabled(false);
        ui->timeout     -> setDisabled(false);
        ui->IP          -> setDisabled(false);
        ui->COMport     -> setStyleSheet("background-color : rgb(255,255,255); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->adres       -> setStyleSheet("background-color : rgb(255,255,255); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->timeout     -> setStyleSheet("background-color : rgb(255,255,255); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->IP          -> setStyleSheet("background-color : rgb(255,255,255); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->lbl_COMport -> setStyleSheet("border : none;");
        ui->lbl_adres   -> setStyleSheet("border : none;");
        ui->lbl_timeout -> setStyleSheet("border : none;");
        ui->lbl_IP      -> setStyleSheet("border : none;");
        break;
    case 3:
        port_index = 3;
        ui->COMport     -> setDisabled(false);
        ui->adres       -> setDisabled(false);
        ui->timeout     -> setDisabled(true);
        ui->IP          -> setDisabled(true);
        ui->COMport     -> setStyleSheet("background-color : rgb(255,255,255); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->adres       -> setStyleSheet("background-color : rgb(255,255,255); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->timeout     -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->IP          -> setStyleSheet("background-color : rgb(230,230,230); border : 1px solid rgb(180,180,180); border-radius: 3px;");
        ui->lbl_COMport -> setStyleSheet("border : none;");
        ui->lbl_adres   -> setStyleSheet("border : none;");
        ui->lbl_timeout -> setStyleSheet("color: rgb(120,120,120); border : none");
        ui->lbl_IP      -> setStyleSheet("color: rgb(120,120,120); border : none");
        break;
    }
}
void DLCalMenu::combo_sampeRate_indexChanged(int index)
{
    switch(index){
    case 0:
        ui->info_sampeRate  -> setText(": 2");
        break;
    case 1:
        ui->info_sampeRate  -> setText(": 4");
        break;
    case 2:
        ui->info_sampeRate  -> setText(": 8");
        break;
    case 3:
        ui->info_sampeRate  -> setText(": 16");
        break;
    case 4:
        ui->info_sampeRate  -> setText(": 32");
        break;
    case 5:
        ui->info_sampeRate  -> setText(": 64");
        break;
    case 6:
        ui->info_sampeRate  -> setText(": 128");
        break;
    case 7:
        ui->info_sampeRate  -> setText(": 256");
        break;
    case 8:
        ui->info_sampeRate  -> setText(": 512");
        break;
    case 9:
        ui->info_sampeRate  -> setText(": 1024");
        break;
    }
}
void DLCalMenu::combo_filterType_indexChanged(int index)
{
    switch(index){
    case 0:
        ui->info_filterType  -> setText(": None");
        break;
    case 1:
        ui->info_filterType  -> setText(": Average");
        break;
    case 2:
        ui->info_filterType  -> setText(": Moving Average");
        break;
    case 3:
        ui->info_filterType  -> setText(": EMA");
        break;
    case 4:
        ui->info_filterType  -> setText(": Butterworth");
        break;
    }
}
void DLCalMenu::combo_inputType_indexChanged(int index)
{
    switch(index){
    case 0:
        ui->info_inputType  -> setText(": LoadCell 1-2mV/V");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/LoadCell.png);");
        break;
    case 1:
        ui->info_inputType  -> setText(": LoadCell 3mV/V");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/LoadCell.png);");
        break;
    case 2:
        ui->info_inputType  -> setText(": 0-100mV Transducer");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/Voltaj_Transducer.png);");
        break;
    case 3:
        ui->info_inputType  -> setText("0-100mV Transducer Differential");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/Voltaj_Transducer.png);");
        break;
    case 4:
        ui->info_inputType  -> setText(": 0-10V Transducer");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/Voltaj_Transducer.png);");
        break;
    case 5:
        ui->info_inputType  -> setText(": 4-20mA Transducer");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/Akim_Transducer.png);");
        break;
    case 6:
        ui->info_inputType  -> setText(": LVTD Single Ended Output");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/LVDT_Single.png);");
        break;
    case 7:
        ui->info_inputType  -> setText(": LVTD Diffrential Output");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/LVDT_Diff.png);");
        break;
    case 8:
        ui->info_inputType  -> setText(": 120 Ohm Single strain Gauge");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/LVDT_Single.png);");
        break;
    case 9:
        ui->info_inputType  -> setText(": 120 Ohm Dual strain Gauge");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/StrainGaugeDual.png);");
        break;
    case 10:
        ui->info_inputType  -> setText(": 350 Ohm Single strain Gauge");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/LVDT_Single.png);");
        break;
    case 11:
        ui->info_inputType  -> setText(": 350 Ohm Dual strain Gauge");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/StrainGaugeDual.png);");
        break;
    case 12:
        ui->info_inputType  -> setText(": 1000 Ohm Single strain Gauge");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/LVDT_Single.png);");
        break;
    case 13:
        ui->info_inputType  -> setText(": 1000 Ohm Dual strain Gauge");
        ui->wdgInput        -> setStyleSheet("border-image: url(:/StrainGaugeDual.png);");
        break;
    case 14:
        ui->info_inputType  -> setText(": Custom 1");
        break;
    case 15:
        ui->info_inputType  -> setText(": Custom 2");
        break;
    case 16:
        ui->info_inputType  -> setText(": Custom 3");
        break;
    }
}
void DLCalMenu::combo_channels_indexChanged(int index)
{
    if(PreChnNo != index){
        PreChnNo = index;
        ui->channelName->clear();
    }
}
void DLCalMenu::combo_rawreal_indexChanged(int index)       // Data type selection combo
{
    index = ui->combo_rawreal->currentIndex();
    if(ui->btn_dispList){
        switch (index) {
        case 0:
            tview_real -> show();
            tview_raw  -> hide();
            tview_file  ->hide();
            break;
        case 1:
            tview_raw  -> show();
            tview_real -> hide();
            tview_file -> hide();
            break;
        }
    }
}
void DLCalMenu::combo_device_indexChanged(int index)        // Setting device combo
{
    switch (index) {
    case 0 :
        dateEdit_1->setDisabled(true);
        dateEdit_2->setDisabled(true);
        timeEdit_1->setDisabled(true);
        timeEdit_2->setDisabled(true);
        break;
    case 1 : {
        QString fileName;
        QString filters("CSV files (*.csv);; All files (*.*)");
        QString defaultFilter("CSV files (*.csv)");
        fileName = QFileDialog::getOpenFileName(this, tr("Choose external tool"),QCoreApplication::applicationDirPath(),
                                                filters, &defaultFilter);
        QFile *externalFile = new QFile(fileName);
        dateEdit_1->setDisabled(false);
        dateEdit_2->setDisabled(false);
        timeEdit_1->setDisabled(false);
        timeEdit_2->setDisabled(false);
    }    break;
    case 2 :
        dateEdit_1->setDisabled(false);
        dateEdit_2->setDisabled(false);
        timeEdit_1->setDisabled(false);
        timeEdit_2->setDisabled(false);
        break;
    }
}
void DLCalMenu::on_btn_password_clicked()
{
    /* QKeyEvent *event;
     if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
             event->ignore();
             return;
     }*/
     get_password();
     if(ui->password->text() == str) {
         mouseevent = true;
         ui->combo_channels  -> setDisabled(false);
         ui->btn_saveChn     -> setDisabled(false);
         ui->channelName     -> setDisabled(false);
         ui->radioBtn_csv    -> setDisabled(false);
         //ui->radioBtn_pdf    -> setDisabled(false);        // TODO : pdf secenegi yok
         ui->btn_newPassword -> setDisabled(false);
         ui->btn_newPassword -> setStyleSheet("background-color : none; border: none; text-decoration: underline; color:rgb(30,60,190); text-align: right");

         QMessageBox message;
         QPixmap unlock(":/icon/unlock.png");
         message.setIconPixmap(QPixmap(unlock));
         message.setText("You are able to authorize");
         message.exec();
     }
     else if(ui->password->text() != "****") {
         mouseevent = false;
         QMessageBox message;
         QPixmap lock(":/icon/lock.png");
         message.setIconPixmap(QPixmap(lock));
         message.setText("Invalid password. Try again!");
         message.exec();
     }
}
void DLCalMenu::on_btn_newPassword_clicked()
{
    QGridLayout *grid_dialogPsw = new QGridLayout;
    dialog_newPswd  =  new QDialog;
    wdg_dialogPsw   =  new QWidget;
    newPswd         =  new QLineEdit ;
    oldPswd         =  new QLineEdit;
    btn_saveNewPswd =  new QPushButton("Apply");
    btn_cancelNewPswd   =  new QPushButton("Cancel");
    keyicon         =  new QLabel(wdg_dialogPsw);

    connect(this->btn_saveNewPswd , SIGNAL(clicked()), this, SLOT(btn_saveNewPswd_onClicked()));
    dialog_newPswd  -> setStyleSheet(QString("QLineEdit,  QPushButton {font-family: Arial; font-size: %1pt; height: %2px}").arg(Fontsize).arg(RealLabelH));
    btn_saveNewPswd -> setCursor(Qt::PointingHandCursor);
    btn_cancelNewPswd -> setCursor(Qt::PointingHandCursor);
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
void DLCalMenu::btn_saveNewPswd_onClicked()
{
    if (oldPswd->text() == ui->password->text()){ // çalışıyo
        if (newPswd->validator() == validator && newPswd->text() != oldPswd->text()){
            str.clear();
            if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
                str.append(QString(newPswd->text()));
                in << str;
                file.close();
            }
            QMessageBox message;
            message.setIconPixmap(QPixmap(":/icon/okay.png"));
            message.setText("Password changed successfully.");
            message.exec();
            dialog_newPswd->close();
        }
        else if(newPswd->text() == oldPswd->text()){ // || newPswd->text() = " "){      // TODO : bos sifre kabul edilmesin
            QMessageBox message;
            message.setIconPixmap(QPixmap(":/icon/warning.png"));
            message.setText("Please enter a valid password!");
            message.exec();
        }
//        qDebug()<<"yeni şifre :"<<str;
//        qDebug()<<"yeni şifre :"<<newPswd->text();
    }
    else if(oldPswd->text() != str){ // çalışıyo
        QMessageBox message;
        message.setIconPixmap(QPixmap(":/icon/warning.png"));
        message.setText("Old password is incorrect.\nTry again!");
        message.exec();
    }
    oldPswd -> clear();
    newPswd -> clear();
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
void DLCalMenu::on_btn_graphDialog_clicked()    // 'Set Device' button
{
    QGridLayout *grid_dialogGraph = new QGridLayout;
    dialog_setDevice = new QDialog;
    wdg_dialogSetDev = new QWidget;
    combo_device     = new QComboBox;
    btn_okDialog     = new QPushButton("OK");
    btn_cancelDialog = new QPushButton("CANCEL");
    lbl_startDate    = new QLabel("Start :");
    lbl_endDate  = new QLabel("End :");
    lbl_device   = new QLabel("Device :");
    dateEdit_1   = new QDateEdit;
    dateEdit_2   = new QDateEdit;
    timeEdit_1   = new QTimeEdit;
    timeEdit_2   = new QTimeEdit;
    connect(combo_device, SIGNAL(currentIndexChanged(int)), this, SLOT(combo_device_indexChanged(int)));
    dialog_setDevice->setStyleSheet(QString("QPushButton, QComboBox, QLabel, QTimeEdit, QDateEdit {font-size: %1pt}").arg(Fontsize));
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
void DLCalMenu::btn_addAlert_onClicked()
{
    //qDebug()<<"Added alarm";
    add_alarm++;
    int j = add_alarm;
    int h = RealLCDH;
    for(int i=0; i<j; i++){
        grid_alert  -> addWidget(checkBox_alarm[j-1],j,0);
        grid_alert  -> addWidget(comboBox_alarm[j-1],j,1);
        grid_alert  -> addWidget(lbl_alarmL[j-1],j,2);
        grid_alert  -> addWidget(spinBox_alarmL[j-1],j,3);
        grid_alert  -> addWidget(lbl_alarmH[j-1],j,4);
        grid_alert  -> addWidget(spinBox_alarmH[j-1],j,5);
        grid_alert  -> addWidget(btn_addAlarm,j+1,1);
        grid_alert  -> addWidget(btn_setAlarm,j+1,3);
        grid_alert  -> addWidget(btn_removeAlarm,j+1,5);
        h = h + RealLCDH;
        wdgAlert    -> setMinimumHeight(h);
        if(j>=AlarmCount){
            btn_addAlarm -> setDisabled(true);
            btn_addAlarm -> setStyleSheet("background-color : none; border: none; color:rgb(150,150,150); text-align: left;");
        }
    }
    //qDebug()<<"j"<<j;
}
void DLCalMenu::btn_setAlert_onClicked()
{
    qDebug()<<"Alarm set at %1 : Channel %1";

    // messageBox oluştur
}
void DLCalMenu::btn_removeAlert_onClicked()
{

}
void DLCalMenu::checkbox_alert_onClicked()
{
   /* for(int i=0; i<AlarmCount; i++){
        if(checkBox_alarm[i]->isChecked()){
            btn_removeAlarm -> setEnabled(true);
            btn_removeAlarm -> setStyleSheet("background-color : rgb(170,0,0); color:rgb(255,255,255); ");
        }
        else if(!checkBox_alarm[i]->isChecked()){
            btn_removeAlarm -> setDisabled(true);
            btn_removeAlarm -> setStyleSheet("background-color : rgb(220,150,150); color:rgb(255,255,255); ");
        }
    }*/

    // messageBox oluştur
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
