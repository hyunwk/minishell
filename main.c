#include "get_next_line/get_next_line.h"
#include <stdio.h>

void set_env(int argc, char **argv, char **envp)
{
	printf("set env\n");
}

void set_signal(void)
{
	// signal handler 구현
	// Ctrl + C
	// Ctrl + D
	// Ctrl + \ 구현
}

int check_valid(char *line)
{
	return 1;
}

char *tokenize(char *line)
{
	printf("split line %s\n", line);
	return line;
}

char *parse(char *token)
{
	return token;
}

int execute(char *parsed)
{
	if (parsed == "builltin" || parsed == "redirection")
	{
		printf("builtin, redirection 처리\n");

		if (parsed == "exit")
		{
			printf("exit\n");
		}
		return 1;
	}

	if (parsed == 'pipe')
	{
		printf("pipe 처리\n");
		return 1;
	}

	if (parsed == "default function")
	{
		printf("프로그램 명령어 (bin or ls..) 처리\n");
		return 1;
	}
}

void loop(void)
{
	int status;
	char *line;	  // input 값 저장
	char *parsed; // 자료형 변경
	char *tokens; // 자료형 변경

	status = 1;

	while (status)
	{
		printf("minishell > ");	 // prompt 출력
		get_next_line(1, &line); // line에 입력받은 값 저장

		if (check_valid(line)) // 입력 값 오류 체크. eof, whitespaces, null 등
		{
			tokens = tokenize(line);  // TOKENIZER + LEXER : 문장을 명령문으로 tokenize
			parsed = parse(tokens);	  // PARSER : tree 구조로 return
			status = execute(parsed); // EXECUTOR : 프로세스 생성. pipe, redirection 처리
		}

		free(line);
		// free(tokens);
		// free(parsed);
	}
}

int main(int argc, char **argv, char **env)
{
	// 환경변수 전역 구현
	set_env(argc, argv, env);

	// keyboard interrupt 구현
	set_signal();

	// shell feature : input, parse, execute
	loop();
}