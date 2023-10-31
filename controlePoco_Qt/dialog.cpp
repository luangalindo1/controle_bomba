#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
	ui->setupUi(this);
	ui->modoout_label->setText("---------");
	ui->nivel_lcdNumber->display("-------");
	arduino = new QSerialPort(this);
	serialBuffer = "";
	parsed_data = "";

	// Código de teste para identificar o Arduino.

	qDebug() << "Número de portas: " << QSerialPortInfo::availablePorts().length() << "\n";

	foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
	{
	    qDebug() << "Descrição: " << serialPortInfo.description() << "\n";
	    qDebug() << "Tem o ID Vendor?: " << serialPortInfo.hasVendorIdentifier() << "\n";
	    qDebug() << "ID do Vendor: " << serialPortInfo.vendorIdentifier() << "\n";
	    qDebug() << "Tem o ID do produto?: " << serialPortInfo.hasProductIdentifier() << "\n";
	    qDebug() << "ID do produto: " << serialPortInfo.productIdentifier() << "\n";
	}

	bool arduino_is_available = false;
	QString arduino_uno_port_name;

	foreach(const QSerialPortInfo & serialPortInfo, QSerialPortInfo::availablePorts())
	{
		if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier())
			if((serialPortInfo.productIdentifier() == arduino_uno_product_id) && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id))
			{
				arduino_is_available = true;
				arduino_uno_port_name = serialPortInfo.portName();
			}
	}

	if(arduino_is_available)
	{
		qDebug() << "Porta Arduino encontrada...\n";
		arduino->setPortName(arduino_uno_port_name);
		arduino->open(QSerialPort::ReadWrite);
		arduino->setBaudRate(QSerialPort::Baud9600);
		arduino->setDataBits(QSerialPort::Data8);
		arduino->setFlowControl(QSerialPort::NoFlowControl);
		arduino->setParity(QSerialPort::NoParity);
		arduino->setStopBits(QSerialPort::OneStop);
		QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
	}
	else
	{
		qDebug() << "Não foi possível encontrar a porta correta do Arduino.\n";
		QMessageBox::information(this, "Erro na Porta Serial", "Não foi possível abrir a porta serial.");
	}
}

Dialog::~Dialog()
{
	if(arduino->isOpen())
		arduino->close();

	delete ui;
}

void Dialog::readSerial()
{
	QStringList buffer_split = serialBuffer.split(",");

	if(buffer_split.length() < 2)
	{
		serialData = arduino->readAll();
		serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
		serialData.clear();
	}
	else
	{
		serialBuffer = "";
		//qDebug() << buffer_split << "\n";
		parsed_data = buffer_split[0];
		//qDebug() << "Nivel: " << parsed_data << "\n";
		Dialog::atualizarNivel(parsed_data);

		if (buffer_split[1] == "d")
			ui->modoout_label->setText(QString("<span style=\" font-size:22pt; color:#00007f;\">%1</span>").arg("Desligado"));
		else if (buffer_split[1] == "a")
			ui->modoout_label->setText(QString("<span style=\" font-size:22pt; color:#00007f;\">%1</span>").arg("Ligado"));
		else if (buffer_split[1] == "m")
			ui->modoout_label->setText(QString("<span style=\" font-size:22pt; color:#00007f;\">%1</span>").arg("Secando"));
	}

}

void Dialog::atualizarNivel(QString sensor_reading)
{
	ui->nivel_lcdNumber->display(sensor_reading);
}


void Dialog::on_automatico_pushButton_clicked()
{
	if (arduino->isWritable())
		arduino -> write("s");
	else
		qDebug() << "Erro ao escrever na porta serial.";
}

void Dialog::on_secar_pushButton_clicked()
{
	if (arduino->isWritable())
		arduino -> write("m");
	else
		qDebug() << "Erro ao escrever na porta serial.";
}
