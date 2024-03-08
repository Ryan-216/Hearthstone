/********************************************************************************
** Form generated from reading UI file 'Hearthstone.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEARTHSTONE_H
#define UI_HEARTHSTONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HearthstoneClass
{
public:

    void setupUi(QWidget *HearthstoneClass)
    {
        if (HearthstoneClass->objectName().isEmpty())
            HearthstoneClass->setObjectName("HearthstoneClass");
        HearthstoneClass->resize(600, 400);

        retranslateUi(HearthstoneClass);

        QMetaObject::connectSlotsByName(HearthstoneClass);
    } // setupUi

    void retranslateUi(QWidget *HearthstoneClass)
    {
        HearthstoneClass->setWindowTitle(QCoreApplication::translate("HearthstoneClass", "Hearthstone", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HearthstoneClass: public Ui_HearthstoneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEARTHSTONE_H
