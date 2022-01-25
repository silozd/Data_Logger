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

    int i = 1000;
    int Fontsize;
    QFont Font1 ("Arial", Fontsize, QFont::Normal);

    if  (ScreenWidth == 3840){
        i = i/2;
        Fontsize =16;
        Font1.setPointSize(Fontsize);
    }
    else if (ScreenWidth <=1920){
        i = 1000;
        Fontsize = 13;
        Font1.setPointSize(Fontsize);
    }
    else if (ScreenWidth > 1920){
        Fontsize = 14;
        Font1.setPointSize(Fontsize);
    }
    qDebug()<<"i"<<i;

    int hr = DLCalMenu::GetScreenHRes(0);
    int vr = DLCalMenu::GetScreenVRes(0);
    qDebug()<<"hr = "<<hr;
    qDebug()<<"vr = "<<vr;

    int SideMargin = hr*10/i;
    int RealLabelH = vr*30/i;
    int RealLabelW = hr*180/i;
    int RealLCDH = vr*45/i;
    int CalibScrollH = RealLCDH*2+RealLabelH*2+SideMargin*3;
    int MainScrollW = RealLabelW;
    int TabBarW = hr*115/i;
    int TabBarH = hr*100/i;
    qDebug()<<"SideMargin"<<SideMargin;
    qDebug()<<"RealLabelH"<<RealLabelH;
    qDebug()<<"RealLabelW"<<RealLabelW;
    qDebug()<<"RealLcdH"<<RealLCDH;
    qDebug()<<"CalibScrollH"<<CalibScrollH;
    qDebug()<<"MainScrollW"<<MainScrollW;
    qDebug()<<"TabBarW"<<TabBarW;

    tabBar = ui->tabWidget->tabBar();
    ui->tabWidget->setStyleSheet(QString("QTabBar::tab { width: %1px; height: %1px;};").arg(TabBarW,TabBarH));
    ui->tabWidget->setFont(Font1);
    tabBar   ->setStyle(new CustomTabStyle);

    tabBar_alarm = ui->tabWidget_alarm->tabBar();

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
        ChnRealLabel[i]     -> setMinimumHeight(RealLabelH);
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

// real raw data - calibration page :
        if(int j = 1){
            ChnRawLabel[i]  = new QLabel(tr("Channel %1 Raw").arg(i + 1),ui->scrollArea);
            ChnRawLabel[i]  -> setAlignment(Qt::AlignCenter);
            ChnRawLabel[i]  -> setFont(Font1);
            ChnRawLabel[i]  -> setStyleSheet("background-color: rgb(10, 10, 10); color: rgb(255, 255, 255);");
            ChnRawLabel[i]  -> setMinimumSize(RealLabelW, RealLabelH);

            ChnLCDRaw[i]    -> display(QString("%1000").arg(i+1));
            ChnLCDRaw[i]    -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDRaw[i]    -> setDigitCount(RawDigitCount);
            ChnLCDRaw[i]    -> setSmallDecimalPoint(true);
            ChnLCDRaw[i]    -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(255, 10, 0)");
            ChnLCDRaw[i]    -> setMinimumSize(RealLabelW, RealLCDH);

            ChnRealLabel[i] = new QLabel(tr("Channel %1 Real").arg(i + 1),ui->scrollArea);
            ChnRealLabel[i] -> setAlignment(Qt::AlignCenter);
            ChnRealLabel[i] -> setFont(Font1);
            ChnRealLabel[i] -> setStyleSheet("background-color: rgb(10, 10, 10); color: rgb(255, 255, 255)");
            ChnRealLabel[i] -> setMinimumSize(RealLabelW, RealLabelH);

            ChnLCDReal[i]   -> display(QString("%1000").arg(i+1));
            ChnLCDReal[i]   -> setSegmentStyle(QLCDNumber::Flat);
            ChnLCDReal[i]   -> setDigitCount(RealDigitCount);
            ChnLCDReal[i]   -> setSmallDecimalPoint(true);
            ChnLCDReal[i]   -> setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(50, 255, 0)");
            ChnLCDReal[i]   -> setMinimumSize(RealLabelW, RealLCDH);

            boxLayout       -> addWidget(ChnRawLabel[i]  , j   , i);
            boxLayout       -> addWidget(ChnLCDRaw[i]    , j+1 , i);
            boxLayout       -> addWidget(ChnRealLabel[i] , j+2 , i);
            boxLayout       -> addWidget(ChnLCDReal[i]   , j+3 , i);
            boxLayout       -> setVerticalSpacing(1);
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
        dataBox -> setMaximumHeight(CalibScrollH);
        ui->scrollArea->setMinimumHeight(CalibScrollH);
        ui->scrollArea->setMaximumHeight(CalibScrollH);

// cal points :
    for (int i = 0; i < MaxCalPoint; ++i) {
        CalStep[i]          =   new QLabel(tr("%1").arg(i + 1));
        CalStep[i]          ->  setAlignment(Qt::AlignCenter);
        CalStep[i]          ->  setStyleSheet("font-size: 16px; margin: 3px");
        CalStep[i]          ->  setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

        UserCalLabel[i]     =   new QLabel(CalPointsFrame);
        UserCalLabel[i]     ->  setText(QString::number((i)*200*10));
        UserCalLabel[i]     ->  setAlignment(Qt::AlignRight);
        UserCalLabel[i]     ->  setFont(Font1);
        UserCalLabel[i]     ->  setStyleSheet("background-color: rgb(123, 168, 246); border: 1px solid rgb(83,128,206); margin-right: 5px;  padding: 1px; ");
        UserCalLabel[i]     ->  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        ChnCalArray[0][8 + i] = QString::number((i)*200*10);

        ChnRawData[i]       =   new QLabel(QString::number(00).arg(i+1));
        ChnRawData[i]       ->  setText(QString::number((i+1)*2000));
        ChnRawData[i]       ->  setAlignment(Qt::AlignRight);
        ChnRawData[i]       ->  setFont(Font1);
        ChnRawData[i]       ->  setStyleSheet("border: 1px solid gray; margin-right: 5px ; padding: 1px; background-color: rgb(255,255,255);");
        ChnRawData[i]       ->  setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        ChnCalArray[0][8 + 16 + i] = QString::number((i+1)*2000);

        CalStepCheckBox[i]  =   new QCheckBox;
        CalStepCheckBox[i]  ->  setStyleSheet(QString("QCheckBox::indicator {height: %1px; width: %1px;}"
                                                      "QCheckBox::indicator:checked{ border-image: url(:/icon/check.png); height: %1px; width: %1px;};").arg(25));
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
    CalPointsFrame  ->  setLayout(CalGridLayout);
    useless1 = new QLabel("Step");
    useless2 = new QLabel("Key Cal Input");
    useless3 = new QLabel("Raw Data");
    CalGridLayout   ->  addWidget(useless1 , 0, 0);
    CalGridLayout   ->  addWidget(useless2 , 0, 1);
    CalGridLayout   ->  addWidget(useless3 , 0, 2);

    qcustomplot_initilize();
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
