#include <string>
extern void triclinic(float cell[3][3]);
extern void monoclinic(float cell[3][3]);
extern float monoclinic1(float cell[3][3]);
extern float monoclinic2(float cell[3][3]);
extern float monoclinic3(float cell[3][3]);
extern void monoclinic4(float cell[3][3], int SpGr);
extern void monoclinic5(float cell[3][3], int SpGr);
extern void monoclinic6(float cell[3][3], int SpGr);
extern void orthorhombic(float cell[3][3]);
extern float orthorhombic1(float cell[3][3]);
extern float orthorhombic2(float cell[3][3]);
extern void orthorhombic3(float cell[3][3]);
extern float cellCalculation(float cell[3][3]);
char symmetry[20], group[20], SYMM[256];
float PUSH1, PUSH2, PUSH3;
int convert[3][3];
extern float scalar(float*a0,float*a1);
extern float det(float a0[3], float a1[3], float a2[3]);
extern int det(int a0[3], int a1[3], int a2[3]);
extern void mmult(int a[3][3], const int b[3][3]);
extern float cell_a, cell_b, cell_c, angle_a, angle_b, angle_c;
extern void Swap(float a[3],float b[3]);
extern void Swap(int a[3],int b[3]);
extern int min(float cell[3][3]);
float cell[3][3];


void SymmetryChoice() {
  int SpGr;
  if(strcmp(symmetry,"P 1 (1)\n")==0) {SpGr=1; strcpy(SYMM,"LATT -1\n");
  strcpy(group,"P1 "); triclinic(cell);}
  else
  if(strcmp(symmetry,"P -1 (1)\n")==0) {SpGr=2; strcpy(SYMM,"LATT 1\n");
  strcpy(group,"P-1 "); triclinic(cell);}
  else//////////////////////////////////////////////////////////////////////////
  if(strcmp(symmetry,"P 2 (1)\n")==0) {SpGr=3; strcpy(SYMM,"LATT -1\nSYMM -X, Y, -Z\n");
  strcpy(group,"P2 "); monoclinic(cell);}
  else
  if(strcmp(symmetry,"P 21 (1)\n")==0) {SpGr=4; strcpy(SYMM,"LATT -1\nSYMM -X, Y+0.5, -Z\n");
  strcpy(group,"P21 "); monoclinic(cell);}
  else
  if(strcmp(symmetry,"C 2 (1)\n")==0) {SpGr=5; strcpy(SYMM,"LATT -7\nSYMM -X, Y, -Z\n");
  strcpy(group,"C2 "); monoclinic1(cell);}
  else
  if(strcmp(symmetry,"C 2 (2)\n")==0) {SpGr=5; strcpy(SYMM,"LATT -7\nSYMM -X, Y, -Z\n");
  strcpy(group,"C2 "); monoclinic2(cell);}
  else
  if(strcmp(symmetry,"C 2 (3)\n")==0) {SpGr=5; strcpy(SYMM,"LATT -7\nSYMM -X, Y, -Z\n");
  strcpy(group,"C2 "); monoclinic3(cell);}
  else
  if(strcmp(symmetry,"P m (1)\n")==0) {SpGr=6; strcpy(SYMM,"LATT -1\nSYMM X, -Y, Z\n");
  strcpy(group,"Pm "); monoclinic(cell);}
  else
  if(strcmp(symmetry,"P c (1)\n")==0) {SpGr=7; strcpy(group,"Pc "); monoclinic4(cell,SpGr);}
  else
  if(strcmp(symmetry,"P c (2)\n")==0) {SpGr=7; strcpy(group,"Pc "); monoclinic5(cell, SpGr);}
  else
  if(strcmp(symmetry,"P c (3)\n")==0) {SpGr=7; strcpy(group,"Pc "); monoclinic6(cell, SpGr);}
  else
  if(strcmp(symmetry,"C m (1)\n")==0) {SpGr=8; strcpy(SYMM,"LATT -7\nSYMM X, -Y, Z\n");
  strcpy(group,"Cm "); monoclinic1(cell);}
  else
  if(strcmp(symmetry,"C m (2)\n")==0) {SpGr=8; strcpy(SYMM,"LATT -7\nSYMM X, -Y, Z\n");
  strcpy(group,"Cm "); monoclinic2(cell);}
  else
  if(strcmp(symmetry,"C m (3)\n")==0) {SpGr=8; strcpy(SYMM,"LATT -7\nSYMM X, -Y, Z\n");
  strcpy(group,"Cm "); monoclinic3(cell);}
  else
  if(strcmp(symmetry,"C c (1)\n")==0) {SpGr=9; strcpy(SYMM,"LATT -7\nSYMM X, -Y, Z+0.5\n");
  strcpy(group,"Cc "); PUSH2=PUSH1=monoclinic1(cell);}
  else
  if(strcmp(symmetry,"C c (2)\n")==0) {SpGr=9; strcpy(SYMM,"LATT -7\nSYMM X, -Y, Z+0.5\n");
  strcpy(group,"Cc "); PUSH2=PUSH1=monoclinic2(cell);}
  else
  if(strcmp(symmetry,"C c (3)\n")==0) {SpGr=9; strcpy(SYMM,"LATT -7\nSYMM X, -Y, Z+0.5\n");
  strcpy(group,"Cc "); PUSH2=PUSH1=monoclinic3(cell);}
  else
  if(strcmp(symmetry,"P 2/m (1)\n")==0) {SpGr=10; strcpy(SYMM,"LATT 1\nSYMM -X, Y, -Z\n");
  strcpy(group,"P2/m "); monoclinic(cell);}
  else
  if(strcmp(symmetry,"P 21/m (1)\n")==0) {SpGr=11; strcpy(SYMM,"LATT 1\nSYMM -X, Y+0.5, -Z\n");
  strcpy(group,"P21/m "); monoclinic(cell);}
  else
  if(strcmp(symmetry,"C 2/m (1)\n")==0) {SpGr=12; strcpy(SYMM,"LATT 7\nSYMM -X, Y, -Z\n");
  strcpy(group,"C2/m "); monoclinic1(cell);}
  else
  if(strcmp(symmetry,"C 2/m (2)\n")==0) {SpGr=12; strcpy(SYMM,"LATT 7\nSYMM -X, Y, -Z\n");
  strcpy(group,"C2/m "); monoclinic2(cell);}
  else
  if(strcmp(symmetry,"C 2/m (3)\n")==0) {SpGr=12; strcpy(SYMM,"LATT 7\nSYMM -X, Y, -Z\n");
  strcpy(group,"C2/m "); monoclinic3(cell);}
  else
  if(strcmp(symmetry,"P 2/c (1)\n")==0) {SpGr=13; strcpy(group,"P2/c "); monoclinic4(cell, SpGr);}
  else
  if(strcmp(symmetry,"P 2/c (2)\n")==0) {SpGr=13; strcpy(group,"P2/c "); monoclinic5(cell, SpGr);}
  else
  if(strcmp(symmetry,"P 2/c (3)\n")==0) {SpGr=13; strcpy(group,"P2/c "); monoclinic6(cell, SpGr);}
  else
  if(strcmp(symmetry,"P 21/c (1)\n")==0) {SpGr=14; strcpy(group,"P21/c "); monoclinic4(cell, SpGr);}
  else
  if(strcmp(symmetry,"P 21/c (2)\n")==0) {SpGr=14; strcpy(group,"P21/c "); monoclinic5(cell, SpGr);}
  else
  if(strcmp(symmetry,"P 21/c (3)\n")==0) {SpGr=14; strcpy(group,"P21/c "); monoclinic6(cell, SpGr);}
  else
  if(strcmp(symmetry,"C 2/c (1)\n")==0) {SpGr=15; strcpy(SYMM,"LATT 7\nSYMM -X, Y, 0.5-Z\n");
  strcpy(group,"C2/c "); PUSH2=PUSH1=monoclinic1(cell);}
  else
  if(strcmp(symmetry,"C 2/c (2)\n")==0) {SpGr=15; strcpy(SYMM,"LATT 7\nSYMM -X, Y, 0.5-Z\n");
  strcpy(group,"C2/c "); PUSH2=PUSH1=monoclinic2(cell);}
  else
  if(strcmp(symmetry,"C 2/c (3)\n")==0) {SpGr=15; strcpy(SYMM,"LATT 7\nSYMM -X, Y, 0.5-Z\n");
  strcpy(group,"C2/c "); PUSH2=PUSH1=monoclinic3(cell);}
  else//////////////////////////////////////////////////////////////////////////
  if(strcmp(symmetry,"P 2 2 2 (1)\n")==0) {SpGr=16; strcpy(group,"P222 "); orthorhombic1(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"P 2 2 21 (1)\n")==0) {SpGr=17; strcpy(group,"P2221 "); PUSH3=orthorhombic2(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z+0.5\nSYMM -X, Y, 0.5-Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"P 21 21 2 (1)\n")==0) {SpGr=18; strcpy(group,"P21212 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM 0.5-X, 0.5+Y, -Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"P 21 21 21 (1)\n")==0) {SpGr=19; strcpy(group,"P212121 "); PUSH3=PUSH2=PUSH1=orthorhombic1(cell);
  strcpy(SYMM,"LATT -1\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM -X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"C 2 2 21 (1)\n")==0) {SpGr=20; strcpy(group,"C2221 "); PUSH3=orthorhombic2(cell);
  strcpy(SYMM,"LATT -7\nSYMM -X, -Y, 0.5+Z\nSYMM -X, Y, 0.5-Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"C 2 2 2 (1)\n")==0) {SpGr=21; strcpy(group,"C222 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -7\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"F 2 2 2 (1)\n")==0) {SpGr=22; strcpy(group,"F222 "); orthorhombic1(cell);
  strcpy(SYMM,"LATT -4\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"I 2 2 2 (1)\n")==0) {SpGr=23; strcpy(group,"I222 "); orthorhombic1(cell);
  strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"I 21 21 21 (1)\n")==0) {SpGr=24; strcpy(group,"I212121 "); PUSH3=PUSH2=PUSH1=orthorhombic1(cell);
  strcpy(SYMM,"LATT -2\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM -X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"P m m 2 (1)\n")==0) {SpGr=25; strcpy(group,"Pmm2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -X, Y, Z\nSYMM X, -Y, Z\n");}
  else
  if(strcmp(symmetry,"P m c 21 (1)\n")==0) {SpGr=26; strcpy(group,"Pmc21 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM -X, Y, Z\nSYMM X, -Y, 0.5+Z\n");}
  else
  if(strcmp(symmetry,"P c c 2 (1)\n")==0) {SpGr=27; strcpy(group,"Pcc2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -X, Y, 0.5+Z\nSYMM X, -Y, 0.5+Z\n");}
  else
  if(strcmp(symmetry,"P m a 2 (1)\n")==0) {SpGr=28; strcpy(group,"Pma2 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM 0.5-X, Y, Z\nSYMM 0.5+X, -Y, Z\n");}
  else
  if(strcmp(symmetry,"P c a 21 (1)\n")==0) {SpGr=29; strcpy(group,"Pca21 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM 0.5+X, -Y, Z\nSYMM 0.5-X, Y, 0.5+Z\n");}
  else
  if(strcmp(symmetry,"P n c 2 (1)\n")==0) {SpGr=30; strcpy(group,"Pnc2 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM X, 0.5-Y, 0.5+Z\nSYMM -X, 0.5+Y, 0.5+Z\n");}
  else
  if(strcmp(symmetry,"P m n 21 (1)\n")==0) {SpGr=31; strcpy(group,"Pmn21 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -1\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM 0.5+X, -Y, 0.5+Z\nSYMM -X, Y, Z\n");}
  else
  if(strcmp(symmetry,"P b a 2 (1)\n")==0) {SpGr=32; strcpy(group,"Pba2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM 0.5+X, 0.5-Y, Z\nSYMM 0.5-X, 0.5+Y, Z\n");}
  else
  if(strcmp(symmetry,"P n a 21 (1)\n")==0) {SpGr=33; strcpy(group,"Pna21 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM 0.5+X, 0.5-Y, Z\nSYMM 0.5-X, Y+0.5, 0.5+Z\n");}
  else
  if(strcmp(symmetry,"P n n 2 (1)\n")==0) {SpGr=34; strcpy(group,"Pnn2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM 0.5+X, 0.5-Y, 0.5+Z\nSYMM 0.5-X, 0.5+Y, 0.5+Z\n");}
  else
  if(strcmp(symmetry,"C m m 2 (1)\n")==0) {SpGr=35; strcpy(group,"Cmm2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -7\nSYMM -X, -Y, Z\nSYMM X, -Y, Z\nSYMM -X, Y, Z\n");}
  else
  if(strcmp(symmetry,"C m c 21 (1)\n")==0) {SpGr=36; strcpy(group,"Cmc21 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -7\nSYMM -X, -Y, 0.5+Z\nSYMM X, -Y, 0.5+Z\nSYMM -X, Y, Z\n");}
  else
  if(strcmp(symmetry,"C c c 2 (1)\n")==0) {SpGr=37; strcpy(group,"Ccc2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -7\nSYMM -X, -Y, Z\nSYMM X, -Y, 0.5+Z\nSYMM -X, Y, 0.5+Z\n");}
  else
  if(strcmp(symmetry,"A m m 2 (1)\n")==0) {SpGr=38; strcpy(group,"Amm2 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -5\nSYMM -X, -Y, Z\nSYMM X, -Y, Z\nSYMM -X, Y, Z\n");}
  else
  if(strcmp(symmetry,"A b m 2 (1)\n")==0) {SpGr=39; strcpy(group,"Abm2 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -5\nSYMM -X, -Y, Z\nSYMM X, 0.5-Y, Z\nSYMM -X, 0.5+Y, Z\n");}
  else
  if(strcmp(symmetry,"A m a 2 (1)\n")==0) {SpGr=40; strcpy(group,"Ama2 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -5\nSYMM -X, -Y, Z\nSYMM 0.5+X, -Y, Z\nSYMM 0.5-X, Y, Z\n");}
  else
  if(strcmp(symmetry,"A b a 2 (1)\n")==0) {SpGr=41; strcpy(group,"Aba2 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -5\nSYMM -X, -Y, Z\nSYMM 0.5+X, 0.5-Y, Z\nSYMM 0.5-X, 0.5+Y, Z\n");}
  else
  if(strcmp(symmetry,"F m m 2 (1)\n")==0) {SpGr=42; strcpy(group,"Fmm2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -4\nSYMM -X, -Y, Z\nSYMM X, -Y, Z\nSYMM -X, Y, Z\n");}
  else
  if(strcmp(symmetry,"F d d 2 (1)\n")==0) {SpGr=43; strcpy(group,"Fdd2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -4\nSYMM -X, -Y, Z\nSYMM 0.25+X, 0.25-Y, 0.25+Z\nSYMM 0.25-X, 0.25+Y, 0.25+Z\n");}
  else
  if(strcmp(symmetry,"I m m 2 (1)\n")==0) {SpGr=44; strcpy(group,"Imm2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM X, -Y, Z\nSYMM -X, Y, Z\n");}
  else
  if(strcmp(symmetry,"I b a 2 (1)\n")==0) {SpGr=45; strcpy(group,"Iba2 "); orthorhombic2(cell);
  strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM 0.5+X, 0.5-Y, Z\nSYMM 0.5-X, 0.5+Y, Z\n");}
  else
  if(strcmp(symmetry,"I m a 2 (1)\n")==0) {SpGr=46; strcpy(group,"Ima2 "); orthorhombic(cell);
  strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM 0.5+X, -Y, Z\nSYMM 0.5-X, Y, Z\n");}
  else
  if(strcmp(symmetry,"P m m m (1)\n")==0) {SpGr=47; strcpy(group,"Pmmm "); orthorhombic1(cell);
  strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"P n n n (1)\n")==0) {SpGr=48; strcpy(group,"Pnnn "); orthorhombic1(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, 0.5-Y, Z\nSYMM 0.5-X, Y, 0.5-Z\nSYMM X, 0.5-Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"P c c m (1)\n")==0) {SpGr=49; strcpy(group,"Pccm "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM -X, Y, 0.5-Z\nSYMM -X, Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"P b a n (1)\n")==0) {SpGr=50; strcpy(group,"Pban "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, 0.5-Y, Z\nSYMM 0.5-X, Y, -Z\nSYMM X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"P m m a (1)\n")==0) {SpGr=51; strcpy(group,"Pmma "); orthorhombic(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, -Y, Z\nSYMM -X, Y, -Z\nSYMM 0.5+X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"P n n a (1)\n")==0) {SpGr=52; strcpy(group,"Pnna "); orthorhombic(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, -Y, Z\nSYMM 0.5-X, 0.5+Y, 0.5-Z\nSYMM X, 0.5-Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"P m n a (1)\n")==0) {SpGr=53; strcpy(group,"Pmna "); orthorhombic(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM 0.5-X, Y, 0.5-Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"P c c a (1)\n")==0) {SpGr=54; strcpy(group,"Pcca "); orthorhombic(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, -Y, Z\nSYMM -X, Y, 0.5-Z\nSYMM 0.5+X, -Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"P b a m (1)\n")==0) {SpGr=55; strcpy(group,"Pbam "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM 0.5-X, 0.5+Y, -Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"P c c n (1)\n")==0) {SpGr=56; strcpy(group,"Pccn "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, 0.5-Y, Z\nSYMM -X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, -Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"P b c m (1)\n")==0) {SpGr=57; strcpy(group,"Pbcm "); orthorhombic(cell);
  strcpy(SYMM,"LATT 1\nSYMM -X, -Y, 0.5+Z\nSYMM -X, 0.5+Y, 0.5-Z\nSYMM X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"P n n m (1)\n")==0) {SpGr=58; strcpy(group,"Pnnm "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM 0.5-X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"P m m n (1)\n")==0) {SpGr=59; strcpy(group,"Pmmn "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, 0.5-Y, Z\nSYMM -X, 0.5+Y, -Z\nSYMM 0.5+X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"P b c n (1)\n")==0) {SpGr=60; strcpy(group,"Pbcn "); orthorhombic(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, 0.5-Y, 0.5+Z\nSYMM -X, Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"P b c a (1)\n")==0) {SpGr=61; strcpy(group,"Pbca "); orthorhombic3(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM -X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"P n m a (1)\n")==0) {SpGr=62; strcpy(group,"Pnma "); orthorhombic(cell);
  strcpy(SYMM,"LATT 1\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM -X, 0.5+Y, -Z\nSYMM 0.5+X, 0.5-Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"C m c m (1)\n")==0) {SpGr=63; strcpy(group,"Cmcm "); orthorhombic(cell);
  strcpy(SYMM,"LATT 7\nSYMM -X, -Y, 0.5+Z\nSYMM -X, Y, 0.5-Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"C m c a (1)\n")==0) {SpGr=64; strcpy(group,"Cmca "); orthorhombic(cell);
  strcpy(SYMM,"LATT 7\nSYMM -X, 0.5-Y, 0.5+Z\nSYMM -X, 0.5+Y, 0.5-Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"C m m m (1)\n")==0) {SpGr=65; strcpy(group,"Cmmm "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 7\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"C c c m (1)\n")==0) {SpGr=66; strcpy(group,"Cccm "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 7\nSYMM -X, -Y, Z\nSYMM -X, Y, 0.5-Z\nSYMM X, -Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"C m m a (1)\n")==0) {SpGr=67; strcpy(group,"Cmma "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 7\nSYMM -X, 0.5-Y, Z\nSYMM -X, 0.5+Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"C c c a (1)\n")==0) {SpGr=68; strcpy(group,"Ccca "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 7\nSYMM 0.5-X, -Y, Z\nSYMM -X, Y, 0.5-Z\nSYMM 0.5+X, -Y, 0.5-Z\n");}
  else
  if(strcmp(symmetry,"F m m m (1)\n")==0) {SpGr=69; strcpy(group,"Fmmm "); orthorhombic1(cell);
  strcpy(SYMM,"LATT 4\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"F d d d (1)\n")==0) {SpGr=70; strcpy(group,"Fddd "); orthorhombic1(cell);
  strcpy(SYMM,"LATT 4\nSYMM 0.75-X, 0.75-Y, Z\nSYMM 0.75-X, Y, 0.75-Z\nSYMM X, 0.75-Y, 0.75-Z\n");}
  else
  if(strcmp(symmetry,"I m m m (1)\n")==0) {SpGr=71; strcpy(group,"Immm "); orthorhombic1(cell);
  strcpy(SYMM,"LATT 4\nSYMM -X, -Y, Z\nSYMM -X, Y, -Z\nSYMM X, -Y, -Z\n");}
  else
  if(strcmp(symmetry,"I b a m (1)\n")==0) {SpGr=72; strcpy(group,"Ibam "); orthorhombic2(cell);
  strcpy(SYMM,"LATT 2\nSYMM -X, -Y, Z\nSYMM 0.5-X, 0.5+Y, -Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"I b c a (1)\n")==0) {SpGr=73; strcpy(group,"Ibca "); PUSH1=PUSH2=PUSH3=orthorhombic1(cell);
  strcpy(SYMM,"LATT 2\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM -X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, -Z\n");}
  else
  if(strcmp(symmetry,"I m m a (1)\n")==0) {SpGr=74; strcpy(group,"Imma "); PUSH3=orthorhombic2(cell);
  strcpy(SYMM,"LATT 2\nSYMM -X, 0.5-Y, Z\nSYMM -X, 0.5+Y, -Z\nSYMM X, -Y, -Z\n");}
  else {////////////////////////////////////////////////////////////////////////
    cellCalculation;
    if(strcmp(symmetry,"P 4 (1)\n")==0) {SpGr=75; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 41 (1)\n")==0) {SpGr=76; strcpy(group,"P41 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM -Y, X, 0.25+Z\nSYMM Y, -X, 0.75+Z\n");}
    else
    if(strcmp(symmetry,"P 42 (1)\n")==0) {SpGr=77; strcpy(group,"P42 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, 0.5+Z\nSYMM Y, -X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"P 43 (1)\n")==0) {SpGr=78; strcpy(group,"P43 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM -Y, X, 0.75+Z\nSYMM Y, -X, 0.25+Z\n");}
    else
    if(strcmp(symmetry,"I 4 (1)\n")==0) {SpGr=79; strcpy(group,"I4 ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"I 41 (1)\n")==0) {SpGr=80; strcpy(group,"I41 ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, 0.5+Z\nSYMM -Y, X, 0.25+Z\nSYMM Y, -X, 0.75+Z\n");}
    else
    if(strcmp(symmetry,"P -4 (1)\n")==0) {SpGr=81; strcpy(group,"P-4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, -Z\nSYMM Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"I -4 (1)\n")==0) {SpGr=82; strcpy(group,"I-4 ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM -Y, X, -Z\nSYMM Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"P 4/m (1)\n")==0) {SpGr=83; strcpy(group,"P4/m ");
    strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/m (1)\n")==0) {SpGr=84; strcpy(group,"P42/m ");
    strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM -Y, X, 0.5+Z\nSYMM Y, -X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"P 4/n (1)\n")==0) {SpGr=85; strcpy(group,"P4/n "); PUSH1=PUSH2=1;
    strcpy(SYMM,"LATT 1\nSYMM 0.5-X, 0.5-Y, Z\nSYMM 0.5-Y, X, Z\nSYMM Y, 0.5-X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/n (1)\n")==0) {SpGr=86; strcpy(group,"P42/n ");
    strcpy(SYMM,"LATT 1\nSYMM 0.5-X, 0.5-Y, Z\nSYMM 0.5-Y, X, 0.5+Z\nSYMM Y, 0.5-X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"I 4/m (1)\n")==0) {SpGr=87; strcpy(group,"I4/m ");
    strcpy(SYMM,"LATT 2\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"I 41/a (1)\n")==0) {SpGr=88; strcpy(group,"I41/a "); PUSH1=1;
    strcpy(SYMM,"LATT 2\nSYMM 0.5-X, -Y, 0.5+Z\nSYMM 0.75-Y, 0.25+X, 0.25+Z\nSYMM 0.75+Y, 0.75-X, 0.75+Z\n");}
    else
    if(strcmp(symmetry,"P 4 2 2 (1)\n")==0) {SpGr=89; strcpy(group,"P422 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, -Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"P 4 21 2 (1)\n")==0) {SpGr=90; strcpy(group,"P4212 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM 0.5-Y, 0.5+X, Z\nSYMM 0.5+Y, 0.5-X, Z\n\
           SYMM 0.5-X, 0.5+Y, -Z\nSYMM 0.5+X, 0.5-Y, -Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"P 41 2 2 (1)\n")==0) {SpGr=91; strcpy(group,"P4122 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM -Y, X, 0.25+Z\nSYMM Y, -X, 0.75+Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, 0.5-Z\nSYMM Y, X, 0.75-Z\nSYMM -Y, -X, 0.25-Z\n");}
    else
    if(strcmp(symmetry,"P 41 21 2 (1)\n")==0) {SpGr=92; strcpy(group,"P41212 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM 0.5-Y, 0.5+X, 0.25+Z\nSYMM 0.5+Y, 0.5-X, 0.75+Z\n\
           SYMM 0.5-X, 0.5+Y, 0.25-Z\nSYMM 0.5+X, 0.5-Y, 0.75-Z\nSYMM Y, X, -Z\nSYMM -Y, -X, 0.5-Z\n");}
    else
    if(strcmp(symmetry,"P 42 2 2 (1)\n")==0) {SpGr=93; strcpy(group,"P4222 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, 0.5+Z\nSYMM Y, -X, 0.5+Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, -Z\nSYMM Y, X, 0.5-Z\nSYMM -Y, -X, 0.5-Z\n");}
    else
    if(strcmp(symmetry,"P 42 21 2 (1)\n")==0) {SpGr=94; strcpy(group,"P42212 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM 0.5-Y, 0.5+X, 0.5+Z\nSYMM 0.5+Y, 0.5-X, 0.5+Z\n\
           SYMM 0.5-X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, 0.5-Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else

    if(strcmp(symmetry,"P 43 2 2 (1)\n")==0) {SpGr=95; strcpy(group,"P4322 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM -Y, X, 0.75+Z\nSYMM Y, -X, 0.25Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, 0.5-Z\nSYMM Y, X, 0.25-Z\nSYMM -Y, -X, 0.75-Z\n");}
    else
    if(strcmp(symmetry,"P 43 21 2 (1)\n")==0) {SpGr=96; strcpy(group,"P43212 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, 0.5+Z\nSYMM 0.5-Y, 0.5+X, 0.75+Z\nSYMM 0.5+Y, 0.5-X, 0.25+Z\n\
           SYMM 0.5-X, 0.5+Y, 0.75-Z\nSYMM 0.5+X, 0.5-Y, 0.25-Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"I 4 2 2 (1)\n")==0) {SpGr=97; strcpy(group,"I422 ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, -Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"I 41 2 2 (1)\n")==0) {SpGr=98; strcpy(group,"I4122 ");
    strcpy(SYMM,"LATT -2\nSYMM 0.5-X, 0.5-Y, 0.5+Z\nSYMM -Y, 0.5+X, 0.25+Z\nSYMM 0.5+Y, -X, 0.75+Z\n\
           SYMM 0.5-X, Y, 0.75-Z\nSYMM X, 0.5-Y, 0.25-Z\nSYMM 0.5+Y, 0.5+X, 0.5-Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"P 4 m m (1)\n")==0) {SpGr=99; strcpy(group,"P4mm ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM X, -Y, Z\nSYMM -X, Y, Z\nSYMM -Y, -X, Z\nSYMM Y, X, Z\n");}
    else
    if(strcmp(symmetry,"P 4 b m (1)\n")==0) {SpGr=100; strcpy(group,"P4bm ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM 0.5+X, 0.5-Y, Z\nSYMM 0.5-X, 0.5+Y, Z\nSYMM 0.5-Y, 0,5-X, Z\nSYMM 0.5+Y, 0.5+X, Z\n");}
    else
    if(strcmp(symmetry,"P 42 c m (1)\n")==0) {SpGr=101; strcpy(group,"P42cm ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, 0.5+Z\nSYMM Y, -X, 0.5+Z\n\
           SYMM X, -Y, 0.5+Z\nSYMM -X, Y, 0.5+Z\nSYMM -Y, -X, Z\nSYMM Y, X, Z\n");}
    else
    if(strcmp(symmetry,"P 42 n m (1)\n")==0) {SpGr=102; strcpy(group,"P42nm ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM 0.5-Y, 0.5+X, 0.5+Z\nSYMM 0.5+Y, 0.5-X, 0.5+Z\n\
           SYMM 0.5+X, 0.5-Y, 0.5+Z\nSYMM 0.5-X, 0.5+Y, 0.5+Z\nSYMM -Y, -X, Z\nSYMM Y, X, Z\n");}
    else
    if(strcmp(symmetry,"P 4 c c (1)\n")==0) {SpGr=103; strcpy(group,"P4cc ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM X, -Y, 0.5+Z\nSYMM -X, Y, 0.5+Z\nSYMM -Y, -X, 0.5+Z\nSYMM Y, X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"P 4 n c (1)\n")==0) {SpGr=104; strcpy(group,"P4nc ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM 0.5+X, 0.5-Y, 0.5+Z\nSYMM 0.5-X, 0.5+Y, 0.5+Z\nSYMM 0.5-Y, 0.5-X, 0.5+Z\nSYMM 0.5+Y, 0.5+X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"P 42 m c (1)\n")==0) {SpGr=105; strcpy(group,"P42mc ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, 0.5+Z\nSYMM Y, -X, 0.5+Z\n\
           SYMM X, -Y, Z\nSYMM -X, Y, Z\nSYMM -Y, -X, 0.5+Z\nSYMM Y, X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"P 42 b c (1)\n")==0) {SpGr=106; strcpy(group,"P42bc ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, 0.5+Z\nSYMM Y, -X, 0.5+Z\n\
           SYMM 0.5+X, 0.5-Y, Z\nSYMM 0.5-X, 0.5+Y, Z\nSYMM 0.5-Y, 0.5-X, 0.5+Z\nSYMM 0.5+Y, 0.5+X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"I 4 m m (1)\n")==0) {SpGr=107; strcpy(group,"I4mm ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM X, -Y, Z\nSYMM -X, Y, Z\nSYMM -Y, -X, Z\nSYMM Y, X, Z\n");}
    else
    if(strcmp(symmetry,"I 4 c m (1)\n")==0) {SpGr=108; strcpy(group,"I4cm ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM X, -Y, 0.5+Z\nSYMM -X, Y, 0.5+Z\nSYMM -Y, -X, 0.5+Z\nSYMM Y, X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"I 41 m d (1)\n")==0) {SpGr=109; strcpy(group,"I41md ");
    strcpy(SYMM,"LATT -1\nSYMM 0.5-X, 0.5-Y, 0.5+Z\nSYMM -Y, 0.5+X, 0.25+Z\nSYMM 0.5+Y, -X, 0.75+Z\n\
           SYMM X, -Y, Z\nSYMM 0.5-X, 0.5+Y, 0.5+Z\nSYMM -Y, 0.5-X, 0.25+Z\nSYMM 0.5+Y, X, 0.75+Z\n");}
    else
    if(strcmp(symmetry,"I 41 c d (1)\n")==0) {SpGr=110; strcpy(group,"I41cd ");
    strcpy(SYMM,"LATT -1\nSYMM 0.5-X, 0.5-Y, 0.5+Z\nSYMM -Y, 0.5+X, 0.25+Z\nSYMM 0.5+Y, -X, 0.75+Z\n\
           SYMM X, -Y, 0.5+Z\nSYMM 0.5-X, 0.5+Y, Z\nSYMM -Y, 0.5-X, 0.75+Z\nSYMM 0.5+Y, X, 0.25+Z\n");}
    else
    if(strcmp(symmetry,"P -4 2 m (1)\n")==0) {SpGr=111; strcpy(group,"P-42m ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, -Z\nSYMM -Y, -X, Z\nSYMM Y, X, Z\n");}
    else
    if(strcmp(symmetry,"P -4 2 c (1)\n")==0) {SpGr=112; strcpy(group,"P-42c ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM -X, Y, 0.5-Z\nSYMM X, -Y, 0.5-Z\nSYMM -Y, -X, 0.5+Z\nSYMM Y, X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"P -4 21 m (1)\n")==0) {SpGr=113; strcpy(group,"P-421m ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM 0.5-X, 0.5+Y, -Z\nSYMM 0.5+X, 0.5-Y, -Z\nSYMM 0.5-Y, 0.5-X, Z\nSYMM 0.5+Y, 0.5+X, Z\n");}
    else
    if(strcmp(symmetry,"P -4 21 c (1)\n")==0) {SpGr=114; strcpy(group,"P-421c ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM 0.5-X, 0.5+Y, 0.5-Z\nSYMM 0.5+X, 0.5-Y, 0.5-Z\nSYMM 0.5-Y, 0.5-X, 0.5+Z\nSYMM 0.5+Y, 0.5+X, 0.5+Z\n");}
    else
    if(strcmp(symmetry,"P -4 m 2 (1)\n")==0) {SpGr=115; strcpy(group,"P-4m2 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM X, -Y, Z\nSYMM -X, Y, Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"P -4 c 2 (1)\n")==0) {SpGr=116; strcpy(group,"P-4c2 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM X, -Y, 0.5+Z\nSYMM -X, Y, 0.5+Z\nSYMM Y, X, 0.5-Z\nSYMM -Y, -X, 0.5-Z\n");}
    else
    if(strcmp(symmetry,"P -4 b 2 (1)\n")==0) {SpGr=117; strcpy(group,"P-4b2 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM 0.5+X, 0.5-Y, Z\nSYMM 0.5-X, 0.5+Y, Z\nSYMM 0.5+Y, 0.5+X, -Z\nSYMM 0.5-Y, 0.5-X, -Z\n");}
    else
    if(strcmp(symmetry,"P -4 n 2 (1)\n")==0) {SpGr=118; strcpy(group,"P-4n2 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM 0.5+X, 0.5-Y, 0.5+Z\nSYMM 0.5-X, 0.5+Y, 0.5+Z\nSYMM 0.5+Y, 0.5+X, 0.5-Z\nSYMM 0.5-Y, 0.5-X, 0.5-Z\n");}
    else
    if(strcmp(symmetry,"I -4 m 2 (1)\n")==0) {SpGr=119; strcpy(group,"I-4m2 ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM X, -Y, Z\nSYMM -X, Y, Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"I -4 c 2 (1)\n")==0) {SpGr=120; strcpy(group,"I-4c2 ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM X, -Y, 0.5+Z\nSYMM -X, Y, 0.5+Z\nSYMM Y, X, 0.5-Z\nSYMM -Y, -X, 0.5-Z\n");}
    else
    if(strcmp(symmetry,"I -4 2 m (1)\n")==0) {SpGr=121; strcpy(group,"I-42m ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM Y, -X, -Z\nSYMM -Y, X, -Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, -Z\nSYMM -Y, -X, Z\nSYMM Y, X, Z\n");}
    else
    if(strcmp(symmetry,"I -4 2 d (1)\n")==0) {SpGr=122; strcpy(group,"I-42d ");
    strcpy(SYMM,"LATT -2\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM 0.5-X, Y, 0.75-Z\nSYMM 0.5+X, -Y, 0.75-Z\nSYMM 0.5-Y, -X, 0.75+Z\nSYMM 0.5+Y, X, 0.75+Z\n");}
    else
    if(strcmp(symmetry,"P 4/m m m (1)\n")==0) {SpGr=123; strcpy(group,"P4/mmm ");
    strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM -X, Y, -Z\nSYMM X, -Y, -Z\nSYMM Y, X, -Z\nSYMM -Y, -X, -Z\n");}
    else
    if(strcmp(symmetry,"P 4/m c c (1)\n")==0) {SpGr=124; strcpy(group,"P4/mcc ");
    strcpy(SYMM,"LATT 1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n\
           SYMM -X, Y, 0.5-Z\nSYMM X, -Y, 0.5-Z\nSYMM Y, X, 0.5-Z\nSYMM -Y, -X, 0.5-Z\n");}

           
    else
    if(strcmp(symmetry,"P 4/n b m (1)\n")==0) {SpGr=125; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 4/n n c (1)\n")==0) {SpGr=126; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 4/m b m (1)\n")==0) {SpGr=127; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 4/m n c (1)\n")==0) {SpGr=128; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 4/n m m (1)\n")==0) {SpGr=129; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 4/n c c (1)\n")==0) {SpGr=130; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/m m c (1)\n")==0) {SpGr=131; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/m c m (1)\n")==0) {SpGr=132; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/n b c (1)\n")==0) {SpGr=133; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/n n m (1)\n")==0) {SpGr=134; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/m b c (1)\n")==0) {SpGr=135; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/m n m (1)\n")==0) {SpGr=136; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/m n c (1)\n")==0) {SpGr=137; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 42/n c m (1)\n")==0) {SpGr=138; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"I 4/m m m (1)\n")==0) {SpGr=139; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"I 4/m c m (1)\n")==0) {SpGr=140; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"I 41/a m d (1)\n")==0) {SpGr=141; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"I 41/a c d (1)\n")==0) {SpGr=142; strcpy(group,"P4 ");
    strcpy(SYMM,"LATT -1\nSYMM -X, -Y, Z\nSYMM -Y, X, Z\nSYMM Y, -X, Z\n");}
    else////////////////////////////////////////////////////////////////////////
    if(strcmp(symmetry,"P 3 (1)\n")==0) {SpGr=143; strcpy(group,"P3 ");
    strcpy(SYMM,"LATT -1\nSYMM -Y, X-Y, Z\nSYMM -X+Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P 31 (1)\n")==0) {SpGr=144; strcpy(group,"P31 ");
    strcpy(SYMM,"LATT -1\nSYMM -Y, X-Y, 0.33333+Z\nSYMM -X+Y, -X, 0.66667+Z\n");}
    else
    if(strcmp(symmetry,"P 32 (1)\n")==0) {SpGr=145; strcpy(group,"P32 ");
    strcpy(SYMM,"LATT -1\nSYMM -Y, X-Y, 0.66667+Z\nSYMM -X+Y, -X, 0.33333+Z\n");}
    else
    if(strcmp(symmetry,"R 3 (1)\n")==0) {SpGr=146; strcpy(group,"R3 ");
    strcpy(SYMM,"LATT -3\nSYMM -Y, X-Y, Z\nSYMM -X+Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"P -3 (1)\n")==0) {SpGr=147; strcpy(group,"P-3 ");
    strcpy(SYMM,"LATT 1\nSYMM -Y, X-Y, Z\nSYMM -X+Y, -X, Z\n");}
    else
    if(strcmp(symmetry,"R -3 (1)\n")==0) {SpGr=148; strcpy(group,"R-3 ");
    strcpy(SYMM,"LATT 3\nSYMM -Y, X-Y, Z\nSYMM -X+Y, -X, Z\n");}



    else strcpy(SYMM,"LATT -1\nSYMM \n");
  }
}

  //////////////////////////////////////////////////////////////////////////////
  //////////////////////THE END OF THE LIST OF SPACE GROUPS/////////////////////
  //////////////////////////////////////////////////////////////////////////////

void triclinic(float cell[3][3]) {
  float list[18][3];
  int matrix[3][3];
  int a,b,c;
  if (scalar(cell[0],cell[0])>scalar(cell[1],cell[1])) {
    Swap(cell[0],cell[1]); Swap(convert[0],convert[1]);
  }
  do {
    matrix[0][0]=matrix[1][1]=matrix[2][2]=1;
    matrix[0][1]=matrix[1][0]=matrix[0][2]=matrix[2][0]=matrix[1][2]=matrix[2][1]=0;
    int current=0;
    for (a=0;a<2;a++) for (b=-1;b<2;b++) for (c=-1;c<2;c++) {
      for (int i=0;i<3;i++) list[current][i]=a*cell[0][i]+b*cell[1][i]+c*cell[2][i];
      current++;
    }
    current=0;
    for (a=0;a<2;a++) for (b=-1;b<2;b++) for (c=-1;c<2;c++) {
      if (scalar(cell[0],cell[0])>scalar(list[current],list[current]))
      if(current!=4) {
        matrix[0][0]=a; matrix[0][1]=b; matrix[0][2]=c;
        for (int i=0;i<3;i++) cell[0][i]=list[current][i];
      }
      current++;
    }
    current=0;
    for (a=0;a<2;a++) for (b=-1;b<2;b++) for (c=-1;c<2;c++) {
      if (scalar(cell[1],cell[1])>scalar(list[current],list[current]))
      if(current!=4) {
        int temp1[3]={13,17,19};
        int temp[3]={a,b,c};
        if(det(matrix[0],temp,temp1)!=0) {
          matrix[1][0]=a; matrix[1][1]=b; matrix[1][2]=c;
          for (int i=0;i<3;i++) cell[1][i]=list[current][i];
        }
      }
      current++;
    }
    cell[2][0]=cell[0][1]*cell[1][2]-cell[1][1]*cell[0][2];
    cell[2][1]=cell[1][0]*cell[0][2]-cell[0][0]*cell[1][2];
    cell[2][2]=cell[0][0]*cell[1][1]-cell[1][0]*cell[0][1];
    matrix[2][0]=matrix[0][1]*matrix[1][2]-matrix[1][1]*matrix[0][2];
    matrix[2][1]=matrix[1][0]*matrix[0][2]-matrix[0][0]*matrix[1][2];
    matrix[2][2]=matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
    current=0;
    for (a=0;a<2;a++) for (b=-1;b<2;b++) for (c=-1;c<2;c++) {
      if (scalar(cell[2],cell[2])>scalar(list[current],list[current]))
      if(current!=4) {
        int temp[3]={a,b,c};
        if(det(matrix[0],matrix[1],temp)!=0) {
          matrix[2][0]=a; matrix[2][1]=b; matrix[2][2]=c;
          for (int i=0;i<3;i++) cell[2][i]=list[current][i];
        }
      }
      current++;
    }
    mmult(convert,matrix);
  } while ((matrix[0][0]!=1)||(matrix[1][1]!=1)||(abs(matrix[2][2])!=1)
         ||(matrix[1][0]!=0)||(matrix[2][0]!=0)||(matrix[2][1]!=0)
         ||(matrix[1][2]!=0)||(matrix[0][1]!=0)||(matrix[0][2]!=0));
  if (det(convert[0],convert[1],convert[2])==-1)
  for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
  cellCalculation(cell);
  int choice=0;
  if(angle_a<90) choice++; if(angle_b<90) choice+=2; if(angle_c<90) choice+=4;
  switch (choice) {
    case 1: case 6: for(int i=0;i<3;i++){cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];
      cell[2][i]=-cell[2][i]; convert[2][i]=-convert[2][i];}
      angle_b=180-angle_b; angle_c=180-angle_c; break;
    case 2: case 5: for(int i=0;i<3;i++){cell[0][i]=-cell[0][i]; convert[0][i]=-convert[0][i];
      cell[2][i]=-cell[2][i]; convert[2][i]=-convert[2][i];}
      angle_a=180-angle_a; angle_c=180-angle_c; break;
    case 3: case 4: for(int i=0;i<3;i++){cell[0][i]=-cell[0][i]; convert[0][i]=-convert[0][i];
      cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
      angle_a=180-angle_a; angle_b=180-angle_b; break;
  }
}

////////////////////////////////////////////////////////////////////////////////

void monoclinic(float cell[3][3]) {
  float list[6][3];
  int matrix[3][3];
  int a,c;
  if (scalar(cell[0],cell[0])>scalar(cell[2],cell[2])) {
    Swap(cell[0],cell[2]); Swap(convert[0],convert[2]);
  }
  do {
    matrix[0][0]=matrix[1][1]=matrix[2][2]=1;
    matrix[0][1]=matrix[1][0]=matrix[0][2]=matrix[2][0]=matrix[1][2]=matrix[2][1]=0;
    int current=0;
    for (a=0;a<2;a++) for (c=-1;c<2;c++) {
      for (int i=0;i<3;i++) list[current][i]=a*cell[0][i]+c*cell[2][i];
      current++;
    }
    current=0;
    for (a=0;a<2;a++) for (c=-1;c<2;c++) {
      if (scalar(cell[0],cell[0])>scalar(list[current],list[current]))
      if(current!=1) {
        matrix[0][0]=a; matrix[0][2]=c;
        for (int i=0;i<3;i++) cell[0][i]=list[current][i];
      }
      current++;
    }
    current=0;
    for (a=0;a<2;a++) for (c=-1;c<2;c++) {
      if (scalar(cell[2],cell[2])>scalar(list[current],list[current]))
      if(current!=1) {
        int temp1[3]={13,17,19};
        int temp[3]={a,0,c};
        if(det(matrix[0],temp,temp1)!=0) {
          matrix[2][0]=a; matrix[2][2]=c;
          for (int i=0;i<3;i++) cell[2][i]=list[current][i];
        }
      }
      current++;
    }
    mmult(convert,matrix);
  } while ((matrix[0][0]!=1)||(matrix[2][2]!=1)||(matrix[2][0]!=0)||(matrix[0][2]!=0));
  if (det(convert[0],convert[1],convert[2])==-1)
  for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
  cellCalculation(cell);
  if(angle_b<90) {
    angle_b=180-angle_b;
    for(int i=0;i<3;i++) {
      cell[0][i]=-cell[0][i];  cell[1][i]=-cell[1][i];
      convert[0][i]=-convert[0][i]; convert[1][i]=-convert[1][i];
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

float monoclinic1(float cell[3][3]) {         //////C2/c Cc Cm C2
  monoclinic(cell);
  if(convert[0][2]%2==0) ;    //C
  else
  if(convert[2][2]%2==0) {    //A
    Swap(cell[0],cell[2]); Swap(convert[0],convert[2]);
    for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
    float temp=cell_a; cell_a=cell_c; cell_c=temp;
  }
  else {                      //I
    int matrix[3][3]={{1,0,1},{0,1,0},{-1,0,0}};
    mmult(convert,matrix);
    float temp[3];
    for(int i=0;i<3;i++) {temp[i]=cell[0][i]; cell[0][i]+=cell[2][i]; cell[2][i]=-temp[i];}
    cell_c=cell_a; cell_a=sqrt(scalar(cell[0],cell[0]));
    angle_b=57.29578*acos(scalar(cell[0],cell[2])/(cell_a*cell_c));
  }
  return convert[2][0]%2;
}

////////////////////////////////////////////////////////////////////////////////

float monoclinic2(float cell[3][3]) { //////A2/n An Am A2
  monoclinic(cell);
  if(convert[0][0]%2==0) ;//C
  else
  if(convert[2][0]%2==0) {//A
    Swap(cell[0],cell[2]); Swap(convert[0],convert[2]);
    for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
    float temp=cell_a; cell_a=cell_c; cell_c=temp;
  }
  else {                  //I
    int matrix[3][3]={{1,0,1},{0,1,0},{-1,0,0}};
    mmult(convert,matrix);
    float temp[3];
    for(int i=0;i<3;i++) {temp[i]=cell[0][i]; cell[0][i]+=cell[2][i]; cell[2][i]=-temp[i];}
    cell_c=cell_a; cell_a=sqrt(scalar(cell[0],cell[0]));
    angle_b=57.29578*acos(scalar(cell[0],cell[2])/(cell_a*cell_c));
  }
  return (convert[2][0]+convert[2][2])%2;
}

////////////////////////////////////////////////////////////////////////////////

float monoclinic3(float cell[3][3]) {  /////// I2/a Ia  Im I2
  monoclinic(cell);
  if((convert[0][0]+convert[0][2])%2==0) ;//C
  else
  if((convert[2][0]+convert[2][2])%2==0) { //A
    Swap(cell[0],cell[2]); Swap(convert[0],convert[2]);
    for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
    float temp=cell_a; cell_a=cell_c; cell_c=temp;
  }
  else {                  //I
    int matrix[3][3]={{1,0,1},{0,1,0},{-1,0,0}};
    mmult(convert,matrix);
    float temp[3];
    for(int i=0;i<3;i++) {temp[i]=cell[0][i]; cell[0][i]+=cell[2][i]; cell[2][i]=-temp[i];}
    cell_c=cell_a; cell_a=sqrt(scalar(cell[0],cell[0]));
    angle_b=57.29578*acos(scalar(cell[0],cell[2])/(cell_a*cell_c));
  }
  return convert[2][2]%2;
}

////////////////////////////////////////////////////////////////////////////////

void monoclinic4(float cell[3][3], int SpGr) { ///Pc P21/c P2/c
  monoclinic(cell);
  if(convert[2][0]%2==0)
  switch (SpGr) {
    case 7:  strcpy(SYMM,"LATT -1\nSYMM X, -Y, Z+0.5\n"); break;
    case 13: strcpy(SYMM,"LATT 1\nSYMM -X, Y, 0.5-Z\n"); break;
    case 14: strcpy(SYMM,"LATT 1\nSYMM -X, Y+0.5, 0.5-Z\n"); break;
  }
  else
  if(convert[0][0]%2==0) {
    switch (SpGr) {
      case 7:  strcpy(SYMM,"LATT -1\nSYMM X, -Y, Z+0.5\n"); break;
      case 13: strcpy(SYMM,"LATT 1\nSYMM -X, Y, 0.5-Z\n"); break;
      case 14: strcpy(SYMM,"LATT 1\nSYMM -X, Y+0.5, 0.5-Z\n"); break;
    }
    Swap(cell[0],cell[2]); Swap(convert[0],convert[2]);
    for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
    float temp=cell_a; cell_a=cell_c; cell_c=temp;
  }
  else
  switch (SpGr) {
    case 7:  strcpy(SYMM,"LATT -1\nSYMM X+0.5, -Y, Z+0.5\n");   strcpy(group,"Pn "); break;
    case 13: strcpy(SYMM,"LATT 1\nSYMM 0.5-X, Y, 0.5-Z\n");     strcpy(group,"P2/n "); break;
    case 14: strcpy(SYMM,"LATT 1\nSYMM 0.5-X, Y+0.5, 0.5-Z\n"); strcpy(group,"P21/n "); break;
  }
}

////////////////////////////////////////////////////////////////////////////////

void monoclinic5(float cell[3][3], int SpGr) {   ///Pn P21/n P2/n
  monoclinic(cell);
  if((convert[2][0]+convert[2][2])%2==0)
  switch (SpGr) {
    case 7:  strcpy(SYMM,"LATT -1\nSYMM X, -Y, Z+0.5\n"); break;
    case 13: strcpy(SYMM,"LATT 1\nSYMM -X, Y, 0.5-Z\n"); break;
    case 14: strcpy(SYMM,"LATT 1\nSYMM -X, Y+0.5, 0.5-Z\n"); break;
  }
  else
  if((convert[0][0]+convert[0][2])%2==0) {
    switch (SpGr) {
      case 7:  strcpy(SYMM,"LATT -1\nSYMM X, -Y, Z+0.5\n"); break;
      case 13: strcpy(SYMM,"LATT 1\nSYMM -X, Y, 0.5-Z\n"); break;
      case 14: strcpy(SYMM,"LATT 1\nSYMM -X, Y+0.5, 0.5-Z\n"); break;
    }
    Swap(cell[0],cell[2]); Swap(convert[0],convert[2]);
    for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
    float temp=cell_a; cell_a=cell_c; cell_c=temp;
  }
  else
  switch (SpGr) {
    case 7:  strcpy(SYMM,"LATT -1\nSYMM X+0.5, -Y, Z+0.5\n");   strcpy(group,"Pn "); break;
    case 13: strcpy(SYMM,"LATT 1\nSYMM 0.5-X, Y, 0.5-Z\n");     strcpy(group,"P2/n "); break;
    case 14: strcpy(SYMM,"LATT 1\nSYMM 0.5-X, Y+0.5, 0.5-Z\n"); strcpy(group,"P21/n "); break;
  }
}

////////////////////////////////////////////////////////////////////////////////

void monoclinic6(float cell[3][3], int SpGr) {   ///Pa P21/a P2/a
  monoclinic(cell);
  if(convert[2][2]%2==0)
  switch (SpGr) {
    case 7:  strcpy(SYMM,"LATT -1\nSYMM X, -Y, Z+0.5\n"); break;
    case 13: strcpy(SYMM,"LATT 1\nSYMM -X, Y, 0.5-Z\n"); break;
    case 14: strcpy(SYMM,"LATT 1\nSYMM -X, Y+0.5, 0.5-Z\n"); break;
  }
  else
  if(convert[0][2]%2==0) {
    switch (SpGr) {
      case 7:  strcpy(SYMM,"LATT -1\nSYMM X, -Y, Z+0.5\n"); break;
      case 13: strcpy(SYMM,"LATT 1\nSYMM -X, Y, 0.5-Z\n"); break;
      case 14: strcpy(SYMM,"LATT 1\nSYMM -X, Y+0.5, 0.5-Z\n"); break;
    }
    Swap(cell[0],cell[2]); Swap(convert[0],convert[2]);
    for (int i=0;i<3;i++) {cell[1][i]=-cell[1][i]; convert[1][i]=-convert[1][i];}
    float temp=cell_a; cell_a=cell_c; cell_c=temp;
  }
  else
  switch (SpGr) {
    case 7:  strcpy(SYMM,"LATT -1\nSYMM X+0.5, -Y, Z+0.5\n");   strcpy(group,"Pn "); break;
    case 13: strcpy(SYMM,"LATT 1\nSYMM 0.5-X, Y, 0.5-Z\n");     strcpy(group,"P2/n "); break;
    case 14: strcpy(SYMM,"LATT 1\nSYMM 0.5-X, Y+0.5, 0.5-Z\n"); strcpy(group,"P21/n "); break;
  }
}

////////////////////////////////////////////////////////////////////////////////

void orthorhombic(float cell[3][3]) {
  cellCalculation(cell);
}

////////////////////////////////////////////////////////////////////////////////

float orthorhombic1(float cell[3][3]) {  /// P 21 21 21
  float push=0;
  int n=min(cell);
  switch (n) {
    case 1: Swap(cell[0],cell[1]);       Swap(cell[1],cell[2]);
            Swap(convert[0],convert[1]); Swap(convert[1],convert[2]); break;
    case 2: Swap(cell[0],cell[2]); Swap(cell[1],cell[2]);
            Swap(convert[0],convert[2]); Swap(convert[1],convert[2]); break;
  }
  if (scalar(cell[1],cell[1])>scalar(cell[2],cell[2])) {
    Swap(cell[1],cell[2]); Swap(convert[1],convert[2]);
    for (int i=0;i<3;i++) {cell[0][i]=-cell[0][i]; convert[0][i]=-convert[0][i];}
    push=1;
  }
  cellCalculation(cell);
  return push;
}

////////////////////////////////////////////////////////////////////////////////

float orthorhombic2(float cell[3][3]) {  // P 21 21 2
  float k=0;
  if (scalar(cell[0],cell[0])>scalar(cell[1],cell[1])) {
    Swap(cell[0],cell[1]); Swap(convert[0],convert[1]); k=1;
    for (int i=0;i<3;i++) {cell[2][i]=-cell[2][i]; convert[2][i]=-convert[2][i];}
  }
  cellCalculation(cell);
  return k;
}

////////////////////////////////////////////////////////////////////////////////

void orthorhombic3(float cell[3][3]) {  // P b c a
  int n=min(cell);
  switch (n) {
    case 1: Swap(cell[0],cell[1]);       Swap(cell[1],cell[2]);
            Swap(convert[0],convert[1]); Swap(convert[1],convert[2]); break;
    case 2: Swap(cell[0],cell[2]); Swap(cell[1],cell[2]);
            Swap(convert[0],convert[2]); Swap(convert[1],convert[2]); break;
  }
  cellCalculation(cell);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////THE END OF CONVERTATION OF UNIT CELLS///////////////////////
////////////////////////////////////////////////////////////////////////////////

void Swap(int a[3],int b[3]) {
  int temp[3];
  for (int i=0;i<3;i++) temp[i]=a[i];
  for (int i=0;i<3;i++) a[i]=b[i];
  for (int i=0;i<3;i++) b[i]=temp[i];
}

void Swap(float a[3],float b[3]) {
  float temp[3];
  for (int i=0;i<3;i++) temp[i]=a[i];
  for (int i=0;i<3;i++) a[i]=b[i];
  for (int i=0;i<3;i++) b[i]=temp[i];
}

////////////////////////////////////////////////////////////////////////////////

int min(float cell[3][3]) {
  int nomer=0;                                    // nomer - the number of the best variant
  for(int i=1;i<3;i++)
  if(scalar(cell[i],cell[i])<scalar(cell[nomer],cell[nomer])) nomer=i;
  return nomer;
}

////////////////////////////////////////////////////////////////////////////////

float det(float a0[3], float a1[3], float a2[3]) {
  float det=(a0[0])*(a1[1])*(a2[2])+(a0[1])*(a1[2])*(a2[0])+(a0[2])*(a1[0])*(a2[1])-\
  (a0[2])*(a1[1])*(a2[0])-(a0[1])*(a1[0])*(a2[2])-(a0[0])*(a1[2])*(a2[1]);
  return det;
}

int det(int a0[3], int a1[3], int a2[3]) {
  int det=(a0[0])*(a1[1])*(a2[2])+(a0[1])*(a1[2])*(a2[0])+(a0[2])*(a1[0])*(a2[1])-\
  (a0[2])*(a1[1])*(a2[0])-(a0[1])*(a1[0])*(a2[2])-(a0[0])*(a1[2])*(a2[1]);
  return det;
}

////////////////////////////////////////////////////////////////////////////////

float scalar(float a0[3],float a1[3]) {
  float scalar=a0[0]*a1[0]+a0[1]*a1[1]+a0[2]*a1[2];
  return scalar;
}

////////////////////////////////////////////////////////////////////////////////

void mmult(int a[3][3], const int b[3][3]) {
  int temp[3][3];
  for (int i=0;i<3;i++) for (int j=0;j<3;j++) temp[i][j]=a[i][j];
  for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
    a[i][j]=0;
    for (int k=0;k<3;k++) a[i][j]+=temp[k][j]*b[i][k];
  }
}

////////////////////////////////////////////////////////////////////////////////

float cellCalculation(float cell[3][3]) {
  float DET=det(cell[0],cell[1],cell[2]);
  if (DET==0) {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) printf(" %5.2f  ",cell[i][j]);
    printf("Singular matrix");
    return 1;
  }
  cell_a=sqrt(scalar(cell[0],cell[0]));
  cell_b=sqrt(scalar(cell[1],cell[1]));
  cell_c=sqrt(scalar(cell[2],cell[2]));
  if (cell_a==0) {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) printf("%5.2f  ",cell[i][j]);
    printf("zero a");
    return 1;
  }
  if (cell_b==0) {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) printf("%5.2f  ",cell[i][j]);
    printf("zero b");
    return 1;
  }
  if (cell_c==0) {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) printf("%5.2f  ",cell[i][j]);
    printf("zero c");
    return 1;
  }
  angle_a=57.29578*acos(scalar(cell[1],cell[2])/(cell_b*cell_c));
  angle_b=57.29578*acos(scalar(cell[0],cell[2])/(cell_a*cell_c));
  angle_c=57.29578*acos(scalar(cell[0],cell[1])/(cell_a*cell_b));
  return DET;
}

