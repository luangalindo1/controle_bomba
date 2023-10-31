#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>


namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    public:
        explicit Dialog(QWidget *parent = 0);
        ~Dialog();

    private slots:
        void readSerial();
        void atualizarNivel(QString);
        void on_automatico_pushButton_clicked();
        void on_secar_pushButton_clicked();

private:
        Ui::Dialog *ui;

        QSerialPort *arduino;
        static const quint16 arduino_uno_vendor_id = 6790;
        static const quint16 arduino_uno_product_id = 29987;
        QByteArray serialData;
        QString serialBuffer;
        QString parsed_data;
};

#endif
