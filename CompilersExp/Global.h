#pragma once
/********************** ���ʵĴʷ����� ********************/
typedef enum
{
	/* ���ǵ��ʷ��� */
	ENDFILE, ERROR,
	/* ������ */
	PROGRAM, PROCEDURE, TYPE, VAR, IF,
	THEN, ELSE, FI, WHILE, DO,
	ENDWH, BEGIN, END, READ, WRITE,
	ARRAY, OF, RECORD, RETURN,

	INTEGER, CHAR,
	/* ���ַ����ʷ��� */
	ID, INTC, CHARC,
	/*������� */
	ASSIGN, EQ, LT, PLUS, MINUS,
	TIMES, OVER, LPAREN, RPAREN, DOT,
	COLON, SEMI, COMMA, LMIDPAREN, RMIDPAREN,
	UNDERANGE
}LexType;

