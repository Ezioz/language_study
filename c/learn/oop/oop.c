/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-12-09 10:01:12
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-09 10:02:18
 */

// 继承
typedef struct _parent
{
    int data_parent;
}Parent;

typedef struct _Child
{
    struct _parent parent;
    int data_child;
}Child;

