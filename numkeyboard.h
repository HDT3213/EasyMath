#ifndef NUMKEYBOARD_H
#define NUMKEYBOARD_H

#include <QDialog>
#include <QString>

namespace Ui {
class NumKeyBoard;
}

class NumKeyBoard : public QDialog
{
    Q_OBJECT
signals:
    void finished(QString ans,int editId);
	void finished(QString ans);
protected:
    QString num;
	int editId;

public:
    explicit NumKeyBoard(QWidget *parent = 0);
    ~NumKeyBoard();

private slots:

	void disp(int id);

	void disp(QString str);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::NumKeyBoard *ui;

};

#endif // NUMKEYBOARD_H
