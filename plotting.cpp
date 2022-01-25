#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"
#include "qcustomplot.h"
#include <QFont>

void DLCalMenu::setup_customPlot()
{
    QFont legendFont = font();
    QFont AxisFont("Newyork");
    AxisFont.setStyleHint(QFont::SansSerif);
    AxisFont.setPointSize(13);
    legendFont.setPointSize(11);
    // main page :
    QGridLayout *grid_mainPlot = new QGridLayout;
    customPlot_main = new QCustomPlot(ui->wdgGraph);
    ui->wdgGraph->setLayout(grid_mainPlot);
    grid_mainPlot->setContentsMargins(0,0,0,0);
    grid_mainPlot->addWidget(customPlot_main,0,0);
    customPlot_main->addGraph(0);
    customPlot_main->setGeometry(0,0,ui->wdgGraph->width(),ui->wdgGraph->height());
    customPlot_main->setContextMenuPolicy(Qt::CustomContextMenu);
    customPlot_main->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                QCP::iSelectLegend | QCP::iSelectPlottables);
    customPlot_main->legend->setSelectableParts(QCPLegend::spItems);
    customPlot_main->legend->setFont(legendFont);
    customPlot_main->legend->setSelectedFont(legendFont);
    customPlot_main->legend->setVisible(true);
    customPlot_main->graph()->setPen(QPen(QColor(0,255,10),2));
    //customPlot_main->graph(0)->setBrush(QBrush(QColor(0,255,10, 20)));
    customPlot_main->setBackground(QColor(20,20,20));
    customPlot_main->xAxis->setBasePen(QPen(QColor(150,150,150), 1));
    customPlot_main->yAxis->setBasePen(QPen(QColor(150,150,150), 1));
    customPlot_main->xAxis->setTickPen(QPen(QColor(255,255,255), 1));
    customPlot_main->yAxis->setTickPen(QPen(QColor(0,255,10), 1));
    customPlot_main->xAxis->setSubTickPen(QPen(QColor(255,255,255), 1));
    customPlot_main->yAxis->setSubTickPen(QPen(QColor(255,255,255), 1));
    customPlot_main->xAxis->setTickLabelColor(QColor(255,255,255));
    customPlot_main->yAxis->setTickLabelColor(QColor(0,255,10));
    customPlot_main->xAxis->setLabelColor(QColor(240,240,240));
    customPlot_main->yAxis->setLabelColor(QColor(240,240,240));
    customPlot_main->xAxis->setLabelFont(AxisFont);
    customPlot_main->yAxis->setLabelFont(AxisFont);
    customPlot_main->legend->setFont(legendFont);
    customPlot_main->legend->setSelectedFont(legendFont);
    customPlot_main->xAxis->grid()->setPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_main->yAxis->grid()->setPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_main->xAxis->grid()->setSubGridPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_main->yAxis->grid()->setSubGridPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_main->xAxis->grid()->setSubGridVisible(true);
    customPlot_main->yAxis->grid()->setSubGridVisible(true);
    customPlot_main->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot_main->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot_main->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot_main->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot_main->axisRect()->setupFullAxesBox();
    customPlot_main->rescaleAxes();
    // graph tab :
    QGridLayout *grid_mainGra = new QGridLayout;
    customPlot_graph = new QCustomPlot(ui->wdgPlot);
    ui->wdgPlot  ->setLayout(grid_mainGra);
    grid_mainGra ->setContentsMargins(0,0,0,0);
    grid_mainGra ->addWidget(customPlot_graph,0,0);
    customPlot_graph ->addGraph(0);
    customPlot_graph ->setGeometry(0,0,ui->wdgPlot->width(),ui->wdgPlot->height());
    customPlot_graph ->setContextMenuPolicy(Qt::CustomContextMenu);
    customPlot_graph ->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                QCP::iSelectLegend | QCP::iSelectPlottables);
    customPlot_graph->legend->setSelectableParts(QCPLegend::spItems);
    customPlot_graph->legend->setVisible(true);
    legendFont.setPointSize(11); // ??
    customPlot_graph->graph()->setPen(QPen(Qt::green,2));
    //customPlot_graph->graph(0)->setBrush(QBrush(QColor(0, 255, 10, 15)));
    customPlot_graph->setBackground(QColor(20,20,20));
    customPlot_graph->xAxis->setBasePen(QPen(Qt::gray, 1));
    customPlot_graph->yAxis->setBasePen(QPen(Qt::gray, 1));
    customPlot_graph->xAxis->setTickPen(QPen(Qt::gray, 1));
    customPlot_graph->yAxis->setTickPen(QPen(Qt::green, 1));
    customPlot_graph->xAxis->setSubTickPen(QPen(Qt::white, 1));
    customPlot_graph->yAxis->setSubTickPen(QPen(Qt::green, 1));
    customPlot_graph->xAxis->setTickLabelColor(Qt::white);
    customPlot_graph->yAxis->setTickLabelColor(Qt::green);
    customPlot_graph->xAxis -> setLabelColor(QColor(240,240,240));
    customPlot_graph->yAxis -> setLabelColor(QColor(240,240,240));
    customPlot_graph->xAxis->setLabelFont(AxisFont);
    customPlot_graph->yAxis->setLabelFont(AxisFont);
    customPlot_graph->legend->setFont(legendFont);
    customPlot_graph->legend->setSelectedFont(legendFont);
    customPlot_graph->xAxis->grid()->setPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_graph->yAxis->grid()->setPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_graph->xAxis->grid()->setSubGridPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_graph->yAxis->grid()->setSubGridPen(QPen(QColor(100,100,100), 1, Qt::DotLine));
    customPlot_graph->xAxis->grid()->setSubGridVisible(true);
    customPlot_graph->yAxis->grid()->setSubGridVisible(true);
    customPlot_graph->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot_graph->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot_graph->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot_graph->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot_graph->axisRect()->setupFullAxesBox();
    customPlot_graph->rescaleAxes();
    //  clickable plot area :       // open
 /*   connect(customPlot_main , SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    connect(customPlot_main , SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(customPlot_main , SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));
    connect(customPlot_main , SIGNAL(axisDoubleClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)));
    connect(customPlot_main , SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));
    connect(customPlot_main , SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));
    connect(customPlot_main , SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));
    connect(customPlot_graph, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    connect(customPlot_graph, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(customPlot_graph, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));
    connect(customPlot_graph, SIGNAL(axisDoubleClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)));
    connect(customPlot_graph, SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));
    connect(customPlot_graph, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));
    connect(customPlot_graph, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint))); */
    //
 /*   customPlot_main->xAxis  ->setLabel(ui->combo_axis1->currentText());
    customPlot_main->yAxis  ->setLabel(ui->combo_axis2->currentText());
    customPlot_graph->xAxis ->setLabel(ui->combo_axisX->currentText());
    customPlot_graph->yAxis ->setLabel(ui->combo_axisY->currentText());*/
    //
    QStringList channels;
    for (int i = 0; i < MaxChnCounts; ++i){
        channels.append(QString(tr("Channel %1").arg(i+1)));
    }
//    combo_diaMain -> addItems(channels);  // OPEN
//    combo_diaGraph-> addItems(channels);
}
