#pragma once
#include <vector>
#include <string>
#include "token.h"

class Lexer {

public:
	virtual ~Lexer() {}
	
	std::vector<Token> lex(std::string source);
	

};
