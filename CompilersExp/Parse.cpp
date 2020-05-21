#include "stdafx.h"
#include"Parse.h"

//符号栈和语法树栈的初始化
Parse::Parse() {
	stack<Symbol> symbol;
	this->symbol = symbol;
	stack<TreeNode*> tree;
	this->tree = tree;
}

void Parse::predict(int pnum) {
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

int Parse::Priosity(LexType op) {
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

void Parse::process1()
{

}

void Parse::process2()
{

}

void Parse::process3()
{

}

void Parse::process4()
{

}

void Parse::process5()
{

}

void Parse::process6()
{

}

void Parse::process7()
{

}

void Parse::process8()
{

}

void Parse::process9()
{

}

void Parse::process10()
{

}

void Parse::process11()
{

}

void Parse::process12()
{

}

void Parse::process13()
{

}

void Parse::process14()
{

}

void Parse::process15()
{

}

void Parse::process16()
{

}

void Parse::process17()
{

}

void Parse::process18()
{

}

void Parse::process19()
{

}

void Parse::process20()
{

}

void Parse::process21()
{

}

void Parse::process22()
{

}

void Parse::process23()
{

}

void Parse::process24()
{

}

void Parse::process25()
{

}

void Parse::process26()
{

}

void Parse::process27()
{

}

void Parse::process28()
{

}

void Parse::process29()
{

}

void Parse::process30()
{

}

void Parse::process31()
{

}

void Parse::process32()
{

}

void Parse::process33()
{

}

void Parse::process34()
{

}

void Parse::process35()
{

}

void Parse::process36()
{

}

void Parse::process37()
{

}

void Parse::process38()
{

}

void Parse::process39()
{

}

void Parse::process40()
{

}

void Parse::process41()
{

}

void Parse::process42()
{

}

void Parse::process43()
{

}

void Parse::process44()
{

}

void Parse::process45()
{

}

void Parse::process46()
{

}

void Parse::process47()
{

}

void Parse::process48()
{

}

void Parse::process49()
{

}

void Parse::process50()
{

}

void Parse::process51()
{

}

void Parse::process52()
{

}

void Parse::process53()
{

}

void Parse::process54()
{

}

void Parse::process55()
{

}

void Parse::process56()
{

}

void Parse::process57()
{

}

void Parse::process58()
{

}

void Parse::process59()
{

}

void Parse::process60()
{

}

void Parse::process61()
{

}

void Parse::process62()
{

}

void Parse::process63()
{

}

void Parse::process64()
{

}

void Parse::process65()
{

}

void Parse::process66()
{

}

void Parse::process67()
{

}

void Parse::process68()
{

}

void Parse::process69()
{

}

void Parse::process70()
{

}

void Parse::process71()
{

}

void Parse::process72()
{

}

void Parse::process73()
{

}

void Parse::process74()
{

}

void Parse::process75()
{

}

void Parse::process76()
{

}

void Parse::process77()
{

}

void Parse::process78()
{

}

void Parse::process79()
{

}

void Parse::process80()
{

}

void Parse::process81()
{

}

void Parse::process82()
{

}

void Parse::process83()
{

}

void Parse::process84()
{

}

void Parse::process85()
{

}

void Parse::process86()
{

}

void Parse::process87()
{

}

void Parse::process88()
{

}

void Parse::process89()
{

}

void Parse::process90()
{

}

void Parse::process91()
{

}

void Parse::process92()
{

}

void Parse::process93()
{

}

void Parse::process94()
{

}

void Parse::process95()
{

}

void Parse::process96()
{

}

void Parse::process97()
{

}

void Parse::process98()
{

}

void Parse::process99()
{

}

void Parse::process100()
{

}

void Parse::process101()
{

}

void Parse::process102()
{

}

void Parse::process103()
{

}

void Parse::process104()
{

}