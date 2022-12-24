#ifndef __STRUCT_H__
#define __STRUCT_H__

struct product
{
    char name[NAME_LEN];
    char maker[MAKER_LEN];
    unsigned int price;
    unsigned int count;
};

#endif // __STRUCT_H__