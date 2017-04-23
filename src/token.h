#pragma once
#include <memory>
#include <string>

enum TokenType {
	NUM = -1, 
	PLUS = -2,
	MIN = -3,	
	MUL = -4,
	DIV = -5,
	ASSIGN = -6,
	ID = -7
};

std::string tokenById(int id);

struct Token {
	TokenType type;
	std::unique_ptr<int> numAttr;		
	std::unique_ptr<std::string> nameAttr;
};


