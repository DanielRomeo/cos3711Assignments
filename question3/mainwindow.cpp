#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydelegate = new Delegate(this);

    // instatiate the model:
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Composer", "Album title", "Replacement Cost", "Rating"}); // Set column headers

    // set model and delegate in UI:
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(mydelegate);

    // create QList that will serve as rows:
    QList<QStandardItem*> row1;

    // a list of composer, album title ... etc
    row1.append(new QStandardItem(QString("Dr Dre"))); // producer
    row1.append(new QStandardItem(QString("The chronic"))); // album title ...
    row1.append(new QStandardItem(QString("NewItem")));
    row1.append(new QStandardItem(QString("NewItem")));

    // add the row into the model:
    model->appendRow(row1);

    // we use a for loop to add the data...
    // Since the model takes in QList's , QLists of the type<QStandardItem>, we have to do exactly that
    // for (int i = 0; i < 5; ++i) {
    //     QList<QStandardItem*> row;
    //     for (int j = 0; j < 3; ++j) {
    //         row.append(new QStandardItem(QString("Item %1-%2").arg(i + 1).arg(j + 1)));
    //     }
    //     model->appendRow(row);
    // }
    // create a list... create columns:
    // QList list = new QList<>;
    // model->appendColumn()
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Add button:
void MainWindow::on_pushButton_clicked()
{
    // we collect all the data from the LineEdits:
    QString composer = ui->lineEdit->text();
    QString albumTitle = ui->lineEdit_2->text();
    int replacementCost = ui->spinBox->value();
    int rating = ui->spinBox_2->value();

    qDebug() << replacementCost;

    // create a list and add the rows:
    // Note that we need to convert the numbers to string, to display them:
    QList<QStandardItem*> row;
    row.append(new QStandardItem(composer));
    row.append(new QStandardItem(albumTitle));
    row.append(new QStandardItem(QString::number(replacementCost)));
    row.append(new QStandardItem(QString::number(rating)));

    model->appendRow(row);

    qDebug() << row ;

}

// When the delete button is clicked:
void MainWindow::on_pushButton_2_clicked()
{
    model->removeRows( ui->tableView->currentIndex().row(), 1); // delete one
}

