#include <stdio.h>
#include <stdlib.h>

void *memcpy(void *str1, const void *str2, size_t n);
void *memmove(void *str1, const void *str2, size_t n);
int strcmp(const char *str1, const char *str2);
size_t strlen(const char *str);

// The StringList struct, with members indicating the
// current number of elements, the number of elements
// allocated, and the list of elements itself
typedef struct _stringList
{
  int size;
  int max;
  char** elements;
} StringList;

// Initialize a StringList and preallocate 4 elements
int StringListInit(StringList* list)
{
  list->size = 0;
  list->max = 4;
  list->elements = malloc(sizeof(char*) * list->max);
  return list->elements != 0;
}

// Add a string to the given list
void StringListAdd(StringList* list, const char* str)
{
  if (list->max == 0)
  {
    StringListInit(list);
  }

  if (list->size == list->max)
  {
    list->max *= 2;
    list->elements = realloc(list->elements, list->max * sizeof(char*));
  }

  const unsigned cb = strlen(str) * sizeof(char);
  char* copy = malloc(cb);
  memcpy(copy, str, cb);
  list->elements[list->size++] = copy;
}

// Remove the string at the given index
int StringListRemove(StringList* list, int index)
{
  if (index < 0 || index >= list->size)
  {
    return 0;
  }

  free(list->elements[index]);
  if (index != list->size - 1) 
  {
    memmove(list->elements + index, list->elements + index + 1, (list->size - index + 1) * sizeof(char*));
  }

  --list->size;

  if (list->size < list->max / 4)
  {
    list->max /= 2;
    list->elements = realloc(list->elements, list->max * sizeof(char*));
  }

  return 1;
}

// Reset the StringList, clearing and freeing all contents.
void StringListClear(StringList* list)
{
  for (int i = 0; i < list->size; ++i)
  {
    free(list->elements[i]);
  }

  free(list->elements);
  list->elements = 0;
  list->size = 0;
  list->max = 0;
}

// Print out all elements in the list
void StringListPrint(StringList* list)
{
  printf("[");
  for (int i = 0; i < list->size; ++i)
  {
    printf("\"%s\"", list->elements[i]);
    if (i != list->size - 1)
    {
      printf(", ");
    }
  }
  printf("]\n");
}

void StringListPrintStats(StringList* list)
{
  printf("SIZE: %d\nMAX:  %d\n", list->size, list->max);
}

void printOptions()
{
  printf("Options:\n\n");
  printf("u <firstname> <symp> - Adds the given name to the list\n");
  printf("q <symp>             - Find all names with the specified symptom\n");
  printf("d <symp>             - Delete all names with the given symp\n");
  printf("l                        - List all names currently in the list\n");
  printf("0                        - Exit the program\n");
  printf("h                        - Print this help message\n\n");

}

int main(void)
{
  StringList firstNames;
  StringList symptom;
  if (!StringListInit(&firstNames) || !StringListInit(&symptom))
  {
    printf("Unable to allocate!\n");
    return 1;
  }

  printOptions();

  char name[100];
  printf("> ");
  while(scanf("%99[^\n]", name))
  {
    if (*name == '0')
    {
      printf("\nGoodbye!\n\n");
      break;
    }

    switch (*name) {
      case 'u':
      {
        int space = 0;
        char* nameStart = name + 2;
        const char* iter = nameStart;
        while (*iter && *iter++ != ' ')
        {
          ++space;
        }
        
        if (space == 0 || space == strlen(nameStart))
        {
          printf("Invalid Input\n");
          break;
        }

        nameStart[space] = 0;
        StringListAdd(&firstNames, nameStart);
        StringListAdd(&symptom, nameStart + space + 1);
        break;
      }
      case 'q':
      {
        const char* symp = name + 2;
        int found = 0;
        for (int i = 0; i < symptom.size; ++i)
        {
          if (strcmp(symp, symptom.elements[i]) == 0)
          {
            found = 1;
            printf("%s %s\n", firstNames.elements[i], symptom.elements[i]);
          }
        }

        if (!found)
        {
          printf("No one found with symptom %s\n", symp);
        }
        break;
      }
      case 'd':
      {
        const char* symp = name + 2;
        for (int i = 0; i < symptom.size; ++i)
        {
          if (strcmp(symp, symptom.elements[i]) == 0)
          {
            StringListRemove(&firstNames, i);
            StringListRemove(&symptom, i);
            --i;
          }
        }
        break;
      }
      case 'l':
        for (int i = 0; i < firstNames.size; ++i)
        {
          printf("%s %s\n", firstNames.elements[i], symptom.elements[i]);
        }
        printf("\n");
        break;
      case 'h':
        printOptions();
        break;
      default:
        printf("Invalid Option\n\n");
        break;
    }

    getchar();
    printf("> ");
  }

  StringListClear(&firstNames);
  StringListClear(&symptom);
  return 0;
}