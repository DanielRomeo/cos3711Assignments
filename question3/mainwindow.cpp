#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // instatiate the model:
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Composer", "Album title", "Replacement Cost", "Rating"}); // Set column headers

    ui->tableView->setModel(model);

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
