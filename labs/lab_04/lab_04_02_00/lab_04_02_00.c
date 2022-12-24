#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 18
#define MAX_STR_LEN 256
#define SUCCESS 0
#define WORD_LEN_ERR 1
#define STR_LEN_ERR 2
#define NO_WORD_ERR 3

int read_line(char *str, int *str_len);
int split_string(char *p_str, char words[][MAX_WORD_LEN], char *p_symb, int *count_words);
void compare_words(char words[][MAX_WORD_LEN], int *count_words);

int main(void)
{
    char str[MAX_STR_LEN] = { '\0' };
    char words[MAX_STR_LEN][MAX_WORD_LEN] = { { '\0' } };
    char symb[] = " ,;:-.!?";
    char *p_str = str, *p_symb = symb;
    int str_len = 0, count_words = 0;
    int rc = 0;

    rc = read_line(str, &str_len);

    if (rc == STR_LEN_ERR)
    {
        //printf("ERROR: Длина строки превышает допустимое значение\n");
        return STR_LEN_ERR;
    }
    
    rc = split_string(p_str, words, p_symb, &count_words);

    if (rc == WORD_LEN_ERR)
    {
        //printf("ERROR: Длина слова превышает допустимое значение\n");
        return WORD_LEN_ERR;
    }    
    
    if (! count_words)
    {
        //printf("ERROR: в строке нет ни одного слова\n");
        return NO_WORD_ERR;
    }

    compare_words(words, &count_words);

    return SUCCESS;
}

int read_line(char *str, int *str_len)
{
    int ch, i = 0;

    printf("Введите строку: ");

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

int split_string(char *p_str, char words[][MAX_WORD_LEN], char *p_symb, int *count_words)
{
    char *p_b = p_symb;
    int i = 0, j = 0;
    int flag = 1;

    while (*p_str != '\0') 
    {
        while (*p_b != '\0')
        {
            if (*p_str == *p_b)
            {
                flag = 0;
                break;
            }
            p_b++;
        }
        if (flag)
            words[i][j++] = *p_str;
        else
        {
            if (j > 0)
            {
                words[i++][j++] = '\0';
                if (j >= MAX_WORD_LEN)
                    return WORD_LEN_ERR;
                (*count_words)++;
                j = 0;
            }
        }
        p_str++;
        p_b = p_symb;
        flag = 1;
    }
    if (j)
    {
        words[i][j++] = '\0';
        if (j >= MAX_WORD_LEN)
            return WORD_LEN_ERR;
        (*count_words)++;
    }
    return SUCCESS;
}

void compare_words(char words[][MAX_WORD_LEN], int *count_words)
{
    int i = 0, j = 0;
    int count = 0, flag = 0;
    char *p, *q, *t;

    printf("Result:\n");
    for (i = 0; i < *count_words; i++)
    {
        count = 1;
        flag = 1;
        p = words[i];
        t = words[0];
        while (t < p)
        {
            if (strcmp(p, t) == 0)
            {
                flag--;
                break;
            }
            t++;
        }
        if (flag)
        {
            for (j = i + 1; j < *count_words; j++)
            {
                q = words[j];
                if (strcmp(p, q) == 0)
                    count++;
            }
            printf("%s %d\n", p, count);
        }
    }
}
