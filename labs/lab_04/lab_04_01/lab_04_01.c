#include <stdio.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

const char *my_strpbrk(const char *str1, const char *str2);
size_t my_strspn(const char *str1, const char *str2);
size_t my_strcspn(const char *str1, const char *str2);
const char *my_strchr(const char *str, int ch);
const char *my_strrchr(const char *str, int ch); 

int module_test_strpbrk(const char *str1, const char *str2);
int module_test_strspn(const char *str1, const char *str2);
int module_test_strcspn(const char *str1, const char *str2);
int module_test_strchr(const char *str, int ch);
int module_test_strrchr(const char *str, int ch);

int main(void)
{
    int failed_tests;

    // strpbrk

    failed_tests = 0;

    failed_tests += module_test_strpbrk("this is a test", "absj");
    failed_tests += module_test_strpbrk("this is a test", "mnk");
    failed_tests += module_test_strpbrk("this is a test", " ");
    failed_tests += module_test_strpbrk("this is a test", "");
    failed_tests += module_test_strpbrk("", "this is a test");
    failed_tests += module_test_strpbrk("", "");

    printf("my_strpbrk : %d\n", failed_tests);

    // strspn

    failed_tests = 0;

    failed_tests += module_test_strspn("0123456789", "210");
    failed_tests += module_test_strspn("0123456789", "789");
    failed_tests += module_test_strspn("0123456789", "123");
    failed_tests += module_test_strspn("012", "0123456789");
    failed_tests += module_test_strspn("0123456789", "");
    failed_tests += module_test_strspn("", "0123456789");
    failed_tests += module_test_strspn("", "");

    printf("my_strspn : %d\n", failed_tests);

    // strcspn

    failed_tests = 0;

    failed_tests += module_test_strcspn("0123456789", "788");
    failed_tests += module_test_strcspn("0123456789", "19");
    failed_tests += module_test_strcspn("0123456789", "088");
    failed_tests += module_test_strcspn("0123456789", "");
    failed_tests += module_test_strcspn("", "0123456789");
    failed_tests += module_test_strcspn("", "");

    printf("my_strcspn : %d\n", failed_tests);

    // strchr

    failed_tests = 0;

    failed_tests += module_test_strchr("its the final countdown", 't');
    failed_tests += module_test_strchr("its the final countdown", 'z');
    failed_tests += module_test_strchr("monday", '\0');
    failed_tests += module_test_strchr("9", '9');
    failed_tests += module_test_strchr("", '\0');

    printf("my_strchr : %d\n", failed_tests);

    // strrchr

    failed_tests = 0;

    failed_tests += module_test_strrchr("its the final countdown", 'd');
    failed_tests += module_test_strrchr("its the final countdown", 'z');
    failed_tests += module_test_strrchr("9", '9');
    failed_tests += module_test_strrchr("monday", '\0');
    failed_tests += module_test_strrchr("", '\0');
    failed_tests += module_test_strrchr("", 'm');

    printf("my_strrchr : %d\n", failed_tests);
}

const char *my_strpbrk(const char *str1, const char *str2)
{
    const char *p = str1, *q, *q_b = str2;
    while (*p != '\0')
    {
        q = q_b;
        while (*q != '\0')
        {
            if (*q == *p)
                return p;
            q++;
        }
        p++;
    }
    
    return NULL;
}

size_t my_strspn(const char *str1, const char *str2)
{
    size_t count_num = 0;
    const char *p = str1, *q = str2, *q_b = str2;

    while (*p != '\0')
    {
        q = q_b;
        while (*q != '\0')
        {
            if (*q == *p)
            {
                count_num++;
                break;
            }
            else if (*(q + 1) == '\0')
                return count_num;
            q++;
        }
        p++;
    }

    return count_num;
}

size_t my_strcspn(const char *str1, const char *str2)
{
    size_t count_num = 0;
    const char *p = str1, *q, *q_b = str2;

    while (*p != '\0')
    {
        q = q_b;
        while (*q != '\0')
        {
            if (*q == *p)
                return count_num;
            q++;
        }
        count_num++;
        p++;
    }

    return count_num;
}

const char *my_strchr(const char *str, int ch)
{
    const char *p = str;

    while (*p != '\0')
    {
        if (*p == ch)
            return p;
        p++; 
    }
    if (ch == '\0')
        return p;

    return NULL;
}

const char *my_strrchr(const char *str, int ch)
{
    const char *p = str;
    const char *q = p;

    while (*q != '\0')
        q++;
   
    while (q >= p)
    {
        if (*q == ch)
            return q;
        q--; 
    }

    return NULL;
}

int module_test_strpbrk(const char *str1, const char *str2)
{
    const char *rc_1 = strpbrk(str1, str2);
    const char *rc_2 = my_strpbrk(str1, str2);

    return (rc_1 == rc_2) ? TRUE : FALSE;
}

int module_test_strspn(const char *str1, const char *str2)
{
    size_t rc_1 = strspn(str1, str2);
    size_t rc_2 = my_strspn(str1, str2);

    return (rc_1 == rc_2) ? TRUE : FALSE;
}


int module_test_strcspn(const char *str1, const char *str2)
{
    size_t rc_1 = strcspn(str1, str2);
    size_t rc_2 = my_strcspn(str1, str2);

    return (rc_1 == rc_2) ? TRUE : FALSE;
}

int module_test_strchr(const char *str, int ch)
{
    const char *rc_1 = strchr(str, ch);
    const char *rc_2 = my_strchr(str, ch);

    return (rc_1 == rc_2) ? TRUE : FALSE;
}

int module_test_strrchr(const char *str, int ch)
{
    const char *rc_1 = strrchr(str, ch);
    const char *rc_2 = my_strrchr(str, ch);

    return (rc_1 == rc_2) ? TRUE : FALSE;
}
