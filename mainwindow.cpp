#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cmd.clear();
    ui->setupUi(this);
    setWindowTitle("EasyMath");

	ui->action->setEnabled(false);
	state = ExprState;
	oper  = FxOper;
	x = 0;
	y = 0;
	supScript.clear();
	subScript.clear();
	cmdHistory.clear();
	ansHistory.clear();
	shift = false;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_10_clicked() {
    cmd += "0";
    ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_9_clicked() {
    cmd += "1";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_8_clicked() {
    cmd += "2";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_7_clicked() {
    cmd += "3";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_6_clicked() {
    cmd += "4";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_5_clicked() {
    cmd += "5";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_4_clicked() {
    cmd += "6";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_clicked() {
    cmd += "7";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_2_clicked() {
    cmd += "8";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_3_clicked() {
    cmd += "9";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_11_clicked() {
    cmd += ".";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_13_clicked() {
    cmd += "+";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_14_clicked() {
    cmd += "-";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_16_clicked() {
    cmd += "*";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_15_clicked() {
    cmd += "/";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_18_clicked() {
    cmd += "(";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_17_clicked() {
    cmd += ")";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_29_clicked() {
	cmd += "^";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_21_clicked() {
	if (shift == false) {
		cmd += "sin(";
	}
	else {
		cmd += "asin(";
	}
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_27_clicked() {
    cmd += "sinh(";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_22_clicked() {
	if (shift == false) {
		cmd += "cos(";
	}
	else  {
		cmd += "acos(";
	}
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_26_clicked() {
    cmd += "cosh(";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_23_clicked() {
	if (shift == false) {
		cmd += "tan(";
	}
	else {
		cmd += "atan(";
	}
	ui->textEdit->setText(cmd);
}


void MainWindow::on_pushButton_28_clicked() {
    cmd += "tanh(";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_24_clicked() {
    cmd += "ln(";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_25_clicked() {
    cmd += "exp(";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_30_clicked() {
    cmd += "pi";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_20_clicked() {
    //Button BackSpace
    cmd = cmd.left(cmd.size() - 1);
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_19_clicked() {
    //Button Clear
    cmd.clear();
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_31_clicked() {
    //Button "f(x)"
	supScript.clear();
	subScript = "x";
	state = FuncState;
	oper = FxOper;
	updatePrefix();
}


void MainWindow::on_pushButton_34_clicked() {
    //Button "lim f(x)"
	supScript.clear();
	subScript.clear();
	state = FuncState;
	oper = LimOper;
	updatePrefix();
}

void MainWindow::on_pushButton_32_clicked() {
    //Button "f'(x)"
	supScript = "1";
	subScript = "x";
	state = FuncState;
	oper  = DiffOper;
	updatePrefix();
}

void MainWindow::on_pushButton_33_clicked() {
    //Button  "Int f(x)"
	supScript.clear();
	subScript.clear();
	state = FuncState;
	oper = IntegralOper;
	updatePrefix();
}

void MainWindow::on_pushButton_36_clicked() {
    //Button "a[n] = f(n)"
	supScript.clear();
	subScript = "n";
	state = GenerState;
	oper = FxOper;
	updatePrefix();
}

void MainWindow::on_pushButton_35_clicked()
{
    //Button "s[n] = f(n)"
	subScript.clear();
	supScript.clear();
	state = GenerState;
	oper  = IntegralOper;
	updatePrefix();
}

void MainWindow::on_pushButton_37_clicked() {
    //Button "lim = f(n)"
	supScript.clear();
	subScript.clear();
	state = GenerState;
	oper  = LimOper;
	updatePrefix();
}

void MainWindow::on_pushButton_38_clicked() {
    //Button "a[n] = f(a[n-1])"
	recurBase.clear();
	recurBaseStr.clear();
	state = RecurState;
	oper  = FxOper;
	updatePrefix();
}

void MainWindow::on_pushButton_39_clicked() {
    //Button "s[n] = f(a[n-1])"
	recurBase.clear();
	recurBaseStr.clear();
	state = RecurState;
	oper  = IntegralOper;
	updatePrefix();
}

void MainWindow::on_pushButton_40_clicked() {
    //Button "lim = f(a[n-1])"
	recurBase.clear();
	recurBaseStr.clear();
	state = RecurState;
	oper = LimOper;
	updatePrefix();
}

void MainWindow::on_pushButton_41_clicked() {
    //Button "a[n-1]"
	cmd += "a[n-1]";
	ui->textEdit->setText(cmd);
}


void MainWindow::on_pushButton_44_clicked() {
	//Button "Expr"
	state = ExprState;
	oper = FxOper;
	updatePrefix();
}

void MainWindow::on_pushButton_43_clicked() {
    //Button "x"
	cmd += "x";
	ui->textEdit->setText(cmd);
}

void MainWindow::on_checkBox_stateChanged(int state) {
    shift = !shift;
}

void MainWindow::dispAnswer(double ans) {
	cmd.clear();
	ui->textEdit->setText(cmd);
	cmd.setNum(ans);
	ui->textEdit->setText(cmd);
	cmdHistory.append(prefix + cmd);
	ansHistory.append(ans);
	updateHistory();
}

void MainWindow::updateHistory() {
	if (cmdHistory.size() < 7) {
		switch (cmdHistory.size()) {
		case  6:
			ui->action6->setText(cmdHistory.at(cmdHistory.size() - 6));
		case 5:
			ui->action5->setText(cmdHistory.at(cmdHistory.size() - 5));
		case 4:
			ui->action4->setText(cmdHistory.at(cmdHistory.size() - 4));
		case 3:
			ui->action3->setText(cmdHistory.at(cmdHistory.size() - 3));
		case 2:
			ui->action2->setText(cmdHistory.at(cmdHistory.size() - 2));
		case 1:
			ui->action1->setText(cmdHistory.at(cmdHistory.size() - 1));
		default:
			break;
		}
	}
	else {
		ui->action1->setText(cmdHistory.at(cmdHistory.size() - 1));
		ui->action2->setText(cmdHistory.at(cmdHistory.size() - 2));
		ui->action3->setText(cmdHistory.at(cmdHistory.size() - 3));
		ui->action4->setText(cmdHistory.at(cmdHistory.size() - 4));
		ui->action5->setText(cmdHistory.at(cmdHistory.size() - 5));
		ui->action6->setText(cmdHistory.at(cmdHistory.size() - 6));
	}
}

void MainWindow::dispWarning(QString warn) {
	QMessageBox::critical(this, "Warning!", warn);
}

void MainWindow::on_pushButton_45_clicked() {
    //superscript
	emit keyBoard(1);
}

void MainWindow::on_pushButton_46_clicked() {
    //subscript
	emit keyBoard(2);
}

void MainWindow::updatePrefix() {
	if (state == FuncState && oper == FxOper) {
		ui->action->setEnabled(true);
	}
	else {
		ui->action->setEnabled(false);
	}
	switch (state){
		case ExprState:
			switch (oper) {
			case FxOper:
				prefix = "y = ";
				ui->label->setText(prefix);
				return;
			default:
				break;
			}
		case FuncState:
			switch (oper) {
			case FxOper:
				prefix = "f(" + subScript + ") = ";
				ui->label->setText(prefix);
				return;
			case DiffOper:
				prefix = "f<sup>(" + supScript + ")</sup>(" + subScript + ") = ";
				ui->label->setText(prefix);
				return;
			case IntegralOper:
				prefix = "Int F(" + subScript + "," + supScript + ") = ";
				ui->label->setText(prefix);
				return;
			case LimOper:
				prefix = "(x ->" + subScript + ") lim f(x) = ";
				ui->label->setText(prefix);
				return;
			default:
				break;
			}
		case GenerState:
		case RecurState:
			switch (oper)
			{
			case FxOper:
				prefix = "a[" + subScript + "] = ";
				ui->label->setText(prefix);
				return;
			case IntegralOper:
				prefix = "sum(" + subScript + "," + supScript + ") = ";
				ui->label->setText(prefix);
				return;
			case LimOper:
				prefix = "(x -> oo)lim a[n] = ";
				ui->label->setText(prefix);
				return;
			default:
				break;
			}
		default:
			break;
		}
}

void MainWindow::on_pushButton_12_clicked() {
	// Button "="
	QStringList cmdList;
	cmdList << QString::number(state) << QString::number(oper) << cmd << QString::number(x) << QString::number(y);
	if (state != RecurState) {
		emit toCalculate(cmdList);
	}
	else {
		emit toCalculate(cmdList, recurBase);
	}
}

void MainWindow::updateScript(QString num, int editId) {
	if (editId == 1) {
		supScript = num;
		y = num.toDouble();
	}
	else if (editId == 2) {
		subScript = num;
		x = num.toDouble();
	}
	updatePrefix();
}

void MainWindow::on_action_triggered() {
	if (state == FuncState && oper == FxOper)
		emit toDrawGraph(cmd);
}

void MainWindow::on_action1_triggered() {
    //History1
	int off = 1;
	if (ansHistory.size() < off) {
		return;
	}
	cmd += QString::number(ansHistory.at(ansHistory.size() - off));
	ui->textEdit->setText(cmd);
}

void MainWindow::on_action2_triggered() {
    //History2
	int off = 2;
	if (ansHistory.size() < off) {
		return;
	}
	cmd += QString::number(ansHistory.at(ansHistory.size() - off));
	ui->textEdit->setText(cmd);
}

void MainWindow::on_action3_triggered() {
    //HIstory3
	int off = 3;
	if (ansHistory.size() < off) {
		return;
	}
	cmd += QString::number(ansHistory.at(ansHistory.size() - off));
	ui->textEdit->setText(cmd);
}

void MainWindow::on_action4_triggered() {
    //History4
	int off = 4;
	if (ansHistory.size() < off) {
		return;
	}
	cmd += QString::number(ansHistory.at(ansHistory.size() - off));
	ui->textEdit->setText(cmd);
}

void MainWindow::on_action5_triggered() {
    //History5
	int off = 5;
	if (ansHistory.size() < off) {
		return;
	}
	cmd += QString::number(ansHistory.at(ansHistory.size() - off));
	ui->textEdit->setText(cmd);
}

void MainWindow::on_action6_triggered() {
    //History6
	int off = 6;
	if (ansHistory.size() < off) {
		return;
	}
	cmd += QString::number(ansHistory.at(ansHistory.size() - off));
	ui->textEdit->setText(cmd);
}

void MainWindow::on_pushButton_47_clicked() {
    //Recur
	emit keyBoard(recurBaseStr);
}

void MainWindow::updateRecurBase(QString str) {
	int lower = 0, upper = 0;
	QString valStr;
	for (upper = 0; upper < str.size(); upper++) {
		if (str.at(upper) == ';') {
			valStr = str.mid(lower, upper - lower);
			lower = upper;
			recurBase.append(valStr.toDouble());
		}
	}
	valStr = str.right(str.size() - lower + 1);
	recurBase.append(valStr.toDouble());
}