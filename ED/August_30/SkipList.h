typedef struct SkipList SkipList;

SkipList *criaSkipList(int MAXLVL, float p);
void liberaSkipList(SkipList* sk);
int insereSkipList(SkipList *sk, int chave);
