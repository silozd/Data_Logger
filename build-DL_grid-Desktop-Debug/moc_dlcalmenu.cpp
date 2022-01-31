/****************************************************************************
** Meta object code from reading C++ file 'dlcalmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dlcalmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlcalmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DLCalMenu_t {
    QByteArrayData data[96];
    char stringdata0[1623];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DLCalMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DLCalMenu_t qt_meta_stringdata_DLCalMenu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DLCalMenu"
QT_MOC_LITERAL(1, 10, 9), // "setup_GUI"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "scroll_movement"
QT_MOC_LITERAL(4, 37, 14), // "slider_Pressed"
QT_MOC_LITERAL(5, 52, 15), // "slider_Released"
QT_MOC_LITERAL(6, 68, 17), // "SaveCalPartoArray"
QT_MOC_LITERAL(7, 86, 5), // "chnno"
QT_MOC_LITERAL(8, 92, 13), // "DisplayCalPar"
QT_MOC_LITERAL(9, 106, 18), // "DataFormat_Changed"
QT_MOC_LITERAL(10, 125, 17), // "InputType_Warning"
QT_MOC_LITERAL(11, 143, 19), // "Channel_itemChanged"
QT_MOC_LITERAL(12, 163, 4), // "open"
QT_MOC_LITERAL(13, 168, 4), // "save"
QT_MOC_LITERAL(14, 173, 6), // "saveAs"
QT_MOC_LITERAL(15, 180, 11), // "opening_val"
QT_MOC_LITERAL(16, 192, 13), // "GetScreenHRes"
QT_MOC_LITERAL(17, 206, 1), // "s"
QT_MOC_LITERAL(18, 208, 13), // "GetScreenVRes"
QT_MOC_LITERAL(19, 222, 25), // "ScrollBarGain_valueChange"
QT_MOC_LITERAL(20, 248, 5), // "value"
QT_MOC_LITERAL(21, 254, 15), // "SendCalParToVTK"
QT_MOC_LITERAL(22, 270, 16), // "SendCalDataToVTK"
QT_MOC_LITERAL(23, 287, 11), // "UpdateFlash"
QT_MOC_LITERAL(24, 299, 15), // "KeyTimerTimeOut"
QT_MOC_LITERAL(25, 315, 15), // "timer_startStop"
QT_MOC_LITERAL(26, 331, 10), // "resetTimer"
QT_MOC_LITERAL(27, 342, 11), // "update_time"
QT_MOC_LITERAL(28, 354, 8), // "ClearKey"
QT_MOC_LITERAL(29, 363, 12), // "get_password"
QT_MOC_LITERAL(30, 376, 15), // "setup_tableView"
QT_MOC_LITERAL(31, 392, 14), // "setup_combobox"
QT_MOC_LITERAL(32, 407, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(33, 435, 5), // "index"
QT_MOC_LITERAL(34, 441, 32), // "on_m_SetSerialPortButton_clicked"
QT_MOC_LITERAL(35, 474, 24), // "combo_axis1_indexChanged"
QT_MOC_LITERAL(36, 499, 24), // "combo_axis2_indexChanged"
QT_MOC_LITERAL(37, 524, 26), // "on_btn_newPassword_clicked"
QT_MOC_LITERAL(38, 551, 26), // "on_btn_graphDialog_clicked"
QT_MOC_LITERAL(39, 578, 24), // "on_btn_plotGraph_clicked"
QT_MOC_LITERAL(40, 603, 24), // "combo_diaCh_indexChanged"
QT_MOC_LITERAL(41, 628, 27), // "combo_portType_indexChanged"
QT_MOC_LITERAL(42, 656, 28), // "combo_sampeRate_indexChanged"
QT_MOC_LITERAL(43, 685, 29), // "combo_filterType_indexChanged"
QT_MOC_LITERAL(44, 715, 28), // "combo_inputType_indexChanged"
QT_MOC_LITERAL(45, 744, 27), // "combo_channels_indexChanged"
QT_MOC_LITERAL(46, 772, 26), // "combo_rawreal_indexChanged"
QT_MOC_LITERAL(47, 799, 25), // "combo_device_indexChanged"
QT_MOC_LITERAL(48, 825, 23), // "on_btn_password_clicked"
QT_MOC_LITERAL(49, 849, 22), // "on_btn_saveChn_clicked"
QT_MOC_LITERAL(50, 872, 25), // "btn_saveNewPswd_onClicked"
QT_MOC_LITERAL(51, 898, 24), // "btn_cancelPswd_onClicked"
QT_MOC_LITERAL(52, 923, 22), // "btn_okDialog_onClicked"
QT_MOC_LITERAL(53, 946, 26), // "btn_cancelDialog_onClicked"
QT_MOC_LITERAL(54, 973, 23), // "btn_diaGrapOK_onClicked"
QT_MOC_LITERAL(55, 997, 27), // "btn_diaGrapCancel_onClicked"
QT_MOC_LITERAL(56, 1025, 23), // "on_btn_dispList_clicked"
QT_MOC_LITERAL(57, 1049, 23), // "on_btn_dispGrap_clicked"
QT_MOC_LITERAL(58, 1073, 16), // "alarm_initialize"
QT_MOC_LITERAL(59, 1090, 22), // "btn_addAlert_onClicked"
QT_MOC_LITERAL(60, 1113, 22), // "btn_setAlert_onClicked"
QT_MOC_LITERAL(61, 1136, 25), // "btn_removeAlert_onClicked"
QT_MOC_LITERAL(62, 1162, 24), // "checkbox_alert_onClicked"
QT_MOC_LITERAL(63, 1187, 16), // "setup_customPlot"
QT_MOC_LITERAL(64, 1204, 14), // "plot_graphMain"
QT_MOC_LITERAL(65, 1219, 11), // "addNewGraph"
QT_MOC_LITERAL(66, 1231, 19), // "addGraphDialog_Main"
QT_MOC_LITERAL(67, 1251, 13), // "hideGraphPlot"
QT_MOC_LITERAL(68, 1265, 13), // "showGraphPlot"
QT_MOC_LITERAL(69, 1279, 10), // "hideLegend"
QT_MOC_LITERAL(70, 1290, 10), // "showLegend"
QT_MOC_LITERAL(71, 1301, 10), // "removePlot"
QT_MOC_LITERAL(72, 1312, 13), // "removeAllPlot"
QT_MOC_LITERAL(73, 1326, 16), // "selectionChanged"
QT_MOC_LITERAL(74, 1343, 10), // "mousePress"
QT_MOC_LITERAL(75, 1354, 10), // "mouseWheel"
QT_MOC_LITERAL(76, 1365, 18), // "contextMenuRequest"
QT_MOC_LITERAL(77, 1384, 3), // "pos"
QT_MOC_LITERAL(78, 1388, 10), // "moveLegend"
QT_MOC_LITERAL(79, 1399, 12), // "graphClicked"
QT_MOC_LITERAL(80, 1412, 21), // "QCPAbstractPlottable*"
QT_MOC_LITERAL(81, 1434, 9), // "plottable"
QT_MOC_LITERAL(82, 1444, 9), // "dataIndex"
QT_MOC_LITERAL(83, 1454, 20), // "axisLabelDoubleClick"
QT_MOC_LITERAL(84, 1475, 8), // "QCPAxis*"
QT_MOC_LITERAL(85, 1484, 4), // "axis"
QT_MOC_LITERAL(86, 1489, 23), // "QCPAxis::SelectablePart"
QT_MOC_LITERAL(87, 1513, 4), // "part"
QT_MOC_LITERAL(88, 1518, 17), // "legendDoubleClick"
QT_MOC_LITERAL(89, 1536, 10), // "QCPLegend*"
QT_MOC_LITERAL(90, 1547, 6), // "legend"
QT_MOC_LITERAL(91, 1554, 22), // "QCPAbstractLegendItem*"
QT_MOC_LITERAL(92, 1577, 4), // "item"
QT_MOC_LITERAL(93, 1582, 15), // "table_writeData"
QT_MOC_LITERAL(94, 1598, 14), // "table_readData"
QT_MOC_LITERAL(95, 1613, 9) // "exportCsv"

    },
    "DLCalMenu\0setup_GUI\0\0scroll_movement\0"
    "slider_Pressed\0slider_Released\0"
    "SaveCalPartoArray\0chnno\0DisplayCalPar\0"
    "DataFormat_Changed\0InputType_Warning\0"
    "Channel_itemChanged\0open\0save\0saveAs\0"
    "opening_val\0GetScreenHRes\0s\0GetScreenVRes\0"
    "ScrollBarGain_valueChange\0value\0"
    "SendCalParToVTK\0SendCalDataToVTK\0"
    "UpdateFlash\0KeyTimerTimeOut\0timer_startStop\0"
    "resetTimer\0update_time\0ClearKey\0"
    "get_password\0setup_tableView\0"
    "setup_combobox\0on_tabWidget_currentChanged\0"
    "index\0on_m_SetSerialPortButton_clicked\0"
    "combo_axis1_indexChanged\0"
    "combo_axis2_indexChanged\0"
    "on_btn_newPassword_clicked\0"
    "on_btn_graphDialog_clicked\0"
    "on_btn_plotGraph_clicked\0"
    "combo_diaCh_indexChanged\0"
    "combo_portType_indexChanged\0"
    "combo_sampeRate_indexChanged\0"
    "combo_filterType_indexChanged\0"
    "combo_inputType_indexChanged\0"
    "combo_channels_indexChanged\0"
    "combo_rawreal_indexChanged\0"
    "combo_device_indexChanged\0"
    "on_btn_password_clicked\0on_btn_saveChn_clicked\0"
    "btn_saveNewPswd_onClicked\0"
    "btn_cancelPswd_onClicked\0"
    "btn_okDialog_onClicked\0"
    "btn_cancelDialog_onClicked\0"
    "btn_diaGrapOK_onClicked\0"
    "btn_diaGrapCancel_onClicked\0"
    "on_btn_dispList_clicked\0on_btn_dispGrap_clicked\0"
    "alarm_initialize\0btn_addAlert_onClicked\0"
    "btn_setAlert_onClicked\0btn_removeAlert_onClicked\0"
    "checkbox_alert_onClicked\0setup_customPlot\0"
    "plot_graphMain\0addNewGraph\0"
    "addGraphDialog_Main\0hideGraphPlot\0"
    "showGraphPlot\0hideLegend\0showLegend\0"
    "removePlot\0removeAllPlot\0selectionChanged\0"
    "mousePress\0mouseWheel\0contextMenuRequest\0"
    "pos\0moveLegend\0graphClicked\0"
    "QCPAbstractPlottable*\0plottable\0"
    "dataIndex\0axisLabelDoubleClick\0QCPAxis*\0"
    "axis\0QCPAxis::SelectablePart\0part\0"
    "legendDoubleClick\0QCPLegend*\0legend\0"
    "QCPAbstractLegendItem*\0item\0table_writeData\0"
    "table_readData\0exportCsv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DLCalMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      78,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  404,    2, 0x08 /* Private */,
       3,    0,  405,    2, 0x08 /* Private */,
       4,    0,  406,    2, 0x08 /* Private */,
       5,    0,  407,    2, 0x08 /* Private */,
       6,    1,  408,    2, 0x08 /* Private */,
       8,    1,  411,    2, 0x08 /* Private */,
       9,    0,  414,    2, 0x08 /* Private */,
      10,    1,  415,    2, 0x08 /* Private */,
      11,    0,  418,    2, 0x08 /* Private */,
      12,    0,  419,    2, 0x08 /* Private */,
      13,    0,  420,    2, 0x08 /* Private */,
      14,    0,  421,    2, 0x08 /* Private */,
      15,    0,  422,    2, 0x08 /* Private */,
      16,    1,  423,    2, 0x0a /* Public */,
      18,    1,  426,    2, 0x0a /* Public */,
      19,    1,  429,    2, 0x0a /* Public */,
      21,    0,  432,    2, 0x0a /* Public */,
      22,    0,  433,    2, 0x0a /* Public */,
      23,    0,  434,    2, 0x0a /* Public */,
      24,    0,  435,    2, 0x0a /* Public */,
      25,    0,  436,    2, 0x0a /* Public */,
      26,    0,  437,    2, 0x0a /* Public */,
      27,    0,  438,    2, 0x0a /* Public */,
      28,    0,  439,    2, 0x0a /* Public */,
      29,    0,  440,    2, 0x0a /* Public */,
      30,    0,  441,    2, 0x0a /* Public */,
      31,    0,  442,    2, 0x0a /* Public */,
      32,    1,  443,    2, 0x0a /* Public */,
      34,    0,  446,    2, 0x0a /* Public */,
      35,    1,  447,    2, 0x0a /* Public */,
      36,    1,  450,    2, 0x0a /* Public */,
      37,    0,  453,    2, 0x0a /* Public */,
      38,    0,  454,    2, 0x0a /* Public */,
      39,    0,  455,    2, 0x0a /* Public */,
      40,    1,  456,    2, 0x0a /* Public */,
      41,    1,  459,    2, 0x0a /* Public */,
      42,    1,  462,    2, 0x0a /* Public */,
      43,    1,  465,    2, 0x0a /* Public */,
      44,    1,  468,    2, 0x0a /* Public */,
      45,    1,  471,    2, 0x0a /* Public */,
      46,    1,  474,    2, 0x0a /* Public */,
      47,    1,  477,    2, 0x0a /* Public */,
      48,    0,  480,    2, 0x0a /* Public */,
      49,    0,  481,    2, 0x0a /* Public */,
      50,    0,  482,    2, 0x0a /* Public */,
      51,    0,  483,    2, 0x0a /* Public */,
      52,    0,  484,    2, 0x0a /* Public */,
      53,    0,  485,    2, 0x0a /* Public */,
      54,    0,  486,    2, 0x0a /* Public */,
      55,    0,  487,    2, 0x0a /* Public */,
      56,    0,  488,    2, 0x0a /* Public */,
      57,    0,  489,    2, 0x0a /* Public */,
      58,    0,  490,    2, 0x0a /* Public */,
      59,    0,  491,    2, 0x0a /* Public */,
      60,    0,  492,    2, 0x0a /* Public */,
      61,    0,  493,    2, 0x0a /* Public */,
      62,    0,  494,    2, 0x0a /* Public */,
      63,    0,  495,    2, 0x0a /* Public */,
      64,    0,  496,    2, 0x0a /* Public */,
      65,    0,  497,    2, 0x0a /* Public */,
      66,    0,  498,    2, 0x0a /* Public */,
      67,    0,  499,    2, 0x0a /* Public */,
      68,    0,  500,    2, 0x0a /* Public */,
      69,    0,  501,    2, 0x0a /* Public */,
      70,    0,  502,    2, 0x0a /* Public */,
      71,    0,  503,    2, 0x0a /* Public */,
      72,    0,  504,    2, 0x0a /* Public */,
      73,    0,  505,    2, 0x0a /* Public */,
      74,    0,  506,    2, 0x0a /* Public */,
      75,    0,  507,    2, 0x0a /* Public */,
      76,    1,  508,    2, 0x0a /* Public */,
      78,    0,  511,    2, 0x0a /* Public */,
      79,    2,  512,    2, 0x0a /* Public */,
      83,    2,  517,    2, 0x0a /* Public */,
      88,    2,  522,    2, 0x0a /* Public */,
      93,    0,  527,    2, 0x0a /* Public */,
      94,    0,  528,    2, 0x0a /* Public */,
      95,    0,  529,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   17,
    QMetaType::Int, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   77,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 80, QMetaType::Int,   81,   82,
    QMetaType::Void, 0x80000000 | 84, 0x80000000 | 86,   85,   87,
    QMetaType::Void, 0x80000000 | 89, 0x80000000 | 91,   90,   92,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DLCalMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DLCalMenu *_t = static_cast<DLCalMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setup_GUI(); break;
        case 1: _t->scroll_movement(); break;
        case 2: _t->slider_Pressed(); break;
        case 3: _t->slider_Released(); break;
        case 4: _t->SaveCalPartoArray((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->DisplayCalPar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->DataFormat_Changed(); break;
        case 7: _t->InputType_Warning((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->Channel_itemChanged(); break;
        case 9: _t->open(); break;
        case 10: _t->save(); break;
        case 11: _t->saveAs(); break;
        case 12: _t->opening_val(); break;
        case 13: { int _r = _t->GetScreenHRes((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->GetScreenVRes((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->ScrollBarGain_valueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->SendCalParToVTK(); break;
        case 17: _t->SendCalDataToVTK(); break;
        case 18: _t->UpdateFlash(); break;
        case 19: _t->KeyTimerTimeOut(); break;
        case 20: _t->timer_startStop(); break;
        case 21: _t->resetTimer(); break;
        case 22: _t->update_time(); break;
        case 23: _t->ClearKey(); break;
        case 24: _t->get_password(); break;
        case 25: _t->setup_tableView(); break;
        case 26: _t->setup_combobox(); break;
        case 27: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_m_SetSerialPortButton_clicked(); break;
        case 29: _t->combo_axis1_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->combo_axis2_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_btn_newPassword_clicked(); break;
        case 32: _t->on_btn_graphDialog_clicked(); break;
        case 33: _t->on_btn_plotGraph_clicked(); break;
        case 34: _t->combo_diaCh_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->combo_portType_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->combo_sampeRate_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->combo_filterType_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->combo_inputType_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->combo_channels_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->combo_rawreal_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->combo_device_indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_btn_password_clicked(); break;
        case 43: _t->on_btn_saveChn_clicked(); break;
        case 44: _t->btn_saveNewPswd_onClicked(); break;
        case 45: _t->btn_cancelPswd_onClicked(); break;
        case 46: _t->btn_okDialog_onClicked(); break;
        case 47: _t->btn_cancelDialog_onClicked(); break;
        case 48: _t->btn_diaGrapOK_onClicked(); break;
        case 49: _t->btn_diaGrapCancel_onClicked(); break;
        case 50: _t->on_btn_dispList_clicked(); break;
        case 51: _t->on_btn_dispGrap_clicked(); break;
        case 52: _t->alarm_initialize(); break;
        case 53: _t->btn_addAlert_onClicked(); break;
        case 54: _t->btn_setAlert_onClicked(); break;
        case 55: _t->btn_removeAlert_onClicked(); break;
        case 56: _t->checkbox_alert_onClicked(); break;
        case 57: _t->setup_customPlot(); break;
        case 58: _t->plot_graphMain(); break;
        case 59: _t->addNewGraph(); break;
        case 60: _t->addGraphDialog_Main(); break;
        case 61: _t->hideGraphPlot(); break;
        case 62: _t->showGraphPlot(); break;
        case 63: _t->hideLegend(); break;
        case 64: _t->showLegend(); break;
        case 65: _t->removePlot(); break;
        case 66: _t->removeAllPlot(); break;
        case 67: _t->selectionChanged(); break;
        case 68: _t->mousePress(); break;
        case 69: _t->mouseWheel(); break;
        case 70: _t->contextMenuRequest((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 71: _t->moveLegend(); break;
        case 72: _t->graphClicked((*reinterpret_cast< QCPAbstractPlottable*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 73: _t->axisLabelDoubleClick((*reinterpret_cast< QCPAxis*(*)>(_a[1])),(*reinterpret_cast< QCPAxis::SelectablePart(*)>(_a[2]))); break;
        case 74: _t->legendDoubleClick((*reinterpret_cast< QCPLegend*(*)>(_a[1])),(*reinterpret_cast< QCPAbstractLegendItem*(*)>(_a[2]))); break;
        case 75: _t->table_writeData(); break;
        case 76: _t->table_readData(); break;
        case 77: _t->exportCsv(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 72:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAbstractPlottable* >(); break;
            }
            break;
        case 73:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis::SelectablePart >(); break;
            }
            break;
        case 74:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAbstractLegendItem* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPLegend* >(); break;
            }
            break;
        }
    }
}

const QMetaObject DLCalMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DLCalMenu.data,
      qt_meta_data_DLCalMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DLCalMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DLCalMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DLCalMenu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DLCalMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
