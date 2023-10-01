#ifndef NUMBEREDMODEL_H
#define NUMBEREDMODEL_H

#include<QAbstractListModel>
#include<QStringList>

class NumberedModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit NumberedModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};

#endif // NUMBEREDMODEL_H
