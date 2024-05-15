#ifndef DELEGATE_H
#define DELEGATE_H
#include <QStyledItemDelegate>
#include <QItemDelegate>
#include <QObject>

class Delegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override ;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

signals:
        // QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
        // QString value = lineEdit->text();
        // model->setData(index, value, Qt::EditRole);

};

#endif // DELEGATE_H
