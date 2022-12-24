#ifndef __ESSENTIAL_FUNCS_H__
#define __ESSENTIAL_FUNCS_H__

int create_file(int count_num, char *file_name);
int print_file(char *file_name);
int sort_file(char *file_name);
int get_number_by_pos(FILE *f, long pos);
void put_number_by_pos(FILE *f, long pos, int *num);

#endif // __ESSENTIAL_FUNCS_H__