#ifndef DICE_H_INCLUDED
#define DICE_H_INCLUDED
void roll(int num,int *arr);
int final_score(int arr[]);
void display_dice(int num, int arr[]);
int select_dice(int num, int *inb, int *outb);
int compute_dice(int num, int *inb, int *outb);
int swap_dice( int *inb, int inL, int *outb,int outL, int swapped);
#endif// DICE_H_INCLUDED