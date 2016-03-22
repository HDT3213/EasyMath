#include "numkeyboard.h"
#include "ui_numkeyboard.h"

NumKeyBoard::NumKeyBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumKeyBoard)
{
    ui->setupUi(this);
	setWindowTitle("Number");
}

NumKeyBoard::~NumKeyBoard()
{
    delete ui;
}

void NumKeyBoard::on_pushButton_clicked()
{
    num += "7";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_2_clicked()
{
    num += "8";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_3_clicked()
{
    num += "9";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_4_clicked()
{
    num += "4";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_5_clicked()
{
    num += "5";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_6_clicked()
{
    num += "6";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_7_clicked()
{
    num += "1";
	ui->lineEdit->setText(num);
}


void NumKeyBoard::on_pushButton_8_clicked()
{
    num += "2";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_9_clicked()
{
    num += "3";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_10_clicked()
{
    num += ".";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_11_clicked()
{
    num += "0";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_13_clicked()
{
    num += "-";
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_pushButton_12_clicked()
{
    num = num.left(num.size() - 1);
	ui->lineEdit->setText(num);
}

void NumKeyBoard::on_buttonBox_accepted()
{
	if (editId != 3) {
		emit finished(num, editId);
	}
	else {
		emit finished(num);
	}
}


void NumKeyBoard::on_buttonBox_rejected()
{
    destroy();
}

void NumKeyBoard::disp(int idArgu) {
	num.clear();
	ui->lineEdit->setText(num);
	editId = idArgu;
	if (idArgu == 1) {
		this->setWindowTitle("superscript");
	}
	else if (idArgu == 2) {
		this->setWindowTitle("subscript");
	}
	this->show();
}

void NumKeyBoard::disp(QString str) {
	editId = 3;
	ui->lineEdit->setText(str);
	this->show();
}

void NumKeyBoard::on_pushButton_14_clicked() {
	num += ";";
	ui->lineEdit->setText(num);
}
