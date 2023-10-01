#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Adaugă declarația prealabilă pentru QListWidgetItem
class QListWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnAdd_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_btnDelete_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_listWidget_2_currentRowChanged(int currentRow);

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_listWidget_itemChanged(QListWidgetItem *item);

    void on_listWidget_2_itemChanged(QListWidgetItem *item);


    void on_btnClearActivities_clicked();

    void on_btnClearPinned_clicked();

    void on_btnClearDone_clicked();

    void on_checkBox_clicked();

    void on_checkBox_stateChanged(int state);

private:
    Ui::MainWindow *ui;
    int mnSelectedActivity = -1;
    int mnSelectedPinned = -1;
    int nextNumber = 1;
    QStringList itemList;

};
#endif // MAINWINDOW_H
