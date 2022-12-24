#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LEN 18
#define MAX_STR_LEN 256
#define NOT_DIG -1
#define SUCCESS 0
#define STR_LEN_ERR 1

int read_line(char *str, int *str_len);
void split_string(char *p_str, char words[][MAX_WORD_LEN], int *count_words);
void make_new_str(char words[][MAX_WORD_LEN], char *new_str, int *count_words);
int matches_format(char *line);
void compare_str(char *str, char *new_str);

int main(void)
{
    char str[MAX_STR_LEN + 1] = { '\0' };
    char words[MAX_STR_LEN + 1][MAX_WORD_LEN] = { '\0' };
    char new_str[MAX_STR_LEN + 1] = { '\0' };
    char *p_str = str;
    int str_len, count_words = 0;
    int rc;

    rc = read_line(str, &str_len);

    if (rc == STR_LEN_ERR)
    {
        //printf("ERROR: Длина строки превышает допустимое значение\n");
        return STR_LEN_ERR;
    }
    
    split_string(p_str, words, &count_words);

    if (count_words != 4)
    {
        printf("NO\n");
        return SUCCESS;
    }

    make_new_str(words, new_str, &count_words);
    compare_str(str, new_str);

    return SUCCESS;
}

int read_line(char *str, int *str_len)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i <= MAX_STR_LEN - 1)
            str[i++] = ch;
        else 
            return STR_LEN_ERR;
    }

    str[i] = '\0';
  
    *str_len = i;

    return SUCCESS;
}

void split_string(char *p_str, char words[][MAX_WORD_LEN], int *count_words)
{
    int i = 0, j = 0;
    int flag = 1;

    while (*p_str != '\0') 
    {
        if (*p_str == '.' || isspace(*p_str) != 0)
            flag = 0;
        if (flag)
            words[i][j++] = *p_str;
        else
        {
            if (j > 0)
            {
                words[i++][j++] = '\0';
                (*count_words)++;
                j = 0;
            }
        }
        p_str++;
        flag = 1;
    }
    if (j)
    {
        words[i][j++] = '\0';
        (*count_words)++;
    }
}

int matches_format(char *line)
{
    int i = 0;
    if (strlen(line) <= 3)
    {
        int d = atoi(line);
        if (d >= 0 && d <= 255)
        {
            while (line[i] != '\0')   
            {
                if (isdigit(line[i]) == 0)
                    return NOT_DIG;
                i++;
            }
        }
        else
            return NOT_DIG;
    }
    else
        return NOT_DIG;
    return SUCCESS;
}

void make_new_str(char words[][MAX_WORD_LEN], char *new_str, int *count_words)
{
    char *p;
    int i, k = 0;
    for (i = 0; i < *count_words; i++)
    {
        if (! matches_format(words[i]))
        {
            p = words[i];
            while (*p != '\0')
            {
                new_str[k++] = *p;
                p++;
            }
        }
        if (i != *count_words - 1)
            new_str[k++] = '.';
    }
    new_str[k++] = '\0';
}

void compare_str(char *str, char *new_str)
{
    int i = 0;
    while (isspace(*str) != 0)
        str++;

    while (isspace(str[i]) == 0 && str[i] != '\0')
        i++;
    str[i] = '\0';

    if (! strcmp(str, new_str))
        printf("YES\n");
    else
        printf("NO\n");
}