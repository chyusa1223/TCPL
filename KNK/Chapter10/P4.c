/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* poker.c (Chapter 10, page 233) */
/* Classifies a poker hand */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
bool royal,straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(int hand[5][2]);
void analyze_hand(int hand[5][2]);
void SelectionSort(int hand[5][2]);
bool CheckForDuplicate(int rank, int suit, int hand[5][2], int cards_read);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
  int hand[NUM_CARDS][2] = {0};

  for (;;) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(int hand[][2])
{
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
    case '0':           exit(EXIT_SUCCESS);
    case '2':           rank = 0; break;
    case '3':           rank = 1; break;
    case '4':           rank = 2; break;
    case '5':           rank = 3; break;
    case '6':           rank = 4; break;
    case '7':           rank = 5; break;
    case '8':           rank = 6; break;
    case '9':           rank = 7; break;
    case 't': case 'T': rank = 8; break;
    case 'j': case 'J': rank = 9; break;
    case 'q': case 'Q': rank = 10; break;
    case 'k': case 'K': rank = 11; break;
    case 'a': case 'A': rank = 12; break;
    default:            bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
    case 'c': case 'C': suit = 0; break;
    case 'd': case 'D': suit = 1; break;
    case 'h': case 'H': suit = 2; break;
    case 's': case 'S': suit = 3; break;
    default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;

    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (CheckForDuplicate(rank,suit,hand,cards_read))
      printf("Duplicate card; ignored.\n");
    else {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit; 
      printf("%d, %d\n",hand[cards_read][0],hand[cards_read][1]);
      cards_read++;
    }
  }
}

bool CheckForDuplicate(int rank, int suit, int hand[][2], int cards_read)
{
  int i;
  for (i = 0; i < cards_read; i++)
    if (hand[i][0] == rank && hand[i][1] == suit) 
      return true;

  return false;
}

void SelectionSort(int hand[][2])
{

  int largest=-1, largest_index=-1;
  int tmp1, tmp2;
  for(int j= NUM_CARDS-1;j>0;j--){

    largest = -1;
    largest_index = -1;
    for(int i=0;i<=j;i++){

      if( hand[i][0] > largest) {
	largest_index = i;
	largest = hand[i][0];
      }
    }
    printf("%d %d %d\n",j, hand[j][0], largest);
    tmp1 = hand[j][0];
   tmp2 = hand[j][1];

   hand[j][0] = hand[largest_index][0];
   hand[j][1] = hand[largest_index][1];

   hand[largest_index][0] = tmp1;
   hand[largest_index][1] = tmp2;
  }

  printf("Sort Start!!\n");

  for(int i=0;i<NUM_CARDS;i++){
    printf("%d,%d\n",hand[i][0],hand[i][1]);
  }

  printf("Sort Finish!!\n");
}
/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(int hand[][2])
{
  int num_consec = 0;
  int rank, suit;
  int matches;
  int smallest=0;

  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0;

  /* check for flush */
  for( int i=0;i<NUM_CARDS-1;i++){
    if( hand[i][1] == hand[i+1][1]) flush = true;
    else {
      flush = false;
      break;
    }
  }

  SelectionSort(hand);

  if( hand[0][0] == 8) { royal = true;}

  /* check for straight */
  for(int i=1;i<NUM_CARDS;i++){
    if (hand[i][0] - hand[i-1][0] != 1)
      break;
    if (i == NUM_CARDS - 1)
      straight = true;
  }
  for (int i = 0; i < NUM_CARDS; i++) {
        matches = 0;
	for (int j = i + 1; j < NUM_CARDS; j++) {
	  if (hand[j][0] == hand[i][0])
	    matches++;
	}

switch(matches) {
	case 1: pairs++;
	break;
	case 2: three = true;
	  break;
	case 3: four = true;
	  break;
	}
  }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
  if( royal && straight && flush) printf("royal flush");
  else if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three && pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two pairs");
  else if (pairs == 1)   printf("Pair");
  else                   printf("High card");
  printf("\n\n");
}
