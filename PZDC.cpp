// PZDC.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Parser.h"



int main()
{
	Scanner *SCANNNER = new Scanner(L"test.txt");
	Parser *PARCER = new Parser(SCANNNER);
	PARCER->Parse();
	Go(); // � ��� ������� ���� �������� ����������, ������������ �������� �����, ����� � ����� �� �������
	return 0; 
}

