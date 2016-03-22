#include "mainwindow.h"
#include "calsolver.h"
#include "numkeyboard.h"
#include "funcgraph.h"

#include <QApplication>

#include <QDebug>
void test_expr()
{
    Expr expr;
    double y;
    string equ("(1+1)");
    y = expr.eval(equ);
    qDebug() << y;
}

void test_func() {
	Func func;
	string equ("x^2"), var("x");
	double val[] = { 2 }, y;
	/*y = func.fx(equ, var, val);
	qDebug() << y;
	y = func.diff(equ, var, val, 1);
	qDebug() << y;
	y = func.diff(equ, var, val, 2);
	qDebug() <<y;*/
	y = func.integral(equ, 0, 1);
	qDebug() << y;
}

void test_prog(void) {
	Arithprog prog;
	string equ("a[n-1]+a[n-2]"), equ2("1/n");
	size_t val_i = 2;
	double val[] = { 1, 1 }, y;
	int n = 3; // 31 is the max
	y = prog.at_recur(equ, val, val_i, n);
	qDebug() << y;
	/*y = prog.sum_recur(equ, val, val_i, 1, n);
	qDebug() << y;

	
	y = prog.at_gener(equ2, n);
	qDebug() << y;
	y = prog.sum_gener(equ2, 1, n);
	qDebug() << y;
	y = prog.limit_gener(equ2);
	qDebug() << y;*/
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	Solver solver;
	NumKeyBoard keyBoard(&w);
	FuncGraph funcGraph(&w);

    w.show();
	test_prog();

    QObject::connect(&w, SIGNAL(toCalculate(QStringList)), &solver, SLOT(calculate(QStringList)) );
	QObject::connect(&w, SIGNAL(toCalculate(QStringList, QList<double>)), &solver, SLOT(calculate(QStringList, QList<double>)));
	QObject::connect(&solver, SIGNAL(calculated(double)), &w, SLOT(dispAnswer(double)) );
	QObject::connect(&solver, SIGNAL(dismatch(QString)), &w, SLOT(dispWarning(QString)));

	QObject::connect(&w, SIGNAL(keyBoard(int)), &keyBoard, SLOT(disp(int)));
	QObject::connect(&w, SIGNAL(keyBoard(QString)), &keyBoard, SLOT(disp(QString)));
	QObject::connect(&keyBoard, SIGNAL(finished(QString, int)), &w, SLOT(updateScript(QString, int)));
	QObject::connect(&keyBoard, SIGNAL(finished(QString)), &w, SLOT(updateRecurBase(QString)));

	QObject::connect(&w, SIGNAL(toDrawGraph(QString)), &funcGraph, SLOT(drawGraph(QString)));

    return a.exec();
}
