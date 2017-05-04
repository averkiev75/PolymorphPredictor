//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include "ex3.h"
#include "SpGr.h"
#pragma argsused
extern float det(float*a0,float*a1,float*a2);
extern float scalar(float a0[3],float a1[3]);
float cell_a, cell_b, cell_c, angle_a, angle_b, angle_c;    

int main(int argc, char* argv[]) {
printf("\
  *************************************************************************\n\
  *         EXTRACT Program for extracting predicted structures           *\n\
  *        in SHEXTL-format from  Cerius2  trajectory  PMP-file           *\n\
  *        Developed by Boris Averkiev    version 3   for Windows         *\n\
  *               Copyright(c) 2004 NMHU, Las Vegas, NM                   *\n\
  *************************************************************************\n");
char outname[80];
char name[80];
char resname[80];
char cnvname[80];
FILE *input, *out, *res, *conv;
int NumberModels=0;
Model *models;
int *NumberMolecules;
char AtomType[3]; AtomType[2]=0;
char AtomLabel[10];
int Id;
int FileNumber=0;
float E_Frag, Tot_E, Vdw_E, Coulomb_E, H_Bond_E, Density;
float cell_a0, cell_b0, cell_c0, angle_a0, angle_b0, angle_c0;
float coord[3], coord_latt[3];

if (argc==1) {printf("need filename with extension\n");return 1;}
else input=fopen(argv[1],"r");
if (input==NULL) {printf("Cannot open input file"); return 2;}
strcpy(name,argv[1]);
if (argc>2) strcpy(argv[1],argv[2]);
else {
  int i=0;
  while(argv[1][i]!='.')
    if(argv[1][i]!=0)i++;
    else break;
  if(argv[1][i]!=0) {
    i++;
    while(argv[1][i]!='.') if(argv[1][i]!=0)i++;
    else break;
  }
  argv[1][i]=0;
}
find("%%Model Info","%%Model Info",input);
fscanf(input,"%i",&NumberModels);
if (NumberModels==0) return 3;
models = new Model[NumberModels];
NumberMolecules = new int[NumberModels];
for (int i=0;i<NumberModels;i++) fscanf(input,"%i",NumberMolecules+i);
for (int i=0;i<NumberModels;i++) {
  while(find("(A C ACL \"","%Model End", input)==1) {
    models[i].size++;
    while(fgetc(input)!=' ');
    AtomType[0]=fgetc(input); AtomType[1]=fgetc(input);
    if(AtomType[1]=='\"') AtomType[1]=0;
    find("A I Id","A I Id",input);
    fscanf(input,"%i",&Id);
    if(find("bel \"",")\n )\n",input)==1) {
      int i=0; char k=fgetc(input);
      while(k!='\"') {AtomLabel[i]=k; i++; k=fgetc(input);}
      AtomLabel[i]=0;
    }
    else strcpy(AtomLabel,AtomType);
    int TYPE=addtype(&ListType,AtomType);
    models[i].addAtom(AtomLabel,TYPE,Id);
  }
  models[i].SortAtom();
}
strcpy(outname,argv[1]);
strcpy(cnvname,argv[1]);
out=fopen(strcat(outname,".out"),"w");
conv=fopen(strcat(cnvname,".cnv"),"w");
fprintf(conv,"  #       Original Cell             Matrix             Converted Cell\n\n");
fprintf(out,"  #    a      b      c    alpha  betta  gamma Energy Density Group\n");
while(find("Start Frame","Start Frame",input)) {
  convert[0][0]=1;convert[0][1]=0;convert[0][2]=0;
  convert[1][0]=0;convert[1][1]=1;convert[1][2]=0;
  convert[2][0]=0;convert[2][1]=0;convert[2][2]=1;
  PUSH1=0; PUSH2=0; PUSH3=0;
  FileNumber++;
  if(FileNumber<10)  sprintf(resname,"%s00%d.res",argv[1],FileNumber);
  else if(FileNumber<100)sprintf(resname,"%s0%d.res",argv[1],FileNumber);
  else sprintf(resname,"%s%d.res",argv[1],FileNumber);
  res=fopen(resname,"w");
  find("Space Group","Space Group",input); fgetc(input);
  fgets(symmetry,20,input);
  int pos=0;
  while ((group[pos]=symmetry[pos])!='(') pos++; group[pos]=0;
  find("%%E/Frag","%%E/Frag",input);       fscanf(input,"%f",&E_Frag);
  find("%%Tot E","%%Tot E",input);         fscanf(input,"%f",&Tot_E);
  find("%%Vdw E","%%Vdw E",input);         fscanf(input,"%f",&Vdw_E);
  find("%%Coulomb E","%%Coulomb E",input); fscanf(input,"%f",&Coulomb_E);
  find("%%H Bond E","%%H Bond E",input);   fscanf(input,"%f",&H_Bond_E);
  find("%%Density","%%Density",input);     fscanf(input,"%f",&Density);
  find("Lat Vects","Lat Vects",input);
  for(int i=0;i<3;i++)  for(int j=0;j<3;j++)  fscanf(input,"%f",&cell[i][j]);
  cellCalculation(cell);
  cell_a0=cell_a; cell_b0=cell_b; cell_c0=cell_c;
  angle_a0=angle_a; angle_b0=angle_b; angle_c0=angle_c;
  fprintf(conv,"%3d     %s                               ",FileNumber,symmetry);
  SymmetryChoice();
  float DET=det(cell[0],cell[1],cell[2]);
  for (int i=0;i<3;i++)  fprintf(conv,"%4d ",convert[0][i]); fprintf(conv,"\n   ");
  fprintf(conv,"   %6.2f %6.2f %6.2f     %4d %4d %4d       %6.2f %6.2f %6.2f\n",cell_a0,cell_b0,cell_c0,
  convert[1][0],convert[1][1],convert[1][2],cell_a,cell_b,cell_c);
  fprintf(conv,"      %6.2f %6.2f %6.2f     %4d %4d %4d       %6.2f %6.2f %6.2f\n",angle_a0,angle_b0,angle_c0,
  convert[2][0],convert[2][1],convert[2][2],angle_a,angle_b,angle_c);
  fprintf(conv,"\n\n");
  fprintf(res,"TITL %s#%d in %s\nCELL 0.71073  ",name,FileNumber,group);
  fprintf(res,"%6.3f %6.3f %6.3f %6.2f %6.2f %6.2f\n",cell_a,cell_b,cell_c,angle_a,angle_b,angle_c);
  fprintf(out,"%3i %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %5.2f   %s\n",\
  FileNumber,cell_a,cell_b,cell_c,angle_a,angle_b,angle_c,E_Frag,Density,group);
  fprintf(res,"%s",SYMM);
  fprintf(res,"SFAC "); print(ListType, res);
  find("Atom Coords","Atom Coords", input);
  fprintf(res,"\n");
  for(int I=0; I<NumberModels; I++)
     for(int J=0; J<NumberMolecules[I]; J++) {
        Atom *current=models[I].atoms;
        for(int i=0;i<models[I].size;i++) {
          for(int j=0;j<3;j++)  fscanf(input,"%f",&coord[j]);
          coord_latt[0]=det(coord,cell[1],cell[2])/DET+0.25*PUSH1;
          coord_latt[1]=det(cell[0],coord,cell[2])/DET+0.25*PUSH2;
          coord_latt[2]=det(cell[0],cell[1],coord)/DET+0.25*PUSH3;
          for(int m=0;m<3;m++) {
            if(coord_latt[m]>3) coord_latt[m]-=3;
            if(coord_latt[m]<-3) coord_latt[m]+=3;
          }
          fprintf(res,"%-5s %-3d",current->Label,current->type);
          for(int j=0;j<3;j++) fprintf(res,"%7.4f  ",coord_latt[j]);
          fprintf(res,"\n");
          current=current->next;
        }
     }
  fprintf(res,"END\n");
  fclose(res);
}
fclose(conv);
fclose(out); fclose(input);
printf("%d structures extracted\n", FileNumber);
return 0;
}
