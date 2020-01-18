//The function required
ElementType EvalPostfix( char *expr ){
    int isnegative = 0;
	int isdominal = 0;
	double integer = 0;
    double dominal = 0;
    double number = 0;
    double calculate[30];
    double op1;
    double op2;
    double watch = 0;
    int i = 0;
    double watch2 = 0;
    while(1){
        watch2 = *expr;
		if((*expr > '0' && *expr < '9') || (*expr == '-' && *(expr+1) > '0' && *(expr) < '9')){
            if(*expr == '-'){
                isnegative = 1;
                expr++;
            }
            integer = *expr - '0';
            expr++;
            while(*expr != ' '){
                watch = *expr;
                if(*expr == '.'){
                    isdominal = 1;
                    expr++;
                }
                if(*expr < '0' || *expr > '9')  break;
                if(isdominal == 0){
                    integer = integer*10 + *expr - '0';
                }
                else if(isdominal > 0){
                    dominal += (*expr - '0')*pow(10,-1*isdominal);
                    isdominal++;
                }
                expr++;
            }
            number = integer + dominal;
            if(isnegative)  number *= -1;
            calculate[i++] = number;
            isdominal = 0;
            isnegative = 0;
            integer = 0;
            number = 0;
            dominal = 0;
        }
        else if(*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/'){
            op2 = calculate[--i];
            op1 = calculate[--i];
            switch(*expr){
                case '+':calculate[i++] = op1 + op2;break;
                case '-':calculate[i++] = op1 - op2;break;
                case '*':calculate[i++] = op1 * op2;break;
                case '/':if(op2 == 0)   return Infinity;calculate[i++] = op1 /op2;break;
            }
            expr++;
        }
        else if(*expr == ' ')	expr++;
        else	break;
    }
    if(i != 1)  return Infinity;
    return calculate[0];
}
