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
    m_serial(new QSerialPort),
    watch   (new stopwatch()),
    wdgReals(new QWidget),
    dataBox (new QWidget),
    CalPointsFrame(new QFrame),
    ui(new Ui::DLCalMenu)
{
    ui->setupUi(this);
    hr = DLCalMenu::GetScreenHRes(0);
    vr = DLCalMenu::GetScreenVRes(0);
    pr = 1000;
    QFont Font1 ("Arial", Fontsize, QFont::Normal);

    if (ScreenWidth < 1680){       // opens properly
        pr = 1000;
        Fontsize = 12;
        FontsizeTab = 13;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/pr;
        RealLabelH = vr*23/pr;
        RealLabelW = hr*90/pr;
        RealLCDH = vr*32/pr;
        RawLabelW= hr*157/pr;
        RawLCDH  = vr*35/pr;    // increase
        CalPointH = vr*35/pr;
        CalPointW = vr*55/pr;
        ToolH = vr*45/pr;
        CalibScrollH = RawLCDH*2+RealLabelH*2+SideMargin*2;
        MainScrollW = RealLabelW;
        TabBarH = hr*105/pr;
        TabBarW = hr*85/pr;
        AppW = hr*1070/pr;
        AppH = vr*730/pr;
        qDebug()<<"Screen Width < 1680 :?"<<ScreenWidth;
    }
    else if (ScreenWidth >= 1680){
        Fontsize = 13;
        FontsizeTab = 13;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/pr;
        RealLabelH = vr*30/pr;
        RealLabelW = hr*180/pr;
        RealLCDH = vr*40/pr;
        RawLabelW= hr*180/pr;
        RawLCDH  = vr*35/pr;
        CalPointH = vr*38/pr;
        CalPointW = vr*86/pr;
        ToolH = vr*60/pr;
        CalibScrollH = RawLCDH*2+RealLabelH*2+SideMargin*2;
        MainScrollW = RealLabelW;
        TabBarH = hr*135/pr;
        TabBarW = hr*100/pr;
        AppW = hr*1260/pr;
        AppH = vr*795/pr;
        qDebug()<<"Screen Width >= 1680 :?"<<ScreenWidth;
    }
    else if  (ScreenWidth >= 3840){
        pr = pr/2;
        Fontsize =16;
        FontsizeTab = 18;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/pr;
        RealLabelH = vr*17/pr;
        RealLabelW = hr*75/pr;
        RealLCDH = vr*30/pr;
        RawLabelW= hr*120/pr;
        RawLCDH  = vr*20/pr;
        CalPointH = vr*20/pr;
        CalPointW = vr*60/pr;
        ToolH = vr*35/pr;
        CalibScrollH = RawLCDH*2+RealLabelH*2+SideMargin;
        MainScrollW = RealLabelW;
        TabBarH = hr*90/pr;
        TabBarW = hr*60/pr;
        qDebug()<<"Screen Width == 3840 :?"<<ScreenWidth;
    }
    if  (ScreenHeight <= 720){        //dlcalmenu org
        pr = 1500;
        Fontsize = 10;
        FontsizeTab = 9;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/pr;
        RealLabelH = vr*30/pr;
        RealLabelW = hr*180/pr;
        RealLCDH = vr*45/pr;
        RawLabelW= hr*130/pr;
        RawLCDH  = vr*25/pr;
        CalPointH = vr*38/pr;
        CalPointW = vr*86/pr;
        ToolH = vr*60/pr;
        CalibScrollH = RawLCDH*2+RealLabelH*2+SideMargin*3;
        MainScrollW = RealLabelW;
        TabBarH = hr*135/pr;
        TabBarW = hr*100/pr;
        AppW = hr*1200/pr;
        AppH = vr*650/pr;
        qDebug()<<"Screen Width :?"<<ScreenWidth;
        qDebug()<<"Screen Height <= 720 :?"<<ScreenHeight;
    }
    else if  (ScreenWidth <= 1024){        //dlcalmenu org
        pr = 1500;
        hr = 840;
        vr = 846;
        Fontsize = 10;
        FontsizeTab = 9;
        Font1.setPointSize(Fontsize);
        SideMargin = hr*10/pr;
        RealLabelH = vr*30/pr;
        RealLabelW = hr*180/pr;
        RealLCDH = vr*45/pr;
        RawLabelW= hr*130/pr;
        RawLCDH  = vr*35/pr;
        CalPointH = vr*38/pr;
        CalPointW = vr*86/pr;
        ToolH = vr*60/pr;
        CalibScrollH = RawLCDH*2+RealLabelH*2+SideMargin*3;
        MainScrollW = RealLabelW;
        TabBarH = hr*135/pr;
        TabBarW = hr*100/pr;
        AppW = hr*1250/pr;
        AppH = vr*600/pr;
        qDebug()<<"Screen Width <= 1024 :?"<<ScreenWidth;
        qDebug()<<"Screen Height :"<<ScreenHeight;
    }
    TabAlarmW = hr*240/pr;
    DialogH = hr*300/pr;
    DialogW = hr*500/pr;
    qDebug()<<"AppW"<<AppW<<", AppH"<<AppH;
//    qDebug()<<"pr"<<pr;
//    qDebug()<<"hr = "<<hr;
//    qDebug()<<"vr = "<<vr;
//    qDebug()<<"SideMargin"<<SideMargin;
//    qDebug()<<"RealLabelH"<<RealLabelH;
//    qDebug()<<"RealLabelW"<<RealLabelW;
//    qDebug()<<"RealLcdH"<<RealLCDH;
//    qDebug()<<"CalibScrollH"<<CalibScrollH;
//    qDebug()<<"MainScrollW"<<MainScrollW;
//    qDebug()<<"TabBarW"<<TabBarW;

    resize(AppW,AppH);
    ComSendType = "";

// tab widget :
    ui->tabWidget->setCurrentIndex(0);
    tabBar = ui->tabWidget->tabBar();
    ui->tabWidget->setStyleSheet(QString("QTabBar::tab { width: %1px; height: %2px; font-size: %3pt}").arg(TabBarW).arg(TabBarH).arg(FontsizeTab)
                   + QString("QLabel{font-family: Times New Roman; font-size: %1pt;} QComboBox,QLineEdit,QSpinBoxQCheckbox,QPushButton,QRadioButton{font-family: Arial; font-size: %1pt; }").arg(Fontsize));
    tabBar   ->setStyle(new CustomTabStyle);

// toolbar :
    ui->toolBar -> toggleViewAction()->setVisible(false);
    QLabel  *logo = new QLabel;
    QWidget *spacer = new QWidget;
    logo    -> setPixmap(QPixmap(":/icon/logo.png"));
    logo    -> setContentsMargins(SideMargin,0,0,0);
    spacer  -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->toolBar -> addWidget(logo);       // OPEN
    ui      -> toolBar->addWidget(spacer);
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
    connect (exportfile, SIGNAL(triggered()), this, SLOT(exportCsv()));

    KeyTimer        = new QTimer(this);
    timer_main      = new QTimer;
    btn_startStop   = new QPushButton(ui->wdgHidden);
    ScrollBarGain   = new QScrollBar(Qt::Horizontal,(ui->wdgHidden));
    Gain            = new QLabel("Gain",ui->wdgHidden);
    LblScrollBarGain= new QLabel(ui->wdgHidden);

// serial port:
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos){
        ui->m_serialPortComboBox->addItem(info.portName());
        ui->currentPort->setText(ui->m_serialPortComboBox->currentText());
    }
// scrollbar - main :
    grid_reals  = new QGridLayout(wdgReals);
    boxLayout   = new QGridLayout(dataBox);
    CalGridLayout = new QGridLayout(CalPointsFrame);
    ui->scrollReals->setWidget(wdgReals);
    ui->scrollReals->setWidgetResizable(1);
    ui->scrollReals->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll_main = new QScrollBar;
    scroll_main = ui->scrollReals -> verticalScrollBar();
    scroll_main -> setTracking(true);
    scroll_main -> setSingleStep(RealLCDH+RealLabelH+SideMargin/1.5);
    connect(scroll_main, SIGNAL(sliderPressed()),    this,   SLOT(slider_Pressed()));
    connect(scroll_main, SIGNAL(sliderReleased()),   this,   SLOT(slider_Released()));
    connect(scroll_main, SIGNAL(sliderReleased()),   this,   SLOT(scroll_movement()));

    for (int i=0; i<MaxChnCounts; i++){
        ChnLCDRaw.append(new QLCDNumber(CalPointsFrame));
    }
    for (int i=0; i<MaxChnCounts; i++){
        ChnLCDReal.append(new QLCDNumber(CalPointsFrame));
        ChnLCDReal_Main.append(new QLCDNumber(wdgReals));
    }
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
            ChnRawLabel[i]  -> setMinimumSize(RawLabelW, RealLabelH);
            ChnRawLabel[i]  -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
            ChnRawLabel[i]  -> setFont(Font1);

            ChnLCDRaw[i]    -> display(QString("%1000").arg(i+1));
            ChnLCDRaw[i]    -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDRaw[i]    -> setDigitCount(RawDigitCount);
            ChnLCDRaw[i]    -> setSmallDecimalPoint(true);
            ChnLCDRaw[i]    -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(255, 10, 0)");
            ChnLCDRaw[i]    -> setMinimumSize(RawLabelW, RawLCDH);
            ChnLCDRaw[i]    -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

            ChnRealLabel[i] = new QLabel(tr("Channel %1 Real").arg(i + 1),ui->scrollArea);
            ChnRealLabel[i] -> setAlignment(Qt::AlignCenter);
            ChnRealLabel[i] -> setFont(Font1);
            ChnRealLabel[i] -> setStyleSheet("font-family: Arial; background-color: rgb(10, 10, 10); color: rgb(255, 255, 255)");
            ChnRealLabel[i] -> setMinimumSize(RawLabelW, RealLabelH);
            ChnRealLabel[i] -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

            ChnLCDReal[i]   -> display(QString("%1000").arg(i+1));
            ChnLCDReal[i]   -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDReal[i]   -> setDigitCount(RealDigitCount);
            ChnLCDReal[i]   -> setSmallDecimalPoint(true);
            ChnLCDReal[i]   -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(50, 255, 0)");
            ChnLCDReal[i]   -> setMinimumSize(RawLabelW, RawLCDH);
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
            ui->CoBoxChannel    -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->combo_channels  -> addItem(QString(tr("Channel %1").arg(i+1)),i);
            ui->activeChannels  -> setText(ui->CoBoxChannel->currentText());
    }
    ui->combo_axis1 ->  addItem("Time",MaxChnCounts+1);
    ui->combo_axis1 ->  setCurrentIndex(MaxChnCounts);
    ui->scrollArea->setWidget(dataBox);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    dataBox     -> setLayout(boxLayout);
    boxLayout   -> setContentsMargins(0,0,0,0);
    dataBox -> setMaximumHeight(CalibScrollH*1.2);
    ui->scrollArea->setMinimumHeight(CalibScrollH+SideMargin);
    ui->scrollArea->setMaximumHeight((CalibScrollH+SideMargin)*1.1);

    // scrollbar - calib:
    scroll_bar  = new QScrollBar;
    scroll_bar  = ui->scrollArea  -> horizontalScrollBar();
    scroll_bar  -> setTracking(true);
    scroll_bar  -> setSingleStep(RawLabelW+SideMargin/1.5);
    connect(scroll_bar, SIGNAL(sliderPressed()),    this,   SLOT(slider_Pressed()))  ;
    connect(scroll_bar, SIGNAL(sliderReleased()),   this,   SLOT(slider_Released())) ;
    connect(scroll_bar, SIGNAL(sliderReleased()),   this,   SLOT(scroll_movement())) ;
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
        UserCalLabel[i]     ->  setStyleSheet("font-family: Arial; background-color: rgb(123, 168, 246); border: 1px solid rgb(83,128,206); margin-right: 5px;  padding: 1px;");
        UserCalLabel[i]     ->  setCursor(Qt::IBeamCursor);
        UserCalLabel[i]     ->  setMinimumSize(CalPointW,CalPointH);
        UserCalLabel[i]     ->  setMaximumHeight(CalPointW);        // TODO
        ChnCalArray[0][8 + i] = QString::number((i)*200*10);

        ChnRawData[i]       =   new QLabel;
        ChnRawData[i]       ->  setText(QString::number((i+1)*2000));
        ChnRawData[i]       ->  setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ChnRawData[i]       ->  setFont(Font1);
        ChnRawData[i]       ->  setStyleSheet("font-family: Arial; border: 1px solid gray; margin-right: 5px ; padding: 1px; background-color: rgb(255,255,255);");
        ChnRawData[i]       ->  setMinimumSize(CalPointW,CalPointH);
        ChnRawData[i]       ->  setMaximumHeight(CalPointW);        // TODO
        ChnCalArray[0][8 + 16 + i] = QString::number((i+1)*2000);

        CalStepCheckBox[i]  =   new QCheckBox;
        CalStepCheckBox[i]  ->  setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
        CalStepCheckBox[i]  ->  setCursor(Qt::PointingHandCursor);
        CalStepCheckBox[i]  ->  setStyleSheet(QString("QCheckBox::indicator {height: %1px; width: %1px;}"
                                                      "QCheckBox::indicator:checked{ border-image: url(:/icon/check.png); height: %1px; width: %1px;};").arg(CalPointH));
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
    ui->scrollCalPoint->setMinimumWidth(RawLabelW*2);
    ui->scrollCalPoint->setMaximumWidth(RawLabelW*4+SideMargin*2);
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

    password_correct = false;
    DisplayCalPar(0);
    setup_GUI();
}
void DLCalMenu::setup_GUI()
{
    setup_customPlot();
    setup_combobox();
    alarm_initialize();
    get_password();
    opening_val();          // open with saved values
    setup_tableView();

    connect(this->KeyTimer         , SIGNAL(timeout())        , this, SLOT(update_time()));
    connect(this->KeyTimer         , SIGNAL(timeout())        , this, SLOT(KeyTimerTimeOut()));
    connect(this->KeyTimer         , SIGNAL(timeout())        , this, SLOT(table_writeData()));
    connect(this->btn_startStop    , SIGNAL(clicked())        , this, SLOT(timer_startStop()));
    connect(this->ScrollBarGain    , SIGNAL(valueChanged(int)), this, SLOT(ScrollBarGain_valueChange(int)));
    connect(ui->btnSendParData     , SIGNAL(clicked())        , this, SLOT(SendCalParToVTK()));
    connect(ui->btnSendCalData     , SIGNAL(clicked())        , this, SLOT(SendCalDataToVTK()));
    connect(ui->btnWriteParDataToFlash, SIGNAL(clicked())     , this, SLOT(UpdateFlash())); // btnWriteParData slot
    connect(ui->CoBoxInputType     , SIGNAL(activated(int))   , this, SLOT(InputType_Warning(int)));
    connect(ui->CoBoxDataFormat    , SIGNAL(activated(int))   , this, SLOT(DataFormat_Changed()));
    connect(ui->CoBoxChannel       , SIGNAL(currentIndexChanged(int)), this, SLOT(Channel_itemChanged()));
    connect(ui->combo_axis1        , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_axis1_indexChanged(int)));
    connect(ui->combo_axis2        , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_axis2_indexChanged(int)));
    connect(ui->combo_portType     , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_portType_indexChanged(int)));
    connect(ui->CoBoxSampeRate     , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_sampeRate_indexChanged(int)));
    connect(ui->CoBoxFilterType    , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_filterType_indexChanged(int)));
    connect(ui->CoBoxInputType     , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_inputType_indexChanged(int)));
    connect(ui->combo_rawreal      , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_rawreal_indexChanged(int)));
    connect(this->combo_diaMain    , SIGNAL(currentIndexChanged(int)), this, SLOT(combo_diaCh_indexChanged(int)));

    ui->password    -> setEchoMode(QLineEdit::Password);
    ui->password    -> setPlaceholderText("Type password");
    ui->password    -> setClearButtonEnabled(true);
    ui->password    -> setMaxLength(4);
    ScrollBarGain   -> hide();
    LblScrollBarGain-> hide();
    Gain            -> hide();
    btn_startStop   -> hide();
    ui->wdgGraph    -> show();
    tview_real  -> hide();
    tview_raw   -> hide();
    tview_file  -> hide();
    customPlot_main->show();
    exportfile -> setDisabled(true);
    ui->btn_dispGrap->hide();
    ui->btnSendCalData      -> setDisabled(true);
    ui->btnWriteParDataToFlash  -> setDisabled(true);
    ui->combo_channels      -> setDisabled(true);
    ui->combo_rawreal       -> setDisabled(true);
    ui->COMport             -> setDisabled(true);
    ui->adres               -> setDisabled(true);
    ui->timeout             -> setDisabled(true);
    ui->IP                  -> setDisabled(true);
    ui->channelName         -> setDisabled(true);
    ui->btn_saveChn         -> setDisabled(true);
    ui->radioBtn_csv        -> setChecked(true);
    ui->radioBtn_csv        -> setDisabled(true);
    ui->radioBtn_pdf        -> setDisabled(true);
    ui->btn_newPassword     -> setDisabled(true);
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
    ui->CoBoxFilterType     -> addItem("None",0);
    ui->CoBoxFilterType     -> addItem("Average",1);
    ui->CoBoxFilterType     -> addItem("Moving Average",2);
    ui->CoBoxFilterType     -> addItem("EMA",3);
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
        //int d ;//= time / 1000 / 60;                         // day      //TODO
        int h = time / 1000 / 60 / 60;                       // hour
        int m = (time / 1000 / 60) - (h * 60);               // min
        int s = (time / 1000) - (m * 60);                    // sec
        int ms = time - ( s + ( m + ( h * 60)) * 60) * 1000; // for miliseconds
        //int ms_dis = ms / 10;
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
    for (int i=0; i<MaxCalPoint; i++){
       CalStepCheckBox[i]-> setDisabled(true);
       CalStepCheckBox[i]-> setChecked(false);
    }
    CalStepCheckBox[0]  -> setDisabled(false);
    ChecKutuNo = 0;
    ui->btnSendParData  -> setEnabled(true);
    ui->btnSendParData  -> setStyleSheet("background-color : none; ; color: rgb(220,0,0); ");
    ui->btnSendCalData  -> setDisabled(true);
    ui->btnSendCalData  -> setStyleSheet("background-color : none; ; color: rgb(210,120,120);");
    ui->btnWriteParDataToFlash  -> setDisabled(true);
    ui->btnWriteParDataToFlash  -> setStyleSheet("color: rgb(210,40,0); font-weight:bold; background-color: "
                                             "qlineargradient(spread:reflect, x1:0, y1:0.5, x2:0, y2:1, stop:0.618812 rgba(90, 90, 90, 255), stop:1 rgba(159, 159, 159, 255));");
}
void DLCalMenu::SendCalParToVTK()   //** new
{
    QMessageBox message;
    message.setText("Calibration Data will be send to the VTK845!");
    message.setIconPixmap(QPixmap(":/icon/okay.png"));
    message.exec();
    int chnno;
    char caldevicechn,caldeviceaddr;
    SendData = "SCAL P";
    chnno = ui->CoBoxChannel-> currentIndex();
    caldeviceaddr  = 48 + (chnno/4);
    caldevicechn   = 48 + (chnno % 4);
    DLCalMenu::SaveCalPartoArray(chnno);

    //Send Channel Parameters such as ADCchannel, dp, input type, sample rate, filter type
    SendData += caldevicechn;//ChnCalArray[chnno][0]; // ADC No = Channel No
    SendData += caldeviceaddr;//"1";; // Select Slave Device 1
    SendData += ChnCalArray[chnno][2]; /// Dp Loaction
    if  (ChnCalArray[chnno][3].size() == 1)
        SendData += "0";
    SendData += ChnCalArray[chnno][3]; /// Input Type
    SendData += ChnCalArray[chnno][4]; /// Sample Rate
    SendData += ChnCalArray[chnno][5]; /// Filter Type
    SendData += "0";                   /// Filter Parameter
    SendData += ChnCalArray[chnno][6]; /// Optional Gain
    SendData += " ";
    SendData += "\r\n";
    ComSendType = "CAL";
    ui->btnSendParData -> setDisabled(true);
    ui->btnSendParData -> setStyleSheet("background-color : none; color: rgb(210,120,120); ");
    ui->btnSendCalData -> setEnabled(true);
    ui->btnSendCalData -> setStyleSheet("background-color : none; color: rgb(220,0,0); ");
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
    //mouseevent = false;   // will be used TODO
    mouseevent = true;      // will be removed  TODO

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
    //int LabelScrollObjH =40;///fixed
    //int y = 490;
    int CalScrollBarW = 400;
    int lblscrolx = CalScrollBarW-68; ///toplam width - "<" + ">" cÄ±kar kayma uzunluÄŸu
    //int x = 254 +((lblscrolx-LabelScrollW)*value/7); ///254 lbl baslama noktasÄ± + (toplamdan kalan deger (lblscrolx) - lbl width (LabelScrollW) ) *7 x=scrol uzerinde mesafe artis sayisi(tikladica gidilen mesafe)
    ///LblScrollBarGain->setGeometry(x,y,LabelScrollW,LabelScrollObjH);
    ///scrolbar width ne kadar olursa hesaplayip lblscrolx artma ve azalma noktasina otomatik donuyor
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
                UserCalLabel[i]->setStyleSheet("font-family: Arial; background-color: rgb(255, 255, 255); border:1px solid black; margin-right: 5px; padding: 1px;");
                UserCalLabel[i]->setFocus();
                break;
                }
            }
        }
        if  ((UserCalLabelActive == true) && (i == MaxCalPoint)){
            /// mouse preseed at the outside of user calibration keyed area
            UserCalLabelActive = false;
            i=UserCalLabelIndex;
            UserCalLabel[i]->setStyleSheet("font-family: Arial; background-color: rgb(123, 168, 246); margin-right: 5px; padding: 1px; border: 1px solid rgb(83,128,186)");
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
    QFont Font1 ("Arial", Fontsize, QFont::Normal);
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
            UserCalLabel[i]->setStyleSheet("font-family: Arial; background-color: rgb(123, 168, 246); margin-right: 5px; padding: 1px; border: 1px solid rgb(103,148,226)");
            UserCalLabel[i]->setFont(Font1);
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
void DLCalMenu::KeyTimerTimeOut()
{
    int i,j,chn,blz = 1, OkReceived=0;
    char m,k;
    int n;
    static int SeriErrCnt, RaworReal = 1;
    static QString ChnData,vl0,vl1,vl2,vl3,vl4,vl5,vl6,vl7,vl8,vl9,vl10,vl11,vl12,vl13,vl14,vl15,TestZeroStr;
    QString Test1;
    const QByteArray seriportData = m_serial->readAll();
    Test1 = seriportData;
    if  (Test1!=""){
            if  ((Test1[0] == "A") && (Test1[1] == "N") && (Test1[2] == "S")){
                for (chn = 0; chn < MaxChnCounts; chn++){
                    n = chn*11;
                    //ChnData = "";
                    k ='H';
                    m = 48+chn;
                    if(chn > 7){
                        k= 48+ (chn/4);
                        m= 48+ (chn%4);
                    }

                    if  (Test1[4+n] == k && Test1[5+n] == m){
                        ChnData = "";
                        vl0 = "";
                        j = 0;
                        ChnData += Test1[6+n];
                        TestZeroStr = "";
                        blz = 1;
                        for (i = 7+n; i < 14+n; i++){
                            //Getting data and blocking leading zeros
                            if  ((Test1[i] != "0") & (Test1[i] != " ")) {
                                ChnData += Test1[i];
                                blz = 0;   //end of leading zero blocking operation
                            }
                            else if (blz == 1) ChnData += " ";
                            else ChnData += "0";
                            j ++;
                            vl0 += Test1[i];
                        }
                        //if  (chn == 1) qDebug() << "Kanal 2 " << "REAL = " << vl0;
                        if  ((vl0.left(RawDigitCount - 1) == "000000")){
                            ChnData = "0"; //because input data = 0
                        }
                    ChnLCDRaw[chn] -> display(ChnData);
                    ChnRawDataQString[chn] = ChnData;
                    vl0 = ChnRawDataQString[0];
                    vl1 = ChnRawDataQString[1];
                    vl2 = ChnRawDataQString[2];
                    vl3 = ChnRawDataQString[3];
                    vl4 = ChnRawDataQString[4];
                    vl5 = ChnRawDataQString[5];
                    vl6 = ChnRawDataQString[6];
                    vl7 = ChnRawDataQString[7];
                    vl8 = ChnRawDataQString[8];
                    vl9 = ChnRawDataQString[9];
                    vl10 = ChnRawDataQString[10];
                    vl11 = ChnRawDataQString[11];
                    vl12 = ChnRawDataQString[12];
                    vl13 = ChnRawDataQString[13];
                    vl14 = ChnRawDataQString[14];
                    vl15 = ChnRawDataQString[15];
            }
         }
        }
        else  if  ((Test1[0] == "R") && (Test1[1] == "C") && (Test1[2] == "L")){    ///Test For Calibrated Real Data
            for (chn = 0; chn < MaxChnCounts; chn++){
                n = chn*11;
                ///ChnData = "";
                k = 'H';
                m = 48+chn;
                if(chn>7){
                    k = 48 + (chn/4);
                    m = 48 + (chn%4);
                }
                if  (Test1[4+n] == k && Test1[5+n] == m){
                    ChnData = "";
                    j = RealDigitCount - 1;
                    ChnData += Test1[6+n];
                    TestZeroStr = "";
                    blz = 1;
                    /// adjust real display size according to decimal point
                    if  (ChnCalArray[chn][2].toInt() >= 1) {
                        ChnLCDReal[chn]      -> setDigitCount(RealDigitCount+1);
                        ChnLCDReal_Main[chn] -> setDigitCount(RealDigitCount+1);
                    }
                    else {
                        ChnLCDReal[chn]      -> setDigitCount(RealDigitCount); /// for no decimal point
                        ChnLCDReal_Main[chn] -> setDigitCount(RealDigitCount); // real mainpage
                    }
                    ///
                    for (i = 8+n; i < 14+n; i++){
                        if  (ChnCalArray[chn][2].toInt() >= 1){
                            if  (j == (ChnCalArray[chn][2].toInt())) {
                                if  (blz == 1) {
                                    blz = 0;
                                    ChnData += "0";
                                }
                                ChnData += ".";
                            }
                        }
                        ///Getting data and blocking leading zeros
                        if  ((Test1[i] != "0") & (Test1[i] != " ")) {
                            ChnData += Test1[i];
                            blz = 0;   ///end of leading zero blocking operation
                        }
                        else if (blz == 1) ChnData += " ";
                        else ChnData += "0";
                        j --;
                        TestZeroStr += Test1[i];
                    }
                    if (TestZeroStr.left(RealDigitCount - 1) == "000000"){
                       ChnData = "0"; ///because input data = 0
                    }
                    ChnLCDReal[chn]      -> display(ChnData);
                    ChnLCDReal_Main[chn] -> display(ChnData); // real mainpage
                    ChnRealDataQString[chn] = ChnData;
                    if(ChnData.length()>3){
                        QString ChnData0 = ChnData.at(2);
                        if(ChnData.at(0)=="+" && ChnData.at(1)==" " ){
                            for(int i=3; i <= ChnData.length()-1;i++){
                                QString ChnData1 = ChnData.at(i);
                                ChnData0 = ChnData0 + ChnData1;
                            }
                        }
                        realData[chn]= ChnData0.toInt();

                        QString ChnData_0 = ChnData.at(2);
                        if(ChnData.at(0)=="-" && ChnData.at(1)==" " ){
                            for(int i=3; i <= ChnData.length()-1;i++){
                                QString ChnData_1 = ChnData.at(i);
                                ChnData_0 = ChnData_0 + ChnData_1;
                            }
                        }
                        realData_neg[chn] = (-1)*ChnData_0.toInt();

                        //qDebug()<<realData[chn] + realData_neg[chn]; //new
                    }
                }
            }
        }
        else if ((Test1[0] == "O") && (Test1[1] == "K")) {
            OkReceived = 1;
        }
    }
    if  (ComSendType == ""){
        if  (RaworReal == 0) {
            RaworReal = 1;
            m_serial->write("REAL\r\n");
        }
        else {
            RaworReal = 0;
            m_serial->write("CONV\r\n");
        }
    }
    ///VF10
    else if  (ComSendType == "WaitOk"){
        SeriErrCnt ++;
        if  (OkReceived == 1)
            ComSendType = "";
        else if (SeriErrCnt > 5){
             ComSendType = "";
             SeriErrCnt = 0;
        }
    }
    else if  (ComSendType == "CAL") {
        ComSendType = "WaitOk";
        QByteArray sd = SendData.toLocal8Bit();
        m_serial->write(sd);
    }
    else if  (ComSendType == "RawZ") {
        ComSendType = "WaitOk";
        SeriErrCnt = 0;
        QByteArray sd = SendData.toLocal8Bit();
        m_serial->write(sd);
    }
    //
    ///static int kutuno = 0;
    j = 0;
    for (i=0; i < MaxCalPoint; i++){
        j = j + 1;
        if  (CalStepCheckBox[i]->isChecked() && ui->CoBoxChannel->currentIndex()==-1){
            return;
        }
        else if (CalStepCheckBox[i]->isChecked()){
            CalStepCheckBox[i]->setDisabled(true);      ///isaretlenen disable
            ChnRawData[i]->setStyleSheet("font-family: Arial; color: rgb(120,120,120); border: 1px solid rgb(150,150,150); margin-right: 5px ; padding: 1px ;background-color: rgb(255,255,255)");
            if  (chndataok == true){
                chndataok = false;
            }
            if  (j > ChecKutuNo) {
                qDebug() << "Active Olan Kutu:" << j;
                ChecKutuNo = i + 1;
                if  (j < MaxCalPoint){
                    CalStepCheckBox[j]->setDisabled(false);   ///bir sonraki aktif
                    /// Raw Data Atama
                    if  (ui->CoBoxChannel->currentIndex() == 0){
                        ChnRawData[i]->setText(vl0);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 1){
                        ChnRawData[i]->setText(vl1);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 2){
                        ChnRawData[i]->setText(vl2);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 3){
                        ChnRawData[i]->setText(vl3);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 4){
                        ChnRawData[i]->setText(vl4);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 5){
                        ChnRawData[i]->setText(vl5);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 6){
                        ChnRawData[i]->setText(vl6);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 7){
                        ChnRawData[i]->setText(vl7);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 8){
                        ChnRawData[i]->setText(vl8);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 9){
                        ChnRawData[i]->setText(vl9);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 10){
                        ChnRawData[i]->setText(vl10);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 11){
                        ChnRawData[i]->setText(vl11);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 12){
                        ChnRawData[i]->setText(vl12);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 13){
                        ChnRawData[i]->setText(vl13);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 14){
                        ChnRawData[i]->setText(vl14);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 15){
                        ChnRawData[i]->setText(vl15);
                    }
                }
                if  (j == MaxCalPoint){
                    if  (ui->CoBoxChannel->currentIndex()==0){
                        ChnRawData[i]->setText(vl0);
                    }
                    if  (ui->CoBoxChannel->currentIndex()==1){
                        ChnRawData[i]->setText(vl1);
                    }
                    if  (ui->CoBoxChannel->currentIndex()==2){
                        ChnRawData[i]->setText(vl2);
                    }
                    if  (ui->CoBoxChannel->currentIndex()==3){
                        ChnRawData[i]->setText(vl3);
                    }
                    if  (ui->CoBoxChannel->currentIndex()==4){
                        ChnRawData[i]->setText(vl4);
                    }
                    if  (ui->CoBoxChannel->currentIndex()==5){
                        ChnRawData[i]->setText(vl5);
                    }
                    if  (ui->CoBoxChannel->currentIndex()==6){
                        ChnRawData[i]->setText(vl6);
                    }
                    if  (ui->CoBoxChannel->currentIndex()==7){
                        ChnRawData[i]->setText(vl7);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 8){
                        ChnRawData[i]->setText(vl8);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 9){
                        ChnRawData[i]->setText(vl9);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 10){
                        ChnRawData[i]->setText(vl10);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 11){
                        ChnRawData[i]->setText(vl11);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 12){
                        ChnRawData[i]->setText(vl12);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 13){
                        ChnRawData[i]->setText(vl13);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 14){
                        ChnRawData[i]->setText(vl14);
                    }
                    if  (ui->CoBoxChannel->currentIndex() == 15){
                        ChnRawData[i]->setText(vl15);
                    }
                }
            }
            else if (ChecKutuNo == 0){
                qDebug() << "Active Olan Kutu:" << ChecKutuNo;
                ChecKutuNo = 1;
            }
        }
    }
    static int counter = 0;
    static int DigitCount = 0;
    ///Bu disaridan gelecek, bu kadar digit olunca islem tamam diye bir sonuc bildirecek
    char s[50];
    counter ++;
    //itoa(counter, s, 10); // sila
    QString TestString = "Passed Time: ";
    TestString += s;
    ///lbltime->setText(s);
    if  (UserCalLabelActive == false) {
        DigitCount = 0;
        KeyedData  = "";
    }
    else if  ((KeyPressWait == false) && (UserCalLabelActive == true)){
        if  ((KeyPressedOk == true) && (KeyReleasedOk == true)){   /// bir tusa basildiktan sonraki ilk state
            KeyPressedOk = false;
            KeyReleasedOk = false;
        }
        else if  ((KeyPressedOk == true) && (KeyReleasedOk == false)){ /// bir tusa basildiktan sonraki 2. veya 3. state
            KeyPressedOk = false;
            KeyReleasedOk = false;
        }
        else if ((KeyPressedOk == false) && (KeyReleasedOk == true)){ /// bir tusa basildiktan sonraki 2. veya 3. state
            KeyPressedOk = false;
            KeyReleasedOk = false;
        }
        else if  ((KeyPressedOk == false) && (KeyReleasedOk == false)){ /// bir tusa basildiktan sonraki son state
            KeyPressedOk    = false;
            KeyReleasedOk   = false;
            KeyTimerEnd     = true;
            KeyPressWait    = true;
            int DpLoc = ui->CoBoxDataFormat->currentIndex();
            if  (KeyValue == Qt::Key_Backspace){
                QString x,y;
                if  (DigitCount > 0){
                    DigitCount--; ///dikkat 1 ise 0 a dusecek
                    KeyedData = KeyedData.left(DigitCount);
                    if  (DigitCount >= DpLoc) {
                        if  (DpLoc == 0) {
                            y = KeyedData;
                            UserCalLabel[UserCalLabelIndex] -> setText(y);
                         }
                        else{
                            x = KeyedData.right(DpLoc);
                            y = KeyedData.left(DigitCount-DpLoc) + "." + x;
                            UserCalLabel[UserCalLabelIndex] -> setText(y);
                        }
                    }
                    else if (DigitCount > 0){
                        UserCalLabel[UserCalLabelIndex] ->setText(KeyedData);
                    }
                    else{
                        KeyedData="";
                        UserCalLabel[UserCalLabelIndex] ->setText(KeyedData);
                    }
                }
            }
            else {
                ///Burada kendi tum islemlerini yapablirsin, girilenleri bir text de gosterebilirsin
                //itoa(DigitCount, s, 10); // sila
                TestString = s;
                TestString += " Times and Presed Key is ";
                //itoa(KeyValue, s, 10); // sila
                TestString += s;
                TestString += " ( ";
                TestString += KeyValue;
                TestString += " )";
                ///Textedit -> setText(TestString);
                QString x,y;
                if  (DigitCount >= KeyDigitCount){
                    KeyedData = KeyedData.right(KeyDigitCount - 1) + KeyValue;
                }
                else KeyedData += KeyValue;
                if  (DigitCount == 0){
                    if  (DpLoc > 0){
                        y = "0." + KeyedData;
                    }
                    else{
                        y = KeyedData;
                    }
                }
                else if  (DigitCount >= DpLoc){
                    if  (DpLoc > 0){
                        x = KeyedData.right(DpLoc);
                        if  (DigitCount >= KeyDigitCount)
                            y = KeyedData.left(DigitCount-(DpLoc)) + "." + x;
                        else
                        y = KeyedData.left(DigitCount-(DpLoc - 1)) + "." + x;
                    }
                    else{
                        y = KeyedData;
                    }
                }
                else {
                    y = "0." + KeyedData;
                }
                UserCalLabel[UserCalLabelIndex] -> setText(y);
                if  (DigitCount < KeyDigitCount) DigitCount++;
                qDebug() << "Girilen Data : " + KeyedData + x + y + '\n';
            }
        }
    }
    if  (ui->CoBoxInputType->currentText()=="Custom"){
        Gain->setVisible(true);
        LblScrollBarGain->setVisible(true);
        ScrollBarGain->setVisible(true);
    }
    else {
        Gain->setVisible(false);
        LblScrollBarGain->setVisible(false);
        ScrollBarGain->setVisible(false);
    }
}
void DLCalMenu::alarm_initialize()
{
    QTabBar *tabBar2;
    tabBar2 =  ui->tabWidget_alarm -> tabBar();
    tabBar2 -> setStyleSheet(QString("QTabBar {background-color: none;}"
                                     "QTabBar::tab { height: %1px; width: %2px; }").arg(RealLCDH).arg(TabAlarmW));
    grid_alert = new QGridLayout;
    wdgAlert   = new QWidget;

    for(int i=0; i<AlarmCount; i++){
        checkBox_alarm[i] = new QCheckBox;
        comboBox_alarm[i] = new QComboBox;
        lbl_alarmL[i]     = new QLabel("Low Alarm:");
        lbl_alarmH[i]     = new QLabel("High Alarm:");
        spinBox_alarmL[i] = new QSpinBox;
        spinBox_alarmH[i] = new QSpinBox;
        lbl_alarmL[i]     -> setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        lbl_alarmH[i]     -> setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        spinBox_alarmH[i] -> setMinimumWidth(DialogH/2);
        spinBox_alarmL[i] -> setMinimumWidth(DialogH/2);
        spinBox_alarmL[i] -> setRange(-99999,99999);
        spinBox_alarmH[i] -> setRange(-99999,99999);
        comboBox_alarm[i] -> setCursor(Qt::PointingHandCursor);
        checkBox_alarm[i] -> setCursor(Qt::PointingHandCursor);
        comboBox_alarm[i] -> setStyleSheet("background-color : none;");
        checkBox_alarm[i] -> setStyleSheet(QString("QCheckBox::indicator {height: %1px; width: %1px;}"
                                                              "QCheckBox::indicator:checked{ border-image: url(:/icon/check.png); height: %1px; width: %1px;};").arg(RealLabelH));
        for (int j = 0; j < MaxChnCounts; ++j){
            comboBox_alarm[i] -> addItem(QString(tr("Channel %1").arg(j+1)),j);}

        checkBox_alarm[i] -> setText(QString("%1.").arg(i+1));       //to show index. will be removed
        connect(checkBox_alarm[i], SIGNAL(clicked()), this, SLOT(checkbox_alert_onClicked()));
    }
    btn_setAlarm    = new QPushButton("Set");
    btn_removeAlarm = new QPushButton("Remove");
    btn_addAlarm    = new QPushButton(QIcon(":/icon/plus.png"),"Add new alarm");

    ui->scrollAlerts -> setWidget(wdgAlert);
    wdgAlert   -> setLayout(grid_alert);
    grid_alert -> addWidget(btn_addAlarm, 2, 0);
    grid_alert -> setHorizontalSpacing(SideMargin);
    grid_alert -> setColumnStretch(0,0);
    grid_alert -> setColumnStretch(1,1);
    grid_alert -> setColumnStretch(2,1);
    grid_alert -> setColumnStretch(3,1);
    grid_alert -> setColumnStretch(4,1);
    grid_alert -> setColumnStretch(5,1);
    wdgAlert        -> setStyleSheet("background-color: rgb(227,225,225);");
    btn_addAlarm    -> setStyleSheet("background-color : none; border: none; color:rgb(30,60,190); text-align: left");
    btn_removeAlarm -> setStyleSheet("background-color : rgb(220,150,150); color:rgb(255,255,255); ");
    btn_setAlarm    -> setStyleSheet("background-color : rgb(0,130,0); color:rgb(255,255,255); ");
    btn_addAlarm    -> setCursor(Qt::PointingHandCursor);
    btn_setAlarm    -> setCursor(Qt::PointingHandCursor);
    btn_removeAlarm -> setCursor(Qt::PointingHandCursor);
    btn_removeAlarm -> setDisabled(true);

    connect(btn_addAlarm      , SIGNAL(clicked()), this, SLOT(btn_addAlert_onClicked()));
    connect(btn_setAlarm      , SIGNAL(clicked()), this, SLOT(btn_setAlert_onClicked()));
    connect(btn_removeAlarm   , SIGNAL(clicked()), this, SLOT(btn_removeAlert_onClicked()));
}

DLCalMenu::~DLCalMenu()
{
    delete ui;
}
