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
    m_serial(new QSerialPort(this)),
    watch(new stopwatch()),
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
        SideMargin = hr*10/i;
        RealLabelH = vr*30/i;
        RealLabelW = hr*180/i;
        RealLCDH = vr*40/i;
        RawLCDH  = vr*50/i;
        CalPointH = vr*38/i;
        CalPointW = vr*86/i;
        ToolH = vr*60/i;
        CalibScrollH = RealLCDH*2+RealLabelH*2+SideMargin*3;
        MainScrollW = RealLabelW;
        TabBarH = hr*135/i;
        TabBarW = hr*100/i;
        AppW = hr*1260/i;
        AppH = vr*795/i;
        qDebug()<<"Screen Width <= 1920 :?"<<ScreenWidth;
    }
    else if (ScreenWidth > 1920){
        Fontsize = 13;
        FontsizeTab = 13;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/i;
        RealLabelH = vr*30/i;
        RealLabelW = hr*180/i;
        RealLCDH = vr*40/i;
        RawLCDH  = vr*50/i;
        CalPointH = vr*38/i;
        CalPointW = vr*86/i;
        ToolH = vr*60/i;
        CalibScrollH = RealLCDH*2+RealLabelH*2+SideMargin*3;
        MainScrollW = RealLabelW;
        TabBarH = hr*135/i;
        TabBarW = hr*100/i;
        AppW = hr*1260/i;
        AppH = vr*795/i;
        qDebug()<<"Screen Width > 1920 :?"<<ScreenWidth;
    }
    else if  (ScreenWidth == 3840){
        i = i/2;
        Fontsize =18;
        FontsizeTab = 20;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/i;
        RealLabelH = vr*20/i;
        RealLabelW = hr*130/i;
        RealLCDH = vr*30/i;
        RawLCDH  = vr*20/i;
        CalPointH = vr*25/i;
        CalPointW = vr*60/i;
        ToolH = vr*40/i;
        CalibScrollH = RealLCDH*2+RealLabelH*2+SideMargin*3;
        MainScrollW = RealLabelW;
        TabBarH = hr*100/i;
        TabBarW = hr*70/i;
        AppW = hr*1260/i;
        AppH = vr*795/i;
        qDebug()<<"Screen Width == 3840 :?"<<ScreenWidth;
    }
    if  (ScreenHeight <= 960){        //dlcalmenu org
        i = 1500;
        Fontsize = 10;
        FontsizeTab = 9;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/i;
        RealLabelH = vr*30/i;
        RealLabelW = hr*180/i;
        RealLCDH = vr*45/i;
        CalPointH = vr*38/i;
        CalPointW = vr*86/i;
        ToolH = vr*60/i;
        CalibScrollH = RealLCDH*2+RealLabelH*2+SideMargin*3;
        MainScrollW = RealLabelW;
        TabBarH = hr*135/i;
        TabBarW = hr*100/i;
        AppW = hr*1260/i;
        AppH = vr*795/i;
        qDebug()<<"Screen Width :?"<<ScreenWidth;
        qDebug()<<"Screen Height <= 960 :?"<<ScreenHeight;
    }
    qDebug()<<"i"<<i;

    qDebug()<<"hr = "<<hr;
    qDebug()<<"vr = "<<vr;
    qDebug()<<"SideMargin"<<SideMargin;
    qDebug()<<"RealLabelH"<<RealLabelH;
    qDebug()<<"RealLabelW"<<RealLabelW;
    qDebug()<<"RealLcdH"<<RealLCDH;
    qDebug()<<"CalibScrollH"<<CalibScrollH;
    qDebug()<<"MainScrollW"<<MainScrollW;
    qDebug()<<"TabBarW"<<TabBarW;

    resize(AppW,AppH);
    ui->tabWidget->setCurrentIndex(0);
    ui->btn_stopGraph->hide();

    setup_GUI();

    tabBar = ui->tabWidget->tabBar();
    ui->tabWidget->setStyleSheet(QString("QTabBar::tab { width: %1px; height: %2px; font-size: %3pt}").arg(TabBarW).arg(TabBarH).arg(FontsizeTab)
                                 + QString("QLabel{font-family: Times New Roman; font-size: %1pt;} QComboBox,QPushButton,QRadioButton,QPushButton{font-family: Arial; font-size: %1pt; }").arg(Fontsize));
    tabBar   ->setStyle(new CustomTabStyle);
    tabBar_alarm = ui->tabWidget_alarm->tabBar();

// toolbar :
    ui->toolBar -> toggleViewAction()->setVisible(false);
    QWidget *spacer = new QWidget();
    QLabel  *logo = new QLabel;
    spacer  -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui      -> toolBar->addWidget(spacer);
    logo    -> setSizeIncrement(350, ToolH);
    logo    -> setPixmap(QPixmap(":/icon/logo.png"));
    logo    -> setContentsMargins(0,0,0,0);
    //ui->toolBar -> addWidget(logo);       // OPEN
    ui->toolBar -> setMaximumHeight(ToolH);
    ui->toolBar -> setIconSize(QSize(ToolH, ToolH));
    ui->toolBar -> setMovable(false);
    clear      = ui->toolBar -> addAction(QIcon(":/icon/clear.png") ,"Clear"       ,this, SLOT(ClearKey()));
    exportfile = ui->toolBar -> addAction(QIcon(":/icon/export.png"),"Export File");
    savefile   = ui->toolBar -> addAction(QIcon(":/icon/save.png")  ,"Save File"   ,this, SLOT(save()));
    openfile   = ui->toolBar -> addAction(QIcon(":/icon/open.png")  ,"Open File"   ,this, SLOT(open()));
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
            ChnLCDRaw[i]    -> setMinimumSize(RealLabelW, RawLCDH);
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
            ChnLCDReal[i]   -> setMinimumSize(RealLabelW, RawLCDH);
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
        UserCalLabel[i]     ->  setMinimumSize(CalPointW,CalPointH);
        UserCalLabel[i]     ->  setMaximumHeight(CalPointW);        // TODO
        ChnCalArray[0][8 + i] = QString::number((i)*200*10);

        ChnRawData[i]       =   new QLabel(QString::number(00).arg(i+1));
        ChnRawData[i]       ->  setText(QString::number((i+1)*2000));
        ChnRawData[i]       ->  setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ChnRawData[i]       ->  setFont(Font1);
        ChnRawData[i]       ->  setStyleSheet("font-family: Arial; border: 1px solid gray; margin-right: 5px ; padding: 1px; background-color: rgb(255,255,255);");
        ChnRawData[i]       ->  setMinimumSize(CalPointW,CalPointH);
        ChnRawData[i]       ->  setMaximumHeight(CalPointW);        // TODO
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
}
void DLCalMenu::setup_GUI()
{
    setup_combobox();
    setup_customPlot();
    get_password();

    KeyTimer = new QTimer(this);
    btn_startStop   = new QPushButton(ui->wdgHidden);
    ScrollBarGain   = new QScrollBar(Qt::Horizontal,(ui->wdgHidden));
    Gain            = new QLabel("Gain",ui->wdgHidden);
    LblScrollBarGain= new QLabel(ui->wdgHidden);

    ScrollBarGain   -> hide();
    LblScrollBarGain-> hide();
    Gain            -> hide();
    btn_startStop   -> hide();

    connect(this->KeyTimer         , SIGNAL(timeout())        , this, SLOT(update_time()));
    connect(this->btn_startStop    , SIGNAL(clicked())        , this, SLOT(timer_startStop()));
    connect(this->ScrollBarGain    , SIGNAL(valueChanged(int)), this, SLOT(ScrollBarGain_valueChange(int)));
    connect(ui->CoBoxInputType     , SIGNAL(activated(int))   , this, SLOT(InputType_Warning(int)));
    connect(ui->CoBoxDataFormat    , SIGNAL(activated(int))   , this, SLOT(DataFormat_Changed()));
    connect(ui->CoBoxChannel       , SIGNAL(currentIndexChanged(int)), this, SLOT(Channel_itemChanged()));
    connect(ui->btnSendCalData     , SIGNAL(clicked())        , this, SLOT(SendCalDataToVTK()));
    connect(ui->btnWriteParDataToFlash, SIGNAL(clicked())   , this, SLOT(UpdateFlash())); // btnWriteParData slot

    // del
    resizer =  new QTimer;
    resizer->start(10);
    connect(resizer,SIGNAL(timeout()),this,SLOT(size_tracker()));
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
void DLCalMenu::timer_startStop()
{
    qDebug()<<"Seriport button clicked : timer";
    if(watch->isRunning()) {
        watch->pause();
    }
    else {
        watch->start();
    }
}
void DLCalMenu::resetTimer()
{
    ui->hundredthsText  -> setText("00");
    ui->secondsText     -> setText("00");
    ui->minutesText     -> setText("00");
    watch           -> reset();
}
void DLCalMenu::update_time()
{
    if(watch->isRunning()){
        qint64 time = watch->getTime();
        int d ;//= time / 1000 / 60;                         // day      //TODO
        int h = time / 1000 / 60 / 60;                       // hour
        int m = (time / 1000 / 60) - (h * 60);               // min
        int s = (time / 1000) - (m * 60);                    // sec
        int ms = time - ( s + ( m + ( h * 60)) * 60) * 1000; // for miliseconds
        int ms_dis = ms / 10;
        /* if(d < 10) {
             daysText->setText(QString("0%1").arg(d));
         }
         else {
             daysText->setText(QString("%1").arg(d));
          ui->daysText->setText("00");*/
        if(h < 10) {
            ui->hundredthsText->setText(QString("0%1").arg(h));
        }
        else {
            ui->hundredthsText->setText(QString("%1").arg(h));
        }
        if(m < 10) {
            ui->minutesText ->setText(QString("0%1").arg(m));
        }
        else {
            ui->minutesText ->setText(QString("%1").arg(m));
        }
        if(s < 10) {
            ui->secondsText ->setText(QString("0%1").arg(s));
        }
        else {
            ui->secondsText ->setText(QString("%1").arg(s));
        }
    }
}
void DLCalMenu::on_m_SetSerialPortButton_clicked()
{
    QString PortName;
    PortName = ui->m_serialPortComboBox->currentText();
    ///serial->setPortName("com6");
    ///serial->setPortName(m_serialPortComboBox->currentText());
    m_serial->setPortName(PortName);
    ///
    m_serial->setBaudRate   (QSerialPort::Baud115200);
    m_serial->setDataBits   (QSerialPort::Data8);
    m_serial->setParity     (QSerialPort::NoParity);
    m_serial->setStopBits   (QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if  (m_serial->open     (QIODevice::ReadWrite)){
        ui->m_SetSerialPortButton->setText("CLOSE PORT");
        ui->m_SetSerialPortButton->setStyleSheet("color: rgb(255,40,0); font-weight: bold;"
                                             "background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:0.516727, stop:0 rgba(202, 202, 202, 255), stop:0.658416 rgba(0, 0, 0, 255));");
        ///m_RequestLineEdit->setFocus();
        btn_startStop   -> clicked(); // del*
        KeyTimer        -> start(100);
        openfile        -> setDisabled(true);
    }
    else{
        m_serial -> close();
        ui->m_SetSerialPortButton->setText("OPEN PORT");
        ui->m_SetSerialPortButton->setStyleSheet("color: yellow; font-weight: bold;"
                                             "background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:0.516727, stop:0 rgba(202, 202, 202, 255), stop:0.658416 rgba(0, 0, 0, 255));");
        btn_startStop       -> clicked(); // del*
        KeyTimer            -> stop();
        openfile            -> setDisabled(false);
    }
}
void DLCalMenu::SaveCalPartoArray(int chnno)   ///VF10
{
    ChnCalArray[chnno][0] = QString::number(chnno);                              /// Sa/Channel no
    ChnCalArray[chnno][2] = QString::number(ui->CoBoxDataFormat -> currentIndex());  /// Save Dp Location
    ChnCalArray[chnno][3] = QString::number(ui->CoBoxInputType  -> currentIndex());  /// Save Input Type
    ChnCalArray[chnno][4] = QString::number(ui->CoBoxSampeRate  -> currentIndex());  /// Save sample Rate
    ChnCalArray[chnno][5] = QString::number(ui->CoBoxFilterType -> currentIndex());  /// Save Filter Type
    ChnCalArray[chnno][6] = QString::number(ScrollBarGain -> value());         /// Save Optional Gain
    int i,j;
    QString dd = "00000";
    ///qDebug() << "Ayrilan Data : " << str <<  UserCalLabel[1]->text() << '\n';
    for (i = 0 ; i < MaxCalPoint ; i++ ) {
        if  (i > 0) {
            dd = UserCalLabel[i]->text();
            if  ((dd !="") && (PreDpLoc > 0)){
                j = dd.size() - 1;
                dd = dd.left(j - (PreDpLoc)) + dd.right(PreDpLoc);
            }
        }
        ChnCalArray[chnno][8 + i] = dd;                  ///Store Cal Previous Channel Keyed Value
        dd = ChnRawData[i] -> text();
        ChnCalArray[chnno][8 + MaxCalPoint + i] = dd;    ///Store Cal Previous Channel Raw Value
    }
}
void DLCalMenu::DisplayCalPar(int chnno)    ///VF10
{
    int i,j;
    ui->CoBoxChannel    ->  setCurrentIndex(chnno);
    ui->CoBoxDataFormat ->  setCurrentIndex(ChnCalArray[chnno][2].toInt());
    ui->CoBoxInputType  ->  setCurrentIndex(ChnCalArray[chnno][3].toInt());
    ui->CoBoxSampeRate  ->  setCurrentIndex(ChnCalArray[chnno][4].toInt());
    ui->CoBoxFilterType ->  setCurrentIndex(ChnCalArray[chnno][5].toInt());
    ScrollBarGain   ->  setValue(ChnCalArray[chnno][6].toInt());
    int DpLoc = ui->CoBoxDataFormat->currentIndex();
    QString dd;
    for (i = 0; i < MaxCalPoint; i++ ) {
        dd = ChnCalArray[chnno][8 + i];      /// Get User Cal Value
        if  ((dd !="") && (DpLoc > 0)){      /// If text not empty and dp location = 0  no decimal
            j = dd.size();
            ///dd = dd.left(j - (DpLoc)) + "." + dd.right(DpLoc);
            dd = dd.left(j - (DpLoc)) + dd.right(DpLoc);
        }
        UserCalLabel[i]->setText(dd);
        dd = ChnCalArray[chnno][8 + MaxCalPoint + i];      ///Get Cal Raw Value
        ChnRawData[i] ->setText(dd); ///VF10
    }
    UserCalLabel[0]->setText("ZERO");
    ///i = ChnCalArray[chnno][1].toInt();
}
void DLCalMenu::DataFormat_Changed()    ///VF10
{
    QMessageBox message;
    message.setText("Your Calibration Data will be formated again");
    message.setIconPixmap(QPixmap(":/icon/okay.png"));
    message.setWindowTitle("Warning!");
    if  (message.exec() == QMessageBox::Ok){
        int chnno = ui->CoBoxChannel->currentIndex();
        PreDpLoc  = ui->CoBoxDataFormat->currentIndex();
        ChnCalArray[chnno][2] = QString::number(PreDpLoc); /// Save Dp Location
        DisplayCalPar(chnno);
    }
}
void DLCalMenu::InputType_Warning(int)
{
    QMessageBox message;
    if  (ui->CoBoxInputType->currentIndex() > 6){
        message.setText("Your device choice does not include this option.");
        message.setIconPixmap(QPixmap(":/icon/warning.png"));
        if  (message.exec() == QMessageBox::Ok){
            ui->CoBoxInputType->setCurrentIndex(0);
        }
    }
}
void DLCalMenu::Channel_itemChanged()
{
    int chnno = ui->CoBoxChannel -> currentIndex();
    if  (PreChnNo != chnno){
        ///Save Previous Channel Parameters
        SaveCalPartoArray(PreChnNo);
        PreChnNo = chnno;
        DisplayCalPar(PreChnNo);  ///VF10
    }
//    for (int i=0; i<MaxCalPoint; i++){        // open asap
//       CalStepCheckBox[i]-> setDisabled(true);
//       CalStepCheckBox[i]-> setChecked(false);
//    }
//    CalStepCheckBox[0]->setDisabled(false);
    ChecKutuNo = 0;
    ui->btnSendParData  -> setEnabled(true);
    ui->btnSendParData  -> setStyleSheet("background-color : none; ; color: rgb(220,0,0); ");
    ui->btnSendCalData  -> setDisabled(true);
    ui->btnSendCalData  -> setStyleSheet("background-color : none; ; color: rgb(210,120,120);");
    ui->btnWriteParDataToFlash  -> setDisabled(true);
    ui->btnWriteParDataToFlash  -> setStyleSheet("color: rgb(210,40,0); font-weight:bold; background-color: "
                                             "qlineargradient(spread:reflect, x1:0, y1:0.5, x2:0, y2:1, stop:0.618812 rgba(90, 90, 90, 255), stop:1 rgba(159, 159, 159, 255));");
}
void DLCalMenu::SendCalDataToVTK()
{
    QMessageBox message;
    message.setText("Calibration Data will be send to VTK845!");
    message.setIconPixmap(QPixmap(":/icon/okay.png"));
    message.exec();
    int chnno;
    char caldevicechn,caldeviceaddr;
    SendData = "SCAL D";
    chnno = ui->CoBoxChannel-> currentIndex();
    caldeviceaddr = 48 + (chnno/4);
    caldevicechn = 48 + (chnno % 4);

    DLCalMenu::SaveCalPartoArray(chnno);
    ///Send Channel Parameters such as ADCchannel, dp, input type, sample rate, filter type
    if(chnno>=4){
        SendData += caldeviceaddr;///"1";; // Select Slave Device 1
        SendData += caldevicechn;///ChnCalArray[chnno][0]; // ADC No = Channel No
    }
    else{
        SendData += caldevicechn;///ChnCalArray[chnno][0]; // ADC No = Channel No
        SendData += caldeviceaddr;///"1";; // Select Slave Device 1
    }
    SendData += ChnCalArray[chnno][2];  /// Dp Loaction
    if  (ChnCalArray[chnno][3].size() == 1)
        SendData += "0";
    SendData += ChnCalArray[chnno][3]; /// Input Type
    SendData += ChnCalArray[chnno][4]; /// Sample Rate
    SendData += ChnCalArray[chnno][5]; /// Filter Type
    SendData += "0";                   /// Filter Parameter
    SendData += ChnCalArray[chnno][6]; /// Optional Gain
    SendData += "K";
    ///Send Cal Keyed Entry
    QString Ar;
    for (int i = 0; i < MaxCalPoint; i++){
        Ar = ChnCalArray[chnno][8 + i];
        if  (Ar =="") i = MaxCalPoint;
        else {
            SendData += Ar;
            SendData += ":"; ///Place serator between user cal values
        }
    }
    ///Send Raw data
    SendData += "R";
    for (int i = 0; i < MaxCalPoint; i++){
        ///SendData += ChnCalArray[chnno][8 + MaxCalPoint + i];
        ///SendData += " ";
        Ar = ChnCalArray[chnno][8 + MaxCalPoint + i];
        if  (Ar =="") i = MaxCalPoint;
        else {
            SendData += Ar;
            SendData += ":";   ///Place serator between raw values
        }
    }
    SendData += "\r\n";
    ComSendType = "CAL";
    ui->btnSendCalData         -> setDisabled(true);
    ui->btnSendCalData         -> setStyleSheet("background-color : none; ; color: rgb(210,120,120); ");
    ui->btnWriteParDataToFlash -> setEnabled(true);
    ui->btnWriteParDataToFlash -> setStyleSheet("color: rgb(255,40,0); font-weight:bold; "
                                          "background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:0.516727, stop:0 rgba(202, 202, 202, 255), stop:0.658416 rgba(0, 0, 0, 255));");
}
void DLCalMenu::UpdateFlash()
{
    QMessageBox message;
    message.setText("Selected Channell Calibration Data will be saved to VTK845 internal memory!");
    message.setIconPixmap(QPixmap(":/icon/saved.png"));
    message.exec();
    int chnno;
    static char caldevicechn,caldeviceaddr;
    SendData = "SCAL U";
    chnno = ui->CoBoxChannel-> currentIndex();
    caldeviceaddr = 48 + (chnno/4);
    caldevicechn = 48 + (chnno % 4);

    SendData += caldevicechn;//ChnCalArray[chnno][0]; // ADC No = Channel No
    SendData += caldeviceaddr;//"1";; // Select Slave Device 1
    SendData += "\r\n";
    ComSendType = "CAL";
    //SendData = "SCAL D";

    ui->btnSendParData -> setEnabled(true);
    ui->btnSendParData -> setStyleSheet("background-color : none; ; color: rgb(220,0,0);");
    ui->btnWriteParDataToFlash -> setDisabled(true);
    ui->btnWriteParDataToFlash->setStyleSheet("color: rgb(210,40,0); font-weight: bold; background-color: qlineargradient(spread:reflect, x1:0, y1:0.5, x2:0, y2:1, stop:0.618812 rgba(90, 90, 90, 255), stop:1 rgba(159, 159, 159, 255));");
}
void DLCalMenu::ClearKey()
{
    mouseevent = true;

    int chnno = ui->CoBoxChannel -> currentIndex();
    for (int i=1; i<MaxCalPoint; i++){
           UserCalLabel[i]->clear();
    }
    for (int i=0; i<MaxCalPoint; i++){
           ChnRawData[i]->clear();
           ChnCalArray[chnno][8 + i] = "";
           ChnCalArray[chnno][8 + MaxCalPoint + i] = "";
           CalStepCheckBox[i]-> setDisabled(true);
           CalStepCheckBox[i]-> setChecked(false);
           ///CalStepCheckBox[i]-> setEnabled()   clearMask() ;
    }      ///CalStepCheckBox[i]->setDisabled(true);
    CalStepCheckBox[0]->setDisabled(false);
    ChecKutuNo = 0;
    ///CalStepCheckBox[j]->setDisabled(false)
}
void DLCalMenu::save()
{
    QString fileName;
       /// int i = 0;
       /// if (i== 0) i = 1;
        if (currentFile.isEmpty()) {
            fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save"), "",
                                                    tr(".abk (*.abk);; All Files (*.*)"));;
            currentFile = fileName;
        }
        else{
            fileName = currentFile;
        }
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString CalValStr, RawValStr;
        int j = ui->CoBoxChannel->currentIndex();
        QString ChnNoStr = "Channel No   : " + ui->CoBoxChannel->currentText() + "\n";    // Save
       /// UserFileArray[j][8+0] = ChnNoStr;//Ayca_8+0, 8+2 ... lardan 8 leri kaldirdim.
        UserFileArray[j][0] = ChnNoStr;
        QString DpLocStr = "Data Format  : " + QString::number(ui->CoBoxDataFormat->currentIndex())+" " + ui->CoBoxDataFormat->currentText() + "\n"; // Save Dp Location
       /// UserFileArray[j][8+2] = DpLocStr;
        UserFileArray[j][2] = DpLocStr;
        QString InTypStr = "Input Type   : " + QString::number(ui->CoBoxInputType->currentIndex())+" " + ui->CoBoxInputType->currentText() + "\n";  // Save Input(Sensor/Source) Type
      ///  UserFileArray[j][8+3] = InTypStr;
        UserFileArray[j][3] = InTypStr;
        QString SamplStr = "Sample Rate  : " + QString::number(ui->CoBoxSampeRate->currentIndex())+" " + ui->CoBoxSampeRate->currentText() + "\n";  // Save Sample Rate
       /// UserFileArray[j][8+4] = SamplStr;
        UserFileArray[j][4] = SamplStr;
        QString FiltStr  = "Filter Type  : " + QString::number(ui->CoBoxFilterType->currentIndex())+" " + ui->CoBoxFilterType->currentText() + "\n"; // Save Filter Type
       /// UserFileArray[j][8+5] = FiltStr ;
        UserFileArray[j][5] = FiltStr ;
        QString GaintStr = "User Gain    : " + LblScrollBarGain->text() + "\n";     // Save User Gain
       /// UserFileArray[j][8+6] = GaintStr;
        UserFileArray[j][6] = GaintStr;
        /// Kayitlarin onune text koymamin nedeni kayitlarin text olarak acik olmasini saglamak, daha sonra sadelestirilebilir 'TODO'
        /// ikiye ayirmamin nedeni; i'nin hem tek haneli hem de cift haneli olmasi nedeni ile kayittaki gorunus bozuklugunu onlemek
        for (int i=0; i<MaxCalPoint; i++){
            if  (i==15){
                UserFileArray[j][9+MaxCalPoint+i]="....................\n";
            }
            if  (i<10){
                CalValStr += "Cal Value  " + QString::number(i) + " : " + UserCalLabel[i]->text() + "\n";
                RawValStr += "Raw Value  " + QString::number(i) + " : " + ChnRawData[i]->text() + "\n";
                UserFileArray[j][8+i]="Cal Value  " + QString::number(i) + " : " + UserCalLabel[i]->text() + "\n";
                UserFileArray[j][8+MaxCalPoint+i]="Raw Value  " + QString::number(i) + " : " + ChnRawData[i]->text() + "\n";
            }
            else{
                CalValStr += "Cal Value " + QString::number(i) + " : " + UserCalLabel[i]->text() + "\n";
                RawValStr += "Raw Value " + QString::number(i) + " : " + ChnRawData[i]->text() + "\n";
                UserFileArray[j][8+i]="Cal Value " + QString::number(i) + " : " + UserCalLabel[i]->text() + "\n";
                UserFileArray[j][8+MaxCalPoint+i]="Raw Value " + QString::number(i) + " : " + ChnRawData[i]->text() + "\n";
              }
        }    ///out << ChnNoStr << DpLocStr << InTypStr << SamplStr << FiltStr << GaintStr << CalValStr << RawValStr;
        for (j = 0; j < 4; j++ ) {
            for (int i=0; i<49; i++){
                out << UserFileArray[j][i];
                if  (UserFileArray[j][i] == "........") i = 50;
            }
        }
        file.close();
}
void DLCalMenu::saveAs()
{
    ///VF10
    SendData = "ZERO C" + QString::number(ui->CoBoxChannel->currentIndex()) + " \r\n";
    ComSendType = "RawZ";
}
void DLCalMenu::opening_val()   // to run app with saved data
{
    mouseevent = false;   // will be used
    //mouseevent = true;      // will be removed

    QString fileName = "/home/sila/Desktop/DL_grid/UserCalFile/AllChnCal.abk";  // baslangicta acilan dosya path'i yazilacak TODO
    setWindowTitle(fileName);

    QFile file;
    file.setFileName("/home/sila/Desktop/DL_grid/UserCalFile/AllChnCal.abk"); // baslangicta acilan dosya path'i yazilacak TODO
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString text;
    QString chnno,formt;
    int k = 0;
    for (int j = 0; j < 4 ; j++ ) {
        chnno = in.readLine();
        k = 0;
        UserFileArray[j][k] = chnno +"\n";
        chnno = chnno.mid(15,10);
        formt = ui->CoBoxChannel -> currentText(); /// test channel file nane with selected channel name
        if  (chnno == formt){
            formt = in.readLine();
            k = 2;
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxDataFormat -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxInputType -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxSampeRate -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxFilterType -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            k = 8;
            for (int i=0; i<MaxCalPoint; i++){
                text = in.readLine();
                UserFileArray[j][k] = text +"\n"; k++;
                UserCalLabel[i]-> setText(text.mid(15,10));
            }
            for (int i=0; i<MaxCalPoint; i++){
                text = in.readLine();
                UserFileArray[j][k] = text +"\n"; k++;
                ChnRawData[i] -> setText(text.mid(15,10));

            }
            int i = ui->CoBoxChannel -> currentIndex();
            DLCalMenu::SaveCalPartoArray(i);
            PreChnNo = i;
        }
        else {      // TODO 16ch yap
            if (j == 0) formt = "Channel 1";
            else if (j == 1) formt = "Channel 2";
            else if (j == 2) formt = "Channel 3";
            else if (j == 3) formt = "Channel 4";
          ///  k = 0;
            if  (chnno == formt){
                ///Valid Chn Header Channel No   : Channel X
                formt = in.readLine();
                k = 2;
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][2] = formt.mid(15,1); /// Get Dp Location
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][3] = formt.mid(15,1); /// Get input type
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][4] = formt.mid(15,1); /// Get Sample rate
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][5] = formt.mid(15,1); /// Get Filter type
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][6] = formt.mid(15,1); /// Get User Gain
                k = 8;
                for (int i=0; i<MaxCalPoint; i++){
                    text = in.readLine();   /// Usel Calibration step Keyed Value
                    UserFileArray[j][k] = text+"\n"; k++;
                    ChnCalArray[j][8 + i] = text.mid(15,10);
                }
                for (int i=0; i<MaxCalPoint; i++){
                    text = in.readLine();   /// Get Calibration step rawdadata
                    UserFileArray[j][k] = text+"\n"; k++;
                    ChnCalArray[j][8 + MaxCalPoint + i] = text.mid(15,10);
                }
            }
        }
        /// pass line ...............................................
        text = in.readLine();
        UserFileArray[j][k] ="....................\n";// k++;
    }
    file.close();
}
void DLCalMenu::open()
{
    mouseevent = false;

    resetTimer();

    QString fileName;
    QString filters("ABK files (*.abk);; All files (*.*)");
    QString defaultFilter("ABK files (*.abk)");
    fileName = QFileDialog::getOpenFileName(this, tr("Open Calibration Data file"),QCoreApplication::applicationDirPath(),
                                            filters, &defaultFilter);
    ///fileName = QFileDialog::getOpenFileName(this, tr("Open the file"), "/UserCalFile", tr("Text Files (*.ABK)"));
    ///fileName = "AllChnCal.ABK";
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text;
    QString chnno,formt;
    int k = 0;
    for (int j = 0; j < 4 ; j++ ) {
        chnno = in.readLine();
        k = 0;
        UserFileArray[j][k] = chnno +"\n";
        chnno = chnno.mid(15,10);
        formt = ui->CoBoxChannel -> currentText(); /// test channel file nane with selected channel name
        if  (chnno == formt){
            formt = in.readLine();
            k = 2;
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxDataFormat -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxInputType -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxSampeRate -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            ui->CoBoxFilterType -> setCurrentIndex(formt.midRef(15,1).toInt());
            formt = in.readLine();
            UserFileArray[j][k] = formt +"\n"; k++;
            k = 8;
            for (int i=0; i<MaxCalPoint; i++){
                text = in.readLine();
                UserFileArray[j][k] = text +"\n"; k++;
                UserCalLabel[i]-> setText(text.mid(15,10));
            }
            for (int i=0; i<MaxCalPoint; i++){
                text = in.readLine();
                UserFileArray[j][k] = text +"\n"; k++;
                ChnRawData[i] -> setText(text.mid(15,10));

            }
            int i = ui->CoBoxChannel -> currentIndex();
            DLCalMenu::SaveCalPartoArray(i);
            PreChnNo = i;
        }
        else {
            if (j == 0) formt = "Channel 1";
            else if (j == 1) formt = "Channel 2";
            else if (j == 2) formt = "Channel 3";
            else if (j == 3) formt = "Channel 4";
          //  k = 0;
            if  (chnno == formt){
                ///Valid Chn Header Channel No   : Channel X
                formt = in.readLine();
                k = 2;
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][2] = formt.mid(15,1); /// Get Dp Location
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][3] = formt.mid(15,1); /// Get input type
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][4] = formt.mid(15,1); /// Get Sample rate
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][5] = formt.mid(15,1); /// Get Filter type
                formt = in.readLine();
                UserFileArray[j][k] = formt+"\n"; k++;
                ChnCalArray[j][6] = formt.mid(15,1); /// Get User Gain
                k = 8;
                for (int i=0; i<MaxCalPoint; i++){
                    text = in.readLine();   /// Usel Calibration step Keyed Value
                    UserFileArray[j][k] = text+"\n"; k++;
                    ChnCalArray[j][8 + i] = text.mid(15,10);
                }
                for (int i=0; i<MaxCalPoint; i++){
                    text = in.readLine();   /// Get Calibration step rawdadata
                    UserFileArray[j][k] = text+"\n"; k++;
                    ChnCalArray[j][8 + MaxCalPoint + i] = text.mid(15,10);
                }
            }
        }
        /// pass line ...............................................
        text = in.readLine();
        UserFileArray[j][k] ="....................\n";// k++;
    }
    file.close();

///    LblScrollBarGain->setText(gan);
///    int LabelScrollW= 40;//fixed
///    int LabelScrollObjH =40;//fixed
///    int y = 250;
///    int xx = gan.toInt();
///    int CalScrollBarW = 400;
///    int lblscrolx = CalScrollBarW-68; //toplam width - "<" + ">" cikar kayma uzunluÄŸu
///    int x = 254 +((lblscrolx-LabelScrollW)*xx/7); //254 lbl baslama noktasÄ± + (toplamdan kalan deger (lblscrolx) - lbl width (LabelScrollW) ) *7 x=scrol uzerinde mesafe artis sayisi(tikladica gidilen mesafe)
///    LblScrollBarGain->setGeometry(x,y,LabelScrollW,LabelScrollObjH);
///    ScrollBarGain->setValue(xx);
}
void DLCalMenu::ScrollBarGain_valueChange(int value)
{
    LblScrollBarGain->setText(QString::number(value));
    int LabelScrollW= 40;///fixed
    int LabelScrollObjH =40;///fixed
    int y = 490;
    int CalScrollBarW = 400;
    int lblscrolx = CalScrollBarW-68; ///toplam width - "<" + ">" cÄ±kar kayma uzunluÄŸu
    int x = 254 +((lblscrolx-LabelScrollW)*value/7); ///254 lbl baslama noktasÄ± + (toplamdan kalan deger (lblscrolx) - lbl width (LabelScrollW) ) *7 x=scrol uzerinde mesafe artis sayisi(tikladica gidilen mesafe)
    ///LblScrollBarGain->setGeometry(x,y,LabelScrollW,LabelScrollObjH);
    ///scrolbar width ne kadar olursa hesaplayip lblscrolx artma ve azalma noktasina otomatik donuyor
}
// ekleniyör
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
void DLCalMenu::mousePressEvent(QMouseEvent *event)
{
    int i = 0;
    QFont Font1 ("Arial", Fontsize, QFont::Normal);
//    UserCalLabel[i]->setFont(Fontsize);       // open asap

    if(mouseevent){ //|| !openfile->isChecked()){
        //qDebug()<<"mouse event = enable";
        psw_widget = childAt(event->pos());
        ui->m_SetSerialPortButton -> setEnabled(true);
        ui->btnSendParData        -> setEnabled(true);
        ui->CoBoxChannel          -> setEnabled(true);
        ui->CoBoxDataFormat       -> setEnabled(true);
        ui->CoBoxFilterType       -> setEnabled(true);
        ui->CoBoxInputType        -> setEnabled(true);
        ui->CoBoxSampeRate        -> setEnabled(true);
        for (i = 0; i<MaxCalPoint; i++){
            if  (psw_widget == UserCalLabel[i]){
                if (UserCalLabelActive == false){
                UserCalLabelIndex = i;
                UserCalLabelActive = true;
                ///UserCalLabel[i]->setText("BASILAN " + QString::number(i+1));
                UserCalLabel[i]->setStyleSheet("background-color: rgb(255, 255, 255); border:1px solid black; margin-right: 5px; padding: 1px;");
                UserCalLabel[i]->setFocus();
                break;
                }
            }
        }
        if  ((UserCalLabelActive == true) && (i == MaxCalPoint)){
            /// mouse preseed at the outside of user calibration keyed area
            UserCalLabelActive = false;
            i=UserCalLabelIndex;
            UserCalLabel[i]->setStyleSheet("background-color: rgb(123, 168, 246); margin-right: 5px; padding: 1px; border: 1px solid rgb(83,128,186)");
        }
    }
     if(!mouseevent){ //&& openfile->isChecked()){
        psw_widget != childAt(event->pos());
        ui->m_SetSerialPortButton -> setDisabled(true);
        ui->btnSendParData        -> setDisabled(true);
        ui->CoBoxChannel          -> setDisabled(true);
        ui->CoBoxDataFormat       -> setDisabled(true);
        ui->CoBoxFilterType       -> setDisabled(true);
        ui->CoBoxInputType        -> setDisabled(true);
        ui->CoBoxSampeRate        -> setDisabled(true);
        //qDebug()<<"mouse event = disable";
        QMessageBox message;
        message.setText("Unable to authorize.\nGo 'Settings' to enter valid password!");
        message.setIconPixmap(QPixmap(":/icon/window_warning.png"));
        message.exec();
        return;
    }
    ///updateInterface(AddingMode);
}
void DLCalMenu::keyPressEvent(QKeyEvent *testevent)
{
    if  (KeyPressWait == true) {
        KeyStateCounter = 0;
        /// New Key Pressed
        /// Burdan hangi tusa basilinca kontrollerini yapabilirsin
        int i;
        QFont ComboFont("Arial", 12, QFont::Normal);
        if  (testevent->key() == Qt::Key_Return){
            KeyValue = testevent->key();
            UserCalLabelActive = false;
            i=UserCalLabelIndex;
            UserCalLabel[i]->setStyleSheet("background-color: rgb(123, 168, 246); margin-right: 5px; padding: 1px; border: 1px solid rgb(103,148,226)");
            UserCalLabel[i]->setFont(ComboFont);
        }
        else if  ((testevent->key() >= Qt::Key_0) && (testevent->key() <= Qt::Key_9)) {
            ///Textedit->setText("You pressed NumericKey 0 - 9");
            KeyValue = testevent->key();
            KeyPressWait = false;
            KeyPressedOk = true;
        }
        else if (testevent->key() == Qt::Key_Backspace) {
             KeyValue = testevent->key();
             KeyPressWait = false;
             KeyPressedOk = true;
        }
    }
}
void DLCalMenu::keyReleaseEvent(QKeyEvent *event)
{
    if  (KeyPressWait == false) {
        if  (event->key() >= Qt::Key_Escape){
            KeyReleasedOk = true;
        }
    }
}
DLCalMenu::~DLCalMenu()
{
    delete ui;
}




