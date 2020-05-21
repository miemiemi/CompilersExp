#include "stdafx.h"
#include "Parser.h"

//符号栈和语法树栈的初始化
Parser::Parser() {
	stack<Symbol> symbol;
	this->symbol = symbol;
	stack<TreeNode**> tree;
	this->tree = tree;
	stack<TreeNode*> opstack;
	this->opstack = opstack;
	stack<TreeNode*> numstack;
	this->numstack = numstack;
}

void Parser::Parse(vector<Token>& Tokenlist)
{
	this->Error = false;
	int t[67][42];
	LL1_init(t);
	this->symbol.push(Program);//可以直接压入vt或lextape，会自动调用构造函数
	this->root = new TreeNode(1, ProK);
	this->tree.push(&(this->root->child[2]));
	this->tree.push(&(this->root->child[1]));
	this->tree.push(&(this->root->child[0]));

	std::vector<Token>::iterator Tokeniterator = Tokenlist.begin();
	while (Tokeniterator != Tokenlist.end() && this->Error == false) {
		Token token = *Tokeniterator;
		this->lineno = token.line;
		int lineno = token.line;
		if (this->symbol.empty()) {
			if (token.type == ENDFILE) {
				cout << "语法分析结束，未发现错误" << endl;
				exit(0);
			}
			else {
				cout << "行数：" << lineno << "文件提前结束" << endl;
				this->Error = true;
			}
		}
		else
		{	//当前栈顶为终极符
			Symbol curSym = this->symbol.top();
			if (curSym.vt == vt_uninit) {
				if (curSym.lex == token.type) {
					this->symbol.pop();
					Tokeniterator++;			//读取下一个token
				}
				else {
					cout << "行数：" << lineno << "    非期望单词错" << endl;
					this->Error = true;
				}
			}
			//当前栈顶为非终极符
			else {
				this->symbol.pop();
				int pnum = t[curSym.vt][token.type];
				if (pnum == -1) {
					cout << "行数：" << lineno << "    没有相应产生式，错误" << endl;
					this->Error = true;
				}
				predict(pnum);
			}
		}

	}

	if (Tokeniterator == Tokenlist.end()&& this->Error == false)
		cout << "行数：" << lineno << "    Token遍历完成" << endl;
	
}

void Parser::predict(int pnum) {
	
	if (pnum == 1)
		process1();
	else if (pnum == 2)
		process2();
	else if (pnum == 3)
		process3();
	else if (pnum == 4)
		process4();
	else if (pnum == 5)
		process5();
	else if (pnum == 6)
		process6();
	else if (pnum == 7)
		process7();
	else if (pnum == 8)
		process8();
	else if (pnum == 9)
		process9();
	else if (pnum == 10)
		process10();
	else if (pnum == 11)
		process11();
	else if (pnum == 12)
		process12();
	else if (pnum == 13)
		process13();
	else if (pnum == 14)
		process14();
	else if (pnum == 15)
		process15();
	else if (pnum == 16)
		process16();
	else if (pnum == 17)
		process17();
	else if (pnum == 18)
		process18();
	else if (pnum == 19)
		process19();
	else if (pnum == 20)
		process20();
	else if (pnum == 21)
		process21();
	else if (pnum == 22)
		process22();
	else if (pnum == 23)
		process23();
	else if (pnum == 24)
		process24();
	else if (pnum == 25)
		process25();
	else if (pnum == 26)
		process26();
	else if (pnum == 27)
		process27();
	else if (pnum == 28)
		process28();
	else if (pnum == 29)
		process29();
	else if (pnum == 30)
		process30();
	else if (pnum == 31)
		process31();
	else if (pnum == 32)
		process32();
	else if (pnum == 33)
		process33();
	else if (pnum == 34)
		process34();
	else if (pnum == 35)
		process35();
	else if (pnum == 36)
		process36();
	else if (pnum == 37)
		process37();
	else if (pnum == 38)
		process38();
	else if (pnum == 39)
		process39();
	else if (pnum == 40)
		process40();
	else if (pnum == 41)
		process41();
	else if (pnum == 42)
		process42();
	else if (pnum == 43)
		process43();
	else if (pnum == 44)
		process44();
	else if (pnum == 45)
		process45();
	else if (pnum == 46)
		process46();
	else if (pnum == 47)
		process47();
	else if (pnum == 48)
		process48();
	else if (pnum == 49)
		process49();
	else if (pnum == 50)
		process50();
	else if (pnum == 51)
		process51();
	else if (pnum == 52)
		process52();
	else if (pnum == 53)
		process53();
	else if (pnum == 54)
		process54();
	else if (pnum == 55)
		process55();
	else if (pnum == 56)
		process56();
	else if (pnum == 57)
		process57();
	else if (pnum == 58)
		process58();
	else if (pnum == 59)
		process59();
	else if (pnum == 60)
		process60();
	else if (pnum == 61)
		process61();
	else if (pnum == 62)
		process62();
	else if (pnum == 63)
		process63();
	else if (pnum == 64)
		process64();
	else if (pnum == 65)
		process65();
	else if (pnum == 66)
		process66();
	else if (pnum == 67)
		process67();
	else if (pnum == 68)
		process68();
	else if (pnum == 69)
		process69();
	else if (pnum == 70)
		process70();
	else if (pnum == 71)
		process71();
	else if (pnum == 72)
		process72();
	else if (pnum == 73)
		process73();
	else if (pnum == 74)
		process74();
	else if (pnum == 75)
		process75();
	else if (pnum == 76)
		process76();
	else if (pnum == 77)
		process77();
	else if (pnum == 78)
		process78();
	else if (pnum == 79)
		process79();
	else if (pnum == 80)
		process80();
	else if (pnum == 81)
		process81();
	else if (pnum == 82)
		process82();
	else if (pnum == 83)
		process83();
	else if (pnum == 84)
		process84();
	else if (pnum == 85)
		process85();
	else if (pnum == 86)
		process86();
	else if (pnum == 87)
		process87();
	else if (pnum == 88)
		process88();
	else if (pnum == 89)
		process89();
	else if (pnum == 90)
		process90();
	else if (pnum == 91)
		process91();
	else if (pnum == 92)
		process92();
	else if (pnum == 93)
		process93();
	else if (pnum == 94)
		process94();
	else if (pnum == 95)
		process95();
	else if (pnum == 96)
		process96();
	else if (pnum == 97)
		process97();
	else if (pnum == 98)
		process98();
	else if (pnum == 99)
		process99();
	else if (pnum == 100)
		process100();
	else if (pnum == 101)
		process101();
	else if (pnum == 102)
		process102();
	else if (pnum == 103)
		process103();
	else if (pnum == 104)
		process104();
}

int Parser::Priosity(LexType op) {
	if (op == END)
		return 0;
	else if (op == EQ || op == LT)
		return 1;
	else if (op == PLUS || op == MINUS)
		return 2;
	else if (op == TIMES || op == OVER)
		return 3;
	else
		return -1;
}

//产生式： <Program>  :: = ProgramHead  DeclarePart  ProgramBody
void Parser::process1()
{
	symbol.push(DOT);
	symbol.push(ProgramBody);
	symbol.push(DeclarePart);
	symbol.push(ProgramHead);

}

//产生式：<ProgramHead>  ::= PROGRAM ProgramName 
void Parser::process2()
{
	symbol.push(ProgramName);
	symbol.push(PROGRAM);
	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno,PheadK);
	*(t) = currentP;
}

//产生式： <ProgramName> ::=  ID;   
void Parser::process3()
{
	symbol.push(ID);

	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}

//产生式： <DeclarePart> ::= TypeDec  VarDec  FuncDec 
void Parser::process4()
{
	symbol.push(ProcDec);
	symbol.push(VarDec);
	symbol.push(TypeDec);
}

//产生式： <TypeDec> :: = ε
void Parser::process5()
{
	//空函数
}
//产生式： <TypeDec> ::= TypeDeclaration 
void Parser::process6()
{
	symbol.push(TypeDeclaration);	
}

//产生式： <TypeDeclaration> :: = TYPE TypeDecList
void Parser::process7()
{
	symbol.push(TypeDecList);
	symbol.push(TYPE);


	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, TypeK); /*生成Type作为标志的结点，它的子结点都是类型声明*/
	(*t) = currentP;							 /*头结点的兄弟结点指针指向此结点*/
	tree.push(&((*currentP).sibling));			/* 压入指向变量声明节点的指针*/
	tree.push(&((*currentP).child[0]));			 /*压入指向第一个类型声明节点的指针*/
}
//产生式： <TypeDecList> ::= TypeId = TypeDef ; TypeDecMore 
void Parser::process8()
{
	symbol.push(TypeDecMore);
	symbol.push(SEMI);
	symbol.push(TypeName);
	symbol.push(EQ);
	symbol.push(TypeId);

	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK); /*生成一个表示类型声明的结点，不添任何信息*/

	(*t) = currentP;			 /*若是第一个，则是Type类型的子结点指向当前结点， 否则，是上一个类型声明的兄弟结点*/

	tree.push(&((*currentP).sibling));
}
//产生式：<TypeDecMore> :: = ε
void Parser::process9()
{
	tree.pop();					/*没有其它的类型声明，这时语法树栈顶存放的是最后一个类型声明节点的兄弟节点，弹出*/
}
//产生式： <TypeDecMore> ::=  TypeDecList  
void Parser::process10()
{
	symbol.push(TypeDecList);
}

//产生式： <TypeId >  ::=  ID 
void Parser::process11()
{
	symbol.push(ID);

	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;

}
//产生式： <TypeDef> ::=  BaseType 
void Parser::process12()
{
	symbol.push(BaseType);

	/*由于数组基类型的问题，这里不能直接用currentP->kind.dec=IntegerK; 而应该这么做，以适应所有情形*/
	this->dectemp = &(currentP->kind.dec);

}
//产生式： <TypeDef > ::=   StructureType 
void Parser::process13()
{
	symbol.push(StructureType);
}

//产生式： <TypeDef> ::=  ID 
void Parser::process14()
{
	symbol.push(ID);

	/*声明的类型部分为类型标识符*/
	(*currentP).kind.dec = IdK;
	currentP->type_name = currentToken.content;
}

//产生式：  <BaseType> :: = INTEGER
void Parser::process15()
{
	symbol.push(INTEGER);

	/*声明的类型部分为整数类型*/
	(*this->dectemp) = IntegerK;
}

//产生式： <BaseType> ::=   CHAR 
void Parser::process16()
{
	symbol.push(CHAR);

	/*声明的类型部分为整数类型*/
	(*this->dectemp) = CharK;
}
//产生式： <StructureType> :: = ArrayType
void Parser::process17()
{
	symbol.push(ArrayType);
}
//产生式：  <StructureType> ::= RecType  
void Parser::process18()
{
	symbol.push(RecType);
}
//产生式： <ArrayType> ::= ARRAY [low..top ] OF BaseType 
void Parser::process19()
{
	symbol.push(BaseType);
	symbol.push(OF);
	symbol.push(RMIDPAREN);
	symbol.push(Top);
	symbol.push(UNDERANGE);
	symbol.push(Low);
	symbol.push(LMIDPAREN);
	symbol.push(ARRAY);

	/*声明的类型为数组类型*/
	(*currentP).kind.dec = ArrayK;

	dectemp = &(currentP->attr.arrayAttr.childType);
}

//产生式： <Low>   ::=  INTC  
void Parser::process20()
{
	symbol.push(INTC);

	/*存储数组的下界*/
	(*currentP).attr.arrayAttr.low = std::stoi(currentToken.content);
}
//产生式： <Top>  ::=  INTC  
void Parser::process21()
{
	symbol.push(INTC);

	/*存储数组的上界*/
	(*currentP).attr.arrayAttr.up = std::stoi(currentToken.content);

}
//产生式： <RecType > ::=  RECORD  FieldDecList  END 
void Parser::process22()
{

}

void Parser::process23()
{

}

void Parser::process24()
{

}

void Parser::process25()
{

}

void Parser::process26()
{

}

void Parser::process27()
{

}

void Parser::process28()
{

}

void Parser::process29()
{

}

void Parser::process30()
{

}

void Parser::process31()
{

}

void Parser::process32()
{

}

void Parser::process33()
{

}

void Parser::process34()
{

}

void Parser::process35()
{

}

void Parser::process36()
{

}

void Parser::process37()
{

}

void Parser::process38()
{

}

void Parser::process39()
{

}

void Parser::process40()
{

}

void Parser::process41()
{

}

void Parser::process42()
{

}

void Parser::process43()
{

}

void Parser::process44()
{

}

void Parser::process45()
{

}

void Parser::process46()
{

}

void Parser::process47()
{

}

void Parser::process48()
{

}

void Parser::process49()
{

}

void Parser::process50()
{

}

void Parser::process51()
{

}

void Parser::process52()
{

}

void Parser::process53()
{

}

void Parser::process54()
{

}

void Parser::process55()
{

}

void Parser::process56()
{

}

void Parser::process57()
{

}

void Parser::process58()
{

}

void Parser::process59()
{

}

void Parser::process60()
{

}

void Parser::process61()
{

}

void Parser::process62()
{

}

void Parser::process63()
{

}

void Parser::process64()
{

}

void Parser::process65()
{

}

void Parser::process66()
{

}

void Parser::process67()
{

}

void Parser::process68()
{

}

void Parser::process69()
{

}

void Parser::process70()
{

}

void Parser::process71()
{

}

void Parser::process72()
{

}

void Parser::process73()
{

}

void Parser::process74()
{

}

void Parser::process75()
{

}

void Parser::process76()
{

}

void Parser::process77()
{

}

void Parser::process78()
{

}

void Parser::process79()
{

}

void Parser::process80()
{

}

void Parser::process81()
{

}

void Parser::process82()
{

}

void Parser::process83()
{

}

void Parser::process84()
{

}

void Parser::process85()
{

}

void Parser::process86()
{

}

void Parser::process87()
{

}

void Parser::process88()
{

}

void Parser::process89()
{

}

void Parser::process90()
{

}

void Parser::process91()
{

}

void Parser::process92()
{

}

void Parser::process93()
{

}

void Parser::process94()
{

}

void Parser::process95()
{

}

void Parser::process96()
{

}

void Parser::process97()
{

}

void Parser::process98()
{

}

void Parser::process99()
{

}

void Parser::process100()
{

}

void Parser::process101()
{

}

void Parser::process102()
{

}

void Parser::process103()
{

}

void Parser::process104()
{

}