// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];
int tableSize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cur = table[index];
    while(cur)
    {
        if(strcasecmp(word, cur->word) == 0)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int res = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {
        res = res * 33 + tolower(word[i]);
    }
    return res % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        int index = hash(word);
        node* newNode = malloc(sizeof(node));
        if (!newNode)
        {
            fclose(file);
            return false;
        }
        strcpy(newNode->word, word);
        newNode->next = NULL;
        if (!table[index])
        {
            table[index] = newNode;
            tableSize++;
            continue;
        }
        newNode->next = table[index];
        table[index] = newNode;
        tableSize++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return tableSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node* cur = table[i];
        while (cur)
        {
            node* temp = cur->next;
            free(cur);
            cur = temp;
            tableSize--;
        }
        table[i] = NULL;
    }
    return true;
}
