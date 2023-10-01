#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <QHBoxLayout>
#include <QListWidgetItem>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        // Conectați semnalul itemChanged la slot-ul onItemChanged
    connect(ui->listWidget, &QListWidget::itemChanged, this, &MainWindow::on_listWidget_itemChanged);
    connect(ui->listWidget, &QListWidget::itemChanged, this, &MainWindow::on_listWidget_2_itemChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
    /*
public slots:
    void onItemChanged(QListWidgetItem *item);
*/

}

/*
void MainWindow::on_btnAdd_clicked()
{
/*
    QString str =  ui->tdActivity->toPlainText();
    if(str.isEmpty())
        return;
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget); // Creați un element fără text
    QCheckBox *checkBox = new QCheckBox; // Creați un QCheckBox
    item->setText(str);
    ui->listWidget->setItemWidget(item, checkBox); // Adăugați QCheckBox la element

    QStringList itemLabels= getLabels();

    QStringListIterator it(itemLabels);
    while (it.hasNext())
    {
        QListWidgetItem *listItem = new QListWidgetItem(it.next(),listWidget);
        listItem->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(listItem);
    }
}
*/
void MainWindow::on_btnAdd_clicked()
{
    QString str =  ui->tdActivity->toPlainText();

    if(str.isEmpty())
        return;

    QString numberedText= QString("%1. %2").arg(nextNumber).arg(str);
    QListWidgetItem *item = new QListWidgetItem(numberedText, ui->listWidget);
    item->setCheckState(Qt::Unchecked);

    nextNumber++;

    QListWidgetItem *emptyItem = new QListWidgetItem("",ui->listWidget);
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    mnSelectedActivity = currentRow;
}

void MainWindow::on_btnDelete_clicked()
{
    if(mnSelectedActivity != -1)
    {
       QListWidgetItem *it = ui->listWidget->takeItem(mnSelectedActivity);
       delete it;

       ui->listWidget->setCurrentRow(-1);
    }
}


void MainWindow::on_buttonBox_accepted()
{
    if(mnSelectedActivity!=-1)
    {
   //QString str =  ui->tdActivity->toPlainText();
    QListWidgetItem *it = ui->listWidget->takeItem(mnSelectedActivity);
     if(it)
     {
        QString text = it->text();
        Qt::CheckState checkStatus = it->checkState();
        if(text.isEmpty())
            return;
        QListWidgetItem *newItem = new QListWidgetItem(text,ui->listWidget_2);
        newItem->setCheckState(checkStatus);
        delete it;
        ui->listWidget->setCurrentRow(-1);
     }
    }
}


void MainWindow::on_buttonBox_rejected()
{
    if(mnSelectedPinned!=-1)
    {
       QListWidgetItem *it = ui->listWidget_2->takeItem(mnSelectedPinned);
       delete it;

       ui->listWidget_2->setCurrentRow(-1);
    }
}


void MainWindow::on_listWidget_2_currentRowChanged(int currentRow)
{
    mnSelectedPinned= currentRow;
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}

void MainWindow::on_listWidget_currentTextChanged(const QString &currentText)
{
    // Implementarea funcției aici
}
void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item)
{
    if(item && item->checkState()== Qt::Checked)
    {
       QString text = item->text();
       if(!text.isEmpty())
       {
        //verificare daca elementul se afla deja in lista
        QList<QListWidgetItem *> itemsExist = ui->listWidget_3->findItems(text,Qt::MatchExactly);
        if(itemsExist.isEmpty())
        {
            QListWidgetItem *newItem =  new QListWidgetItem(text,ui->listWidget_3);
            newItem->setCheckState(Qt::Unchecked);

            //sterge elementul
            int row = ui->listWidget->row(item);
            delete ui->listWidget->takeItem(row);
        }
        else
        {
            QListWidgetItem *existItem = itemsExist.first();
            if(existItem->checkState()!=Qt::Checked)
            {
                existItem->setCheckState(Qt::Checked);
            }
            int row = ui->listWidget->row(item);
            delete ui->listWidget->takeItem(row);
        }
       }
    }
}

void MainWindow::on_listWidget_2_itemChanged(QListWidgetItem *item)
{
    if(item && item->checkState()== Qt::Checked)
    {
       QString text = item->text();
       if(!text.isEmpty())
       {
        //verificare daca elementul se afla deja in lista
        QList<QListWidgetItem *> itemsExist = ui->listWidget_3->findItems(text,Qt::MatchExactly);
        if(itemsExist.isEmpty())
        {
            QListWidgetItem *newItem =  new QListWidgetItem(text,ui->listWidget_3);
            newItem->setCheckState(Qt::Checked);

            //sterge elementul
            int row = ui->listWidget_2->row(item);
            delete ui->listWidget_2->takeItem(row);
        }
        else
        {
            QListWidgetItem *existItem = itemsExist.first();
            if(existItem->checkState()!=Qt::Checked)
            {
                existItem->setCheckState(Qt::Checked);
            }
            int row = ui->listWidget_2->row(item);
            delete ui->listWidget_2->takeItem(row);
        }
       }
    }
}




void MainWindow::on_btnClearActivities_clicked()
{
    ui->listWidget->clear();
}

void MainWindow::on_btnClearPinned_clicked()
{
    ui->listWidget_2->clear();
}

void MainWindow::on_btnClearDone_clicked()
{
    ui->listWidget_3->clear();
}


void MainWindow::on_checkBox_clicked()
{
    //
}



void MainWindow::on_checkBox_stateChanged(int state)
{
    if(state == Qt::Checked)
    {
       ui->listWidget->clear();
       ui->listWidget_2->clear();
       ui->listWidget_3->clear();
    }
}

