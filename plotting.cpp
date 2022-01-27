#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"
#include "qcustomplot.h"
#include <QFont>

void DLCalMenu::setup_customPlot()
{
    QFont legendFont = font();
    QFont AxisFont("Newyork");
    AxisFont.setStyleHint(QFont::SansSerif);
    AxisFont.setPointSize(Fontsize);
    legendFont.setPointSize(Fontsize);
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
//  clickable plot area :       // open
    connect(customPlot_main , SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    connect(customPlot_main , SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(customPlot_main , SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));
    connect(customPlot_main , SIGNAL(axisDoubleClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)));
    connect(customPlot_main , SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));
    connect(customPlot_main , SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));
    connect(customPlot_main , SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));
    //
    customPlot_main->xAxis  ->setLabel(ui->combo_axis1->currentText());
    customPlot_main->yAxis  ->setLabel(ui->combo_axis2->currentText());
    //
    QStringList channels;
    for (int i = 0; i < MaxChnCounts; ++i){
        channels.append(QString(tr("Channel %1").arg(i+1)));
    }
    grid_dialogAddMain  = new QGridLayout;
    dialog_addToMain    = new QDialog;
    wdg_dialogAddMain   = new QWidget;
    combo_diaMain       = new QComboBox;
    btn_diaOKMain       = new QPushButton("Apply");
    btn_diaCancelMain   = new QPushButton("Cancel");
    lbl_diaAxisMain     = new QLabel("Axis Y : ");
    combo_diaMain       -> addItems(channels);
}

void DLCalMenu::plot_graphMain()
{
    static QTime graph_time(QTime::currentTime());
    double key = graph_time.elapsed()/1000.0;
    timer_main->setInterval(100);

    //timeTicker->setTimeFormat("%h:%m:%s");
    for (index_x = 0; index_x < MaxChnCounts; ++index_x) {
        index_x = ui->combo_axis1->currentIndex();
        if(index_x < MaxChnCounts){
            displayData_X = realData[index_x] + realData_neg[index_x];
        }
        else {
            displayData_X = key;  // disp time val
        }
        break;
    }
    for (index_y = 0; index_y < MaxChnCounts; ++index_y) {
        index_y = ui->combo_axis2->currentIndex();
        if(index_y < MaxChnCounts)
            displayData_Y = realData[index_y] + realData_neg[index_y];
            break;
    }
    if(ad_main>=1){
        for(int index=0; index<ad_main; index++){
            newDataY[index]=realData[new_index_Y[index]] + realData_neg[new_index_Y[index]];
            if(plot_statu != -1){
                customPlot_main -> graph(index+1) -> addData(displayData_X, newDataY[index]);
                customPlot_main -> graph(index+1) -> rescaleValueAxis(true, true);
            }
            /*else if(plot_statu = -1) {
                customPlot_main -> graph(del-1) -> addData(displayData_X, newDataY[index]);
               // customPlot_main -> graph() -> rescaleValueAxis(true, true);
            }*/
            if(newDataY[index]<axisYLower && customPlot_main -> graph(index+1) -> visible()){
                axisYLower=newDataY[index];
            }
            if(newDataY[index]>axisYUpper && customPlot_main -> graph(index+1) -> visible()){
                axisYUpper=newDataY[index];
            }
            /* if(del != del_ctr) {
                qDebug() <<"del"<<del<<" != delctr"<<del_ctr;
                customPlot_main->selectedGraphs();
             }
             if(del == del_ctr)
                qDebug() <<"del"<<del<<" == delctr"<<del_ctr;
             //qDebug() <<"ad_main"<<ad_main<<" ?= del-1 "<<del-1;*/
        }
    }
    else {
        axisYLower=displayData_Y;
        axisYUpper=displayData_Y;
    }

    customPlot_main -> graph(0) -> addData(displayData_X      , displayData_Y);
    customPlot_main -> xAxis    -> setRange(displayData_X-10  , displayData_X+10);
    customPlot_main -> yAxis    -> setRange(axisYLower-10     , axisYUpper+10);
//    customPlot_main -> graph() -> setName(customPlot_main->xAxis->label()+" - "+customPlot_main->yAxis->label());
    customPlot_main -> graph(0) -> setName(ui->combo_axis1->currentText()+" - "+ui->combo_axis2->currentText());
    customPlot_main -> graph(0) -> rescaleValueAxis(true,true);
    customPlot_main -> replot();
}
void DLCalMenu::addGraphDialog_Main()
{
    grid_dialogAddMain = new QGridLayout;
    lbl_diaAxisMain   -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    combo_diaMain     -> setStyleSheet("color: red");
    grid_dialogAddMain-> addWidget(lbl_diaAxisMain,0,0);
    grid_dialogAddMain-> addWidget(combo_diaMain,0,1);  //main
    grid_dialogAddMain-> addWidget(btn_diaCancelMain,1,0);
    grid_dialogAddMain-> addWidget(btn_diaOKMain,1,1);
    wdg_dialogAddMain -> setParent(dialog_addToMain);
    wdg_dialogAddMain -> setGeometry(10,10,300,75);
    dialog_addToMain  -> setLayout(grid_dialogAddMain);
    dialog_addToMain  -> setWindowTitle("Add Graph");
    dialog_addToMain  -> resize(DialogW,DialogH);
    dialog_addToMain  -> exec();
}
void DLCalMenu::addNewGraph()
{
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(rand()/(double)RAND_MAX*2+1);

    ad_main++;
    plot_statu = 1;
    timer_main      -> start();
    customPlot_main -> addGraph();
    customPlot_main -> graph() -> setPen(graphPen);
    customPlot_main -> graph() -> setName(customPlot_main->xAxis->label()+" - "+customPlot_main->yAxis->label());
    new_index_Y[ad_main-1] = combo_diaMain->currentIndex();     //gets graph channel index
    ui->btn_plotGraph   -> setDisabled(true);
    ui->btn_plotGraph   -> hide();
}
void DLCalMenu::removePlot()
{
    //if(!plot_statu == 1){
    if (customPlot_main->selectedGraphs().size() > 0){
        for(del_ctr = 0; del_ctr < customPlot_main -> graphCount(); del_ctr++){
           del = del_ctr;
        }
        customPlot_main->removeGraph(customPlot_main->selectedGraphs().first());
//            customPlot_main -> removeGraph(del);
//            customPlot_main -> legend -> removeItem(del);
        plot_statu = -1;
    }
    ad_main = del-1;
    customPlot_main -> replot();
}
void DLCalMenu::removeAllPlot()
{
    //if(!plot_statu == 1){
    for (int i=customPlot_main->graphCount() ; i > 1 ; i--){
        customPlot_main->removeGraph(customPlot_main->graph(i-1));
        customPlot_main -> graph(0) -> setName(ui->combo_axis1->currentText()+" - "+ui->combo_axis2->currentText());
        del_ctr=0;
    }
    ad_main=0;
    del = 0;
}
void DLCalMenu::hideGraphPlot()
{
    int foundIndex=0;
    if (customPlot_main->selectedGraphs().size() > 0){
        for(int j=0; j<customPlot_main->graphCount(); j++){
            if(customPlot_main->graph(j)->name()==customPlot_main->selectedGraphs().first()->name()){
                foundIndex=j;
               // break;
            }
        }
        customPlot_main->graph(foundIndex)->setVisible(false);
        customPlot_main->selectedGraphs().constFirst()->removeFromLegend();
     // customPlot_main->removeGraph(customPlot_graph->selectedGraphs().first());
      customPlot_main->replot();
    }
}
void DLCalMenu::showGraphPlot()
{
    int foundIndex=0;
    if (customPlot_main->selectedGraphs().size() > 0) {
        for(int j=0; j<customPlot_main->graphCount(); j++){
            if(customPlot_main->graph(j)->name() == customPlot_main->selectedGraphs().first()->name()){
                foundIndex=j;
               // break;
            }
        }
      customPlot_main->graph(foundIndex)->setVisible(true);
      customPlot_main->replot();
    }
}
void DLCalMenu::selectionChanged()
{
    if (customPlot_main ->xAxis ->selectedParts().testFlag(QCPAxis::spAxis)  || customPlot_main ->xAxis ->selectedParts().testFlag(QCPAxis::spTickLabels))
        customPlot_main ->xAxis ->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    if (customPlot_main ->yAxis->selectedParts().testFlag(QCPAxis::spAxis)  || customPlot_main  ->yAxis ->selectedParts().testFlag(QCPAxis::spTickLabels))
        customPlot_main ->yAxis ->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);

    for (int i=0; i<customPlot_main->graphCount(); ++i){
        QCPGraph *graph = customPlot_main->graph(i);
        QCPPlottableLegendItem *item = customPlot_main->legend->itemWithPlottable(graph);
            if (item->selected() || graph->selected()){
                item->setSelected(true);
                graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
            }
    }
}
void DLCalMenu::mousePress()
{
    if      (customPlot_main->xAxis->selectedParts().testFlag(QCPAxis::spAxis)) customPlot_main->axisRect()->setRangeDrag(customPlot_main->xAxis->orientation());
    else if (customPlot_main->yAxis->selectedParts().testFlag(QCPAxis::spAxis)) customPlot_main->axisRect()->setRangeDrag(customPlot_main->yAxis->orientation());
    else     customPlot_main->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}
void DLCalMenu::mouseWheel()
{
    if      (customPlot_main->xAxis->selectedParts().testFlag(QCPAxis::spAxis)) customPlot_main->axisRect()->setRangeZoom(customPlot_main->xAxis->orientation());
    else if (customPlot_main->yAxis->selectedParts().testFlag(QCPAxis::spAxis)) customPlot_main->axisRect()->setRangeZoom(customPlot_main->yAxis->orientation());
    else     customPlot_main->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}
void DLCalMenu::contextMenuRequest(QPoint pos)
{
    QMenu *menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);

    if (customPlot_main->legend->selectTest(pos, false) >= 0 ){
        menu->addAction("Move to top left"      , this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop      |Qt::AlignLeft));
        menu->addAction("Move to top right"     , this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop      |Qt::AlignRight));
        menu->addAction("Move to bottom right"  , this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom   |Qt::AlignRight));
        menu->addAction("Move to bottom left"   , this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom   |Qt::AlignLeft));
        hidelegend = menu->addAction("Hide"     , this, SLOT(hideLegend()));
    }
    else {
        if(current_page == SCR_MAIN){
            if (customPlot_main -> selectedGraphs().size() > 0){//&& plot_statu == 0)
                menu -> addAction("Add graph"       , this, SLOT(addGraphDialog_Main()));
                if(customPlot_main->graphCount() > 1){
                    menu -> addAction("Clear all"   , this, SLOT(removeAllPlot()));
                    //menu -> addAction("Remove graph", this, SLOT(removePlot()));
                }
            }
        }
        if(!customPlot_main -> legend -> visible())
            showlegend = menu -> addAction("Show legend" , this, SLOT(showLegend()));
//        if (customPlot_main -> selectedGraphs().size() > 0)
//            menu -> addAction("Hide graph"  , this, SLOT(hideGraphPlot()));
//        if(customPlot_main -> selectedGraphs().size() > 0  && !customPlot_main  -> selectedGraphs().first() -> visible())
//            menu -> addAction("Show graph"  , this, SLOT(showGraphPlot()));
    }
    menu->popup(customPlot_main -> mapToGlobal(pos));
 }
void DLCalMenu::moveLegend()
{
    if (QAction* contextAction = qobject_cast<QAction*>(sender())){
        bool ok;
        int dataInt = contextAction->data().toInt(&ok);
        if (ok){
            customPlot_main ->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
            customPlot_main ->replot();
        }
    }
}
void DLCalMenu::hideLegend()
{
    customPlot_main ->legend->setVisible(false);
}
void DLCalMenu::showLegend()
{
    customPlot_main ->legend->setVisible(true);
}
void DLCalMenu::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
    // grafikte tiklanan noktanın degerini gormek icin bir alternatif

    double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
    QString message = QString("  Seçilen grafik: '%1' | Veri: #%2 | Değer: %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);
    //  some_label->setText(message);
}
void DLCalMenu::axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part)
{
    if (part == QCPAxis::spAxisLabel){
        bool ok;
        QString newLabel = QInputDialog::getText(this, "EKSEN", "Yeni eksen adı :", QLineEdit::Normal, axis->label(), &ok);
        if (ok){
            axis->setLabel(newLabel);
            customPlot_main->replot();
        }
    }
}
void DLCalMenu::legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item)
{
    Q_UNUSED(legend)
    bool ok = false;

    if (item) plItem = qobject_cast<QCPPlottableLegendItem*> (item);
        QString newName = QInputDialog::getText(this, "GRAFİK", "Yeni grafik adı :", QLineEdit::Normal, plItem->plottable()->name(), &ok);
    if (ok){
        plItem->plottable()->setName(newName);
        customPlot_main->replot();
    }
}
