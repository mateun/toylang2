#include "lexer.h"
#include <ctype.h>
#include <string.h>

static char numBufferStart[64];
static char* numBuf = numBufferStart;
static char idBufferStart[256];
static char* idBuf = idBufferStart;

static void resetNumBuffer() {
	numBuf = numBufferStart;
	memset(numBufferStart, 0, 64);
}

static void resetBuffer(char** buf, char* bufStart, 
							int size) {
	*buf = bufStart;
	memset(bufStart, 0, size);
}

enum CurrMultiCharType {
	NUMBER,
	IDENT
};

bool endIdString(std::string src, 
			int pos) {
	char next = src[pos+1];
	return (next == '-' || next == '+' 
			|| next == '=' || next == '/'
			|| next == '*' || isspace(next));
}

std::vector<Token> Lexer::lex(std::string source) {
	
	CurrMultiCharType currType = NUMBER;
	std::vector<Token> toks;
	int counter = 0;	
	printf("source length in bytes: %lu\n", source.size());
	printf("raw source: \n");
	printf("%s\n\n", source.c_str());

	for (char& c : source) {

		if (isspace(c)) {
			counter++;
			continue;
		}

		else if (isdigit(c)) {
			// Handle the case when we are 
			// getting a digit, but we are
			// currently within an ID string.
			if (currType == IDENT) {
				*idBuf = c;
				idBuf++;
				// If the ID string ends, 
				// spit out an ID token and
				// set the currType back to NUMBER.
				if (endIdString(source, counter)) {
					std::unique_ptr<std::string> id(
						new std::string(idBufferStart));
					printf("name: %s\n", id.get()->c_str());
					Token t = { ID, 0, std::move(id) };
					toks.push_back(std::move(t));
					currType = NUMBER;
					resetBuffer(&idBuf, idBufferStart, 256);	
				}
			}
			else {
				*numBuf = c;	
				numBuf++;
				// Look ahead to check if the 
				// next char is NOT a number.
				// If this is the case, end the 
				// number recording and spit out a
				// NUM token.
				if (!isdigit(source[counter+1])) {
					std::unique_ptr<int> num(
						new int(atoi(numBufferStart)));
					printf("number %d\n", *num);
					resetNumBuffer();		
					Token tok = { NUM, std::move(num) };
					toks.push_back(std::move(tok));		
				}
			}
					
		} 

		else if ('+' == c) {
			Token t = { PLUS };
			toks.push_back(std::move(t));
		}

		else if ('-' == c) {
			Token t = { MIN };
			toks.push_back(std::move(t));
		}

		else if ('/' == c) {
			Token t = { DIV };
			toks.push_back(std::move(t));
		}

		else if ('*' == c) {
			Token t = { MUL };
			toks.push_back(std::move(t));
		}

		else if ('=' == c) {
			Token t = { ASSIGN };
			toks.push_back(std::move(t));
		}

		else {
			currType = IDENT;
			*idBuf = c;
			idBuf++;
			// Check if the ID string should end
			if (endIdString(source, counter)) {
					std::unique_ptr<std::string> id(
						new std::string(idBufferStart));
					printf("name: %s\n", id.get()->c_str());
					Token t = { ID, 0, std::move(id) };
					toks.push_back(std::move(t));
					currType = NUMBER;
					resetBuffer(&idBuf, idBufferStart, 256);	
			}
		}
		counter++;
	}

	return toks;

}
