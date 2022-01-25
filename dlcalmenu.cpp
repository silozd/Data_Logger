#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"
#include "customtabstyle.h"
#include <QDebug>

DLCalMenu::DLCalMenu(QWidget *parent) :
    QMainWindow(parent),
    wdgReals(new QWidget),
    dataBox(new QWidget),
    CalPointsFrame(new QFrame),
    ui(new Ui::DLCalMenu)
{
    ui->setupUi(this);
    tabBar = ui->tabWidget->tabBar();
    ui->tabWidget->setStyleSheet(QString("QTabBar::tab { height: %1px; width: %1px; font-size: 15px; };").arg(84));
    tabBar   ->setStyle(new CustomTabStyle);
    QFont ComboFont ("Arial" , 13, QFont::Normal);

// toolbar :
    ui->toolBar -> toggleViewAction()->setVisible(false);
    QWidget *spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->toolBar->addWidget(spacer);
    QLabel  *logo = new QLabel;
    logo    -> setSizeIncrement(350, 40);
    logo    -> setPixmap(QPixmap(":/icon/logo.png"));
    logo    -> setContentsMargins(0,0,0,0);
    //ui->toolBar -> addWidget(logo);       // OPEN
    ui->toolBar -> setMaximumHeight(40);
    ui->toolBar -> setIconSize(QSize(40, 40));
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

    grid_reals  = new QGridLayout(wdgReals);
    boxLayout   = new QGridLayout(dataBox);
    CalGridLayout = new QGridLayout(CalPointsFrame);
    ui->scrollReals->setWidget(wdgReals);
    ui->scrollReals->setWidgetResizable(1);
    ui->scrollReals->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    qcustomplot_initilize();
    for (int i=0; i<MaxChnCounts; i++){
        ChnLCDRaw.append(new QLCDNumber(CalPointsFrame));
    }
    for (int i=0; i<MaxChnCounts; i++){
        ChnLCDReal.append(new QLCDNumber(CalPointsFrame));
        ChnLCDReal_Main.append(new QLCDNumber(wdgReals));
    }

    // real data - main page :
    for (int i = 0; i < MaxChnCounts; ++i) {            // real- raw array loop
        ChnRealLabel[i]     = new QLabel(tr("Channel %1 Real").arg(i + 1),wdgReals);
        ChnRealLabel[i]     -> setAlignment(Qt::AlignCenter);
        ChnRealLabel[i]     -> setStyleSheet("background-color: rgb(20,20,20); color: rgb(255,255,255)");
        ChnRealLabel[i]     -> setMinimumSize(110,25);
        ChnRealLabel[i]     -> setFont(ComboFont);

        ChnLCDReal_Main[i]  -> display(QString("%1000").arg(i+1));
        ChnLCDReal_Main[i]  -> setSegmentStyle(QLCDNumber::Flat);
        ChnLCDReal_Main[i]  -> setDigitCount(RealDigitCount);
        ChnLCDReal_Main[i]  -> setSmallDecimalPoint(true);
        ChnLCDReal_Main[i]  -> setStyleSheet("background-color: rgb(20,20,20); color: rgb(100,220,255)");
        ChnLCDReal_Main[i]  -> setMinimumSize(110, 30);

        grid_reals          -> setContentsMargins(0,0,0,0);
        grid_reals          -> setVerticalSpacing(3);
        grid_reals          -> addWidget(ChnRealLabel[i]   , i*2   , 0);
        grid_reals          -> addWidget(ChnLCDReal_Main[i], i*2+1 , 0);

// real raw data - calibration page :
        if(int j = 1){
            ChnRawLabel[i]  = new QLabel(tr("Channel %1 Raw").arg(i + 1),ui->scrollArea);
            ChnRawLabel[i]  -> setAlignment(Qt::AlignCenter);
            ChnRawLabel[i]  -> setFont(ComboFont);
            ChnRawLabel[i]  -> setStyleSheet("background-color: rgb(10, 10, 10); color: rgb(255, 255, 255);");
            ChnRawLabel[i]  -> setMinimumSize(125, 20);

            ChnLCDRaw[i]    -> display(QString("%1000").arg(i+1));
            ChnLCDRaw[i]    -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDRaw[i]    -> setDigitCount(RawDigitCount);
            ChnLCDRaw[i]    -> setSmallDecimalPoint(true);
            ChnLCDRaw[i]    -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(255, 10, 0)");
            ChnLCDRaw[i]    -> setMinimumSize(125, 25);

            ChnRealLabel[i] = new QLabel(tr("Channel %1 Real").arg(i + 1),ui->scrollArea);
            ChnRealLabel[i] -> setAlignment(Qt::AlignCenter);
            ChnRealLabel[i] -> setFont(ComboFont);
            ChnRealLabel[i] -> setStyleSheet("background-color: rgb(10, 10, 10); color: rgb(255, 255, 255)");
            ChnRealLabel[i] -> setMinimumSize(125, 20);

            ChnLCDReal[i]   -> display(QString("%1000").arg(i+1));
            ChnLCDReal[i]   -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDReal[i]   -> setDigitCount(RealDigitCount);
            ChnLCDReal[i]   -> setSmallDecimalPoint(true);
            ChnLCDReal[i]   -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(50, 255, 0)");
            ChnLCDReal[i]   -> setMinimumSize(125, 25);

            boxLayout       -> addWidget(ChnRawLabel[i]  , j   , i);
            boxLayout       -> addWidget(ChnLCDRaw[i]    , j+1 , i);
            boxLayout       -> addWidget(ChnRealLabel[i] , j+2 , i);
            boxLayout       -> addWidget(ChnLCDReal[i]   , j+3 , i);
            boxLayout       -> setVerticalSpacing(2);
            boxLayout       -> setHorizontalSpacing(5);
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
        dataBox -> setMaximumHeight(130);
        ui->scrollArea->setMinimumHeight(130);
        ui->scrollArea->setMaximumHeight(130);

// cal points :
    for (int i = 0; i < MaxCalPoint; ++i) {
        CalStep[i]          =   new QLabel(tr("%1").arg(i + 1));
        CalStep[i]          ->  setAlignment(Qt::AlignCenter);
        //CalStep[i]          ->  setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
        CalStep[i]          ->  setMinimumWidth(18);
        CalStep[i]          ->  setStyleSheet("font-size: 16px; margin: 3px");

        UserCalLabel[i]     =   new QLabel(CalPointsFrame);
        UserCalLabel[i]     ->  setText(QString::number((i)*200*10));
        UserCalLabel[i]     ->  setAlignment(Qt::AlignRight);
        UserCalLabel[i]     ->  setFont(ComboFont);
        UserCalLabel[i]     ->  setStyleSheet("background-color: rgb(123, 168, 246); border: 1px solid rgb(83,128,206); margin-right: 5px;  padding: 1px; ");
        //UserCalLabel[i]     ->  setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
        UserCalLabel[i]     ->  setMinimumSize(90,20);
        ChnCalArray[0][8 + i] = QString::number((i)*200*10);

        ChnRawData[i]       =   new QLabel(QString::number(00).arg(i+1));
        ChnRawData[i]       ->  setText(QString::number((i+1)*2000));
        ChnRawData[i]       ->  setAlignment(Qt::AlignRight);
        ChnRawData[i]       ->  setFont(ComboFont);
        ChnRawData[i]       ->  setStyleSheet("border: 1px solid gray; margin-right: 5px ; padding: 1px; background-color: rgb(255,255,255);");
        //ChnRawData[i]       ->  setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
        ChnRawData[i]       ->  setMinimumSize(90,20);
        ChnCalArray[0][8 + 16 + i] = QString::number((i+1)*2000);

        CalStepCheckBox[i]  =   new QCheckBox;
        CalStepCheckBox[i]  ->  setStyleSheet(QString("QCheckBox::indicator {height: %1px; width: %1px;}"
                                                      "QCheckBox::indicator:checked{ border-image: url(:/icon/check.png); height: %1px; width: %1px;};").arg(18));
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
    CalPointsFrame  ->  setLayout(CalGridLayout);
    useless1 = new QLabel("Step");
    useless2 = new QLabel("Key Cal Input");
    useless3 = new QLabel("Raw Data");
    CalGridLayout   ->  addWidget(useless1 , 0, 0);
    CalGridLayout   ->  addWidget(useless2 , 0, 1);
    CalGridLayout   ->  addWidget(useless3 , 0, 2);
}

DLCalMenu::~DLCalMenu()
{
    delete ui;
}
