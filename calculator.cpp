//#include "calculator.h"
//#include "pch.h"
//
//int priority(int state, char a)
//{
//	int rank;
//	switch (a) {
//	case '+':
//	case '-':
//		rank = 1;//+，-优先级为1。 
//		break;
//	case '*':
//	case '/':
//		rank = 2;//*，/优先级为2。 
//		break;
//	case '(':// 保证“（”直接入栈 ，也不会干扰其他运算符判断。 
//		if (state == 0)
//			rank = 3;
//		else
//			rank = 0;
//		break;
//	case '#':
//		rank = 0;//#表示结束。 
//		break;
//	default:
//		break;
//	}
//	return rank;
//}//priority函数主要来判断栈里面运算符的优先级。 
//
//double calculate(char op, double num1, double num2)
//{
//	double anwser;
//	switch (op) {
//	case '+':
//		anwser = num1 + num2;
//		break;
//	case '-':
//		anwser = num1 - num2;
//		break;
//	case '*':
//		anwser = num1 * num2;
//		break;
//	case '/':
//		anwser = num1 / num2;
//		break;
//	default:
//		break;
//	}
//	return anwser;
//}//calculate函数主要是实现两个数字的运算（包括加减乘除），以op来读取OP栈里面的运算符。 
//
//double result(string s, int a, int& sign)
//{
//	stack<char> OP;//定义OP栈来存放操作运算符。 
//	stack<double> OPND;//定义OPND来存放需要运算的数字（包括小数）。
//	int t = 0;
//	for (int i = 0; i < a; i++) {
//		if (isdigit(s[i])) {
//			t++;
//		}
//	}
//	if (t == 0) {
//		sign = 0;
//		return 0;
//	}
//	if (s[0] == '*' || s[0] == '/' || s[0] == '.') {
//		sign = 0;
//		return 0;
//	}
//	OP.push('#');//先在运算符的栈之中放入一个中止运算符。 
//	OPND.push(0);
//	string num;//用来保存一个完整的运算数字。 
//	int j = 0, k = 0;
//	for (int i = 0; i < a; i++) {//判断运算式是否合法。
//		if (s[i] == '(') {
//			j++;
//		}
//		if (s[i] == ')') {
//			k++;
//		}
//		if (!isdigit(s[i])) {
//			if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '(' && s[i] != ')' && s[i] != '.' && s[i] != '=') {//判断运算式是否合法。
//				sign = 0;
//				return 0;
//			}
//		}
//		if (s[i] == '.')
//		{
//			int v, w;
//			v = i + 1;
//			w = v;
//			if (s[v] != '+' && s[v] != '-' && s[v] != '*' && s[v] != '/' && s[v] != '(' && s[v] != ')' && s[v] != '#' && s[v] != '=') {
//				v++;
//			}
//			for (w; w <= v; w++) {
//				if (s[w] == '.') {
//					sign = 0;
//					break;
//				}
//			}
//		}
//	}
//	if (j != k) {//判断括号个数是否匹配。
//		sign = 0;
//		return 0;
//	}
//	else {
//		for (int i = 0; i < a; i++) {//读取整个s字符串。
//			if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') && (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/'))//判断是不是合法。
//			{
//				sign = 0;
//				break;
//			}
//			if (isdigit(s[i])) {//判断是否为0到9的数字。 
//				while (isdigit(s[i]) || (s[i] == '.')) {
//					num.push_back(s[i]);//判断输入小数点之后，在末尾增加一个小数点。 
//					i++;//继续后移一位，读入小数点后面的部分。 
//				}
//				double a = atof(num.c_str());//把上面读取出来的整个数字字符串转化为双精度类型的数字赋值给a。 
//				OPND.push(a);// 将a这个数字放入OPND的栈之中。 
//				num.clear();//清除num中的数字。 
//				i--;//后移一位。 
//			}
//			else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(') {
//				if (s[i] == '(') {
//					if (s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '.') {
//						sign = 0;
//						break;
//					}
//					if (s[i + 1] == '-')
//						OPND.push(0);
//				};
//				if (priority(0, s[i]) > priority(1, OP.top()))//比较字符串s中的运算符优先级和OP栈中的优先级，大则入栈。 
//					OP.push(s[i]);
//				else {
//					while (priority(0, s[i]) <= priority(1, OP.top())) {
//						char temp = OP.top();//定义temp保存OP栈顶运算符。 
//						OP.pop();//弹出栈顶 
//						double op2 = OPND.top();//将OPND栈顶的数字赋值给op2（由于先进后出原则，必须赋值给op2保证运算顺序）。
//						OPND.pop();//弹出栈顶 
//						double op1 = OPND.top();//取出OPND当前栈顶的数字，进行下一步的运算。
//						OPND.pop(); //弹出栈顶 
//						if (op2 == 0 && temp == '/') {
//							sign = 0;
//						}
//						OPND.push(calculate(temp, op1, op2));//将计算结果入栈。 
//					}
//					OP.push(s[i]);
//				}
//			}
//			else if (s[i] == ')') {
//				while (OP.top() != '(') {//取出操作，直到将取出OP栈中的“（”为止。 
//					char temp = OP.top();
//					OP.pop();
//					double op2 = OPND.top();
//					OPND.pop();
//					double op1 = OPND.top();
//					OPND.pop();
//					if (op2 == 0 && temp == '/') {
//						sign = 0;
//					}
//					OPND.push(calculate(temp, op1, op2));
//				}
//				OP.pop();//弹出“）” ，结束。 
//			}//上面的操作已经判断过优先级，所以括号里的数字可以直接计算，无需重复判断。
//		}
//		while (OP.top() != '#') {
//			char temp = OP.top();
//			OP.pop();
//			double op2 = OPND.top();
//			OPND.pop();
//			double op1 = OPND.top();
//			OPND.pop();
//			if (op2 == 0 && temp == '/') {
//				sign = 0;
//			}
//			OPND.push(calculate(temp, op1, op2));
//		}//将栈中的运算符全部取出来，计算完成全部表达式，将值再一次放回OPND栈中。 
//		return OPND.top();;//此时结果OPND栈顶的结果就是整个表达式的结果。 
//	}
//}
//
