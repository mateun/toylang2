#include "token.h"

std::string tokenById(int id) {
	switch(id) {
		case -1: return "NUM";
		case -2: return "PLUS";
		case -3: return "MIN";
		case -4: return "MUL";
		case -5: return "DIV";
		case -6: return "ASSIGN";
		case -7: return "ID";

	}
}
