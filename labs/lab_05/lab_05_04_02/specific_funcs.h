#ifndef __SPECIFIC_FUNCS_H__
#define __SPECIFIC_FUNCS_H__

struct product;
void read_struct_by_pos(FILE *f, size_t i, struct product *p);
void write_struct_by_pos(FILE *f, size_t i, struct product *p);
int compare_names(char *file_name, char *substr);

#endif // __SPECIFIC_FUNCS_H__