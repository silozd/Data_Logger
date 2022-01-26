#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"
#include "customtabstyle.h"
#include <QDebug>
#include <QAction>
#include <QApplication>
#include <QDateEdit>
#include <QDebug>
#include <QDesktopWidget>
#include <QFile>
#include <QFileDialog>
#include <QIcon>
#include <QMessageBox>
#include <QMouseEvent>
#include <QProgressBar>
#include <QRadioButton>
#include <QScreen>
#include <QTextStream>
#include <QTimeEdit>
#include <QToolBar>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

DLCalMenu::DLCalMenu(QWidget *parent) :
    QMainWindow(parent),
    wdgReals(new QWidget),
    dataBox(new QWidget),
    CalPointsFrame(new QFrame),
    ui(new Ui::DLCalMenu)
{
    ui->setupUi(this);
    int hr = DLCalMenu::GetScreenHRes(0);
    int vr = DLCalMenu::GetScreenVRes(0);
    int i = 1000;
    QFont Font1 ("Arial", Fontsize, QFont::Normal);

    if (ScreenWidth <=1920){
        i = 1000;
        Fontsize = 13;
        FontsizeTab = 13;
        Font1.setPointSize(Fontsize);
        qDebug()<<"Screen Width <= 1920 :?"<<ScreenWidth;
    }
    else if (ScreenWidth > 1920){
        Fontsize = 13;
        FontsizeTab = 13;
        Font1.setPointSize(Fontsize);
        qDebug()<<"Screen Width > 1920 :?"<<ScreenWidth;
    }
    else if  (ScreenWidth == 3840){
        i = i/2;
        Fontsize =14;
        FontsizeTab = 16;
        Font1.setPointSize(Fontsize);
        qDebug()<<"Screen Width == 3840 :?"<<ScreenWidth;
    }
    if  (ScreenHeight <= 960){        //dlcalmenu org
        i = 1500;
        Fontsize = 11;
        FontsizeTab = 9;
        qDebug()<<"Screen Width :?"<<ScreenWidth;
        qDebug()<<"Screen Height <= 960 :?"<<ScreenHeight;
    }
    qDebug()<<"i"<<i;

    int SideMargin = hr*10/i;
    int RealLabelH = vr*30/i;
    int RealLabelW = hr*180/i;
    int RealLCDH = vr*40/i;
    int CalPointH = vr*38/i;
    int CalPointW = vr*86/i;
    int ToolH = vr*60/i;
    int CalibScrollH = RealLCDH*2+RealLabelH*2+SideMargin*3;
    int MainScrollW = RealLabelW;
    int TabBarH = hr*135/i;
    int TabBarW = hr*100/i;
    int AppW = hr*1260/i;
    int AppH = vr*795/i;

    resize(AppW,AppH);

    qDebug()<<"hr = "<<hr;
    qDebug()<<"vr = "<<vr;
    qDebug()<<"SideMargin"<<SideMargin;
    qDebug()<<"RealLabelH"<<RealLabelH;
    qDebug()<<"RealLabelW"<<RealLabelW;
    qDebug()<<"RealLcdH"<<RealLCDH;
    qDebug()<<"CalibScrollH"<<CalibScrollH;
    qDebug()<<"MainScrollW"<<MainScrollW;
    qDebug()<<"TabBarW"<<TabBarW;

    tabBar = ui->tabWidget->tabBar();
    ui->tabWidget->setStyleSheet(QString("QTabBar::tab { width: %1px; height: %2px; font-size: %3pt}").arg(TabBarW).arg(TabBarH).arg(FontsizeTab)
                                 + QString("QLabel{font-family: Times New Roman; font-size: %1pt;} QComboBox,QPushButton,QRadioButton,QPushButton{font-family: Arial; font-size: %1pt;}").arg(Fontsize));
    tabBar   ->setStyle(new CustomTabStyle);
    tabBar_alarm = ui->tabWidget_alarm->tabBar();

// toolbar :
    ui->toolBar -> toggleViewAction()->setVisible(false);
    QWidget *spacer = new QWidget();
    QLabel  *logo = new QLabel;
    spacer  -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui      -> toolBar->addWidget(spacer);
//    logo    -> setSizeIncrement(350, ToolH);
//    logo    -> setPixmap(QPixmap(":/icon/logo.png"));
//    logo    -> setContentsMargins(0,0,0,0);
    //ui->toolBar -> addWidget(logo);       // OPEN
    ui->toolBar -> setMaximumHeight(ToolH);
    ui->toolBar -> setIconSize(QSize(ToolH, ToolH));
    ui->toolBar -> setMovable(false);
    clear      = ui->toolBar -> addAction(QIcon(":/icon/clear.png") ,"Clear"       );//,this, SLOT(ClearKey()));
    exportfile = ui->toolBar -> addAction(QIcon(":/icon/export.png"),"Export File");
    savefile   = ui->toolBar -> addAction(QIcon(":/icon/save.png")  ,"Save File"   );//,this, SLOT(save()));
    openfile   = ui->toolBar -> addAction(QIcon(":/icon/open.png")  ,"Open File"   );//,this, SLOT(open()));
    ui->toolBar -> addSeparator();
    help = ui->toolBar-> addAction(QIcon(":/icon/info.png"), "Open Document");
    ui->toolBar -> addSeparator();
    quit = ui->toolBar-> addAction(QIcon(":/icon/quit.png"), "Quit Application");
    connect (quit, &QAction::triggered, qApp, &QApplication::quit);
//    connect (exportfile, SIGNAL(triggered()), this, SLOT(exportCsv()));       // OPEN

// dialog password initilize:       // OPEN DIALOG
/*    dialog_newPswd          =  new QDialog;
    password                -> setEchoMode(QLineEdit::Password);
    password                -> setPlaceholderText("Type password");
    password                -> setClearButtonEnabled(true);
    password                -> setMaxLength(4);
    wdg_dialogPsw           =  new QWidget;
    newPswd                 =  new QLineEdit ;
    oldPswd                 =  new QLineEdit;
    btn_saveNewPswd         =  new QPushButton("Apply");
    btn_cancelNewPswd       =  new QPushButton("Cancel");
    keyicon                 =  new QLabel(wdg_dialogPsw);

// dialog set device:
    dialog_setDevice        = new QDialog;
    wdg_dialogSetDev        = new QWidget;
    combo_device            = new QComboBox;
    btn_okDialog            = new QPushButton("OK");
    btn_cancelDialog        = new QPushButton("CANCEL");
    lbl_startDate           = new QLabel("Start :");
    lbl_endDate             = new QLabel("End :");
    lbl_device              = new QLabel("Device :");
    dateEdit_1              = new QDateEdit;
    dateEdit_2              = new QDateEdit;
    timeEdit_1              = new QTimeEdit;
    timeEdit_2              = new QTimeEdit;

// dialog add graph:
    grid_dialogAddMain      = new QGridLayout;
    grid_dialogAddGra       = new QGridLayout;
    dialog_addToGraph       = new QDialog;
    dialog_addToMain        = new QDialog;
    wdg_dialogAddGra        = new QWidget;
    wdg_dialogAddMain       = new QWidget;
    combo_diaMain           = new QComboBox;
    combo_diaGraph          = new QComboBox;
    btn_diaOKMain           = new QPushButton("Apply");
    btn_diaOKGra            = new QPushButton("Apply");
    btn_diaCancelMain       = new QPushButton("Cancel");
    btn_diaCancelGra        = new QPushButton("Cancel");
    lbl_diaAxisMain         = new QLabel("Axis Y : ");
    lbl_diaAxisGra          = new QLabel("Axis Y : ");
*/
    grid_reals  = new QGridLayout(wdgReals);
    boxLayout   = new QGridLayout(dataBox);
    CalGridLayout = new QGridLayout(CalPointsFrame);
    ui->scrollReals->setWidget(wdgReals);
    ui->scrollReals->setWidgetResizable(1);
    ui->scrollReals->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

// serial port:
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos){
        ui->m_serialPortComboBox->addItem(info.portName());
        ui->currentPort->setText(ui->m_serialPortComboBox->currentText());
    }

    for (int i=0; i<MaxChnCounts; i++){
        ChnLCDRaw.append(new QLCDNumber(CalPointsFrame));
    }
    for (int i=0; i<MaxChnCounts; i++){
        ChnLCDReal.append(new QLCDNumber(CalPointsFrame));
        ChnLCDReal_Main.append(new QLCDNumber(wdgReals));
    }

// scrollbar - main :
        scroll_main = new QScrollBar;
        scroll_main = ui->scrollReals -> verticalScrollBar();
        scroll_main -> setTracking(true);
        scroll_main -> setSingleStep(RealLCDH+RealLabelH+SideMargin/1.5);
        connect(scroll_main, SIGNAL(sliderPressed()),    this,   SLOT(slider_Pressed()));
        connect(scroll_main, SIGNAL(sliderReleased()),   this,   SLOT(slider_Released()));
        connect(scroll_main, SIGNAL(sliderReleased()),   this,   SLOT(scroll_movement()));

// real data - main page :
    for (int i = 0; i < MaxChnCounts; ++i) {            // real- raw array loop
        ChnRealLabel[i]     = new QLabel(tr("Channel %1 Real").arg(i + 1), wdgReals);
        ChnRealLabel[i]     -> setAlignment(Qt::AlignCenter);
        ChnRealLabel[i]     -> setStyleSheet("font-family: Arial; background-color: rgb(20,20,20); color: rgb(255,255,255)");
        ChnRealLabel[i]     -> setMinimumSize(RealLabelW,RealLabelH);
        ChnRealLabel[i]     -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        ChnRealLabel[i]     -> setFont(Font1);

        ChnLCDReal_Main[i]  -> display(QString("%1000").arg(i+1));
        ChnLCDReal_Main[i]  -> setSegmentStyle(QLCDNumber::Flat);
        ChnLCDReal_Main[i]  -> setDigitCount(RealDigitCount);
        ChnLCDReal_Main[i]  -> setSmallDecimalPoint(true);
        ChnLCDReal_Main[i]  -> setStyleSheet("background-color: rgb(20,20,20); color: rgb(100,220,255)");
        ChnLCDReal_Main[i]  -> setMinimumHeight(RealLCDH);
        ChnLCDReal_Main[i]  -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        grid_reals          -> setContentsMargins(0,0,0,0);
        grid_reals          -> setVerticalSpacing(SideMargin/3);
        grid_reals          -> addWidget(ChnRealLabel[i]   , i*2   , 0);
        grid_reals          -> addWidget(ChnLCDReal_Main[i], i*2+1 , 0);
        ui->scrollReals     -> setMaximumWidth(RealLabelW*2);

// real raw data - calibration page :
        if(int j = 1){
            ChnRawLabel[i]  = new QLabel(tr("Channel %1 Raw").arg(i + 1),ui->scrollArea);
            ChnRawLabel[i]  -> setAlignment(Qt::AlignCenter);
            ChnRawLabel[i]  -> setStyleSheet("font-family: Arial; background-color: rgb(10, 10, 10); color: rgb(255, 255, 255);");
            ChnRawLabel[i]  -> setMinimumSize(RealLabelW, RealLabelH);
            ChnRawLabel[i]  -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
            ChnRawLabel[i]  -> setFont(Font1);

            ChnLCDRaw[i]    -> display(QString("%1000").arg(i+1));
            ChnLCDRaw[i]    -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDRaw[i]    -> setDigitCount(RawDigitCount);
            ChnLCDRaw[i]    -> setSmallDecimalPoint(true);
            ChnLCDRaw[i]    -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(255, 10, 0)");
            ChnLCDRaw[i]    -> setMinimumSize(RealLabelW, RealLCDH);
            ChnLCDRaw[i]    -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

            ChnRealLabel[i] = new QLabel(tr("Channel %1 Real").arg(i + 1),ui->scrollArea);
            ChnRealLabel[i] -> setAlignment(Qt::AlignCenter);
            ChnRealLabel[i] -> setFont(Font1);
            ChnRealLabel[i] -> setStyleSheet("font-family: Arial; background-color: rgb(10, 10, 10); color: rgb(255, 255, 255)");
            ChnRealLabel[i] -> setMinimumSize(RealLabelW, RealLabelH);
            ChnRealLabel[i] -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

            ChnLCDReal[i]   -> display(QString("%1000").arg(i+1));
            ChnLCDReal[i]   -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDReal[i]   -> setDigitCount(RealDigitCount);
            ChnLCDReal[i]   -> setSmallDecimalPoint(true);
            ChnLCDReal[i]   -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(50, 255, 0)");
            ChnLCDReal[i]   -> setMinimumSize(RealLabelW, RealLCDH);
            ChnLCDReal[i]   -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

            boxLayout       -> addWidget(ChnRawLabel[i]  , j   , i);
            boxLayout       -> addWidget(ChnLCDRaw[i]    , j+1 , i);
            boxLayout       -> addWidget(ChnRealLabel[i] , j+2 , i);
            boxLayout       -> addWidget(ChnLCDReal[i]   , j+3 , i);
            boxLayout       -> setVerticalSpacing(SideMargin/4);
            boxLayout       -> setHorizontalSpacing(SideMargin/1.5);
        }

// combobox channel items :
            ui->combo_axis1     -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->combo_axis2     -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->combo_axisX     -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->combo_axisY     -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->CoBoxChannel    -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->combo_channels  -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->activeChannels  -> setText(ui->CoBoxChannel->currentText());
        }
        ui->combo_axisX ->  addItem("Time",MaxChnCounts+1);
        ui->combo_axis1 ->  addItem("Time",MaxChnCounts+1);
        ui->combo_axis1 ->  setCurrentIndex(MaxChnCounts);
        ui->combo_axisX ->  setCurrentIndex(MaxChnCounts);
        ui->scrollArea->setWidget(dataBox);
        ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        dataBox     -> setLayout(boxLayout);
        boxLayout   -> setContentsMargins(0,0,0,0);
        dataBox -> setMaximumHeight(CalibScrollH*1.2);
        ui->scrollArea->setMinimumHeight(CalibScrollH+SideMargin);
        ui->scrollArea->setMaximumHeight((CalibScrollH+SideMargin)*1.2);

// cal points :
    for (int i = 0; i < MaxCalPoint; ++i) {
        CalStep[i]          =   new QLabel(tr("%1").arg(i + 1));
        CalStep[i]          ->  setAlignment(Qt::AlignCenter);
        CalStep[i]          ->  setStyleSheet("margin: 3px");
        CalStep[i]          ->  setFont(Font1);
        CalStep[i]          ->  setMinimumHeight(CalPointH);
        CalStep[i]          ->  setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

        UserCalLabel[i]     =   new QLabel(CalPointsFrame);
        UserCalLabel[i]     ->  setText(QString::number((i)*200*10));
        UserCalLabel[i]     ->  setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        UserCalLabel[i]     ->  setFont(Font1);
        UserCalLabel[i]     ->  setStyleSheet("font-family: Arial; background-color: rgb(123, 168, 246); border: 1px solid rgb(83,128,206); margin-right: 5px;  padding: 1px; ");
        //UserCalLabel[i]     ->  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        UserCalLabel[i]     ->  setMinimumSize(CalPointW,CalPointH);
        UserCalLabel[i]     ->  setMaximumHeight(CalPointW);
        ChnCalArray[0][8 + i] = QString::number((i)*200*10);

        ChnRawData[i]       =   new QLabel(QString::number(00).arg(i+1));
        ChnRawData[i]       ->  setText(QString::number((i+1)*2000));
        ChnRawData[i]       ->  setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ChnRawData[i]       ->  setFont(Font1);
        ChnRawData[i]       ->  setStyleSheet("font-family: Arial; border: 1px solid gray; margin-right: 5px ; padding: 1px; background-color: rgb(255,255,255);");
      //  ChnRawData[i]       ->  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        ChnRawData[i]       ->  setMinimumSize(CalPointW,CalPointH);
        ChnRawData[i]       ->  setMaximumHeight(CalPointW);
        ChnCalArray[0][8 + 16 + i] = QString::number((i+1)*2000);

        CalStepCheckBox[i]  =   new QCheckBox;
        CalStepCheckBox[i]  ->  setStyleSheet(QString("QCheckBox::indicator {height: %1px; width: %1px;}"
                                                      "QCheckBox::indicator:checked{ border-image: url(:/icon/check.png); height: %1px; width: %1px;};").arg(CalPointH));
        CalStepCheckBox[i]  ->  setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
        if  (i > 0){
            CalStepCheckBox[i]->setDisabled(true);
        }
        CalGridLayout   ->  addWidget(CalStep[i]        , i + 1,  0);
        CalGridLayout   ->  addWidget(UserCalLabel[i]   , i + 1 , 1);
        CalGridLayout   ->  addWidget(ChnRawData[i]     , i + 1 , 2);
        CalGridLayout   ->  addWidget(CalStepCheckBox[i], i + 1 , 3);
    }
    UserCalLabel[0] ->  setText("ZERO");
    ui->scrollCalPoint->setWidget(CalPointsFrame);
    ui->scrollCalPoint->setMinimumWidth(RealLabelW*2);
    ui->scrollCalPoint->setMaximumWidth(RealLabelW*4+SideMargin*2);
    ui->CoBoxInputType->setMinimumWidth(RealLabelW);
    CalPointsFrame  ->  setLayout(CalGridLayout);
    useless1 = new QLabel("Step");
    useless2 = new QLabel("Cal Input");
    useless3 = new QLabel("Raw Data");
    useless2->setAlignment(Qt::AlignHCenter);
    useless3->setAlignment(Qt::AlignHCenter);
    CalGridLayout   ->  addWidget(useless1 , 0, 0);
    CalGridLayout   ->  addWidget(useless2 , 0, 1);
    CalGridLayout   ->  addWidget(useless3 , 0, 2);
    CalGridLayout   ->  setHorizontalSpacing(SideMargin/SideMargin);

// scrollbar - calib:
    scroll_bar  = new QScrollBar;
    scroll_bar  = ui->scrollArea  -> horizontalScrollBar();
    scroll_bar  -> setTracking(true);
    scroll_bar  -> setSingleStep(RealLabelW+SideMargin/1.5);
    connect(scroll_bar, SIGNAL(sliderPressed()),    this,   SLOT(slider_Pressed()))  ;
    connect(scroll_bar, SIGNAL(sliderReleased()),   this,   SLOT(slider_Released())) ;
    connect(scroll_bar, SIGNAL(sliderReleased()),   this,   SLOT(scroll_movement())) ;

    ui->btn_stopGraph->hide();
    setup_combobox();
    setup_customPlot();

    resizer =  new QTimer;
    resizer->start(10);
    connect(resizer,SIGNAL(timeout()),this,SLOT(size_tracker()));
}
void DLCalMenu::size_tracker()      // TODO
{
    int w = ui->tabWidget->width();
  //  qDebug()<<Fontsize;
    if (w<3840){
        for(w=w ; w<3840 ; w++){
            w=w;
            Fontsize++;
            //qDebug()<<Fontsize;
        }
    }
}

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
void DLCalMenu::setup_combobox()
{
    // Ports tab :
    ui->combo_portType      -> addItem("Choose port",0);
    ui->combo_portType      -> addItem("USB",1);
    ui->combo_portType      -> addItem("Ethernet",2);
    ui->combo_portType      -> addItem("RTU",3);
    // Main tab :
    ui->CoBoxInputType      -> insertItem(0, QObject::tr("LoadCell 1-2mV/V"));
    ui->CoBoxInputType      -> insertItem(1, QObject::tr("LoadCell 3mV/V"));
    ui->CoBoxInputType      -> insertItem(2, QObject::tr("0-100mV Transducer"));
    ui->CoBoxInputType      -> insertItem(3, QObject::tr("0-100mV Transducer Differential"));
    ui->CoBoxInputType      -> insertItem(4, QObject::tr("0-10V Transducer"));
    ui->CoBoxInputType      -> insertItem(5, QObject::tr("4-20mA Transducer"));
    ui->CoBoxInputType      -> insertItem(6, QObject::tr("LVTD Single Ended Output"));
    ui->CoBoxInputType      -> insertItem(7, QObject::tr("LVTD Diffrential Output"));
    ui->CoBoxInputType      -> insertItem(8, QObject::tr("120 Ohm Single strain Gauge"));
    ui->CoBoxInputType      -> insertItem(9, QObject::tr("120 Ohm Dual strain Gauge"));
    ui->CoBoxInputType      -> insertItem(10, QObject::tr("350 Ohm Single strain Gauge"));
    ui->CoBoxInputType      -> insertItem(11, QObject::tr("350 Ohm Dual strain Gauge"));
    ui->CoBoxInputType      -> insertItem(12, QObject::tr("1000 Ohm Single strain Gauge"));
    ui->CoBoxInputType      -> insertItem(13, QObject::tr("1000 Ohm Dual strain Gauge"));
    ui->CoBoxInputType      -> insertItem(14, QObject::tr("Custom 1"));
    ui->CoBoxInputType      -> insertItem(15, QObject::tr("Custom 2"));
    ui->CoBoxInputType      -> insertItem(16, QObject::tr("Custom 3"));
    ///CoBoxInputType   ->setItemData(5,5, Qt::UserRole - 1); pasif etme
    ui->CoBoxInputType      -> setCurrentText("LoadCell 1-2mV/V");
    ui->CoBoxInputType      -> setCurrentIndex(0);
    ui->CoBoxSampeRate      -> addItem("2"  ,0);
    ui->CoBoxSampeRate      -> addItem("4"  ,1);
    ui->CoBoxSampeRate      -> addItem("8"  ,2);
    ui->CoBoxSampeRate      -> addItem("16" ,3);
    ui->CoBoxSampeRate      -> addItem("32" ,4);
    ui->CoBoxSampeRate      -> addItem("64" ,5);
    ui->CoBoxSampeRate      -> addItem("128",6);
    ui->CoBoxSampeRate      -> addItem("256",7);
    ui->CoBoxSampeRate      -> addItem("512",8);
    ui->CoBoxSampeRate      -> addItem("1024",9);
    ui->CoBoxSampeRate      -> setCurrentIndex(3);
    ui->CoBoxDataFormat     -> addItems(QStringList() << tr("#####") << tr("####.#") << tr("###.##") << tr("##.###"));
    ui->CoBoxDataFormat     -> setCurrentText("#####");
    ui->CoBoxDataFormat     -> setCurrentIndex(0);
    ui->CoBoxSampeRate      -> setCurrentText("8");
    ui->CoBoxFilterType     -> addItem("None"       ,0);
    ui->CoBoxFilterType     -> addItem("Average"    ,1);
    ui->CoBoxFilterType     -> addItem("Moving Average",2);
    ui->CoBoxFilterType     -> addItem("EMA"        ,3);
    ui->CoBoxFilterType     -> addItem("Butterworth",4);
    ui->CoBoxFilterType     -> setCurrentText("None");
    ui->CoBoxFilterType     -> setCurrentIndex(0);
    ui->combo_rawreal       -> addItem("Real"   ,0);
    ui->combo_rawreal       -> addItem("Raw"    ,1);
    ui->combo_rawreal       -> setCurrentIndex(0);
    ui->combo_recPeriod     -> addItem("500"    ,0);    //1sn
    ui->combo_recPeriod     -> addItem("2500"   ,1);    //5sn
    ui->combo_recPeriod     -> addItem("5000"   ,2);    //10sn
    ui->combo_recPeriod     -> addItem("15000"  ,3);    //30sn
    ui->combo_recPeriod     -> addItem("30000"  ,4);    //1dk
    ui->combo_recPeriod     -> addItem("150000" ,5);    //5dk
    ui->combo_recPeriod     -> addItem("300000" ,6);    //10dk
    ui->combo_recPeriod     -> addItem("900000" ,7);    //30dk
    ui->combo_recPeriod     -> setCurrentIndex(1);
//    combo_device        -> addItem("Current device",0);     // DIALOG TOO
//    combo_device        -> addItem("External",1);
//    combo_device        -> addItem("SD Card",2);
//    combo_device        -> setCurrentIndex(0);
    ui->CoBoxChannel        -> setCurrentText("Channel 1");
    ui->CoBoxChannel        -> setCurrentIndex(0);
}
int DLCalMenu::GetScreenHRes(int s){
    auto screens = QGuiApplication::screens();
    qDebug() << "Ekran Listesi " << screens.count();
    int i = 0;
    if (screens.count() >= 1) i = s;
    auto SecScrenRect = screens[s]->geometry();
    QString Text = QString ("%1 Ekran Resolution "). arg(s);//.arg(s));
    qDebug() << Text << SecScrenRect;
    auto px = screens[i]-> physicalDotsPerInchX(); //size();
    auto lx = screens[i]-> logicalDotsPerInchX();
    //QRect rec = QGuiApplication::primaryScreen()->geometry();
    QRect rec = screens[i]->geometry();
    ScreenWidth = rec.width();
    ScreenHeight = rec.height();
    Text = QString ("%1 Ekran"). arg(s);
    qDebug() << Text << "Yatay:" << ScreenWidth << "Pixel  &  Dikey : " << ScreenHeight << "Pixel";
    qDebug() << Text << "Yatay Faktor:"  << "PX =" << px << "LX " << lx << "SR =" << lx/px;
    i = (1000*px)/lx;
    if (px >= lx) i = (1000*lx)/px;;
    return (i) ;
    return ((1000*lx)/px) ;
}
int DLCalMenu::GetScreenVRes(int s){
    auto screens = QGuiApplication::screens();
    auto ly = screens[s]-> physicalDotsPerInchY(); //size();
    auto py = screens[s]-> logicalDotsPerInchY();
    QString Text = QString (" %1 Ekran Dikey Faktor "). arg(s);//.arg(s));
    qDebug() << Text<< "PY =" << py << "LY " << ly << "SR =" << py / ly;
    int i = (1000*py)/ly;
    if (py >= ly) i = (1000*ly)/py;;
    return (i) ;
}
DLCalMenu::~DLCalMenu()
{
    delete ui;
}


