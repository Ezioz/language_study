/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-12-13 21:40:37
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-13 21:44:06
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node *link;
struct node
{
    unsigned char elem;
    link next;
};

link make_node(unsigned char elem);
void free_node(link p);
link search(unsigned char elem);