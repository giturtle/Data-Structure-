#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//创建一个空栈S
void InitStack(SqStack &S) {
	//创建一个空栈S
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) {
		exit(-1);	//动态内存分配失败
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 0;
}

void GetTop(SqStack S, SElemType &e) {
	//若栈不空，则用e返回S的栈顶元素，并返回0，否则返回-1
	if (S.top == S.base) {
		return -1;
	}
	e = *(S.top - 1);
	return 0;
}


//插入元素e为新的栈顶元素
void Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {	//栈满，追加存储空间
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) {
			exit(-1);		//储存分配失败
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 0;
}

void Pop(SqStack &S, SElemType &e) {
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回0，否则返回-1
	if (S.top == S.base) {
		return -1;
	}
	e = *--S.top;	//立即向回步进一步，将内容赋予e变量
	return 0;
}
