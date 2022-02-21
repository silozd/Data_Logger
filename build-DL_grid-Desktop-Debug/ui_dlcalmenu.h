/********************************************************************************
** Form generated from reading UI file 'dlcalmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLCALMENU_H
#define UI_DLCALMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DLCalMenu
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *MainPage;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollReals;
    QWidget *scrollAreaWidgetContents;
    QWidget *frameInfo;
    QGridLayout *gridLayout_3;
    QLabel *lbl_axis2;
    QLabel *lbl_inputType;
    QLabel *info_inputType;
    QComboBox *combo_axis1;
    QLabel *lbl_sampeRate;
    QLabel *m_serialPortLabel;
    QLabel *info_filterType;
    QLabel *label_3;
    QComboBox *combo_rawreal;
    QComboBox *m_serialPortComboBox;
    QComboBox *combo_recPeriod;
    QLabel *info_sampeRate;
    QLabel *lbl_axis1;
    QComboBox *combo_axis2;
    QLabel *label_2;
    QLabel *lbl_filterType;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_graphDialog;
    QPushButton *btn_plotGraph;
    QPushButton *btn_dispGrap;
    QPushButton *btn_dispList;
    QTabWidget *wdgGraph;
    QWidget *pg1;
    QWidget *pg2;
    QWidget *CalibPage;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollCalPoint;
    QWidget *scrollAreaWidgetContents_4;
    QWidget *wdgCalib;
    QGridLayout *gridLayout_6;
    QWidget *wdgInput;
    QFrame *frameCalibSet;
    QGridLayout *gridLayout_7;
    QComboBox *CoBoxFilterType;
    QComboBox *CoBoxInputType;
    QLabel *SampeRate;
    QComboBox *CoBoxSampeRate;
    QLabel *DataFormat;
    QComboBox *CoBoxDataFormat;
    QComboBox *CoBoxChannel;
    QLabel *FilterType;
    QLabel *Channel;
    QLabel *InputType;
    QSpacerItem *horizontalSpacer_3;
    QFrame *CalbtnFrame1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSendParData;
    QPushButton *btnSendCalData;
    QPushButton *btnWriteParDataToFlash;
    QPushButton *m_SetSerialPortButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *SettingsPage;
    QGridLayout *gridLayout_10;
    QSpacerItem *horizontalSpacer;
    QLabel *label_21;
    QSpacerItem *verticalSpacer;
    QLabel *label_19;
    QSpacerItem *verticalSpacer_2;
    QLabel *lbl_version;
    QWidget *widget_3;
    QGridLayout *gridLayout_17;
    QLabel *lbl_settingsTime;
    QLabel *minutesText;
    QLabel *hundredthsText;
    QLabel *secondsText;
    QLabel *label_5;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout_15;
    QLabel *activeChannels;
    QLabel *currentPort;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_23;
    QLineEdit *channelName;
    QComboBox *combo_channels;
    QLabel *label_24;
    QPushButton *btn_saveChn;
    QLabel *label_22;
    QProgressBar *memory;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioBtn_csv;
    QRadioButton *radioBtn_pdf;
    QRadioButton *radioBtn_txt;
    QWidget *widget_2;
    QGridLayout *gridLayout_16;
    QLabel *label_20;
    QLineEdit *password;
    QPushButton *btn_password;
    QPushButton *btn_newPassword;
    QWidget *widget_4;
    QWidget *PortSetPage;
    QGridLayout *gridLayout_11;
    QWidget *wdgPort;
    QGridLayout *gridLayout_12;
    QLabel *lbl_COMport;
    QLineEdit *COMport;
    QLabel *lbl_adres;
    QLineEdit *adres;
    QLabel *lbl_timeout;
    QLineEdit *timeout;
    QLabel *lbl_IP;
    QLineEdit *IP;
    QWidget *widget_9;
    QGridLayout *gridLayout_13;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QWidget *wdgHidden;
    QWidget *widget_8;
    QFrame *framePortCombo;
    QGridLayout *gridLayout_4;
    QComboBox *combo_portType;
    QLabel *lbl_portType;
    QPushButton *pushButton_11;
    QWidget *AlertsPage;
    QGridLayout *gridLayout_14;
    QTabWidget *tabWidget_alarm;
    QWidget *AlarmModes;
    QWidget *AlarmControl;
    QWidget *AlarmDelay;
    QWidget *AlarmActive;
    QGridLayout *gridLayout_8;
    QTableWidget *table_alarm;
    QScrollArea *scrollAlerts;
    QWidget *scrollAreaWidgetContents_2;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DLCalMenu)
    {
        if (DLCalMenu->objectName().isEmpty())
            DLCalMenu->setObjectName(QStringLiteral("DLCalMenu"));
        DLCalMenu->resize(1023, 627);
        centralWidget = new QWidget(DLCalMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        MainPage = new QWidget();
        MainPage->setObjectName(QStringLiteral("MainPage"));
        gridLayout_2 = new QGridLayout(MainPage);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        scrollReals = new QScrollArea(MainPage);
        scrollReals->setObjectName(QStringLiteral("scrollReals"));
        scrollReals->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 193, 471));
        scrollReals->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollReals, 1, 1, 1, 1);

        frameInfo = new QWidget(MainPage);
        frameInfo->setObjectName(QStringLiteral("frameInfo"));
        gridLayout_3 = new QGridLayout(frameInfo);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(18);
        gridLayout_3->setVerticalSpacing(3);
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        lbl_axis2 = new QLabel(frameInfo);
        lbl_axis2->setObjectName(QStringLiteral("lbl_axis2"));
        lbl_axis2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_axis2->setIndent(3);

        gridLayout_3->addWidget(lbl_axis2, 2, 0, 1, 1);

        lbl_inputType = new QLabel(frameInfo);
        lbl_inputType->setObjectName(QStringLiteral("lbl_inputType"));
        lbl_inputType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_inputType->setIndent(3);

        gridLayout_3->addWidget(lbl_inputType, 2, 4, 1, 1);

        info_inputType = new QLabel(frameInfo);
        info_inputType->setObjectName(QStringLiteral("info_inputType"));

        gridLayout_3->addWidget(info_inputType, 2, 5, 1, 1);

        combo_axis1 = new QComboBox(frameInfo);
        combo_axis1->setObjectName(QStringLiteral("combo_axis1"));
        combo_axis1->setMinimumSize(QSize(0, 25));
        combo_axis1->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(combo_axis1, 1, 1, 1, 1);

        lbl_sampeRate = new QLabel(frameInfo);
        lbl_sampeRate->setObjectName(QStringLiteral("lbl_sampeRate"));
        lbl_sampeRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_sampeRate->setIndent(-1);

        gridLayout_3->addWidget(lbl_sampeRate, 0, 4, 1, 1);

        m_serialPortLabel = new QLabel(frameInfo);
        m_serialPortLabel->setObjectName(QStringLiteral("m_serialPortLabel"));
        m_serialPortLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_serialPortLabel->setIndent(3);

        gridLayout_3->addWidget(m_serialPortLabel, 0, 2, 1, 1);

        info_filterType = new QLabel(frameInfo);
        info_filterType->setObjectName(QStringLiteral("info_filterType"));

        gridLayout_3->addWidget(info_filterType, 1, 5, 1, 1);

        label_3 = new QLabel(frameInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_3, 2, 2, 1, 1);

        combo_rawreal = new QComboBox(frameInfo);
        combo_rawreal->setObjectName(QStringLiteral("combo_rawreal"));
        combo_rawreal->setMinimumSize(QSize(0, 25));
        combo_rawreal->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(combo_rawreal, 2, 3, 1, 1);

        m_serialPortComboBox = new QComboBox(frameInfo);
        m_serialPortComboBox->setObjectName(QStringLiteral("m_serialPortComboBox"));
        m_serialPortComboBox->setMinimumSize(QSize(0, 25));
        m_serialPortComboBox->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(m_serialPortComboBox, 0, 3, 1, 1);

        combo_recPeriod = new QComboBox(frameInfo);
        combo_recPeriod->setObjectName(QStringLiteral("combo_recPeriod"));
        combo_recPeriod->setMinimumSize(QSize(0, 25));
        combo_recPeriod->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(combo_recPeriod, 1, 3, 1, 1);

        info_sampeRate = new QLabel(frameInfo);
        info_sampeRate->setObjectName(QStringLiteral("info_sampeRate"));

        gridLayout_3->addWidget(info_sampeRate, 0, 5, 1, 1);

        lbl_axis1 = new QLabel(frameInfo);
        lbl_axis1->setObjectName(QStringLiteral("lbl_axis1"));
        lbl_axis1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_axis1->setIndent(3);

        gridLayout_3->addWidget(lbl_axis1, 1, 0, 1, 1);

        combo_axis2 = new QComboBox(frameInfo);
        combo_axis2->setObjectName(QStringLiteral("combo_axis2"));
        combo_axis2->setMinimumSize(QSize(0, 25));
        combo_axis2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_3->addWidget(combo_axis2, 2, 1, 1, 1);

        label_2 = new QLabel(frameInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2->setIndent(3);

        gridLayout_3->addWidget(label_2, 1, 2, 1, 1);

        lbl_filterType = new QLabel(frameInfo);
        lbl_filterType->setObjectName(QStringLiteral("lbl_filterType"));
        lbl_filterType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_filterType->setIndent(3);

        gridLayout_3->addWidget(lbl_filterType, 1, 4, 1, 1);


        gridLayout_2->addWidget(frameInfo, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_graphDialog = new QPushButton(MainPage);
        btn_graphDialog->setObjectName(QStringLiteral("btn_graphDialog"));
        btn_graphDialog->setMinimumSize(QSize(0, 25));
        btn_graphDialog->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btn_graphDialog);

        btn_plotGraph = new QPushButton(MainPage);
        btn_plotGraph->setObjectName(QStringLiteral("btn_plotGraph"));
        btn_plotGraph->setMinimumSize(QSize(0, 25));
        btn_plotGraph->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btn_plotGraph);

        btn_dispGrap = new QPushButton(MainPage);
        btn_dispGrap->setObjectName(QStringLiteral("btn_dispGrap"));
        btn_dispGrap->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btn_dispGrap);

        btn_dispList = new QPushButton(MainPage);
        btn_dispList->setObjectName(QStringLiteral("btn_dispList"));
        btn_dispList->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(btn_dispList);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        wdgGraph = new QTabWidget(MainPage);
        wdgGraph->setObjectName(QStringLiteral("wdgGraph"));
        pg1 = new QWidget();
        pg1->setObjectName(QStringLiteral("pg1"));
        wdgGraph->addTab(pg1, QString());
        pg2 = new QWidget();
        pg2->setObjectName(QStringLiteral("pg2"));
        wdgGraph->addTab(pg2, QString());

        gridLayout_2->addWidget(wdgGraph, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 5);
        gridLayout_2->setColumnStretch(0, 4);
        gridLayout_2->setColumnStretch(1, 1);
        tabWidget->addTab(MainPage, QString());
        CalibPage = new QWidget();
        CalibPage->setObjectName(QStringLiteral("CalibPage"));
        gridLayout_5 = new QGridLayout(CalibPage);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(3, 3, 3, 9);
        scrollCalPoint = new QScrollArea(CalibPage);
        scrollCalPoint->setObjectName(QStringLiteral("scrollCalPoint"));
        scrollCalPoint->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 322, 465));
        scrollCalPoint->setWidget(scrollAreaWidgetContents_4);

        gridLayout_5->addWidget(scrollCalPoint, 1, 0, 1, 1);

        wdgCalib = new QWidget(CalibPage);
        wdgCalib->setObjectName(QStringLiteral("wdgCalib"));
        gridLayout_6 = new QGridLayout(wdgCalib);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 0, -1, 0);
        wdgInput = new QWidget(wdgCalib);
        wdgInput->setObjectName(QStringLiteral("wdgInput"));

        gridLayout_6->addWidget(wdgInput, 1, 0, 1, 1);

        frameCalibSet = new QFrame(wdgCalib);
        frameCalibSet->setObjectName(QStringLiteral("frameCalibSet"));
        gridLayout_7 = new QGridLayout(frameCalibSet);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(2);
        gridLayout_7->setContentsMargins(-1, 5, -1, 5);
        CoBoxFilterType = new QComboBox(frameCalibSet);
        CoBoxFilterType->setObjectName(QStringLiteral("CoBoxFilterType"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CoBoxFilterType->sizePolicy().hasHeightForWidth());
        CoBoxFilterType->setSizePolicy(sizePolicy);
        CoBoxFilterType->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_7->addWidget(CoBoxFilterType, 2, 4, 1, 1);

        CoBoxInputType = new QComboBox(frameCalibSet);
        CoBoxInputType->setObjectName(QStringLiteral("CoBoxInputType"));
        sizePolicy.setHeightForWidth(CoBoxInputType->sizePolicy().hasHeightForWidth());
        CoBoxInputType->setSizePolicy(sizePolicy);
        CoBoxInputType->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_7->addWidget(CoBoxInputType, 2, 1, 1, 1);

        SampeRate = new QLabel(frameCalibSet);
        SampeRate->setObjectName(QStringLiteral("SampeRate"));

        gridLayout_7->addWidget(SampeRate, 0, 3, 1, 1);

        CoBoxSampeRate = new QComboBox(frameCalibSet);
        CoBoxSampeRate->setObjectName(QStringLiteral("CoBoxSampeRate"));
        sizePolicy.setHeightForWidth(CoBoxSampeRate->sizePolicy().hasHeightForWidth());
        CoBoxSampeRate->setSizePolicy(sizePolicy);
        CoBoxSampeRate->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_7->addWidget(CoBoxSampeRate, 0, 4, 1, 1);

        DataFormat = new QLabel(frameCalibSet);
        DataFormat->setObjectName(QStringLiteral("DataFormat"));

        gridLayout_7->addWidget(DataFormat, 1, 3, 1, 1);

        CoBoxDataFormat = new QComboBox(frameCalibSet);
        CoBoxDataFormat->setObjectName(QStringLiteral("CoBoxDataFormat"));
        sizePolicy.setHeightForWidth(CoBoxDataFormat->sizePolicy().hasHeightForWidth());
        CoBoxDataFormat->setSizePolicy(sizePolicy);
        CoBoxDataFormat->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_7->addWidget(CoBoxDataFormat, 1, 4, 1, 1);

        CoBoxChannel = new QComboBox(frameCalibSet);
        CoBoxChannel->setObjectName(QStringLiteral("CoBoxChannel"));
        sizePolicy.setHeightForWidth(CoBoxChannel->sizePolicy().hasHeightForWidth());
        CoBoxChannel->setSizePolicy(sizePolicy);
        CoBoxChannel->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_7->addWidget(CoBoxChannel, 1, 1, 1, 1);

        FilterType = new QLabel(frameCalibSet);
        FilterType->setObjectName(QStringLiteral("FilterType"));

        gridLayout_7->addWidget(FilterType, 2, 3, 1, 1);

        Channel = new QLabel(frameCalibSet);
        Channel->setObjectName(QStringLiteral("Channel"));

        gridLayout_7->addWidget(Channel, 1, 0, 1, 1);

        InputType = new QLabel(frameCalibSet);
        InputType->setObjectName(QStringLiteral("InputType"));

        gridLayout_7->addWidget(InputType, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(1, 2);
        gridLayout_7->setColumnStretch(2, 1);
        gridLayout_7->setColumnStretch(3, 1);
        gridLayout_7->setColumnStretch(4, 2);

        gridLayout_6->addWidget(frameCalibSet, 0, 0, 1, 1);

        CalbtnFrame1 = new QFrame(wdgCalib);
        CalbtnFrame1->setObjectName(QStringLiteral("CalbtnFrame1"));
        horizontalLayout = new QHBoxLayout(CalbtnFrame1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        btnSendParData = new QPushButton(CalbtnFrame1);
        btnSendParData->setObjectName(QStringLiteral("btnSendParData"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSendParData->sizePolicy().hasHeightForWidth());
        btnSendParData->setSizePolicy(sizePolicy1);
        btnSendParData->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnSendParData);

        btnSendCalData = new QPushButton(CalbtnFrame1);
        btnSendCalData->setObjectName(QStringLiteral("btnSendCalData"));
        sizePolicy1.setHeightForWidth(btnSendCalData->sizePolicy().hasHeightForWidth());
        btnSendCalData->setSizePolicy(sizePolicy1);
        btnSendCalData->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnSendCalData);

        btnWriteParDataToFlash = new QPushButton(CalbtnFrame1);
        btnWriteParDataToFlash->setObjectName(QStringLiteral("btnWriteParDataToFlash"));
        sizePolicy1.setHeightForWidth(btnWriteParDataToFlash->sizePolicy().hasHeightForWidth());
        btnWriteParDataToFlash->setSizePolicy(sizePolicy1);
        btnWriteParDataToFlash->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btnWriteParDataToFlash);

        m_SetSerialPortButton = new QPushButton(CalbtnFrame1);
        m_SetSerialPortButton->setObjectName(QStringLiteral("m_SetSerialPortButton"));
        sizePolicy1.setHeightForWidth(m_SetSerialPortButton->sizePolicy().hasHeightForWidth());
        m_SetSerialPortButton->setSizePolicy(sizePolicy1);
        m_SetSerialPortButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(m_SetSerialPortButton);


        gridLayout_6->addWidget(CalbtnFrame1, 2, 0, 1, 1);

        gridLayout_6->setRowStretch(0, 2);
        gridLayout_6->setRowStretch(1, 10);

        gridLayout_5->addWidget(wdgCalib, 1, 1, 1, 1);

        scrollArea = new QScrollArea(CalibPage);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 977, 115));
        scrollArea->setWidget(scrollAreaWidgetContents_3);

        gridLayout_5->addWidget(scrollArea, 0, 0, 1, 2);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 4);
        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 2);
        tabWidget->addTab(CalibPage, QString());
        SettingsPage = new QWidget();
        SettingsPage->setObjectName(QStringLiteral("SettingsPage"));
        gridLayout_10 = new QGridLayout(SettingsPage);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(9, 9, 9, 9);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 6, 3, 1, 1);

        label_21 = new QLabel(SettingsPage);
        label_21->setObjectName(QStringLiteral("label_21"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);
        label_21->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(250, 250, 250);"));
        label_21->setMargin(5);
        label_21->setIndent(9);

        gridLayout_10->addWidget(label_21, 3, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer, 2, 1, 1, 1);

        label_19 = new QLabel(SettingsPage);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);
        label_19->setStyleSheet(QLatin1String("background-color: rgb(85, 87, 83);\n"
"color: rgb(250, 250, 250);"));
        label_19->setMargin(5);
        label_19->setIndent(9);

        gridLayout_10->addWidget(label_19, 0, 0, 1, 4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_2, 5, 1, 1, 1);

        lbl_version = new QLabel(SettingsPage);
        lbl_version->setObjectName(QStringLiteral("lbl_version"));
        QFont font;
        font.setFamily(QStringLiteral("Cantarell"));
        lbl_version->setFont(font);
        lbl_version->setTextFormat(Qt::AutoText);

        gridLayout_10->addWidget(lbl_version, 7, 0, 1, 4);

        widget_3 = new QWidget(SettingsPage);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout_17 = new QGridLayout(widget_3);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        lbl_settingsTime = new QLabel(widget_3);
        lbl_settingsTime->setObjectName(QStringLiteral("lbl_settingsTime"));

        gridLayout_17->addWidget(lbl_settingsTime, 0, 0, 1, 1);

        minutesText = new QLabel(widget_3);
        minutesText->setObjectName(QStringLiteral("minutesText"));
        minutesText->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(minutesText, 0, 3, 1, 1);

        hundredthsText = new QLabel(widget_3);
        hundredthsText->setObjectName(QStringLiteral("hundredthsText"));
        hundredthsText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(hundredthsText, 0, 1, 1, 1);

        secondsText = new QLabel(widget_3);
        secondsText->setObjectName(QStringLiteral("secondsText"));

        gridLayout_17->addWidget(secondsText, 0, 6, 1, 1);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_5, 0, 5, 1, 1);

        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label, 0, 2, 1, 1);


        gridLayout_10->addWidget(widget_3, 6, 2, 1, 1);

        widget = new QWidget(SettingsPage);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_15 = new QGridLayout(widget);
        gridLayout_15->setSpacing(18);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        activeChannels = new QLabel(widget);
        activeChannels->setObjectName(QStringLiteral("activeChannels"));
        activeChannels->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        activeChannels->setIndent(4);

        gridLayout_15->addWidget(activeChannels, 3, 1, 1, 2);

        currentPort = new QLabel(widget);
        currentPort->setObjectName(QStringLiteral("currentPort"));
        currentPort->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        currentPort->setIndent(4);

        gridLayout_15->addWidget(currentPort, 4, 1, 1, 2);

        label_26 = new QLabel(widget);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_15->addWidget(label_26, 4, 0, 1, 1);

        label_28 = new QLabel(widget);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_15->addWidget(label_28, 5, 0, 1, 1);

        label_23 = new QLabel(widget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_15->addWidget(label_23, 2, 0, 1, 1);

        channelName = new QLineEdit(widget);
        channelName->setObjectName(QStringLiteral("channelName"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(channelName->sizePolicy().hasHeightForWidth());
        channelName->setSizePolicy(sizePolicy3);

        gridLayout_15->addWidget(channelName, 0, 2, 1, 1);

        combo_channels = new QComboBox(widget);
        combo_channels->setObjectName(QStringLiteral("combo_channels"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(combo_channels->sizePolicy().hasHeightForWidth());
        combo_channels->setSizePolicy(sizePolicy4);
        combo_channels->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_15->addWidget(combo_channels, 0, 1, 1, 1);

        label_24 = new QLabel(widget);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_15->addWidget(label_24, 3, 0, 1, 1);

        btn_saveChn = new QPushButton(widget);
        btn_saveChn->setObjectName(QStringLiteral("btn_saveChn"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btn_saveChn->sizePolicy().hasHeightForWidth());
        btn_saveChn->setSizePolicy(sizePolicy5);
        btn_saveChn->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_15->addWidget(btn_saveChn, 1, 2, 1, 1);

        label_22 = new QLabel(widget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_15->addWidget(label_22, 0, 0, 1, 1);

        memory = new QProgressBar(widget);
        memory->setObjectName(QStringLiteral("memory"));
        memory->setValue(24);

        gridLayout_15->addWidget(memory, 5, 1, 1, 2);

        horizontalFrame = new QFrame(widget);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalLayout_2 = new QHBoxLayout(horizontalFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioBtn_csv = new QRadioButton(horizontalFrame);
        radioBtn_csv->setObjectName(QStringLiteral("radioBtn_csv"));
        radioBtn_csv->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(radioBtn_csv);

        radioBtn_pdf = new QRadioButton(horizontalFrame);
        radioBtn_pdf->setObjectName(QStringLiteral("radioBtn_pdf"));
        radioBtn_pdf->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(radioBtn_pdf);

        radioBtn_txt = new QRadioButton(horizontalFrame);
        radioBtn_txt->setObjectName(QStringLiteral("radioBtn_txt"));
        radioBtn_txt->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(radioBtn_txt);


        gridLayout_15->addWidget(horizontalFrame, 2, 1, 1, 2);

        gridLayout_15->setRowStretch(0, 1);
        gridLayout_15->setRowStretch(1, 1);
        gridLayout_15->setRowStretch(2, 1);
        gridLayout_15->setRowStretch(5, 1);
        gridLayout_15->setColumnStretch(0, 1);
        gridLayout_15->setColumnStretch(1, 1);
        gridLayout_15->setColumnStretch(2, 1);

        gridLayout_10->addWidget(widget, 4, 0, 1, 1);

        widget_2 = new QWidget(SettingsPage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_16 = new QGridLayout(widget_2);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setVerticalSpacing(12);
        label_20 = new QLabel(widget_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_16->addWidget(label_20, 0, 0, 1, 1);

        password = new QLineEdit(widget_2);
        password->setObjectName(QStringLiteral("password"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy6);

        gridLayout_16->addWidget(password, 0, 1, 1, 1);

        btn_password = new QPushButton(widget_2);
        btn_password->setObjectName(QStringLiteral("btn_password"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(btn_password->sizePolicy().hasHeightForWidth());
        btn_password->setSizePolicy(sizePolicy7);
        btn_password->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_16->addWidget(btn_password, 0, 2, 1, 1);

        btn_newPassword = new QPushButton(widget_2);
        btn_newPassword->setObjectName(QStringLiteral("btn_newPassword"));
        sizePolicy7.setHeightForWidth(btn_newPassword->sizePolicy().hasHeightForWidth());
        btn_newPassword->setSizePolicy(sizePolicy7);
        btn_newPassword->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_16->addWidget(btn_newPassword, 1, 1, 1, 1);

        gridLayout_16->setColumnStretch(0, 1);
        gridLayout_16->setColumnStretch(1, 1);
        gridLayout_16->setColumnStretch(2, 1);

        gridLayout_10->addWidget(widget_2, 1, 0, 1, 1);

        widget_4 = new QWidget(SettingsPage);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        gridLayout_10->addWidget(widget_4, 1, 1, 1, 3);

        gridLayout_10->setRowStretch(1, 1);
        gridLayout_10->setRowStretch(4, 1);
        gridLayout_10->setRowStretch(5, 1);
        gridLayout_10->setColumnStretch(0, 3);
        gridLayout_10->setColumnStretch(1, 1);
        tabWidget->addTab(SettingsPage, QString());
        PortSetPage = new QWidget();
        PortSetPage->setObjectName(QStringLiteral("PortSetPage"));
        gridLayout_11 = new QGridLayout(PortSetPage);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        wdgPort = new QWidget(PortSetPage);
        wdgPort->setObjectName(QStringLiteral("wdgPort"));
        gridLayout_12 = new QGridLayout(wdgPort);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        lbl_COMport = new QLabel(wdgPort);
        lbl_COMport->setObjectName(QStringLiteral("lbl_COMport"));

        gridLayout_12->addWidget(lbl_COMport, 0, 0, 1, 1);

        COMport = new QLineEdit(wdgPort);
        COMport->setObjectName(QStringLiteral("COMport"));

        gridLayout_12->addWidget(COMport, 0, 1, 1, 1);

        lbl_adres = new QLabel(wdgPort);
        lbl_adres->setObjectName(QStringLiteral("lbl_adres"));

        gridLayout_12->addWidget(lbl_adres, 1, 0, 1, 1);

        adres = new QLineEdit(wdgPort);
        adres->setObjectName(QStringLiteral("adres"));

        gridLayout_12->addWidget(adres, 1, 1, 1, 1);

        lbl_timeout = new QLabel(wdgPort);
        lbl_timeout->setObjectName(QStringLiteral("lbl_timeout"));

        gridLayout_12->addWidget(lbl_timeout, 2, 0, 1, 1);

        timeout = new QLineEdit(wdgPort);
        timeout->setObjectName(QStringLiteral("timeout"));

        gridLayout_12->addWidget(timeout, 2, 1, 1, 1);

        lbl_IP = new QLabel(wdgPort);
        lbl_IP->setObjectName(QStringLiteral("lbl_IP"));

        gridLayout_12->addWidget(lbl_IP, 3, 0, 1, 1);

        IP = new QLineEdit(wdgPort);
        IP->setObjectName(QStringLiteral("IP"));

        gridLayout_12->addWidget(IP, 3, 1, 1, 1);

        gridLayout_12->setColumnStretch(0, 1);
        gridLayout_12->setColumnStretch(1, 1);

        gridLayout_11->addWidget(wdgPort, 1, 0, 1, 1);

        widget_9 = new QWidget(PortSetPage);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        gridLayout_13 = new QGridLayout(widget_9);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_39 = new QLabel(widget_9);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_13->addWidget(label_39, 0, 0, 1, 1);

        label_40 = new QLabel(widget_9);
        label_40->setObjectName(QStringLiteral("label_40"));

        gridLayout_13->addWidget(label_40, 0, 1, 1, 1);

        label_41 = new QLabel(widget_9);
        label_41->setObjectName(QStringLiteral("label_41"));

        gridLayout_13->addWidget(label_41, 1, 0, 1, 1);

        label_42 = new QLabel(widget_9);
        label_42->setObjectName(QStringLiteral("label_42"));

        gridLayout_13->addWidget(label_42, 1, 1, 1, 1);

        label_43 = new QLabel(widget_9);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout_13->addWidget(label_43, 2, 0, 1, 1);

        label_44 = new QLabel(widget_9);
        label_44->setObjectName(QStringLiteral("label_44"));

        gridLayout_13->addWidget(label_44, 2, 1, 1, 1);

        label_45 = new QLabel(widget_9);
        label_45->setObjectName(QStringLiteral("label_45"));

        gridLayout_13->addWidget(label_45, 3, 0, 1, 1);

        label_46 = new QLabel(widget_9);
        label_46->setObjectName(QStringLiteral("label_46"));

        gridLayout_13->addWidget(label_46, 3, 1, 1, 1);


        gridLayout_11->addWidget(widget_9, 2, 0, 1, 1);

        wdgHidden = new QWidget(PortSetPage);
        wdgHidden->setObjectName(QStringLiteral("wdgHidden"));

        gridLayout_11->addWidget(wdgHidden, 3, 0, 1, 1);

        widget_8 = new QWidget(PortSetPage);
        widget_8->setObjectName(QStringLiteral("widget_8"));

        gridLayout_11->addWidget(widget_8, 3, 1, 1, 1);

        framePortCombo = new QFrame(PortSetPage);
        framePortCombo->setObjectName(QStringLiteral("framePortCombo"));
        framePortCombo->setFrameShape(QFrame::StyledPanel);
        framePortCombo->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(framePortCombo);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(9);
        combo_portType = new QComboBox(framePortCombo);
        combo_portType->setObjectName(QStringLiteral("combo_portType"));
        combo_portType->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_4->addWidget(combo_portType, 0, 1, 1, 1);

        lbl_portType = new QLabel(framePortCombo);
        lbl_portType->setObjectName(QStringLiteral("lbl_portType"));

        gridLayout_4->addWidget(lbl_portType, 0, 0, 1, 1);

        pushButton_11 = new QPushButton(framePortCombo);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_4->addWidget(pushButton_11, 0, 2, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnStretch(2, 1);

        gridLayout_11->addWidget(framePortCombo, 0, 0, 1, 1);

        gridLayout_11->setRowStretch(1, 1);
        gridLayout_11->setRowStretch(2, 1);
        gridLayout_11->setRowStretch(3, 1);
        gridLayout_11->setColumnStretch(0, 1);
        gridLayout_11->setColumnStretch(1, 1);
        tabWidget->addTab(PortSetPage, QString());
        AlertsPage = new QWidget();
        AlertsPage->setObjectName(QStringLiteral("AlertsPage"));
        gridLayout_14 = new QGridLayout(AlertsPage);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(3, 3, 3, 3);
        tabWidget_alarm = new QTabWidget(AlertsPage);
        tabWidget_alarm->setObjectName(QStringLiteral("tabWidget_alarm"));
        AlarmModes = new QWidget();
        AlarmModes->setObjectName(QStringLiteral("AlarmModes"));
        tabWidget_alarm->addTab(AlarmModes, QString());
        AlarmControl = new QWidget();
        AlarmControl->setObjectName(QStringLiteral("AlarmControl"));
        tabWidget_alarm->addTab(AlarmControl, QString());
        AlarmDelay = new QWidget();
        AlarmDelay->setObjectName(QStringLiteral("AlarmDelay"));
        tabWidget_alarm->addTab(AlarmDelay, QString());
        AlarmActive = new QWidget();
        AlarmActive->setObjectName(QStringLiteral("AlarmActive"));
        gridLayout_8 = new QGridLayout(AlarmActive);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        table_alarm = new QTableWidget(AlarmActive);
        table_alarm->setObjectName(QStringLiteral("table_alarm"));

        gridLayout_8->addWidget(table_alarm, 0, 0, 1, 1);

        tabWidget_alarm->addTab(AlarmActive, QString());

        gridLayout_14->addWidget(tabWidget_alarm, 1, 0, 1, 1);

        scrollAlerts = new QScrollArea(AlertsPage);
        scrollAlerts->setObjectName(QStringLiteral("scrollAlerts"));
        scrollAlerts->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 977, 293));
        scrollAlerts->setWidget(scrollAreaWidgetContents_2);

        gridLayout_14->addWidget(scrollAlerts, 0, 0, 1, 1);

        gridLayout_14->setRowStretch(0, 1);
        gridLayout_14->setRowStretch(1, 1);
        tabWidget->addTab(AlertsPage, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        DLCalMenu->setCentralWidget(centralWidget);
        toolBar = new QToolBar(DLCalMenu);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        DLCalMenu->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(tabWidget, combo_axis1);
        QWidget::setTabOrder(combo_axis1, combo_axis2);
        QWidget::setTabOrder(combo_axis2, m_serialPortComboBox);
        QWidget::setTabOrder(m_serialPortComboBox, combo_recPeriod);
        QWidget::setTabOrder(combo_recPeriod, combo_rawreal);
        QWidget::setTabOrder(combo_rawreal, btn_graphDialog);
        QWidget::setTabOrder(btn_graphDialog, btn_plotGraph);
        QWidget::setTabOrder(btn_plotGraph, btn_dispGrap);
        QWidget::setTabOrder(btn_dispGrap, btn_dispList);
        QWidget::setTabOrder(btn_dispList, scrollReals);
        QWidget::setTabOrder(scrollReals, wdgGraph);
        QWidget::setTabOrder(wdgGraph, scrollArea);
        QWidget::setTabOrder(scrollArea, scrollCalPoint);
        QWidget::setTabOrder(scrollCalPoint, CoBoxChannel);
        QWidget::setTabOrder(CoBoxChannel, CoBoxInputType);
        QWidget::setTabOrder(CoBoxInputType, CoBoxSampeRate);
        QWidget::setTabOrder(CoBoxSampeRate, CoBoxDataFormat);
        QWidget::setTabOrder(CoBoxDataFormat, CoBoxFilterType);
        QWidget::setTabOrder(CoBoxFilterType, btnSendParData);
        QWidget::setTabOrder(btnSendParData, btnSendCalData);
        QWidget::setTabOrder(btnSendCalData, btnWriteParDataToFlash);
        QWidget::setTabOrder(btnWriteParDataToFlash, m_SetSerialPortButton);
        QWidget::setTabOrder(m_SetSerialPortButton, password);
        QWidget::setTabOrder(password, btn_password);
        QWidget::setTabOrder(btn_password, btn_newPassword);
        QWidget::setTabOrder(btn_newPassword, combo_channels);
        QWidget::setTabOrder(combo_channels, channelName);
        QWidget::setTabOrder(channelName, btn_saveChn);
        QWidget::setTabOrder(btn_saveChn, combo_portType);
        QWidget::setTabOrder(combo_portType, pushButton_11);
        QWidget::setTabOrder(pushButton_11, COMport);
        QWidget::setTabOrder(COMport, adres);
        QWidget::setTabOrder(adres, timeout);
        QWidget::setTabOrder(timeout, IP);
        QWidget::setTabOrder(IP, scrollAlerts);
        QWidget::setTabOrder(scrollAlerts, tabWidget_alarm);
        QWidget::setTabOrder(tabWidget_alarm, table_alarm);

        retranslateUi(DLCalMenu);

        tabWidget->setCurrentIndex(2);
        wdgGraph->setCurrentIndex(1);
        tabWidget_alarm->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DLCalMenu);
    } // setupUi

    void retranslateUi(QMainWindow *DLCalMenu)
    {
        DLCalMenu->setWindowTitle(QApplication::translate("DLCalMenu", "DLCalMenu", Q_NULLPTR));
        lbl_axis2->setText(QApplication::translate("DLCalMenu", "Axis Y :", Q_NULLPTR));
        lbl_inputType->setText(QApplication::translate("DLCalMenu", "Input Type :", Q_NULLPTR));
        info_inputType->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        lbl_sampeRate->setText(QApplication::translate("DLCalMenu", "Sampe Rate :", Q_NULLPTR));
        m_serialPortLabel->setText(QApplication::translate("DLCalMenu", "Serial Port :", Q_NULLPTR));
        info_filterType->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        label_3->setText(QApplication::translate("DLCalMenu", "Show Data :", Q_NULLPTR));
        info_sampeRate->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        lbl_axis1->setText(QApplication::translate("DLCalMenu", "Axis X :", Q_NULLPTR));
        label_2->setText(QApplication::translate("DLCalMenu", "Period :", Q_NULLPTR));
        lbl_filterType->setText(QApplication::translate("DLCalMenu", "Filter Type :", Q_NULLPTR));
        btn_graphDialog->setText(QApplication::translate("DLCalMenu", "Read From ..", Q_NULLPTR));
        btn_plotGraph->setText(QApplication::translate("DLCalMenu", "Plot Graph", Q_NULLPTR));
        btn_dispGrap->setText(QApplication::translate("DLCalMenu", "Display Graph", Q_NULLPTR));
        btn_dispList->setText(QApplication::translate("DLCalMenu", "Display Results", Q_NULLPTR));
        wdgGraph->setTabText(wdgGraph->indexOf(pg1), QApplication::translate("DLCalMenu", "plot", Q_NULLPTR));
        wdgGraph->setTabText(wdgGraph->indexOf(pg2), QApplication::translate("DLCalMenu", "list", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(MainPage), QApplication::translate("DLCalMenu", "Main", Q_NULLPTR));
        SampeRate->setText(QApplication::translate("DLCalMenu", "Sampe Rate :", Q_NULLPTR));
        DataFormat->setText(QApplication::translate("DLCalMenu", "Data Format :", Q_NULLPTR));
        FilterType->setText(QApplication::translate("DLCalMenu", "Filter Type :", Q_NULLPTR));
        Channel->setText(QApplication::translate("DLCalMenu", "Channels :", Q_NULLPTR));
        InputType->setText(QApplication::translate("DLCalMenu", "Input Type :", Q_NULLPTR));
        btnSendParData->setText(QApplication::translate("DLCalMenu", "SEND PAR", Q_NULLPTR));
        btnSendCalData->setText(QApplication::translate("DLCalMenu", "SEND CAL", Q_NULLPTR));
        btnWriteParDataToFlash->setText(QApplication::translate("DLCalMenu", "RECORD CH", Q_NULLPTR));
        m_SetSerialPortButton->setText(QApplication::translate("DLCalMenu", "SET PORT", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(CalibPage), QApplication::translate("DLCalMenu", "Calib", Q_NULLPTR));
        label_21->setText(QApplication::translate("DLCalMenu", "Device Settings :", Q_NULLPTR));
        label_19->setText(QApplication::translate("DLCalMenu", "Enter password to use device..", Q_NULLPTR));
        lbl_version->setText(QApplication::translate("DLCalMenu", "Version", Q_NULLPTR));
        lbl_settingsTime->setText(QApplication::translate("DLCalMenu", "Connected since ", Q_NULLPTR));
        minutesText->setText(QApplication::translate("DLCalMenu", "00", Q_NULLPTR));
        hundredthsText->setText(QApplication::translate("DLCalMenu", "00", Q_NULLPTR));
        secondsText->setText(QApplication::translate("DLCalMenu", "00", Q_NULLPTR));
        label_5->setText(QApplication::translate("DLCalMenu", ":", Q_NULLPTR));
        label->setText(QApplication::translate("DLCalMenu", ":", Q_NULLPTR));
        activeChannels->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        currentPort->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        label_26->setText(QApplication::translate("DLCalMenu", "Connected Port :", Q_NULLPTR));
        label_28->setText(QApplication::translate("DLCalMenu", "Memory :", Q_NULLPTR));
        label_23->setText(QApplication::translate("DLCalMenu", "Export Format :", Q_NULLPTR));
        label_24->setText(QApplication::translate("DLCalMenu", "Active Channel :", Q_NULLPTR));
        btn_saveChn->setText(QApplication::translate("DLCalMenu", "Save", Q_NULLPTR));
        label_22->setText(QApplication::translate("DLCalMenu", "Channel :", Q_NULLPTR));
        radioBtn_csv->setText(QApplication::translate("DLCalMenu", ".csv", Q_NULLPTR));
        radioBtn_pdf->setText(QApplication::translate("DLCalMenu", ".pdf", Q_NULLPTR));
        radioBtn_txt->setText(QApplication::translate("DLCalMenu", ".txt", Q_NULLPTR));
        label_20->setText(QApplication::translate("DLCalMenu", "Password    :     ", Q_NULLPTR));
        btn_password->setText(QApplication::translate("DLCalMenu", "OK", Q_NULLPTR));
        btn_newPassword->setText(QApplication::translate("DLCalMenu", "Change password", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(SettingsPage), QApplication::translate("DLCalMenu", "Settings", Q_NULLPTR));
        lbl_COMport->setText(QApplication::translate("DLCalMenu", "COM Port :", Q_NULLPTR));
        lbl_adres->setText(QApplication::translate("DLCalMenu", "Address :", Q_NULLPTR));
        lbl_timeout->setText(QApplication::translate("DLCalMenu", "Connection Timeout :", Q_NULLPTR));
        lbl_IP->setText(QApplication::translate("DLCalMenu", "IP Address :", Q_NULLPTR));
        label_39->setText(QApplication::translate("DLCalMenu", "Statu :", Q_NULLPTR));
        label_40->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        label_41->setText(QApplication::translate("DLCalMenu", "Device Number :", Q_NULLPTR));
        label_42->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        label_43->setText(QApplication::translate("DLCalMenu", "Product Code :", Q_NULLPTR));
        label_44->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        label_45->setText(QApplication::translate("DLCalMenu", "Serial No :", Q_NULLPTR));
        label_46->setText(QApplication::translate("DLCalMenu", "-", Q_NULLPTR));
        lbl_portType->setText(QApplication::translate("DLCalMenu", "Port Type :", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("DLCalMenu", "CONNECT", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(PortSetPage), QApplication::translate("DLCalMenu", "Ports", Q_NULLPTR));
        tabWidget_alarm->setTabText(tabWidget_alarm->indexOf(AlarmModes), QApplication::translate("DLCalMenu", "Alarm Modes", Q_NULLPTR));
        tabWidget_alarm->setTabText(tabWidget_alarm->indexOf(AlarmControl), QApplication::translate("DLCalMenu", "Control Modes", Q_NULLPTR));
        tabWidget_alarm->setTabText(tabWidget_alarm->indexOf(AlarmDelay), QApplication::translate("DLCalMenu", "Delay", Q_NULLPTR));
        tabWidget_alarm->setTabText(tabWidget_alarm->indexOf(AlarmActive), QApplication::translate("DLCalMenu", "Active Alarms", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(AlertsPage), QApplication::translate("DLCalMenu", "Alerts", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("DLCalMenu", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DLCalMenu: public Ui_DLCalMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLCALMENU_H
