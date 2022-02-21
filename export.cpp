#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"
#include <QTextStream>
#include <QtSql>

void DLCalMenu::export_file()       // TODO : filtera göre slot emit :: BURDA KALDI
{
    QString fileName;
    QFile file;

    if(ui->radioBtn_csv->isChecked()){
       fileName = QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(), "CSV (*.csv)");
       file.setFileName(fileName);
       if(ui->combo_rawreal->currentIndex() == 0){     // REAL displays
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
               qDebug()<<"Real file exported as .csv";
               }
           }
       if(ui->combo_rawreal->currentIndex() == 1){     // RAW displays
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
               qDebug()<<"Raw file exported as .csv";
           }
       }
       file.close();
    }
    if(ui->radioBtn_pdf->isChecked()){
        QPrinter printer(QPrinter::HighResolution);
        printer.setOrientation(QPrinter::Portrait);
        printer.setPageSize(QPrinter::A4);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(QDir::currentPath() + "/example.pdf");
        QPrintDialog dlg(&printer, 0);
        if(dlg.exec() == QDialog::Accepted) {
            QSqlQuery query;
            query.exec("SELECT * from person");
            table_printPDF(&printer, query);
        }
    }
    if(ui->radioBtn_txt->isChecked()){
        fileName = QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(), "TEXT (*.txt)");
        file.setFileName(fileName);
        if(ui->combo_rawreal->currentIndex() == 0){     // REAL displays
           file.open(QIODevice::WriteOnly);
           QTextStream lines(&file);
           lines.setCodec("UTF-8");
           lines << QString("TEST RESULTS \n");
        //            lines << QString("Line_1 :") << ui->lineEdit_1->text() << "\n";
           qDebug()<<"Real file exported as .txt";
        }
        if(ui->combo_rawreal->currentIndex() == 1){     // RAW displays
           file.open(QIODevice::WriteOnly);
           QTextStream lines(&file);
           lines.setCodec("UTF-8");
           lines << QString("TEST RESULTS \n");
           qDebug()<<"Raw file exported as .txt";
        }
       file.close();
    }
}
bool DLCalMenu::sql_connection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"), "Click Cancel to exit.", QMessageBox::Cancel);
        qDebug()<<"açılmadı database :(";
        return false;
    }
    QSqlQuery query;
//    qDebug() << "table:" <<   query.exec("create table person (id int primary key, "
//                                       "firstname varchar(20), lastname varchar(20), num int )");
//    query.exec("insert into person values(101, 'Dennis', 'Young','1')");
//    ..
    return true;
    qDebug()<<"sql_connection";
}
void DLCalMenu::table_printPDF (QPrinter* printer, QSqlQuery&  Query)
{
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setPageSize(QPageSize(QPageSize::A4));
    QPainter painter;
    painter.begin(printer);
    int y = 300;
    int x = y;
    if(ui->combo_rawreal->currentIndex() == 0){     // REAL displays
        painter.drawText( x, y, "REAL DATA VALUES");
        painter.drawText( x, 2*y, "Line 1 :     " );
        painter.drawText( x, 3*y, "Line 2 :     " );

        painter.end();
        qDebug()<<"Real file exported as .pdf";
    }
    if(ui->combo_rawreal->currentIndex() == 1){     // RAW displays
        painter.drawText( x, y, "RAW DATA VALUES");

        qDebug()<<"Raw file exported as .pdf";
    }

////  Just write to PDF
//    QString strStream;
//    QTextStream out(&strStream);

//    const int rowCount = Query.size();
//    const int columnCount = MaxChnCounts+2;//Query.record().count();     // TODO FIX

//    if(ui->combo_rawreal->currentIndex() == 0){     // REAL displays
//        out <<  "<html>\n"
//          "<head>\n"
//          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
//          <<  QString("<title>%1</title>\n").arg("REAL-TIME SONUÇLAR")
//          <<  "</head>\n"
//          "<body bgcolor=#ffffff link=#5000A0>\n"
//          "<table border=1 cellspacing=0 cellpadding=2>\n";

//        // headers
//        out << "<thead><tr bgcolor=#f0f0f0>";
//        for (int column = 0; column < columnCount; column++)
//        out << QString("<th>%1</th>").arg("abcd");     // TODO FIX
//        out << "</tr></thead>\n";

//        while (Query.next()) {
//        out << "<tr>";
//        for (int column = 0; column < columnCount; column++) {
//          QString data = Query.value(column).toString();
//          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
//        }
//        out << "</tr>\n";
//        }

//        out <<  "</table>\n"
//          "</body>\n"
//          "</html>\n";

//        qDebug()<<"Real file exported as .pdf";
//    }
//    if(ui->combo_rawreal->currentIndex() == 1){     // RAW displays
//        qDebug()<<"Raw file exported as .pdf";
//    }
//    QTextDocument document;
//    document.setHtml(strStream);
//    document.print(printer);

////  QTableView to PDF
//    QTextDocument *doc = new QTextDocument;
//    doc->setDocumentMargin(10);
//    QTextCursor cursor(doc);

//    cursor.movePosition(QTextCursor::Start);

//    QTextTable *table = cursor.insertTable(properties.size() + 1, 2, tableFormat);
//    QTextTableCell headerCell = table->cellAt(0, 0);
//    QTextCursor headerCellCursor = headerCell.firstCursorPosition();
//    headerCellCursor.insertText(QObject::tr("Name"), boldFormat);
//    headerCell = table->cellAt(0, 1);
//    headerCellCursor = headerCell.firstCursorPosition();
//    headerCellCursor.insertText(QObject::tr("Value"), boldFormat);

//    for(int i = 0; i < properties.size(); i++){
//       QTextCharFormat cellFormat = i % 2 == 0 ? textFormat : alternateCellFormat;
//       QTextTableCell cell = table->cellAt(i + 1, 0);
//       cell.setFormat(cellFormat);
//       QTextCursor cellCursor = cell.firstCursorPosition();
//       cellCursor.insertText(properties.at(i)->name());

//       cell = table->cellAt(i + 1, 1);
//       cell.setFormat(cellFormat);
//       cellCursor = cell.firstCursorPosition();
//       cellCursor.insertText(properties.at(i)->value().toString() + " " + properties.at(i)->unit());
//    }

//    cursor.movePosition(QTextCursor::End);
//    cursor.insertBlock();
//    printer(QPrinter::HighResolution);
//    printer->setOutputFormat(QPrinter::PdfFormat);
//    printer->setOutputFileName(filename);
//    doc->print(printer);

    //    // QTableWidget to PDF
//    QString strFile = QDir::currentPath()+ "/pdf_deneme.pdf";
//    printer->setResolution(QPrinter::HighResolution);
//    printer->setOutputFormat(QPrinter::PdfFormat);
//    printer->setPaperSize(QPrinter::A4);
//    printer->setOrientation(QPrinter::Landscape);
//    printer->setOutputFileName(strFile);

//    QTextDocument doc;

//    QString text("<table><thead>");
//    text.append("<tr>");
//    for (int i = 0; i < csvModel_real->columnCount(); i++) {
//        text.append("<th>").append(csvModel_real->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
//    }
//    text.append("</tr></thead>");
//    text.append("<tbody>");
//    for (int i = 0; i < csvModel_real->rowCount(); i++) {
//        text.append("<tr>");
//        for (int j = 0; j < csvModel_real->columnCount(); j++) {
//            QTableWidget *a;
//            QTableWidgetItem *item = a->item(i, j);
//            if (!item || item->text().isEmpty()) {
//                csvModel_real->setItem(i, j, new QTableWidgetItem("0"));
//            }
//            text.append("<td>").append(csvModel_real->item(i, j)->text()).append("</td>");
//        }
//        text.append("</tr>");
//    }
//    text.append("</tbody></table>");
//    doc.setHtml(text);
//    doc.setPageSize(printer->pageRect().size());
//    doc.print(printer);
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
