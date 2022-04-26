#include <iostream>
#include <mpi.h>
using namespace std;

const int SIZE=30000; //a graf maximum merete
char G[SIZE][SIZE]; //adjacenciamatrix
bool OK[SIZE]; //kesz csomopontok
int D[SIZE]; //tavolsag
int path[SIZE]; //honnan jottunk a csomopontba
const int INFINITY=9999; //eleg nagy szam, nagyobb mint barmilyen lehetseges utvonal

int nproc, id; 
/* az id illetve nproc valtozok globalisak, mivel az MPI inicializaciot a main-ben vegezzuk el
de maga a folyamatkozi kommunikacio a void dijk(int) fuggvenyben fog megvalosulni*/
MPI_Status status;
int N;

/*Az int Read_G_Adjacency_Matrix() fuggvenyt csak deklaracio szintjen adjuk meg*/
int Read_G_Adjacency_Matrix(){
//aktualis beolvasott G[][] adjacencia matrix
}

void dijk(int s){
int i,j;
int tmp, x;
int pair[2];
int tmp_pair[2];
for(i=id;i<N;i+=nproc){
D[i]=G[s][i];
OK[i]=false;
path[i]=s;
}
OK[s]=true;
path[s]=-1;
for(j=1;j<N;j++){

tmp=INFINITY;
for(i=id;i<N;i+=nproc){
if(!OK[i] && D[i]<tmp){
x=i;
tmp=D[i];
} }

pair[0]=x;
pair[1]=tmp;

if(id!=0){ //Szolga
MPI_Send(pair,2,MPI_INT,0,1,MPI_COMM_WORLD);
}else{ // id==0, Mester
for(i=1;i<nproc;++i){
MPI_Recv(tmp_pair,2,MPI_INT,i,1,MPI_COMM_WORLD, &status);
if(tmp_pair[1]<pair[1]){
pair[0]=tmp_pair[0];
pair[1]=tmp_pair[1];
} } 
}
MPI_Bcast(pair,2,MPI_INT,0,MPI_COMM_WORLD);
x=pair[0];
D[x]=pair[1];
OK[x]=true;
for(i=id;i<N;i+=nproc){
if(!OK[i] && D[i]>D[x]+G[x][i]){
D[i]=D[x]+G[x][i];
path[i]=x;
} } } 
}

main(int argc, char** argv){
  double t1, t2;

MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD, &nproc); // osszes munkas szama
MPI_Comm_rank(MPI_COMM_WORLD, &id); // sajat azonosito lekerese

N=Read_G_Adjacency_Matrix();
// G[][]-be valo beolvasas
//aktualis meret beallitasa

if(id==0){
t1=MPI_Wtime();
}

dijk(200);
//meghivjuk az algoritmust a valasztott csomoponttal

if(id==0){
t2=MPI_Wtime();

//ellenorizzuk az eredmenyeket a G[][] es D[] kimenetei altal

cout<<"time elapsed: "<<(t2-t1)<<endl;
}

MPI_Finalize();
}
