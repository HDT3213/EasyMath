#include "funcgraph.h"
#include "ui_funcgraph.h"

#include <QDebug>
FuncGraph::FuncGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FuncGraph)
{
    ui->setupUi(this);
	setWindowTitle("Graph");

	this->order = 0;
	this->lower = -200;
	this->upper = 200;
	this->zoom = 1;
}

FuncGraph::~FuncGraph() {
    delete ui;
}

void FuncGraph::drawGrid(QPainter *painter) {
	//width = 400 height = 300

	//Draw X
	painter->drawLine(0, 150, 400, 150);
	//Draw Y
	painter->drawLine(200, 0, 200, 300);

}

Geometry FuncGraph::transform(Geometry mathGeo) {
	Geometry windowGeo;
	
	mathGeo.x *= 10 * zoom;
	mathGeo.y *= 10 * zoom;

	windowGeo.x = mathGeo.x + 200;
	windowGeo.y = -mathGeo.y + 150;

	return windowGeo;
}

void FuncGraph::drawGraph(QString equArgu) {
	equ = equArgu;
	update();
	this->show();
}

void FuncGraph::initPos() {
	Func func;
	double x, y;
	Geometry geo;
	pos.clear();
	for (x = lower; x <= upper; x += XDIS) {
		y = func.diff(equ.toStdString(), x, order);
		geo.x = x;
		geo.y = y;
		pos.append(geo);
	}
}
void FuncGraph::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	QBrush brush;
	Geometry winGeo, lastWinGeo;
	Func func;
	size_t i;

	initPos();

	brush.setStyle(Qt::SolidPattern);
	brush.setColor(Qt::black);
	painter.setBrush(brush);
	drawGrid(&painter);

	brush.setColor(Qt::blue);
	painter.setBrush(brush);

	winGeo = transform(pos.at(0));
	lastWinGeo = winGeo;
	for (i = 0; i < pos.size(); i++) {
		winGeo = transform(pos.at(i));
		painter.drawEllipse(winGeo.x, winGeo.y, 1, 1);
		painter.drawLine(winGeo.x, winGeo.y, lastWinGeo.x, lastWinGeo.y);
		lastWinGeo = winGeo;
	}
}

void FuncGraph::setLimit(double lower, double uppper) {
	this->lower = lower;
	this->upper = upper;
}




void FuncGraph::on_horizontalSlider_sliderReleased() {
		double last = zoom;
        zoom = ui->horizontalSlider->value() / 100;
        update();
}

void FuncGraph::on_horizontalSlider_sliderMoved(int position) {}
