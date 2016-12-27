// PZDC.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "Parser.h"



int main()
{
	Scanner *SCANNNER = new Scanner(L"test.txt");
	Parser *PARCER = new Parser(SCANNNER);
	PARCER->Parse();
	Go(); // в эту функцию надо написать заклинани€, заставл€ющие работать точки, ребра и вывод на консоль
	return 0; 
}

