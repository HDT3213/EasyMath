#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calsolver.h"
#include "numkeyboard.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <QMouseEvent>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
	void toCalculate(QStringList cmd);
	void toCalculate(QStringList cmd, QList<double> val);
	void keyBoard(int id);
	void keyBoard(QString str);
	void toDrawGraph(QString equ);

protected:
	QString cmd;
    State   state;
	Oper    oper;
	bool    shift;
	double  x;
	double  y;

	QString supScript;
	QString subScript;
	QString prefix;

	QString recurBaseStr;
	QList<double> recurBase;

	QList<QString> cmdHistory;
	QList<double>  ansHistory;
	void updateHistory();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	
    void dispAnswer(double ans);
	void dispWarning(QString warn);

	void updateScript(QString num, int editId);
	void updatePrefix();

	void updateRecurBase(QString str);

    void on_pushButton_10_clicked();
	void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_41_clicked();

    void on_checkBox_stateChanged(int arg1);
    void on_pushButton_44_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_29_clicked();
    
	void on_action_triggered();

    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_action4_triggered();

    void on_action5_triggered();

    void on_action6_triggered();

    void on_pushButton_47_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
