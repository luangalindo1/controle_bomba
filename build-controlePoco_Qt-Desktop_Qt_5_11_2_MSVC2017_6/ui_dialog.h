/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *automatico_pushButton;
    QLCDNumber *nivel_lcdNumber;
    QLabel *nivel_label;
    QLabel *porcentagem_label;
    QLabel *modo_label;
    QLabel *modoout_label;
    QPushButton *secar_pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(340, 240);
        automatico_pushButton = new QPushButton(Dialog);
        automatico_pushButton->setObjectName(QStringLiteral("automatico_pushButton"));
        automatico_pushButton->setGeometry(QRect(10, 140, 321, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        automatico_pushButton->setFont(font);
        nivel_lcdNumber = new QLCDNumber(Dialog);
        nivel_lcdNumber->setObjectName(QStringLiteral("nivel_lcdNumber"));
        nivel_lcdNumber->setGeometry(QRect(110, 20, 171, 51));
        QPalette palette;
        QBrush brush(QColor(0, 0, 94, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        QBrush brush2(QColor(60, 60, 60, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        QBrush brush3(QColor(76, 76, 76, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        nivel_lcdNumber->setPalette(palette);
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setKerning(true);
        nivel_lcdNumber->setFont(font1);
        nivel_lcdNumber->setDigitCount(7);
        nivel_label = new QLabel(Dialog);
        nivel_label->setObjectName(QStringLiteral("nivel_label"));
        nivel_label->setGeometry(QRect(10, 20, 91, 51));
        porcentagem_label = new QLabel(Dialog);
        porcentagem_label->setObjectName(QStringLiteral("porcentagem_label"));
        porcentagem_label->setGeometry(QRect(290, 20, 41, 51));
        modo_label = new QLabel(Dialog);
        modo_label->setObjectName(QStringLiteral("modo_label"));
        modo_label->setGeometry(QRect(10, 90, 181, 51));
        modoout_label = new QLabel(Dialog);
        modoout_label->setObjectName(QStringLiteral("modoout_label"));
        modoout_label->setGeometry(QRect(200, 90, 131, 51));
        secar_pushButton = new QPushButton(Dialog);
        secar_pushButton->setObjectName(QStringLiteral("secar_pushButton"));
        secar_pushButton->setGeometry(QRect(10, 190, 321, 41));
        secar_pushButton->setFont(font);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        automatico_pushButton->setText(QApplication::translate("Dialog", "Autom\303\241tico", nullptr));
        nivel_label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#000000;\">N\303\255vel:</span></p></body></html>", nullptr));
        porcentagem_label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:28pt; color:#00007f;\">%</span></p></body></html>", nullptr));
        modo_label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600; color:#000000;\">Autom\303\241tico:</span></p></body></html>", nullptr));
        modoout_label->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:22pt; color:#00007f;\">Desligado</span></p></body></html>", nullptr));
        secar_pushButton->setText(QApplication::translate("Dialog", "Secar Po\303\247o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
