#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "softwarereview.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setting a custom width and height for the window
    int width = 400;
    int height = 300;
    setFixedSize(width, height);

    QWidget *centralWidget = new QWidget();
    setCentralWidget(centralWidget);

    // Window title and layout creat
    setWindowTitle("Software Review");
    titleLabel = new QLabel("Fill in the data and click Add");
    nameLabel = new QLabel("Name:");
    dateLabel = new QLabel("Date:");
    recommendLabel = new QLabel("Recommend:");
    nameEdit = new QLineEdit();
    dateEdit = new QLineEdit();
    recommendCheckbox = new QCheckBox(); // checkbox
    addButton = new QPushButton("Add"); // button
    displayButton = new QPushButton("Display");

    // Connect buttons to their respective slots
    connect(addButton, &QPushButton::clicked, this, &MainWindow::handleAddButtonClicked);
    connect(displayButton, &QPushButton::clicked, this, &MainWindow::handleDisplayButtonClicked);

    // The layouts start here
    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->addWidget(titleLabel);
    titleLayout->setAlignment(Qt::AlignCenter);

    QVBoxLayout *infoLayout = new QVBoxLayout();
    infoLayout->addWidget(nameLabel);
    infoLayout->addWidget(nameEdit);
    infoLayout->addWidget(dateLabel);
    infoLayout->addWidget(dateEdit);
    infoLayout->addWidget(recommendLabel);
    infoLayout->addWidget(recommendCheckbox);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(displayButton);

    // This is the main layout. We have 3 sections and we add all of them to this on QVBoxLayout layout to make everything neat
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(infoLayout);
    mainLayout->addLayout(buttonLayout);

    // setLayout(mainLayout);
    centralWidget->setLayout(mainLayout);
}

// functionality for when the Add button is clicked:
void MainWindow::handleAddButtonClicked() {
    // Get data from UI elements and create a SoftwareReview object
    QString name = nameEdit->text();
    QString date = dateEdit->text();
    bool recommended = recommendCheckbox->isChecked();

    SoftwareReview review(name, date, recommended);
    reviews_.append(review);

    // Clear input fields for new entries (optional)
    nameEdit->clear();
    dateEdit->clear();
    recommendCheckbox->setChecked(false);
}

// functionality for when the dispay button is clicked:
void MainWindow::handleDisplayButtonClicked() {

    // Here we make use of iterators to loop through the QList array and display the reviews:
    for (const SoftwareReview &review : reviews_) {

        QString isRecommended ="";
        if(review.isRecommended() == true){
            isRecommended = "Yes";
        }else{
            isRecommended = "No";
        }
        QString nameText = "Name: " + review.getName();
        QString dateText = "Date: " + review.getDate();
        QString recommendedText = "Recommended?: " + isRecommended;

        qDebug() << "-------Software Review---------";
        qDebug() << nameText;
        qDebug() << dateText;
        qDebug() << recommendedText;
        qDebug() << "-------------------------------";

    }
}

// destructor:
MainWindow::~MainWindow()
{
    delete ui;
}



