#ifndef FUNCGRAPH_H
#define FUNCGRAPH_H

#include "calsolver.h"

#include <QDialog>
#include <QPainter>
#include <QString>
#include <QList>

#define XDIS  0.1
#define YDIS  1

namespace Ui {
class FuncGraph;
}

struct Geometry {
	double x;
	double y;

	Geometry() {
		x = 0;
		y = 0;
	}
};

class FuncGraph : public QDialog
{
    Q_OBJECT
public slots:
	void drawGraph(QString equArgu);

protected:
	Geometry transform(Geometry mathGeo);
	QString equ;

	QList<Geometry> pos;
	double lower;
	double upper;
	int order;

    double zoom;

	void initPos();
public:
    explicit FuncGraph(QWidget *parent = 0);
    ~FuncGraph();

	void paintEvent(QPaintEvent *);
	void drawGrid(QPainter *painter);

	void setLimit(double lower, double upper);
private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_sliderReleased();

private:
    Ui::FuncGraph *ui;
};

#endif // FUNCGRAPH_H
