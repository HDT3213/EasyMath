#include "calsolver.h"

Expr::Expr() {
    init_map();
}

double Expr::eval(const string& equ_argu) {
    string equ = string(equ_argu);
	return cal_brac(equ);
}

void Expr::init_map() {
    //initialize rep_expr
    rep_expr.insert(make_pair("sin", "1s"));
    rep_expr.insert(make_pair("cos", "1c"));
    rep_expr.insert(make_pair("tan", "1t"));
    rep_expr.insert(make_pair("asin", "1S"));
    rep_expr.insert(make_pair("acos", "1C"));
    rep_expr.insert(make_pair("atan", "1T"));
    rep_expr.insert(make_pair("sinh", "1T"));
    rep_expr.insert(make_pair("sinh", "1i"));
    rep_expr.insert(make_pair("cosh", "1o"));
    rep_expr.insert(make_pair("tanh", "1a"));
    rep_expr.insert(make_pair("exp", "1p"));
    rep_expr.insert(make_pair("ln", "1n"));
    rep_expr.insert(make_pair("lg", "1g"));
    rep_expr.insert(make_pair("pi", "3.1415926"));
    //initialize oper_type
    oper_type.insert(make_pair(sin_o, 4));
    oper_type.insert(make_pair(cos_o, 4));
    oper_type.insert(make_pair(tan_o, 4));
    oper_type.insert(make_pair(asin_o, 4));
    oper_type.insert(make_pair(acos_o, 4));
    oper_type.insert(make_pair(atan_o, 4));
    oper_type.insert(make_pair(sinh_o, 4));
    oper_type.insert(make_pair(cosh_o, 4));
    oper_type.insert(make_pair(tanh_o, 4));
    oper_type.insert(make_pair(exp_o, 4));
    oper_type.insert(make_pair(ln_o, 4));
    oper_type.insert(make_pair(lg_o, 4));
    oper_type.insert(make_pair('^', 3));
    oper_type.insert(make_pair('*', 2));
    oper_type.insert(make_pair('/', 2));
    oper_type.insert(make_pair('+', 1));
    oper_type.insert(make_pair('-', 1));
}

string Expr::pretreat(string& equ) {
    int len;
    string::iterator iter;
    string test;
    for (iter = equ.begin(); iter != equ.end(); iter++) {
        for (len = 3; len > 1; len--) {
            if (iter - equ.begin() + len < equ.size()) {
                test.assign(iter, iter + len);
                if (rep_expr.count(test)) {
                    equ.erase(iter, iter + len);
                    test = rep_expr.find(test)->second;
                    equ.insert(iter, test.begin(), test.end());
                }
            }
        }
    }
    return equ;
}

double Expr::cal_poly(string& equ) {
    stringstream temp_buf;
    string temp_str;
    string::iterator iter,beg=equ.begin();
    vector<char> oper_que;
    vector<double> val_que;
    double temp_val;
    size_t i;
    Brac_dismatch error_brac_dismatch;
    for (iter=equ.begin();iter != equ.end(); iter++) { 
        if (*iter == '(' || *iter == ')') {
            throw error_brac_dismatch;
        }
		if (iter == equ.begin() && *iter == '-') {
			iter++; //ignore the first byte which may be "-".
		}
        if (oper_type.count(*iter)) { // if *iter is an operator
            //push the val
            temp_str.assign(beg,iter);
            temp_buf<<temp_str;
            temp_buf>>temp_val;
            val_que.push_back(temp_val);
            //push the operator
            oper_que.push_back(*iter);
            //reset beg, iter.
            beg=++iter;
            //If there is a negative sign, it will regard it as part of the value
            //without judging whether it is an operator.
        }
    }
    //push the last val
    temp_str.assign(beg,equ.end());
    temp_buf.clear();
    temp_buf<<temp_str;
    temp_buf>>temp_val;
    val_que.push_back(temp_val);
    // Calculate an expression and replace it with its answer.
    // The operator, oper_que[i], has two operands, val_que[i] and val_que[i+1].
    //calculate
    for (i=0;i<oper_que.size();i++) {
        if (oper_que.at(i) == sin_o) {
            val_que.at(i+1)=sin(val_que.at(i+1));
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else  if (oper_que.at(i) == cos_o) {
            val_que.at(i+1)=cos(val_que.at(i+1));
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == tan_o) {
            val_que.at(i+1)=tan(val_que.at(i+1));
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == asin_o) {
            val_que.at(i+1)=asin(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == acos_o) {
             val_que.at(i+1)=acos(val_que.at(i+1));
             //cout<<val_que.at(i+1)<<endl;
             val_que.erase(val_que.begin()+i);
             oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == atan_o) {
            val_que.at(i+1)=atan(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == sinh_o) {
            val_que.at(i+1)=sinh(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == cosh_o) {
            val_que.at(i+1)=cosh(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == tanh_o) {
            val_que.at(i+1)=tanh(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == exp_o) {
            val_que.at(i+1)=exp(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == ln_o) {
            val_que.at(i+1)=log(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == lg_o) {
            val_que.at(i+1)=log10(val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
    }
    for (i=0;i<oper_que.size();i++) {
        if (oper_que.at(i) == '^') {
            val_que.at(i+1)=pow(val_que.at(i),val_que.at(i+1));
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
    }
    for (i=0;i<oper_que.size();i++) {
        if (oper_que.at(i) == '*') {
            val_que.at(i+1)=val_que.at(i)*val_que.at(i+1);
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else  if (oper_que.at(i) == '/') {
            val_que.at(i+1)=val_que.at(i)/val_que.at(i+1);
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
    }
    for (i=0;i<oper_que.size();i++) {
        if (oper_que.at(i) == '+') {
            val_que.at(i+1)=val_que.at(i)+val_que.at(i+1);
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
        else if (oper_que.at(i) == '-') {
            val_que.at(i+1)=val_que.at(i)-val_que.at(i+1);
            //cout<<val_que.at(i+1)<<endl;
            val_que.erase(val_que.begin()+i);
            oper_que.erase(oper_que.begin()+i);
        }
    }
    return val_que.at(0);
}

double Expr::cal_brac(string& equ) {
    pretreat(equ);
    string temp_str;
    vector<int> brac_stack;
    stringstream temp_buf;
    double ans;
    size_t equ_i;
    Brac_dismatch error_brac_dismatch;
    for (equ_i=0;equ_i < equ.size();equ_i++) {
        if (equ.at(equ_i) == '(') {
            //push left bracket into stack
            brac_stack.push_back(equ_i);
        }
        else if (equ.at(equ_i) == ')') {
             // calculate the expression within a pair of brackets
             temp_str.assign(equ.begin()+brac_stack.back()+1,equ.begin()+equ_i);
             ans=cal_poly(temp_str);
             //cast the ans (double) to string
             temp_buf.clear();
             temp_buf<<ans;
             temp_buf>>temp_str;
             //replace the brackets for its value
             equ.replace(brac_stack.back(),equ_i+1,temp_str);
             brac_stack.pop_back();
        }
    }
    if (brac_stack.empty() == false) {
        throw error_brac_dismatch;
    }
    //calculate the last expression which has no bracket.
    temp_str.assign(equ.begin(),equ.end());
    ans=cal_poly(temp_str);
    return ans;
}

string& Func::subs(string& equ, string& var, double* val) {
	//string equ = equ_argu;
	stringstream temp_buf;
	string str_var;
	size_t i, var_n = var.size();
	size_t equ_i, equ_len = equ.size();
	char var_cur;
	for (i = 0; i<var_n; i++) {
		temp_buf.clear();
		temp_buf << val[i];
		temp_buf >> str_var;
		//substituion
		var_cur = var.at(i);
		for (equ_i = 0; equ_i < equ_len; equ_i++) {
			if (equ.at(equ_i) == var_cur) {
				equ.replace(equ_i, 1, str_var);
			}
		}
	}
	return equ;
}

double Func::fx(string& equ_argu, string& var, double *val) {
	Expr expr;
	string equ(equ_argu);
	subs(equ, var, val);
	return expr.eval(equ);
}

double Func::fx(string& equ_argu, double x) {
	Expr expr;
	string equ(equ_argu), var("x");
	double val[1];
	val[0] = x;
	subs(equ, var, val);
	return expr.eval(equ);
}

double Func::limit(string& equ, double x) {
	return limit_fx(equ, x);
}

double  Func::diff(string& equ_argu, string& var, double *val_argu, unsigned int order) {
	return diff_2Points(equ_argu, var, val_argu, order);
};

double  Func::diff(string& equ_argu, double x, int order) {
    double fa, fb;
    Func func;
    if (order == 0) {
        return func.fx(equ_argu,x);
    }
    if (order == 1) {
        fa = func.fx(equ_argu, x + EPS);
        fb = func.fx(equ_argu, x);
        return (fa - fb) / EPS;
    }
    else if (order > 1) {
        fa = diff(equ_argu, x + EPS, order - 1);
        fb = diff(equ_argu, x, order - 1);
        return (fa - fb) / EPS;
    }
}

double Func::integral(string& equ, double lower, double upper) {
	return integral_romberg(equ, lower, upper);
}

double Func::diff_2Points(string& equ_argu, string& var, double *val_argu, unsigned int order) {
	size_t i, n = var.size();
	string equ_copy, equ(equ_argu);
	double val[MLen];
	double y1, y2;
	Expr expr;
	for (i = 0; i<n; i++) {
		val[i] = val_argu[i];
	}
	//derivative
	if (order == 0) {
		return fx(equ, var, val);
	}
	else if (order == 1) {
		equ_copy = equ;
		subs(equ, var, val);
		y1 = expr.eval(equ);
		val[n - 1] += EPS;
		subs(equ_copy, var, val);
		y2 = expr.eval(equ_copy);
		return (y2 - y1) / EPS;
	}
	else {
		y1 = diff_2Points(equ, var, val, order - 1);
		val[n - 1] += EPS;
		y2 = diff_2Points(equ, var, val, order - 1);
		return (y2 - y1) / EPS;
	}
}

double Func::limit_fx(string& equ, double x){
	double fa, fb, d;
	Func func;
	Limit_diffuse limit_diffuse;
	fa = func.fx(equ, x - EPS);
	fb = func.fx(equ, x + EPS);
	d = (fa>fb) ? (fa - fb) : (fb - fa);
	if (d < EPS) {
		return fb;
	}
	else {
		throw limit_diffuse;
	}
}

double Func::integral_romberg(string& equ, double lower, double upper) {
	int i, k, m, n;
	double h, x, s, p, q, ep;
	double y[8];
	Func func;
	//initial
	h = upper - lower;
	y[0] = h*(func.fx(equ, lower) + func.fx(equ, upper)) / 2.0;
	m = 1;
	n = 1;
	ep = EPS + 1.0;
	//iteration
	while ((ep >= EPS) && (m < 8))
	{
		p = 0.0;
		for (i = 0; i<n; i++)
		{
			x = lower + (i + 0.5)*h;
			p = p + func.fx(equ, x);
		}
		p = (y[0] + h*p) / 2.0;
		s = 1.0;
		for (k = 1; k <= m; k++)
		{
			s = 4.0*s;
			q = (s*p - y[k - 1]) / (s - 1.0);
			y[k - 1] = p;
			p = q;
		}

		p = fabs(q - y[m - 1]);
		m = m + 1;
		y[m - 1] = q;
		n = n + n; h = h / 2.0;
	}
	return q;
}

double Arithprog::at_gener(string& equ, int index) {
	Func func;
	size_t i, l = equ.size();
	for (i = 0; i<l; i++) {
		if (equ.at(i) == 'n') {
			equ.at(i) = 'x';
		}
	}
	return func.fx(equ, double(index));
}

double Arithprog::sum_gener(string& equ, int lower, int upper) {
	Func func;
	double sum = 0;
	int i;
	for (i = lower; i <= upper; i++) {
		sum += func.fx(equ, i);
	}
	return sum;
}

double Arithprog::limit_gener(string& equ) {
	Func func;
	double y, z, d;
	Limit_diffuse limit_diffuse;
	y = func.fx(equ, ITER_LIMIT * 100);
	z = func.fx(equ, ITER_LIMIT * 100 + 1);
	d = (y>z) ? (y - z) : (y + z);
	if (d < EPS) {
		return y;
	}
	else {
		throw limit_diffuse;
	}
}

double Arithprog::at_recur(string& equ, double* val_argu, size_t val_i, int n) { //index from 1
	double val[MLen] = { 0 };
	size_t i;
	for (i = 0; i < val_i; i++) {
		val[i] = val_argu[i];
	}
	return recur(equ, val, val_i, n - 1);
}

double Arithprog::sum_recur(string& equ, double* val_argu, size_t val_i, int lower, int upper) { //index from 1
	Arithprog prog;
	double sum = 0, val[MLen] = { 0 };
	size_t i;
	for (i = 0; i < val_i; i++) {
		val[i] = val_argu[i];
	}
	prog.recur(equ, val, val_i, upper);
	for (i = lower - 1; i < upper; i++) {
		sum += val[i];
	}
	return sum;
}

double Arithprog::limit_recur(string& equ, double* val_argu, size_t val_i) {
	Arithprog prog;
	Limit_diffuse limit_diffuse;
	double val[ITER_LIMIT + 2] = { 0 }, y, z, d;
	size_t i;
	for (i = 0; i < val_i; i++) {
		val[i] = val_argu[i];
	}
	prog.recur(equ, val, val_i, ITER_LIMIT);
	y = val[ITER_LIMIT];
	z = val[ITER_LIMIT - 1];
	d = (y>z) ? (y - z) : (z - y);
	if (d < EPS) {
		return y;
	}
	else {
		throw limit_diffuse;
	}
}

double Arithprog::recur(string& equ_argu, double *val_arr, size_t val_i, int n) { // index from 0
	size_t equ_i, brac_i, off, i;
	Brac_dismatch error_brac_dismatch;
	stringstream temp_buf;
	string equ, temp;
	double sum = 0;
	Expr expr;
	for (; val_i <= n; val_i++) {
		//reset equ
		equ = equ_argu;
		for (equ_i = 0; equ_i < equ.size(); equ_i++) {
			if (equ.at(equ_i) == 'a' || equ.at(equ_i) == 's') {
				// get off_set
				for (brac_i = equ_i; equ.at(brac_i) != ']' && equ.at(brac_i); brac_i++);
				if (brac_i == equ.size()) {
					throw error_brac_dismatch;
				}
				temp.assign(equ, equ_i + 4, brac_i - equ_i - 4);
				temp_buf.clear();
				temp_buf << temp;
				temp_buf >> off;
				// get  a[val_i-off]
				if (equ.at(equ_i) == 'a') {
					temp_buf.clear();
					temp_buf << val_arr[val_i - off];
					temp_buf >> temp;
				}
				else if (equ.at(equ_i) == 's') {
					for (i = sum = 0; i <= val_i - off; i++) {
						sum += val_arr[i];
					};
					temp_buf.clear();
					temp_buf << sum;
					temp_buf >> temp;
				}
				equ.replace(equ_i, brac_i + 1, temp);
			}
		}
		val_arr[val_i] = expr.eval(equ);
	}
	return val_arr[val_i - 1];
}

Solver::Solver() {
}

void Solver::calculate(QStringList cmdList) {
	//cmdList << State << Oper << equ << x << y;
	State state = State(cmdList.at(0).toInt());
	Oper  oper = Oper(cmdList.at(1).toInt());
	string equ = cmdList.at(2).toStdString();
	double x = cmdList.at(3).toDouble(), y = cmdList.at(4).toDouble();
	Expr expr;
	Func func;
	Arithprog prog;
	double ans = 0;

	try {
		switch (state){
		case ExprState:
			switch (oper) {
			case FxOper:
				ans = expr.eval(equ);
				emit calculated(ans);
				return;
			default:
				break;
			}
		case FuncState:
			switch (oper) {
			case FxOper:
				ans = func.fx(equ, x);
				emit calculated(ans);
				return;
			case DiffOper:
				ans = func.diff(equ, x, y);
				emit calculated(ans);
				return;
			case IntegralOper:
				ans = func.integral(equ, x, y);
				emit calculated(ans);
				return;
			case LimOper:
				ans = func.limit(equ, x);
				emit calculated(ans);
				return;
			default:
				break;
			}
		case GenerState:
			switch (oper)
			{
			case FxOper:
				ans = prog.at_gener(equ, x);
				emit calculated(ans);
				return;
			case IntegralOper:
				ans = prog.sum_gener(equ, x, y);
				return;
			case LimOper:
				ans = prog.limit_gener(equ);
				emit calculated(ans);
				return;
			default:
				break;
			}
		default:
			break;
		}
	}
	catch (Brac_dismatch) {
		emit dismatch(tr("Brackets dismatch! Please check your input."));
	}
	catch (Oper_dismatch) {
		emit dismatch(tr("Operators dismatch! Please check your input."));
	}
	catch (Limit_diffuse) {
		emit dismatch(tr("Limit Diffuse!"));
	}
}


void Solver::calculate(QStringList cmdList, QList<double> valArgu) {
	State state = State(cmdList.at(0).toInt());
	Oper  oper = Oper(cmdList.at(1).toInt());
	string equ = cmdList.at(2).toStdString();
	double x = cmdList.at(3).toDouble(), y = cmdList.at(4).toDouble();
	Arithprog prog;
	double ans = 0, val[MLen] = {0};
	int i, val_i = valArgu.size();

	for (i = 0; i < val_i; i++) {
		val[i] = valArgu.at(i);
	}

	try {
		if (state != RecurState) {
			return;
		}
		switch (oper) {
			case FxOper:
				ans = prog.at_recur(equ, val, val_i, x);
				emit calculated(ans);
				return;
			case IntegralOper:
				ans = prog.sum_recur(equ, val, val_i, x, y);
				emit calculated(ans);
				return;
			case LimOper:
				ans = prog.limit_recur(equ, val, val_i);
				emit calculated(ans);
				return;
			default:
				break;
		}
	}
	catch (Brac_dismatch) {
		emit dismatch(tr("Brackets dismatch! Please check your input."));
	}
	catch (Oper_dismatch) {
		emit dismatch(tr("Operators dismatch! Please check your input."));
	}
	catch (Limit_diffuse) {
		emit dismatch(tr("Limit Diffuse!"));
	}
}