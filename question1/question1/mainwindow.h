#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QMainWindow>

#include "softwarereview.h" // Include the SoftwareReview class header

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// the slots for the events to emit data when the button sare clicked:
private slots:
    void handleAddButtonClicked(); // Function for handling Add button click (not implemented)
    void handleDisplayButtonClicked(); // Function for handling Display button click (not implemented)

private:
    Ui::MainWindow *ui;
    QLabel *titleLabel;
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLabel *recommendLabel;
    QLineEdit *nameEdit;
    QLineEdit *dateEdit;
    QCheckBox *recommendCheckbox;
    QPushButton *addButton;
    QPushButton *displayButton;

    // this will be our array that stores the reviews:
    QList<SoftwareReview> reviews_;
};
#endif // MAINWINDOW_H
