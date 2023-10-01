#include "numberedmodel.h"
#include "mainwindow.h"
NumberedModel::NumberedModel(QObject *parent)
    : QAbstractListModel(parent)
{
    initializeItemList();
}
int NumberedModel::rowCount(const QModelIndex &parent) const
{
    return itemList.size();
}
QVariant NumberedModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        // Verificați dacă indexul este în limitele listei itemList
        if (index.row() >= 0 && index.row() < itemList.size())
        {
            return itemList.at(index.row());
        }
    }

    return QVariant();
}
