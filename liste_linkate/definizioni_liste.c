// il tipo delle liste di (elementi di tipo) T

typedef... T;

typedef struct listNode *List;

struct listNode {
  T data;
  List next;
};

// scritto senza usare "typedef"

struct listNode {
  ... data;
  struct listNode *next;
};

// il tipo delle liste (elementi di tipo) int

typedef struct intListNode *IntList;

struct intListNode {
  int data;
  IntList next;
};
