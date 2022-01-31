#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"
#include <QTextStream>
#include <QtSql/QSqlTableModel>

void DLCalMenu::exportCsv()
{
    QString filters("CSV files (*.csv);; Text files (*.txt);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                       filters, &defaultFilter);
    QFile file(fileName);

    if(ui->combo_rawreal->currentIndex() == 0){
        QAbstractItemModel *model = tview_real->model();
        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream data(&file);
            QStringList strList;
            for (int i = 0; i < model->columnCount(); i++) {
                if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") << "\n";
            for (int i = 0; i < model->rowCount(); i++) {
                strList.clear();
                for (int j = 0; j < model->columnCount(); j++) {

                    if (model->data(model->index(i, j)).toString().length() > 0)
                        strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") + "\n";
            }
            file.close();
            qDebug()<<"Real file exported as .csv";
        }
    }
    if(ui->combo_rawreal->currentIndex() == 1){
        QAbstractItemModel *model = tview_raw->model();
        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream data(&file);
            QStringList strList;
            for (int i = 0; i < model->columnCount(); i++) {
                if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") << "\n";
            for (int i = 0; i < model->rowCount(); i++) {
                strList.clear();
                for (int j = 0; j < model->columnCount(); j++) {

                    if (model->data(model->index(i, j)).toString().length() > 0)
                        strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") + "\n";
            }
            file.close();
            qDebug()<<"Raw file exported as .csv";
        }
    }
}
void DLCalMenu::setup_tableView()
{
    tview_real  = new QTableView;
    tview_raw   = new QTableView;
    tview_file  = new QTableView;                 //Added External Read
    csvModel_real = new QStandardItemModel;
    csvModel_raw  = new QStandardItemModel;
    csvModel_realnew = new QStandardItemModel;    //Added External Read
    tview_file  -> setParent(ui->pg2);
    tview_real  -> setParent(ui->pg2);
    tview_raw   -> setParent(ui->pg2);
    grid_wdgGraph -> addWidget(tview_real,0,0);
    grid_wdgGraph -> addWidget(tview_raw,0,0);
    grid_wdgGraph -> addWidget(tview_file,0,0);
    grid_wdgGraph -> setContentsMargins(0,0,0,0);
    tview_file  -> setGeometry(0,0,ui->wdgGraph->width(),ui->wdgGraph->height());
    tview_raw   -> setGeometry(0,0,ui->wdgGraph->width(),ui->wdgGraph->height());
    tview_real  -> setGeometry(0,0,ui->wdgGraph->width(),ui->wdgGraph->height());
    tview_file  -> resize(ui->wdgGraph->width(),ui->wdgGraph->height());
    tview_raw   -> resize(ui->wdgGraph->width(),ui->wdgGraph->height());
    tview_real  -> resize(ui->wdgGraph->width(),ui->wdgGraph->height());

}
void DLCalMenu::table_writeData()   // Read External : moved to tableWrite
{
    QList<QStandardItem *> standardItemsReal;
    QList<QStandardItem *> standardItemsRaw;
    QStandardItem *itemStd;//[row][col];
    QStandardItem *timeStd;//[row][col];
    QStandardItem *dateStd;//[row][col];
    QStringList timeList;
    QStringList dateList;
    QStringList horizontalHeader;
    QString     itemstr;
    QString     datestr;
    QString     timestr;
    QDateTime   date;
    QTime       time;
    int         itemint;
    int col = 0 ;
    if(ui->m_SetSerialPortButton){
        timeList. append(QString("Time"));
        dateList. append(QString("Date"));
        date    . setDate(QDate::currentDate());
        time    = QTime::currentTime();
        datestr = date.toString("/dd/MM/yyyy/");
        timestr = time.toString(":hh:mm:ss:");
        dateStd = new QStandardItem(datestr);
        timeStd = new QStandardItem(timestr);
        rec_time = ui->combo_recPeriod->currentText().toInt();
        rec_time = rec_time/50;
        ctr++;

        standardItemsReal.append(new QStandardItem(datestr));
        standardItemsReal.append(new QStandardItem(timestr));
        standardItemsRaw .append(new QStandardItem(datestr));
        standardItemsRaw .append(new QStandardItem(timestr));
        if(ctr%rec_time==0){
           for (col = 0; col < MaxChnCounts; ++col){
                csvModel_raw    -> setColumnCount(MaxChnCounts+2);
                csvModel_real   -> setColumnCount(MaxChnCounts+2);
                if(ui->combo_rawreal-> currentIndex() == 0){
                    horizontalHeader.  append(QString("Channel[%1]\nReal").arg(col+1));
                    itemstr = ChnRealDataQString[col];
                }
                else if(ui->combo_rawreal->currentIndex() == 1){
                    horizontalHeader.  append(QString("Channel[%1]\nRaw").arg(col+1));
                    itemstr = ChnRawDataQString[col];
                }
                standardItemsReal.insert(MaxChnCounts,new QStandardItem(itemstr));
                standardItemsRaw .insert(MaxChnCounts,new QStandardItem(itemstr));
            }
            tview_real  -> setEditTriggers(QAbstractItemView::NoEditTriggers);
            tview_raw   -> setEditTriggers(QAbstractItemView::NoEditTriggers);
            csvModel_real     -> setHorizontalHeaderLabels(dateList + timeList + horizontalHeader);
            csvModel_raw      -> setHorizontalHeaderLabels(dateList + timeList + horizontalHeader);
            if(ui->combo_rawreal  -> currentIndex() == 0)
                csvModel_real -> appendRow(standardItemsReal);
            if(ui->combo_rawreal -> currentIndex() == 1 )
                csvModel_raw  -> appendRow(standardItemsRaw);
            ctr=0;
        }
        tview_real    -> setModel(csvModel_real);
        csvModel_real -> setParent(tview_real);
        tview_raw     -> setModel(csvModel_raw);
        csvModel_raw  -> setParent(tview_raw);
    }
}
void DLCalMenu::table_readData()       // External table
{
    QStringList timeList;
    QStringList dateList;
    QStringList horizontalHeader;
    int itemint;
    int check=3, value1=0;
    linecnt=0;
    QString data;
    int data_1;
    int polarity=1;

    if (!externalFile->open(QIODevice::ReadOnly) ) {
        qDebug() << "File not exists";
    }
    else{
        qDebug() << "File exists";
        QTextStream out(externalFile);
        while (!out.atEnd()) {
//            QStandardItemModel* model = qobject_cast<QStandardItemModel*>(tview_file->model());
//            QString line = out.readLine();
//            QStringList lineToken = line.split(";", QString::SkipEmptyParts);
//            for (int j = 0; j < lineToken.size(); j++) {
//                       QString value = lineToken.at(j);
//                       QStandardItem* item = new QStandardItem(value);
//                       model->setItem(linecnt, j, item);
//             }
//             linecnt++;
//          }
            linecnt++;
            QString line = out.readLine();
            //qDebug()<<line;
            if(linecnt>MaxChnCounts+1) {
                for(QString item: line.split(";")){
                    value1++;
                    if(value1==1){
                        dateItems = item.split('/');
                        //DateList[0].append(dateItems[0].toInt());
                        DateList[1].append(dateItems[1].toInt());
                        DateList[2].append(dateItems[2].toInt());
                        DateList[3].append(dateItems[3].toInt());
                    }
                    if(value1==2) {
                        timeItems = item.split(":");
                        //HourList[0].append(timeItems[0].toInt());
                        HourList[1].append(timeItems[1].toInt());
                        HourList[2].append(timeItems[2].toInt());
                        HourList[3].append(timeItems[3].toInt());
                    }
                    if(value1>2){
                       for(int index=0; index<item.size(); index++){
                           if(item.at(index)=='-'){
                               polarity=-1;
                         }
                           if(item.at(index)>=48 && item.at(index)<=57){
                               data+=item.at(index);
                           }
                       }
                       if(value1==check){
                           data_1=data.toInt();
                           ItemsList[check-3].append(data_1*polarity);check++;polarity=1;
                       }
                           data="";
                       if(value1==18){
                           value1=0;check=3;
                       }
                   }
                }
            }
        //qDebug()<<linecnt;
        externalFile->close();
        }
    }
    tview_file   -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    horizontalHeader.append("Date");
    horizontalHeader.append("Time");
    ItemsFile.append(new QStandardItem(QString::number(DateList[1].at(0))+"/"+QString::number(DateList[2].at(0))+"/"+QString::number(DateList[3].at(0))));
    ItemsFile.append(new QStandardItem(QString::number(HourList[1].at(0))+":"+QString::number(HourList[2].at(0))+":"+QString::number(HourList[3].at(0))));
    for (int a = 0; a < MaxChnCounts; a++) {
        horizontalHeader. append(QString("Channel[%1]\nReal").arg(a+1));
    }
    csvModel_realnew    -> setHorizontalHeaderLabels(dateList + timeList + horizontalHeader);
    for(int row=0; row<ItemsList[0].size(); row++) {
        for(int col=0; col<MaxChnCounts; col++) {
            itemint=ItemsList[col].at(row);
            ItemsFile.append(new QStandardItem(QString::number(itemint)));
        }
        csvModel_realnew -> appendRow(ItemsFile);
        ItemsFile.clear();
        if(row<ItemsList[0].size()-1) {
            ItemsFile.append(new QStandardItem(QString::number(DateList[1].at(row+1))+"/"+QString::number(DateList[2].at(row+1))+"/"+QString::number(DateList[3].at(row+1))));
            ItemsFile.append(new QStandardItem(QString::number(HourList[1].at(row+1))+":"+QString::number(HourList[2].at(row+1))+":"+QString::number(HourList[3].at(row+1))));
        }
     }
     tview_file->setModel(csvModel_realnew);
     csvModel_realnew -> setParent(tview_file);
     tview_real->hide();
     tview_raw->hide();
}
