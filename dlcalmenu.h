#ifndef DLCALMENU_H
#define DLCALMENU_H

#include <QMainWindow>

#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QFrame>
#include <QFile>
#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QRadioButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QStackedWidget>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QSpinBox>
#include <QTabBar>
#include <QTabWidget>
#include <QTableView>
#include <QTableWidget>
#include <QTextEdit>
#include <QTimeEdit>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QVector>
#include "qcustomplot.h"
#include "stopwatch.h"

typedef unsigned char u8;

#define SCR_MAIN            0
#define SCR_CALIB           1
#define SCR_SET             2
#define SCR_PORTSET         3
#define SCR_ALERTS          4

#define DIA_DEVICE          0
#define DIA_GRAPH           1
#define DIA_PSW             2

namespace Ui {
class DLCalMenu;
}

class DLCalMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit DLCalMenu(QWidget *parent = 0);
    ~DLCalMenu();
    ///const int MaxCalPoint = 16;
    ///const int MaxChnCounts = 4;
    const int KeyDigitCount = 6;
    ///const int MaxDataSend = 40;

    enum Mode { NavigationMode, AddingMode };
    int PreChnNo = 0;
    int PreDpLoc = 0;
    ///int PreInputType = 0;
    ///int PreSampeRate = 0;
    ///int PreFilterType = 0;
    ///
    u8 current_page;                            // to assign index for each tab
    u8 current_dialog;

private:
    Ui::DLCalMenu *ui;
    stopwatch *watch;                           // for serial port connection time count

protected:
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

public :
    enum { MaxCalPoint = 16 };
    QLabel *CalStep[MaxCalPoint];               // cal step numbers
    QLabel *UserCalLabel[MaxCalPoint];          // key cal inputs
    QLabel *ChnRawData[MaxCalPoint];            // cal raw data
    QCheckBox *CalStepCheckBox[MaxCalPoint];    // cal checkboxes
    QLabel *useless1;                           // 'step' label
    QLabel *useless2;                           // 'keycalinput' label
    QLabel *useless3;                           // 'raw data' label
    enum { MaxChnCounts = 16};
    QLabel *ChnRawLabel[MaxChnCounts];
    QLabel *ChnRealLabel[MaxChnCounts];
    QVector<QLCDNumber*> ChnLCDRaw;
    QVector<QLCDNumber*> ChnLCDReal;
    QVector<QLCDNumber*> ChnLCDReal_Main;       // main page lcd real values

    QSerialPort *m_serial;

    char port_index;
    int  forsh   = 1;
    int  ctr     = 0;                           // table listing counter
    int  ScreenWidth, ScreenHeight;

    // plotting :
    double displayData_X;                       // x axis value
    double displayData_Y;                       // y axis value
    int index_x;                                // x axis channel index
    int index_y;                                // y axis channel index
    int realData[MaxChnCounts];                 // plotting + values
    int realData_neg[MaxChnCounts];             // plotting - values
    int new_index_Y[MaxChnCounts];              // y axis channel index for additional graphs
    int newDataY[MaxChnCounts];                 // plotting value for additional graphs
    int axisYUpper;                             // y axis range for additional graphs
    int axisYLower;                             // y axis range for additional graphs
    int KeyStateCounter;
    int UserCalLabelIndex;
    int KeyValue;
    int ChecKutuNo      = 0;
    int RawDigitCount   = 7;
    int RealDigitCount  = 7;
    bool KeyTimerEnd    = false;
    bool KeyPressWait   = true;
    bool UserCalLabelActive = false;
    bool KeyPressedOk   = false;
    bool KeyReleasedOk  = false;
    bool chndataok      = true;
    bool mouseevent;
    bool password_correct;
    bool plot_run;
    int dispList = 0;

    // layout :
    int hr;
    int vr;
    int pr;
    int SideMargin;
    int RealLabelH;
    int RealLabelW;
    int RealLCDH;
    int RawLabelW;
    int RawLCDH;
    int CalPointH;
    int CalPointW;
    int ToolH;
    int CalibScrollH;
    int MainScrollW;
    int TabBarH;
    int TabBarW;
    int TabAlarmW;
    int AppW;
    int AppH;
    int DialogH;
    int DialogW;

    QLabel *label;
    QString KeyedData;
    QString currentFile;
    QString *list_axisMain;
    QString *list_axisPlot;
    QString ChnRawDataQString[MaxChnCounts];
    QString ChnRealDataQString[MaxChnCounts];
    QString ComSendType;
    QString ChnCalArray[16][50];///VF10
    QString UserFileArray[16][50];///VF10
    QString SendData;///VF10
    QString rawdata;
    ///QByteArray SendData;///VF10
    QRect PriScrenRect;
    QWidget *psw_widget;                        // for mouse event permission

    // toolbar actions :
    QAction *clear ;                            // clear button
    QAction *exportfile ;                       // export button
    QAction *savefile ;                         // save as button
    QAction *openfile ;                         // open saved file button
    QAction *help ;                             // info button
    QAction *quit ;                             // exit button

    //QAction *addgraph;                        // in popup menu : add new graph
    QAction *hidelegend;                        // in popup menu : hide legend
    QAction *showlegend;                        // in popup menu : show legend
    QAction *clearAll;
    QAction *clearPlot;

    // page layout groups :
    QTabBar *tabBar;
    QTabBar *tabBar_alarm;
    QWidget *wdgReals;
    QWidget *dataBox;                           // calib raw real data display
    QFrame *CalPointsFrame;
    QGridLayout *grid_reals;
    QGridLayout *boxLayout;                     // calib raw-real data layout
    QGridLayout *CalGridLayout;

    // page items :
    QScrollBar *scroll_main;
    QScrollBar *scroll_bar;     //scroll position
    int position[2]={0,0};

    QTimer *KeyTimer;
    QTimer *timer;
    QTimer *timer_plot;
    QTimer *timer_main;

    // alarm page:
    int add_alarm = 0;
    enum {AlarmCount = 20};
    QGridLayout *grid_alert;            //alarm : initilized at dlcalmenu.cpp
    QScrollArea *scrollAlerts;          //alarm : initilized at dlcalmenu.cpp
    QLabel      *lbl_alarmL[AlarmCount];
    QLabel      *lbl_alarmH[AlarmCount];
    QCheckBox   *checkBox_alarm[AlarmCount];
    QComboBox   *comboBox_alarm[AlarmCount];
    QSpinBox    *spinBox_alarmL[AlarmCount];
    QSpinBox    *spinBox_alarmH[AlarmCount];
    QPushButton *btn_setAlarm;
    QPushButton *btn_removeAlarm;
    QPushButton *btn_addAlarm;
    ////////////////////////  new alarm
    QWidget *wdgAlert;
    QRadioButton *radioBtn_alarmScreen;
    QRadioButton *radioBtn_alarmMail;
    QPushButton *btn_editAlarm;
    QSpinBox *spinBox_alarmDelay;
    QTableWidget *table_alarm;
    QStandardItemModel *model_alert;
    /// ///////////////////

    // dialog password:
    QDialog *dialog_newPswd;    // password change dialog
    QWidget *wdg_dialogPsw;
    QLineEdit *newPswd;
    QLineEdit *oldPswd;
    QPushButton *btn_saveNewPswd;
    QPushButton *btn_cancelNewPswd;
    QLabel *keyicon;

    // dialog set device:
    QDialog *dialog_setDevice;    // password initilize device
    QWidget *wdg_dialogSetDev;
    QTimeEdit *timeEdit_1;
    QTimeEdit *timeEdit_2;
    QDateEdit *dateEdit_1;
    QDateEdit *dateEdit_2;
    QLabel *lbl_startDate;
    QLabel *lbl_endDate;
    QLabel *lbl_device;
    QPushButton *btn_readExternal;
    QPushButton *btn_readSD;
    QPushButton *btn_okDialog;
    QPushButton *btn_cancelDialog;
    QComboBox *combo_device;
    bool timeset = false;
    QTime PreTime;
    QDate PreDate;
    QTime time_1;
    QTime time_2;
    QDate date_1;
    QDate date_2;

    // dialog add graph:
    QGridLayout *grid_dialogAddMain;
    QDialog     *dialog_addToMain;
    QWidget     *wdg_dialogAddMain;
    QComboBox   *combo_diaMain ;
    QPushButton *btn_diaOKMain;
    QPushButton *btn_diaCancelMain;
    QLabel      *lbl_diaAxisMain;
    QStringList removed_channels;

    // time :
    bool    mRunning = false;
    qint64  mTotalTime = 0;
    qint64  mTempTime  = 0;
    int     totalTime  = 0;
    QTime   time;
    QDateTime mStartTime;

    // hidden objects :
    QPushButton *btn_startStop;
    QScrollBar *ScrollBarGain;
    QLabel *Gain;
    QLabel *LblScrollBarGain;

    // graph :
    QCPPlottableLegendItem *plItem;
    QCustomPlot *customPlot_main;
    QCustomPlot *customPlot_graph;
    int rec_time;
    int del = 0;                    //removePlot()
    int del_ctr = 0;                //removePlot()
    int plot_statu  = 0;
    int ad_main     = 0;
    int ad_graph    = 0;
    int x_change    = 0;
    bool plot;

    // table :
    QFile *externalFile;
    QTableView *tview_real;
    QTableView *tview_raw;
    QTableView *tview_file;
    QStandardItemModel *csvModel_real;
    QStandardItemModel *csvModel_raw;
    QStandardItemModel *csvModel_realnew;
    QList<QStandardItem *> ItemsFile;
    QList <int> ItemsList[MaxChnCounts]; // while external device selected. List that holds the prerecorded values read from selected csv file.
    QList <int> DateList[3];
    //QList <QStandardItem *> DateList;
    QList <int> HourList[4];
    QStringList dateItems;
    QStringList timeItems;

    bool deviceSelected=true;
    bool externalSelected=false;
    bool sdSelected=false;
    int linecnt=0;

    int Fontsize;
    int FontsizeTab;

private slots:
    void setup_GUI();

    void scroll_movement(); // Added Scroll Movement
    void slider_Pressed();  // Get Position of scroll_bar when pressed
    void slider_Released(); // Get Position of scroll_bar when released

    void SaveCalPartoArray(int chnno);  //VF1
    void DisplayCalPar(int chnno);  //VF10
    void DataFormat_Changed();
    void InputType_Warning(int);
    void Channel_itemChanged();
    void SendCalDataToVTK();
    void UpdateFlash();
    void open();
    void save();
    void saveAs();
    void opening_val();

public slots:
    int GetScreenHRes(int s);
    int GetScreenVRes(int s);
    void ScrollBarGain_valueChange(int value);
    void timer_startStop();
    void resetTimer();
    void update_time();
    void ClearKey();
    void KeyTimerTimeOut();
    void get_password();

    void setup_combobox();
    void on_tabWidget_currentChanged(int index);
    void on_m_SetSerialPortButton_clicked();
    void combo_axis1_indexChanged(int index);
    void combo_axis2_indexChanged(int index);
    void on_btn_newPassword_clicked();
    void on_btn_graphDialog_clicked();
    void on_btn_plotGraph_clicked();
    void combo_diaCh_indexChanged(int index);
    void combo_portType_indexChanged(int index);
    void combo_sampeRate_indexChanged(int index);
    void combo_filterType_indexChanged(int index);
    void combo_inputType_indexChanged(int index);
    void combo_channels_indexChanged(int index);
    void combo_rawreal_indexChanged(int index);
    void combo_device_indexChanged(int index);
    void on_btn_password_clicked();
    void on_btn_saveChn_clicked();
    void btn_saveNewPswd_onClicked();
    void btn_cancelPswd_onClicked();
    void btn_okDialog_onClicked();
    void btn_cancelDialog_onClicked();
    void btn_diaGrapOK_onClicked();
    void btn_diaGrapCancel_onClicked();
    void on_btn_dispList_clicked();

    // alarm :
    void alarm_initialize();
    void btn_addAlert_onClicked();
    void btn_setAlert_onClicked();
    void btn_removeAlert_onClicked();
    void checkbox_alert_onClicked();

    // plot:
    void setup_customPlot();
    void plot_graphMain();
    void addNewGraph();
    void addGraphDialog_Main();
    void hideGraphPlot();
    void showGraphPlot();
    void hideLegend();
    void showLegend();
    void removePlot();
    void removeAllPlot();
    void selectionChanged();
    void mousePress();
    void mouseWheel();
    void contextMenuRequest(QPoint pos);
    void moveLegend();
    void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);
    void axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part);
    void legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item);

    // export file:
    void table_writeData();
    void table_readData();
    void exportCsv();

};

#endif // DLCALMENU_H
