#ifndef CALSOLVER_H
#define CALSOLVER_H

#include <QObject>
#include <QStringList>
#include <QString>

#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<map>

using namespace std;

#define sin_o  's'
#define cos_o  'c'
#define tan_o  't'
#define asin_o 's'
#define acos_o 'C'
#define atan_o 'T'
#define sinh_o 'i'
#define cosh_o 'o'
#define tanh_o 'a'
#define exp_o  'p'
#define ln_o   'n'
#define lg_o   'g'

typedef enum {
	ExprState, FuncState, GenerState, RecurState
} State;

typedef enum {
	FxOper, LimOper, IntegralOper, DiffOper
} Oper;

//using a tiny  number as infinitely small
#define EPS 1E-4
//using a large number as infinitely great
#define INF 1E8
//The max time of iteration
#define ITER_LIMIT  1000
#define DIFFUSE 2147483647
#define MLen 512

class Brac_dismatch {};
class Oper_dismatch {};
class Limit_diffuse {};

class Expr : public QObject {
    Q_OBJECT
protected:
    void    init_map();
    string  pretreat(string& equ);
    double  cal_poly(string& equ);
    double  cal_brac(string& equ);

    map<char,int>  oper_type;
    map<string, string> rep_expr;
public:
    Expr();
    double eval(const string& equ_argu); //interface,deal with Exception,Protect origin argument.
};

class Func {  //function
protected:
    string& subs(string& equ_argu, string& var, double* val);
    double  integral_romberg(string& equ, double lower, double upper);
    double  limit_fx(string& equ, double x);
    double  diff_2Points(string& equ_argu, string& var, double *val_argu, unsigned int order);
public:
    double  fx(string &equ_argu, double x);
    double  fx(string& equ_argu, string& var, double* val);
    double  diff(string& equ_argu, double x, int order);
    double  diff(string& equ_argu, string& var, double *val_argu, unsigned int order);
    double  integral(string& equ, double lower, double upper);
    double  limit(string& equ, double x);
};

class Arithprog { // arithmetic progression, index from 1
private:
   double recur(string& equ_argu,double *val_arr, size_t val_i, int n);
public:
    //general term formula
    double at_gener(string& equ,int index);
    double sum_gener(string& equ,int lower,int upper); //[lower,upper]
    double limit_gener(string& equ);
    double at_recur(string& equ, double* val_argu, size_t val_i, int index);
    double sum_recur(string& equ,double* val_argu, size_t val_i, int lower, int upper);
    double limit_recur(string& equ, double* val_argu, size_t val_i);
};

class Solver : public QObject {
	Q_OBJECT

public:
    Solver();

signals:
	void calculated(double);
	void dismatch(QString warn);

public slots:
	void calculate(QStringList cmdList);
	void calculate(QStringList cmdList, QList<double> val); // val index from 0
};

#endif // CALSOLVER_H
