#include <stdio.h>
#include "globals.h"
#include "lexer.h"

std::string readSourceFromStdIn() {

	char bufStart[4000];
	char* buf = bufStart; 
	char c;
	while ((c = getchar()) != EOF) {
		*buf = c;
		buf++;	
	}
	return std::string(bufStart);
}

int main(int argc, char** args) {

	printf("invoking toycompiler version %d.%d.%d\n", 
		V_MAJ, V_MIN, V_PAT);		

	Lexer l;
	std::string source = readSourceFromStdIn();
	std::vector<Token> tokens =  
			l.lex(source);		
	for (auto& t : tokens) {
		printf("tok: %s", tokenById(t.type).c_str());			
		if (t.type == -1) {
			printf("=>%d\n", *(t.numAttr.get()));
		}
		else if (t.type == -7) {
			printf("=>%s\n", (t.nameAttr.get()->c_str()));
		}
		else printf("\n");
	}
	return 0;

}
