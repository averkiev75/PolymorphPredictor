#include <string>

struct Type {char name[3];
             Type* next;} *ListType;

struct Atom {
  char FFType[10];
  int Id;
  char Label[10];
  int type;
  Atom* next;
};

struct Model {
  int Id;
  char Label[80];
  Atom* atoms;
  int size;
  void addAtom(char* Label, int type, int Id);
  void SortAtom();
};

void Model::addAtom(char* Label,int type, int Id) {
 if(atoms==0){
   atoms=new Atom;
   strcpy((atoms->Label),Label);
   (atoms->type)=type;
   (atoms->Id)=Id;
   (atoms->next)=0;
   }
 else {
   Atom *current=atoms;
   Atom *new_atom=new Atom;
   while((current->next)) current=(current->next);
   (current->next)=new_atom;
   strcpy((new_atom->Label),Label);
   (new_atom->type)=type;
   (new_atom->Id)=Id;
   (new_atom->next)=0;
   }
}

int addtype(Type** list, char* name) {
 int type=1;
 if((*list)==0) {
   (*list)=new Type;
   strcpy((*list)->name,name);
   ((*list)->next)=0;
   return 1;
   }
 else {
  Type *current=(*list);
  while(strcmp(current->name,name)) {
    type++;
    if((current->next)!=0) current=(current->next);
    else {
      Type *new_type=new Type;
      (current->next)=new_type;
      strcpy((new_type->name),name);
      (new_type->next)=0;
      return type;
      }
    }
  return type;
 }
}

int find(char* what1, char* what2, FILE *input)
{
 char *current;
 int length=strlen(what1);
 current=new char[length+1]; for(int i=0;i<length+1;i++) current[i]=0;
 for(int i=0;i<length;i++)  {current[i]=fgetc(input); if(current[i]==EOF) return 0;}
 while(1){
  if (strcmp(current,what1)==0) return 1;
  else
  if (strcmp(current,what2)==0) return 2;
  else {
    for(int i=0;i<length-1;i++) {current[i]=current[i+1];}
    current[length-1]=fgetc(input);
    if(current[length-1]==EOF) return 0;
    }
 }
}

void Model::SortAtom() {
 int swapId;
 char swapLabel[10];
 int swapType;
 for(int number=size;number>1;number--) {
 Atom *current=atoms;
 for(int i=0;i<size-1;i++) {
   Atom *next=current->next;
   if((current->Id)>(next->Id)) {
     swapId=current->Id;
     strcpy(swapLabel,current->Label);
     swapType=(current->type);
     (current->Id)=(next->Id);
     strcpy((current->Label),(next->Label));
     (current->type)=(next->type);
     (next->Id)=swapId;
     strcpy((next->Label),swapLabel);
     (next->type)=(swapType);
     }
   current=current->next;
   }
 }
}

void print(Type* list, FILE* res) {
  Type *current=list;
  while ((current->next)!=NULL) {
    fprintf(res," %s",current->name);
    current=(current->next);
    }
  fprintf(res," %s",current->name);
}