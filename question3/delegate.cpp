#include "delegate.h"

#include <QLineEdit>

Delegate::Delegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QLineEdit *lineEdit = new QLineEdit(parent);
    return lineEdit;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const  {
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(value);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const  {
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    QString value = lineEdit->text();
    model->setData(index, value, Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const  {
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}
