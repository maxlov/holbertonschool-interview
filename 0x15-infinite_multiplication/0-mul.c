#include <stdlib.h>
#include <stdio.h>

#include "holberton.h"

/**
 * exit_with_error - Prints out error and exits with status code
 * @code: code to exit with
 * Return: Exits the program
 */
void exit_with_error(int code)
{
	char *msg = "Error\n";
	int i = 0;

	for (i = 0; msg[i] != '\0'; i++)
		_putchar(msg[i]);
	exit(code);
}

/**
 * _strlen - My implementation of str len
 * @string: string to get size of
 * Return: Size of string in int
 */
int _strlen(char *string)
{
	int size = 0;

	for (size = 0; string[size] != '\0'; size++)
		continue;
	return (size + 1);
}

/**
 * rev_string - reverse string
 * @s: a string
 *
 * Return: nothing
 */
char *rev_string(char *s)
{
	int length = -1;
	int pos;
	char temp;
	char *copy = s;

	pos = 0;
	while (*copy++)
		length++;
	while (pos <= length)
	{
		temp = s[pos];
		s[pos] = s[length];
		s[length] = temp;
		pos++;
		length--;
	}
	return (s);
}

/**
 * main - Entry point. Prints mul of two numbers
 * @argc: count of args
 * @argv: list of args
 * Return: On success 0
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *answer;
	int len_num1, len_num2, digit1, digit2, product, i, j, carry = 0;
	int zeros, flag = 0;

	if (argc != 3)
		exit_with_error(98);
	num1 = rev_string(argv[1]);
	num2 = rev_string(argv[2]);
	len_num1 = _strlen(num1);
	len_num2 = _strlen(num2);
	answer = malloc(sizeof(char) * (len_num1 + len_num2 - 1));
	if (answer == NULL)
		exit(98);
	for (i = 0; i < len_num1 + len_num2 - 1; i++)
		answer[i] = '0';
	answer[i] = '\0';
	for (i = 0; num2[i] != '\0'; i++)
	{
		digit2 = num2[i] - '0';
		for (j = 0; num1[j] != '\0'; j++)
		{
			digit1 = num1[j] - '0';
			zeros = i + j;
			carry = answer[zeros] - '0';
			product = (digit1 * digit2) + carry;
			answer[zeros] = (product % 10) + '0';
			answer[zeros + 1] += product / 10;
		}
	}
	for (i = len_num1 + len_num2 - 2; i >= 0; i--)
		if (answer[i] != '0' || flag)
		{
			_putchar(answer[i]);
			flag = 1;
		}
	_putchar('\n');
	free(answer);
	return (0);
}
