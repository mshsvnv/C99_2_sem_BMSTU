#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 18
#define MAX_STR_LEN 256
#define SUCCESS 0
#define WORD_LEN_ERR 1
#define STR_LEN_ERR 2
#define NO_WORD_ERR 3
#define NO_UNIQUE_ERR 4

int read_line(char *str, int *str_len);
int split_string(char *p_str, char words[][MAX_WORD_LEN], char *p_symb, int *count_words);
void make_new_massive(char words[][MAX_WORD_LEN], char new_words[][MAX_WORD_LEN], int *count_words);
int make_new_str(char new_words[][MAX_WORD_LEN], char *p_new_str, int *count_words);
void print_new_string(char *p_new_str);

int main(void)
{
    char str[MAX_STR_LEN] = { '\0' };
    char words[MAX_STR_LEN][MAX_WORD_LEN] = { { '\0' } };
    char new_words[MAX_STR_LEN][MAX_WORD_LEN] = { { '\0' } };
    char new_string[MAX_STR_LEN] = { '\0' };
    char symb[] = " ,;:-.!?";
    char *p_str = str, *p_symb = symb, *p_new_str = new_string;
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
        //printf("ERROR: В строке только одно слово\n");
        return NO_WORD_ERR;
    } 
    
    make_new_massive(words, new_words, &count_words);

    rc = make_new_str(new_words, p_new_str, &count_words);

    if (rc != 0)
    {
        //printf("ERROR: Вся строка состоит из элементов, идентичных последнему\n");
        return NO_UNIQUE_ERR;
    }  

    print_new_string(p_new_str);

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

void make_new_massive(char words[][MAX_WORD_LEN], char new_words[][MAX_WORD_LEN], int *count_words)
{
    int i = *count_words - 1;
    int j, k = i, r;

    for (; i >= 0; i--)
    {
        j = 1;
        r = 0;
        char f_sym = words[i][0];
        new_words[k - i][r++] = f_sym;
        while (words[i][j] != '\0')
        {
            if (words[i][j] != f_sym)
                new_words[k - i][r++] = words[i][j];
            j++;
        }
    }
}

int make_new_str(char new_words[][MAX_WORD_LEN], char *p_new_str, int *count_words)
{
    int i, j;
    char *p_b = p_new_str;
    for (i = 1; i < *count_words; i++)
    {
        j = 0;
        if (strcmp(new_words[i], new_words[0]) != 0)
        {
            while (new_words[i][j] != '\0')
            {
                *p_new_str = new_words[i][j++];
                p_new_str++;
            }
            *p_new_str = ' ';
            p_new_str++;
        }
    }
    if (p_new_str == p_b)
        return NO_UNIQUE_ERR;
    else
    {
        p_new_str--;
        *p_new_str = '\0';
        return SUCCESS;
    }
}

void print_new_string(char *p_new_str)
{
    printf("Result: ");
    while (*p_new_str != '\0')
    {
        printf("%c", *p_new_str);
        p_new_str++;
    }
    printf("\n");
}
