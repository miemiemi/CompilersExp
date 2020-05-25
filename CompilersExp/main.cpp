#include "stdafx.h"
#include <iostream>
#include "TokenScanner.h"
#include "Parser.h"

static string �ʷ�����[100] = { "ENDFILE", "ERROR" ,
"PROGRAM", "PROCEDURE", "TYPE", "VAR", "IF",
"THEN", "ELSE"," FI", "WHILE", "DO",
"ENDWH", "BEGIN", "END", "READ", "WRITE",
"ARRAY", "OF", "RECORD", "RETURN",
"INTEGER", "CHAR",
/* ���ַ����ʷ��� */
"ID", "INTC","CHARC",
/*������� */
"ASSIGN", "EQ", "LT", "PLUS", "MINUS",
"TIMES", "OVER"," LPAREN", "RPAREN", "DOT",
"COLON", "SEMI","COMMA"," LMIDPAREN", "RMIDPAREN",
"UNDERANGE"
};


int main()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\miemiemie\\Desktop\\ʵ�鱨��\\SNL��������\\һ������\\C4.txt", "r")) == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1);
	}

	TokenScanner* TScanner = new TokenScanner();	// �ʷ��������ֵ�Scanner
	vector<Token> Tokenlist;						//�洢Token����
	Token* newtoken = NULL;
	while (!feof(fp))
	{
		newtoken = TScanner->Scan(fp);
		Tokenlist.push_back(*newtoken);
		if (TScanner->Error == true) {
			cout << "Error token  " << newtoken->content << endl;
			exit(1);
		}
		newtoken = NULL;
	}
	fclose(fp);
	if (Tokenlist.back().type == DOT) {
		Token* endfileTolen = new Token();
		endfileTolen->line = TScanner->Line;
		endfileTolen->content = "";
		endfileTolen->type = ENDFILE;
		Tokenlist.push_back(*endfileTolen);
	}
	for (Token t : Tokenlist) {
		if (t.type == ID)
			cout << "����: " << t.line << "    " << t.type << "     " << t.content << endl;
		else
			cout << "����: " << t.line << "    " << t.type << "     " << �ʷ�����[t.type] << endl;
	}

	Parser* parser = new Parser();
	parser->Parse(Tokenlist);
	parser->PrintTree(parser->root);
	return 0;
}
